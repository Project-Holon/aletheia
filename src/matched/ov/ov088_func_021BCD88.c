/*
 * function: func_021BCD88
 * address:  0x021BCD88
 * packet:   pkt_ov088_021BCD88
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
 *   func_021BCF44  0x021BCF44  thumb  ov088
 *   func_021BCF6C  0x021BCF6C  thumb  ov088
 *   func_021BCFEC  0x021BCFEC  thumb  ov088
 *   func_021BD078  0x021BD078  thumb  ov088
 *   func_021BD0F4  0x021BD0F4  thumb  ov088
 *   func_021BD21C  0x021BD21C  thumb  ov088
 */

extern void func_021BCF44(void);
extern void func_021BCF6C(void);
extern void func_021BCFEC(void *);
extern void func_021BD078(void *);
extern void func_021BD0F4(void *);
extern void func_021BD21C(void);

void func_021BCD88(void *p, int *st)
{
    func_021BCF44();
    func_021BCF6C();
    func_021BCFEC(p);
    func_021BD078(p);
    func_021BD0F4(p);
    func_021BD21C();
    *st = 1;
}
