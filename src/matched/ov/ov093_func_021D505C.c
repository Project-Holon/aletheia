/*
 * function: BTL_POKEPARAM_SaveMovesToMon
 * address:  0x021D505C
 * packet:   pkt_ov093_021D505C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKE_TOOL_SetMoveSlot  0x020181F4  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct E {
    u16 f00;
    u8 f02;
    u8 pad03;
    u8 f04;
    u8 pad05[9];
};

struct A {
    void *f00;
    u8 pad04[0x100];
    struct E e[4];
};

extern void POKE_TOOL_SetMoveSlot(void *p, u16 move, u32 slot);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);

void BTL_POKEPARAM_SaveMovesToMon(struct A *a)
{
    void *mon = a->f00;
    u32 i;

    for (i = 0; i < 4; i++) {
        POKE_TOOL_SetMoveSlot(mon, a->e[i].f00, (u8)i);
        POKE_TOOL_SetPartyValue(mon, 0x3a + i, a->e[i].f02);
        POKE_TOOL_SetPartyValue(mon, 0x3e + i, a->e[i].f04);
    }
}
