/*
 * function: func_02201CA4
 * address:  0x02201CA4
 * packet:   pkt_ov094_02201CA4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 */
typedef struct Ent { void *h8; void *hc; void *h10; void *h14; } Ent;
typedef struct Res { void *owner; void *h; Ent e[7]; } Res;
typedef unsigned int   u32;
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
struct Obj;
extern void func_0204B3B4(struct Obj *p);

void func_02201CA4(Res *r, int i)
{
    func_0204A8D4((u32)r->e[i].hc);
    func_0204ADA4((u32)r->e[i].h10);
    func_0204AFD8((u32)r->e[i].h14);
    func_0204B3B4(r->e[i].h8);
    r->e[i].h8 = 0;
}
