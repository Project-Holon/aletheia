/*
 * function: func_021E5868
 * address: 0x021E5868
 * packet: pkt_ov177_021E5868
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned int   u32;
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020307B0(void *);
typedef struct { int a, b, c, d, e, f; } S5868;
void func_021E5868(S5868 *p)
{
    func_0204ADA4(p->a);
    func_0204A8D4(p->c);
    func_0204AFD8(p->e);
    func_0204ADA4(p->b);
    func_0204A8D4(p->d);
    func_0204AFD8(p->f);
    func_02040DA8(0, 1, 0);
    func_020307B0(p);
}
