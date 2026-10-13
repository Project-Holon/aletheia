/*
 * function: TR_AI_Start
 * address:  0x021880BC
 * packet:   pkt_ov096_021880BC
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02011324  0x02011324  thumb
 *   func_0203F0A8  0x0203F0A8  arm
 */
#include "../include/Obj02152.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

struct ScriptVm;
extern void *func_02011324(struct ScriptVm *vm);
extern u32 func_0203F0A8(void);

void TR_AI_Start(int a, u8 *b, int c)
{
    u8 *p;
    int i;
    int z;

    p = func_02011324((struct ScriptVm *)a);
    p[0] = 0;
    ((struct Obj02152 *)p)->f2 = 0;
    p[1] = 0;
    ((struct Obj02152 *)p)->f38 = 0;
    p[0x44] = 0;
    p[0x45] = 0;
    p[0x94] = c;
    ((struct Obj02152 *)p)->f3C = ((struct Obj02152 *)p)->f40;
    ((struct Obj02152 *)p)->fC8 = 4;
    z = 0;
    for (i = 0; i < 4; i++) {
        if (b[i] == 0)
            *(int *)(p + 0x14 + i * 4) = z;
        else
            *(int *)(p + 0x14 + i * 4) = 100;
        p[0x48 + i] = 100 - (u32)(((u64)func_0203F0A8() * 0x10) >> 32);
    }
    ((struct Obj02152 *)p)->fCC = (u32)(((u64)func_0203F0A8() * 0x100) >> 32);
}
