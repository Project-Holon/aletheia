/*
 * function: func_021FE0BC
 * address: 0x021FE0BC
 * packet: pkt_ov135_021FE0BC
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02202940 0x02202940 thumb ov135
 *   func_020452E8 0x020452E8 arm
 *   func_02040DA8 0x02040DA8 arm
 */
extern void func_02202940(void *);
extern void func_020452E8(void *);
extern void func_02040DA8(int, int, int);
void func_021FE0BC(unsigned char *p)
{
    int i;
    func_02202940(p + 0xfa0);
    func_020452E8(*(void **)(p + 0xde0));
    func_020452E8(*(void **)(p + 0xd40));
    for (i = 0; i < 9; ++i)
        func_020452E8(*(void **)(p + i * 4 + 0xd90));
    for (i = 0; i < 2; ++i)
        func_020452E8(*(void **)(p + i * 4 + 0xdd8));
    func_02040DA8(3, 1, 0);
}
