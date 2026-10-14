/*
 * function: ZUKAN_LIST_ProcMain
 * address:  0x021BC274
 * packet:   pkt_021BC274
 * region:   ov209
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_LIST_RunState 0x021BCC58 thumb
 */

extern int ZUKAN_LIST_RunState(char *p);

int ZUKAN_LIST_ProcMain(int a, int b, int c, int d)
{
    if (ZUKAN_LIST_RunState((char *)d) == 0)
        return 1;
    return 0;
}