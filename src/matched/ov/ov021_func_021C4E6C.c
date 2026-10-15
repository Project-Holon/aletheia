/*
 * function: SOUND_OBJ_ApplyRotation
 * address:  0x021C4E6C
 * packet:   pkt_ov021_021C4E6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Same HSV-to-RGB shape as arm9 ICA_ANIME_SetCameraStatus: three 4.12 channels from
 * ICA_ANIME_GetRotate, wrapped into [0,360), rescaled to 0..65535, handed to
 * BUTTON_MAN_MakeRotMtxXYZ.
 *
 * symbols:
 *   _fdiv          0x0209CE10  arm
 *   _fflt          0x0209BDBC  arm
 *   _ffixu         0x0209C4C8  arm
 *   _fls           0x0209BC74  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   ICA_ANIME_GetRotate  0x02011638  thumb
 *   MTX_Identity33_  0x0207ADC4  arm
 *   BUTTON_MAN_MakeRotMtxXYZ  0x020520FC  arm
 */
#include "../include/Obj01666.h"

typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct IcaAnime;
struct Rec12;
extern u32 ICA_ANIME_GetRotate(struct IcaAnime *ctx, struct Rec12 *hsv);
extern void MTX_Identity33_(void *p);
struct Mtx33;
extern void BUTTON_MAN_MakeRotMtxXYZ(int h, int s, int v, struct Mtx33 *out);

void SOUND_OBJ_ApplyRotation(char *p)
{
    s32 hsv[3];
    u16 ch;
    u16 cs;
    u16 cv;
    float h;
    float s;
    float v;

    if (((struct Obj01666 *)p)->f10 == 0) {
        return;
    }
    if (ICA_ANIME_GetRotate(((struct Obj01666 *)p)->f10, (struct Rec12 *)hsv) != 1) {
        return;
    }

    h = hsv[0] / 4096.0f;
    s = hsv[1] / 4096.0f;
    v = hsv[2] / 4096.0f;

    while (h < 0.0f) {
        h += 360.0f;
    }
    while (s < 0.0f) {
        s += 360.0f;
    }
    while (v < 0.0f) {
        v += 360.0f;
    }

    ch = (u16)(u32)(65535.0f * (h / 360.0f));
    cs = (u16)(u32)(65535.0f * (s / 360.0f));
    cv = (u16)(u32)(65535.0f * (v / 360.0f));
    MTX_Identity33_(*(char * *)&((struct Obj01666 *)p)->f14 + 0x18);
    BUTTON_MAN_MakeRotMtxXYZ(ch, cs, cv, (struct Mtx33 *)(*(char * *)&((struct Obj01666 *)p)->f14 + 0x18));
}
