/*
 * function: ICA_ANIME_SetCameraPos
 * address:  0x02011CF0
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
 *   G3D_CAMERA_SetEye  0x02048AFC  arm
 *
 * Twelve bytes of stack filled by ICA_ANIME_GetTranslate from the *second* argument
 * (the first word handed to it is r1, not r0), then the buffer goes to the ARM
 * function G3D_CAMERA_SetEye together with the original first argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ICA_ANIME_SetCameraPos.c \
 *       --func ICA_ANIME_SetCameraPos --addr 0x02011CF0 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;

struct IcaAnime;
struct Rec12;
extern unsigned int ICA_ANIME_GetTranslate(struct IcaAnime *a1, struct Rec12 *buf);
extern void G3D_CAMERA_SetEye(void *a0, const u8 *buf);

void ICA_ANIME_SetCameraPos(void *a0, void *a1)
{
    u8 buf[0xc];

    ICA_ANIME_GetTranslate(a1, (struct Rec12 *)buf);
    G3D_CAMERA_SetEye(a0, buf);
}
