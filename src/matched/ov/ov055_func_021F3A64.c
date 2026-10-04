/*
 * function: func_021F3A64
 * address:  0x021F3A64
 * packet:   pkt_ov055_021F3A64
 * region:   ov055
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02189A68  0x02189A68  thumb  ov021
 *   func_021F3CE4  0x021F3CE4  thumb  ov055
 *   func_021F3F20  0x021F3F20  thumb  ov055
 *   func_021F4430  0x021F4430  thumb  ov055
 */

extern void func_02189A68(char *a, int b);
extern void func_021F3CE4(char *);
extern void func_021F3F20(char *);
extern void func_021F4430(char *);

void func_021F3A64(int a, int b, char *c)
{
    int i;

    func_02189A68((char *)b, 0);
    for (i = 0; i < 0x20; i++)
        func_021F3CE4(c + 8 + i * 0x18);
    func_021F3F20(c + 0x308);
    func_021F4430(c + 0x348);
    *(int *)c = 0;
    *(int *)(c + 4) = 0;
}
