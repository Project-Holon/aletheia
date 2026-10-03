/*
 * function: func_02156A58
 * address:  0x02156A58
 * packet:   pkt_ov009_02156A58
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   func_02155374  0x02155374  thumb  ov009
 *   func_02155D2C  0x02155D2C  thumb  ov009
 *   func_0203D650  0x0203D650  arm
 *   func_0216B7E0  0x0216B7E0  arm  ov009
 *   func_0216B908  0x0216B908  arm  ov009
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *g_021A8264;
extern void func_02155374(int v);
extern void func_02155D2C(int);
extern u32 func_0203D650(void);
extern void func_0216B7E0(u8);
extern int func_0216B908(void);

void func_02156A58(int a, int b, int c, int d, int e)
{
    int flag = 0;
    *(u32 *)(g_021A8264 + 0x778) = 0;
    if (a == 0) {
        if (b == 0) {
            if (g_021A8264[0x7a4] != 0 && e == -1) {
                flag = 1;
            }
            if (*(u32 *)(g_021A8264 + 0x2a4) != 0) {
                if (((int (*)(int, u32))*(u32 *)(g_021A8264 + 0x2a4))(e, func_0203D650()) == 0) {
                    flag = 1;
                }
            }
            if (g_021A8264[0x7a0] != 0 || flag != 0) {
                if (e != -1) {
                    func_0216B7E0(e);
                }
            }
            *(int *)(g_021A8264 + 0x770) = e;
            *(u32 *)(g_021A8264 + 0x798) = func_0216B908();
            if (*(u32 *)(g_021A8264 + 0x798) == 1) {
                func_02155374(8);
                return;
            }
            func_02155D2C(e);
            return;
        }
        if (c == 0) {
            *(u16 *)(g_021A8264 + 0x780) = e;
            *(int *)(g_021A8264 + 0x774) = flag - 1;
        }
    }
}
