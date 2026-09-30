/*
 * function: func_021C86B8
 * address: 0x021C86B8
 * packet: pkt_ov114_021C86B8
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 * d_021D3D28 0x021D3D28 data a4
 * d_021D3D2C 0x021D3D2C data a4
 * d_021CF538 0x021CF538 data a4
 * d_021D3D40 0x021D3D40 data a4
 * func_021C9EE4 0x021C9EE4 arm ov114
 * func_021CA470 0x021CA470 arm ov114
 * func_021CA1B4 0x021CA1B4 arm ov114
 * d_021D3E6C 0x021D3E6C data a4
 * d_021CF578 0x021CF578 data a4
 * func_02092344 0x02092344 arm
 */
extern unsigned int *d_021D3D28;
typedef struct { unsigned int words[0x4f]; unsigned int a; unsigned int gap[0x20]; unsigned int count, b, c; } State;
extern State d_021D3D2C;
extern unsigned int d_021CF538[], d_021D3D40[];
extern void func_021C9EE4(void *, void *);
extern int func_021CA470(void *, unsigned int, void *, unsigned int, unsigned int);
extern void func_021CA1B4(void);
extern unsigned int d_021D3E6C[], d_021CF578[];
extern void *func_02092344(void *, const void *, unsigned int);
void func_021C86B8(const void *a, const void *b, int c)
{
    func_02092344(d_021D3D40, a, 0x128);
    d_021D3D2C.a = 0;
    func_02092344(d_021D3E6C, b, c);
    d_021D3D2C.count = c;
    func_021C9EE4(d_021D3D28, d_021CF538);
    if (func_021CA470(d_021CF578, d_021D3D2C.words[2], d_021D3D40, 0x1b0, 0) == 0) {
        d_021D3D2C.words[0] = 2;
        return;
    }
    d_021D3D2C.words[0] = 24;
    d_021D3D2C.words[1] = -13;
    func_021CA1B4();
}
