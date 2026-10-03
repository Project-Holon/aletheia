/*
 * function: func_021DD464
 * address: 0x021DD464
 * packet: pkt_ov170_021DD464
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD2D0 0x021DD2D0 thumb ov170
 *   func_021DD684 0x021DD684 thumb ov170
 *   func_021EDAB0 0x021EDAB0 thumb ov170
 *   func_021EDB34 0x021EDB34 thumb ov170
 *   func_0200752C 0x0200752C thumb
 *   func_02007664 0x02007664 thumb
 */
extern void *func_021DD2D0(void ***,int,unsigned);
extern int func_021DD684(unsigned char *,unsigned);
typedef unsigned int   u32;
struct Sub02007454Entry;
extern int func_0200752C(void **save, u32 box, const struct Sub02007454Entry *src);
extern void func_02007664(void *,unsigned,unsigned);
extern void func_021EDAB0(unsigned char *,unsigned);
extern void func_021EDB34(unsigned char *,unsigned);
void func_021DD464(unsigned char *p,unsigned a,unsigned b,unsigned c)
{
    void *m;
    unsigned box;
    m = func_021DD2D0((void ***)p,a,b);
    box = func_021DD684(p,c);
    func_0200752C((*(void ***)p)[1],box,m);
    func_02007664((*(void ***)p)[1],a,b);
    func_021EDAB0(p,a);
    func_021EDB34(p,a);
    func_021EDAB0(p,box);
    func_021EDB34(p,box);
}
