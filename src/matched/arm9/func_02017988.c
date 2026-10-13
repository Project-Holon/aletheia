/*
 * function: POKE_TOOL_ChangeForm
 * address:  0x02017988
 * packet:   pkt_0201756C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_TOOL_ChangeForm.c \
 *       --func POKE_TOOL_ChangeForm --addr 0x02017988 --cc 1.1p1 --thumb
 *
 * symbols:
 *   POKE_TOOL_ChangeBoxForm  0x020179B8  thumb
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

struct Sav;
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern int POKE_TOOL_ChangeBoxForm(int a0, int a1);
extern void POKE_TOOL_RecalcParam(void *p);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);

u32 POKE_TOOL_ChangeForm(void *p, u32 a)
{
    u8 v = (u8)POKE_TOOL_DecodePartyParam(p);
    u32 r = POKE_TOOL_ChangeBoxForm((int)p, a);

    if (r == 1) {
        POKE_TOOL_RecalcParam(p);
    }
    POKE_TOOL_EncodePartyParam(p, v);
    return r;
}
