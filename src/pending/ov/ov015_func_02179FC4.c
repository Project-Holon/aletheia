/*
 * function: func_02179FC4
 * address:  0x02179FC4
 * packet:   pkt_ov015_02179FC4
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * notes:    2026-10-05 wave P20 lane 4: libirc start. If the fields at +0x24 and +0x1c are both zero, sets +0x1c, sends the
 *           one-byte frame 0x56 through func_0217A8EC (IRCi_Write), sets +0x20 and stores OS_GetTick (u64) at +0x28.
 *           Residue: 16 bytes, pure schedule order. Original: add r0,sp / mov r1,r5 / str r5,[+0x1c] / mov r2,#0x56 / strb.
 *           Ours: mov r2,#0x56 first, then add r0 / mov r1 / str. Tried (one compile each): flag store before or after
 *           buf[0]; struct with named fields; int local for the constant 1; u8 local c instead of buf[1]; c initialised at
 *           declaration; nested block local; buf[4]; callee size as int; pointer alias p = buf; array initialiser
 *           {0x56}; early return guard; int-array extern; pragmas scheduling, opt_propagation, opt_lifetimes,
 *           opt_common_subs, opt_dead_assignments, peephole off. All keep 16 bytes off or worse. Callees checked:
 *           func_0217A8EC is void (u8 *, u8) in matched ov_sdk, OS_GetTick returns u64, no arity problem.
 *
 * symbols:
 *   func_0217A8EC  0x0217A8EC  arm    ov015
 *   OS_GetTick     0x020870D0  arm
 *   d_0217ABA8     0x0217ABA8  data   ov015
 */

extern char d_0217ABA8[];
extern void func_0217A8EC(unsigned char *data, unsigned char size);
extern unsigned long long OS_GetTick(void);

void func_02179FC4(void)
{
    unsigned char buf[1];

    if (*(int *)(d_0217ABA8 + 0x24) == 0 && *(int *)(d_0217ABA8 + 0x1c) == 0) {
        *(int *)(d_0217ABA8 + 0x1c) = 1;
        buf[0] = 0x56;
        func_0217A8EC(buf, 1);
        *(int *)(d_0217ABA8 + 0x20) = 1;
        *(unsigned long long *)(d_0217ABA8 + 0x28) = OS_GetTick();
    }
}
