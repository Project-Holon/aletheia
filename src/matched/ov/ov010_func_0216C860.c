/*
 * function: func_0216C860
 * address: 0x0216C860
 * packet: pkt_ov010_0216C860
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201210C 0x0201210C thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0216C7FC 0x0216C7FC thumb ov010
 */
typedef unsigned int   u32;
struct Ctx;
struct Desc;
struct Obj;
extern void *func_0201210C(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int func_0216C7FC(int, int *, int *);
void *func_0216C860(void *a) {
    void *v; void *t; void **p;
    v=func_0201210C(a); t=func_020122C0(a,0,(void *)func_0216C7FC,0x14); p=func_020124E8(t);
    p[1]=a; *(void **)p=v; return t;
}
