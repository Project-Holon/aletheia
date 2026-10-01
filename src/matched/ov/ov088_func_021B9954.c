/*
 * function: func_021B9954
 * address:  0x021B9954
 * packet:   pkt_ov088_021B9954
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204A648  0x0204A648  arm
 */

extern void func_0204A648(void);

void func_021B9954(void *task, short *p)
{
    func_0204A648();
    *(volatile unsigned int *)0x04000064 = p[4] | (0xC0330000 | (p[5] << 8));
}
