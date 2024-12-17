//
// Created by Karol on 17.12.2024.
//

#include "package.h"


Package::Package()
{
    if (freed_IDs.empty() == true)
    {
        if (assigned_IDs.empty() == true){
            ID_ = 1;
        }
        int max_ID = *std::max(assigned_IDs.begin(), assigned_IDs.end()) + 1;
        assigned_IDs.insert(assigned_IDs.end(), max_ID);
        ID_ = max_ID;
    }
    else {
        ID_ = *freed_IDs.begin();
        freed_IDs.erase(freed_IDs.begin());
    }

}

Package::~Package() {
    assigned_IDs.erase(assigned_IDs.find(ID_));
    freed_IDs.insert(freed_IDs.end(), ID_);
}

Package& Package::operator=(Package&& package) {
    if (this == &package)
    {
        return *this;
    }
    assigned_IDs.erase(this -> ID_);
    freed_IDs.insert(this -> ID_);
    this -> ID_ = package.ID_;
    assigned_IDs.insert(this -> ID_);
    return *this;
}