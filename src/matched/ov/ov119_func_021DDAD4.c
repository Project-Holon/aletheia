/*
 * function: func_021DDAD4
 * address: 0x021DDAD4
 * packet: pkt_ov119_021DDAD4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E76F4 0x021E76F4 data a4
 *   func_021E1410 0x021E1410 thumb ov119
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DDA50 0x021DDA50 thumb ov119
 */
typedef struct { int a,b; } Pair;
extern const Pair d_021E76F4;
extern void func_021E1410(void *,Pair *,int);
extern void func_021B6558(int,int,int);
extern void func_021D8E84(void *,int);
extern void func_021DDA50(void *);
void func_021DDAD4(char *p)
{
    Pair t=d_021E76F4;
    func_021E1410(p,&t,2);
    func_021B6558(*(int *)(p+0x9c0),1,0);
    func_021D8E84(p,(int)func_021DDA50);
}
