/*
 * function: func_0215B4DC
 * address:  0x0215B4DC
 * packet:   pkt_0215B4DC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unpacks a record into a local and, when the overlay call says it took,
 * forwards the record and the third argument to the arm9 side.
 *
 * symbols:
 *   func_0215B4AC   0x0215B4AC  thumb  ov010
 *   func_02017E1C   0x02017E1C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215B4AC(void *, void *, void *);
extern u32 func_02017E1C(void *p, u32 id, u32 v);

int func_0215B4DC(void *a0, void *a1, void *a2)
{
    int v;

    if (func_0215B4AC(a0, a1, &v) == 1)
        return func_02017E1C((void *)v, (u32)a2, 0);

    return 0;
}

