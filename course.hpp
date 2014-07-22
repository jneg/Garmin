 #ifndef COURSE_HPP
#define COURSE_HPP

#include <vector>
#include "lap.hpp"

class Course
{
private:
    /* Course Laps */
    vector<Lap> m_claps;

    /* Course Total Trackpoints */
    int m_ntotaltrackpoints;

    /* Course Time */
    int m_nelapsedtime {-1};
    int m_nactivitytime {-1};
    int m_nmovingtime {-1};

    /* Course Distance */
    double m_ddistance {-1};

    /* Course Speed */
    double m_daverageactivityspeed {-1};
    double m_daveragemovingspeed {-1};
    double m_dmaxspeed {-1};

    /* Course Elevation */
    double m_delevationgained {-1};
    double m_delevationlost {-1};
    double m_delevationmax {-1};
    double m_delevationmin {-1};

    /* Course Heart Rate */
    int m_nminheartbpm {-1};
    int m_naverageheartbpm {-1};
    int m_nmaxheartbpm {-1};

    /* Course Cadence */
    int m_naveragecadence {-1};
    int m_nmaxcadence {-1};

    /* Course Calories */
    int m_ntotalcalories {-1};
public:
    /* Default constructor */
    Course() {}

    /* Set the Course Data */
    void setTotalTrackpoints(int);
    void setElapsedTime(int); /* Course total */
    void setActivityTime(int); /* Distance > 0 */
    void setMovingTime(int); /* Dist > 0 && Speed > 0 */
    void setDistance(double);
    void setAverageActivitySpeed(double); /* Distance > 0 */
    void setAverageMovingSpeed(double); /* Dist > 0 && Speed > 0 */
    void setMaxSpeed(double);
    void setElevationGained(double);
    void setElevationLost(double);
    void setElevationMax(double);
    void setElevationMin(double);
    void setMinHeartBpm(int);
    void setAverageHeartBpm(int);
    void setMaxHeartBpm(int);
    void setAverageCadence(int);
    void setMaxCadence(int);
    void setTotalCalories(int);

    /* Retrieve the Course Data */
    int getTotalTrackpoints();
    int getElapsedTime();
    int getActivityTime();
    int getMovingTime();
    double getDistance();
    double getAverageActivitySpeed();
    double getAverageMovingSpeed();
    double getMaxSpeed();
    double getElevationGained();
    double getElevationLost();
    double getElevationMax();
    double getElevationMin();
    int getMinHeartBpm();
    int getAverageHeartBpm();
    int getMaxHeartBpm();
    int getAverageCadence();
    int getMaxCadence();
    int getTotalCalories();

    /* Retrieve the Lap vector */
    vector<Lap>& getLaps();
};

#endif // COURSE_HPP
