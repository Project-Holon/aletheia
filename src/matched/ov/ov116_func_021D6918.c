/*
 * function: func_021D6918
 * address: 0x021D6918
 * packet: pkt_ov116_021D6918
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D730C 0x021D730C thumb ov116
 *   func_021D73D0 0x021D73D0 thumb ov116
 *   func_021D7420 0x021D7420 thumb ov116
 *   func_021D6B70 0x021D6B70 thumb ov116
 *   func_021D7C58 0x021D7C58 thumb ov116
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov_id 0x00000072 data
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb  arm9
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb  arm9
 *   GFL_USE_PopBgm  0x02005E9C  thumb  arm9
 */
typedef unsigned char u8;
struct S020315D4;
extern void func_021D730C(u8 *p);
extern void func_021D73D0(void *);
extern void func_021D7420(void *);
extern void func_021D6B70(unsigned char *a);
extern void func_021D7C58(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int);
extern void func_02034A5C(int handle);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_SetBgmPlayerParam(void *);
extern void GFL_USE_FadeInBgmFull(unsigned);
extern u8 ov_id[];
int func_021D6918(void *p, int a, int b, u8 *q) {
    func_021D730C(q);
    func_021D73D0(q);
    func_021D7420(q);
    func_021D6B70(q + 0x1610);
    func_021D7C58(q + 4);
    func_020315D4(p);
    func_020306F0(125);
    func_02034A5C((int)ov_id);
    GFL_USE_PopBgm();
    GFL_USE_SetBgmPlayerParam(0);
    GFL_USE_FadeInBgmFull(60);
    return 1;
}
