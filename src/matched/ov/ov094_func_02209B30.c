/*
 * function: func_02209B30
 * address:  0x02209B30
 * packet:   pkt_ov094_02209B30
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02209C18  0x02209C18  thumb  ov094
 */

typedef struct {
    int h0;
    int f4;
    void *f8;
    int fc;
    int f10;
    int f14;
} P;

typedef unsigned int   u32;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_02209C18(char *p);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204ADA4(u32 i);
struct Bank;
extern void func_0204B1CC(struct Bank *bank);
extern void func_020307B0(void *p);

void func_02209B30(P *p)
{
    func_02030EAC(p->f8);
    func_02209C18((char *)p);
    func_0204A8D4(p->fc);
    func_0204AFD8(p->f14);
    func_0204ADA4(p->f10);
    func_0204B1CC((struct Bank *)p->h0);
    func_020307B0(p);
}
