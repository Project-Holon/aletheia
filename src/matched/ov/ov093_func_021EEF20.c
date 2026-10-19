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
 * Walks a message string for the first 0xF000 tag that PRINTSYS_IsWordSlotTag calls a
 * word reference; the guard on p wraps the whole walk (two `return 0` tails).
 *
 * symbols:
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   PRINTSYS_GetTagChar  0x0201D5C4  thumb
 *   PRINTSYS_IsWordSlotTag  0x0201D5CC  thumb
 *   PRINTSYS_GetTagParam  0x0201D670  thumb
 *   PRINTSYS_GetTagGroup  0x0201D5F4  thumb
 *   PRINTSYS_GetTagKind  0x0201D658  thumb
 *   PRINTSYS_SkipTag  0x0201D688  thumb
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u16 STRBUF_GetEosChar(void);
extern u32 PRINTSYS_GetTagChar(void);
extern u32 PRINTSYS_IsWordSlotTag(const u16 *p);
extern u32 PRINTSYS_GetTagParam(const u16 *p, u32 i);
extern u32 PRINTSYS_GetTagGroup(const u16 *p);
extern u32 PRINTSYS_GetTagKind(const u16 *p);
extern u16 *PRINTSYS_SkipTag(u16 *p);

u16 *BTL_MSG_FindWordTag(u16 *p, u32 *o1, u16 *o2, u8 *o3)
{
    u16 end;
    u32 tag;

    if (p != 0) {
        end = STRBUF_GetEosChar();
        tag = PRINTSYS_GetTagChar();
        while (*p != end) {
            if (*p == tag) {
                if (PRINTSYS_IsWordSlotTag(p) != 0) {
                    *o3 = PRINTSYS_GetTagParam(p, 0);
                    *o1 = PRINTSYS_GetTagGroup(p);
                    *o2 = PRINTSYS_GetTagKind(p);
                    return PRINTSYS_SkipTag(p);
                }
                p = PRINTSYS_SkipTag(p);
            } else {
                p = p + 1;
            }
        }
        return 0;
    }
    return 0;
}
