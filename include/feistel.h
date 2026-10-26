#ifndef FEISTEL_H
#define FEISTEL_H
#include <stdint.h>

uint64_t Exp(uint32_t R);// Expansion de 32 bits en 48 bits

uint32_t Feist_f(uint32_t R, uint64_t K);

#endif // DEBUG