/*
 * function: SCRCMD_MMDL_ICA_Update
 * address:  0x021D18F4
 * packet:   pkt_ov021_021D18F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ICA_ANIME_IncFrameLoop  0x02011590  thumb
 *   ICA_ANIME_Delete  0x02011558  thumb
 *   SCRCMD_MMDL_ICA_ApplyFrame  0x021D1988  thumb  ov021
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_InitPosition  0x0216E014  thumb  ov010
 *   FLDMMDL_ClearMoveBit  0x0216D570  thumb  ov010
 *   FLDMMDL_CallDrawProc  0x0216D758  thumb  ov010
 *   gMmdlIcaReleaseMoveBitTable     0x021DD5E0  data    ov021  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01673.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

typedef struct Vec3 { s32 x, y, z; } Vec3;

struct IcaAnime;
extern u32 ICA_ANIME_IncFrameLoop(struct IcaAnime *p, s32 v);
extern void ICA_ANIME_Delete(struct IcaAnime *p);
extern void SCRCMD_MMDL_ICA_ApplyFrame(u32 a, u32 b, struct Vec3 *c);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void FLDMMDL_InitPosition(void *a, int *p, int b);
extern char *FLDMMDL_ClearMoveBit(char *p, u32 v);
extern void FLDMMDL_CallDrawProc(void *a0);
extern u32 gMmdlIcaReleaseMoveBitTable[];

void SCRCMD_MMDL_ICA_Update(u32 a, u32 b, u8 *p)
{
    Vec3 v;

    if (p[0x19A] == 0) {
        return;
    }
    if (p[0x19A] == 1) {
        if (ICA_ANIME_IncFrameLoop((struct IcaAnime *)(((struct Obj01673 *)p)->f184), 0x1000) == 0) {
            SCRCMD_MMDL_ICA_ApplyFrame(((struct Obj01673 *)p)->f184, ((struct Obj01673 *)p)->f0, (struct Vec3 *)(p + 0x18C));
        } else {
            ICA_ANIME_Delete((struct IcaAnime *)(((struct Obj01673 *)p)->f184));
            ((struct Obj01673 *)p)->f184 = 0;
            p[0x19A] = 0;
            FLDMMDL_GetPos((const struct Actor *)((struct Obj01673 *)p)->f0, (struct VecFx32 *)&v);
            FLDMMDL_InitPosition((void *)(((struct Obj01673 *)p)->f0), (int *)(&v), FLDMMDL_GetDirDisp((void *)(((struct Obj01673 *)p)->f0)));
            if (gMmdlIcaReleaseMoveBitTable[p[0x199]] != 0) {
                FLDMMDL_ClearMoveBit((char *)(((struct Obj01673 *)p)->f0), 0x8000);
            }
        }
        FLDMMDL_CallDrawProc((void *)(((struct Obj01673 *)p)->f0));
    }
}
