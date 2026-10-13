/*
 * function: BTL_POKEPARAM_DecrementMovePP
 * address:  0x021D5608
 * packet:   pkt_ov093_021D5608
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct UtilEntry {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u16 f4;
    u16 f6;
    u8 f8;
    u8 f9;
    u16 fA;
    u8 fC;
    u8 fD;
};

struct UtilWork {
    void *f0;
    u8 pad4[0x100];
    struct UtilEntry e[4];
    u8 pad13C[4];
    u8 n140;
    u8 pad141[3];
    u8 f144;
    u8 pad145[5];
    u16 f14A;
    u16 f14C;
    u16 f14E;
    u8 pad150[3];
    u8 bits153[2];
    u8 bits155[2];
    u8 f157[5];
};

extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);

void BTL_POKEPARAM_DecrementMovePP(struct UtilWork *p, int i, u8 n)
{
    if (p->e[i].f8 >= n) p->e[i].f8 -= n;
    else p->e[i].f8 = 0;
    if (p->e[i].fC != 0) {
        p->e[i].f2 = p->e[i].f8;
        POKE_TOOL_SetPartyValue(p->f0, i + 0x3A, p->e[i].f2);
    }
}
