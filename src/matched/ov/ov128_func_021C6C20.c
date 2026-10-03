/*
 * function: func_021C6C20
 * address: 0x021C6C20
 * packet: pkt_ov128_021C6C20
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201283C 0x0201283C thumb
 *   func_02009864 0x02009864 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 */
typedef unsigned char u8;
extern void *func_0201283C(const void *);
typedef unsigned int   u32;
struct Sub020097BCObj;
struct WordSet;
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
int func_021C6C20(u8 *p,u8 *q,int idx)
{
    void *base;
    unsigned v;
    int result;
    base=func_0201283C(*(void **)(q+4));
    result=1;
    v=func_02009864(base,idx,7);
    if(v==0) result=0;
    func_0201EFA4(*(void **)p,2,v,2,0,1);
    v=func_02009864(base,idx,5);
    func_0201EFA4(*(void **)p,0,v,4,1,1);
    v=func_02009864(base,idx,6);
    func_0201EFA4(*(void **)p,1,v,2,0,1);
    return result;
}
