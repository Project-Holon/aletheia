/*
 * file:     gpiutility.c
 * unit:     yes
 * function: strzcpy, gpiCheckForError, gpiValueForKeyWithIndex, gpiValueForKey, gpiCheckSocketConnect, gpiReadKeyAndValue, gpiSetError, gpiSetErrorString, gpiEncodeString
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
 *   strncmp  0x020949F4  arm
 *   atoi  0x020964E0  arm
 *   strstr  0x02094B20  arm
 *   gpiCallErrorCallback  0x02189D78  arm  ov009
 *   gGpiUtilityKeyError     0x021A5718  data
 *   gGpiUtilityKeyErr     0x021A5720  data
 *   gGpiUtilityKeyErrMsg     0x021A5728  data
 *   gGpiUtilityKeyFatal     0x021A5734  data
 *   strlen  0x0209477C  arm
 *   GSISocketSelect  0x0217ED64  arm  ov009
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   gGpiUtilityMsgErrorConnecting     0x021A573C  data
 *   gGpiUtilityMsgErrorChecking     0x021A5750  data
 *   gGpiUtilityMsgConnectionRejected     0x021A5788  data
 *   gGpiUtilityMsgConnectionAccepted     0x021A57A0  data
 *   gGpiUtilityMsgParseError     0x021A57B8  data
 *   Util_RandSeed  0x0217F790  arm  ov009
 *   Util_RandInt  0x0217F7AC  arm  ov009
 *   B64Encode  0x0217FA90  arm  ov009
 *   strncpy  0x02094860  arm  arm9
 */
typedef unsigned int   u32;

typedef unsigned char  u8;

extern u8 *strncpy(u8 *dest, const u8 *src, u32 n);
extern int strncmp(const unsigned char *s1, const unsigned char *s2, unsigned int n);
extern int atoi(u32 s);
extern u8 *strstr(const u8 *s1, const u8 *s2);
extern int gpiCallErrorCallback(void **connection, int result, int fatal);
extern int strlen(const u8 *s);
extern int GSISocketSelect(int theSocket, int *theReadFlag, int *theWriteFlag, int *theExceptFlag);
extern void gsDebugFormat(int cat, int type, int level, char *fmt, ...);
extern void Util_RandSeed(unsigned int v);
extern unsigned int Util_RandInt(unsigned int min, unsigned int max);
extern void B64Encode(const char *input, char *output, int inlen, int encodingType);
void strzcpy(char *p, int b, int n);
int gpiCheckForError(int *connection, const char *input, int fatal);
int gpiValueForKeyWithIndex(char *command, char *key, int *index, char *value, int len);
int gpiValueForKey(const char *command, const char *key, char *value, int valueLen);
int gpiCheckSocketConnect(int *connection, int sock, int *state);
int gpiReadKeyAndValue(int *connection, const char *buffer, int *index, char *key, char *value);
void gpiSetError(int *connection, int result, int errorString);
void gpiSetErrorString(int *p, int b);
void gpiEncodeString(const char *plaintext, char *encoded);
extern char gGpiUtilityKeyError[];
extern char gGpiUtilityKeyErr[];
extern char gGpiUtilityKeyErrMsg[];
extern char gGpiUtilityKeyFatal[];
extern char gGpiUtilityMsgErrorConnecting[];
extern char gGpiUtilityMsgErrorChecking[];
extern char gGpiUtilityMsgConnectionRejected[];
extern char gGpiUtilityMsgConnectionAccepted[];
extern char gGpiUtilityMsgParseError[];


/*
 * Clears the byte one before the sum of the block and the count.
 */
