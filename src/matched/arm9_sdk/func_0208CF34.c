/*
 * function: STD_TSScanf
 * address:  0x0208CF34
 * packet:   pkt_02087AE4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libos os_printf.o.  This is NOT a new function: the worklist seeded
 * the open entry at 0x0208CF38, four bytes into the body.  The real entry is
 * the `push {r0,r1,r2,r3}` argument-home store at 0x0208CF34 that every
 * varargs function in this library opens with (see
 * docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md);
 * disasm.py labels the SECOND push (the one that saves lr) instead, so
 * 0x0208CF38 was a mis-seeded label, not a function.  layout/symbols_sdk.txt
 * names 0x0208CF34 STD_TSScanf.
 *
 * The callee 0x0208CFD8 is named STD_TVSScanf in layout/symbols_sdk.txt, but
 * the call shape here (dst, fmt, va_list) is a vsprintf, not a scanf; the SDK
 * table's name for that address looks wrong.  The address is what matters and
 * the name is carried through unchanged so the table and this file agree.
 *
 * symbols:
 *   STD_TVSScanf  0x0208CFD8  arm
 */

typedef char *va_list;
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_end(v)

extern int STD_TVSScanf(char *dst, const char *fmt, va_list vlist);

int STD_TSScanf(char *dst, const char *fmt, ...)
{
    int r;
    va_list vlist;
    va_start(vlist, fmt);
    r = STD_TVSScanf(dst, fmt, vlist);
    va_end(vlist);
    return r;
}
