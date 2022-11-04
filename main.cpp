#include <iostream>
#include <fstream>
#include <string>

// string html = "HTTP/1.1 200 OK\nContent-Type:text/html\nContent-Length: 600\n\n<!DOCTYPE html>\r\n<html>\r\n<head>\r\n<title> File Upload Form</title>\r\n</head>\r\n<body>\r\n<h1>Upload file</h1>\r\n<form id =\"form\" method=\"POST\" action=\"/\" enctype=\"multipart/form-data\">\r\n<input type=\"file\" name=\"fileName\"/><br/><br/>\r\nCaption: <input type =\"text\" name=\"caption\"<br/><br/>\r\n <br/>\nDate : <input type=\"date\" name=\"date\"<br/><br/>\r\n <br/>\n <input id='formBtn' type=\"submit\" name=\"submit\" value=\"Submit\"/>\r\n </form>\r\n</body>\r\n</html>\r\n";

using namespace std;

string readFile(string filename){
    // Open declared File - <fstream> header for file Reading and Writing
    std::fstream f{filename};

    // Can manually open as well
    //    f.open("data.txt");

    // String for output
    std::string input;
    string output;
    string intermediate;
    output = output + "HTTP/1.1 200 OK\n";
    output = output + "Content-Type:text/html\n";
    output = output + "Content-Length: ";

    if (f.is_open()){

        // Keep getting next Line
        while(std::getline(f,input)){
            intermediate = intermediate + input;
            intermediate = intermediate + "\n";
        }
        f.close();
    }

    output = output + to_string(intermediate.length());
    output = output + "\n\n";
    output = output + intermediate;

    return output;
}

int main() {
    string output = readFile("../index - Copy.html");
    cout << output;
    return 0;
}





// "HTTP/1.1 200 OK\nContent-Type:text/html\nContent-Length: 14\n\n<h1>Hell<h1>\n"
