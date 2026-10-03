/*
 * function: func_02161824
 * address: 0x02161824
 * packet: pkt_ov010_02161824
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02161724 0x02161724 thumb ov010
 */

typedef unsigned int u32;
struct AnimWork;
struct Ctx;
struct Desc;
struct Obj;
extern int func_02161724(void *task, u32 *seq, struct AnimWork *w);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_020120F4(const struct Ctx *p);
void *func_02161824(void *a, void *b) { void *t; u32 *p; t=func_020122C0(a,0,func_02161724,0x10); p=func_020124E8(t); p[0]=(u32)a; p[1]=(u32)b; p[2]=(u32)func_020120F4(a); return t; }
