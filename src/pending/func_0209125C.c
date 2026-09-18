/*
 * function: func_0209125C
 * address:  0x0209125C
 * packet:   pkt_020911D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker:  the call to func_02091284 is an ARM long-branch stub
 *           (`ldr pc, [pc, #-4]`) whose pointer word is 0x02731920, inside
 *           no region of layout/layout.json (arm9i, not extracted), so
 *           veneer_at() refuses condition 4 and the site stays wildcarded.
 *           The stub is not producible from C, so it can never earn a
 *           shard entry either.
 *
 * symbols:
 *   func_02085D88  0x02085D88  arm
 *   func_02088234  0x02088234  arm
 *   func_02091284  0x02091284  arm
 */

typedef unsigned int u32;

extern int func_02085D88(u32 a0);
extern void func_02088234(void);
extern int func_02091284(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);

int func_0209125C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    if (func_02085D88(a0) == 0)
        func_02088234();
    {
        int r = func_02091284(a0, a1, a2, a3, a4);
        return r;
    }
}
