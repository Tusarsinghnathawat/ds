// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract BankAccount {
    // Each user's address maps to their individual balance
    mapping(address => uint256) private balances;

    // Deposit ether into your own account
    function deposit() public payable {
        balances[msg.sender] += msg.value;
    }

    // Withdraw ether from your account
    function withdraw(uint256 amount) public {
        require(balances[msg.sender] >= amount, "Not enough balance");
        balances[msg.sender] -= amount;
        payable(msg.sender).transfer(amount);
    }

    // View your current balance
    function getBalance() public view returns (uint256) {
        return balances[msg.sender];
    }
}

// 1. which solc && solc --version
// 2. solc --abi --bin BankAccount.sol
// 3. solc --abi --bin --output-dir . --overwrite BankAccount.sol
// .bin - evm bytecode is long seq of number for evm, it gets deployed
// .abi - ABI tells external applications (like Remix, web apps) how to talk to your contract