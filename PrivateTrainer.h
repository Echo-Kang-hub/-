#pragma once
#include <string>
#include <vector>
using namespace std;

class PrivateTrainer 
{
private:
    string name;

    string specialties;  // 擅长的领域，比如 "力量训练"、"瑜伽"、"有氧运动" 等
public:

    PrivateTrainer(const string& n, const string& spec): name(n), specialties(spec) {}

    void showInfo()const
    {
        cout << name << "-" << specialties << endl;
    }
};