/*
 * function: func_021F69B0
 * address:  0x021F69B0
 * packet:   pkt_ov094_021F69B0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Applies each of the two transforms whose disable bit is clear.
 *
 * symbols:
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 */
typedef struct {
    char pad[0x24];
    void *h[2];             /* 0x24 */
    char xf[2][0x3c];       /* 0x2c */
    char padA4[0xb4 - 0xa4];
    unsigned off : 2;       /* 0xb4 */
} Obj;

struct Arg;
extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);

void func_021F69B0(Obj *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (!(p->off & (1 << i)))
            G3D_SYSTEM_DrawObject(p->h[i], (struct Arg *)p->xf[i]);
    }
}
