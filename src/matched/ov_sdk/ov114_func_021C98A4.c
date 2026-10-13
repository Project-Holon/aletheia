/*
 * function: my_rand
 * address:  0x021C98A4
 * packet:   pkt_ov114_021C98A4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      my_rand (dwc_encsession.o)
 *
 * symbols:
 *   _u32_div_f     0x0209C2B0  arm
 *   gDwcEncSession     0x021CF7AC  data
 *   gDwcEncRandState     0x021D4228  data
 */

#include "../include/G_Session.h"

typedef struct {
    char pad[0x44];
    unsigned int mul;
    unsigned int add;
    unsigned int mod;
} Session;
extern struct Session gDwcEncSession;
extern int gDwcEncRandState;

unsigned char my_rand(void)
{
    gDwcEncRandState = (gDwcEncSession.key1 * gDwcEncRandState + gDwcEncSession.key2) % gDwcEncSession.key3;
    return gDwcEncRandState >> 16;
}
