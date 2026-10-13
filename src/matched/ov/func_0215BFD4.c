/*
 * function: SCRCMD_PROC_GetRelearnableMoveCount
 * address:  0x0215BFD4
 * packet:   pkt_0215BFD4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SCRCMD_PROC_GetPartyMember  0x0215B4AC  thumb  ov010
 *   WAZA_OSHIE_CreateMoveList  0x0216F948  thumb  ov010
 *   WAZA_OSHIE_IsListEntryValid  0x0216FAA0  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern int SCRCMD_PROC_GetPartyMember(void *a0, u32 a1, void **a2);
extern u16 *WAZA_OSHIE_CreateMoveList(void *mon, u32 heap);
extern int WAZA_OSHIE_IsListEntryValid(u16 *p);
extern u32 func_020307B0(void *p);

int SCRCMD_PROC_GetRelearnableMoveCount(int a0, int a1, int a2)
{
    int v0;
    int t5;
    int t6;
    int t7;
    void *buf;
    u16 *q;
t6 = a0 + 0;
t5 = a1 + 0;
    q = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0215BFDE:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = (int)SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
loc_0215BFE8:
t6 = a0 + 0;
a0 = t5 + 0;
    a0 = SCRCMD_WORK_GetHeapId((void *)a0);
loc_0215BFF0:
t7 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
a2 = (int)&v0;
    a0 = SCRCMD_PROC_GetPartyMember((void *)a0, a1, (void **)a2);
loc_0215BFFC:
    if (a0 != 1) goto loc_0215C016;
loc_0215C000:
    a0 = v0;
a1 = t7 + 0;
    buf = WAZA_OSHIE_CreateMoveList((void *)a0, a1);
loc_0215C008:
    a0 = WAZA_OSHIE_IsListEntryValid(buf);
loc_0215C00E:
*q = a0;
    a0 = func_020307B0(buf);
loc_0215C016:
a0 = 0;
    return a0;
}
