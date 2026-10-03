/*
 * function: func_0217DE60,func_0217DE8C,func_0217DE98
 * unit: yes
 * address: 0x0217DE60
 * packet: pkt_ov176_0217DE60
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E64C8 0x021E64C8 thumb ov177
 *   func_021E65FC 0x021E65FC thumb ov177
 *   func_021E5EF8 0x021E5EF8 thumb ov177
 *   func_021E62A0 0x021E62A0 thumb ov177
 *   func_020414EC 0x020414EC arm
 *   func_020409B4 0x020409B4 arm
 */
extern void func_021E5EF8(int);
extern void func_021E62A0(int);
typedef unsigned int   u32;
extern void func_020414EC(u32 i);
extern void func_020409B4(u32 index);
extern int func_021E64C8(int);
extern int func_021E65FC(int);
void func_0217DE60(int *p)
{
    if (p[2]) {
        if (p[5] == 0)
            func_021E5EF8(p[2]);
        else
            func_021E62A0(p[2]);
        p[2] = 0;
    }
    func_020414EC(1);
    func_020409B4(1);
}
int func_0217DE8C(int *p) { return func_021E64C8(p[2]); }
int func_0217DE98(int *p) { return func_021E65FC(p[2]); }
