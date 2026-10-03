/*
 * function: func_021F2908
 * address:  0x021F2908
 * packet:   pkt_ov032_021F2908
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F2908  0x021F2908  thumb
 *   func_021F2664  0x021F2664  thumb  ov032
 *   func_0203101C  0x0203101C  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_02021518  0x02021518  thumb
 *   func_0202155C  0x0202155C  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_0201C4C8  0x0201C4C8  thumb
 *   func_0201C4DC  0x0201C4DC  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_0201DD68  0x0201DD68  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_020457B0  0x020457B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct MsgBank;
struct Tcbl;
struct U16Vec;
struct WordSet;
extern void func_021F2664(int a, char *p);
extern struct Tcbl *func_0203101C(u32 heap, u16 tag, u32 count, u32 workSize);
extern void *func_020056A0(void *fn, void *ctx, u32 a);
extern u32 func_02021518(u32 heap);
extern void func_0202155C(u32 h, u32 a, u32 b, u32 heap);
extern u32 func_0201C440(u32 heap);
extern void func_0201C4C8(u32 p, u8 v);
extern void func_0201C4DC(u32 p, u32 a, u32 b);
extern u32 func_02188C54(u32 a);
extern u32 func_021904AC(u32 a);
extern void func_0201DD68(void);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);

void func_021F2908(char *p)
{
    *(void **)(p + 0xa0) = func_0203101C(*(u16 *)(p + 0x98), *(u16 *)(p + 0x98), 0x10, 0x80);
    *(void **)(p + 0xa4) = func_020056A0((void *)func_021F2664, p, 0);
    *(u32 *)(p + 0xac) = func_02021518(*(u16 *)(p + 0x98));
    func_0202155C(*(u32 *)(p + 0xac), 1, 0x1c0, *(u16 *)(p + 0x98));
    func_0202155C(*(u32 *)(p + 0xac), 3, 0x200, *(u16 *)(p + 0x98));
    *(u32 *)(p + 0xb4) = func_0201C440(*(u16 *)(p + 0x98));
    func_0201C4C8(*(u32 *)(p + 0xb4), 1);
    func_0201C4DC(*(u32 *)(p + 0xb4), 0x1f4, 0);
    *(u32 *)(p + 0xb0) = func_021904AC(func_02188C54(*(u32 *)(p + 8)));
    func_0201DD68();
    *(void **)(p + 0x110) = func_0201EC64(*(u16 *)(p + 0x98));
    *(void **)(p + 0x114) = func_02045B38(1, 2, 8, *(u16 *)(p + 0x98));
    *(void **)(p + 0x118) = func_020457B0(0xd9, *(u16 *)(p + 0x98));
    *(void **)(p + 0x11c) = func_020457B0(0xd9, *(u16 *)(p + 0x98));
    *(void **)(p + 0x120) = func_020457B0(0xd9, *(u16 *)(p + 0x98));
}
