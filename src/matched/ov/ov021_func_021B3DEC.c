/*
 * function: SCRCMD_PROC_FLD_CreateShopActors
 * address:  0x021B3DEC
 * packet:   pkt_ov021_021B3DEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   d_021D96E0     0x021D96E0  data   ov021  a2
 *   d_021D96E8     0x021D96E8  data   ov021  a2
 *   d_021D96F0     0x021D96F0  data   ov021  a2
 *   d_021D96F8     0x021D96F8  data   ov021  a2
 *   d_021D9700     0x021D9700  data   ov021  a2
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00357.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u16 a, b, c; u8 d, e; } Rect;

struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *, unsigned int);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern const Rect d_021D96E0;
extern const Rect d_021D96E8;
extern const Rect d_021D96F0;
extern const Rect d_021D96F8;
extern const Rect d_021D9700;

void SCRCMD_PROC_FLD_CreateShopActors(char *w)
{
    ((struct Obj00357 *)w)->f1C0 = (int)CLACT_CreateActor((void *)((struct Obj00357 *)w)->f1BC, ((struct Obj00357 *)w)->f1D8, ((struct Obj00357 *)w)->f1D4,
                                        ((struct Obj00357 *)w)->f1DC, &d_021D96E0, 0, ((struct Obj00357 *)w)->f4);
    ((struct Obj00357 *)w)->f1C4 = (int)CLACT_CreateActor((void *)((struct Obj00357 *)w)->f1BC, ((struct Obj00357 *)w)->f1E4, ((struct Obj00357 *)w)->f1D4,
                                        ((struct Obj00357 *)w)->f1E8, &d_021D96E8, 0, ((struct Obj00357 *)w)->f4);
    ((struct Obj00357 *)w)->f1C8 = (int)CLACT_CreateActor((void *)((struct Obj00357 *)w)->f1BC, ((struct Obj00357 *)w)->f1E4, ((struct Obj00357 *)w)->f1D4,
                                        ((struct Obj00357 *)w)->f1E8, &d_021D96F0, 0, ((struct Obj00357 *)w)->f4);
    ((struct Obj00357 *)w)->f1CC = (int)CLACT_CreateActor((void *)((struct Obj00357 *)w)->f1BC, ((struct Obj00357 *)w)->f1E4, ((struct Obj00357 *)w)->f1D4,
                                        ((struct Obj00357 *)w)->f1E8, &d_021D96F8, 0, ((struct Obj00357 *)w)->f4);
    CLACT_SetActorAutoAnim((struct Obj *)((struct Obj00357 *)w)->f1CC, 1);
    ((struct Obj00357 *)w)->f1D0 = (int)CLACT_CreateActor((void *)((struct Obj00357 *)w)->f1BC, ((struct Obj00357 *)w)->f1F0, ((struct Obj00357 *)w)->f1EC,
                                        ((struct Obj00357 *)w)->f1F4, &d_021D9700, 0, ((struct Obj00357 *)w)->f4);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00357 *)w)->f1C4, 0);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00357 *)w)->f1C8, 0);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00357 *)w)->f1CC, 0);
}
