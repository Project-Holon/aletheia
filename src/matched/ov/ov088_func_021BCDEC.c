/*
 * function: func_021BCDEC
 * address:  0x021BCDEC
 * packet:   pkt_ov088_021BCDEC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the extent runs two bytes long (trailing padding pair).
 *
 * symbols:
 *   func_0201FEBC  0x0201FEBC  thumb
 *   func_021BD118  0x021BD118  thumb  ov088
 *   func_021BD23C  0x021BD23C  thumb  ov088
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_0201FEBC(u8 *p);
extern void func_021BD118(int *p, u32 mode);
extern void func_021BD23C(void);

void func_021BCDEC(void *p, int *st)
{
    int r = func_0201FEBC(*(void **)((char *)p + 0x20));

    if (r == 0)
        goto a;
    if (r == -2)
        goto b;
    return;
a:
    func_021BD118(p, 1);
    *st = 4;
    return;
b:
    func_021BD23C();
    *st = 7;
}
