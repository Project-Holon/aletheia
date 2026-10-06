/*
 * function: func_021BD62C
 * address:  0x021BD62C
 * packet:   pkt_ov217_021BD62C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD718  0x021BD718  thumb  ov217
 *   func_021BD868  0x021BD868  thumb  ov217
 *   func_021BD89C  0x021BD89C  thumb  ov217
 *   func_021BDC18  0x021BDC18  thumb  ov217
 *   func_021BDF58  0x021BDF58  thumb  ov217
 *   func_021BE040  0x021BE040  thumb  ov217
 *   func_021BE094  0x021BE094  thumb  ov217
 *   func_021BE0D0  0x021BE0D0  thumb  ov217
 *   func_021BE108  0x021BE108  thumb  ov217
 *   func_021BE21C  0x021BE21C  thumb  ov217
 *   func_021BE33C  0x021BE33C  thumb  ov217
 *   func_021BE36C  0x021BE36C  thumb  ov217
 *   func_021BE384  0x021BE384  thumb  ov217
 *   func_021BF6D4  0x021BF6D4  thumb  ov217
 *   func_021BF710  0x021BF710  thumb  ov217
 *   func_021BED9C  0x021BED9C  thumb  ov217
 *   func_021C20C4  0x021C20C4  thumb  ov217
 *   func_021BF600  0x021BF600  thumb  ov217
 *   func_021BF5E4  0x021BF5E4  thumb  ov217
 *   func_021BEDC4  0x021BEDC4  thumb  ov217
 *   func_021BEDEC  0x021BEDEC  thumb  ov217
 *   func_021BE490  0x021BE490  thumb  ov217
 *   func_021BE4A4  0x021BE4A4  thumb  ov217
 *   func_0204A600  0x0204A600  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00021.h"

typedef unsigned char  u8;
extern void func_021BD718(unsigned char *p);
typedef unsigned int   u32;
extern void func_021BD868(u32 a0);
extern void func_021BD89C(u8 *p);
extern void func_021BDC18(u8 *p);
extern void func_021BDF58(u8 *p);
extern void func_021BE040(u8 *p);
extern void func_021BE094(u32 a0);
extern void func_021BE0D0(u32 a0);
extern void func_021BE108(char *p);
extern void func_021BE21C(char *p);
extern void func_021BE33C(u32 a0);
extern void func_021BE36C(u32 a0);
extern void func_021BE384(u32 a0);
extern void func_021BF6D4(char *p);
extern void func_021BF710(void *p);
extern void func_0204A600(void *h);
extern void func_021BED9C(char *p);
extern void func_021C20C4(void *h);
extern void func_021BF600(u8 *a0);
extern void func_021BF5E4(int *p);
extern void func_021BEDC4(char *p);
extern void func_021BEDEC(char *p);
extern void func_021BE490(void *p);
extern void func_021BE4A4(u32 a0);

void func_021BD62C(unsigned char *p)
{
    switch (((struct Obj00021 *)p)->f20) {
    case 0: func_021BD718(p); break;
    case 1: func_021BD868((u32)p); break;
    case 2: func_021BD89C(p); break;
    case 3: func_021BDC18(p); break;
    case 4: func_021BDF58(p); break;
    case 5: func_021BE040(p); break;
    case 6: func_021BE094((u32)p); break;
    case 7: func_021BE0D0((u32)p); break;
    case 8: func_021BE108((char *)p); break;
    case 9: func_021BE21C((char *)p); break;
    case 10: func_021BE33C((u32)p); break;
    case 11: func_021BE36C((u32)p); break;
    case 12: func_021BE384((u32)p); break;
    case 13: return;
    }
    func_021BF6D4((char *)p);
    func_021BF710(p);
    if (((struct Obj00021 *)p)->f3C4 != 0) {
        func_0204A600(((struct Obj00021 *)p)->f3C4);
        func_021BED9C((char *)p);
        func_021C20C4(((struct Obj00021 *)p)->f2D0);
        func_021BF600(p);
        func_021BF5E4((int *)p);
        func_021BEDC4((char *)p);
        func_021BEDEC((char *)p);
        *(volatile unsigned int *)0x04000540 = 0;
    }
    func_021BE490(p);
    func_021BE4A4((u32)p);
}
