/*
 * function: func_021B3B14
 * address:  0x021B3B14
 * packet:   pkt_ov021_021B3B14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B3B14 0x021B3B14 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0203101C 0x0203101C arm
 *   func_02045EC0 0x02045EC0 arm
 */

typedef unsigned short u16;

typedef unsigned int   u32;
struct MsgBank;
struct Tcbl;
struct U16Vec;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct Tcbl *func_0203101C(u32 heap, u16 tag, u32 count, u32 workSize);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);

int func_021B3B14(char *p, int a)
{
    *(void **)(p + 392) = func_02045B38(0, 3, 423, *(u16 *)(p + 4));
    *(void **)(p + 396) = func_02045B38(0, 2, 53, *(u16 *)(p + 4));
    *(void **)(p + 400) = func_0201EC64(*(u16 *)(p + 4));
    *(void **)(p + 408) = func_020457B0(200, *(u16 *)(p + 4));
    *(void **)(p + 436) = func_0203101C(*(u16 *)(p + 4), *(u16 *)(p + 4), 32, 32);
    *(void **)(p + 412) = func_02045EC0(*(void **)(p + 392), 29);
    return a;
}
