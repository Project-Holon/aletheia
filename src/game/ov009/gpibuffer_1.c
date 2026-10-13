/*
 * file:     gpibuffer_1.c
 * unit:     yes
 * function: func_0218934C, func_021893C8, func_0218946C, func_0218949C, func_021894D8
 * address:  0x0218934C
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
 *   func_0217EAC8  0x0217EAC8  arm  ov009
 *   func_02193734  0x02193734  arm  ov009
 *   g_021A44C8     0x021A44C8  data
 *   func_02092344  0x02092344  arm
 *   func_0209477C  0x0209477C  arm
 *   func_02084F40  0x02084F40  arm
 *   g_021A44D8     0x021A44D8  data
 *   func_0217EC90  0x0217EC90  arm  ov009
 *   func_0217ED54  0x0217ED54  arm  ov009
 *   func_02193710  0x02193710  arm  ov009
 *   func_02189D78  0x02189D78  arm  ov009
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   g_021A44DC     0x021A44DC  data ov009
 *   g_021A4504     0x021A4504  data ov009
 *   g_021A4528     0x021A4528  data ov009
 *   _ZZ13func_021894D8PiiPciS_S_S0_E9sendCount 0x021ADFC8 data
 */
typedef unsigned char  u8;

extern char *func_0217EAC8(char *p, int n);
extern void func_02193734(int *connection, int string);
extern void *func_02092344(void *dest, const void *src, unsigned int n);
extern int func_0209477C(const u8 *s);
extern int func_02084F40(char *dst, const char *fmt, ...);
extern int func_0217EC90(int sock, char *buffer, int bufferLen, int flags);
extern int func_0217ED54(int sock);
extern void func_02193710(int *connection, int result, int errorString);
extern int func_02189D78(int *connection, int a1, int a2);
extern char *func_0217EAB0(int size);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_0217EAE0(void *p);
int func_0218934C(int *connection, int *buffer, int c);
int func_021893C8(int *connection, int *buffer, int src, int n);
int func_0218946C(int *connection, int *buffer, const char *string);
int func_0218949C(int *connection, int *buffer, int value);
int func_021894D8(int *connection, int sock, char *buffer, int bufferLen, int *closed, int *sent, char *id);
extern char g_021A44C8[];
extern char g_021A44D8[];
extern char g_021A44DC[];
extern char g_021A4504[];
extern char g_021A4528[];


/*
 * gpiAppendCharToBuffer: append one character to a GPIBuffer (0=data,
 * 4=size, 8=len), growing the backing store by 0x4000 bytes when full.
 */
int func_0218934C(int *connection, int *buffer, int c)
{
    int len = buffer[2];
    int size = buffer[1];
    char *data;

    data = (char *)buffer[0];
    if (size == len) {
        size += 0x4000;
        data = func_0217EAC8(data, size + 1);
        if (data == 0) {
            func_02193734(connection, (int)g_021A44C8);
            return 1;
        }
    }
    data[len] = c;
    data[len + 1] = 0;
    buffer[0] = (int)data;
    buffer[2] += 1;
    buffer[1] = size;
    return 0;
}


/*
 * gpiAppendDataToBuffer: append `n` bytes of `src` to a GPIBuffer
 * (0=data, 4=size, 8=len).  Grows the store by max(0x4000, n) when the
 * free tail is shorter than n, then NUL-terminates.
 */
int func_021893C8(int *connection, int *buffer, int src, int n)
{
    int buflen;
    int size;
    char *data;

    if (src == 0)
        return 0;
    buflen = buffer[2];
    size = buffer[1];
    data = (char *)buffer[0];
    if (size - buflen < n) {
        int grow = 0x4000;
        if (n >= grow)
            grow = n;
        size += grow;
        data = func_0217EAC8(data, size + 1);
        if (data == 0) {
            func_02193734(connection, (int)g_021A44C8);
            return 1;
        }
    }
    func_02092344(data + buflen, (const void *)src, n);
    data[buflen + n] = 0;
    buffer[1] = size;
    buffer[2] += n;
    buffer[0] = (int)data;
    return 0;
}


/*
 * gpiAppendStringToBuffer: append a NUL-terminated string's bytes to a
 * GPIBuffer, its length supplied by strlen.
 */
int func_0218946C(int *connection, int *buffer, const char *string)
{
    return func_021893C8(connection, buffer, (int)string, func_0209477C((const u8 *)string));
}


/*
 * gpiAppendIntToBuffer: format the integer with sprintf("%d") into a small
 * stack buffer, then append that string to the GPIBuffer.
 */
int func_0218949C(int *connection, int *buffer, int value)
{
    char buf[0x10];

    func_02084F40(buf, g_021A44D8, value);
    return func_0218946C(connection, buffer, buf);
}


