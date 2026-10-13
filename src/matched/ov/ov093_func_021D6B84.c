/*
 * function: BTL_POKEPARAM_WriteBackToParam
 * address:  0x021D6B84
 * packet:   pkt_ov093_021D6B84
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_SetStatusCondition  0x02017F9C  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_POKEPARAM_SaveMovesToMon  0x021D505C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct {
    void *w;
    u8 pad4[4];
    u32 f8;
    u8 padC[4];
    u16 f10;
    u16 f12;
    u8 pad14[7];
    u8 f1b_lo : 5;
    u8 f1b_b5 : 1;
} Obj;

extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetStatusCondition(void *p, u32 v);
extern void POKE_TOOL_RecalcParam(void *p);
struct A;
struct Unk021D62A8;
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern void BTL_POKEPARAM_SaveMovesToMon(struct A *a);

void BTL_POKEPARAM_WriteBackToParam(Obj *p, int flag)
{
    void *w = p->w;
    u32 r;

    POKE_TOOL_SetPartyValue(w, 8, p->f8);
    POKE_TOOL_SetPartyValue(w, 0xa0, p->f10);
    if (p->f10 != 0)
        POKE_TOOL_SetStatusCondition(w, BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)p));
    else
        POKE_TOOL_SetStatusCondition(w, 0);
    BTL_POKEPARAM_SaveMovesToMon((struct A *)p);
    if (p->f1b_b5 || flag != 0)
        r = p->f1b_lo;
    else
        r = ((u8 *)p)[0x141];
    POKE_TOOL_SetPartyValue(w, 0x6f, (u8)r);
    POKE_TOOL_RecalcParam(w);
    POKE_TOOL_SetPartyValue(w, 6, p->f12);
}
