/*
 * function: func_0219D2CC
 * address:  0x0219D2CC
 * packet:   pkt_ov021_0219D2CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Promoted 2026-09-27 (lane ov010 blocker tree).  The call at +0x08 is a
 * Thumb `bl` (d0 f7 10 f9), not an interworking `blx`: the target must be
 * Thumb.  The old header called 0x0216D4F8 `arm ov009`, but ov009's byte
 * there is an ARM fragment with no start, while ov010 holds an EXACT Thumb
 * getter (src/matched/func_0216D4F8.c, shard layout/matched/ov010/
 * pkt_0216D4F8.json).  With the region/ISA hint fixed to `thumb ov010` the
 * site resolves as `matched` and the entry is EXACT.
 *
 * symbols:
 *   func_0216D4F8  0x0216D4F8  thumb  ov010
 *   d_021DDD70     0x021DDD70  data ov021 a4
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_0216D4F8(u8 *p);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern unsigned char d_021DDD70[];
void func_0219D2CC(int *obj)
{
    *(int *)((char *)obj + 0x20) =
        (int)func_02030734(func_0216D4F8((u8 *)obj[4]), 0x30, 1, (const char *)d_021DDD70, 0x979);
}
