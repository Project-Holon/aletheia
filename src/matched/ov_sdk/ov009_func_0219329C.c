/*
 * function: func_0219329C
 * address:  0x0219329C
 * packet:   pkt_0219329C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * gpiCheckForError.  Every concrete byte reproduces (220 bytes).
 *
 * Promoted from MATCH by the recursive-unblocker lane: 0x020964E0 now has an
 * EXACT arm9 shard entry (pkt_020964E0) reproducing the argument-defaulting
 * thunk, so the atoi call at +0x54 resolves via `matched`.  Filed under a new
 * packet id (pkt_0219329C) so the promotion writes its own shard instead of
 * the ov009 lane's in-flight pkt_0219091C.
 *
 * Layout note that closed the old DIFF: the `\fatal\` branch's third
 * argument is written as a *double* boolean -- `int b = func_02094B20(...)
 * != 0;` then `func_02189D78(connection, 4, b != 0);`.  `_Bool` is not a
 * keyword in this C99 front end (CCERR), and folding the two tests into one
 * loses four instructions (12 bytes).
 *
 * Behaviour: guard on the 7-char prefix "\err\"; on a match read the code
 * from "\err\" via gpiValueForKey into a 0x10 stack buffer and atoi it into
 * iconnection+0x5b8; read the message from "\err\msg\" straight into the
 * connection's error string at +0 (and clear byte 0 if absent); on a fatal
 * request check for "\fatal\" and raise callback type 4 through func_02189D78.
 *
 * symbols:
 *   func_020949F4  0x020949F4  arm
 *   func_02193418  0x02193418  arm  ov009
 *   func_020964E0  0x020964E0  arm
 *   func_02094B20  0x02094B20  arm
 *   func_02189D78  0x02189D78  arm  ov009
 *   g_021A5718     0x021A5718  data
 *   g_021A5720     0x021A5720  data
 *   g_021A5728     0x021A5728  data
 *   g_021A5734     0x021A5734  data
 */

extern int func_020949F4(const char *s1, const char *s2, int n);
extern int func_02193418(const char *command, const char *key, char *value, int valueLen);
typedef unsigned int   u32;
extern int func_020964E0(u32 a0);
typedef unsigned char  u8;
extern u8 *func_02094B20(const u8 *s1, const u8 *s2);
extern int func_02189D78(int *connection, int a1, int a2);
extern char g_021A5718[];
extern char g_021A5720[];
extern char g_021A5728[];
extern char g_021A5734[];

int func_0219329C(int *connection, const char *input, int fatal)
{
    char value[0x10];
    int *ic = (int *)*connection;

    if (func_020949F4(input, g_021A5718, 7) != 0)
        goto fail;
    if (func_02193418(input, g_021A5720, value, 0x10))
        ic[0x5b8 / 4] = func_020964E0((u32)value);
    if (!func_02193418(input, g_021A5728, (char *)ic, 0x100))
        *(char *)ic = 0;
    if (fatal != 0) {
        int b = func_02094B20((const u8 *)input, (const u8 *)g_021A5734) != 0;
        func_02189D78(connection, 4, b != 0);
    }
    return 1;
fail:
    return 0;
}
