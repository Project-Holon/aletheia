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

typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern int func_020399A8(void);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

void func_02173BB0(unsigned char *p)
{
    if (*(int *)(p + 0x3540) == 0) {
        func_02034714((void *)0x02175624, 0, (void *)0x02175624);
    }
    func_0203D3F8(func_020399A8(), 0xff, 0x1406, 0x678, *(int *)(p + 0x3540), 1, 0, 1);
}
