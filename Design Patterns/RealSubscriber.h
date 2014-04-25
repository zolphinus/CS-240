#ifndef REAL_SUBSCRIBER
#define REAL_SUBSCRIBER
#include "Subscriber.h"

class RealSubscriber : public Subscriber{
public:
    void update(NewsPublisher&);

};

#endif // REAL_SUBSCRIBER
