/*
 * function: func_021BD07C
 * address: 0x021BD07C
 * packet: pkt_ov216_021BD07C
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02043AF4 0x02043AF4 arm
 *   func_021BDA54 0x021BDA54 thumb ov216
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021BDD8A 0x021BDD8A data a2
 */
struct Four { unsigned short a; unsigned char b,c; };
extern const struct Four d_021BDD8A[];
extern void func_02043AF4(void *,short,int,unsigned short,unsigned short,int);
extern void func_021BDA54(void *,void *,unsigned char,int,int,unsigned short);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern void func_02045730(void *);
extern void func_020409B4(void);
void func_021BD07C(void *p,void **q,int v,short a,unsigned char b,unsigned char c,unsigned char d,unsigned char e)
{
    void *x;
    func_02043AF4(q[1],(short)(a*8),0,(unsigned short)(c*8),(unsigned short)(d*8),d_021BDD8A[e].b);
    func_021BDA54(p,q,b,0,v,d_021BDD8A[e].a);
    x=q[0];
    func_02045334(x); func_02045374(x); func_02045730(x); func_020409B4();
}
