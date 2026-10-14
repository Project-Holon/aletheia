/*
 * function: BTLV_INPUT_VisibilityTaskMain
 * address:  0x02204BAC
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_INPUT_VisibilityTaskMain   0x02204BAC  thumb
 *   BTLV_EFFECT_GetWorkPtr 0x021F8678 thumb ov094
 *   BTLV_EFFECT_SetVisibilityMode 0x021F8884 thumb ov094
 *   BTLV_INPUT_DeleteTask 0x0220687C thumb ov094

 *
 * lane O10 candidate
 */

extern void *BTLV_EFFECT_GetWorkPtr(void);
extern void BTLV_EFFECT_SetVisibilityMode(int a);
extern void BTLV_INPUT_DeleteTask(char *p, void *q);

void BTLV_INPUT_VisibilityTaskMain(int a, int *b)
{
    if (BTLV_EFFECT_GetWorkPtr() != 0) {
        BTLV_EFFECT_SetVisibilityMode(b[1]);
        BTLV_INPUT_DeleteTask((char *)b[0], (void *)a);
    }
}

