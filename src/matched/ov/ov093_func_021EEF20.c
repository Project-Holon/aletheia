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
 * Walks a message string for the first 0xF000 tag that func_0201D5CC calls a
 * word reference; the guard on p wraps the whole walk (two `return 0` tails).
 *
 * symbols:
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   func_0201D5C4  0x0201D5C4  thumb
 *   func_0201D5CC  0x0201D5CC  thumb
 *   func_0201D670  0x0201D670  thumb
 *   func_0201D5F4  0x0201D5F4  thumb
 *   func_0201D658  0x0201D658  thumb
 *   func_0201D688  0x0201D688  thumb
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u16 STRBUF_GetEosChar(void);
extern u32 func_0201D5C4(void);
extern u32 func_0201D5CC(const u16 *p);
extern u32 func_0201D670(const u16 *p, u32 i);
extern u32 func_0201D5F4(const u16 *p);
extern u32 func_0201D658(const u16 *p);
extern u16 *func_0201D688(u16 *p);

u16 *BTL_MSG_FindWordTag(u16 *p, u32 *o1, u16 *o2, u8 *o3)
{
    u16 end;
    u32 tag;

    if (p != 0) {
        end = STRBUF_GetEosChar();
        tag = func_0201D5C4();
        while (*p != end) {
            if (*p == tag) {
                if (func_0201D5CC(p) != 0) {
                    *o3 = func_0201D670(p, 0);
                    *o1 = func_0201D5F4(p);
                    *o2 = func_0201D658(p);
                    return func_0201D688(p);
                }
                p = func_0201D688(p);
            } else {
                p = p + 1;
            }
        }
        return 0;
    }
    return 0;
}
