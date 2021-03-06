#include <utility>

// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include <memory>
#include "Rental.h"

class Customer {
public:
    Customer();
    explicit Customer( std::string  name );

    virtual void addRental( const std::shared_ptr<Rental> arg );
    std::string getName() const;
    std::string statement();
    virtual double getTotalAmount();
    virtual int getTotalPoint();
    virtual std::string getRentalList();

private:
    std::string _name;
    std::vector< std::shared_ptr<Rental> > _rentals;
};

inline Customer::
Customer() = default;

inline Customer::
Customer( std::string  name )
        : _name(std::move( name )) {}

inline void Customer::
addRental( std::shared_ptr<Rental> arg ) { _rentals.push_back( std::move(arg) ); }

inline std::string Customer::
getName() const { return _name; }

#endif // CUSTOMER_H