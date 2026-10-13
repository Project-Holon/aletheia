/*
 * function: FIELD_MSGBG_GetStrHeightChars
 * address:  0x0219272C
 * packet:   pkt_ov021_0219272C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201D42C  0x0201D42C  thumb
 *   STRBUF_Clone  0x02045874  arm
 *   func_0201D37C  0x0201D37C  thumb
 *   STRBUF_Delete  0x02045808  arm
 */
#include "../include/Obj12612.h"

typedef unsigned short u16;
typedef unsigned int   u32;

struct StrObj;
struct U16Vec;
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern struct U16Vec *STRBUF_Clone(struct U16Vec *src, u32 heapId);
extern u32 func_0201D37C(struct StrObj *src, struct StrObj *dst, u32 n);
extern void STRBUF_Delete(struct U16Vec *vec);

u32 FIELD_MSGBG_GetStrHeightChars(u16 *a, u32 b, u32 c)
{
    u32 n;
    u32 h;
    u32 i;

    n = c * 2 + func_0201D42C((struct StrObj *)b, (void *)(((struct Obj12612 *)a)->f8));
    h = (u32)STRBUF_Clone((struct U16Vec *)b, *a);
    i = 0;
    if (func_0201D37C((struct StrObj *)b, (struct StrObj *)h, 0) == 1) {
        while (++i < 0x18 && func_0201D37C((struct StrObj *)b, (struct StrObj *)h, i) == 1)
            ;
    }
    STRBUF_Delete((struct U16Vec *)h);
    n += (i - 1) * 2;
    if (n & 7)
        n += 8;
    return n >> 3;
}
