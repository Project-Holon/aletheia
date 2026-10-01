/*
 * function: func_021F168C
 * address: 0x021F168C
 * packet: pkt_ov194_021F168C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F5354 0x021F5354 thumb ov194
 *   func_021F3ED0 0x021F3ED0 thumb ov194
 *   func_021F3D54 0x021F3D54 thumb ov194
 *   func_021F31B8 0x021F31B8 thumb ov194
 *   func_021F4D78 0x021F4D78 thumb ov194
 *   func_021F1F7C 0x021F1F7C thumb ov194
 *   func_021F4608 0x021F4608 thumb ov194
 *   func_021F42A0 0x021F42A0 thumb ov194
 *   func_021F1968 0x021F1968 thumb ov194
 *   func_021F1878 0x021F1878 thumb ov194
 *   func_021F4B84 0x021F4B84 thumb ov194
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02025588 0x02025588 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021F5354(u8 *);
extern void func_021F3ED0(u8 *);
extern void func_021F3D54(u8 *);
extern void func_021F31B8(u8 *);
extern void func_02045808(void *);
extern void func_021F4D78(u8 *);
extern void func_021F1F7C(u8 *);
extern void func_021F4608(u8 *);
extern void func_021F42A0(u8 *);
extern void func_021F1968(u8 *);
extern int func_021F1878(u8 *);
extern void func_02025588(void *);
extern void func_021F4B84(void *);
extern void func_0201ED04(void *);
extern void func_02045C04(void *);
extern void func_0201C6EC(void *);
extern void func_0201C4C0(void *);
extern void func_0201D83C(void *);
extern void func_020315D4(void *);
extern void func_020306F0(u32);
int func_021F168C(void *a,u32 b,u32 c,u8 *d)
{
    func_021F5354(*(u8 **)(d+716));
    func_021F3ED0(d+596);
    func_021F3D54(d+560);
    func_021F31B8(d+252);
    func_02045808(*(void **)(d+720));
    func_021F4D78(*(u8 **)(d+556));
    func_021F1F7C(d+104);
    func_021F4608(d+672);
    func_021F42A0(d+612);
    func_021F1968(d+4);
    func_021F1878(d+100);
    func_02025588(*(void **)(d+704));
    func_021F4B84(*(void **)d);
    func_0201ED04(*(void **)(d+700));
    func_02045C04(*(void **)(d+696));
    func_0201C6EC(*(void **)(d+692));
    func_0201C4C0(*(void **)(d+692));
    func_0201D83C(*(void **)(d+688));
    func_020315D4(a);
    func_020306F0(30);
    return 1;
}
