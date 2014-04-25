#ifndef SUBSCRIBER
#define SUBSCRIBER
#include <string>

class NewsPublisher;

class Subscriber{
public:
    void update(NewsPublisher&);
    ~Subscriber();

protected:
    Subscriber();
    std::string myName;
    std::string myMedium;


};




#endif // SUBSCRIBER
