/*
 * function: BTL_MSG_CountWordTags
 * address:  0x021EEF98
 * packet:   pkt_ov093_021EEF98
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_GetChars  0x02045A90  arm
 *   BTL_MSG_FindWordTag  0x021EEF20  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct U16Vec;
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern u16 *BTL_MSG_FindWordTag(u16 *p, u32 *o1, u16 *o2, u8 *o3);

u8 BTL_MSG_CountWordTags(void *s)
{
    u32 o1;
    u16 o2;
    u8 o3;
    u16 *p;
    u8 n;

    p = STRBUF_GetChars(s);
    n = 0;
    if (p != 0) {
        do {
            p = BTL_MSG_FindWordTag(p, &o1, &o2, &o3);
            if (p != 0 && o1 == 1) {
                if (o2 == 1 || o2 == 2 || o2 == 12)
                    n = n + 1;
            }
        } while (p != 0);
    }
    return n;
}
