/*
   First Partial Evaluation
   Data Structures TC1018.1
   January 2016

    Name: Jose Manuel Beauregard Mendez
    ID Number: A01021716
    Compiler: Windows Console

    Complete the program accroding to the requirements
*/
/*
   Class to store information of newborn babies
*/

#include <string>
#include <iostream>

class NewBorn {
    private:
        std::string name;
        double apgar;
        double height;
        double weight;
    public:
        NewBorn () {}
        NewBorn (std::string _name, double _apgar, double _height, double _weight);
        double get_apgar() const { return apgar; }
        double get_weight() const { return weight; }
        double get_height() const { return height; }
        ///// EXAM QUESTION /////
        // Create overload operators for < and >
        friend std::ostream & operator<< (std::ostream & stream, const NewBorn & baby);
        bool operator< (const NewBorn & other);
        bool operator> (const NewBorn & other);
};




NewBorn::NewBorn (std::string _name, double _apgar, double _height, double _weight)
{
    name = _name;
    apgar = _apgar;
    height = _height;
    weight = _weight;
}

std::ostream & operator<< (std::ostream & stream, const NewBorn & baby)
{
    stream << "APGAR: " << baby.apgar << " | Weight: " << baby.weight << " | Height: " << baby.height << " | Name: " << baby.name << std::endl;
    return stream;
}

bool NewBorn::operator< (const NewBorn & other)
{
    if (apgar > other.apgar)
        return false;
    else if (apgar < other.apgar)
        return true;
    else if(apgar == other.apgar)
    {
        if(weight > other.weight) 
            return false;
        else if(weight < other.weight) 
            return true;
        else if (weight == other.weight)
        {
            if(height < other.height) 
                return true;
            else 
                return false;
        }
    }
}

bool NewBorn::operator> (const NewBorn & other)
{
    if (apgar < other.apgar)
        return false;
    else if (apgar > other.apgar)
        return true;
    else if (apgar == other.apgar)
    {
        if (weight < other.weight)
            return false;
        else if (weight > other.weight)
            return true;
        else if (weight == other.weight)
        {
            if (height < other.height)
                return false;
            else 
                return true;

        }
    }
}