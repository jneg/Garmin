#ifndef BADTRACKPOINT_HPP
#define BADTRACKPOINT_HPP

#include <iostream>
#include <exception>

using namespace std;

class BadTrackpoint
{
private:
    int m_nlap;
    int m_ntp;
    string m_strerror;
public:
    BadTrackpoint(int lap, int tp, const string& error) : m_nlap {lap}, m_ntp {tp}, m_strerror {error} {}

    const string what() const throw()
    {
      return "Bad Trackpoint (Lap " + to_string(m_nlap) + ", Trackpoint " + to_string(m_ntp) + "): " + m_strerror;
    }
};

#endif // BADTRACKPOINT_HPP
