/*
 * function: FIELD_EVENT_CHECK_CheckLedgeJump
 * address:  0x0218B408
 * packet:   pkt_ov021_0218B408
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetFormCode  0x021A3098  thumb
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb
 *   FIELD_PLAYER_ChooseMoveDirFromKeys  0x021A2FA4  thumb
 *   FIELD_PLAYER_GetPosInDir  0x021A3364  thumb
 *   MAP_ATTR_GetAt  0x021AB0D4  thumb
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb
 *   MAP_ATTR_IsLongHopEdge  0x021AB2E8  thumb
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb  ov010
 *   FIELD_EVENT_CHECK_IsLedgePathClear  0x0218B6F8  thumb
 *   FIELD_EVENT_CHECK_CreateLedgeJumpTask  0x0218B3DC  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07410.h"

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u32 FIELD_PLAYER_GetFormCode(u8 *p);
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern u16 FIELD_PLAYER_ChooseMoveDirFromKeys(u8 *p, u32 a1);
extern void FIELD_PLAYER_GetPosInDir(u32 *a, int b, int *out);
extern int MAP_ATTR_GetAt(void *a, void *b);
extern u16 MAP_ATTR_GetFlags(u32 attr);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern int MAP_ATTR_IsLongHopEdge(int a);
extern void FLDMMDL_MOVE_AddDirVector(int a, int *b, int c);
extern int FIELD_EVENT_CHECK_IsLedgePathClear(char *p, void *x);
extern int FIELD_EVENT_CHECK_CreateLedgeJumpTask(int unused, int a, int b, int c, int d);

int FIELD_EVENT_CHECK_CheckLedgeJump(char *p, void *a, void *x)
{
    void *cam;
    int r7;
    int t;
    int flag;
    int t2;
    void *id;
    int v;
    int buf[3];

    id = FIELDMAP_GetFieldPlayer(x);
    if (FIELD_PLAYER_GetFormCode(id) == 2) {
        cam = (void *)FIELDMAP_GetG3dMapper(x);
        r7 = FIELD_PLAYER_ChooseMoveDirFromKeys((u8 *)(*(int *)&((struct Obj07410 *)p)->f18), ((struct Obj07410 *)p)->f2C);
        if (r7 != 9) {
            FIELD_PLAYER_GetPosInDir(id, r7, buf);
            t = MAP_ATTR_GetAt(cam, buf);
            v = MAP_ATTR_GetFlags(t);
            t2 = MAP_ATTR_GetTerrainId(t);
            flag = 0;
            if (MAP_ATTR_IsLongHopEdge(t2) == 1) {
                FLDMMDL_MOVE_AddDirVector(r7, buf, 0x10000);
                v = MAP_ATTR_GetFlags(MAP_ATTR_GetAt(cam, buf));
                flag = 1;
            }
            if (FIELD_EVENT_CHECK_IsLedgePathClear(p, x) == 1 && !(v & 1) && !(v & 2))
                return FIELD_EVENT_CHECK_CreateLedgeJumpTask((int)p, (int)a, (int)x, r7, flag);
        }
    }
    return 0;
}
