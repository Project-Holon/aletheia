/*
 * function: func_02017988
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
 *   python tools/match.py one --src src/matched/func_02017988.c \
 *       --func func_02017988 --addr 0x02017988 --cc 1.1p1 --thumb
 *
 * symbols:
 *   POKE_TOOL_ChangeBoxForm  0x020179B8  thumb
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

struct Sav;
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern int POKE_TOOL_ChangeBoxForm(int a0, int a1);
extern void func_020185C4(void *p);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);

u32 func_02017988(void *p, u32 a)
{
    u8 v = (u8)POKE_TOOL_DecodePartyParam(p);
    u32 r = POKE_TOOL_ChangeBoxForm((int)p, a);

    if (r == 1) {
        func_020185C4(p);
    }
    POKE_TOOL_EncodePartyParam(p, v);
    return r;
}
