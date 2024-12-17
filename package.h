
#ifndef PACKAGE_H
#define PACKAGE_H
#include <set>

#endif //PACKAGE_H
#include "types.h"

class Package {
    public:
    Package();
    Package(ElementID ID){ID_ = ID;}
    Package(Package &&package){ID_(package.ID_);}
    ~Package();

    Package& operator=(Package&& package);
    ElementID get_id(){return ID_;}


    private:
    ElementID ID_;
    static std::set<ElementID>  assigned_IDs;
    static std::set<ElementID>  freed_IDs;

};
