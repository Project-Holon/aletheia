/*
 * function: func_021F5398
 * address: 0x021F5398
 * packet: pkt_ov073_021F5398
 * region: ov073
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201210C 0x0201210C thumb
 *   func_02189A08 0x02189A08 thumb ov021
 *   func_021CF52C 0x021CF52C thumb ov021
 *   func_020122C0 0x020122C0 thumb
 *   func_021F53C8 0x021F53C8 thumb ov073
 */
typedef unsigned int u32;
struct Ctx;
struct Desc;
extern void *func_0201210C(const struct Ctx *p);
extern int func_02189A08(unsigned char *p);
extern u32 *func_021CF52C(void *,u32,u32);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F53C8(void *,int *);
void *func_021F5398(void *a,int unused,u32 b,u32 c) {
    u32 *w;
    w=func_021CF52C((void *)func_02189A08((unsigned char *)((int)func_0201210C(a))),12,0x50);
    w[0]=0; w[1]=b; w[2]=c;
    return func_020122C0(a,0,(void *)func_021F53C8,0);
}
