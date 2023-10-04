#pragma once

#include <string>
#include <fstream>
#include <string.h>
#include <unistd.h>
#include <vector>
#include <time.h>
#include <assert.h>
#include "Exception.hpp"
#define VAR_DUMP(e) cout << #e << "=" << e << endl
#define SPILT_LINE cout << endl                                     \
                        << "------------------------------" << endl \
                        << endl
#define REPORT_POSITION                         \
    cout << "Report current position: " << endl \
         << "File: " << __FILE__ << endl        \
         << "Line: " << __LINE__ << endl        \
         << "Function: " << __func__ << endl;
#ifdef _WIN32
const string TempFolder = "C:\\Windows\\Temp\\";
const string PathSeparator = "\\";
#else
const string TempFolder = "/tmp/";
const string PathSeparator = "/";
#endif
using namespace std;
void GetCurrentDir();
string StringReplaceAll(string Data, string Before, string After);
string StringReplaceAllNoLoop(string Data, string Before, string After);
string GetStringBetween(string Data, string Start, string End);
vector<string> SpiltString(string Input, string Separator);
bool IfFileExist(string FileName);
string GetDataFromFileToString(string FileName = TempFolder + "Body.tmp");
void SetDataFromStringToFile(string FileName, string Data);
string FixString(string Data);
#ifndef _WIN32
string GetUserHomeFolder();
#endif
