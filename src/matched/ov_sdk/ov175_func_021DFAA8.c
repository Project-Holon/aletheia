/*
 * function: scSetSessionId
 * address:  0x021DFAA8
 * packet:   pkt_021DFAA8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sciInterfaceSetSessionId  0x021DF928  arm
 *
 * Fire-and-forget wrapper: kick 0x021DF928 and report success.
 */

extern void sciInterfaceSetSessionId(char *obj, int v);

int scSetSessionId(char *a, int b)
{
    sciInterfaceSetSessionId(a, b);
    return 0;
}

