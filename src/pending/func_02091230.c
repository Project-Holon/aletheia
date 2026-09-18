/*
 * function: func_02091230
 * address:  0x02091230
 * packet:   pkt_020911D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker:  tail call to the Thumb/ARM linker stub func_0209124C whose
 *           pointer word is 0x02731765, inside no region of
 *           layout/layout.json (arm9i, not extracted), so the veneer class
 *           refuses and the site has no witness outside this range.
 *
 * symbols:
 *   func_02085D88  0x02085D88  arm
 *   func_02088234  0x02088234  arm
 *   func_0209124C  0x0209124C  thumb
 */

typedef unsigned int u32;

extern int func_02085D88(u32 a0);
extern void func_02088234(void);
extern int func_0209124C(u32 a0, u32 a1);

int func_02091230(u32 a0, u32 a1)
{
    if (func_02085D88(a0) == 0)
        func_02088234();
    {
        int r = func_0209124C(a0, a1);
        return r;
    }
}
