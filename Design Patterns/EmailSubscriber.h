#ifndef EMAIL_SUBSCRIBER
#define EMAIL_SUBSCRIBER
#include "Subscriber.h"
#include <string>

class EmailSubscriber : public Subscriber{
public:
    EmailSubscriber(std::string);
private:
    EmailSubscriber();

};

#endif // EMAIL_SUBSCRIBER
