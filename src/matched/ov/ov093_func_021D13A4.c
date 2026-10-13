/*
 * function: func_021D13A4
 * address:  0x021D13A4
 * packet:   pkt_ov093_021D13A4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_ADAPTER_GetRecvData  0x021EEC20  thumb  ov093
 *   func_021B902C  0x021B902C  thumb  ov093
 */
#include "../include/Obj00066.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *battle;         /* 0x00 */
    u8 unk04[0x50];
    void *msgWin;         /* 0x54 */
    u8 msg[0x14E];        /* 0x58 */
    u8 unk1A6;            /* 0x1A6 */
} BattleSeq;

extern int BTL_ADAPTER_GetRecvData(int, u16 **);
extern int func_021B902C(int a, int b);

int func_021D13A4(BattleSeq *s)
{
    u16 *q;

    BTL_ADAPTER_GetRecvData(((struct Obj00066 *)s)->f50, &q);
    switch (q[1]) {
    case 0:
        if (func_021B902C((u8)q[0], (u8)s->unk1A6) == 0)
            return 1;
        break;
    case 1:
        if (func_021B902C((u8)q[0], (u8)s->unk1A6) == 0)
            return 0;
        break;
    }
    return q[1];
}
