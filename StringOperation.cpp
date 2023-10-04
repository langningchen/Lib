#include "StringOperation.hpp"
string StringReplaceAll(string Data, string Before, string After)
{
    size_t Index = 0;
    while ((Index = Data.find(Before)) != string::npos)
        Data.replace(Index, Before.size(), After);
    return Data;
}
string StringReplaceAllNoLoop(string Data, string Before, string After)
{
    string Identifier = "${TEMP" + to_string(time(NULL)) + "}";
    Data = StringReplaceAll(Data, Before, Identifier);
    Data = StringReplaceAll(Data, Identifier, After);
    return Data;
}
string GetStringBetween(string Data, string Start, string End)
{
    int StartPos = Data.find(Start);
    if (StartPos == -1)
        return "";
    StartPos += Start.size();
    int EndPos = Data.find(End, StartPos + 1);
    if (EndPos == -1)
        return "";
    return Data.substr(StartPos, EndPos - StartPos);
}
vector<string> SpiltString(string Input, string Separator)
{
    Input += Separator;
    vector<string> Output;
    size_t Last = 0;
    for (size_t i = 0; i < Input.size() - Separator.size() + 1; i++)
        if (Input.substr(i, Separator.size()) == Separator)
        {
            Output.push_back(Input.substr(Last, i - Last));
            i += Separator.size();
            Last = i;
            i--;
        }
    return Output;
}
bool IfFileExist(string FileName)
{
    ifstream InputFileStream(FileName);
    if (InputFileStream.bad() || !InputFileStream.is_open())
        return false;
    InputFileStream.close();
    return true;
}
string GetDataFromFileToString(string FileName)
{
    string Data = "";
    FILE *FilePointer = fopen(FileName.c_str(), "r");
    if (FilePointer == NULL)
        TRIGGER_ERROR("Cannot open input file: " + FileName);
    while (!feof(FilePointer))
        Data.push_back(fgetc(FilePointer));
    fclose(FilePointer);
    while (Data.size() > 0 && (Data[Data.size() - 1] == 0x00 || Data[Data.size() - 1] == 0xFF || Data[Data.size() - 1] == -1 || Data[Data.size() - 1] == '\r' || Data[Data.size() - 1] == '\n'))
        Data.erase(Data.size() - 1);
    return Data;
}
void SetDataFromStringToFile(string FileName, string Data)
{
    FILE *FilePointer = fopen(FileName.c_str(), "w");
    if (FilePointer == NULL)
        TRIGGER_ERROR("Cannot open output file: " + FileName);
    for (auto i : Data)
        fputc(i, FilePointer);
    fclose(FilePointer);
}
string FixString(string Data)
{
    while (Data[0] == '\n' ||
           Data[0] == '\t' ||
           Data[0] == '\r' ||
           Data[0] == ' ')
        Data.erase(0, 1);
    while (Data[Data.size() - 1] == '\n' ||
           Data[Data.size() - 1] == '\t' ||
           Data[Data.size() - 1] == '\r' ||
           Data[Data.size() - 1] == ' ')
        Data.erase(Data.size() - 1, 1);
    return Data;
}
#ifndef _WIN32
string GetUserHomeFolder()
{
    char *HomeFolder = getenv("HOME");
    if (HomeFolder == NULL)
        TRIGGER_ERROR("Cannot get user home folder");
    return HomeFolder;
}
#endif
