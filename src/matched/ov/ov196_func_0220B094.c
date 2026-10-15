/*
 * function: B_APP_TOOL_ShowWindows
 * address:  0x0220B094
 * packet:   pkt_0220B094
 * region:   ov196
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   B_APP_TOOL_ShowWindow  0x0220B07C  thumb  ov196
 */
extern void B_APP_TOOL_ShowWindow(void **p);

void B_APP_TOOL_ShowWindows(char *p, unsigned char *q)
{
    int i = 0;
    for (;;) {
        unsigned char c = q[i];
        if (c == 0xff)
            break;
        B_APP_TOOL_ShowWindow((void **)(p + (c << 3)));
        i++;
    }
}
