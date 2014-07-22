#include "trackpoint.hpp"

/* Set the trackpoint data */
void Trackpoint::setDate(const string& date) { m_strdate = {date}; }

void Trackpoint::setTime(const string& time) { m_strtime = {time}; }

void Trackpoint::setLatitude(double latitude) { m_dlatitude = {latitude}; }

void Trackpoint::setLongitude(double longitude) { m_dlongitude = {longitude}; }

void Trackpoint::setAltitude(double altitude) { m_daltitude = {altitude}; }

void Trackpoint::setDistance(double distance) { m_ddistance = {distance}; }

void Trackpoint::setHeartBpm(int bpm) { m_nheartbpm = {bpm}; }

void Trackpoint::setCadence(int cadence) { m_ncadence = {cadence}; }

void Trackpoint::setSpeed(double speed) { m_dspeed = {speed}; }


/* Retrieve the trackpoint data */
int Trackpoint::getLap() { return m_nlap; }

int Trackpoint::getTp() { return m_ntp; }

string Trackpoint::getDate() { return m_strdate; }

string Trackpoint::getTime() { return m_strtime; }

double Trackpoint::getLatitude() { return m_dlatitude; }

double Trackpoint::getLongitude() { return m_dlongitude; }

double Trackpoint::getAltitude() { return m_daltitude; }

double Trackpoint::getDistance() { return m_ddistance; }

int Trackpoint::getHeartBpm() { return m_nheartbpm; }

int Trackpoint::getCadence() { return m_ncadence; }

double Trackpoint::getSpeed() { return m_dspeed; }


/* Set the gained information after database retrieval */
void Trackpoint::setTimeGained(int time_gained) { m_ntime_gained = {time_gained}; }

void Trackpoint::setDistanceGained(double distance_gained) { m_ddistance_gained = {distance_gained}; }

void Trackpoint::setAltitudeGained(double altitude_gained) { m_daltitude_gained = {altitude_gained}; }


/* Retrieve this gained information */
int Trackpoint::getTimeGained() { return m_ntime_gained; }

double Trackpoint::getDistanceGained() { return m_ddistance_gained; }

double Trackpoint::getAltitudeGained() { return m_daltitude_gained; }
