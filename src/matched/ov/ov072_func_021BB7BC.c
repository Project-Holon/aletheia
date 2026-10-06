/*
 * function: func_021BB7BC
 * address:  0x021BB7BC
 * packet:   pkt_ov072_021BB7BC
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204335C  0x0204335C  arm
 *   func_020433E0  0x020433E0  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0204361C  0x0204361C  arm
 *   func_020434CC  0x020434CC  arm
 *   func_0201DD60  0x0201DD60  thumb
 *   d_021BBBDC     0x021BBBDC  data  ov072
 */
typedef unsigned short u16;
typedef unsigned int   u32;

extern char d_021BBBDC[];

extern void func_0204335C(u32 a);
struct DispVram;
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32 a);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_0201DD60(void);

void func_021BB7BC(void)
{
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021BBBDC);
    func_0204363C(0);
    func_0204361C();
    func_020434CC();
    func_0201DD60();
}
