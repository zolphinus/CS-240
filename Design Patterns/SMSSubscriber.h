#ifndef SMS_SUBSCRIBER
#define SMS_SUBSCRIBER
#include "Subscriber.h"
#include <string>

class SMSSubscriber : public Subscriber{
public:
    SMSSubscriber(std::string);
private:
    SMSSubscriber();

};

#endif SMS_SUBSCRIBER

