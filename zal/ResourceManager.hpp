#pragma once

#include "Resource.hpp"

class ResourceManager
{
  public:
    Resource* res;

    ResourceManager()
    {
      res= new Resource;
    };

    ResourceManager(const ResourceManager& resM) { res = new Resource(*(resM.res)); }

    ResourceManager& operator=(const ResourceManager&  resM)
    {
      if (this != &resM)
       {
             *R = *(resM.res);
       }
       return *this;

    }
    ResourceManager(ResourceManager&& resM) : res(resM.res)
    {
        resM.res         = nullptr;
    }
    ResourceManager& operator=(ResourceManager&& reM )
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
    double get() { return Rres->get(); };  
};
