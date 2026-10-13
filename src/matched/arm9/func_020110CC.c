/*
 * function: GPOWER_UsePpRestore
 * address:  0x020110CC
 * packet:   pkt_0201104C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02146208     0x02146208  data
 *   g_02146228     0x02146228  data
 *   func_0201AB08  0x0201AB08  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   WAZA_TOOL_GetMaxPP  0x0201C158  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb
 *   GPOWER_ClearType  0x02010F50  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_UsePpRestore.c  *       --func GPOWER_UsePpRestore --addr 0x020110CC --cc 1.1p1 --thumb
 *
 * net_save.c, gated on mode byte +0x1a (slot 6): for each of the record's
 * four slots whose field 0x36+i is set, add the +0xe factor to field
 * 0x3a+i, clamped to WAZA_TOOL_GetMaxPP(field 0x36+i, field 0x3e+i); inside the
 * POKE_TOOL_DecodePartyParam / POKE_TOOL_EncodePartyParam access bracket; then clear slot 6.  Same
 * declarations as GPOWER_UseHpRestore.c (the callees take the box / record
 * pointer, the record is its own local), which is what closed the
 * entry-order residue of docs/notes/pkt_0201104C.sub_020110CC.c.txt.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 g_02146208[];
extern u8 g_02146228[];
extern u32   func_0201AB08(void *box);
extern void *func_0201AB28(void *box, u32 idx);
struct Sav;
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u8 WAZA_TOOL_GetMaxPP(u16 move, u32 ppUp);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);
extern void  GPOWER_ClearType(int idx);

u32 GPOWER_UsePpRestore(void *box)
{
    void *p;
    u32 idx;
    u32 h;
    u32 i;
    u32 move;
    u32 max;
    u32 v;

    if (g_02146208[0x1a] != 0x30) {
        idx = func_0201AB08(box);
        p = func_0201AB28(box, idx);
        h = POKE_TOOL_DecodePartyParam(p);
        for (i = 0; i < 4; i++) {
            move = POKE_TOOL_GetPartyValue(p, (int)(0x36 + i), (int)0);
            if (move != 0) {
                max = (u32)WAZA_TOOL_GetMaxPP(move, (u8)POKE_TOOL_GetPartyValue(p, (int)(0x3e + i), (int)0));
                v = POKE_TOOL_GetPartyValue(p, (int)(0x3a + i), (int)0);
                v += *(u16 *)(g_02146228 + 0xe);
                if (v > max) {
                    v = max;
                }
                POKE_TOOL_SetPartyValue(p, (int)(0x3a + i), v);
            }
        }
        POKE_TOOL_EncodePartyParam(p, h);
        GPOWER_ClearType(6);
        return idx;
    }
    return 0xff;
}
