/*
 * function: func_021FDB40
 * address:  0x021FDB40
 * packet:   pkt_ov094_021FDB40
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   func_02006148  0x02006148  thumb
 *   func_0200616C  0x0200616C  thumb
 *   func_02006138  0x02006138  thumb
 *   func_02006268  0x02006268  thumb
 *   func_02072F34  0x02072F34  arm
 *   func_02073058  0x02073058  arm
 *   func_02073078  0x02073078  arm
 */
typedef unsigned int u32;
typedef unsigned short u16;

extern void func_020061E4(u32 a);
extern int func_02006148(u32 a);
struct Obj;
extern void func_0200616C(void *arg, int i);
extern u32 *func_02006138(int i);
extern void func_02006268(int i, u32 a, u32 b, u32 c);
extern void func_02072F34(char *p, unsigned int v);
extern void func_02073058(struct Obj *o, u32 v, u32 w);
extern void func_02073078(struct Obj *o, u32 v, u32 w);

void func_021FDB40(u32 a0, int m, int a2, int a3, unsigned int e, unsigned int f, unsigned int g)
{
    if (m == 5) {
        func_020061E4(a0);
        m = func_02006148(a0);
    } else {
        func_0200616C((void *)a0, m);
    }
    func_02072F34((char *)func_02006138(m), e);
    func_02006268(m, -1, -1, a2);
    func_02006268(m, -1, a3, -1);
    if (f) {
        func_02073058((struct Obj *)func_02006138(m), 0xffff, f);
        func_02073078((struct Obj *)func_02006138(m), 0xffff, g);
    }
}
