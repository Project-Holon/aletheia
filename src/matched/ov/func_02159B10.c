/*
 * function: SCRIPT_WORK_ReadWorkValue
 * address:  0x02159B10
 * packet:   pkt_02159B10
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Same three-argument submission as its neighbour, aimed at the second
 * overlay handler.
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData   0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork   0x0215A5F4  thumb  ov010
 *   VM_GetU16   0x02011330  thumb
 *   SCRIPT_WORK_GetWorkValue   0x0215901C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern unsigned int SCRIPT_WORK_GetWorkValue(void *a, void *b, unsigned int id);

unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1)
{
    void *v = SCRCMD_WORK_GetGameData(a1);

    return SCRIPT_WORK_GetWorkValue(SCRCMD_WORK_GetScriptWork(a1), v, VM_GetU16(a0));
}

