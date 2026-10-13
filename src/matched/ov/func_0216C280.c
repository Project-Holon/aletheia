/*
 * function: NAMEIN_SETUP_SyncObjHeightToAnim
 * address:  0x0216C280
 * packet:   pkt_0216C280
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * unblocked: FLD_EXP_OBJ_GetModelStatus (ov021, unlabelled leaf) matched bottom-up and
 *           filed as pkt_021BE480; the `ov021` token resolves the +0x18
 *           call as `matched, overlay`.  FIELDMAP_GetExpObj was already matched.
 *
 * Asks the arm9 side for the slot's descriptor, sizes it through the
 * overlay helper and copies the second word of the local into it.
 *
 * symbols:
 *   ICA_ANIME_GetTranslate   0x02011610  thumb
 *   FIELDMAP_GetExpObj   0x02188D2C  thumb
 *   FLD_EXP_OBJ_GetModelStatus   0x021BE480  thumb  ov021
 */
#include "../include/Obj01029.h"
#include "../include/Obj17767.h"
#include "../include/Obj17768.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct IcaAnime;
struct Rec12;
extern u32 ICA_ANIME_GetTranslate(struct IcaAnime *, struct Rec12 *);
extern void *FIELDMAP_GetExpObj(void *);
extern int FLD_EXP_OBJ_GetModelStatus(char *p, unsigned i, int j);

void *NAMEIN_SETUP_SyncObjHeightToAnim(void *p)
{
    char v[12];
    void *q;

    ICA_ANIME_GetTranslate(((struct Obj01029 *)p)->f10, (struct Rec12 *)v);
    q = (void *)FLD_EXP_OBJ_GetModelStatus(FIELDMAP_GetExpObj(((struct Obj01029 *)p)->f8), 0, 0);
    ((struct Obj17768 *)q)->f4 = ((struct Obj17767 *)v)->f4;

    return q;
}

