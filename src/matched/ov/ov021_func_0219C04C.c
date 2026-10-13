/*
 * function: FLDMMDL_MOVE_FaceDirResolvePlayerDir
 * address:  0x0219C04C
 * packet:   pkt_ov021_0219C04C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysSearchPlayer  0x0216DEE0  thumb  ov010
 *   FLDMMDL_GetDirMove  0x0216D608  thumb  ov010
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb  ov010
 *   FLDMMDL_OffMoveBitMoveEnd  0x0216DA7C  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern void *FLDMMDL_SysSearchPlayer(void *a0);
extern u16 FLDMMDL_GetDirMove(void *p);
extern void FLDMMDL_OffMoveBitMove(u8 *p);
extern void FLDMMDL_OffMoveBitMoveEnd(u8 *p);

int FLDMMDL_MOVE_FaceDirResolvePlayerDir(u32 a, s8 *s)
{
    u32 o;
    if (s[1] == 9) {
        o = (u32)FLDMMDL_SysSearchPlayer(FLDMMDL_GetMmdlSys((void *)a));
        if (o != 0) {
            s[1] = FLDMMDL_GetDirMove((void *)o);
        }
    }
    FLDMMDL_OffMoveBitMove((u8 *)a);
    FLDMMDL_OffMoveBitMoveEnd((u8 *)a);
    s[0] = 3;
    return 1;
}
