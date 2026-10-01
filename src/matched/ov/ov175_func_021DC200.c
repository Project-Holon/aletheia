/*
 * function: func_021DC200
 * address: 0x021DC200
 * packet: pkt_ov175_021DC200
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_0201A918 0x0201A918 thumb
 */
extern unsigned long func_020399A8(void);
extern unsigned long func_0203D1A4(unsigned long);
extern unsigned long func_0203D3F8(unsigned long,unsigned long,unsigned long,unsigned long,unsigned long,unsigned long,unsigned long,unsigned long);
extern int func_0201A918(void);
void func_021DC200(char *p,unsigned long data)
{
    unsigned long busy=func_0203D1A4(func_020399A8());
    int flag=1;
    if(busy!=0) flag=0;
    func_0203D3F8(func_020399A8(),(unsigned char)flag,0x2403,func_0201A918(),data,1,1,1);
}
