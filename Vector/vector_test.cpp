/*
   Gilberto Echeverria

   Simple program to try out the 3DVector class
*/

#include <iostream>
#include "Vector3D.h"

using namespace std;

//cd Dropbox\Carrera\Cuarto Semestre\Estructura de Datos\Vector

int main()
{
    Vector3D vec1 (3.6, 5.1, 2.4);
    Vector3D vec2 (2.8, 3.9, 6.7);
    Vector3D vec3;

    vec3 = vec1;

    cout << "Vector 1: " << vec1 << endl;
    cout << "Vector 2: " << vec2 << endl;
    cout << "Vector 3: " << vec3 << endl;

    vec3 = vec1 + vec2;

    cout << "Vector 3: " << vec3 << endl;

    // Compare vectors 1 and 2
    if (vec1 == vec2)
        cout << "V1 == V2" << endl;
    else
        cout << "V1 != V2" << endl;

    vec3 = vec1;

    // Compare vectors 1 and 3
    if (vec1 == vec3)
        cout << "V1 == V3" << endl;
    else
        cout << "V1 != V3" << endl;

    return 0;
}
