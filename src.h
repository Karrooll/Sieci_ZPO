//
// Created by Karol on 17.12.2024.
//
#ifndef SRC_H
#define SRC_H
#endif //SRC_H

enum class QueueType {
    Fifo, Lifo
};



class Package {
    public:
    Package();
    Package(ElementID): ElementID(ElementID) {}
    Package(Package&&);
    operator = (Package&&);
    get_id() {
        return ElementID;
    }
    ~Package();
    private:
    std::string ElementID;

};