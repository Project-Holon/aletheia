/*
 * function: func_021E8940
 * address:  0x021E8940
 * packet:   pkt_ov093_021E8940
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-02 DIFF: image is 899C-shaped (kind=2, b=v&0x3f) plus a second pooled mask 0x1ff applied to the whole word at the end (44 bytes, two pool words 0xFFFFFE07 and 0x000001FF). Tried s.c=0 with c:23 (shift form lsrs #0x17), c:16/d:7 (two masks, 52 bytes), return & 0x1ff, struct return; none give one pooled 0x1ff AND.
 *
 * symbols:

 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S { unsigned a:3; unsigned b:6; unsigned c:23; };

int func_021E8940(u32 a)
{
    struct S s = {0};

    s.a = 2;
    s.b = a & 0x3f;
    s.c = 0;
    return *(int *)&s;
}
