/*
 * function: BTLV_INPUT_CursorActorTaskMain
 * address:  0x022047CC
 * packet:   pkt_ov094_022047CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_INPUT_DeleteTask  0x0220687C  thumb  ov094
 *   CLACT_IsActorAnimActive  0x0204B98C  arm  arm9
 */
typedef unsigned int   u32;
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void BTLV_INPUT_DeleteTask(char *p, void *q);

void BTLV_INPUT_CursorActorTaskMain(void *a, void **s)
{
    int i;
    for (i = 0; i < 6; i++) {
        if (s[i + 2] != 0 && CLACT_IsActorAnimActive(s[i + 2]) != 0)
            return;
    }
    BTLV_INPUT_DeleteTask(s[0], a);
}
