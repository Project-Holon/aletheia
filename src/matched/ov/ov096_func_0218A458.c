/*
 * function: func_0218A458
 * address: 0x0218A458
 * packet: pkt_ov096_0218A458
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   D_0218A7C0 0x0218A7C0 data a4
 */

#include "../include/G_Slot.h"

typedef unsigned char u8;
typedef struct { u8 id[4]; u8 ref[4]; void *obj[4]; } Slot;
extern struct Slot *D_0218A7C0;
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_0218A458(void) { int i; int zero; if(D_0218A7C0!=0) { zero=0; for(i=0;i<4;i++) { if(D_0218A7C0->obj[i]!=0) { func_020307B0(D_0218A7C0->obj[i]); D_0218A7C0->obj[i]=(void *)zero; } } func_020307B0(D_0218A7C0); D_0218A7C0=0; } }
