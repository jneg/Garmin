/*

All coding done by JNeg
Works for Garmin xml or tcx files

*/

#include "course.hpp"
#include "lap.hpp"
#include "trackpoint.hpp"
#include "BadTrackpoint.hpp"
#include <iostream>
#include <fstream>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <numeric>
using namespace std;

void parseFile(Course& trip, char* filename)
{
    /* Create an input file stream called xmlfile to open the file we input */
    ifstream xmlfile {filename};
    assert(xmlfile.is_open() && "Error: Could not open XML File");

    /* Create two temporary strings and integers for parsing purposes */
    string strline;
    string strsub;
    int nlapnum {-1};
    int ntracknum {-1};


    /* Run through the XML File until the end of file */
    while(!xmlfile.eof())
    {
        /* Skip any whitespaces in the beginning of the line */
        while(xmlfile.peek() == ' ')
        {
            xmlfile.get();
        }

        /* Get the rest of the line until the newline character */
        getline(xmlfile, strline);

        /* Check the line for a '>' character */
        if (count(strline.begin(), strline.end(), '>') > 0)
        {
            /* If we found the start of a Trackpoint, create a trackpoint */
            strsub = strline.substr(1, strline.find(">") - 1);
            if (strsub == "Trackpoint")
            {
                /* Push in a new Trackpoint to this Lap's Trackpoint vector */
                ntracknum++;
                trip.getLaps().at(nlapnum).getTrackpoints().push_back(Trackpoint {nlapnum, ntracknum});

                /* Add in Trackpoint data */
                while(!xmlfile.eof())
                {
                    /* Skip any whitespaces in the beginning of the line */
                    while(xmlfile.peek() == ' ')
                    {
                        xmlfile.get();
                    }

                    /* Find the next keyword */
                    getline(xmlfile, strline);
                    strsub = strline.substr(1, strline.find('>') - 1);

                    /* Find and set Date and Time */
                    if(strsub == "Time")
                    {
                        strsub = strline.substr(strline.find('>') + 1, 10);
                        trip.getLaps().at(nlapnum).getTrackpoints().at(ntracknum).setDate(strsub);

                        strsub = strline.substr(strline.find('T', strline.find('>')) + 1, 8);
                        trip.getLaps().at(nlapnum).getTrackpoints().at(ntracknum).setTime(strsub);
                    }
                    /* Find and set Latitude */
                    else if(strsub == "LatitudeDegrees")
                    {
                        strsub = strline.substr(strline.find(">") + 1);
                        strsub = strsub.substr(0, strsub.find("</"));
                        trip.getLaps().at(nlapnum).getTrackpoints().at(ntracknum).setLatitude(atof(strsub.c_str()));
                    }
                    /* Find and set Longitude */
                    else if(strsub == "LongitudeDegrees")
                    {
                        strsub = strline.substr(strline.find(">") + 1);
                        strsub = strsub.substr(0, strsub.find("</"));
                        trip.getLaps().at(nlapnum).getTrackpoints().at(ntracknum).setLongitude(atof(strsub.c_str()));
                    }
                    /* Find and set Altitude */
                    else if(strsub == "AltitudeMeters")
                    {
                        strsub = strline.substr(strline.find(">") + 1);
                        strsub = strsub.substr(0, strsub.find("</"));
                        trip.getLaps().at(nlapnum).getTrackpoints().at(ntracknum).setAltitude(atof(strsub.c_str()));
                    }
                    /* Find and set Distance */
                    else if(strsub == "DistanceMeters")
                    {
                        strsub = strline.substr(strline.find(">") + 1);
                        strsub = strsub.substr(0, strsub.find("</"));
                        trip.getLaps().at(nlapnum).getTrackpoints().at(ntracknum).setDistance(atof(strsub.c_str()));
                    }
                    /* Find and set HeartBpm */
                    else if(strsub == "Value")
                    {
                        strsub = strline.substr(strline.find(">") + 1);
                        strsub = strsub.substr(0, strsub.find("</"));
                        trip.getLaps().at(nlapnum).getTrackpoints().at(ntracknum).setHeartBpm(atoi(strsub.c_str()));
                    }
                    /* Find and set Cadence */
                    else if(strsub == "Cadence")
                    {
                        strsub = strline.substr(strline.find(">") + 1);
                        strsub = strsub.substr(0, strsub.find("</"));
                        trip.getLaps().at(nlapnum).getTrackpoints().at(ntracknum).setCadence(atoi(strsub.c_str()));
                    }
                    /* Find and set Speed */
                    else if(strsub == "Speed")
                    {
                        strsub = strline.substr(strline.find(">") + 1);
                        strsub = strsub.substr(0, strsub.find("</"));
                        trip.getLaps().at(nlapnum).getTrackpoints().at(ntracknum).setSpeed(atof(strsub.c_str()));
                    }
                    /* Exit out of the Trackpoint loop */
                    else if(strsub == "/Trackpoint")
                    {
                        break;
                    }
                }
            }
            /* If we found the end of a Lap, reset ntracknum */
            else if(strsub == "/Lap")
            {
                ntracknum = -1;
            }

            /* If we found the start of a Lap, create a lap */
            strsub = strline.substr(1, strline.find(' ') - 1);
            if (strsub == "Lap")
            {
                /* Push in a new Lap to trip.getLaps() */
                nlapnum++;
                trip.getLaps().push_back(Lap {nlapnum});

                /* Set the Date of this Lap */
                strsub = strline.substr(strline.find('"') + 1, 10);
                trip.getLaps().at(nlapnum).setDate(strsub);

                /* Set the Time of this Lap */
                strsub = strline.substr(strline.find("T", strline.find('"')) + 1, 8);
                trip.getLaps().at(nlapnum).setTime(strsub);

                /* Add in Lap data */
                while(!xmlfile.eof())
                {
                    /* Skip any whitespaces in the beginning of the line */
                    while(xmlfile.peek() == ' ')
                    {
                        xmlfile.get();
                    }

                    /* Find the next keyword */
                    getline(xmlfile, strline);
                    strsub = strline.substr(1, strline.find('>') - 1);

                    /* Find and set TotalTimeSeconds */
                    if(strsub == "TotalTimeSeconds")
                    {
                        strsub = strline.substr(strline.find(">") + 1);
                        strsub = strsub.substr(0, strsub.find("</"));
                        trip.getLaps().at(nlapnum).setTotalSec(atof(strsub.c_str()));
                    }
                    /* Find and set DistanceMeters */
                    else if(strsub == "DistanceMeters")
                    {
                        strsub = strline.substr(strline.find(">") + 1);
                        strsub = strsub.substr(0, strsub.find("</"));
                        trip.getLaps().at(nlapnum).setDistance(atof(strsub.c_str()));
                    }
                    /* Find and set MaximumSpeed */
                    else if(strsub == "MaximumSpeed")
                    {
                        strsub = strline.substr(strline.find(">") + 1);
                        strsub = strsub.substr(0, strsub.find("</"));
                        trip.getLaps().at(nlapnum).setMaxSpeed(atof(strsub.c_str()));
                    }
                    /* Find and set Calories */
                    else if(strsub == "Calories")
                    {
                        strsub = strline.substr(strline.find(">") + 1);
                        strsub = strsub.substr(0, strsub.find("</"));
                        trip.getLaps().at(nlapnum).setCalories(atoi(strsub.c_str()));
                    }
                    /* Find and set AverageHeartRateBpm */
                    else if(strsub == "AverageHeartRateBpm")
                    {
                        while(xmlfile.peek() == ' ')
                        {
                            xmlfile.get();
                        }
                        getline(xmlfile, strline);
                        strsub = strline.substr(strline.find(">") + 1);
                        strsub = strsub.substr(0, strsub.find("</"));
                        trip.getLaps().at(nlapnum).setAverageBpm(atoi(strsub.c_str()));
                    }
                    /* Find and set MaximumHeartRateBpm */
                    else if(strsub == "MaximumHeartRateBpm")
                    {
                        while(xmlfile.peek() == ' ')
                        {
                            xmlfile.get();
                        }
                        getline(xmlfile, strline);
                        strsub = strline.substr(strline.find(">") + 1);
                        strsub = strsub.substr(0, strsub.find("</"));
                        trip.getLaps().at(nlapnum).setMaxBpm(atoi(strsub.c_str()));
                    }
                    /* Find and set Intensity */
                    else if(strsub == "Intensity")
                    {
                        strsub = strline.substr(strline.find(">") + 1);
                        strsub = strsub.substr(0, strsub.find("</"));
                        trip.getLaps().at(nlapnum).setIntensity(strsub);
                    }
                    /* Find and set Cadence */
                    else if(strsub == "Cadence")
                    {
                        strsub = strline.substr(strline.find(">") + 1);
                        strsub = strsub.substr(0, strsub.find("</"));
                        trip.getLaps().at(nlapnum).setCadence(atoi(strsub.c_str()));
                    }
                    /* Find and set TriggerMethod */
                    else if(strsub == "TriggerMethod")
                    {
                        strsub = strline.substr(strline.find(">") + 1);
                        strsub = strsub.substr(0, strsub.find("</"));
                        trip.getLaps().at(nlapnum).setTriggerMethod(strsub);
                    }
                    /* Exit out of the Lap loop */
                    else if(strsub == "Track")
                    {
                        break;
                    }
                }
            }
        }
    }

    /* We're done with the XML File, close it */
    xmlfile.close();
}

