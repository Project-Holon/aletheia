/*
 * function: func_0219329C
 * address:  0x0219329C
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * gpiCheckForError.  Every concrete byte reproduces (220 bytes); the one
 * unresolved site is the atoi call at +0x54 to 0x020964E0, an unlabelled
 * argument-defaulting thunk (`ldr ip,[pc,#8]; mov r1,#0; mov r2,#0xa;
 * bx ip` -> 0x02095F40).  It has no func_ label, so neither `label` nor
 * `sole-ref/code` can attest the site, and the nearest EXACT* entry
 * (func_020963F8, pkt_02095AA4) stops before it.  Witness class: label /
 * sole-ref/code; promotes to EXACT when 0x020964E0 is labelled.
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
extern int func_020964E0(const char *s);
extern int func_02094B20(const char *s1, const char *s2);
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
        ic[0x5b8 / 4] = func_020964E0(value);
    if (!func_02193418(input, g_021A5728, (char *)ic, 0x100))
        *(char *)ic = 0;
    if (fatal != 0) {
        int b = func_02094B20(input, g_021A5734) != 0;
        func_02189D78(connection, 4, b != 0);
    }
    return 1;
fail:
    return 0;
}
