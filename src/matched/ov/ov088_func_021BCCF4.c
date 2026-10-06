/*
 * function: func_021BCCF4
 * address:  0x021BCCF4
 * packet:   pkt_ov088_021BCCF4
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the extent runs two bytes long (trailing padding pair).
 *
 * symbols:
 *   func_021BCD88  0x021BCD88  thumb  ov088
 *   func_021BCDB4  0x021BCDB4  thumb  ov088
 *   func_021BCDD0  0x021BCDD0  thumb  ov088
 *   func_021BCDEC  0x021BCDEC  thumb  ov088
 *   func_021BCE20  0x021BCE20  thumb  ov088
 *   func_021BCE3C  0x021BCE3C  thumb  ov088
 *   func_021BCE80  0x021BCE80  thumb  ov088
 *   func_021BCF18  0x021BCF18  thumb  ov088
 */

extern void func_021BCD88(void *, int *);
extern void func_021BCDB4(void *, int *);
extern void func_021BCDD0(void *, int *);
extern void func_021BCDEC(void *, int *);
extern void func_021BCE20(void *, int *);
extern void func_021BCE3C(char *p, int *out);
typedef unsigned char  u8;
extern void func_021BCE80(u8 *p, int *a1);
extern void func_021BCF18(void *, int *);

int func_021BCCF4(int a, int *st, int c, void *p)
{
    switch (*st) {
    case 0:
        func_021BCD88(p, st);
        break;
    case 1:
        func_021BCDB4(p, st);
        break;
    case 2:
        func_021BCDD0(p, st);
        break;
    case 3:
        func_021BCDEC(p, st);
        break;
    case 4:
        func_021BCE20(p, st);
        break;
    case 5:
        func_021BCE3C(p, st);
        break;
    case 6:
        func_021BCE80(p, st);
        break;
    case 7:
        func_021BCF18(p, st);
        break;
    case 8:
        return 1;
    }
    return 0;
}
