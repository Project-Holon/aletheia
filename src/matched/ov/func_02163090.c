/*
 * function: FLDMMDL_MOVE_IsMoveProcAllowed
 * address:  0x02163090
 * packet:   pkt_02163090
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_CheckMoveBitMove  0x0216DA5C  thumb  ov010
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   FLDMMDL_GetMoveCode  0x0216D5A0  thumb  ov010
 *   FLDMMDL_GetMoveBit  0x0216D564  thumb  ov010
 *   FLDMMDL_CheckStatusBitHeightGetOff  0x0216DB68  thumb  ov010
 *   FLDMMDL_CheckStatusBitAttrGetOff  0x0216DCB4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_CheckMoveBitMove(void *a0);
extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);
extern u16 FLDMMDL_GetMoveCode(void *p);
extern u32 FLDMMDL_GetMoveBit(void *p);
extern int FLDMMDL_CheckStatusBitHeightGetOff(void *a0);
extern int FLDMMDL_CheckStatusBitAttrGetOff(void *a0);

int FLDMMDL_MOVE_IsMoveProcAllowed(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
    a0 = FLDMMDL_CheckMoveBitMove((void *)a0);
loc_02163098:
    if (a0 != 0) goto loc_021630F0;
loc_0216309C:
a1 = 6;
a0 = t5 + 0;
a1 = a1 << 0xa;
    a0 = FLDMMDL_CheckMoveBit((void *)a0, a1);
loc_021630A6:
    if (a0 != 0) goto loc_021630AE;
loc_021630AA:
a0 = 1;
    return a0;
loc_021630AE:
a0 = t5 + 0;
    a0 = FLDMMDL_GetMoveCode((void *)a0);
loc_021630B4:
    if (a0 != 0x32) goto loc_021630BC;
loc_021630B8:
a0 = 1;
    return a0;
loc_021630BC:
a0 = t5 + 0;
    a0 = FLDMMDL_GetMoveBit((void *)a0);
loc_021630C2:
t4 = a0 + 0;
a0 = 1;
a0 = a0 << 0xc;
    if ((a0 & t4) == 0) goto loc_021630DA;
loc_021630CC:
a0 = t5 + 0;
    a0 = FLDMMDL_CheckStatusBitHeightGetOff((void *)a0);
loc_021630D2:
    if (a0 != 0) goto loc_021630DA;
loc_021630D6:
a0 = 0;
    return a0;
loc_021630DA:
a0 = 2;
a0 = a0 << 0xa;
    if ((a0 & t4) == 0) goto loc_021630F0;
loc_021630E2:
a0 = t5 + 0;
    a0 = FLDMMDL_CheckStatusBitAttrGetOff((void *)a0);
loc_021630E8:
    if (a0 != 0) goto loc_021630F0;
loc_021630EC:
a0 = 0;
    return a0;
loc_021630F0:
a0 = 1;
    return a0;}
