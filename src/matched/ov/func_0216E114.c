/*
 * function: FLDMMDL_InitDraw
 * address:  0x0216E114
 * packet:   pkt_0216E114
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 76 compiled 74
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysCheckDrawInit  0x0216D948  thumb  ov010
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   FLDMMDL_MOVE_UpdateHeight  0x02164010  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_CheckMoveBitDrawInitComp  0x0216DAA0  thumb  ov010
 *   FLDMMDL_SetDrawProcList  0x0216E160  thumb  ov010
 *   FLDMMDL_CallDrawInitProc  0x0216D744  thumb  ov010
 *   FLDMMDL_OnMoveBitDrawInitComp  0x0216DA88  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *FLDMMDL_GetMmdlSys(void *a0);
extern int FLDMMDL_SysCheckDrawInit(int a0);
extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);
extern int FLDMMDL_MOVE_UpdateHeight(int a);
extern int FLDMMDL_SetDrawStatus();
extern int FLDMMDL_CheckMoveBitDrawInitComp(void *a0);
extern int FLDMMDL_SetDrawProcList(int a0);
extern int FLDMMDL_CallDrawInitProc();
extern int FLDMMDL_OnMoveBitDrawInitComp();

int FLDMMDL_InitDraw(int a0)
{
    int a1;
    int t4;

t4 = a0 + 0;
    a0 = (int)FLDMMDL_GetMmdlSys((void *)a0);
loc_0216E11C:
    a0 = FLDMMDL_SysCheckDrawInit(a0);
loc_0216E120:
    if (a0 == 0) goto loc_0216E15C;
loc_0216E124:
a1 = 1;
a0 = t4 + 0;
a1 = a1 << 0xc;
    a0 = FLDMMDL_CheckMoveBit((void *)a0, a1);
loc_0216E12E:
    if (a0 == 0) goto loc_0216E138;
loc_0216E132:
a0 = t4 + 0;
    a0 = FLDMMDL_MOVE_UpdateHeight(a0);
loc_0216E138:
a0 = t4 + 0;
a1 = 0;
    a0 = FLDMMDL_SetDrawStatus(a0, a1);
loc_0216E140:
a0 = t4 + 0;
    a0 = FLDMMDL_CheckMoveBitDrawInitComp((void *)a0);
loc_0216E146:
    if (a0 != 0) goto loc_0216E15C;
loc_0216E14A:
a0 = t4 + 0;
    a0 = FLDMMDL_SetDrawProcList(a0);
loc_0216E150:
a0 = t4 + 0;
    a0 = FLDMMDL_CallDrawInitProc(a0);
loc_0216E156:
a0 = t4 + 0;
    a0 = FLDMMDL_OnMoveBitDrawInitComp(a0);
loc_0216E15C:
    return a0;}
