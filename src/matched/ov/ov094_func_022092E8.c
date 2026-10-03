/*
 * function: func_022092E8
 * address:  0x022092E8
 * packet:   pkt_ov094_022092E8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02209458  0x02209458  thumb  ov094
 */

typedef struct {
    int h0;
    int h4;
    char pad08[0x40 - 0x08];
    int h40;
    int h44;
    int h48;
} W;

extern void func_02209458(W *w);
typedef unsigned int   u32;
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204B1CC(int h);
extern void func_020307B0(void *p);

void func_022092E8(W *w)
{
    func_02209458(w);
    func_0204A8D4(w->h40);
    func_0204AFD8(w->h44);
    func_0204ADA4(w->h48);
    func_0204B1CC(w->h0);
    func_0204B1CC(w->h4);
    func_020307B0(w);
}
