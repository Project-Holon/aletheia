/*
 * function: FIELD_PLAYER_CORE_FormStepRestoreModel
 * address:  0x021A3EE0
 * packet:   pkt_ov021_021A3EE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetFormCode  0x021A3974  thumb  ov021
 *   FIELD_PLAYER_CORE_GetSex  0x021A398C  thumb  ov021
 *   FIELD_PLAYER_GetObjCodeOfFormCode  0x021A31A4  thumb  ov021
 *   FIELD_PLAYER_CORE_ChangeToObjCode  0x021A3D08  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x24];
    u32 mask;
    u8 pad28[4];
    u16 timer;
    u16 count;
    short step;
    u16 done;
} Obj021A3EE0;

u32 FIELD_PLAYER_CORE_GetFormCode(u8 *p);
u32 FIELD_PLAYER_CORE_GetSex(u8 *p);
int FIELD_PLAYER_GetObjCodeOfFormCode(int i, int v);
int FIELD_PLAYER_CORE_ChangeToObjCode(u8 *p, u32 v);

int FIELD_PLAYER_CORE_FormStepRestoreModel(Obj021A3EE0 *p)
{
    int a = FIELD_PLAYER_CORE_GetFormCode((u8 *)p);

    if (FIELD_PLAYER_CORE_ChangeToObjCode((u8 *)p, FIELD_PLAYER_GetObjCodeOfFormCode(FIELD_PLAYER_CORE_GetSex((u8 *)p), a)) != 1)
        p->step++;
    return 0;
}
