/*
 * function: func_0215DB00
 * address: 0x0215DB00
 * packet: pkt_ov010_0215DB00
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_0215A168 0x0215A168 thumb ov010
 *   func_0215897C 0x0215897C thumb ov010
 */
typedef unsigned short u16;
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A168(int,int,int);
extern void func_0215897C(void *,void *);
int func_0215DB00(void *a,void *b)
{
 int x = (int)func_02159AE8(a,b);
 int y = (int)func_02159AE8(a,b);
 void *p = func_0215A5F4(b);
 func_0215897C(p,func_0215A168(func_0215A5DC(b),x,y));
 return 1;
}
