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
 * status:   MATCH
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void sub_0202B420(void *p);

void func_0202B7C8(u8 *p)
{
    sub_0202B420(*(void **)(p + 0x18));
}
