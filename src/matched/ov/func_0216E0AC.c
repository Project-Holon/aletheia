/*
 * function: FLDMMDL_ChangeHeader
 * address:  0x0216E0AC
 * packet:   pkt_0216E0AC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_CallMoveDeleteProc  0x0216D71C  thumb  ov010
 *   FLDMMDL_SetHeaderParams  0x0216CFC4  thumb  ov010
 *   FLDMMDL_SetHeaderPos  0x0216D02C  thumb  ov010
 *   FLDMMDL_InitMoveProcList  0x0216D230  thumb  ov010
 *   FLDMMDL_InitMove  0x0216D268  thumb  ov010
 *   FLDMMDL_SetupRailPosFromHeader  0x0216D0E8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *FLDMMDL_GetMmdlSys(void *a0);
extern void FLDMMDL_CallMoveDeleteProc(void *a0);
extern int FLDMMDL_SetHeaderParams(int a0, int a1);
extern void FLDMMDL_SetHeaderPos(int a, u8 *p);
extern int FLDMMDL_InitMoveProcList(int a0);
extern int FLDMMDL_InitMove(int a0, int a1);
extern int FLDMMDL_SetupRailPosFromHeader();

void FLDMMDL_ChangeHeader(void *a0, void *a1)
{
    void *t4;
    void *t5;
    int t6;

t5 = a0;
t4 = a1;
    t6 = (int)FLDMMDL_GetMmdlSys(a0);
loc_0216E0B6:
    FLDMMDL_CallMoveDeleteProc(t5);
loc_0216E0BE:
    FLDMMDL_SetHeaderParams((int)t5, (int)t4);
loc_0216E0C6:
    FLDMMDL_SetHeaderPos((int)t5, t4);
loc_0216E0CE:
    FLDMMDL_InitMoveProcList((int)t5);
loc_0216E0D4:
    FLDMMDL_InitMove(t6, (int)t5);
loc_0216E0DC:
    FLDMMDL_SetupRailPosFromHeader(t5, t4, 0);
loc_0216E0E6:
    return;}
