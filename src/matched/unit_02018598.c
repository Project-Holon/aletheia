/*
 * unit:     yes
 * address:  0x02018598
 * packet:   pkt_0201854C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02018598, func_020185A0, func_020185B0
 *
 * The middle piece of the run 0x0201854C..0x0201862C.  Its two neighbours are
 * parked in src/pending/: func_02018584 is the only caller of func_02019BA4
 * in the image and func_020185C4 the only caller of func_02018A7C, so neither
 * has a witness outside itself and no cut reaches them.
 *
 * func_02018598 carries no label: it is the eight byte pool-word tail call of
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md to the function that follows
 * it, so the site is the `local` class.
 *
 * symbols:
 *   func_02017E40  0x02017E40  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_020185C4  0x020185C4  thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void func_02017E40(void *p, u32 id, u32 v);
extern u32  func_02017E88(void *p, u32 id, u32 v);
extern void func_020185C4(void *p);

u8 func_020185A0(void *p);

u8 func_02018598(void *p)
{
    return func_020185A0(p);
}

u8 func_020185A0(void *p)
{
    return (u8)func_02017E88(p, 0x70, 0);
}

void func_020185B0(void *p, u32 v)
{
    func_02017E40(p, 0x70, v);
    func_020185C4(p);
}
