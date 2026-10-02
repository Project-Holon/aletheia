/*
 * function: func_021DF7F0
 * address: 0x021DF7F0
 * packet: pkt_ov119_021DF7F0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_02035D20 0x02035D20 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021E67C4 0x021E67C4 thumb ov119
 *   func_021DF8A0 0x021DF8A0 thumb ov119
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 */
typedef unsigned short u16;

extern int func_021D8AA8(void *);
extern int func_02035D20(unsigned *,unsigned *);
extern void func_021E67C4(void *,int);
extern void func_021DF8A0(void *,int,int);
extern int func_021D8A24(void *);
extern void *func_020399A8(void);
extern int func_0203D3A8(void *a, u16 b, u16 c, void *d);
void func_021DF7F0(void *p)
{
    unsigned x,y;
    unsigned char slot;
    if (!func_021D8AA8(p)) return;
    if (!func_02035D20(&x,&y)) return;
    if(x<8 || x>=104 || y<144 || y>=168) return;
    slot=(x-8)/24U;
    if(slot>=4) slot=3;
    func_021E67C4(p,slot);
    func_021DF8A0(p,slot,0);
    if(func_021D8A24(p)) func_0203D3A8(func_020399A8(),0xc0d,1,&slot);
}
