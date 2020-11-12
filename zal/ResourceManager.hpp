#pragma once
#include <iostream>
#include "Resource.hpp"
using namespace std;

class ResourceManager
{
public:

  ResourceManager() {
      nowy = new Resource;
  }

  ResourceManager(ResourceManager&& res){
        nowy   = res.nowy;
        res.nowy = nullptr;
    }

  ResourceManager& operator=(ResourceManager&& opp){
    if (&opp == this){
            return *this;
        delete nowy;
        nowy       = opp.nowy;
        opp.nowy = nullptr;
        return *this;
    }
  }

  ResourceManager(const ResourceManager& kop){
    nowy = new Resource;
    *nowy = *kop.nowy;
  }

  ResourceManager& operator=(const ResourceManager& przypis){
   if (this != &przypis){
            *nowy= *przypis.nowy;
        return *this;
     }
  }

  double get(){
    return nowy->get();
   }

  ~ResourceManager(){
     delete nowy;
    }
  private:
    Resource *nowy;

};