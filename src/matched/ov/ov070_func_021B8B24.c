/*
 * function: func_021B8B24
 * address:  0x021B8B24
 * packet:   pkt_ov070_021B8B24
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202E940  0x0202E940  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_0202E9AC  0x0202E9AC  thumb
 *   func_02049238  0x02049238  arm
 */

extern int func_0202E940();
extern int func_020490F4();
extern void func_0202E9AC();
extern void func_02049238();

void func_021B8B24(int p)
{
    int h;
    *(int *)((char *)p + 0x850) =
        func_0202E940(0x10, 0x10, 0xFFFE, *(unsigned short *)((char *)p + 0x544));
    h = func_020490F4(0x58, *(unsigned short *)((char *)p + 0x544));
    func_0202E9AC(*(int *)((char *)p + 0x850), h, 0x15, 0x10, 0x20);
    func_02049238(h);
}
