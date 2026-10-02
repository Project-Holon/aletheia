/*
 * function: func_02167044
 * address: 0x02167044
 * packet: pkt_ov010_02167044
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02166F9C 0x02166F9C thumb ov010
 *   func_02030734 0x02030734 arm
 *   d_02172A00 0x02172A00 data a1
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02166F9C(void *, int *, int *);
extern const char d_02172A00[];
extern void *func_020122C0(void *, void *, void *, u32);
extern void *func_020124E8(void *);
extern void *func_02030734(u32, u32, int, const char *, u16);
void *func_02167044(void *a, void *b) {
    void *task;
    void **w;
    void **q;
    task = func_020122C0(a, 0, func_02166F9C, 12);
    w = func_020124E8(task);
    w[0] = a;
    w[1] = b;
    q = func_02030734(4, 4, 0, d_02172A00, 117);
    w[2] = q;
    q[0] = a;
    return task;
}
