/*
 * function: func_021BC774
 * address: 0x021BC774
 * packet: pkt_ov217_021BC774
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent ends in two zero alignment bytes at 021BC816.
 * symbols:
 *   func_021BC94C 0x021BC94C thumb ov217
 *   func_021BC910 0x021BC910 thumb ov217
 *   func_021BC8D0 0x021BC8D0 thumb ov217
 *   func_021BCD6C 0x021BCD6C thumb ov217
 *   func_021BCF4C 0x021BCF4C thumb ov217
 *   func_021BCFB4 0x021BCFB4 thumb ov217
 *   func_021BCDDC 0x021BCDDC thumb ov217
 *   func_021BD474 0x021BD474 thumb ov217
 *   func_021BD078 0x021BD078 thumb ov217
 *   func_021BD50C 0x021BD50C thumb ov217
 */
#include "../include/Obj00850.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_020056BC(void);
extern void func_021BC94C(void *);
extern void func_021BC910(void *);
extern void func_021BC8D0(void *);
extern void func_021BCD6C(void *);
extern void func_021BCF4C(void *);
extern void func_021BCFB4(void *);
extern void func_021BCDDC(void *);
extern void func_021BD474(void *);
extern void func_021BD078(void *);
extern void func_021BD50C(void *);
void func_021BC774(u8 *p)
{
    ((struct Obj00850 *)p)->f4 = 0;
    ((struct Obj00850 *)p)->f1C = 0;
    ((struct Obj00850 *)p)->f24 = 0;
    ((struct Obj00850 *)p)->f158 = 0;
    ((struct Obj00850 *)p)->f28 = 15;
    p[0x32] = 0;
    p[0x33] = 0;
    p[0x30] = 0;
    ((struct Obj00850 *)p)->f2C = 0;
    p[0x31] = 255;
    ((struct Obj00850 *)p)->f150 = func_020056BC();
    ((struct Obj00850 *)p)->f34 = 0;
    ((struct Obj00850 *)p)->f38 = 0;
    ((struct Obj00850 *)p)->f3C = 0;
    ((struct Obj00850 *)p)->f40 = 0;
    ((struct Obj00850 *)p)->f44 = 0;
    ((struct Obj00850 *)p)->f48 = 0;
    ((struct Obj00850 *)p)->f15C = 0;
    ((struct Obj00850 *)p)->f160 = 0;
    ((struct Obj00850 *)p)->f168 = 0;
    ((struct Obj00850 *)p)->f164 = 0;
    ((struct Obj00850 *)p)->f154 = 0;
    func_021BC94C(p);
    func_021BC910(p);
    func_021BC8D0(p);
    func_021BCD6C(p);
    func_021BCF4C(p);
    func_021BCFB4(p);
    func_021BCDDC(p);
    func_021BD474(p);
    func_021BD078(p);
    func_021BD50C(p);
}
