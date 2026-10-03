/*
 * function: func_0215CD80
 * address: 0x0215CD80
 * packet: pkt_ov010_0215CD80
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021F36E8 0x021F36E8 thumb ov037
 *   ov037_id 0x00000025 data a1
 */
extern char ov037_id[];
extern void *func_0215A5DC(void *a0);
extern unsigned int func_02159B10(void *a0, void *a1);
extern int func_02034AC4(int);
extern void func_02034A5C(int);
extern void func_021F36E8(void *, int);

int func_0215CD80(void *a, void *b)
{
    void *p = func_0215A5DC(b);
    int v = func_02159B10(a, b);
    func_02034AC4((int)ov037_id);
    func_021F36E8(p, v);
    func_02034A5C((int)ov037_id);
    return 0;
}
