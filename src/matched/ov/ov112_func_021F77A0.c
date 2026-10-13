/*
 * function: func_021F77A0
 * address: 0x021F77A0
 * packet: pkt_ov112_021F77A0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero padding before 021F77EC.
 * symbols:
 *   BILLBOARD_FreeElem 0x0204F5A8 arm
 *   func_021F4D40 0x021F4D40 thumb ov112
 *   func_021F4B4C 0x021F4B4C thumb ov112
 *   func_021F5330 0x021F5330 thumb ov112
 */
#include "../include/Obj10320.h"
#include "../include/Obj10321.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void BILLBOARD_FreeElem(void *p, u32 idx);
extern void func_021F4D40(u8 *p, u8 *e);
struct Tagged;
extern void func_021F4B4C(struct Tagged *a0);
extern void func_021F5330(int, int);
typedef struct { int pad[24]; int value; int pad2[8]; int other; } Slot;
void func_021F77A0(char *p, char *q) {
    u8 i;
    BILLBOARD_FreeElem((void *)(((struct Obj10320 *)p)->f8), ((struct Obj10321 *)q)->f5C);
    for (i = 0; i < 9; i++) {
        if (((Slot *)(q + i * 4))->other != 0) {
            func_021F4D40((u8 *)(((struct Obj10320 *)p)->f10), (u8 *)(((Slot *)(q + i * 4))->other));
            func_021F4B4C((struct Tagged *)(((Slot *)(q + i * 4))->value));
            ((Slot *)(q + i * 4))->value = 0;
            ((Slot *)(q + i * 4))->other = 0;
        }
    }
    func_021F5330(((struct Obj10320 *)p)->fC, ((struct Obj10321 *)q)->f58);
    ((struct Obj10321 *)q)->f0 = 0;
}
