/*
 * function: func_0215642C
 * address: 0x0215642C
 * packet: pkt_ov009_0215642C
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Retains the live result of func_0216B838 as func_021AF2AC's argument.
 * symbols:
 *   d_021A8264 0x021A8264 data ov009 a4
 *   func_0216B838 0x0216B838 arm ov009
 *   func_021AF2AC 0x021AF2AC thumb ov013
 *   func_021AF30C 0x021AF30C thumb ov013
 */
typedef unsigned char u8;
extern u8 *d_021A8264;
extern int func_0216B838(void);
extern int func_021AF2AC(int);
extern void func_021AF30C(int);
void func_0215642C(int flag)
{
    if (flag) {
        func_021AF2AC(func_0216B838());
        d_021A8264[0x79F] = 1;
    } else {
        d_021A8264[0x79F] = 0;
    }
    func_021AF30C(d_021A8264[0x79F]);
}
