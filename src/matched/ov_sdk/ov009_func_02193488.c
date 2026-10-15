/*
 * function: gpiCheckSocketConnect
 * address:  0x02193488
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * gpiCheckSocketConnect: probe the socket with GSISocketSelect.  -1 means the
 * select failed, a non-positive return leaves the state at 0, and otherwise
 * the two out-parameters decide between accepted (state 4) and rejected
 * (state 3).
 *
 * symbols:
 *   GSISocketSelect  0x0217ED64  arm  ov009
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   gpiSetError  0x02193710  arm  ov009
 *   gpiCallErrorCallback  0x02189D78  arm  ov009
 *   gGpiUtilityMsgErrorConnecting     0x021A573C  data
 *   gGpiUtilityMsgErrorChecking     0x021A5750  data
 *   gGpiUtilityMsgConnectionRejected     0x021A5788  data
 *   gGpiUtilityMsgConnectionAccepted     0x021A57A0  data
 */

extern int GSISocketSelect(int theSocket, int *theReadFlag, int *theWriteFlag, int *theExceptFlag);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern void gpiSetError(int *connection, int result, int errorString);
extern int gpiCallErrorCallback(int *connection, int a1, int a2);
extern char gGpiUtilityMsgErrorConnecting[];
extern char gGpiUtilityMsgErrorChecking[];
extern char gGpiUtilityMsgConnectionRejected[];
extern char gGpiUtilityMsgConnectionAccepted[];

int gpiCheckSocketConnect(int *connection, int sock, int *state)
{
    int e[2];
    int r;

    e[1] = 0;
    e[0] = 0;
    r = GSISocketSelect(sock, 0, &e[1], &e[0]);
    if (r == -1) {
        gsDebugFormat(1, 0, 1, (const char *)((int)gGpiUtilityMsgErrorConnecting));
        gpiSetError(connection, 5, (int)gGpiUtilityMsgErrorChecking);
        gpiCallErrorCallback(connection, 3, 1);
        return 3;
    }
    if (r <= 0)
        goto zero;
    if (e[0] != 0) {
        gsDebugFormat(1, 0, 1, (const char *)((int)gGpiUtilityMsgConnectionRejected));
        *state = 4;
        return 0;
    }
    if (e[1] != 0) {
        gsDebugFormat(1, 0, 8, (const char *)((int)gGpiUtilityMsgConnectionAccepted));
        *state = 3;
        return 0;
    }
zero:
    *state = 0;
    return 0;
}
