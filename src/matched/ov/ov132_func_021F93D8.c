/*
 * function: func_021F93D8
 * address: 0x021F93D8
 * packet: pkt_ov132_021F93D8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201C6FC 0x0201C6FC thumb
 * abi: 0201CCE4 forwards the pointer result of matched 0201CD10; the caller stores it at d8.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { ZERO } Zero;
extern void func_0201CE48(void *);
extern void func_02045808(void *);
extern void *func_02045770(void *);
extern void func_02043B5C(void *, u8);
extern void *func_02045EC0(void *, u32);
extern void *func_0201CCE4(void *, u32, u32, void *, void *, u32, void *, u32, u16, u32);
extern void func_0201C6FC(void *, void *, int, int, void *, u32);
void func_021F93D8(u8 *p, u32 index, u32 speed)
{
    Zero zero;
    if (*(void **)(p + 0xD8)) {
        func_0201CE48(*(void **)(p + 0xD8));
        *(void **)(p + 0xD8) = 0;
    }
    if (*(void **)(p + 0xE0)) {
        func_02045808(*(void **)(p + 0xE0));
        *(void **)(p + 0xE0) = 0;
    }
    func_02043B5C(func_02045770(*(void **)(p + 0xD0)), 0);
    zero = ZERO;
    *(void **)(p + 0xE0) = func_02045EC0(*(void **)(p + 0xDC), index);
    if (speed != 255) {
        *(void **)(p + 0xD8) = func_0201CCE4(*(void **)(p + 0xD0), zero, zero,
            *(void **)(p + 0xE0), *(void **)(p + 0xD4), speed,
            *(void **)(p + 0xCC), 2, *(u16 *)p, zero);
    } else {
        func_0201C6FC(*(void **)(p + 0xE8), func_02045770(*(void **)(p + 0xD0)),
            zero, zero, *(void **)(p + 0xE0), *(u32 *)(p + 0xD4));
        *(int *)(p + 0xE4) = 1;
        func_02045808(*(void **)(p + 0xE0));
        *(void **)(p + 0xE0) = (void *)zero;
    }
}
