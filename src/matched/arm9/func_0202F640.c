/*
 * function: SAVE_EVENT_AdvanceStage
 * address:  0x0202F640
 * packet:   pkt_0202F498
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The two trailing pool words (0x753B / 0x753D, bare literals with no
 * relocation) are part of the compiled body, so the compared output is 72
 * bytes against the worklist's 62 code bytes; the listing extent runs to the
 * end of the packet.  All four call sites resolve on `label`.
 *
 * symbols:
 *   POKE_TOOL_SetBoxValue  0x02017E64  thumb
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb
 *   SAVE_EVENT_CheckStage  0x0202F498  thumb
 */

typedef unsigned int u32;

struct Sav;
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern int SAVE_EVENT_CheckStage(void *a0, int a1);
extern void POKE_TOOL_SetBoxValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);

void SAVE_EVENT_AdvanceStage(u32 a, u32 b)
{
    u32 r = POKE_TOOL_DecodeBoxParam((struct Sav *)a);

    if (SAVE_EVENT_CheckStage((void *)a, b) == 1) {
        switch (b) {
        case 0:
            POKE_TOOL_SetBoxValue((void *)a, 0x96, 0x753B);
            break;
        case 2:
            POKE_TOOL_SetBoxValue((void *)a, 0x96, 0x753D);
            break;
        }
    }
    POKE_TOOL_EncodeBoxParam((struct Sav *)a, r);
}
