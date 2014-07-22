#include "course.hpp"
#include <iostream>

/* Set the Course Data */
void Course::setTotalTrackpoints(int number) { m_ntotaltrackpoints = {number}; }

void Course::setElapsedTime(int elapsedTime) { m_nelapsedtime = {elapsedTime}; }

void Course::setActivityTime(int activityTime) { m_nactivitytime = {activityTime}; }

void Course::setMovingTime(int movingTime) { m_nmovingtime = {movingTime}; }

void Course::setDistance(double distance) { m_ddistance = {distance}; }

void Course::setAverageActivitySpeed(double activitySpeed) { m_daverageactivityspeed = {activitySpeed}; }

void Course::setAverageMovingSpeed(double movingSpeed) { m_daveragemovingspeed = {movingSpeed}; }

void Course::setMaxSpeed(double maxSpeed) { m_dmaxspeed = {maxSpeed}; }

void Course::setElevationGained(double elevationGained) { m_delevationgained = {elevationGained}; }

void Course::setElevationLost(double elevationLost) { m_delevationlost = {elevationLost}; }

void Course::setElevationMax(double elevationMax) { m_delevationmax = {elevationMax}; }

void Course::setElevationMin(double elevationMin) { m_delevationmin = {elevationMin}; }

void Course::setMinHeartBpm(int minHeartBpm) { m_nminheartbpm = {minHeartBpm}; }

void Course::setAverageHeartBpm(int averageHeartBpm) { m_naverageheartbpm = {averageHeartBpm}; }

void Course::setMaxHeartBpm(int maxHeartBpm) { m_nmaxheartbpm = {maxHeartBpm}; }

void Course::setAverageCadence(int averageCadence) { m_naveragecadence = {averageCadence}; }

void Course::setMaxCadence(int maxCadence) { m_nmaxcadence = {maxCadence}; }

void Course::setTotalCalories(int totalCalories) { m_ntotalcalories = {totalCalories}; }


/* Retrieve the Course Data */
int Course::getTotalTrackpoints() { return m_ntotaltrackpoints; }

int Course::getElapsedTime() { return m_nelapsedtime; }

int Course::getActivityTime() { return m_nactivitytime; }

int Course::getMovingTime() { return m_nmovingtime; }

double Course::getDistance() { return m_ddistance; }

double Course::getAverageActivitySpeed() { return m_daverageactivityspeed; }

double Course::getAverageMovingSpeed() { return m_daveragemovingspeed; }

double Course::getMaxSpeed() { return m_dmaxspeed; }

double Course::getElevationGained() { return m_delevationgained; }

double Course::getElevationLost() { return m_delevationlost; }

double Course::getElevationMax() { return m_delevationmax; }

double Course::getElevationMin() { return m_delevationmin; }

int Course::getMinHeartBpm() { return m_nminheartbpm; }

int Course::getAverageHeartBpm() { return m_naverageheartbpm; }

int Course::getMaxHeartBpm() { return m_nmaxheartbpm; }

int Course::getAverageCadence() { return m_naveragecadence; }

int Course::getMaxCadence() { return m_nmaxcadence; }

int Course::getTotalCalories() { return m_ntotalcalories; }


/* Retrieve the Lap vector */
vector<Lap>& Course::getLaps() { return m_claps; }
