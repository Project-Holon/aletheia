/*
 * function: FLDMMDL_RAIL_WanderInit
 * address:  0x0219EBA0
 * packet:   pkt_ov021_0219EBA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
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
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    u8 pad[0xc];
    u8 lo : 4;
    u8 hi : 4;
    u8 z;
    u8 c;
    u8 d;
} E;

typedef struct {
    u16 a;
    u16 pad;
    s16 c;
    u16 d;
} S;

extern void *FLDMMDL_RAIL_InitMoveWork(u32 a, u32 size);
extern void FLDMMDL_RAIL_GetNextLocation(void *o, void *out);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void FLDMMDL_OffMoveBitMove(u8 *p);

void FLDMMDL_RAIL_WanderInit(u32 o, u32 k)
{
    E *e;
    S s;

    e = FLDMMDL_RAIL_InitMoveWork(o, 0x10);
    FLDMMDL_RAIL_GetNextLocation((void *)o, &s);
    e->lo = 0;
    e->z = 0;
    e->hi = k;
    e->d = s.d;
    e->c = s.c;
    FLDMMDL_SetDrawStatus((void *)o, 0);
    FLDMMDL_OffMoveBitMove((u8 *)o);
}
