#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, vector<string>> pairs = {
    {"my name is (.*)", {"Hello %1, it's nice to meet you! How can I assist you today?", "Hi %1, how can I help you today?"}},
    {"hi|hello|hey there|hola", {"Hello, it's great to see you! What can I do for you today?", "Hi there! How can I assist you today?"}},
    {"what is your name ?", {"You can call me Claude. How can I assist you today?", "I'm Claude. What can I do for you today?"}},
    {"how are you ?", {"I'm doing well, thank you! How about you?", "I'm good, thanks for asking! How can I assist you today?"}},
    {"sorry (.*)", {"It's alright, no worries.", "That's okay, don't worry about it."}},
    {"I am fine", {"Great to hear that! How can I assist you today?", "That's good to hear. What can I do for you?"}},
    {"I am (.*)", {"Hello %1, nice to meet you! How can I assist you today?", "Hi %1, what can I do for you today?"}},  // Added this line for I am <name>
    {"(.*) age?", {"Well, in digital years, I'm quite young!", "Age is just a number, especially for a bot like me!"}},
    {"what (.*) want ?", {"I'm here to assist you. What can I help you with today?", "My goal is to be helpful to you. What can I do for you today?"}},
    {"(.*) created ?", {"I was created by a team of developers.", "A team of programmers put their effort into creating me."}},
    {"(.*) (location|city) ?", {"I exist in the digital world, so I don't have a physical location.", "I'm based in the cloud, ready to assist you wherever you are."}},
    {"how is weather in (.*)?", {"I'm sorry, I can't provide real-time data as I don't have access to live databases.", "Unfortunately, I can't provide weather updates as I don't have access to real-time information."}},
    {"i work in (.*)?", {"%1 sounds like a great place to work. How can I assist you today?", "%1? That's interesting. How can I help you with your work?"}},
    {"quit", {"It was nice talking to you. Have a great day!", "Goodbye! Don't hesitate to return if you have more questions."}}
};

// Function to match user input to pairs
string get_response(const string &input)
{
    for (const auto &pair : pairs)
    {
        regex pattern(pair.first);
        smatch match;
        if (regex_search(input, match, pattern))
        {
            string response = pair.second[rand() % pair.second.size()];
            if (match.size() > 1)
            {
                // Replace %1 with the matched group
                response.replace(response.find("%1"), 2, match[1].str());
            }
            return response;
        }
    }
    return "Sorry, I didn't understand that. Could you rephrase?";
}

int main()
{
    cout << "Hey there! I am Claude at your service. How can I assist you today?" << endl;

    string input;
    while (true)
    {
        getline(cin, input);

        // Convert input to lowercase for more flexibility
        transform(input.begin(), input.end(), input.begin(), ::tolower);

        if (input == "quit")
        {
            cout << "Goodbye! Don't hesitate to return if you have more questions." << endl;
            break;
        }

        cout << get_response(input) << endl;
    }

    return 0;
}
