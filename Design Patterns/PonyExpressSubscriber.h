#ifndef PONY_EXPRESS_SUBSCRIBER
#define PONY_EXPRESS_SUBSCRIBER
#include "Subscriber.h"
#include <string>

class PonyExpressSubscriber : public Subscriber{
public:
    PonyExpressSubscriber(std::string);
private:
    PonyExpressSubscriber();

};

#endif PONY_EXPRESS_SUBSCRIBER

