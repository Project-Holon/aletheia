/*
 * function: func_02173BB0
 * address:  0x02173BB0
 * packet:   pkt_ov012_02173BB0
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

extern void func_02034714(void *file, int line, void *msg);
extern int func_020399A8(void);
extern int func_0203D3F8(int a, int b, int c, int d, int e, int f, int g, int h);

void func_02173BB0(unsigned char *p)
{
    if (*(int *)(p + 0x3540) == 0) {
        func_02034714((void *)0x02175624, 0, (void *)0x02175624);
    }
    func_0203D3F8(func_020399A8(), 0xff, 0x1406, 0x678, *(int *)(p + 0x3540), 1, 0, 1);
}
