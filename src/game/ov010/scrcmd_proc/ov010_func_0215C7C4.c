/*
 * function: func_0215C7C4
 * address:  0x0215C7C4
 * packet:   pkt_ov010_0215C7C4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf (callback of func_0215C7E0): stores whether the
 * first record's word at +4 equals 1 into the halfword the second record
 * points to, then frees the first record's first word.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Rec {
    u32 *src;
    u16 *dst;
} Rec;

extern u32 func_020307B0(void *p);

void func_0215C7C4(Rec *r)
{
    if (r->src[1] == 1)
        *r->dst = 1;
    else
        *r->dst = 0;
    func_020307B0(r->src);
}
