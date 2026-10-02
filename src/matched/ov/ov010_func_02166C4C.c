/*
 * function: func_02166C4C
 * address: 0x02166C4C
 * packet: pkt_ov010_02166C4C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02166B58 0x02166B58 thumb ov010
 */
typedef unsigned char u8;
extern unsigned int func_02166B58(void *, unsigned int *, unsigned int *);
extern void *func_020122C0(void *, void *, void *, unsigned int);
extern void *func_020124E8(void *);
extern void *func_020120F4(const void *);
void *func_02166C4C(void *a, void *b, void *c) {
    void *task;
    void **w;
    task = func_020122C0(a, 0, func_02166B58, 24);
    w = func_020124E8(task);
    w[0] = a;
    w[2] = b;
    w[1] = func_020120F4(a);
    w[3] = c;
    return task;
}
