/*
 * function: func_021BFD24
 * address: 0x021BFD24
 * packet: pkt_ov093_021BFD24
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u16 c and u8 n recover spill scheduling; fifth e and C676C fourth argument are u16.
 * symbols:
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021C676C 0x021C676C thumb ov093
 *   func_021BFE30 0x021BFE30 thumb ov093
 *   func_021BFE40 0x021BFE40 thumb ov093
 *   func_021BFE50 0x021BFE50 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C6848 0x021C6848 thumb ov093
 *   func_021D5C30 0x021D5C30 thumb ov093
 *   func_021C5718 0x021C5718 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(void *, u32, int);
extern int func_021C676C(u8 *, u8 *, u8 *, u16, u8 *, u32 *);
extern int func_021BFE30(u8 *);
extern u8 *func_021BFE40(u8 *, int);
extern u8 func_021BFE50(void *, u8);
extern u8 func_021D5440(u8 *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C6848(u8 *, u8 *);
extern int func_021D5C30(u8 *);
extern void func_021C5718(u8 *, u8 *, u32);
int func_021BFD24(u8 *p, u8 *q, u16 c, u8 *d, u16 e)
{
    u32 out;
    u8 id;
    u32 lock;
    int r;
    u8 n;
    out = 0;
    id = 31;
    lock = func_021CC8D8(p + 0x1d74, 5160);
    r = func_021C676C(p, q, d, e, &id, &out);
    if (r) {
        n = p[0x77f];
        if (func_021BFE30(d))
            n = func_021BFE50(p + 0x1ab8, func_021D5440(func_021BFE40(d, 0)));
        func_021CD4B0(*(void **)(p + 12), 48, c, n, e, 0);
    }
    func_021CC95C(p + 0x1d74, lock, 5173);
    if (r) {
        lock = func_021CC8D8(p + 0x1d74, 5177);
        func_021C6848(p, q);
        func_021CC95C(p + 0x1d74, lock, 5179);
        if (func_021D5C30(q))
            func_021CD4B0(*(void **)(p + 12), 49, func_021D5440(q), 1);
        if (id != 31)
            func_021CD4B0(*(void **)(p + 12), 49, id, 1);
    } else if (out == 0) {
        func_021C5718(p, q, e);
    }
    return r;
}
