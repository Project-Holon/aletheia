/*
 * function: FIELDMAP_CTRL_NOGRID_WORK_MovePlayer
 * address:  0x021A6DA4
 * packet:   pkt_ov021_021A6DA4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   FIELD_PLAYER_SetupNogrid  0x021A3674  thumb
 */

typedef unsigned int u32;

extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
typedef unsigned char  u8;
extern void FIELD_PLAYER_SetupNogrid(u8 *p, u32 b, u32 c);

void FIELDMAP_CTRL_NOGRID_WORK_MovePlayer(u32 *a)
{
    u32 x = func_020362DC();
    u32 y = func_0203630C();
    FIELD_PLAYER_SetupNogrid((u8 *)(*a), x, y);
}
