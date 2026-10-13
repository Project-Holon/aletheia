/*
 * function: FLDMMDL_MOVE_WallWalkStop
 * address:  0x0219C13C
 * packet:   pkt_ov021_0219C13C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void FLDMMDL_OffMoveBitMove(u8 *p);

int FLDMMDL_MOVE_WallWalkStop(u32 a, u8 *s)
{
    FLDMMDL_OffMoveBitMove((u8 *)a);
    s[0]++;
    return 1;
}
