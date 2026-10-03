/*
 * function: func_02165ECC
 * address:  0x02165ECC
 * packet:   pkt_ov010_02165ECC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Clear a string buffer and copy the 11-character text at +0x34 into it;
 * the type switch that follows has no effect left in it.
 *
 * The image dispatches as a two-node switch tree (`cmp #0x26; bgt` to the
 * lone `cmp #0x2f`, then `subs #0x10; bmi` into a 0x10..0x26 table). 1.1p1
 * builds that tree only when the 16..38 cluster holds 10 or 11 case labels
 * (9 or fewer: compare chain; 12 or more: one 0x10..0x2F table). The table
 * holes and the listed cases all reach the same exit, so WHICH ten labels
 * the source had is not recoverable from the bytes; 16..24 and 38 are a
 * stand-in, only the endpoints are pinned (2026-09-28 tree_ov010_4).
 *
 * symbols:
 *   func_0204581C  0x0204581C  arm
 *   func_02045994  0x02045994  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;

struct Strbuf;
struct U16Vec;
extern void func_0204581C(struct U16Vec *vec);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);

typedef struct Rec {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u8 pad32[2];
    u16 text[11];       /* 0x34 */
} Rec;

void func_02165ECC(Rec *r, void *buf)
{
    func_0204581C(buf);
    func_02045994(buf, r->text, 11);
    switch (r->type) {
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 38:
    case 47:
        return;
    }
}
