#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// Function to convert a string to lowercase
string toLowerCase(const string& input) {
    string result = input;
    transform(result.begin(), result.end(), result.begin(), [](unsigned char c) {
        return tolower(c);
    });
    return result;
}

// Function to check if a keyword exists in the input
bool containsKeyword(const string& input, const vector<string>& keywords) {
    for (const string& keyword : keywords) {
        if (input.find(keyword) != string::npos) {
            return true;
        }
    }
    return false;
}

// Main chatbot function
void mentalHealthChatbot() {
    cout << "Hello! I'm your mental health chatbot. How can I help you today?\n";
    cout << "You can type 'exit' to end the chat.\n";

    string userInput;
    while (true) {
        cout << "\nYou: ";
        getline(cin, userInput);

        // Convert input to lowercase for easier keyword matching
        string inputLower = toLowerCase(userInput);

        if (inputLower == "exit") {
            cout << "Chatbot: Take care of yourself! Remember, you're not alone. Goodbye!\n";
            break;
        }

        // Respond based on keywords
        if (containsKeyword(inputLower, {"stress", "anxious", "overwhelmed"})) {
            cout << "Chatbot: It sounds like you're feeling stressed. Try taking deep breaths or a short walk to clear your mind.";
        } else if (containsKeyword(inputLower, {"sad", "depressed", "unhappy"})) {
            cout << "Chatbot: I'm sorry you're feeling this way. Talking to a friend or writing down your feelings might help.";
        } else if (containsKeyword(inputLower, {"tired", "exhausted", "sleep"})) {
            cout << "Chatbot: Make sure you're getting enough rest. A consistent sleep schedule can make a big difference.";
        } else if (containsKeyword(inputLower, {"happy", "joy", "excited"})) {
            cout << "Chatbot: I'm glad to hear you're feeling good! Keep doing what makes you happy!";
        } else {
            cout << "Chatbot: I see. Sometimes just talking helps. Is there anything else you'd like to share?";
        }
    }
}

int main() {
    mentalHealthChatbot();
    return 0;
}
