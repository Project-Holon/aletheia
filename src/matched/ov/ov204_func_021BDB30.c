/*
 * function: func_021BDB30
 * address:  0x021BDB30
 * packet:   pkt_ov204_021BDB30
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BEF88  0x021BEF88  thumb  ov204
 *   func_021BDD4C  0x021BDD4C  thumb  ov204
 *   func_021BDD60  0x021BDD60  thumb  ov204
 *   func_021BF898  0x021BF898  thumb  ov204
 *   func_021BF610  0x021BF610  thumb  ov204
 *   func_021BFCE0  0x021BFCE0  thumb  ov204
 *   func_021BF9FC  0x021BF9FC  thumb  ov204
 *   func_021BDD6C  0x021BDD6C  thumb  ov204
 */

typedef unsigned char  u8;
extern int func_021BEF88(char *p);
extern void func_021BDD4C(u8 *p);
extern void func_021BDD60(char *p);
extern void func_021BF898(char *p);
extern void func_021BF610(u8 *p);
extern void func_021BFCE0(int);
extern void func_021BF9FC(char *p);
extern void func_021BDD6C(char *p);

int func_021BDB30(int a, int b, int c, void *p)
{
    if (func_021BEF88((char *)(*(int *)((char *)p + 0x14))) == 0) {
        return 1;
    }
    func_021BDD4C((u8 *)(*(int *)((char *)p + 8)));
    func_021BDD60((char *)(*(int *)((char *)p + 8)));
    func_021BF898((char *)(*(int *)((char *)p + 0x18)));
    func_021BF610((u8 *)(*(int *)((char *)p + 0x18)));
    func_021BFCE0(*(int *)((char *)p + 0x20));
    func_021BF9FC((char *)(*(int *)((char *)p + 0x1c)));
    func_021BDD6C((char *)(*(int *)((char *)p + 8)));
    return 0;
}
