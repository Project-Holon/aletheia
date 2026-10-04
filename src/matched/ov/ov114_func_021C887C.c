/*
 * function: func_021C887C
 * address:  0x021C887C
 * packet:   pkt_ov114_021C887C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Twin of func_021C87FC: same shape, a different packet-descriptor
 * constant (d_021CF5D4) and a success code of 8 instead of 6.  Overlay
 * hints omitted for the same overlapping-bss reason.
 *
 * symbols:
 *   d_021D3D28   0x021D3D28  data  a4
 *   d_021D3D2C   0x021D3D2C  data  a4
 *   d_021CF538   0x021CF538  data  a4
 *   d_021CF5D4   0x021CF5D4  data  a4
 *   d_021D3D40   0x021D3D40  data  a4
 *   func_021C9EE4 0x021C9EE4  arm
 *   func_021CA470 0x021CA470  arm
 *   func_021CA1B4 0x021CA1B4  arm
 */

extern unsigned int *d_021D3D28;
extern unsigned int d_021D3D2C[];
extern unsigned int d_021CF538[];
extern unsigned int d_021CF5D4[];
extern unsigned int d_021D3D40[];

extern void func_021C9EE4(int server, char *initdata);
extern int func_021CA470(void *, unsigned int, void *, unsigned int, unsigned int);
extern void func_021CA1B4(void);

void func_021C887C(unsigned int x)
{
    d_021D3D2C[0x72] = x;
    func_021C9EE4((int)((void *)d_021D3D28), (char *)d_021CF538);
    if (func_021CA470(d_021CF5D4, d_021D3D2C[2], d_021D3D40, 0x1b0, 0) == 0) {
        d_021D3D2C[0] = 8;
        return;
    }
    d_021D3D2C[0] = 0x18;
    d_021D3D2C[1] = -0x0d;
    func_021CA1B4();
}
