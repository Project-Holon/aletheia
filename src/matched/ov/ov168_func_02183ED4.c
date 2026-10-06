/*
 * function: func_02183ED4
 * address:  0x02183ED4
 * packet:   pkt_02183ED4
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020434CC  0x020434CC  arm
 *   func_02043588  0x02043588  arm
 *   func_02022224  0x02022224  thumb
 */
typedef unsigned int u32;

extern void func_020434CC(void);
extern void func_02043588(void);
extern u32 func_02022224(void *win);

void func_02183ED4(int a0)
{
    func_020434CC();
    func_02043588();
    *(volatile u32 *)0x04000000 &= 0xFFFFE0FFu;
    *(volatile u32 *)0x04001000 &= 0xFFFFE0FFu;
    func_02022224((void *)0);
    func_02022224((void *)1);
}
