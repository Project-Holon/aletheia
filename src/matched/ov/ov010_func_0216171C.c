/*
 * function: func_0216171C
 * address: 0x0216171C
 * packet: pkt_ov010_0216171C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov010/event_field_proclink.c and filed here.
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */

extern int func_020307B0();
void func_0216171C(void);

/* Thumb tail call into the ARM function func_020307B0: ldr r3,[pc]; bx r3. */
void func_0216171C(void)
{
    func_020307B0();
}
