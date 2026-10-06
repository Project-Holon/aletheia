/*
 * function: func_02095EAC
 * address:  0x02095EAC
 * packet:   pkt_020949F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * MSL strtoul: the unsigned member of the strtoX wrapper family over the
 * scanner core at 0x02095B3C.  Four lanes and twenty-five spellings left this
 * at one instruction out (+0x70, `mvnne r0, #0` against 1.1p1's
 * `subne r0, r1, #0x23` fold from the 0x22 errno value) because every one of
 * them RETURNED the -1 from inside the error block.  The MSL source does not:
 *
 *     if (overflow) { value = ULONG_MAX; errno = ERANGE; }
 *     else if (negative) value = -value;
 *     return value;
 *
 * The -1 is assigned to the result variable BEFORE the errno store, the
 * negation is an ELSE-IF, and there is one return.  Under that shape the
 * value is a definition of `r` rather than a return constant and the back
 * end rematerialises it with `mvn`; the same compiler, no pin.  The return
 * type is u32 (unsigned long) and the core's return is u32 as well.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02095EAC.c \
 *       --func func_02095EAC --addr 0x02095EAC --cc 1.1p1 --arm
 *   EXACT, 148 bytes, 3 relocation sites, all resolved.
 *
 * symbols:
 *   func_02095B3C  0x02095B3C  arm
 *   func_020946D8  0x020946D8  arm
 *   g_02153FAC     0x02153FAC  data
 */
typedef unsigned int u32;
extern u32 func_02095B3C(int base, int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg, int *chars_scanned, int *negative, int *overflow);
extern int func_020946D8(u32 *p, u32 a1, u32 a2);
extern u32 g_02153FAC;

u32 func_02095EAC(u32 a0, u32 *a1, u32 mode)
{
    u32 len;
    u32 sign;
    u32 err;
    u32 buf[2];
    u32 r;

    buf[0] = a0;
    buf[1] = 0;
    r = func_02095B3C(mode, 0x7FFFFFFFu, (int (*)(void *, int,  int))((u32)func_020946D8), buf, (int *)(&len), (int *)(&sign), (int *)(&err));
    if (a1 != 0)
        *a1 = a0 + len;
    if (err != 0) {
        r = 0xFFFFFFFFu;
        g_02153FAC = 0x22;
    } else if (sign != 0)
        r = -r;
    return r;
}
