/*
 * function: func_02208B54
 * address:  0x02208B54
 * packet:   pkt_02208B54
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020480E4 0x020480E4 arm
 *   func_02208714 0x02208714 thumb
 */

extern void func_020480E4(int, int);
extern void func_02208714(int);

void func_02208B54(char *a)
{
    func_020480E4(*(int *)(a + 0x14), *(unsigned short *)(a + 0x18));
    func_02208714(*(int *)(a + 0x20));
    *(unsigned short *)(a + 0x1c) = 0;
}