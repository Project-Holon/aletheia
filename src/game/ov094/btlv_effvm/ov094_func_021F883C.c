/*
 * function: func_021F883C
 * address:  0x021F883C
 * packet:   pkt_ov094_021F883C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094
 *   func_022088F4  0x022088F4  thumb  ov094
 *   func_0220893C  0x0220893C  thumb  ov094
 *   func_02208900  0x02208900  thumb  ov094
 *   func_02005E9C  0x02005E9C  thumb
 *   func_02005D90  0x02005D90  thumb
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    char pad[0x1A4];
    void *obj;          /* 0x1A4 */
} Work;

extern Work *d_0220AF20;

extern u32 func_022088F4(void *o);
extern void func_0220893C(void *o, u32 v);
extern void func_02208900(void *o, u32 v);
extern int func_02005E9C(void);
extern void func_02005D90(u32 a, u32 b);

void func_021F883C(u32 a)
{
    if (func_022088F4(d_0220AF20->obj) == 1)
        func_02005E9C();
    func_0220893C(d_0220AF20->obj, 1);
    func_02208900(d_0220AF20->obj, 0);
    func_02005D90(a, 0x0000FFFF);
}
