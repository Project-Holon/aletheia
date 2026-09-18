/*
 * function: func_020911D8
 * address:  0x020911D8
 * packet:   pkt_020911D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker:  the tail call to func_020911F0 is a Thumb `bx pc` + ARM
 *           `ldr ip/bx ip` linker stub whose pointer word is 0x02731755,
 *           inside no region of layout/layout.json (the TWL-only arm9i
 *           module this project does not extract).  veneer_at() therefore
 *           refuses condition 4, and the only branch to 0x020911F0 in the
 *           whole image is the one inside this file, so the site stays
 *           wildcarded.  No C change can fix it: the stub is not
 *           producible from C, so it can never earn a shard entry either.
 *
 * symbols:
 *   func_02085D88  0x02085D88  arm
 *   func_02088234  0x02088234  arm
 *   func_020911F0  0x020911F0  thumb
 */

typedef unsigned int u32;

extern int func_02085D88(u32 a0);
extern void func_02088234(void);
extern int func_020911F0(u32 a0);

int func_020911D8(u32 a0)
{
    if (func_02085D88(a0) == 0)
        func_02088234();
    {
        int r = func_020911F0(a0);
        return r;
    }
}
