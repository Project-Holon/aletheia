/*
 * function: func_022003EC
 * address:  0x022003EC
 * packet:   pkt_ov094_022003EC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02017100  0x02017100  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_020172AC  0x020172AC  thumb
 */
typedef unsigned int u32;

typedef struct {
    int pad00;              /* 0x00 */
    void *obj;              /* 0x04 */
} Work;

extern void func_02017100(void *p, int a, int v);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_020172AC(void *obj, int k);

void func_022003EC(Work *w, void *p, int a, int flags)
{
    int v = 1;

    if (flags & 1)
        v = 0;
    func_02017100(p, a, v);
    func_020172AC(w->obj, func_02017E1C(p, 0, 0));
}
