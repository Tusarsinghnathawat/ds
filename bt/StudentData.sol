// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData {
    // Structure to hold student details
    struct Student {
        uint256 rollNo;
        string name;
        uint8 age;
    }

    // Dynamic array to store multiple students
    Student[] public students;

    // Event to log when fallback or receive is called
    event FallbackCalled(address sender, uint256 value);

    // Function to add a new student
    function addStudent(uint256 _rollNo, string memory _name, uint8 _age) public {
        students.push(Student(_rollNo, _name, _age));
    }

    // Function to get student details by index
    function getStudent(uint256 index)
        public
        view
        returns (uint256, string memory, uint8)
    {
        require(index < students.length, "Invalid index");
        Student memory s = students[index];
        return (s.rollNo, s.name, s.age);
    }

    // Fallback function – executes if someone sends ether or calls invalid function
    fallback() external payable {
        emit FallbackCalled(msg.sender, msg.value);
    }

    // Receive function – executes when ether is sent without data
    receive() external payable {
        emit FallbackCalled(msg.sender, msg.value);
    }

    // Function to check contract's current balance
    function getContractBalance() public view returns (uint256) {
        return address(this).balance;
    }
}


// 1. which solc && solc --version
// 2. solc --abi --bin StudentData.sol
// 3. solc --abi --bin --output-dir . --overwrite StudentData.sol
// In Solidity, the fallback function is a special function that’s automatically called when a contract receives a transaction that doesn’t match any existing function