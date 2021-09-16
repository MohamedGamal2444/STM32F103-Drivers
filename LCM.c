/*
 * LCM.c
 *
 *  Created on: Sep 7, 2021
 *      Author: Mohamed G.Mazen
 */
#include<LCM.h>
uint32_t gcd(uint16_t a, uint16_t b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

// Function to return LCM of two numbers
uint32_t lcm(uint16_t a, uint16_t b)
{
    return (a / gcd(a, b)) * b;
}
