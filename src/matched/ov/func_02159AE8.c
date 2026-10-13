/*
 * function: SCRIPT_WORK_ReadWorkPointer
 * address:  0x02159AE8
 * packet:   pkt_02159AE8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two record lookups on the second argument and a classification of the
 * first, submitted as three arguments.
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData   0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork   0x0215A5F4  thumb  ov010
 *   VM_GetU16   0x02011330  thumb
 *   SCRIPT_WORK_GetWorkPtr   0x02158FE0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern u16 *SCRIPT_WORK_GetWorkPtr(void *, void *, unsigned int);

u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1)
{
    void *v = SCRCMD_WORK_GetGameData(a1);

    return SCRIPT_WORK_GetWorkPtr(SCRCMD_WORK_GetScriptWork(a1), v, VM_GetU16(a0));
}

