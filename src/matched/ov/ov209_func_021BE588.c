/*
 * function: func_021BE588
 * address: 0x021BE588
 * packet: pkt_ov209_021BE588
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD958 0x021BD958 thumb ov209
 *   func_021B8AE4 0x021B8AE4 thumb ov067
 *   func_021BD934 0x021BD934 thumb ov209
 */
typedef unsigned short u16;
struct S;
extern void func_021BD958(char *,int,short *,short *,u16);
extern unsigned func_021B8AE4(struct S *,unsigned);
extern void func_021BD934(char *,int,short,short,u16);
void func_021BE588(char *p)
{
    short pos[2];
    unsigned value;
    func_021BD958(p,0,&pos[1],&pos[0],0);
    value=func_021B8AE4(*(struct S **)(p+0xc2c),pos[0]);
    if(value<12)value=12;else if(value>156)value=156;
    func_021BD934(p,0,252,value,0);
}
