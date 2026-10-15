/*
 * function: gpiReadKeyAndValue
 * address:  0x0219359C
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * gpiReadKeyAndValue.  Faithful port of the public GameSpy gpiUtility.c body:
 * one running `buffer` pointer shared by both loops and a single reused `i`,
 * with `start` taken before the leading backslash is consumed.  The four
 * malformed cases each inline their own CallbackFatalError tail (gpiSetError
 * with result 1 and the "Parse Error." string pinned at 0x021A57B8, then
 * gpiCallErrorCallback with callback type 3 and return 3); they are not a shared
 * block.  The earlier DIFF was a register rotation caused by spelling the two
 * copies out of one pointer with separate key/value cursor locals; using the
 * public running-pointer form reproduces the original allocation (start in
 * lr, buffer/cursor in r1, c in r5 then r3, i in r6 then r5, value in ip).
 *
 * symbols:
 *   gpiSetError  0x02193710  arm  ov009
 *   gpiCallErrorCallback  0x02189D78  arm  ov009
 *   g_021A57B8     0x021A57B8  data
 */

extern void gpiSetError(int *connection, int result, int errorString);
extern int gpiCallErrorCallback(int *connection, int a1, int a2);
extern char g_021A57B8[];

int gpiReadKeyAndValue(int *connection, const char *buffer, int *index, char *key, char *value)
{
    int c;
    int i;
    char *start;

    buffer += *index;
    start = (char *)buffer;

    if (*buffer++ != '\\') {
        gpiSetError(connection, 1, (int)g_021A57B8);
        gpiCallErrorCallback(connection, 3, 1);
        return 3;
    }

    for (i = 0; (c = *buffer++) != '\\'; i++) {
        if (c == 0) {
            gpiSetError(connection, 1, (int)g_021A57B8);
            gpiCallErrorCallback(connection, 3, 1);
            return 3;
        }
        if (i == 0x1ff) {
            gpiSetError(connection, 1, (int)g_021A57B8);
            gpiCallErrorCallback(connection, 3, 1);
            return 3;
        }
        *key++ = (char)c;
    }
    *key = 0;

    for (i = 0; ((c = *buffer++) != '\\') && (c != 0); i++) {
        if (i == 0x1ff) {
            gpiSetError(connection, 1, (int)g_021A57B8);
            gpiCallErrorCallback(connection, 3, 1);
            return 3;
        }
        *value++ = (char)c;
    }
    *value = 0;

    *index += (int)(buffer - start - 1);
    return 0;
}
