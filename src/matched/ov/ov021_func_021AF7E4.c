/*
 * function: SCRCMD_BufferItemNameWithCount
 * address:  0x021AF7E4
 * packet:   pkt_ov021_021AF7E4
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
 *   WORDSET_SetSlotFromMsg118  0x0201EF5C  thumb
 *   WORDSET_SetSlotFromMsg117  0x0201EF4C  thumb
 *   WORDSET_SetSlotFromMsg36  0x0201EF40  thumb
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
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern void WORDSET_SetSlotFromMsg118(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_SetSlotFromMsg117(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_SetSlotFromMsg36(struct WordSet *p, u32 i, u32 v);

void SCRCMD_BufferItemNameWithCount(Script *a, u32 b)
{
    u32 x = (u32)SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork((void *)b));
    u8 *p = a->cur;
    u32 v = *p;
    u32 y, n, flag;
    u8 *q;
    a->cur = p + 1;
    y = SCRIPT_WORK_ReadWorkValue(a, (void *)b);
    n = SCRIPT_WORK_ReadWorkValue(a, (void *)b);
    q = a->cur;
    flag = *q;
    a->cur = q + 1;
    if (n > 1) {
        WORDSET_SetSlotFromMsg118((struct WordSet *)x, v, y);
    } else if (flag != 0) {
        WORDSET_SetSlotFromMsg117((struct WordSet *)x, v, y);
    } else {
        WORDSET_SetSlotFromMsg36((struct WordSet *)x, v, y);
    }
}
