#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Bot response collections
const vector<string> GREETINGS = {
    "Hello! Welcome to ShopEasy customer support.",
    "Hi there! How can I help you today?",
    "Welcome! What can I assist you with?"
};

const vector<string> FAREWELLS = {
    "Thank you for contacting us. Have a great day!",
    "We're happy to help. Goodbye!",
    "Let us know if you need anything else. Bye!"
};

// Structure for knowledge base entries
struct ResponseEntry {
    vector<string> keywords;
    string response;
};

// Knowledge base
const vector<ResponseEntry> RESPONSES = {
    {{"order", "status", "tracking"}, 
     "You can check your order status by visiting 'My Orders' in your account.\n"
     "Tracking information is available in your order details once your package ships."},
     
    {{"return", "exchange", "refund"}, 
     "Our return policy allows returns within 30 days. Visit Returns Center to start."},
     
    {{"hour", "open", "close", "time"}, 
     "Our stores are open 9am-9pm Monday-Saturday, 10am-6pm Sunday."},
     
    {{"contact", "phone", "email", "call"}, 
     "You can reach our support team at 1-800-SHOPEASY or support@shopeasy.com."}
};

// Function to check if any keyword exists in user input
bool containsKeyword(const string& input, const vector<string>& keywords) {
    for (const string& keyword : keywords) {
        if (input.find(keyword) != string::npos) {
            return true;
        }
    }
    return false;
}

// Function to get random response from a collection
string getRandomResponse(const vector<string>& responses) {
    return responses[rand() % responses.size()];
}

void chatbot() {
    srand(time(0)); // Seed random number generator
    
    cout << getRandomResponse(GREETINGS) << endl;
    
    while (true) {
        cout << "\nYou: ";
        string user_input;
        getline(cin, user_input);
        
        // Convert to lowercase for case-insensitive comparison
        transform(user_input.begin(), user_input.end(), user_input.begin(), ::tolower);
        
        if (user_input.find("bye") != string::npos || 
            user_input.find("goodbye") != string::npos ||
            user_input.find("exit") != string::npos ||
            user_input.find("quit") != string::npos) {
            cout << "Bot: " << getRandomResponse(FAREWELLS) << endl;
            break;
        }
        else if (user_input.find("thank") != string::npos) {
            cout << "Bot: You're welcome! Is there anything else I can help with?" << endl;
        }
        else {
            bool found_response = false;
            for (const ResponseEntry& entry : RESPONSES) {
                if (containsKeyword(user_input, entry.keywords)) {
                    cout << "Bot: " << entry.response << endl;
                    found_response = true;
                    break;
                }
            }
            
            if (!found_response) {
                cout << "Bot: I'm sorry, I didn't understand that. Could you rephrase or ask about:\n";
                cout << "- Order status\n- Returns\n- Store hours\n- Contact information" << endl;
            }
        }
    }
}

int main() {
    cout << "ShopEasy Customer Support Chatbot (type 'quit' to exit)\n";
    cout << "=====================================================\n";
    chatbot();
    return 0;
}