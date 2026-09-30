/*
 * function: func_021C8E18
 * address: 0x021C8E18
 * packet: pkt_ov114_021C8E18
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021D3D28 0x021D3D28 data a4
 *   d_021D3D2C 0x021D3D2C data a4
 *   d_021CF538 0x021CF538 data a4
 *   d_021CF6B8 0x021CF6B8 data a4
 *   d_021D3D40 0x021D3D40 data a4
 *   func_02087C6C 0x02087C6C arm
 *   func_02092344 0x02092344 arm
 *   func_021C9EE4 0x021C9EE4 arm ov114
 *   func_021CA470 0x021CA470 arm ov114
 *   func_021CA1B4 0x021CA1B4 arm ov114
 */
extern void *d_021D3D28;
typedef struct { unsigned words[114]; unsigned value; } State;
extern State d_021D3D2C;
extern unsigned d_021CF538[], d_021CF6B8[], d_021D3D40[];
extern void func_02087C6C(void *);
extern void *func_02092344(void *, const void *, unsigned);
extern void func_021C9EE4(void *, void *);
extern int func_021CA470(void *, unsigned, void *, unsigned, unsigned);
extern void func_021CA1B4(void);
void func_021C8E18(unsigned char *p, unsigned x)
{
    func_02087C6C(p + 0x1c);
    func_02092344(d_021D3D40, p, 100);
    d_021D3D2C.value = x;
    func_021C9EE4(d_021D3D28, d_021CF538);
    if (func_021CA470(d_021CF6B8, d_021D3D2C.words[2], d_021D3D40, 100, 0) == 0) {
        d_021D3D2C.words[0] = 22;
        return;
    }
    d_021D3D2C.words[0] = 24;
    d_021D3D2C.words[1] = -13;
    func_021CA1B4();
}
