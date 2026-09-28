/*
 * function: func_02155E9C
 * address:  0x02155E9C
 * packet:   pkt_ov009_02155E9C
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
 *   func_02156400  0x02156400  thumb  ov009
 *   func_0216B804  0x0216B804  arm  ov009
 *   func_0203CA98  0x0203CA98  arm
 *   func_0203C9AC  0x0203C9AC  arm
 *   func_0203A338  0x0203A338  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *g_021A8264;
extern void func_02155374(u32);
extern void func_02156400(void);
extern int func_0216B804(void);
extern u32 *func_0203CA98(void);
extern void func_0203C9AC(u32, u32, u32, u32);
extern void func_0203A338(u32);

void func_02155E9C(int a, int b, int c, u32 d)
{
    if (d < 2) {
        *(u32 *)(g_021A8264 + 0x760) = 0;
        *(u32 *)(g_021A8264 + 0x78c) = 0;
        *(u32 *)(g_021A8264 + 0x778) = 0;
        if (a == 0) {
            if (g_021A8264[0x7a1] == 1 && func_0216B804() == 1) {
                if (*(u32 *)(g_021A8264 + 0x754) != 8) {
                    func_02155374(0x12);
                }
                if (*(u32 *)(g_021A8264 + 0x76c) != 0) {
                    func_02156400();
                }
            }
            if (b == 0) {
                func_02155374(0x12);
            }
        }
        if (g_021A8264[0x7a3] != 0) {
            u32 *q = func_0203CA98();
            if (q[3] == 0) {
                func_0203C9AC(q[0], q[1], q[2], 0x3f1);
            }
        }
        func_0203A338(d);
        {
            void (*cb)(u32, u32) = *(void (**)(u32, u32))(g_021A8264 + 0x284);
            if (cb != 0) {
                cb(d, *(u32 *)(g_021A8264 + 0x288));
            }
        }
    }
}
