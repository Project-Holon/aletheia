/*
 * function: FLDMMDL_ChangeMoveCode
 * address:  0x0216E0E8
 * packet:   pkt_0216E0E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_CallMoveDeleteProc  0x0216D71C  thumb  ov010
 *   FLDMMDL_SetMoveCode  0x0216D59C  thumb  ov010
 *   FLDMMDL_InitMoveProcList  0x0216D230  thumb  ov010
 *   FLDMMDL_InitMove  0x0216D268  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *FLDMMDL_GetMmdlSys(void *a0);
extern int FLDMMDL_CallMoveDeleteProc();
extern int FLDMMDL_SetMoveCode();
extern int FLDMMDL_InitMoveProcList(int a0);
extern int FLDMMDL_InitMove(int a0, int a1);

int FLDMMDL_ChangeMoveCode(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = (int)FLDMMDL_GetMmdlSys((void *)a0);
loc_0216E0F2:
t6 = a0 + 0;
a0 = t5 + 0;
    a0 = FLDMMDL_CallMoveDeleteProc(a0);
loc_0216E0FA:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_SetMoveCode(a0, a1);
loc_0216E102:
a0 = t5 + 0;
    a0 = FLDMMDL_InitMoveProcList(a0);
loc_0216E108:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = FLDMMDL_InitMove(a0, a1);
loc_0216E110:
    return a0;}
