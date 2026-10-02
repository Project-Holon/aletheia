/*
 * function: func_021BDE94
 * address: 0x021BDE94
 * packet: pkt_ov099_021BDE94
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototypes: 49238 SDK asm reads r0 despite its void(void) declaration; caller-visible handle preserved. Empty 021BE5B4 preserves caller-loaded live r0; 021BE5B8 preserves visible r1 despite no body read.
 * volatile: RMW display registers read at 021BDEB4/021BDEC0 and written at 021BDEBC/021BDEC4.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049238 0x02049238 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0204363C 0x0204363C arm
 *   func_021BE030 0x021BE030 thumb ov099
 *   func_021BE040 0x021BE040 thumb ov099
 *   func_02045088 0x02045088 arm
 *   func_021BE53C 0x021BE53C thumb ov099
 *   func_021BE028 0x021BE028 thumb ov099
 *   func_020056A0 0x020056A0 thumb
 *   func_021BE5B4 0x021BE5B4 thumb ov099
 *   func_021BE5B8 0x021BE5B8 thumb ov099
 *   func_020434DC 0x020434DC arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02030EAC(void *);
extern void func_02043534(u32);
extern void func_020435F4(u32);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049238(void *);
extern void *func_0201EC64(u32);
extern void *func_02045B38(u32, u32, u32, u32);
extern void *func_0201D7EC(int, int, int, int, u32);
extern void func_0204363C(u32);
extern void func_021BE030(void);
extern void func_021BE040(int);
extern void func_02045088(u16);
extern void func_021BE53C(char *, void *);
extern void func_021BE028(void);
extern void *func_020056A0(u32, u32, u32);
extern void func_021BE5B4(void *);
extern void func_021BE5B8(char *, void *);
extern void func_020434DC(u32, u32);
void func_021BDE94(char *p)
{
    void *h;
    if (*(void **)p != 0) func_02030EAC(*(void **)p);
    func_02043534(0);
    func_020435F4(0);
    *(volatile u32 *)0x04000000 &= 0xffffe0ff;
    *(volatile u32 *)0x04001000 &= 0xffffe0ff;
    h = func_020490F4(0x21, 0x21);
    *(void **)(p + 0xdc) = func_0201EC64(0x21);
    *(void **)(p + 0xe0) = func_02045B38(0, 2, 0xd1, 0x21);
    *(void **)(p + 0xe4) = func_02045B38(0, 2, 0xe8, 0x21);
    *(void **)(p + 0xe8) = func_0201D7EC(0x17, 0, 0, 0, 0x21);
    *(void **)(p + 0xec) = func_0201D7EC(0x17, 3, 0, 0, 0x21);
    func_0204363C(1);
    func_021BE030();
    func_021BE040(0x21);
    func_02045088(0x21);
    func_021BE53C(p, h);
    *(void **)p = func_020056A0((u32)func_021BE028, (u32)p, 1);
    func_021BE5B4(*(void **)p);
    func_021BE5B8(p, h);
    func_020434DC(0x10, 1);
    func_02049238(h);
}
