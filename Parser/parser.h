#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>
#include <math.h>
#include <cmath> 
#include "../Graph/graph.h"
#include "../Graph/UndirectedGraph.h"
#include "../Graph/DirectedGraph.h"
#include <string>

#define pi 3.14159265358979323846
using namespace std;


class Parser {
    private:
        Json::Value objs;

    public:
        Parser() {};
        ~Parser() {
            clear();
        };

        void clear(){
            objs.clear();
        }

        void readJSON(string pathFile){
            ifstream ifs(pathFile);
            Json::Reader reader;
            reader.parse(ifs, this->objs);
        }
        void uGraphMake(UnDirectedGraph<string, double>*& graph) {

            for (Json::Value::ArrayIndex i = 0; i < this->objs.size(); i++)
                graph->insertVertex(this->objs[i]["Airport ID"].asString(), this->objs[i]["Airport ID"].asString());

            for (Json::Value::ArrayIndex i = 0; i < this->objs.size(); i++){                
                for (int e = 0; e < this->objs[i]["destinations"].size(); e++) {
                    double distance;
                    for (Json::Value::ArrayIndex j = 0; j < this->objs.size(); j++){
                        if (this->objs[j]["Airport ID"].asString() == this->objs[i]["destinations"][e].asString()){
                            distance = calculateDistance(stod(this->objs[i]["Latitude"].asString()), stod(this->objs[i]["Longitude"].asString()),
                                                         stod(this->objs[j]["Latitude"].asString()), stod(this->objs[j]["Longitude"].asString()));
                            graph->createEdge(this->objs[i]["Airport ID"].asString(), this->objs[j]["Airport ID"].asString(), distance);
                            break;
                        }
                    }
                }
            }
        }
        void dGraphMake(DirectedGraph<string, double>*& graph) {
            for (Json::Value::ArrayIndex i = 0; i < this->objs.size(); i++)
                graph->insertVertex(this->objs[i]["Airport ID"].asString(), this->objs[i]["Airport ID"].asString());

            for (Json::Value::ArrayIndex i = 0; i < this->objs.size(); i++){                
                for (int e = 0; e < this->objs[i]["destinations"].size(); e++) {
                    double distance;
                    for (Json::Value::ArrayIndex j = 0; j < this->objs.size(); j++){
                        if (this->objs[j]["Airport ID"].asString() == this->objs[i]["destinations"][e].asString()){
                            distance = calculateDistance(stod(this->objs[i]["Latitude"].asString()), stod(this->objs[i]["Longitude"].asString()),
                                                         stod(this->objs[j]["Latitude"].asString()), stod(this->objs[j]["Longitude"].asString()));
                            graph->createEdge(this->objs[i]["Airport ID"].asString(), this->objs[j]["Airport ID"].asString(), distance);
                            break;
                        }
                    }
                }
            }
        }
        unordered_map<string, double> getHeuristic(string id_target) {
            unordered_map<string, double> heuristic;
            double target_lat = 0.0;
            double target_lon = 0.0;
            for (Json::Value::ArrayIndex i = 0; i != this->objs.size(); i++){
                if (this->objs[i]["Airport ID"].asString() == id_target){
                    target_lat = stod(this->objs[i]["Latitude"].asString());
                    target_lon = stod(this->objs[i]["Longitude"].asString());
                    break;
                }
            }
            for (Json::Value::ArrayIndex i = 0; i != this->objs.size(); i++){
                if (this->objs[i]["Airport ID"].asString() != id_target){
                    double distance = calculateDistance(stod(this->objs[i]["Latitude"].asString()), stod(this->objs[i]["Longitude"].asString()),
                                                        target_lat, target_lon);
                    heuristic[this->objs[i]["Airport ID"].asString()] = distance;
                }
            }
            return heuristic;
        }

    private:
        double DegtoRad(double degree) {
            return degree * pi / 180 ;
        }

        double calculateDistance(double lat1, double long1, double lat2, double long2) {
            double dist;
            lat1 = DegtoRad(lat1); lat2 = DegtoRad(lat2);
            long1 = DegtoRad(long1); long2 = DegtoRad(long2);
            
            double u = sin((lat2 - lat1)/2);
            double v = sin((long2 - long1)/2);
            return 2.0 * 6371.0 * asin(sqrt(u * u + cos(lat1) * cos(lat2) * v * v));
        }


};


#endif