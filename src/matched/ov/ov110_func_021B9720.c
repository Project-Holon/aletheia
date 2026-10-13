/*
 * function: func_021B9720
 * address: 0x021B9720
 * packet: pkt_ov110_021B9720
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: 2026-10-04 (wD2 lane06): MATCH. Locals declared o, limit, count, base, i; `base = ...; count = 0; limit = ...` in that order fixed the zero register and slots. Only unresolved relocations are arm9 leaves 0x0202414C and 0x02024994, filed as src/matched/arm9 EXACT leaves this wave (need manifest witness).
 * symbols:
 *   PMSI_PARAM_GetWordSave 0x0202414C thumb
 *   PMS_WORD_MakeWordId 0x02024888 thumb
 *   PMS_WORD_CheckFlag 0x02024994 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *PMSI_PARAM_GetWordSave(char *p);
extern u16 PMS_WORD_MakeWordId(u32 idx, u16 add);
extern int PMS_WORD_CheckFlag(const u32 *p, u32 idx);
u32 func_021B9720(u8 *p, u16 *src, u32 n, u16 *out)
{
    void *o;
    u32 limit;
    u32 count;
    u32 base;
    u32 i;
    o = PMSI_PARAM_GetWordSave((char *)(*(u32 *)p));
    base = PMS_WORD_MakeWordId(0x97, 0);
    count = 0;
    limit = (u16)(base + 7);
    for (i = 0; i < n; i++) {
        u32 v = src[i];
        if (v >= base && v <= limit) {
            if (PMS_WORD_CheckFlag(o, v - base) == 0)
                continue;
        }
        v = src[i];
        p[0x1D6E + (v >> 3)] |= (u8)(1 << (v & 7));
        *out = v;
        out++;
        count++;
    }
    return count;
}
