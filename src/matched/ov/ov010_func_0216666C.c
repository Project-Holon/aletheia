/*
 * function: func_0216666C
 * address: 0x0216666C
 * packet: pkt_ov010_0216666C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021666B8 0x021666B8 thumb ov010
 *   func_02161CDC 0x02161CDC thumb ov010
 *   func_0216670C 0x0216670C thumb ov010
 */
typedef unsigned char u8;
extern int func_021666B8(void *, unsigned int *);
typedef unsigned int   u32;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02161CDC(void *, void *, u8, u8);
extern int func_0216670C(void *);
void *func_0216666C(void *a, void *b, void *c) {
    void *task;
    void **w;
    task = func_020122C0(a, 0, func_021666B8, 32);
    w = func_020124E8(task);
    w[6] = b;
    w[7] = c;
    func_02161CDC(w, a, 1, 0);
    ((int *)w)[2] = func_0216670C(b);
    return task;
}
