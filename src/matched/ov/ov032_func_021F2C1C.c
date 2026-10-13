/*
 * function: func_021F2C1C
 * address:  0x021F2C1C
 * packet:   pkt_ov032_021F2C1C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F2C1C 0x021F2C1C thumb
 *   func_02028590 0x02028590 thumb
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   func_02045EC0 0x02045EC0 arm
 */
#include "../include/Obj00007.h"

extern unsigned func_02028590(int, int, int, unsigned);
typedef unsigned short u16;
typedef unsigned int   u32;
struct MsgBank;
struct R;
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);

void func_021F2C1C(char *p)
{
    int i;
    int z;

    z = 0;
    ((struct Obj00007 *)p)->fBC = func_02028590(9, 0, 1, ((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->fB8 = (unsigned int)APP_TASKMENU_RES_Create(4, 0xe, ((struct Obj00007 *)p)->fB0, ((struct Obj00007 *)p)->fB4, ((struct Obj00007 *)p)->f98);
    i = 0;
    do {
        *(unsigned *)(p + i * 16 + 0xc4) = (unsigned int)func_02045EC0((struct MsgBank *)(*(unsigned *)&((struct Obj00007 *)p)->f114), i + 0xc);
        *(unsigned short *)(p + i * 16 + 0xc8) = 0x39e3;
        *(int *)(p + i * 16 + 0xcc) = z;
        *(int *)(p + i * 16 + 0xc0) = z;
        i++;
    } while (i < 3);
    z = 0;
    i = 0;
    do {
        *(unsigned *)(p + i * 16 + 0xf4) = (unsigned int)func_02045EC0((struct MsgBank *)(*(unsigned *)&((struct Obj00007 *)p)->f114), i + 0xf);
        *(unsigned short *)(p + i * 16 + 0xf8) = 0x39e3;
        *(int *)(p + i * 16 + 0xfc) = z;
        *(int *)(p + i * 16 + 0xf0) = z;
        i++;
    } while (i < 2);
}
