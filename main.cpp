
#include "Vector.h"

#include <iostream>
#include <iterator>
using namespace std;

typedef Vector<float,3> V3;
typedef Vector<float,2> V2;

#define PANDE(cmd) cout << #cmd" \t==> " << (cmd) << '\n'
#define TEST(c1,c2) cout << boolalpha << #c1" \t== "#c2" \t==> " << ((c1)==(c2)) << '\n'

// FIXME: {cout << v} never can be deduced to this func when templated. Why?
ostream& operator << ( ostream& os, const V3& v )
{
    os << "< ";
    copy( v.begin(), v.end(), ostream_iterator<V3::value_type>(os," ") );
    os << '>';
    return os;
}
ostream& operator << ( ostream& os, const V2& v )
{
    os << "< ";
    copy( v.begin(), v.end(), ostream_iterator<V3::value_type>(os," ") );
    os << '>';
    return os;
}

template< typename T, int S >
int size( const T (&v)[S] )
{
    return S;
}

int main()
{
    V3 v1 = {2,4,8};
    V3 v1Origin = v1;
    V3 v1Over2 = {1,2,4};
    V3 TwoOverV1 = { 2.0/2, 2.0/4, 2.0/8 };

    V2 threeFourFive = {3.0,4.0};

    TEST( v1 + v1, v1 * 2 );
    TEST( v1 + (v1+v1), v1 * 3 );
    TEST( v1 += v1, v1Origin * 2 );
    TEST( v1 -= v1Origin, v1Origin );
    TEST( v1 - v1Over2, v1Over2 );
    TEST( v1 / 2, v1Over2 );
    TEST( v1 /= 2, v1Over2 );
    TEST( v1 *= 2, v1Origin );
    TEST( 2 / v1, TwoOverV1 );
    TEST( magnitude( threeFourFive ), 5.0 ); // Tests dot(v1,v2) and magnitude(v).
    TEST( magnitude( threeFourFive, 10.0f ), threeFourFive*2 ); // Tests dot(v1,v2) and magnitude(v).
    TEST( normalize( threeFourFive ), threeFourFive/5.0 );
    TEST( size(v1.data()), 3 );
}
