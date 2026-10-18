/*
 * function: ICA_ANIME_SetCameraTarget
 * address:  0x02011D0C
 * packet:   pkt_020116E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ICA_ANIME_GetTranslate  0x02011610  thumb
 *   G3D_CAMERA_SetCamTarget  0x02048B44  arm
 *
 * Identical to ICA_ANIME_SetCameraPos except for the second callee, G3D_CAMERA_SetCamTarget.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ICA_ANIME_SetCameraTarget.c \
 *       --func ICA_ANIME_SetCameraTarget --addr 0x02011D0C --cc 1.1p1 --thumb
 */

typedef unsigned char u8;

struct IcaAnime;
struct Rec12;
extern unsigned int ICA_ANIME_GetTranslate(struct IcaAnime *a1, struct Rec12 *buf);
extern void G3D_CAMERA_SetCamTarget(void *a0, const u8 *buf);

void ICA_ANIME_SetCameraTarget(void *a0, void *a1)
{
    u8 buf[0xc];

    ICA_ANIME_GetTranslate(a1, (struct Rec12 *)buf);
    G3D_CAMERA_SetCamTarget(a0, buf);
}