/*
 * gpiSendData (static helper of gpiSendFromBuffer): one send() on the socket.
 * On -1/GOAGetLastError outside the three would-block/in-progress/timeout
 * codes, a "PR" peer id returns GP_NETWORK_ERROR immediately, else raise
 * GP_NETWORK on the connection and return GP_NETWORK_ERROR.  On rcode == 0
 * mark the connection closed; otherwise raw-dump the sent bytes through the
 * GSIDebug network logger and account them in the static sendCount.
 *
 * BLOCKER (codegen only, 21 bytes at +0x118..+0x138): the whole function is
 * the right size (364) and every other byte is identical, but the GSIDebug
 * raw-dump call schedules `sendCount++` differently.  The original loads the
 * format pointer into r3 *before* the counter (base r1, fmt r3, count r2,
 * stm sp,{r2,r6}, add r2,#1, str r2,[r1]); this front end instead does the
 * counter first (base r0, base r1, count r3, add, str, stm sp,{r3,sl}) and
 * rematerialises the format address after the increment.  Tried: scalar vs
 * array vs struct-member counter, a named count local, a `register` local,
 * both-fmt-and-count locals, a pointer-to-counter local, an unprototyped
 * callee, and void/int callee returns; all reproduce the same order.  Every
 * other call site in this file (the error path and the rcode==0 branch) is
 * byte-exact.  Not a witness problem: the three literals and both gsiSet
 * underlays all resolve; this is the mwcc argument-scheduling heuristic for
 * a post-increment in a varargs list.  Documented as docs/idioms/
 * a-varargs-counter-increment-is-scheduled-before-a-later-format-pointer.md.
 *
 * Re-verified 2026-09-27 (region ov009 / ARM confirmed): still 364/364 with
 *   the same 21 bytes at +0x118..+0x138; all 13 relocations resolve, so the
 *   only cap is the argument-scheduling quirk.  Not promotable to MATCH (real
 *   bytes differ), so it stays parked.
 *
 * lane U41 (2026-09-30).  Re-measured: still 364/364 with the same 21 bytes at
 * +0118..+0138, 13/13 relocations resolved.  Six more spellings measured, all
 * 21 diffs: `int c = sendCount++;` passed as the argument, the pre-increment
 * split into two statements, `c = ...` in a later statement, `(int)` and
 * `(unsigned)` casts on the post-increment, and the increment moved after the
 * call (that one is 34).  Residue unchanged and named: the argument scheduler
 * picks r3 for the counter and computes `count + 1` into r2 before the vararg
 * store, where the image keeps the counter in r2 and increments it in place
 * after `stm sp, {r2, r6}`.
 *
 * lane T5 (2026-09-30).  Pin sweep (all 9 dsi compilers x 4 flag sets): no
 * configuration moves the 21 bytes at +0118..+0138; 1.1p1 -O4,p at 364/21 is the
 * unique best.  Residue unchanged and already named: the GSIDebug raw-dump call
 * schedules `sendCount++` before the format pointer (see
 * docs/idioms/a-varargs-counter-increment-is-scheduled-before-a-later-format-pointer.md).
 *
 * lane W8 (2026-09-30): re-measured 364/364, 13/13 relocations, 21 concrete.
 *   New spellings tried: `const char *fmt = g_021A4528;` then `fmt` + inline
 *   `sendCount++` (same 21, compactor already sinks the fmt load); sequential
 *   `int count = g_021ADFC8; char *fmt = g_021A4528; ... g_021ADFC8 = count+1;`
 *   which does place the fmt load between the counter load and its store but
 *   resizes to 368/117 (extra callee-saved).  Residue unchanged: mwcc sinks the
 *   format-pointer load below the counter RMW and colours the counter r3.
 *
 * lane W7 (2026-09-30): re-measured 364/364, 13/13 relocations, 21 concrete
 * bytes.  Re-tested the counter as a `cnt` temp with the increment before the
 * call (368/117), after the call (368/119) and passing `g_021ADFC8 + 1` then
 * incrementing (368/71); all are worse and change the size, confirming the
 * image's push-then-writeback order is the mwcc argument scheduler.
 *
 * lane04 (2026-10-01): EXACT. The vendor relocation names
 * `_ZZ11gpiSendData...E9sendCount`, a function-local static. Declaring
 * `static int sendCount;` inside the function closes all 21 bytes (a file-scope
 * static or a block-scope extern does not): the counter's address never
 * escapes, so the varargs scheduler keeps it in r2 and loads fmt first. Its
 * `.bss` relocation resolves through the symbols line naming the compiled
 * local static (mangled with this file's function name). Also restored the
 * DWARF gsDebugFormat prototype (`(int,int,int,char *,int,...)` did not
 * compile).
 */
int func_021894D8(int *connection, int sock, char *buffer, int bufferLen,
                  int *closed, int *sent, char *id)
{
    static int sendCount;
    int rcode = func_0217EC90(sock, buffer, bufferLen, 0);

    if (rcode == -1) {
        rcode = func_0217ED54(sock);
        if (rcode != -6 && rcode != -26 && rcode != -76) {
            if (id[0] == 'P' && id[1] == 'R')
                return 3;
            func_02193710(connection, 5, (int)g_021A44DC);
            func_02189D78(connection, 3, 0);
            return 3;
        }
        *sent = 0;
        *closed = 0;
    } else if (rcode == 0) {
        func_0217D254(1, 0, 0x10, g_021A4504, id);
        *sent = 0;
        *closed = 1;
    } else {
        char *buf = func_0217EAB0(rcode + 1);

        func_02092344(buf, buffer, rcode);
        buf[rcode] = 0;
        func_0217D254(1, 0, 0x20, g_021A4528, sendCount++, id, buf);
        func_0217EAE0(buf);
        *sent = rcode;
        *closed = 0;
    }
    return 0;
}
