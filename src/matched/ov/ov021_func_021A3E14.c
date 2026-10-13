/*
 * function: FIELD_PLAYER_CORE_FormStepCycle
 * address:  0x021A3E14
 * packet:   pkt_ov021_021A3E14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetSex  0x021A398C  thumb  ov021
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FIELD_PLAYER_CORE_SetFormCode  0x021A3980  thumb  ov021
 *   FIELD_PLAYER_CORE_PostZoneBgmChange  0x021A4114  thumb  ov021
 *   FIELD_PLAYER_CORE_ChangeToFormSlot  0x021A3D50  thumb  ov021
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
} Obj021A3E14;

u32 FIELD_PLAYER_CORE_GetSex(u8 *p);
void *FIELD_PLAYER_CORE_GetMmdl(u8 *p);
void FIELD_PLAYER_CORE_SetFormCode(u8 *p, u32 a1);
void FIELD_PLAYER_CORE_PostZoneBgmChange(u32 *p);
int FIELD_PLAYER_CORE_ChangeToFormSlot(u32 a, u32 b);

int FIELD_PLAYER_CORE_FormStepCycle(Obj021A3E14 *p)
{
    FIELD_PLAYER_CORE_GetSex((u8 *)p);
    FIELD_PLAYER_CORE_GetMmdl((u8 *)p);
    FIELD_PLAYER_CORE_SetFormCode((u8 *)p, 1);
    FIELD_PLAYER_CORE_PostZoneBgmChange((u32 *)p);
    if (FIELD_PLAYER_CORE_ChangeToFormSlot((u32)p, 1) != 1)
        p->step++;
    return 0;
}
