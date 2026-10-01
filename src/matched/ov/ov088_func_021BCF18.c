/*
 * function: func_021BCF18
 * address:  0x021BCF18
 * packet:   pkt_ov088_021BCF18
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
 *   func_020221A4  0x020221A4  thumb
 *   func_021BD10C  0x021BD10C  thumb  ov088
 *   func_021BD0C8  0x021BD0C8  thumb  ov088
 *   func_021BD04C  0x021BD04C  thumb  ov088
 *   func_021BCFD4  0x021BCFD4  thumb  ov088
 */

extern int func_020221A4(void);
extern void func_021BD10C(void *);
extern void func_021BD0C8(void *);
extern void func_021BD04C(void *);
extern void func_021BCFD4(void);

void func_021BCF18(void *p, int *st)
{
    if (func_020221A4() == 1) {
        func_021BD10C(p);
        func_021BD0C8(p);
        func_021BD04C(p);
        func_021BCFD4();
        *st = 8;
    }
}