void calcTrackpointGained(Course& trip)
{
    for(auto l = trip.getLaps().begin(); l != trip.getLaps().end(); ++l)
    {
        for(auto t = trip.getLaps().at(l->getLap()).getTrackpoints().begin(); t != trip.getLaps().at(l->getLap()).getTrackpoints().end(); ++t)
        {
            if(t->getTp() > 0)
            {
                /* Parse Year, Month, Day, Hour, Minute, Second for the previous trackpoint */
                int npYr = atoi((t-1)->getDate().substr(0,4).c_str());
                int npMo = atoi((t-1)->getDate().substr(5,2).c_str());
                int npDay = atoi((t-1)->getDate().substr(8,2).c_str());
                int npHour = atoi((t-1)->getTime().substr(0,2).c_str());
                int npMin = atoi((t-1)->getTime().substr(3,2).c_str());
                int npSec = atoi((t-1)->getTime().substr(6,2).c_str());

                /* Parse Year, Month, Day, Hour, Minute, Second for this trackpoint */
                int nYr = atoi(t->getDate().substr(0,4).c_str());
                int nMo = atoi(t->getDate().substr(5,2).c_str());
                int nDay = atoi(t->getDate().substr(8,2).c_str());
                int nHour = atoi(t->getTime().substr(0,2).c_str());
                int nMin = atoi(t->getTime().substr(3,2).c_str());
                int nSec = atoi(t->getTime().substr(6,2).c_str());

                /* If the month is not within 1-12, throw an BadTrackpoint Exception */
                if(nMo < 1 || nMo > 12) { throw BadTrackpoint{l->getLap(), t->getTp(), "Month not between 1-12!"}; }

                /* If the day is not correct for the month, throw an BadTrackpoint Exception */
                if ((nMo == 1) || (nMo == 3) || (nMo == 5) || (nMo == 7) || (nMo == 8) || (nMo == 10) || (nMo == 12))
                {
                    /* If the day is not within 1-31, throw a BadTrackpoint Exception */
                    if(nDay < 1 || nDay > 31) { throw BadTrackpoint{l->getLap(), t->getTp(), "Day not within 1-31!"}; }
                }
                else if((nMo == 4) || (nMo == 6) || (nMo == 9) || (nMo == 11))
                {
                    /* If the day is not within 1-30, throw a BadTrackpoint Exception */
                    if(nDay < 1 || nDay > 30) { throw BadTrackpoint{l->getLap(), t->getTp(), "Day not within 1-30!"}; }
                }
                else if(nMo==2)
                {
                    /* If it is February of a leap year and the day is not within 1-29, throw a BadTrackpoint Exception */
                    if( ((nYr % 4) == 0) && ( ((nYr % 100) != 0) || ((nYr % 400) == 0) ) )
                    {
                        if(nDay < 1 || nDay > 29) { throw BadTrackpoint{l->getLap(), t->getTp(), "Day not within 1-29!"}; }
                    }
                    /* If it is February and the day is not within 1-29, throw a BadTrackpoint Exception */
                    else
                    {
                        if(nDay < 1 || nDay > 28) { throw BadTrackpoint{l->getLap(), t->getTp(), "Day not within 1-28!"}; }
                    }
                }

                /* If the hour is not within 0-23, throw an incorrectHour Exception */
                if(nHour < 0 || nHour > 23) { throw BadTrackpoint{l->getLap(), t->getTp(), "Hour not within 0-23!"}; }

                /* If the minute is not within 0-59, throw an incorrectMinute Exception */
                if(nMin < 0 || nMin > 59) { throw BadTrackpoint{l->getLap(), t->getTp(), "Minute not within 0-59!"}; }

                /* If the second is not within 0-59, throw an incorrectSecond Exception */
                if(nSec < 0 || nSec > 59) { throw BadTrackpoint{l->getLap(), t->getTp(), "Second not within 0-59!"}; }

                /* If the times are within the same LEAP year, calculate time gained */
                if(npYr == nYr && ((nYr % 4) == 0) && ( ((nYr % 100) != 0) || ( (nYr % 400) == 0) ))
                {
                    vector<int> months = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

                    t->setTimeGained( (24*3600*(accumulate(months.begin()+npMo-1,months.begin()+nMo,0))) + (24*3600*(nDay - npDay)) + (3600*(nHour - npHour)) + (60*(nMin - npMin)) + (nSec - npSec) );
                }
                /* If the times are within the same year, calculate time gained */
                else if(npYr == nYr)
                {
                    vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

                    t->setTimeGained( (24*3600*(accumulate(months.begin()+npMo,months.begin()+nMo,0))) + (24*3600*(nDay - npDay)) + (3600*(nHour - npHour)) + (60*(nMin - npMin)) + (nSec - npSec) );
                }

                /* Calculate the Distance gained for each trackpoint */
                t->setDistanceGained(t->getDistance()-(t-1)->getDistance());

                /* Calculate the Altitude gained for each trackpoint */
                t->setAltitudeGained(t->getAltitude()-(t-1)->getAltitude());
            }
        }
    }
}

