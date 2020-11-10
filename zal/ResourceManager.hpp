#pragma once

#include "Resource.hpp"
using namespace std;


class ResourceManager
{
  public:
    Resource* res;

    ResourceManager()
    {
      res= new Resource;
    };

    ResourceManager(const ResourceManager& xd) {
      res = new Resource(*(xd.res)); 
      }

    ResourceManager& operator=(const ResourceManager&  resM)
    {
      if (this != &resM)
       {
             *res = *(resM.res);
       }
       return *this;
    }
    ResourceManager(ResourceManager&& resM) : res(resM.res)
    {
        resM.res         = nullptr;
    }
    ResourceManager& operator=(ResourceManager&& resM )
    {
        if (&resM == this)
        {
            return *this;
            delete res;
            res=resM.res;
            resM.res = nullptr;
            return *this;
        }
    }
    ~ResourceManager()
    {
        delete res;
    }
    double get() { return res->get(); };  
};
