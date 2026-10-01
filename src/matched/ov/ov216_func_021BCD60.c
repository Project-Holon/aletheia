/*
 * function: func_021BCD60
 * address: 0x021BCD60
 * packet: pkt_ov216_021BCD60
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6548 0x021B6548 thumb ov067
 */
extern void func_021B6548(void *,int,int);
struct Object { unsigned char bytes[0x124]; void *menu; };
void func_021BCD60(unsigned char *p)
{
    func_021B6548(((struct Object *)p)->menu,1,1);
    if(p[0x30]) func_021B6548(((struct Object *)p)->menu,3,1);
    else func_021B6548(((struct Object *)p)->menu,3,0);
    if(p[0x30]<p[0x2f]-1) func_021B6548(((struct Object *)p)->menu,2,1);
    else func_021B6548(((struct Object *)p)->menu,2,0);
}
