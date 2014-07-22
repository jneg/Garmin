#ifndef TRACKPOINT_HPP
#define TRACKPOINT_HPP

#include <string>
using namespace std;

class Trackpoint
{
private:
    /* Hide default constructor */
    Trackpoint();

    /* Lap and Trackpoint ID should be unchanged */
    const int m_nlap {-1};
    const int m_ntp {-1};

    /* Various Trackpoint data gathered from the file */
    string m_strdate;
    string m_strtime;
    double m_dlatitude {-1};
    double m_dlongitude {-1};
    double m_daltitude {-1};
    double m_ddistance {-1};
    int m_nheartbpm {-1};
    int m_ncadence {-1};
    double m_dspeed {-1};

    /* Various gained information gathered from the database */
    int m_ntime_gained {0};
    double m_ddistance_gained {0};
    double m_daltitude_gained {0};
public:
    /* Construct a Trackpoint with a lap and trackpoint ID */
    Trackpoint(int lap, int tp) : m_nlap {lap}, m_ntp {tp} { }

    /* Set the trackpoint data */
    void setDate(const string&);
    void setTime(const string&);
    void setLatitude(double);
    void setLongitude(double);
    void setAltitude(double);
    void setDistance(double);
    void setHeartBpm(int);
    void setCadence(int);
    void setSpeed(double);

    /* Retrieve the trackpoint data */
    int getLap();
    int getTp();
    string getDate();
    string getTime();
    double getLatitude();
    double getLongitude();
    double getAltitude();
    double getDistance();
    int getHeartBpm();
    int getCadence();
    double getSpeed();

    /* Set the gained information after database retrieval */
    void setTimeGained(int);
    void setDistanceGained(double);
    void setAltitudeGained(double);

    /* Retrieve this gained information */
    int getTimeGained();
    double getDistanceGained();
    double getAltitudeGained();
};

#endif /* TRACKPOINT_HPP */
