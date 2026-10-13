/*
 * function: FLD3D_CI_PlayCueSound
 * address:  0x021C3158
 * packet:   pkt_ov021_021C3158
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Plays the next sound effect of the current cue table when its frame is
 * reached.
 *
 * symbols:
 *   d_021DA720     0x021DA720  data  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj00576.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int se;
    u32 frame;
} Ent;

extern Ent *d_021DA720[];
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

void FLD3D_CI_PlayCueSound(u8 *p)
{
    Ent *t = d_021DA720[((struct Obj00576 *)p)->f66];

    if (t[((struct Obj00576 *)p)->f136].se != -1 && ((struct Obj00576 *)p)->f134 == t[((struct Obj00576 *)p)->f136].frame) {
        GFL_USE_PlaySeDefaultVolume(t[((struct Obj00576 *)p)->f136].se);
        (((struct Obj00576 *)p)->f136)++;
    }
}
