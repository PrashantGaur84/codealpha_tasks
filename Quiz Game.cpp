#include <iostream>
#include <vector>
#include <string>

class Question {
public:
    std::string question;
    std::string options[4];
    char correctAnswer;

    Question(std::string q, std::string op1, std::string op2, std::string op3, std::string op4, char correct) {
        question = q;
        options[0] = op1;
        options[1] = op2;
        options[2] = op3;
        options[3] = op4;
        correctAnswer = correct;
    }
};

class User {
public:
    std::string username;
    int score;

    User(std::string name) {
        username = name;
        score = 0;
    }
};

void displayQuestion(Question& q) {
    std::cout << q.question << std::endl;
    std::cout << "a. " << q.options[0] << std::endl;
    std::cout << "b. " << q.options[1] << std::endl;
    std::cout << "c. " << q.options[2] << std::endl;
    std::cout << "d. " << q.options[3] << std::endl;
}

int main() {
    std::vector<Question> questions = {
        Question("What is the capital of France?", "Berlin", "London", "Paris", "Madrid", 'c'),
        Question("What is 2 + 2?", "3", "4", "5", "6", 'b'),
        Question("Who wrote 'To Kill a Mockingbird'?", "Harper Lee", "Jane Austen", "Mark Twain", "Charles Dickens", 'a'),
        Question("What is the largest planet in our Solar System?", "Earth", "Mars", "Jupiter", "Saturn", 'c')
    };

    std::string username;
    std::cout << "Enter your username: ";
    std::getline(std::cin, username);
    User user(username);

    for (int i = 0; i < questions.size(); ++i) {
        displayQuestion(questions[i]);
        char answer;
        std::cout << "Your answer: ";
        std::cin >> answer;

        if (answer == questions[i].correctAnswer) {
            user.score++;
        }
    }

    std::cout << "Quiz finished!" << std::endl;
    std::cout << "Your score: " << user.score << "/" << questions.size() << std::endl;

    std::cout << "Correct answers:" << std::endl;
    for (int i = 0; i < questions.size(); ++i) {
        std::cout << questions[i].question << std::endl;
        std::cout << "Correct answer: " << questions[i].correctAnswer << ". " << questions[i].options[questions[i].correctAnswer - 'a'] << std::endl;
    }

    return 0;
}
