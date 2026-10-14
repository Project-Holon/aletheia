/*
 * function: BTLV_INPUT_DeleteAllTasks
 * address:  0x022068E8
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_INPUT_DeleteAllTasks   0x022068E8  thumb
 *   BTLV_INPUT_DeleteTask 0x0220687C thumb ov094

 *
 * lane O10 candidate
 */

extern void BTLV_INPUT_DeleteTask(char *p, void *q);

void BTLV_INPUT_DeleteAllTasks(char *p)
{
    int i;

    for (i = 0; i < 8; i++) {
        int v = *(int *)(p + 8 + i * 4);

        if (v != 0)
            BTLV_INPUT_DeleteTask(p, (void *)v);
    }
}

