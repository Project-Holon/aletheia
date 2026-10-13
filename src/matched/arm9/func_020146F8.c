/*
 * function: func_020146F8
 * address:  0x020146F8
 * packet:   pkt_02014628
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   FIELD_STATUS_SubProcEvent  0x02014628  thumb
 */

typedef unsigned int u32;

struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern u32 FIELD_STATUS_SubProcEvent(void *obj, u32 *mode, u32 *p);

void *func_020146F8(char *a0, int a1, int a2, int a3, int a4)
{
    void *r = func_020122C0(a0, 0, (void *)((int)FIELD_STATUS_SubProcEvent), 0x14);
    u32 *p = func_020124E8(r);

    p[0] = (u32)a0;
    p[1] = a1;
    p[2] = a2;
    p[3] = a3;
    p[4] = a4;
    return r;
}