void calcLaps(Course& trip)
{
    /* Loop through every Lap and input Lap data from its Trackpoints */
    for(auto l = trip.getLaps().begin(); l != trip.getLaps().end(); ++l)
    {
        /* Lap Times */
        int nelapsedtime {0};
        int nactivitytime {0};
        int nmovingtime {0};

        /* Lap Distance */
        double dlapdistance {0};

        /* Lap Calculated Max Speed */
        double dmaxspeed {0};

        /* Lap Elevations */
        double delevationgain {0};
        double delevationloss {0};
        double delevationmax {0};
        double delevationmin {1000};

        /* Lap Heart Rates */
        int nmaxheartbpm {0};
        int ntotalheartbpm {0};
        int nminheartbpm {1000};

        /* Lap Cadences */
        int nmaxcadence {0};
        int ntotalcadence {0};

        /* Loop through every trackpoint in the Lap and calculate Lap data */
        for(auto t = trip.getLaps().at(l->getLap()).getTrackpoints().begin(); t != trip.getLaps().at(l->getLap()).getTrackpoints().end(); ++t)
        {
            nelapsedtime += t->getTimeGained();
            if(t->getDistanceGained() > 0)
            {
                nactivitytime += t->getTimeGained();
                if(t->getSpeed() > 0)
                {
                    nmovingtime += t->getTimeGained();
                }
            }

            dlapdistance += t->getDistanceGained();

            if(t->getSpeed() > dmaxspeed)
            {
                dmaxspeed = t->getSpeed();
            }

            if(t->getAltitudeGained() > 0)
            {
                delevationgain += t->getAltitudeGained();
            }
            else if(t->getAltitudeGained() < 0)
            {
                delevationloss += t->getAltitudeGained();
            }
            if(t->getAltitude() > delevationmax)
            {
                delevationmax = t->getAltitude();
            }
            if(t->getAltitude() < delevationmin)
            {
                delevationmin = t->getAltitude();
            }

            ntotalheartbpm += t->getHeartBpm();
            if(t->getHeartBpm() > nmaxheartbpm)
            {
                nmaxheartbpm = t->getHeartBpm();
            }
            if(t->getHeartBpm() < nminheartbpm)
            {
                nminheartbpm = t->getHeartBpm();
            }

            ntotalcadence += t->getCadence();
            if(t->getCadence() > nmaxcadence)
            {
                nmaxcadence = t->getCadence();
            }
        }

        /* Set all Lap data */
        l->setTotalTrackpoints(l->getTrackpoints().size());
        l->setElapsedTime(nelapsedtime);
        l->setActivityTime(nactivitytime);
        l->setMovingTime(nmovingtime);
        l->setCalculatedDistance(dlapdistance);
        l->setAverageActivitySpeed(3.6*(l->getCalculatedDistance()/l->getActivityTime()));
        l->setAverageMovingSpeed(3.6*(l->getCalculatedDistance()/l->getMovingTime()));
        l->setCalculatedMaxSpeed(3.6*dmaxspeed);
        l->setElevationGained(delevationgain);
        l->setElevationLost(delevationloss);
        l->setElevationMax(delevationmax);
        l->setElevationMin(delevationmin);
        l->setMaxHeartBpm(nmaxheartbpm);
        l->setAverageHeartBpm(ntotalheartbpm/trip.getLaps().at(l->getLap()).getTrackpoints().size());
        l->setMinHeartBpm(nminheartbpm);
        l->setMaxCadence(nmaxcadence);
        l->setAverageCadence(ntotalcadence/trip.getLaps().at(l->getLap()).getTrackpoints().size());
    }
}

