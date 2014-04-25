#ifndef BUSINESS_PUBLISHER
#define BUSINESS_PUBLISHER
#include "NewsPublisher.h"
#include <string>

class BusinessPublisher : public NewsPublisher{
public:
    BusinessPublisher(std::string);
private:
    BusinessPublisher();

};

#endif BUSINESS_PUBLISHER


