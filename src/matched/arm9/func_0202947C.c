/*
 * function: func_0202947C
 * address:  0x0202947C
 * packet:   pkt_02029354
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The callee is an unlabelled Thumb leaf, so its ISA has to be declared here;
 * without the `symbols:` line the name convention defaults it to ARM and the
 * `matched` class refuses the EXACT entry at 0x02012E40 on the ISA mismatch.
 *
 * symbols:
 *   func_02012E40  0x02012E40  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202947C.c \\
 *       --func func_0202947C --addr 0x0202947C --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  func_02012E40(u32 v);

u32 func_0202947C(u8 *p)
{
    return func_02012E40(*(u32 *)p);
}
