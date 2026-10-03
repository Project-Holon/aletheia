/*
 * function: func_021AEB20
 * address:  0x021AEB20
 * packet:   pkt_ov013_021AEB20
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0208B24C  0x0208B24C  arm
 *   func_0208B8B0  0x0208B8B0  arm
 *   func_0208BEF0  0x0208BEF0  arm
 *   func_0208BF38  0x0208BF38  arm
 *   func_021B0CD8  0x021B0CD8  arm  ov013
 *   func_020726D0  0x020726D0  arm
 *   func_020737C0  0x020737C0  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_021B0D08  0x021B0D08  arm  ov013
 *   d_021B3C80     0x021B3C80  data  ov013
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *d_021B3C80;

extern void func_0208B24C(void);
extern void func_0208B8B0(void);
extern unsigned int func_0208BEF0(unsigned int status);
extern unsigned int func_0208BF38(unsigned int gain);
extern void func_021B0CD8(int x);
extern void func_020726D0(void);
extern void func_020737C0(void *p);
extern void func_02082AC0(int v, void *p, u32 n);
extern void func_021B0D08(int x);

void func_021AEB20(void)
{
    func_0208B24C();
    func_0208B8B0();
    func_0208BEF0(1);
    func_0208BF38(3);
    func_021B0CD8(1);
    func_020726D0();
    func_020737C0(d_021B3C80 + 0x19B8);
    func_02082AC0(0, d_021B3C80 + 0x1104, 0x880);
    *(u32 *)(d_021B3C80 + 0x1A44) = 0;
    func_021B0D08(1);
}
