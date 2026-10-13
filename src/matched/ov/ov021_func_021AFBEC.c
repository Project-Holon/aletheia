/*
 * function: SCRCMD_BufferByteEntryCommon
 * address:  0x021AFBEC
 * packet:   pkt_ov021_021AFBEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 */

typedef unsigned char u8;

typedef struct {
    char pad[0x14];
    u8 *cur;
} Ctx;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRIPT_WORK_GetWordSet(void *p);

int SCRCMD_BufferByteEntryCommon(Ctx *a0, int a1, int (*fn)())
{
    u8 *p = a0->cur;
    int b = *p;
    int t;

    a0->cur = p + 1;
    t = (int)SCRIPT_WORK_ReadWorkValue(a0, (void *)a1);
    fn(SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork((void *)a1)), b, (u8)t);
    return 0;
}
