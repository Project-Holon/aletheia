/*
 * function: func_02193488
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
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_02193710  0x02193710  arm  ov009
 *   func_02189D78  0x02189D78  arm  ov009
 *   g_021A573C     0x021A573C  data
 *   g_021A5750     0x021A5750  data
 *   g_021A5788     0x021A5788  data
 *   g_021A57A0     0x021A57A0  data
 */

extern int GSISocketSelect(int theSocket, int *theReadFlag, int *theWriteFlag, int *theExceptFlag);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_02193710(int *connection, int result, int errorString);
extern int func_02189D78(int *connection, int a1, int a2);
extern char g_021A573C[];
extern char g_021A5750[];
extern char g_021A5788[];
extern char g_021A57A0[];

int func_02193488(int *connection, int sock, int *state)
{
    int e[2];
    int r;

    e[1] = 0;
    e[0] = 0;
    r = GSISocketSelect(sock, 0, &e[1], &e[0]);
    if (r == -1) {
        func_0217D254(1, 0, 1, (const char *)((int)g_021A573C));
        func_02193710(connection, 5, (int)g_021A5750);
        func_02189D78(connection, 3, 1);
        return 3;
    }
    if (r <= 0)
        goto zero;
    if (e[0] != 0) {
        func_0217D254(1, 0, 1, (const char *)((int)g_021A5788));
        *state = 4;
        return 0;
    }
    if (e[1] != 0) {
        func_0217D254(1, 0, 8, (const char *)((int)g_021A57A0));
        *state = 3;
        return 0;
    }
zero:
    *state = 0;
    return 0;
}
