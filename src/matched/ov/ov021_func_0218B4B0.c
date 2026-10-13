/*
 * function: FIELD_EVENT_CHECK_SearchGridFrontMmdl
 * address:  0x0218B4B0
 * packet:   pkt_ov021_0218B4B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reads the object's grid position, and when the tile attribute in front
 * allows it (MAP_ATTR_IsCameraStep) steps it one tile in its facing direction, then
 * moves the camera object there (FLDMMDL_SysSearchGridPosHeight).
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   FIELD_PLAYER_GetFrontGridPos  0x021A3460  thumb
 *   FLDMMDL_MOVE_GridToVector  0x02164294  thumb  ov010
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb
 *   MAP_ATTR_GetAt  0x021AB0D4  thumb
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb
 *   MAP_ATTR_IsCameraStep  0x021AB194  thumb
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_MOVE_AddDirGrid  0x02164240  thumb  ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb
 *   FLDMMDL_GetPosY  0x0216D8AC  thumb  ov010
 *   FLDMMDL_SysSearchGridPosHeight  0x0216DDDC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct FieldCtx {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    u16 f10;
    char pad12[0x06];
    void *f18;
    char pad1C[0x20];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
};

extern void *FIELD_PLAYER_GetMmdl(u8 *p);
typedef signed int     s32;
extern int FIELD_PLAYER_GetFrontGridPos(u32 a, u32 b, u32 c, u32 d);
extern void FLDMMDL_MOVE_GridToVector(int x, int y, int z, int *out);
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern int MAP_ATTR_GetAt(void *a, void *b);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern int MAP_ATTR_IsCameraStep(u16 id);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void FLDMMDL_MOVE_AddDirGrid(int dir, s16 *x, s16 *z, s16 amt);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern u32 FLDMMDL_GetPosY(void *p);
extern u8 *FLDMMDL_SysSearchGridPosHeight(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);

int FIELD_EVENT_CHECK_SearchGridFrontMmdl(struct FieldCtx *p, u8 *pos)
{
    void *obj = FIELD_PLAYER_GetMmdl(p->f18);
    s16 v[3];
    int xyz[3];
    void *cam;

    FIELD_PLAYER_GetFrontGridPos((u32)p->f18, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
    FLDMMDL_MOVE_GridToVector(v[2], v[1], v[0], xyz);
    if (MAP_ATTR_IsCameraStep(MAP_ATTR_GetTerrainId(MAP_ATTR_GetAt((void *)FIELDMAP_GetG3dMapper(pos), xyz))) == 1)
        FLDMMDL_MOVE_AddDirGrid(FLDMMDL_GetDirDisp(obj), &v[2], &v[0], 1);
    cam = FIELDMAP_GetMmdlSys(pos);
    return (int)FLDMMDL_SysSearchGridPosHeight((u32)cam, v[2], v[0], FLDMMDL_GetPosY(obj), 0x10000, 0);
}
