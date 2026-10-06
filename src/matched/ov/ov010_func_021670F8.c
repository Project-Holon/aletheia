/*
 * function: func_021670F8
 * address: 0x021670F8
 * packet: pkt_ov010_021670F8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02167080 0x02167080 thumb ov010
 *   func_0216711C 0x0216711C thumb ov010
 */
struct O;
extern int func_02167080(void *a, int *st, struct O *o, int a3);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0216711C(u8 *p, void *sys);
void *func_021670F8(void *p) {
    void *task;
    task = func_020122C0(p, 0, func_02167080, 32);
    func_0216711C(func_020124E8(task), p);
    return task;
}
