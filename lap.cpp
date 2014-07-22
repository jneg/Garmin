#include "lap.hpp"

/* Set the lap data */
void Lap::setDate(const string& date) { m_strdate = {date}; }

void Lap::setTime(const string& date) { m_strtime = {date}; }

void Lap::setTotalSec(double totalsec) { m_dtotalsec = {totalsec}; }

void Lap::setDistance(double distance) { m_ddistance = {distance}; }

void Lap::setMaxSpeed(double maxspeed) { m_dmaxspeed = {maxspeed}; }

void Lap::setCalories(int calories) { m_ncalories = {calories}; }

void Lap::setAverageBpm(int averagebpm) { m_naveragebpm = {averagebpm}; }

void Lap::setMaxBpm(int maxbpm) { m_nmaxbpm = {maxbpm}; }

void Lap::setIntensity(const string& intensity) { m_strintensity = {intensity}; }

void Lap::setCadence(int cadence) { m_ncadence = {cadence}; }

void Lap::setTriggerMethod(const string& triggermethod) { m_strtriggermethod = {triggermethod}; }


/* Retrieve the lap data */
int Lap::getLap() { return m_nlap; }

string Lap::getDate() { return m_strdate; }

string Lap::getTime() { return m_strtime; }

double Lap::getTotalSec() { return m_dtotalsec; }

double Lap::getDistance() { return m_ddistance; }

double Lap::getMaxSpeed() { return m_dmaxspeed; }

int Lap::getCalories() { return m_ncalories; }

int Lap::getAverageBpm() { return m_naveragebpm; }

int Lap::getMaxBpm() { return m_nmaxbpm; }

string Lap::getIntensity() { return m_strintensity; }

int Lap::getCadence() { return m_ncadence; }

string Lap::getTriggerMethod() { return m_strtriggermethod; }


/* Set the Calculated Lap Data */
void Lap::setTotalTrackpoints(int number) { m_ntotaltrackpoints = {number}; }

void Lap::setElapsedTime(int elapsedTime) { m_nelapsedtime = {elapsedTime}; }

void Lap::setActivityTime(int activityTime) { m_nactivitytime = {activityTime}; }

void Lap::setMovingTime(int movingTime) { m_nmovingtime = {movingTime}; }

void Lap::setCalculatedDistance(double calculateddistance) { m_dcalculateddistance = {calculateddistance}; }

void Lap::setAverageActivitySpeed(double activitySpeed) { m_daverageactivityspeed = {activitySpeed}; }

void Lap::setAverageMovingSpeed(double movingSpeed) { m_daveragemovingspeed = {movingSpeed}; }

void Lap::setCalculatedMaxSpeed(double maxSpeed) { m_dcalculatedmaxspeed = {maxSpeed}; }

void Lap::setElevationGained(double elevationGained) { m_delevationgained = {elevationGained}; }

void Lap::setElevationLost(double elevationLost) { m_delevationlost = {elevationLost}; }

void Lap::setElevationMax(double elevationMax) { m_delevationmax = {elevationMax}; }

void Lap::setElevationMin(double elevationMin) { m_delevationmin = {elevationMin}; }

void Lap::setMinHeartBpm(int minHeartBpm) { m_nminheartbpm = {minHeartBpm}; }

void Lap::setAverageHeartBpm(int averageHeartBpm) { m_naverageheartbpm = {averageHeartBpm}; }

void Lap::setMaxHeartBpm(int maxHeartBpm) { m_nmaxheartbpm = {maxHeartBpm}; }

void Lap::setAverageCadence(int averageCadence) { m_naveragecadence = {averageCadence}; }

void Lap::setMaxCadence(int maxCadence) { m_nmaxcadence = {maxCadence}; }


/* Retrieve the Calculated Lap Data */
int Lap::getTotalTrackpoints() { return m_ntotaltrackpoints; }

int Lap::getElapsedTime() { return m_nelapsedtime; }

int Lap::getActivityTime() { return m_nactivitytime; }

int Lap::getMovingTime() { return m_nmovingtime; }

double Lap::getCalculatedDistance() { return m_dcalculateddistance; }

double Lap::getAverageActivitySpeed() { return m_daverageactivityspeed; }

double Lap::getAverageMovingSpeed() { return m_daveragemovingspeed; }

double Lap::getCalculatedMaxSpeed() { return m_dcalculatedmaxspeed; }

double Lap::getElevationGained() { return m_delevationgained; }

double Lap::getElevationLost() { return m_delevationlost; }

double Lap::getElevationMax() { return m_delevationmax; }

double Lap::getElevationMin() { return m_delevationmin; }

int Lap::getMinHeartBpm() { return m_nminheartbpm; }

int Lap::getAverageHeartBpm() { return m_naverageheartbpm; }

int Lap::getMaxHeartBpm() { return m_nmaxheartbpm; }

int Lap::getAverageCadence() { return m_naveragecadence; }

int Lap::getMaxCadence() { return m_nmaxcadence; }


/* Retrieve the Trackpoint vector */
vector<Trackpoint>& Lap::getTrackpoints() { return m_cpoints; }
