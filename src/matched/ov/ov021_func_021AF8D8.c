/*
 * function: SCRCMD_BufferSpeciesNameCommon
 * address:  0x021AF8D8
 * packet:   pkt_ov021_021AF8D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x14];
    u8 *cur;
} Script;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);

int SCRCMD_BufferSpeciesNameCommon(Script *a, u32 b, void (*fn)(u32, u32, u32))
{
    u32 x = (u32)SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork((void *)b));
    u8 *p = a->cur;
    u32 v = *p;
    a->cur = p + 1;
    fn(x, v, SCRIPT_WORK_ReadWorkValue(a, (void *)b));
    return 0;
}
