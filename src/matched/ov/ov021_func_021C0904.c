/*
 * function: EVENT_RECOVERY_InitBalls
 * address:  0x021C0904
 * packet:   pkt_ov021_021C0904
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_G3D_MAPPER_GetBuildModel  0x0218DC6C  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_BUILDMODEL_CollectEntriesInRect  0x0218C584  thumb  ov021
 *   FIELD_BUILDMODEL_GetEntryWorldPos  0x0218C6D0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj02394.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern u32 FIELD_G3D_MAPPER_GetBuildModel(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *a, struct VecFx32 *pos);
extern u32 *FIELD_BUILDMODEL_CollectEntriesInRect(u32 a, int *rect, u32 n, int *cnt);
extern void FIELD_BUILDMODEL_GetEntryWorldPos(int *p, int b);
extern u32 func_020307B0(void *p);

void EVENT_RECOVERY_InitBalls(u8 *p, u32 a, u32 n)
{
    void *s;
    u32 w;
    u32 t;
    u32 *r;
    int pos[3];
    int rect[4];
    int cnt;

    s = GAMESYSTEM_GetFieldMap((void *)a);
    w = FIELDMAP_GetHeapId(s);
    t = FIELDMAP_GetG3dMapper(s);
    ((struct Obj02394 *)p)->f0 = w;
    p[0x14] = n;
    ((struct Obj02394 *)p)->f4 = s;
    p[0x15] = 0;
    ((struct Obj02394 *)p)->f18 = FIELD_G3D_MAPPER_GetBuildModel((u8 *)t);
    ((struct Obj02394 *)p)->f34 = 0;
    if (p[0x14] > 6) {
        p[0x14] = 6;
    }
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(((struct Obj02394 *)p)->f4), (struct VecFx32 *)pos);
    rect[0] = pos[2] - 0x50000;
    rect[1] = pos[2] + 0x50000;
    rect[2] = pos[0] - 0x50000;
    rect[3] = pos[0] + 0x50000;
    r = FIELD_BUILDMODEL_CollectEntriesInRect(((struct Obj02394 *)p)->f18, rect, 3, &cnt);
    if (r) {
        ((struct Obj02394 *)p)->f34 = *r;
        FIELD_BUILDMODEL_GetEntryWorldPos((int *)(*r), (int)(p + 8));
    }
    func_020307B0(r);
}
