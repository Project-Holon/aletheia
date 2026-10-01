/*
 * function: func_021F6F20
 * address:  0x021F6F20
 * packet:   pkt_ov094_021F6F20
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds the transform at 0x18/0x24, then loads it into the handle at word 1 and commits.
 *
 * symbols:
 *   func_021F7108 0x021F7108 thumb ov094
 *   func_02048AFC 0x02048AFC arm
 *   func_02048AD0 0x02048AD0 arm
 */
typedef struct {
    char pad[4];
    void *h;            /* 0x04 */
    char pad08[0x18 - 8];
    int m[3];           /* 0x18 */
    int v[3];           /* 0x24 */
} Obj;

extern void func_021F7108(Obj *, int, int, int *, int *);
extern void func_02048AFC(void *, int *);
extern void func_02048AD0(void *);

void func_021F6F20(Obj *p, int a, int b)
{
    func_021F7108(p, a, b, p->m, p->v);
    func_02048AFC(p->h, p->m);
    func_02048AD0(p->h);
}
