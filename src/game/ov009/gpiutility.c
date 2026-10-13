/*
 * file:     gpiutility.c
 * unit:     yes
 * function: func_0219327C, func_0219329C, func_02193378, func_02193418, func_02193488, func_0219359C, func_02193710, func_02193734, func_02193748
 * address:  0x0219327C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020949F4  0x020949F4  arm
 *   func_020964E0  0x020964E0  arm
 *   func_02094B20  0x02094B20  arm
 *   func_02189D78  0x02189D78  arm  ov009
 *   g_021A5718     0x021A5718  data
 *   g_021A5720     0x021A5720  data
 *   g_021A5728     0x021A5728  data
 *   g_021A5734     0x021A5734  data
 *   func_0209477C  0x0209477C  arm
 *   func_0217ED64  0x0217ED64  arm  ov009
 *   func_0217D254  0x0217D254  arm  ov009
 *   g_021A573C     0x021A573C  data
 *   g_021A5750     0x021A5750  data
 *   g_021A5788     0x021A5788  data
 *   g_021A57A0     0x021A57A0  data
 *   g_021A57B8     0x021A57B8  data
 *   func_0217F790  0x0217F790  arm  ov009
 *   func_0217F7AC  0x0217F7AC  arm  ov009
 *   func_0217FA90  0x0217FA90  arm  ov009
 */
typedef unsigned int   u32;

typedef unsigned char  u8;

extern u8 *func_02094860(u8 *dest, const u8 *src, u32 n);
extern int func_020949F4(const unsigned char *s1, const unsigned char *s2, unsigned int n);
extern int func_020964E0(u32 a0);
extern u8 *func_02094B20(const u8 *s1, const u8 *s2);
extern int func_02189D78(int *connection, int a1, int a2);
extern int func_0209477C(const u8 *s);
extern int func_0217ED64(int theSocket, int *theReadFlag, int *theWriteFlag, int *theExceptFlag);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_0217F790(unsigned int v);
extern unsigned int func_0217F7AC(unsigned int min, unsigned int max);
extern void func_0217FA90(const char *input, char *output, int inlen, int encodingType);
void func_0219327C(char *p, int b, int n);
int func_0219329C(int *connection, const char *input, int fatal);
int func_02193378(char *command, char *key, int *index, char *value, int len);
int func_02193418(const char *command, const char *key, char *value, int valueLen);
int func_02193488(int *connection, int sock, int *state);
int func_0219359C(int *connection, const char *buffer, int *index, char *key, char *value);
void func_02193710(int *connection, int result, int errorString);
void func_02193734(int *p, int b);
void func_02193748(const char *plaintext, char *encoded);
extern char g_021A5718[];
extern char g_021A5720[];
extern char g_021A5728[];
extern char g_021A5734[];
extern char g_021A573C[];
extern char g_021A5750[];
extern char g_021A5788[];
extern char g_021A57A0[];
extern char g_021A57B8[];


/*
 * Clears the byte one before the sum of the block and the count.
 */
void func_0219327C(char *p, int b, int n)
{
    func_02094860((u8 *)p, (const u8 *)b, n);
    *(char *)(p + n - 1) = 0;
}


/*
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
 */
