/*
 * function: func_021C031C
 * address:  0x021C031C
 * packet:   pkt_ov093_021C031C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D61A8  0x021D61A8  thumb  ov093
 *   func_021C5620  0x021C5620  thumb  ov093
 *   func_021C54C8  0x021C54C8  thumb  ov093
 *   func_021D7AF0  0x021D7AF0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Slot;
extern u8 func_021D5440(u8 *p);
extern void func_021CD64C(void *w, u8 id, ...);
extern int func_021D62C4(u8 *p, int i);
extern int func_021D61A8(u8 *p);
extern void func_021C5620(u8 *p, u8 *a, int k, struct Slot *out);
extern void func_021C54C8(u8 *p, u8 *a);
extern int func_021D7AF0(u32 pct);
int func_021C031C(u8 *p, u8 *a)
{
    int k = 6;
    if (*(int *)(p + 0x1F78) == 3) {
        func_021CD64C(*(void **)(p + 0xc), 0x5a, 0xbc, func_021D5440(a), 0xffff0000);
        return 1;
    }
    if (func_021D62C4(a, k) != 0) {
        if (func_021D61A8(a) != 0) {
            func_021C5620(p, a, k, 0);
            func_021CD64C(*(void **)(p + 0xc), 0x5b, 0x15f, func_021D5440(a), 0xffff0000);
            return 0;
        }
        func_021C54C8(p, a);
        return func_021D7AF0(50);
    }
    return 0;
}
