/*
 * function: func_0202B7C8
 * address:  0x0202B7C8
 * packet:   pkt_0202B7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * Parked: every concrete byte is right; the only unresolved relocation site(s)
 * target 0202B420, which has no witness outside this range (no outside branch names it,
 * not a manifest entry, not in layout/runtime_arm9.txt).
 * status:   EXACT
 *
 * The callee is an unlabelled Thumb leaf, so its ISA has to be declared here;
 * without the `symbols:` line the name convention defaults it to ARM and the
 * `matched` class refuses the EXACT entry at 0x0202B420 on the ISA mismatch.
 *
 * symbols:
 *   sub_0202B420  0x0202B420  thumb

 * Closed by the `matched` class: 0x0202B420 was filed as an EXACT entry this wave (pkt_0202B1F4), and the callee had to be declared thumb here.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void sub_0202B420(void *p, u16 v);

void func_0202B7C8(u8 *p, u16 v)
{
    sub_0202B420(*(void **)(p + 0x18), v);
}
