/*
 * function: FIELD_PLAYER_CORE_FinishFormSlotChange
 * address:  0x021A3D6C
 * packet:   pkt_ov021_021A3D6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_CheckDrawProcReady  0x021A3B94  thumb  ov021
 *   FIELD_PLAYER_CORE_GetSex  0x021A398C  thumb  ov021
 *   FIELD_PLAYER_GetFormObjCode  0x021A3190  thumb  ov021
 *   FIELD_PLAYER_CORE_ChangeModel  0x021A3AD8  thumb  ov021
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
} Obj021A3D6C;

int FIELD_PLAYER_CORE_CheckDrawProcReady(u32 *p);
u32 FIELD_PLAYER_CORE_GetSex(u8 *p);
u16 FIELD_PLAYER_GetFormObjCode(int i, int j);
void FIELD_PLAYER_CORE_ChangeModel(u8 *p, int a);

int FIELD_PLAYER_CORE_FinishFormSlotChange(Obj021A3D6C *p, int a)
{
    if (FIELD_PLAYER_CORE_CheckDrawProcReady((u32 *)p) == 1) {
        p->count++;
        FIELD_PLAYER_CORE_ChangeModel((u8 *)p, FIELD_PLAYER_GetFormObjCode(FIELD_PLAYER_CORE_GetSex((u8 *)p), a));
        p->done = 1;
        return 1;
    }
    return 0;
}
