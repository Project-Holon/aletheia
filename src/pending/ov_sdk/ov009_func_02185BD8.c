/*
 * function: func_02185BD8
 * address:  0x02185BD8
 * packet:   pkt_ov009_02185BD8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      gpGetInfo (gp.o)
 *
 * NEAR MISS (callee of func_02168ECC / func_02168F18).  The guard chain,
 * GPIConnection field checks (0x108, 0x1f4), gpiSetErrorString calls, the
 * callback path and the gpiGetInfo tail call all reconstruct cleanly, but the
 * 0x204-byte GPGetInfoResponseArg zeroing is a blocker: the vendor object
 * inlines it as a word `stm lr!,{r0,r1,r2,r3}` fill loop (16 iterations) while
 * this front end lowers `memset`/compound-literal zeroing to an out-of-line
 * memset call (or a temp copy with a doubled frame).  mwccarm 1.1p1 does not
 * inline memset for a constant size; the object's stamp 4.0.0.1025 (no shipped
 * build writes it) also made this a memset-inline difference.  Registers then
 * diverge (original keeps connection in r5 and callback in lr, freeing r0 for
 * the fill) and the function never reaches EXACT.  No witness problem.
 *
 * symbols:
 *   func_02193734  0x02193734  arm
 *   func_0218D4A4  0x0218D4A4  arm
 *   g_021A4010     0x021A4010  data
 *   g_021A4024     0x021A4024  data
 */

typedef struct GPIConnection GPIConnection;

typedef struct {
    unsigned long w[0x81];
} GPGetInfoResponseArg;

extern void func_02193734(void **connection, char *errorString);
extern void func_02082BCC(void *dst, unsigned char val, unsigned long size);
extern int func_0218D4A4(void **connection, int profile, int checkCache, int blocking,
                         void (*callback)(void **, void *, void *), void *param);
extern char g_021A4010[];
extern char g_021A4024[];

int func_02185BD8(void **connection, int profile, int checkCache, int blocking,
                  void (*callback)(void **, void *, void *), void *param)
{
    GPGetInfoResponseArg arg;
    GPIConnection *iconnection;

    if (connection == 0 || *connection == 0 || profile == 0) return 2;
    if (callback == 0) {
        func_02193734(connection, g_021A4010);
        return 2;
    }
    iconnection = (GPIConnection *)*connection;
    if (*(int *)((char *)iconnection + 0x108) != 0) {
        func_02082BCC(&arg, 0, sizeof(arg));
        callback(connection, &arg, param);
        return 0;
    }
    if (*(int *)((char *)iconnection + 0x1f4) == 4) {
        func_02193734(connection, g_021A4024);
        return 2;
    }
    return func_0218D4A4(connection, profile, checkCache, blocking, callback, param);
}
