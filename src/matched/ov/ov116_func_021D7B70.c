/*
 * function: func_021D7B70
 * address: 0x021D7B70
 * packet: pkt_ov116_021D7B70
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: incoming heap in r1 is forwarded unchanged to 021D821C.
 * evidence: 0203101C's second parameter is wide here: original 021D7C26
 * copies full r6 to r1 with no truncation; its definition stores the low halfword.
 * symbols:
 *   func_021D821C 0x021D821C thumb ov116
 *   func_021D7D0C 0x021D7D0C thumb ov116
 *   func_020450F0 0x020450F0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0203101C 0x0203101C arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0203D34C 0x0203D34C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_021D821C(int, u32);
extern void func_021D7D0C(u8 *, u32);
extern void *func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern void func_0201F73C(void *, int, u16, int);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
extern void func_02041B6C(u32);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_0203101C(u32, u32, u32, u32);
extern void func_020434DC(u32, u32);
extern void func_02043598(u32, u32);
extern void func_0203D34C(u32, u32);
#define P(k) (*(void **)(p + (k)))
void func_021D7B70(u8 *p, u32 heap)
{
    P(8) = func_021D821C(1, heap);
    *(u16 *)(p + 4) = heap;
    func_021D7D0C(p, heap);
    P(0x97c) = func_020450F0(1, 1, 19, 30, 4, 12, 1);
    func_0201F73C(P(0x97c), 1, *(u32 *)(p + 0x984), 13);
    func_02043B5C(func_02045770(P(0x97c)), 15);
    func_02045374(P(0x97c));
    func_02045334(P(0x97c));
    func_02041B6C(1);
    P(0x990) = func_02045B38(0, 2, 206, heap);
    P(0x994) = func_0201EC64(heap);
    P(0x998) = func_0201D7EC(23, 0, 0, 0, heap);
    P(0x99c) = func_020457B0(128, heap);
    P(0x9a0) = func_020457B0(128, heap);
    P(0x9a8) = func_0203101C(heap, heap, 1, 0);
    *(u32 *)p = 1;
    func_020434DC(16, 1);
    func_02043598(16, 1);
    func_0203D34C(1, heap);
}
