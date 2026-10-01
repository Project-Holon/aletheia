/*
 * function: func_021DECF4
 * address: 0x021DECF4
 * packet: pkt_ov137_021DECF4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_021DEB10 0x021DEB10 thumb ov137
 *   func_021841A0 0x021841A0 thumb ov022
 *   func_0203D4D0 0x0203D4D0 arm
 */
typedef unsigned char u8;
extern void *func_020399A8(void *);
extern void *func_021DEB10(void *);
extern int func_021841A0(void *);
extern int func_0203D4D0(void *, u8, int, int, void *, int, int, int);
int func_021DECF4(u8 *p)
{
    void *q;
    q = func_020399A8(p);
    if (func_0203D4D0(q, func_021841A0(func_021DEB10(p)), 10255, 1428, *(void **)(p + 0x24), 1, 1, 1))
        *(int *)p = 14;
    return 0;
}
