#include "Exception.hpp"
CLNException::CLNException()
{
}
CLNException::CLNException(const string &message)
{
    Content = "We're sorry but this program occurred " + message + "\n" +
              "\n" +
              "Please try to run this program again later, if this error still occurred, contact the developer for help! Thanks! \n";
}
string CLNException::what() const
{
    return Content;
}
CLNException::~CLNException()
{
}
