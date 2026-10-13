/*
 * function: FLDEFF_BTRAIN_Exit
 * address:  0x021D0308
 * packet:   pkt_ov021_021D0308
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Rec;
extern void G3D_SYSTEM_DeleteObject(struct Rec *p);
extern void G3D_SYSTEM_DeleteAnime(struct Rec *p);

void FLDEFF_BTRAIN_Exit(void *unused, u32 *p)
{
    int i;

    G3D_SYSTEM_DeleteObject((struct Rec *)p[3]);
    for (i = 0; i < 4; i++) {
        G3D_SYSTEM_DeleteAnime((struct Rec *)p[4 + i]);
    }
}
