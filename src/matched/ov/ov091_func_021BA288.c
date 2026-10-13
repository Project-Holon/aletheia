/*
 * function: POKELIST_StartHpTransfer
 * address:  0x021BA288
 * packet:   pkt_ov091_021BA288
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201AB28  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   POKELIST_UpdateHpTransfer  0x021BA318  thumb ov091
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define W(o) (*(u32 *)(p + (o)))

extern void *func_0201AB28(void *p, u32 idx);
extern u32   POKE_TOOL_GetPartyValue(void *obj, u32 key, u32 off);
extern void  POKE_TOOL_SetPartyValue(void *obj, u32 key, u32 v);
extern void POKELIST_UpdateHpTransfer(u8 *p);

void POKELIST_StartHpTransfer(u8 *p)
{
    void *o1;
    void *o2;
    u32 b, c, d, e;

    o1 = func_0201AB28((void *)*(u32 *)W(0x280), W(0x34));
    POKE_TOOL_GetPartyValue(o1, 0xa0, 0);
    b = POKE_TOOL_GetPartyValue(o1, 0xa1, 0);
    o2 = func_0201AB28((void *)*(u32 *)W(0x280), ((u32 *)W(0x280))[0x3c / 4]);
    c = POKE_TOOL_GetPartyValue((void *)W(0x38), 0xa0, 0);
    d = POKE_TOOL_GetPartyValue((void *)W(0x38), 0xa1, 0);
    W(0x2c) = ((u32 *)W(0x280))[0x3c / 4];
    e = c + b / 5;
    if (e > d) {
        POKE_TOOL_SetPartyValue(o2, 0xa0, d);
    } else {
        POKE_TOOL_SetPartyValue(o2, 0xa0, e);
    }
    W(0x120) = (u32)POKELIST_UpdateHpTransfer;
    p[0xc] = 10;
    W(0x24) = 1;
}
