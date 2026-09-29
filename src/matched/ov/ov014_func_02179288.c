/*
 * function: func_02179288
 * address:  0x02179288
 * packet:   pkt_ov014_02179288
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021797A8     0x021797A8  data   ov014  a4
 *   func_02178138  0x02178138  thumb  ov014
 *   func_02178168  0x02178168  thumb  ov014
 *   func_0208EF30  0x0208EF30  arm
 *   func_0203D6CC  0x0203D6CC  arm
 *   func_0203D6BC  0x0203D6BC  arm
 *   func_0203D680  0x0203D680  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int BOOL;

extern u8 *g_021797A8;

extern void func_02178138(int state);
extern BOOL func_02178168(void);
extern u16 func_0208EF30(void);
extern int func_0203D6CC(void);
extern int func_0203D6BC(void);
extern int func_0203D680(void);

BOOL func_02179288(int mode, u16 a, u16 b, u16 c)
{
    *(u16 *)(g_021797A8 + 0x1EBA) = 0;
    *(int *)(g_021797A8 + 0x1E74) = mode;
    func_02178138(3);
    *(u16 *)(g_021797A8 + 0xC) = a;
    *(u16 *)(g_021797A8 + 0x32) = b;
    *(u16 *)(g_021797A8 + 0x18) = func_0208EF30();
    if (func_0203D6CC() != 0) {
        *(u16 *)(g_021797A8 + 0x34) = func_0203D6CC();
    } else {
        *(u16 *)(g_021797A8 + 0x34) = func_0203D6BC() * func_0203D680() + 4;
    }
    *(u16 *)(g_021797A8 + 0x36) = func_0203D6BC();
    *(u16 *)(g_021797A8 + 0x10) = c;
    *(u16 *)(g_021797A8 + 0x16) = 0;
    *(u16 *)(g_021797A8 + 0x12) = 0;
    *(u16 *)(g_021797A8 + 0xE) = 1;
    *(u16 *)(g_021797A8 + 0x14) = (mode == 2);
    if (mode == 0 || mode == 2 || mode == 4)
        return func_02178168();
    return 0;
}
