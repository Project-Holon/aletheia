/*
 * function: BTL_MSG_FindWordTag
 * address:  0x021EEF20
 * packet:   pkt_ov093_021EEF20
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Walks a message string for the first 0xF000 tag that GF_FONT_CheckD5CC calls a
 * word reference; the guard on p wraps the whole walk (two `return 0` tails).
 *
 * symbols:
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   GF_FONT_GetTagChar  0x0201D5C4  thumb
 *   GF_FONT_CheckD5CC  0x0201D5CC  thumb
 *   GF_FONT_GetTagParam  0x0201D670  thumb
 *   GF_FONT_GetTagGroup  0x0201D5F4  thumb
 *   GF_FONT_GetTagKind  0x0201D658  thumb
 *   GF_FONT_SkipTag  0x0201D688  thumb
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u16 STRBUF_GetEosChar(void);
extern u32 GF_FONT_GetTagChar(void);
extern u32 GF_FONT_CheckD5CC(const u16 *p);
extern u32 GF_FONT_GetTagParam(const u16 *p, u32 i);
extern u32 GF_FONT_GetTagGroup(const u16 *p);
extern u32 GF_FONT_GetTagKind(const u16 *p);
extern u16 *GF_FONT_SkipTag(u16 *p);

u16 *BTL_MSG_FindWordTag(u16 *p, u32 *o1, u16 *o2, u8 *o3)
{
    u16 end;
    u32 tag;

    if (p != 0) {
        end = STRBUF_GetEosChar();
        tag = GF_FONT_GetTagChar();
        while (*p != end) {
            if (*p == tag) {
                if (GF_FONT_CheckD5CC(p) != 0) {
                    *o3 = GF_FONT_GetTagParam(p, 0);
                    *o1 = GF_FONT_GetTagGroup(p);
                    *o2 = GF_FONT_GetTagKind(p);
                    return GF_FONT_SkipTag(p);
                }
                p = GF_FONT_SkipTag(p);
            } else {
                p = p + 1;
            }
        }
        return 0;
    }
    return 0;
}
