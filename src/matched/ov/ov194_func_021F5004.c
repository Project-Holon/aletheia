/*
 * function: NAMEIN_GRAPHIC_IsNameCharValid
 * address:  0x021F5004
 * packet:   pkt_ov194_021F5004
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note (2026-10-05, wD4 lane09): EXACT. `j = 0;` before `p = bufs[k];` at the k-loop top, declaration
 *   order bufs, ret, h, j, idx, k, v, t, and NAMEIN_GRAPHIC_GetGridCell declared with u16 parameters (as its other
 *   callers do) so the call passes m and j uncast; the conversion temp then takes sp+0x20, not sp+0.
 *
 * symbols:
 *   NAMEIN_GRAPHIC_LoadArcMember 0x021F4D20 thumb ov194
 *   NAMEIN_GRAPHIC_LoadPairMember 0x021F4F50 thumb ov194
 *   NAMEIN_GRAPHIC_GetGridCell 0x021F4DA4 thumb ov194
 *   NAMEIN_GRAPHIC_GetGridWidth 0x021F4D9C thumb ov194
 *   NAMEIN_GRAPHIC_GetGridHeight 0x021F4DA0 thumb ov194
 *   NAMEIN_GRAPHIC_GetPairCount 0x021F4F68 thumb ov194
 *   NAMEIN_GRAPHIC_GetPairEntry 0x021F4F6C thumb ov194
 *   NAMEIN_GRAPHIC_FreePairMember 0x021F4F60 thumb ov194
 *   NAMEIN_GRAPHIC_FreeMember 0x021F4D34 thumb ov194
 *   STRBUF_GetEosChar 0x02045A98 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int NAMEIN_GRAPHIC_LoadArcMember(u32 a, u32 b);
extern int NAMEIN_GRAPHIC_LoadPairMember(int a);
extern u32 NAMEIN_GRAPHIC_GetGridCell(u8 *p, u16 a, u16 b);
extern u16 NAMEIN_GRAPHIC_GetGridWidth(const u16 *p);
extern u16 NAMEIN_GRAPHIC_GetGridHeight(const u16 *p);
extern int NAMEIN_GRAPHIC_GetPairCount(const u16 *p);
extern unsigned short NAMEIN_GRAPHIC_GetPairEntry(char *base, int i, int j);
extern void NAMEIN_GRAPHIC_FreePairMember(void *p);
extern void NAMEIN_GRAPHIC_FreeMember(void *p);
extern u16 STRBUF_GetEosChar(void);
u32 NAMEIN_GRAPHIC_IsNameCharValid(u16 *s, u32 x)
{
    u8 *bufs[4];
    u32 ret;
    u8 *h;
    int j, idx, k;
    u32 v;
    int t;
    int i, m;
    u32 found;
    u8 *p;
    v = (x & 0x7FFF) | 0x8000;
    for (i = 0; i < 4; i++) bufs[i] = (u8 *)NAMEIN_GRAPHIC_LoadArcMember(i, (u16)v);
    h = (u8 *)NAMEIN_GRAPHIC_LoadPairMember(v & 0xFFFF);
    ret = 1;
    idx = 0;
    while (s[idx] != STRBUF_GetEosChar()) {
        found = 0;
        for (k = 0; (u32)k < 4; k++) {
            j = 0;
            p = bufs[k];
            for (; j < (int)NAMEIN_GRAPHIC_GetGridHeight((const u16 *)p) && found == 0; j++) {
                for (m = 0; m < (int)NAMEIN_GRAPHIC_GetGridWidth((const u16 *)p) && found == 0; m++) {
                    if (s[idx] == NAMEIN_GRAPHIC_GetGridCell(p, m, j)) found = 1;
                }
            }
        }
        for (t = 0; t < NAMEIN_GRAPHIC_GetPairCount((const u16 *)h); t++) {
            for (m = 0; m < 3; m++) {
                if (s[idx] == NAMEIN_GRAPHIC_GetPairEntry((char *)h, (u16)t, (u16)m)) found = 1;
            }
        }
        if (found == 0) {
            ret = 0;
            break;
        }
        idx++;
    }
    NAMEIN_GRAPHIC_FreePairMember(h);
    for (i = 0; i < 4; i++) NAMEIN_GRAPHIC_FreeMember(bufs[i]);
    return ret;
}
