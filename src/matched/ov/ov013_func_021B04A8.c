/*
 * function: func_021B04A8
 * address:  0x021B04A8
 * packet:   pkt_ov013_021B04A8
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021B01FC  0x021B01FC  arm  ov013
 *   func_021AFABC  0x021AFABC  arm  ov013
 *   func_021AF494  0x021AF494  arm  ov013
 */

typedef unsigned char u8;
typedef short s16;

typedef struct AdpcmHdr {
    s16 pred;
    u8 index;
    u8 zero;
} AdpcmHdr;

typedef struct AdpcmState {
    s16 pred;
    u8 index;
} AdpcmState;

extern void func_021B01FC(void *dst, void *a, int n, AdpcmState *st);
extern void func_021AFABC(void *dst, void *a, int n, AdpcmState *st);
extern void func_021AF494(void *dst, void *a, int n, AdpcmState *st);

void func_021B04A8(AdpcmHdr *out, void *a, int n, AdpcmState *st, int mode)
{
    out->pred = st->pred;
    out->index = st->index;
    out->zero = 0;
    switch (mode) {
    case 2:
        func_021B01FC((u8 *)out + 4, a, n, st);
        break;
    case 3:
        func_021AFABC((u8 *)out + 4, a, n, st);
        break;
    case 4:
        func_021AF494((u8 *)out + 4, a, n, st);
        break;
    }
}
