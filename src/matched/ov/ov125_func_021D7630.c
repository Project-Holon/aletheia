/*
 * function: func_021D7630
 * address: 0x021D7630
 * packet: pkt_ov125_021D7630
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_0214616C 0x0214616C data a4
 *   func_0203F1FC 0x0203F1FC arm
 */

#include "../include/G_BattleRec.h"

typedef unsigned short u16;
extern struct BattleRec *d_0214616C;
typedef unsigned char  u8;
extern u16 func_0203F1FC(const u8 *src, unsigned int len);
typedef unsigned int   u32;
extern void func_0200B908(void *a, u32 b, u32 c);
struct BattleRec;
extern u32 func_0200B67C(void *a, struct BattleRec *b, u32 c, u16 *state, u16 e);
int func_021D7630(void *a, int x, u16 *state, u16 *b, u16 c)
{
    unsigned int value;
    switch (*state) {
    case 0:
        *(unsigned char *)(((char *)d_0214616C) + 0xaa) = 1;
        *(u16 *)(((char *)d_0214616C) + 0xa8) = 57985;
        *(u16 *)(((char *)d_0214616C) + 0xc0) = func_0203F1FC((const u8 *)(((char *)d_0214616C) + 0x80), 56);
        value = *(u16 *)(((char *)d_0214616C) + 0x18a0);
        func_0200B908(((char *)d_0214616C) + 0xc4, 0x17dc, value + ((value ^ 0xffff) << 16));
        ++*state;
        break;
    case 1:
        return func_0200B67C(a, (struct BattleRec *)((char *)d_0214616C), x, b, c);
    }
    return 0;
}
