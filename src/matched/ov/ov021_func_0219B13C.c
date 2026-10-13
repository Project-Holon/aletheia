/*
 * function: FLDMMDL_MOVECODE_GetSightDirToPlayer
 * address:  0x0219B13C
 * packet:   pkt_ov021_0219B13C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetEventType  0x0216D5A8  thumb  ov010
 *   FLDMMDL_MOVECODE_IsPlayerWalking  0x0219B074  thumb  ov021
 *   FLDMMDL_GetMoveCode  0x0216D5A0  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysSearchPlayer  0x0216DEE0  thumb  ov010
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_GetParam  0x0216D63C  thumb  ov010
 *   FLDMMDL_MOVE_GetDirFromPoints  0x021642B4  thumb  ov010
 *   gMmdlSightMoveCodes  0x021D4FEC  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u16 FLDMMDL_GetEventType(u8 *p);
extern int FLDMMDL_MOVECODE_IsPlayerWalking(int a);
extern u16 FLDMMDL_GetMoveCode(void *p);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern void *FLDMMDL_SysSearchPlayer(void *a0);
extern int FLDMMDL_GetGridNowY(void *p);
extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);
extern int FLDMMDL_GetParam(char *a0, int a1);
extern u16 FLDMMDL_MOVE_GetDirFromPoints(int x0, int y0, int x1, int y1);
extern u32 gMmdlSightMoveCodes[];

int FLDMMDL_MOVECODE_GetSightDirToPlayer(u32 a)
{
    int k;
    u32 v;
    u32 e;
    int i;
    u32 o;
    int ox, oy, ax, ay, r;
    int x0, x1, y0, y1;

    k = FLDMMDL_GetEventType((u8 *)a);
    if (k != 1 && k != 2) {
        return 9;
    }
    if (FLDMMDL_MOVECODE_IsPlayerWalking(a) == 0) {
        return 9;
    }
    i = 0;
    v = FLDMMDL_GetMoveCode((void *)a);
    do {
        e = gMmdlSightMoveCodes[i++];
    } while (e != v && e != 0xFF);
    if (v != e) {
        return 9;
    }
    o = (u32)FLDMMDL_SysSearchPlayer(FLDMMDL_GetMmdlSys((void *)a));
    if (o == 0) {
        return 9;
    }
    if (FLDMMDL_GetGridNowY((void *)o) != FLDMMDL_GetGridNowY((void *)a)) {
        return 9;
    }
    ox = FLDMMDL_GetGridNowX((void *)o);
    oy = FLDMMDL_GetGridNowZ((void *)o);
    r = FLDMMDL_GetParam((char *)a, 0);
    ax = FLDMMDL_GetGridNowX((void *)a);
    ay = FLDMMDL_GetGridNowZ((void *)a);
    x0 = ax - r;
    x1 = ax + r;
    y0 = ay - r;
    y1 = ay + r;
    if (y0 <= oy && y1 >= oy && x0 <= ox && x1 >= ox) {
        return FLDMMDL_MOVE_GetDirFromPoints(ax, ay, ox, oy);
    }
    return 9;
}
