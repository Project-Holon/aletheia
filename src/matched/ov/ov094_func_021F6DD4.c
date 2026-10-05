/*
 * function: func_021F6DD4
 * address:  0x021F6DD4
 * packet:   pkt_ov094_021F6DD4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unless flag bit 0 at 0x68 is set, applies the vector at 0x1c to the handle at 0x18.
 *
 * symbols:
 *   func_02047A60 0x02047A60 arm
 */
typedef struct {
    char pad[0x18];
    void *h;            /* 0x18 */
    int v[3];           /* 0x1c */
    char pad28[0x68 - 0x28];
    unsigned b0 : 1;    /* 0x68 */
} Obj;

extern void func_02047A60(void *, int *);

void func_021F6DD4(Obj *p)
{
    if (!p->b0)
        func_02047A60(p->h, p->v);
}