int func_0219329C(int *connection, const char *input, int fatal)
{
    char value[0x10];
    int *ic = (int *)*connection;

    if (func_020949F4((const unsigned char *)input, (const unsigned char *)g_021A5718, 7) != 0)
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


/*
 * sdk:      gpiValueForKeyWithIndex (libdwcgsgp.TWL.HYB.a(gpiutility.o))
 */
int func_02193378(char *command, char *key, int *index, char *value, int len)
{
    char delimiter;
    char *start;
    int i;
    char c;

    command += *index;
    delimiter = key[0];
    start = (char *)func_02094B20((const unsigned char *)command, (const unsigned char *)key);
    if (start == 0)
        return 0;
    start += func_0209477C((const u8 *)key);
    for (i = 0; i < len - 1 && (c = start[i]) != 0 && c != delimiter; i++)
        value[i] = c;
    value[i] = 0;
    *index += (start - command) + func_0209477C((const u8 *)value);
    return 1;
}


/*
 * gpiValueForKey: locate `key` in `command` with strstr, skip the key text
 * with strlen, then copy up to valueLen-1 characters into `value`, stopping
 * at NUL or at the key's first character (the '\\' delimiter).  Returns 1
 * when the key was found, 0 otherwise.
 *
 * The delimiter is read once at entry.  The loop character must be bound to
 * a named local inside the condition (`(c = p[i]) != '\0'`), otherwise this
 * compiler puts the register delimiter in `cmp`'s first slot instead of the
 * freshly loaded byte and the function is one instruction off.
 */
int func_02193418(const char *command, const char *key, char *value, int valueLen)
{
    char *p;
    int i;
    char keychar = key[0];
    char c;

    p = (char *)func_02094B20((const u8 *)command, (const u8 *)key);
    if (p == 0)
        return 0;
    p += func_0209477C((const u8 *)key);
    i = 0;
    while ((i < valueLen - 1) && ((c = p[i]) != '\0') && (c != keychar)) {
        value[i] = c;
        i++;
    }
    value[i] = '\0';
    return 1;
}


/*
 * gpiCheckSocketConnect: probe the socket with func_0217ED64.  -1 means the
 * select failed, a non-positive return leaves the state at 0, and otherwise
 * the two out-parameters decide between accepted (state 4) and rejected
 * (state 3).
 */
int func_02193488(int *connection, int sock, int *state)
{
    int e[2];
    int r;

    e[1] = 0;
    e[0] = 0;
    r = func_0217ED64(sock, 0, &e[1], &e[0]);
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


/*
 * gpiReadKeyAndValue.  Faithful port of the public GameSpy gpiUtility.c body:
 * one running `buffer` pointer shared by both loops and a single reused `i`,
 * with `start` taken before the leading backslash is consumed.  The four
 * malformed cases each inline their own CallbackFatalError tail (gpiSetError
 * with result 1 and the "Parse Error." string pinned at 0x021A57B8, then
 * func_02189D78 with callback type 3 and return 3); they are not a shared
 * block.  The earlier DIFF was a register rotation caused by spelling the two
 * copies out of one pointer with separate key/value cursor locals; using the
 * public running-pointer form reproduces the original allocation (start in
 * lr, buffer/cursor in r1, c in r5 then r3, i in r6 then r5, value in ip).
 */
int func_0219359C(int *connection, const char *buffer, int *index, char *key, char *value)
{
    int c;
    int i;
    char *start;

    buffer += *index;
    start = (char *)buffer;

    if (*buffer++ != '\\') {
        func_02193710(connection, 1, (int)g_021A57B8);
        func_02189D78(connection, 3, 1);
        return 3;
    }

    for (i = 0; (c = *buffer++) != '\\'; i++) {
        if (c == 0) {
            func_02193710(connection, 1, (int)g_021A57B8);
            func_02189D78(connection, 3, 1);
            return 3;
        }
        if (i == 0x1ff) {
            func_02193710(connection, 1, (int)g_021A57B8);
            func_02189D78(connection, 3, 1);
            return 3;
        }
        *key++ = (char)c;
    }
    *key = 0;

    for (i = 0; ((c = *buffer++) != '\\') && (c != 0); i++) {
        if (i == 0x1ff) {
            func_02193710(connection, 1, (int)g_021A57B8);
            func_02189D78(connection, 3, 1);
            return 3;
        }
        *value++ = (char)c;
    }
    *value = 0;

    *index += (int)(buffer - start - 1);
    return 0;
}


/*
 * gpiSetError: copy the error string into the connection-owned buffer at
 * the head of the connection object and record the result word at +0x5b8.
 */
void func_02193710(int *connection, int result, int errorString)
{
    char *iconnection = *(char **)connection;

    func_0219327C(iconnection, errorString, 0x100);
    *(int *)(iconnection + 0x5b8) = result;
}


/*
 * Tail call on the word the pointer holds, with the constant third argument 0x100.
 */
void func_02193734(int *p, int b)
{
    func_0219327C((char *)(*p), b, 0x100);
}


/*
 * gpiEncodeString: seed the shared RNG with the constant 0x79707367 ("gspy"),
 * XOR each plaintext byte with a random byte, then hand the temporary to
 * func_0217FA90 with mode 1.
 */
void func_02193748(const char *plaintext, char *encoded)
{
    char temp[0x20];
    unsigned int i;
    unsigned int len;

    len = func_0209477C((const u8 *)plaintext);
    func_0217F790(0x79707367);
    for (i = 0; i < len; i++)
        temp[i] = plaintext[i] ^ (char)func_0217F7AC(0, 0xff);
    temp[i] = 0;
    func_0217FA90(temp, encoded, len, 1);
}
