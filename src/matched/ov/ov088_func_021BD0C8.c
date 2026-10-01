/*
 * function: func_021BD0C8
 * address:  0x021BD0C8
 * packet:   pkt_ov088_021BD0C8
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020452E8  0x020452E8  arm
 *   func_020450C8  0x020450C8  arm
 */

extern void func_020452E8(void *);
extern void func_020450C8(void);

void func_021BD0C8(unsigned char *p)
{
    func_020452E8(*(void **)(p + 0x1C));
    func_020450C8();
}
