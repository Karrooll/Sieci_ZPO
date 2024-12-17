#ifndef PACKAGE_H
#define PACKAGE_H

#include "types.h"
#include <set>

class Package {
public:
    Package();
    Package(ElementID ID) : ID_{ID} {assigned_IDs.insert(ID);}
    Package(Package &&package) : ID_{package.ID_} {}

    Package(const Package& other) : ID_{other.ID_} {
        assigned_IDs.insert(ID_);
    }

    Package& operator=(const Package& other) {
        if (this != &other) {
            ID_ = other.ID_;
            assigned_IDs.insert(ID_);
        }
        return *this;
    }

    Package& operator=(Package&& package) noexcept;
    ElementID get_id() const {return ID_;}

    ~Package();

private:
    ElementID ID_;
    static std::set<ElementID>  freed_IDs;
    static std::set<ElementID>  assigned_IDs;

};

#endif

