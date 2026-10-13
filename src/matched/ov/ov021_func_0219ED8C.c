/*
 * function: FLDMMDL_RAIL_ShuttleInitBody
 * address:  0x0219ED8C
 * packet:   pkt_ov021_0219ED8C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_RAIL_InitMoveWork  0x0219E968  thumb  ov021
 *   FLDMMDL_RAIL_GetNextLocation  0x0219E2F4  thumb  ov021
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct {
    u16 f0;
    u16 f2;
    s16 f4;
    u16 f6;
} Pos;

extern void *FLDMMDL_RAIL_InitMoveWork(u32 a, u32 size);
extern void FLDMMDL_RAIL_GetNextLocation(void *o, void *out);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void FLDMMDL_OffMoveBitMove(u8 *p);

void FLDMMDL_RAIL_ShuttleInitBody(u32 a)
{
    u8 *q = FLDMMDL_RAIL_InitMoveWork(a, 16);
    Pos pos;
    FLDMMDL_RAIL_GetNextLocation((void *)a, &pos);
    q[0xc] = 0;
    q[0xd] = 0;
    q[0xf] = pos.f6;
    q[0xe] = pos.f4;
    FLDMMDL_SetDrawStatus((void *)a, 0);
    FLDMMDL_OffMoveBitMove((u8 *)a);
}
