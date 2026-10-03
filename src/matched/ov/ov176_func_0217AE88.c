/*
 * function: func_0217AE88
 * address:  0x0217AE88
 * packet:   pkt_ov176_0217AE88
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E8A78  0x021E8A78  thumb  ov093
 *   func_0217AF9C  0x0217AF9C  thumb  ov176
 *   func_0217AF44  0x0217AF44  thumb  ov176
 *   func_0217AF04  0x0217AF04  thumb  ov176
 *   func_02034A5C  0x02034A5C  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   ov177_id       0x000000B1  data
 *   ov67_id        0x00000043  data
 */

extern void func_021E8A78(int);
extern void func_0217AF9C(int *);
extern void func_0217AF44(int *);
extern void func_0217AF04(int *);
extern void func_02034A5C(int);
extern void func_020315D4(int);
extern void func_020306F0(int);
extern char ov177_id[];
extern char ov67_id[];

int func_0217AE88(int a, int b, int c, int *p)
{
    func_021E8A78(*(int *)((char *)p + 4));
    func_0217AF9C(p);
    func_0217AF44(p);
    func_0217AF04(p);
    func_02034A5C((int)ov177_id);
    func_02034A5C((int)ov67_id);
    func_020315D4(a);
    func_020306F0(0x4e);
    return 1;
}
