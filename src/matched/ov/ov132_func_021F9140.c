/*
 * function: func_021F9140
 * address: 0x021F9140
 * packet: pkt_ov132_021F9140
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204A380 0x0204A380 arm
 *   func_021FAD0C 0x021FAD0C thumb ov132
 */
#include "../include/Obj05397.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0204A380(void *a0, u32 a1, u32 a2, u16 a3);
extern char *func_021FAD0C(char *p, char *base, unsigned index, unsigned char flag);
void func_021F9140(u8 *p, u32 n, int i)
{
    void *table;
    u16 score;
    table = func_0204A380((void *)(((struct Obj05397 *)p)->f18), n + 0x37, 0, ((struct Obj05397 *)p)->f0);
    score = *(u16 *)(*(u8 **)(*(u8 * *)&((struct Obj05397 *)p)->f30 + i * 4 + 4) + 0x4a);
    if (score >= 70) {
        func_021FAD0C(((struct Obj05397 *)p)->fB0, table, 0, (u8)(1 << i));
    } else if (score >= 40) {
        func_021FAD0C(((struct Obj05397 *)p)->fB0, table, 1, (u8)(1 << i));
    } else {
        func_021FAD0C(((struct Obj05397 *)p)->fB0, table, 2, (u8)(1 << i));
    }
}
