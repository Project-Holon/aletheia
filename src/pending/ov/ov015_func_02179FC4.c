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
 *           pass 2 2026-10-06 P2L27 (40 compiles, 3 rounds): no gain, best stays 14/80. Found: when the flag store is the last
 *           store before the call (buf first, or flag assigned in the size argument) it sinks below add r0 / mov r1, but mov #0x56
 *           and strb then go to the top (20 off). A pointer local St *p = &d (any placement where it is not propagated) sinks both
 *           stores below the argument setup as in the original, but hoists mov #0x56 above it and swaps r4/r5 (24 off). Inert:
 *           irc.o file statics as in ov_sdk 02179F74, const u8 * callee parameter, nested-block u8 cmd = 0x56, inline helper with
 *           the flag assignment as argument, block-scoped buf, &buf[0], sizeof(buf), volatile flag field, pragmas
 *           lifetimes/propagation/common_subs/dead_assignments/optimize_for_size, int *flag pointer (62), q = buf (38).
 *           pass 3 2026-10-06 P3L13 (40 compiles, 3 rounds): best now 12/80 (body below). `#pragma scheduling` is an illegal
 *           pragma on this front end (docs/MATCHING.md), so the order is the scheduler's; a pick model (height, then textual
 *           order, memory edge from the direct flag store to the strb) predicts every form tried. A two-use pointer p = buf
 *           assigned in the block under opt_propagation off moves add r0,sp up to the original position; left: the strb goes
 *           through [r0] instead of [sp], and mov r1,r5 (always the call-time copy) stays after the stores. Inert (14):
 *           opt_lifetimes off (irc.o setting) on the base, comma statement, stores in a comma size argument, inline helpers
 *           (stores in body, &buf[0], enum size parameter, buffer-returning cmd(buf, 0x56)), named single-use p/n under
 *           propagation/common_subs/dead_assignments off (front end substitutes them), buf[size++] builder, IRCHeader local,
 *           K&R prototype, IRC_IsConnect inline guard, Raw second view for the flag. Worse: u8 cmd at function top (33,
 *           but the block order is then exactly the original), memset (79), init array (47), St *s pointer forms (20-22).
 *           Asm search: the sequence add r0,sp / mov r1 / global store / stack store / bl occurs only here.
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

#pragma opt_lifetimes off
#pragma opt_propagation off
void func_02179FC4(void)
{
    unsigned char buf[1];
    unsigned char *p;

    if (d_0217ABA8.f24 == 0 && d_0217ABA8.f1C == 0) {
        p = buf;
        d_0217ABA8.f1C = 1;
        p[0] = 0x56;
        func_0217A8EC(p, 1);
        d_0217ABA8.f20 = 1;
        d_0217ABA8.tick = OS_GetTick();
    }
}
#pragma opt_propagation reset
#pragma opt_lifetimes reset
