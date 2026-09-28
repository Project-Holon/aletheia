/*
 * function: func_021BE3B4
 * address:  0x021BE3B4
 * packet:   pkt_021BE3B4
 * region:   ov210
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 */

extern void func_020452E8(void *);
extern void func_020450C8(void);

void func_021BE3B4(char *p)
{
    unsigned int i;
    for (i = 0; i < 0x10; i++)
    {
        func_020452E8(*(void **)(p + 0x14c + i * 8));
    }
    func_020450C8();
}
