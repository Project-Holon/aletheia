/*
 * function: func_0218A41C
 * address: 0x0218A41C
 * packet: pkt_ov096_0218A41C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   D_0218A7C0 0x0218A7C0 data a4
 *   D_0218A7A0 0x0218A7A0 data
 */

#include "../include/G_Slot.h"

typedef unsigned char u8;
typedef struct { u8 id[4]; u8 ref[4]; void *obj[4]; } Slot;
extern struct Slot *D_0218A7C0;
extern const char D_0218A7A0[];
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
void func_0218A41C(unsigned int a) { int i; if(D_0218A7C0==0) { D_0218A7C0=func_02030734(a,24,1,D_0218A7A0,3999); for(i=0;i<4;i++) D_0218A7C0->id[i]=255; } }
