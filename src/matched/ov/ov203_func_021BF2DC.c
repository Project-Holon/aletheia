/*
 * function: func_021BF2DC
 * address: 0x021BF2DC
 * packet: pkt_ov203_021BF2DC
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_021BF320 0x021BF320 thumb ov203
 *   func_021BF404 0x021BF404 thumb ov203
 */
extern void *func_020311B8(void *,void (*)(void *,void *),unsigned,unsigned),*func_02031290(void *);
extern void func_021BF320(void *,void *),func_021BF404(char *,void *,int,int,int,unsigned char,unsigned char,unsigned char,unsigned char);
void func_021BF2DC(char *p,int a,int b,int c,unsigned char d,unsigned char e,unsigned char f,unsigned char g)
{
    func_021BF404(p,func_02031290(func_020311B8(*(void **)(p+0x20),func_021BF320,0x28,1)),a,b,c,d,e,f,g);
}
