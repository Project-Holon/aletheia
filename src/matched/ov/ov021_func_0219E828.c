/*
 * function: FLDMMDL_RAIL_StayInit
 * address: 0x0219E828
 * packet: pkt_ov021_0219E828
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/fldmmdl_blact_p10.c and filed here.
 *
 * symbols:
 *   FLDMMDL_RAIL_InitMoveWork 0x0219E968 thumb
 */

typedef unsigned int   u32;
void *FLDMMDL_RAIL_StayInit(u32 a);
void *FLDMMDL_RAIL_InitMoveWork(u32 a, u32 size);

void *FLDMMDL_RAIL_StayInit(u32 a)
{
    return FLDMMDL_RAIL_InitMoveWork(a, 0xc);
}
