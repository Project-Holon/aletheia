/*
 * function: SCRCMD_WORK_CmdGetMsgDataId
 * address:  0x0215AADC
 * packet:   pkt_0215AADC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetMsgDataId  0x0215A610  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u16 SCRCMD_WORK_GetMsgDataId(void *p);

int SCRCMD_WORK_CmdGetMsgDataId(int a0, int a1)
{
    int t5;
    u16 *q;

t5 = a1 + 0;
    q = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0215AAE4:
a0 = t5 + 0;
    a0 = SCRCMD_WORK_GetMsgDataId((void *)a0);
loc_0215AAEC:
*q = a0;
a0 = 0;
    return a0;}
