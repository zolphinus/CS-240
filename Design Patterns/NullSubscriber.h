#ifndef NULL_SUBSCRIBER
#define NULL_SUBSCRIBER

#include "Subscriber.h"
#include <string>

class NullSubscriber : public Subscriber{
public:
    NullSubscriber(std::string);
    void update(NewsPublisher&);
    NullSubscriber();
    ~NullSubscriber();

private:

};


#endif // NULL_SUBSCRIBER
