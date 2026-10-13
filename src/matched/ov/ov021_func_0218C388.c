/*
 * function: FIELD_BUILDMODEL_ResetAnimSet
 * address:  0x0218C388
 * packet:   pkt_ov021_0218C388
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_DisableObjectAnime  0x020477D4  arm
 */

typedef struct {
    int h;
    int f4;
    int arr[4];
} S;

typedef unsigned int   u32;
struct Owner;
int G3D_SYSTEM_DisableObjectAnime(struct Owner *owner, u32 index);

void FIELD_BUILDMODEL_ResetAnimSet(S *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (p->arr[i] != 0) {
            G3D_SYSTEM_DisableObjectAnime((struct Owner *)p->h, (unsigned short)i);
            p->arr[i] = 0;
        }
    }
}
