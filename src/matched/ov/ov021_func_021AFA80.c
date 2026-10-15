/*
 * function: SCRCMD_BufferNumber
 * address:  0x021AFA80
 * packet:   pkt_ov021_021AFA80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
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
struct WordSet;
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);

int SCRCMD_BufferNumber(Script *a, u32 b)
{
    u32 x = (u32)SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork((void *)b));
    u8 *p = a->cur;
    u32 v = *p;
    u32 e, f;
    a->cur = p + 1;
    e = SCRIPT_WORK_ReadWorkValue(a, (void *)b);
    f = SCRIPT_WORK_ReadWorkValue(a, (void *)b);
    WORDSET_SetSlotNumber((struct WordSet *)x, v, e, f, 0, 1);
    return 0;
}
