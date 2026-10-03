/*
 * function: func_021BE2F0
 * address: 0x021BE2F0
 * packet: pkt_ov172_021BE2F0
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0200ED48 0x0200ED48 thumb
 */
typedef unsigned int u32;
extern int func_02012EBC(u32 a);
extern void *func_0200ED48(void *p);
struct L0200ED54;
struct Sub0200852CObj;
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
void func_021BE2F0(u32 *p, void *q)
{
    void *l = func_0200ED48((void *)func_02012EBC(*(u32 *)p[0x7e]));
    func_0200ED54(l, func_02008530(q));
}
