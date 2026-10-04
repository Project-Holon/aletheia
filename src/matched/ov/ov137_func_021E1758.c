/*
 * function: func_021E1758
 * address: 0x021E1758
 * packet: pkt_ov137_021E1758
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DEB10 0x021DEB10 thumb ov137
 *   func_021841A4 0x021841A4 thumb ov022
 */
#include "../include/Obj01753.h"
extern void *func_021DEB10(char *p);
extern int func_021841A4(unsigned char *);
void func_021E1758(char *p) { ((struct Obj01753 *)p)->f30=func_021841A4(func_021DEB10(p)); }
