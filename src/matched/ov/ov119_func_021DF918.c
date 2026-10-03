/*
 * function: func_021DF918
 * address: 0x021DF918
 * packet: pkt_ov119_021DF918
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E6308 0x021E6308 thumb ov119
 *   func_021E293C 0x021E293C thumb ov119
 *   func_021E36D8 0x021E36D8 thumb ov119
 *   func_021E6F0C 0x021E6F0C thumb ov119
 *   func_021E272C 0x021E272C thumb ov119
 *   func_02041B6C 0x02041B6C arm
 *   func_021E36A8 0x021E36A8 thumb ov119
 */
extern void func_021E6308(void *,int,int);
typedef unsigned int   u32;
extern void func_021E293C(char *p, int i);
extern void func_021E36D8(void *,int);
extern void func_021E6F0C(char *p, int side, void *mon);
extern void func_021E272C(char *p, int i, void *mon);
extern void func_02041B6C(u32 bit);
extern void func_021E36A8(void *,int,int,void *,int,int);
void func_021DF918(void *p,int i,void *v)
{
    int one;
    func_021E6308(p,i,0);
    if (((unsigned char *)p+i)[0x11e2]) {
        func_021E293C(p,i);
        func_021E36D8(p,i);
    }
    func_021E6F0C(p,i,v);
    func_021E272C(p,i,v);
    one=1;
    func_02041B6C(1);
    func_021E36A8(p,i,one-i,v,one-i,one);
}
