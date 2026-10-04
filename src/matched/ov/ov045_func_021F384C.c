/*
 * function: func_021F384C
 * address: 0x021F384C
 * packet: pkt_ov045_021F384C
 * region: ov045
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021F39B8 0x021F39B8 thumb ov045
 */
typedef unsigned int u32;
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
typedef unsigned char  u8;
struct Big;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern int *func_021897BC(char *,int);
extern int func_021F39B8(void *,int *);
struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_021F384C(void *a,int b)
{
    u32 p;
    int *q;
    p=(u32)func_0201210C(a);
    func_02012EC4(func_020120F4(func_02188C80((void *)p)));
    q=func_021897BC((char *)p,1);
    if(b>=3)return 0;
    *q=b;
    return func_020122C0(a,0,func_021F39B8,0);
}
