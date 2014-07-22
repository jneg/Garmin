#ifndef LAP_HPP
#define LAP_HPP

#include <string>
#include <vector>
#include "trackpoint.hpp"
using namespace std;

class Lap
{
private:
    /* Remove default constructor */
    Lap();

    /* Lap ID should be unchanged */
    const int m_nlap {-1};

    /* Various lap data gathered from the file */
    string m_strdate;
    string m_strtime;
    double m_dtotalsec {-1};
    double m_ddistance {-1};
    double m_dmaxspeed {-1};
    int m_ncalories {-1};
    int m_naveragebpm {-1};
    int m_nmaxbpm {-1};
    string m_strintensity;
    int m_ncadence {-1};
    string m_strtriggermethod;


    /* Lap Total Trackpoints */
    int m_ntotaltrackpoints;

    /* Lap Time */
    int m_nelapsedtime {-1};
    int m_nactivitytime {-1};
    int m_nmovingtime {-1};

    /* Lap Calculated Distance */
    double m_dcalculateddistance {-1};

    /* Lap Speed */
    double m_daverageactivityspeed {-1};
    double m_daveragemovingspeed {-1};
    double m_dcalculatedmaxspeed {-1};

    /* Lap Elevation */
    double m_delevationgained {-1};
    double m_delevationlost {-1};
    double m_delevationmax {-1};
    double m_delevationmin {-1};

    /* Lap Heart Rate */
    int m_nminheartbpm {-1};
    int m_naverageheartbpm {-1};
    int m_nmaxheartbpm {-1};

    /* Lap Cadence */
    int m_naveragecadence {-1};
    int m_nmaxcadence {-1};

    /* Lap Calories */
    int m_ntotalcalories {-1};

    /* The vector of Trackpoints within the lap */
    vector<Trackpoint> m_cpoints;
public:
    /* Construct a Lap with a Lap ID */
    Lap(int lap) : m_nlap {lap} { }

    /* Set the Lap Data */
    void setDate(const string&);
    void setTime(const string&);
    void setTotalSec(double);
    void setDistance(double);
    void setMaxSpeed(double);
    void setCalories(int);
    void setAverageBpm(int);
    void setMaxBpm(int);
    void setIntensity(const string&);
    void setCadence(int);
    void setTriggerMethod(const string&);

    /* Retrieve the Lap Data */
    int getLap();
    string getDate();
    string getTime();
    double getTotalSec();
    double getDistance();
    double getMaxSpeed();
    int getCalories();
    int getAverageBpm();
    int getMaxBpm();
    string getIntensity();
    int getCadence();
    string getTriggerMethod();

    /* Set the Calculated Lap Data */
    void setTotalTrackpoints(int);
    void setElapsedTime(int); /* Course total */
    void setActivityTime(int); /* Distance > 0 */
    void setMovingTime(int); /* Dist > 0 && Speed > 0 */
    void setCalculatedDistance(double);
    void setAverageActivitySpeed(double); /* Distance > 0 */
    void setAverageMovingSpeed(double); /* Dist > 0 && Speed > 0 */
    void setCalculatedMaxSpeed(double);
    void setElevationGained(double);
    void setElevationLost(double);
    void setElevationMax(double);
    void setElevationMin(double);
    void setMinHeartBpm(int);
    void setAverageHeartBpm(int);
    void setMaxHeartBpm(int);
    void setAverageCadence(int);
    void setMaxCadence(int);

    /* Retrieve the Calculated Lap Data */
    int getTotalTrackpoints();
    int getElapsedTime();
    int getActivityTime();
    int getMovingTime();
    double getCalculatedDistance();
    double getAverageActivitySpeed();
    double getAverageMovingSpeed();
    double getCalculatedMaxSpeed();
    double getElevationGained();
    double getElevationLost();
    double getElevationMax();
    double getElevationMin();
    int getMinHeartBpm();
    int getAverageHeartBpm();
    int getMaxHeartBpm();
    int getAverageCadence();
    int getMaxCadence();

    /* Retrieve the Trackpoint vector */
    vector<Trackpoint>& getTrackpoints();
};

#endif /* LAP_HPP */
