#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>

bool wordStarted = false;
int wordLenght = 0;
std::string currentWord {};

struct data{
    int count{};
    std::set<int> lines{};
};

bool isgood(const char a){
    return isalpha(a);

}
bool findWords(char currentChar) {
    if (isgood(currentChar))
        {
            if (!wordStarted)
            {
                wordStarted = true;
                wordLenght = 0;
            }

            if (wordStarted)
            {

                currentWord += (char)std::tolower(currentChar);
                wordLenght++;
            }
        }
}


void process(const std::string &line, int lineNumber, std::map<std::string, data> &WordCounts) {
    std::vector<int>temp;
    temp.push_back(lineNumber);
    data first{};
    first.lines.insert(lineNumber);
    first.count=1;
    for (int i = 0; i < line.length(); i++)
    {
        char currentChar = line[i];
        findWords(currentChar);
        if (wordStarted)
        {
            if (!isgood(currentChar) || i == line.length() - 1)
            { auto search = WordCounts.find(currentWord);

                if (search != WordCounts.end())
                {
                    WordCounts[currentWord].count++;
                    WordCounts[currentWord].lines.insert(lineNumber);
                }
                else
                {
                    WordCounts.emplace(currentWord, first);
                }
                wordStarted = false;
                currentWord = "";
            }
        }
    }
};

std::map<std::string, data> readLines(std::ifstream& a)  {
    std::map<std::string, data> WordCounts;
    std::string line{};
    int lineNumber{0};
    while (std::getline(a,line)){
        lineNumber++;
        process(line,lineNumber,WordCounts);

    }
    return WordCounts;
};

int main(){
    std::ifstream fileInput("text");
    std::map<std::string,data> WordCounts = readLines(fileInput);
    for (auto a : WordCounts ) {
        if(a.second.count>1){
            std::cout<<std::left << std::setfill(' ')<<std::setw(15)<<a.first<<"Count: \t"<<a.second.count<<"\tLine: ";
            for (auto line : a.second.lines) {
                std::cout<<line<<", ";
            }
            std::cout<<"\n";
        }

    }
    return 0;
}
 