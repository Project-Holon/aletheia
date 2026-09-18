/*
 * function: func_02091200
 * address:  0x02091200
 * packet:   pkt_020911D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker:  tail call to the Thumb/ARM linker stub func_02091220 whose
 *           pointer word is 0x02731761, inside no region of
 *           layout/layout.json (arm9i, not extracted), so the veneer class
 *           refuses and the site has no witness outside this range.
 *
 * symbols:
 *   func_02085D88  0x02085D88  arm
 *   func_02088234  0x02088234  arm
 *   func_02091220  0x02091220  thumb
 */

typedef unsigned int u32;

extern int func_02085D88(u32 a0);
extern void func_02088234(void);
extern int func_02091220(u32 a0, u32 a1, u32 a2);

int func_02091200(u32 a0, u32 a1, u32 a2)
{
    if (func_02085D88(a0) == 0)
        func_02088234();
    {
        int r = func_02091220(a0, a1, a2);
        return r;
    }
}
