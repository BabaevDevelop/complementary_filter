#include <iostream>

float clamp(float v, float minv, float maxv){
    if (v > maxv)
        return maxv;
    else if (v < minv)
        return minv;
    return v;
}

float complementaryFilter(){
    float dt = 0.5;
    float xk_1 = 0, vk_1 = 0, a = 0.85, b = 0.005;

    float xk, vk, rk;
    float xm;

         xm = rand() % 100; // input signal

         xk = xk_1 + (vk_1 * dt);
         vk = vk_1;

         rk = xm - xk;

         xk += a * rk;
         vk += (b * rk) / dt;

         xk_1 = xk;
         vk_1 = vk;

         return clamp(xk_1, 0, 1);



}

int main() {
    while (1){
        std::cout << complementaryFilter()<<' ';
        _sleep(200);
    }

    return 0;
}
