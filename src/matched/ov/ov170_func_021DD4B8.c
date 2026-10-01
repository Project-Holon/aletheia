/*
 * function: func_021DD4B8
 * address: 0x021DD4B8
 * packet: pkt_ov170_021DD4B8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: declaring m before box selects r7 for m and r6 for box.
 * symbols:
 *   func_021DD684 0x021DD684 thumb ov170
 *   func_021DD8A8 0x021DD8A8 thumb ov170
 *   func_021DD314 0x021DD314 thumb ov170
 *   func_021EDAB0 0x021EDAB0 thumb ov170
 *   func_021EDB34 0x021EDB34 thumb ov170
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017988 0x02017988 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CFA0 0x0200CFA0 thumb
 *   func_020185F4 0x020185F4 thumb
 *   func_0200752C 0x0200752C thumb
 */
extern int func_021DD684(unsigned char *,unsigned);
extern void func_021DD8A8(unsigned char *,unsigned);
extern void func_021DD314(unsigned char *,int,int);
extern void func_021EDAB0(unsigned char *,unsigned);
extern void func_021EDB34(unsigned char *,unsigned);
extern void *func_0201AB28(void *,unsigned);
extern unsigned func_02017E1C(void *,unsigned,unsigned);
extern int func_02017988(void *,unsigned);
extern void *func_0200CA1C(void *);
extern void func_0200CFA0(void *,void *);
extern void *func_020185F4(void *);
extern int func_0200752C(void *,unsigned,void *);
void func_021DD4B8(unsigned char *p,unsigned a,unsigned b)
{
    void *m;
    unsigned box;
    box=func_021DD684(p,b);
    m=func_0201AB28((*(void ***)p)[2],a-30);
    if(func_02017E1C(m,5,0)==492){
        func_02017988(m,0);
        func_021DD8A8(p,a);
        func_0200CFA0(func_0200CA1C((*(void ***)p)[0]),m);
    }
    func_0200752C((*(void ***)p)[1],box,func_020185F4(m));
    func_021DD314(p,p[0x14],a);
    func_021EDAB0(p,box);
    func_021EDB34(p,box);
}
