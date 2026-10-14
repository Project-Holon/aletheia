/*
 * function: BTLV_INPUT_RegisterTask
 * address:  0x0220684C
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_INPUT_RegisterTask   0x0220684C  thumb
 *   BTLV_INPUT_AllocTaskSlot 0x022068C4 thumb ov094

 *
 * lane O10 candidate
 */

extern int BTLV_INPUT_AllocTaskSlot(char *p);

void BTLV_INPUT_RegisterTask(char *p, int a, int b)
{
    int i = BTLV_INPUT_AllocTaskSlot(p);

    *(int *)(p + i * 4 + 8) = a;
    *(int *)(p + i * 4 + 0x28) = b;
}

