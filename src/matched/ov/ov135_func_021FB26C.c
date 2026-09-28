/*
 * function: func_021FB26C
 * address:  0x021FB26C
 * packet:   pkt_021FB26C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
  *
  *
 * symbols:
 *   func_021F8498  0x021F8498  thumb
 *   func_021F84BC  0x021F84BC  thumb
 *   func_021FB240  0x021FB240  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u16 *func_021F8498(u32 heap, u32 unused, u32 *count);
extern void func_021F84BC(u32 i, int *start, int *end);
extern int func_021FB240(u32 unused, void *bag, u32 c, u16 *list, int start, int end);
extern void *func_0201F81C(u32 n, u32 heap);
extern u32 func_0200D064(void *bag, u16 id);
extern void func_0201F878(void *table, void *msg, u32 b, u32 tag, u32 heap);
extern void func_020307B0(void *p);

int func_021FB26C(void **menu, void *msg, void *bank, u32 x, u32 kind, void *bag)
{
    u32 count;
    int start;
    int end;
    int n;
    int i;
    u16 *list;

    list = func_021F8498(0x48, 0, &count);
    func_021F84BC(kind, &start, &end);
    count = end - start;
    n = func_021FB240(x, bag, count, list, start, end);
    *menu = func_0201F81C(n + 1, 0x48);
    for (i = start; i < end; i++) {
        if (func_0200D064(bag, list[i]) != 0) {
            func_0201F878(*menu, msg, list[i], list[i], 0x48);
        }
    }
    func_020307B0(list);
    return n;
}
