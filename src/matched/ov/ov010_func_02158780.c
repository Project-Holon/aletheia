/*
 * function: func_02158780
 * address: 0x02158780
 * packet: pkt_ov010_02158780
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020124E4 0x020124E4 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02012374 0x02012374 thumb
 *   func_02158920 0x02158920 thumb ov010
 */
typedef unsigned short u16;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_020124E8(struct Obj *p);
struct Evt;
extern void func_02012374(struct Evt *evt, struct Evt **out);
struct Desc;
extern struct Desc *func_02158920(int a, int b, int c, int d, int e);
int func_02158780(void *p, u16 b, int c, int d, u16 e)
{
    struct Desc *h = func_02158920((int)func_020124E4(p), e, b, c, d);
    int *q = func_020124E8((void *)h);
    func_02012374(p, (struct Evt **)((void **)h));
    return *q;
}
