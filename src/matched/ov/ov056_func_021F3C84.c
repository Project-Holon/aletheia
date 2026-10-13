/*
 * function: FIELD_FK_DEMO_StepModel
 * address:  0x021F3C84
 * packet:   pkt_ov056_021F3C84
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_FK_DEMO_GetAnimeEndFrame  0x021F36D4  thumb  ov056
 *   G3D_SYSTEM_SetObjectAnimeFrame  0x0204784C  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_FK_DEMO_GetAnimeEndFrame(u32 a);
typedef signed int     s32;
struct AnmCtl;
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u16 idx, s32 *frame);

int FIELD_FK_DEMO_StepModel(u32 *p)
{
    int r;
    int lim;
    int ret;

    r = FIELD_FK_DEMO_GetAnimeEndFrame(p[5]);
    lim = p[31] + 0x1000;
    if (r <= lim) {
        ret = 1;
        p[31] = r - 0x1000;
    } else {
        ret = 0;
        p[31] = lim;
    }
    G3D_SYSTEM_SetObjectAnimeFrame((struct AnmCtl *)p[7], 0, (int *)&p[31]);
    G3D_SYSTEM_SetObjectAnimeFrame((struct AnmCtl *)p[7], 1, (int *)&p[31]);
    return ret;
}