void strzcpy(char *p, int b, int n)
{
    strncpy((u8 *)p, (const u8 *)b, n);
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
 * argument is written as a *double* boolean -- `int b = strstr(...)
 * != 0;` then `gpiCallErrorCallback(connection, 4, b != 0);`.  `_Bool` is not a
 * keyword in this C99 front end (CCERR), and folding the two tests into one
 * loses four instructions (12 bytes).
 *
 * Behaviour: guard on the 7-char prefix "\err\"; on a match read the code
 * from "\err\" via gpiValueForKey into a 0x10 stack buffer and atoi it into
 * iconnection+0x5b8; read the message from "\err\msg\" straight into the
 * connection's error string at +0 (and clear byte 0 if absent); on a fatal
 * request check for "\fatal\" and raise callback type 4 through gpiCallErrorCallback.
 */
int gpiCheckForError(int *connection, const char *input, int fatal)
{
    char value[0x10];
    int *ic = (int *)*connection;

    if (strncmp((const unsigned char *)input, (const unsigned char *)gGpiUtilityKeyError, 7) != 0)
        goto fail;
    if (gpiValueForKey(input, gGpiUtilityKeyErr, value, 0x10))
        ic[0x5b8 / 4] = atoi((u32)value);
    if (!gpiValueForKey(input, gGpiUtilityKeyErrMsg, (char *)ic, 0x100))
        *(char *)ic = 0;
    if (fatal != 0) {
        int b = strstr((const u8 *)input, (const u8 *)gGpiUtilityKeyFatal) != 0;
        gpiCallErrorCallback((void **)connection, 4, b != 0);
    }
    return 1;
fail:
    return 0;
}


/*
 * sdk:      gpiValueForKeyWithIndex (libdwcgsgp.TWL.HYB.a(gpiutility.o))
 */
int gpiValueForKeyWithIndex(char *command, char *key, int *index, char *value, int len)
{
    char delimiter;
    char *start;
    int i;
    char c;

    command += *index;
    delimiter = key[0];
    start = (char *)strstr((const unsigned char *)command, (const unsigned char *)key);
    if (start == 0)
        return 0;
    start += strlen((const u8 *)key);
    for (i = 0; i < len - 1 && (c = start[i]) != 0 && c != delimiter; i++)
        value[i] = c;
    value[i] = 0;
    *index += (start - command) + strlen((const u8 *)value);
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
int gpiValueForKey(const char *command, const char *key, char *value, int valueLen)
{
    char *p;
    int i;
    char keychar = key[0];
    char c;

    p = (char *)strstr((const u8 *)command, (const u8 *)key);
    if (p == 0)
        return 0;
    p += strlen((const u8 *)key);
    i = 0;
    while ((i < valueLen - 1) && ((c = p[i]) != '\0') && (c != keychar)) {
        value[i] = c;
        i++;
    }
    value[i] = '\0';
    return 1;
}


/*
 * gpiCheckSocketConnect: probe the socket with GSISocketSelect.  -1 means the
 * select failed, a non-positive return leaves the state at 0, and otherwise
 * the two out-parameters decide between accepted (state 4) and rejected
 * (state 3).
 */
int gpiCheckSocketConnect(int *connection, int sock, int *state)
{
    int e[2];
    int r;

    e[1] = 0;
    e[0] = 0;
    r = GSISocketSelect(sock, 0, &e[1], &e[0]);
    if (r == -1) {
        gsDebugFormat(1, 0, 1, (char *)((int)gGpiUtilityMsgErrorConnecting));
        gpiSetError(connection, 5, (int)gGpiUtilityMsgErrorChecking);
        gpiCallErrorCallback((void **)connection, 3, 1);
        return 3;
    }
    if (r <= 0)
        goto zero;
    if (e[0] != 0) {
        gsDebugFormat(1, 0, 1, (char *)((int)gGpiUtilityMsgConnectionRejected));
        *state = 4;
        return 0;
    }
    if (e[1] != 0) {
        gsDebugFormat(1, 0, 8, (char *)((int)gGpiUtilityMsgConnectionAccepted));
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
 * gpiCallErrorCallback with callback type 3 and return 3); they are not a shared
 * block.  The earlier DIFF was a register rotation caused by spelling the two
 * copies out of one pointer with separate key/value cursor locals; using the
 * public running-pointer form reproduces the original allocation (start in
 * lr, buffer/cursor in r1, c in r5 then r3, i in r6 then r5, value in ip).
 */
int gpiReadKeyAndValue(int *connection, const char *buffer, int *index, char *key, char *value)
{
    int c;
    int i;
    char *start;

    buffer += *index;
    start = (char *)buffer;

    if (*buffer++ != '\\') {
        gpiSetError(connection, 1, (int)gGpiUtilityMsgParseError);
        gpiCallErrorCallback((void **)connection, 3, 1);
        return 3;
    }

    for (i = 0; (c = *buffer++) != '\\'; i++) {
        if (c == 0) {
            gpiSetError(connection, 1, (int)gGpiUtilityMsgParseError);
            gpiCallErrorCallback((void **)connection, 3, 1);
            return 3;
        }
        if (i == 0x1ff) {
            gpiSetError(connection, 1, (int)gGpiUtilityMsgParseError);
            gpiCallErrorCallback((void **)connection, 3, 1);
            return 3;
        }
        *key++ = (char)c;
    }
    *key = 0;

    for (i = 0; ((c = *buffer++) != '\\') && (c != 0); i++) {
        if (i == 0x1ff) {
            gpiSetError(connection, 1, (int)gGpiUtilityMsgParseError);
            gpiCallErrorCallback((void **)connection, 3, 1);
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
void gpiSetError(int *connection, int result, int errorString)
{
    char *iconnection = *(char **)connection;

    strzcpy(iconnection, errorString, 0x100);
    *(int *)(iconnection + 0x5b8) = result;
}


/*
 * Tail call on the word the pointer holds, with the constant third argument 0x100.
 */
void gpiSetErrorString(int *p, int b)
{
    strzcpy((char *)(*p), b, 0x100);
}


/*
 * gpiEncodeString: seed the shared RNG with the constant 0x79707367 ("gspy"),
 * XOR each plaintext byte with a random byte, then hand the temporary to
 * B64Encode with mode 1.
 */
void gpiEncodeString(const char *plaintext, char *encoded)
{
    char temp[0x20];
    unsigned int i;
    unsigned int len;

    len = strlen((const u8 *)plaintext);
    Util_RandSeed(0x79707367);
    for (i = 0; i < len; i++)
        temp[i] = plaintext[i] ^ (char)Util_RandInt(0, 0xff);
    temp[i] = 0;
    B64Encode(temp, encoded, len, 1);
}
