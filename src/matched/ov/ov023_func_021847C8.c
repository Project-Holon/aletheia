/*
 * function: func_021847C8
 * address:  0x021847C8
 * packet:   pkt_ov023_021847C8
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_02186694  0x02186694  thumb  ov023
 *   func_02185004  0x02185004  thumb  ov023
 *   func_02184B34  0x02184B34  thumb  ov023
 *   func_02045C04  0x02045C04  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02186558  0x02186558  thumb  ov023
 *   func_02184B04  0x02184B04  thumb  ov023
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02030EAC(u32);
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
extern void func_0204AFD8(u32);
extern void func_0204B1CC(u32);
extern void func_0204A5AC(void);
extern void func_02186694(u8 *);
extern void func_02185004(u8 *);
extern void func_02184B34(void);
extern void func_02045C04(u32);
extern void func_0201ED04(u32);
extern void func_0201D83C(u32);
extern int  func_02186558(u8 *);
extern void func_02184B04(u8 *);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(u32);

int func_021847C8(u32 a, int *seq, u8 *c, u8 *d)
{
    switch (*seq) {
    case 0:
        func_02030EAC(*(u32 *)(d + 0x08));
        func_0204A8D4(*(u32 *)(d + 0x58));
        func_0204ADA4(*(u32 *)(d + 0x54));
        func_0204AFD8(*(u32 *)(d + 0x5C));
        func_0204A8D4(*(u32 *)(d + 0x4C));
        func_0204ADA4(*(u32 *)(d + 0x48));
        func_0204AFD8(*(u32 *)(d + 0x50));
        func_0204A8D4(*(u32 *)(d + 0x40));
        func_0204ADA4(*(u32 *)(d + 0x3C));
        func_0204AFD8(*(u32 *)(d + 0x44));
        func_0204B1CC(*(u32 *)(d + 0x38));
        func_0204A5AC();
        if (*(u32 *)(d + 0x178) != 0) {
            func_02186694(d);
        }
        func_02185004(d);
        func_02184B34();
        func_02045C04(*(u32 *)(d + 0x14));
        func_0201ED04(*(u32 *)(d + 0x10));
        func_0201D83C(*(u32 *)(d + 0x0C));
        (*seq)++;
        break;
    case 1:
        (*seq)++;
        break;
    case 2:
        if (*(u32 *)(d + 0x9E78) != 0) {
            if (func_02186558(d) == 1) {
                (*seq)++;
            }
        } else {
            (*seq)++;
        }
        break;
    case 3:
        func_02184B04(d);
        func_020315D4((struct S020315D4 *)a);
        func_020306F0(0x28);
        return 1;
    }
    return 0;
}
