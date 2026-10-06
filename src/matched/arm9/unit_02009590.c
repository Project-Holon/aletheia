/*
 * unit:     yes
 * function: func_02009590
 * address:  0x02009590
 * packet:   pkt_02009590
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02009584  0x02009584  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_02009794  0x02009794  thumb
 *
 * Checks mode and validity flags, adjusting count when active.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009590.c \
 *       --addr 0x02009590 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub02009470Obj;
extern u8 func_02009584(const struct Sub02009470Obj *obj);
struct Sub0200852CObj;
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
struct Sub02009470Obj;
extern u32 func_02009794(const struct Sub02009470Obj *obj, u32 n);

u8 func_02009590(void *a, u32 b, u32 c)
{
    u8 res = func_02009584(a);

    if (c == 0) {
        int r = func_0200856C((const struct Sub0200852CObj *)b);
        if (r == 0) {
            res = 0;
        } else if (func_02009794(a, r) && res != 0) {
            res--;
        }
    }

    return res;
}
