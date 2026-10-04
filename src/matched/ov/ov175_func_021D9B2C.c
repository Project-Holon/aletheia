/*
 * function: func_021D9B2C
 * address:  0x021D9B2C
 * packet:   pkt_ov175_021D9B2C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020173EC  0x020173EC  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_021B9A64  0x021B9A64  thumb  ov114
 *   func_021B9A94  0x021B9A94  thumb  ov114
 *   func_021B9A1C  0x021B9A1C  thumb  ov114
 *   func_021B9A8C  0x021B9A8C  thumb  ov114
 *
 * Serialises a list: allocates count records of 0x020173EC's size from heap (heap | 0x8000, top-down), copies every entry in, hands the buffer to the ov114 writer with the +0x54 block, frees it and returns the writer's result.
 *
 * Leaf: +008A func_021B9A8C resolves as matched through
 *     src/matched/ov/ov114_func_021B9A8C.c (pkt_ov114_021B9A8C), the
 *     unlabelled ov114 tail-call stub to 0x020307B0. Twin of
 *     ov175_func_021D67BC.c; 0201AA18/0201AB28 prototypes follow the
 *     matched arm9 callers (pointer list, u32 count).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_020173EC(void);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u8 *func_021B9A64(int a, int b, int c);
extern void func_021B9A94(void *buf, void *entry, u32 size, int i);
extern u32 func_021B9A1C(void *buf, u32 size, u32 count, char *dst, u16 heap);
extern void func_021B9A8C(void *buf);

u32 func_021D9B2C(char *obj, void *list, u32 heapId)
{
    int heap = (heapId & 0x7fff) | 0x8000;
    u32 size = func_020173EC();
    void *buf = func_021B9A64(size, func_0201AA18(list), (u16)heap);
    int i;
    u32 ret;

    for (i = 0; i < (int)func_0201AA18(list); i++) {
        void *e = func_0201AB28(list, i);
        func_021B9A94(buf, e, func_020173EC(), i);
    }
    size = func_020173EC();
    ret = func_021B9A1C(buf, size, func_0201AA18(list), obj + 0x54, (u16)heap);
    func_021B9A8C(buf);
    return ret;
}
