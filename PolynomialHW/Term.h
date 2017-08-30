/*
   Gilberto Echeverria

   Class for the terms in a polynomial
*/


class Term {
    private:
        double constant;
        int exponent;
    public:
        // Constructors
        Term () {}
        Term (double _constant, int _exponent) : constant(_constant), exponent(_exponent) {}
        // Operators
        void operator = (const Term & other);
        Term operator + (const Term & other);
        Term operator - (const Term & other);
        bool operator < (const Term & other);
        bool operator > (const Term & other);
        bool operator == (const Term & other);
        bool operator != (const Term & other);
        friend std::ostream& operator<< (std::ostream& stream, const Term& term);
        // Access methods
        double getConstant() { return constant; }
        double getExponent() { return exponent; }
        void setConstant(double _constant) { constant = _constant; }
        void setExponent(double _exponent) { exponent = _exponent; }
};

/*
   Term assignment
*/
void Term::operator = (const Term & other)
{
    constant = other.constant;
    exponent = other.exponent;
}

/*
   Addition of two "like" terms
*/
Term Term::operator + (const Term & other)
{
    Term result;
    result.constant = constant + other.constant;
    result.exponent = exponent;
    return result;
}

/*
   Vector substraction
*/
Term Term::operator - (const Term & other)
{
    Term result;
    result.constant = constant - other.constant;
    result.exponent = exponent;
    return result;
}

/*
   Term less than comparison
   Compares only the exponents
*/
bool Term::operator < (const Term & other)
{
    return (exponent < other.exponent);
}

/*
   Term greater than comparison
   Compares only the exponents
*/
bool Term::operator > (const Term & other)
{
    return (exponent > other.exponent);
}

/*
   Term comparison
   Compares only the exponents
*/
bool Term::operator == (const Term & other)
{
    //return (exponent == other.exponent && constant == other.constant);
    return (exponent == other.exponent);
}

/*
   Term comparison
   Compares only the exponents
*/
bool Term::operator != (const Term & other)
{
    //return (exponent != other.exponent || constant != other.constant);
    return (exponent != other.exponent);
}

/*
    Overload for output stream operator.
    Based on the example at:
    http://www.learncpp.com/cpp-tutorial/93-overloading-the-io-operators/
*/
std::ostream & operator << (std::ostream & out, const Term & term)
{
    // Since operator<< is a friend of the Term class, we can access
    // Term's members directly.
    out << term.constant;
    if (term.exponent == 1)
        out << "x";
    else if (term.exponent > 1)
        out << "x^" << term.exponent;
    return out;
}