/*
 * function: func_02162040
 * address: 0x02162040
 * packet: pkt_ov010_02162040
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * The full target body overwrites r1/r2 with 0/8 before use; neither
 * caller nor thunk supplies those legacy trailing parameters.
 * symbols:
 *   func_02162358 0x02162358 thumb ov010
 */
extern void func_02162358(int a0);
void func_02162040(char *p)
{
    func_02162358((int)p);
}
