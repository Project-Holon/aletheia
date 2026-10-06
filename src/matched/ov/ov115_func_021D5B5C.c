/*
 * function: func_021D5B5C
 * address: 0x021D5B5C
 * packet: pkt_ov115_021D5B5C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_021D5FA0 0x021D5FA0 thumb ov115
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02028470 0x02028470 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 * note 2026-10-05 (wD9r lane A6): first read of the field at +0x50 is an int read, later reads u32; the same-type form gets CSE'd and loads r1 for +0x2c. Row set after the first call.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
struct Descriptor;
struct CharBuf;
struct Cfg;
struct Rec3;
extern void func_02045CAC(struct MsgBank *, u32, void *);
extern u32 func_021D5FA0(u32);
extern u32 func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *, u8);
extern void func_0201DD78(u32, u32, u32);
extern void func_02028470(u8 *p, u32 v);
extern void func_0201CE48(struct Rec3 *);
extern signed char func_02012FFC(void);
extern u32 func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern void func_02041B6C(u32);
void func_021D5B5C(char *p, struct MsgBank *a, int b)
{
    int row;
    int kind;
    u32 w;
    func_02045CAC(a, b, *(void **)(p + 0x28));
    row = 1;
    if (*(int *)(p + 0x50) != 0) row = 19;
    if (*(u32 *)(p + 0x2c) == 0) {
        *(u32 *)(p + 0x2c) = func_020450F0(func_021D5FA0(*(u32 *)(p + 0x50)), 1, row, 30, 4, 11, 1);
    }
    w = *(u32 *)(p + 0x2c);
    func_02043B5C((struct CharBuf *)func_02045770((struct Descriptor *)w), 15);
    func_0201DD78(1, 2, 15);
    kind = 2;
    if (*(u32 *)(p + 0x50) == 0) kind = 6;
    func_02028470((u8 *)(p + 0x3c), (int)kind);
    if (*(u32 *)(p + 0x38) != 0) func_0201CE48(*(struct Rec3 **)(p + 0x38));
    *(u32 *)(p + 0x38) = func_0201CCE4(w, 0, 0, *(u32 *)(p + 0x28), *(u32 *)(p + 0x24), func_02012FFC(), *(u32 *)(p + 0x44), 2, *(u16 *)(p + 0x4c), 15);
    func_0201F73C((void *)w, 1, (u16)(*(u32 *)p), 12);
    func_02045334((struct Descriptor *)w);
    func_02045374((struct Cfg *)w);
    func_02041B6C(func_021D5FA0(*(u32 *)(p + 0x50)));
}
