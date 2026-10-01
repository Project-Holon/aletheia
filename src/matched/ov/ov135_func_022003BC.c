/*
 * function: func_022003BC
 * address: 0x022003BC
 * packet: pkt_ov135_022003BC
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02202940 0x02202940 thumb ov135
 *   func_020452E8 0x020452E8 arm
 */
typedef unsigned char u8;
extern void func_02202940(void *);
extern void func_020452E8(void *);
void func_022003BC(u8 *p)
{
    int i;
    func_02202940(p + 0xFA0);
    func_020452E8(*(void **)(p + 0xDE0));
    func_020452E8(*(void **)(p + 0xDD0));
    func_020452E8(*(void **)(p + 0xD40));
    for (i = 0; i < 3; i++) func_020452E8(*(void **)(p + i * 4 + 0xD50));
    func_020452E8(*(void **)(p + 0xD48));
}