void calcCourse(Course& trip)
{
    /* Course Total Trackpoints */
    int ntotaltrackpoints {0};

    /* Course Time */
    int nelapsedtime {0};
    int nactivitytime {0};
    int nmovingtime {0};

    /* Course Distance */
    double ddistance {0};

    /* Course Speed */
    double dtotalaverageactivityspeed {0};
    double dtotalaveragemovingspeed {0};
    double dmaxspeed {0};

    /* Course Elevation */
    double delevationgained {0};
    double delevationlost {0};
    double delevationmax {0};
    double delevationmin {1000};

    /* Course Heart Rate */
    int nminheartbpm {1000};
    int ntotalaverageheartbpm {0};
    int nmaxheartbpm {0};

    /* Course Cadence */
    int ntotalaveragecadence {0};
    int nmaxcadence {0};

    /* Course Calories */
    int ntotalcalories {0};

    /* Loop through the vector of laps and calculate Course data */
    for(auto l = trip.getLaps().begin(); l != trip.getLaps().end(); ++l)
    {
        /* Sum the total trackpoints */
        ntotaltrackpoints += l->getTrackpoints().size();

        /* Sum the times */
        nelapsedtime += l->getElapsedTime();
        nactivitytime += l->getActivityTime();
        nmovingtime += l->getMovingTime();

        /* Sum the distances */
        ddistance += l->getCalculatedDistance();

        /* Average the Speeds */
        dtotalaverageactivityspeed += l->getAverageActivitySpeed();
        dtotalaveragemovingspeed += l->getAverageMovingSpeed();
        if(l->getCalculatedMaxSpeed() > dmaxspeed)
        {
            dmaxspeed = l->getCalculatedMaxSpeed();
        }

        /* Sum the Elevations */
        delevationgained += l->getElevationGained();
        delevationlost += l->getElevationLost();
        if(l->getElevationMax() > delevationmax)
        {
            delevationmax = l->getElevationMax();
        }
        if(l->getElevationMin() < delevationmin)
        {
            delevationmin = l->getElevationMin();
        }

        /* Average the Heart rates */
        ntotalaverageheartbpm += l->getAverageHeartBpm();
        if(l->getMaxHeartBpm() > nmaxheartbpm)
        {
            nmaxheartbpm = l->getMaxHeartBpm();
        }
        if(l->getMinHeartBpm() < nminheartbpm)
        {
            nminheartbpm = l->getMinHeartBpm();
        }

        /* Average the Cadences */
        ntotalaveragecadence += l->getAverageCadence();
        if(l->getMaxCadence() > nmaxcadence)
        {
            nmaxcadence = l->getMaxCadence();
        }

        ntotalcalories += l->getCalories();
    }

    /* Set all Course data */
    trip.setTotalTrackpoints(ntotaltrackpoints);
    trip.setElapsedTime(nelapsedtime);
    trip.setActivityTime(nactivitytime);
    trip.setMovingTime(nmovingtime);
    trip.setDistance(ddistance);
    trip.setAverageActivitySpeed(dtotalaverageactivityspeed/trip.getLaps().size());
    trip.setAverageMovingSpeed(dtotalaveragemovingspeed/trip.getLaps().size());
    trip.setMaxSpeed(dmaxspeed);
    trip.setElevationGained(delevationgained);
    trip.setElevationLost(delevationlost);
    trip.setElevationMax(delevationmax);
    trip.setElevationMin(delevationmin);
    trip.setMinHeartBpm(nminheartbpm);
    trip.setAverageHeartBpm(ntotalaverageheartbpm/trip.getLaps().size());
    trip.setMaxHeartBpm(nmaxheartbpm);
    trip.setAverageCadence(ntotalaveragecadence/trip.getLaps().size());
    trip.setMaxCadence(nmaxcadence);
    trip.setTotalCalories(ntotalcalories);
}

