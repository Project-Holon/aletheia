/*
 * function: func_021C829C
 * address:  0x021C829C
 * packet:   pkt_ov111_021C829C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GX_LoadOBJPltt  0x0207E51C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef struct {
    unsigned char pad0[0xC];
    unsigned char *fC;
} Res;

typedef struct {
    unsigned char pad0[0x158];
    Res *res[3];
} Work;

extern void GX_LoadOBJPltt(const void *src, int ofs, int size);

void func_021C829C(Work *p, int idx, int k)
{
    if (k > 2) {
        k = 2;
    }
    GX_LoadOBJPltt((unsigned short *)p->res[k]->fC + idx * 16, idx * 32, 32);
}
