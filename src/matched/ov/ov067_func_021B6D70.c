/*
 * function: MSGSEARCH_PrefixMatches
 * address:  0x021B6D70
 * packet:   pkt_ov067_021B6D70
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_GetLength  0x020458F8  arm
 *   STRBUF_GetChars  0x02045A90  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct U16Vec;
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);

int MSGSEARCH_PrefixMatches(u32 a, u32 b, u32 n)
{
    u16 *pa;
    u16 *pb;
    u32 i;

    if (STRBUF_GetLength((struct U16Vec *)a) < n) {
        return 0;
    }
    if (STRBUF_GetLength((struct U16Vec *)b) < n) {
        return 0;
    }
    pa = STRBUF_GetChars((struct U16Vec *)a);
    pb = STRBUF_GetChars((struct U16Vec *)b);
    for (i = 0; i < n; i++) {
        if (*pa++ != *pb++) {
            return 0;
        }
    }
    return 1;
}