void displaySummary(Course& trip)
{
    for(auto l = trip.getLaps().begin(); l != trip.getLaps().end(); ++l)
    {
        cout << "Lap " << l->getLap()+1 << endl;
        cout << "Trackpoints: " << l->getTotalTrackpoints() << endl;
        cout << "Calories Burned: " << l->getCalories() << endl;
        cout << "Date: " << l->getDate() << " (" << l->getTime() << ")" << endl;
        cout << "Elapsed Time: " << l->getElapsedTime()/3600 << ":" << (l->getElapsedTime()%3600)/60 << ":" << (l->getElapsedTime()%3600)%60 << endl;
        cout << "Activity Time: " << l->getActivityTime()/3600 << ":" << (l->getActivityTime()%3600)/60 << ":" << (l->getActivityTime()%3600)%60 << endl;
        cout << "Moving Time: " << l->getMovingTime()/3600 << ":" << (l->getMovingTime()%3600)/60 << ":" << (l->getMovingTime()%3600)%60 << endl;
        cout << "Distance: " << l->getCalculatedDistance() << " m" << endl;
        cout << "Average Activity Speed: " << l->getAverageActivitySpeed() << " km/h" << endl;
        cout << "Average Moving Speed: " << l->getAverageMovingSpeed() << " km/h" << endl;
        cout << "Maximum Speed: " << l->getCalculatedMaxSpeed() << " km/h" << endl;
        cout << "Elevation Gain: " << l->getElevationGained() << " m" << endl;
        cout << "Elevation Loss: " << l->getElevationLost() << " m" << endl;
        cout << "Maximum Elevation: " << l->getElevationMax() << " m" << endl;
        cout << "Minimum Elevation: " << l->getElevationMin() << " m" << endl;
        cout << "Maximum Heart Rate: " << l->getMaxHeartBpm() << " bpm" << endl;
        cout << "Average Heart Rate: " << l->getAverageHeartBpm() << " bpm" << endl;
        cout << "Minimum Heart Rate: " << l->getMinHeartBpm() << " bpm" << endl;
        cout << "Maximum Cadence: " << l->getMaxCadence() << " rpm" << endl;
        cout << "Average Cadence: " << l->getAverageCadence() << " rpm" << endl;
        cout << "\n" << endl;
    }
    cout << "Course Total" << endl;
    cout << "Total Trackpoints: " << trip.getTotalTrackpoints() << endl;
    cout << "Calories Burned: " << trip.getTotalCalories() << endl;
    cout << "Elapsed Time: " << trip.getElapsedTime()/3600 << ":" << (trip.getElapsedTime()%3600)/60 << ":" << (trip.getElapsedTime()%3600)%60 << endl;
    cout << "Activity Time: " << trip.getActivityTime()/3600 << ":" << (trip.getActivityTime()%3600)/60 << ":" << (trip.getActivityTime()%3600)%60 << endl;
    cout << "Moving Time: " << trip.getMovingTime()/3600 << ":" << (trip.getMovingTime()%3600)/60 << ":" << (trip.getMovingTime()%3600)%60 << endl;
    cout << "Distance: " << trip.getDistance() << " m" << endl;
    cout << "Average Activity Speed: " << trip.getAverageActivitySpeed() << " km/h" << endl;
    cout << "Average Moving Speed: " << trip.getAverageMovingSpeed() << " km/h" << endl;
    cout << "Maximum Speed: " << trip.getMaxSpeed() << " km/h" << endl;
    cout << "Elevation Gain: " << trip.getElevationGained() << " m" << endl;
    cout << "Elevation Loss: " << trip.getElevationLost() << " m" << endl;
    cout << "Maximum Elevation: " << trip.getElevationMax() << " m" << endl;
    cout << "Minimum Elevation: " << trip.getElevationMin() << " m" << endl;
    cout << "Maximum Heart Rate: " << trip.getMaxHeartBpm() << " bpm" << endl;
    cout << "Average Heart Rate: " << trip.getAverageHeartBpm() << " bpm" << endl;
    cout << "Minimum Heart Rate: " << trip.getMinHeartBpm() << " bpm" << endl;
    cout << "Maximum Cadence: " << trip.getMaxCadence() << " rpm" << endl;
    cout << "Average Cadence: " << trip.getAverageCadence() << " rpm" << endl;
}

int main(int argc, char** argv)
{
    /* Ensure that we have one argument - our xml filename */
    if(argc != 2)
    {
        cout << "./program <filename>" << endl;
        exit(1);
    }

    /* Construct a Course */
    Course trip;

    /* Insert laps and trackpoints data into trip */
    try { parseFile(trip, argv[1]); }
    catch(...) { cout << "Unknown Exception from parseFile ()" << endl; }

    /* Calculate the time, distance, and altitude gained for each Trackpoint */
    try { calcTrackpointGained(trip); }
    catch(const BadTrackpoint& e) { cout << e.what() << endl; }
    catch(...) { cout << "Unknown Exception from calcTrackpointGained()" << endl; }

    /* Calculate Lap synopsis */
    try { calcLaps(trip); }
    catch(...) { cout << "Unknown Exception from calcLaps()" << endl;  }

    /* Calculate Course synopsis */
    try { calcCourse(trip); }
    catch(...) { cout << "Unknown Exception from calcCourse()" << endl;  }

    /* Print out Lap and Course Summary */
    try { displaySummary(trip); }
    catch(...) { cout << "Unknown Exception from displaySummary()" << endl;  }

    /* Execution was successful */
    return 0;
}
