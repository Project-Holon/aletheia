/*
 * function: func_0202BABC
 * address:  0x0202BABC
 * packet:   pkt_0202B9F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * Blocked: 0202B9F0 (thumb, from header) has no witness outside 0202BABC..0202BAE6. Every concrete byte reproduces.
 * status:   MATCH
 * symbols:
 *   func_0202B9E0  0x0202B9E0  thumb
 *   func_0202B9F0  0x0202B9F0  thumb
 *   func_0202BB48  0x0202BB48  thumb
 *
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  func_02005C44(u32 v);
extern u32  func_0202B9F0(void *o, u32 v);
extern void func_0202B9E0(void *o, u32 v);
extern void func_0202BB48(void *o);

void func_0202BABC(u8 *o)
{
    if (*(u32 *)(o + 4) != 0) {
        return;
    }
    *(u32 *)(o + 4) = 1;
    func_0202B9E0(o, func_0202B9F0(o, func_02005C44(1)));
    func_0202BB48(o);
}
