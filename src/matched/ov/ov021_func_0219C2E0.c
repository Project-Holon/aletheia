/*
 * function: FLDMMDL_MOVE_GetWallWalkDir
 * address:  0x0219C2E0
 * packet:   pkt_ov021_0219C2E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_MOVE_IsWallNearA  0x0219C298  thumb  ov021
 *   FLDMMDL_MOVE_IsWallNearB  0x0219C2BC  thumb  ov021
 *   gWallWalkRedirectDir  0x021D53F4  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FLDMMDL_MOVE_IsWallNearA(u32 a, int b, int c);
extern int FLDMMDL_MOVE_IsWallNearB(u32 a, int b, int c);
extern int gWallWalkRedirectDir[][2];

int FLDMMDL_MOVE_GetWallWalkDir(u32 a, int b, int c)
{
    if (FLDMMDL_MOVE_IsWallNearA(a, b, c) == 0) {
        if (FLDMMDL_MOVE_IsWallNearB(a, b, c) == 0) {
            return 9;
        }
        b = gWallWalkRedirectDir[b][c];
    }
    return b;
}
