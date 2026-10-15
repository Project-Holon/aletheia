/*
 * function: FLDMMDL_SysWaitBlActResLoad
 * address:  0x0216CD88
 * packet:   pkt_0216CD88
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 48 compiled 46
 *
 * symbols:
 *   FLDMMDL_BLACT_IsReservePending  0x0219C630  thumb
 *   FLDMMDL_UpdateSysProc  0x0216CD64  thumb  ov010
 *   OS_WaitInterrupt  0x02087A3C  arm
 *   FLDMMDL_UpdateSysBlAct  0x0216CD78  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_BLACT_IsReservePending();
extern int FLDMMDL_UpdateSysProc(int a0);
extern int OS_WaitInterrupt();
extern int FLDMMDL_UpdateSysBlAct(int a0);

int FLDMMDL_SysWaitBlActResLoad(int a0)
{
    int a1;
    int t4;
    int t5;

t5 = a0 + 0;
    a0 = FLDMMDL_BLACT_IsReservePending(a0);
loc_0216CD90:
    if (a0 != 1) goto loc_0216CDB4;
loc_0216CD94:
t4 = 1;
loc_0216CD96:
a0 = t5 + 0;
    a0 = FLDMMDL_UpdateSysProc(a0);
loc_0216CD9C:
a0 = t4 + 0;
a1 = t4 + 0;
    a0 = OS_WaitInterrupt(a0, a1);
loc_0216CDA4:
a0 = t5 + 0;
    a0 = FLDMMDL_UpdateSysBlAct(a0);
loc_0216CDAA:
a0 = t5 + 0;
    a0 = FLDMMDL_BLACT_IsReservePending(a0);
loc_0216CDB0:
    if (a0 == 1) goto loc_0216CD96;
loc_0216CDB4:
    return a0;}
