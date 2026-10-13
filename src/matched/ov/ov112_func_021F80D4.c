/*
 * function: func_021F80D4
 * address: 0x021F80D4
 * packet: pkt_ov112_021F80D4
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: handed label 021F80D6 follows the parameter-home push.
 * symbols:
 *   func_021F5374 0x021F5374 thumb ov112
 *   func_021F4E6C 0x021F4E6C thumb ov112
 *   BILLBOARD_SetElemVisible 0x0204F720 arm
 */
#include "../include/Obj13845.h"
#include "../include/Obj13846.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021F5374(int *p, int b);
extern void func_021F4E6C(u8 *p, u8 *e, u32 value);
extern void BILLBOARD_SetElemVisible(void *p, u32 idx, u32 *flag);
typedef struct { int pad[33]; int a; int pad2[17]; int b; } Slot;
void func_021F80D4(char *p, char *q, int v) {
    int i;
    int value = v;
    func_021F5374((int *)(((struct Obj13846 *)q)->f58), value);
    for (i = 0; i < 9; i++) {
        if (((Slot *)(q + i * 4))->a != 0 && ((Slot *)(q + i * 4))->b == 1)
            func_021F4E6C((u8 *)(((struct Obj13845 *)p)->f10), (u8 *)(((Slot *)(q + i * 4))->a), value);
    }
    BILLBOARD_SetElemVisible((void *)(((struct Obj13845 *)p)->f8), ((struct Obj13846 *)q)->f5C, (u32 *)(&v));
}
