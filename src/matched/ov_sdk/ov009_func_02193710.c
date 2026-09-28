/*
 * function: func_02193710
 * address:  0x02193710
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * gpiSetError: copy the error string into the connection-owned buffer at
 * the head of the connection object and record the result word at +0x5b8.
 *
 * symbols:
 *   func_0219327C  0x0219327C  arm  ov009
 */

extern void func_0219327C(char *p, int b, int n);

void func_02193710(int *connection, int result, int errorString)
{
    char *iconnection = *(char **)connection;

    func_0219327C(iconnection, errorString, 0x100);
    *(int *)(iconnection + 0x5b8) = result;
}
