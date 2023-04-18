//Dorota Dyczek
#include <iostream>
#include <cmath>
int main () {
    float x1, x2, x3;
    float q;
    float p;
    float s;
    float N;
    float q1,q2,delta;
    float a,b,c;

    std::cout.precision(10);
    std::cin>> N;
    for(int i = 0; i < N; i++)
    {
        std::cin>>p>>s;

        x1 = x2/q;
        x3 = x2*q;

        x2 = cbrt(p);
        b = 1 - s/x2;
        a = 1;
        c = 1;
        delta = b * b - 4 * a * c;

        if (x2 == 0 || p == 0)
        {
            std::cout<<0<<" "<<0<<" "<<0<<std::scientific;
        }
        else if(delta >= 0) {
            q1 = (-b - sqrt(delta));
            q2 = (-b + sqrt(delta));

            float qtemp1, qtemp2;
            if (b >= 0)
            {
            q = q1;
            qtemp1 = q/2;
            qtemp2 = 2/q;
            }
            else {
                q = q2;
                qtemp1 = 2/q;
                qtemp2 = q/2;
            }

            x1 = x2/qtemp1;
            x3 = x2*qtemp1;
            if(x1 < x3)
            {
                x1 = x2/qtemp2;
                x3 = x2*qtemp2;
            }
            std::cout<<x1<<" "<<x2<<" "<<x3<<std::scientific;
        }
        else
            std::cout<<0<<" "<<0<<" "<<0<<std::scientific;

        std::cout<<std::endl;

    }

    return 0;
}
