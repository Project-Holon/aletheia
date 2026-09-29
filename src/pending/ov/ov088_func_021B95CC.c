/*
 * function: func_021B95CC
 * address:  0x021B95CC
 * packet:   pkt_ov088_021B95CC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct. Only blocker: func_0201160C (arm9, thumb, unlabelled getter,
 * 0x0201160C..0x02011610, 4 bytes inside the labelled arm9 unit_02011590 run;
 * Ilias's leaf). Its verified body (bytes 00 69 70 47):
 *     u32 func_0201160C(u32 *p) { return p[4]; }   // ldr r0,[r0,#0x10]; bx lr
 *
 * symbols:
 *   func_0204E720  0x0204E720  arm
 *   func_0204363C  0x0204363C  arm
 *   func_02040588  0x02040588  arm
 *   func_02043598  0x02043598  arm
 *   func_020434DC  0x020434DC  arm
 *   func_0201160C  0x0201160C  thumb
 *   func_021B9E7C  0x021B9E7C  thumb  ov088
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0204E720(int a, int b, int c, int d);
extern void func_0204363C(int a);
extern void func_02040588(int a, int b);
extern void func_02043598(int a, int b);
extern void func_020434DC(int a, int b);
extern u32  func_0201160C(int a);
extern void func_021B9E7C(void *a, int b);

void func_021B95CC(char *p)
{
    if (*(u32 *)(p + 0x8c) == 0x29A) {
        func_0204E720(12, 16, 0, 3);
        func_0204363C(1);
        func_02040588(6, 0);
        func_02043598(16, 0);
        func_020434DC(8, 0);
        *(u32 *)(p + 0x94) = 1;
    }
    if (*(u32 *)(p + 0x94) == 2 && func_0201160C(*(int *)(p + 0x4c)) == 0x015F3000)
        func_021B9E7C(p + 0x40, 0x14B5);
    *(u32 *)(p + 0x8c) += 1;
    if (*(u32 *)(p + 0x8c) > 0x1248) {
        *(u32 *)(p + 4) = 1;
        *(u16 *)p = 5;
    }
}
