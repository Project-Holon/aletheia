/*
 * function: func_021BB69C
 * address: 0x021BB69C
 * packet: pkt_ov217_021BB69C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021BB70E..021BB710 is two zero bytes of alignment padding.
 * arity: BB910 visibly receives r1=13; retain it through the forwarding chain despite its one-argument legacy file.
 * symbols:
 *   func_021BB98C 0x021BB98C thumb ov217
 *   func_021BB990 0x021BB990 thumb ov217
 *   func_021BB948 0x021BB948 thumb ov217
 *   func_021BC490 0x021BC490 thumb ov217
 *   func_021BC4A0 0x021BC4A0 thumb ov217
 *   func_021BC50C 0x021BC50C thumb ov217
 *   func_021BC55C 0x021BC55C thumb ov217
 *   func_021C1038 0x021C1038 thumb ov217
 *   func_021BB91C 0x021BB91C thumb ov217
 *   func_021BB910 0x021BB910 thumb ov217
 */
#include "../include/Obj00025.h"
typedef unsigned char u8;
extern unsigned func_021BB98C(void *);
extern void func_021BB990(void *);
extern unsigned func_021BB948(u8 *);
extern void func_021BC490(void);
extern int func_021BC4A0(void);
extern void func_021BC50C(char *p);
extern unsigned func_021BC55C(unsigned);
extern void func_021C1038(u8 *p, u8 palette);
extern void func_021BB91C(void *);
extern void func_021BB910(u8 *, unsigned);
void func_021BB69C(u8 *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        if (func_021BB948(p) < ((struct Obj00025 *)p)->f24) {
            func_021BC490();
            func_021BB990(p);
        }
        break;
    case 1:
        if (func_021BC4A0()) {
            func_021BC50C((char *)p);
            func_021BB990(p);
        }
        break;
    case 2:
        if (func_021BC55C((unsigned)p)) {
            func_021C1038((u8 *)(*(unsigned *)(p + p[0x32] * 4 + 0xb4)), 15);
            func_021BB91C(p);
            func_021BB910(p, 13);
        }
        break;
    }
}
