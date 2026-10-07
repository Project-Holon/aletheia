/*
 * file:     unit_027040B4_p01.c
 * unit:     yes
 * function: func_027040B4, func_027040EC
 * address:  0x027040B4
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020862F0  0x020862F0  code twl a2
 *   func_02088610  0x02088610  code twl a2
 *   data_02150FEC  0x02150FEC  data a1
 *   func_020879EC  0x020879EC  arm twl a2
 */
typedef unsigned int u32;

extern void func_020862F0(u32, u32);
extern int func_02088610(u32, u32, u32);
extern u32 func_020879EC(void);
asm void func_027040B4(u32 a0);
u32 func_027040EC(void);
extern u32 data_02150FEC[];


asm void func_027040B4(u32 a0) {
    stmdb sp!, {r4, r5, r6, lr}
    mov r1, #0x800
    mov r4, r0
    bl func_020862F0
    mov r6, r4, lsr #5
    mov r5, #0x14
    mov r4, #0
@lbl_027040D0:
    mov r0, r5
    mov r1, r6
    mov r2, r4
    bl func_02088610
    cmp r0, #0
    dcd 0xbafffff9
    ldmfd sp!, {r4, r5, r6, pc}
}


/*
 *   witness.  The address is a real arm9 bss object (layout/data_objects.txt
 *   row `arm9 0x02150FEC pool`, 160+ ARM9 pool referrers), but sole-ref
 *   refuses it here because its only referrer inside this compared range IS
 *   the site under test, and a bss address has no ROM word for sole-ref/self.
 */
u32 func_027040EC(void) {
    if (func_020879EC() == 0x12) {
        return 0x80000000u;
    }
    return data_02150FEC[1];
}
