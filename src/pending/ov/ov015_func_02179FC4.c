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
 *           final push 2026-10-05 G5L2 (40 compiles, 3 rounds): best form is the sibling's struct view (St as in matched
 *           0217A1FC), 14 bytes off: ours str flag / mov r2 / add r0 / mov r1 / strb; original add r0 / mov r1 / str / mov r2 / strb.
 *           Only the position of mov r2,#0x56 and the flag store differ. Raw-offset form is 16 off. Tried with no gain: inline
 *           send(c) helpers (with and without the pointer and count as parameters), p = buf alias at top or in the block, named
 *           locals n and p with opt_propagation off, u8 n, struct Pkt, u8 scalar local with &cmd, signed char 'V', unsigned
 *           pointer types, callee prototypes (void *, u16 size, int return), nested ifs, early return, buf store before or after
 *           the flag store, tick via u64 temp, brace initialiser in block (53 off), pragmas lifetimes/propagation/scheduling on
 *           the struct form. scheduling off shows the IR already orders str, mov r2, add, mov r1, strb, so the original IR has
 *           the const materialised late; no human source form found that does this.
 *
 * symbols:
 *   func_0217A8EC  0x0217A8EC  arm    ov015
 *   OS_GetTick     0x020870D0  arm
 *   d_0217ABA8     0x0217ABA8  data   ov015
 */

typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct {
    int f0, f4, f8, fC, f10, f14, f18;
    int f1C;
    u32 f20;
    int f24;
    u64 tick;
} St;
extern St d_0217ABA8;
extern void func_0217A8EC(unsigned char *data, unsigned char size);
extern u64 OS_GetTick(void);

void func_02179FC4(void)
{
    unsigned char buf[1];

    if (d_0217ABA8.f24 == 0 && d_0217ABA8.f1C == 0) {
        d_0217ABA8.f1C = 1;
        buf[0] = 0x56;
        func_0217A8EC(buf, 1);
        d_0217ABA8.f20 = 1;
        d_0217ABA8.tick = OS_GetTick();
    }
}
