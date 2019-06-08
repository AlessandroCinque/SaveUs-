#pragma once
#include<iostream>
#include <string>
#include<vector>

void CutString(std::string& sentence, int start, int lenght);
void AddString(std::string& string1, std::string& string2);
void AddString(std::string& string1, const char* string2);
void ListString(const std::string subMetod);
void ParseString(std::string& str, std::vector<std::string>& sub, char token);
