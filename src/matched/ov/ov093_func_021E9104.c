/*
 * function: func_021E9104
 * address:  0x021E9104
 * packet:   pkt_ov093_021E9104
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F745C  0x021F745C  thumb  ov094
 *   func_021F7544  0x021F7544  thumb  ov094
 *   func_020307B0  0x020307B0  arm
 *   func_021EB028  0x021EB028  thumb  ov093
 *   func_021E91C8  0x021E91C8  thumb  ov093
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021EB32C  0x021EB32C  thumb  ov093
 *   func_021EB52C  0x021EB52C  thumb  ov093
 *   func_021CD9C8  0x021CD9C8  thumb  ov093
 *   func_021CD9DC  0x021CD9DC  thumb  ov093
 *   func_021E91D8  0x021E91D8  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Param;

extern void *func_021F745C(u8 *p, int a, u16 heap);
extern void func_021F7544(void *p, int arg, u16 heap);
extern void func_020307B0(void *p);
extern void func_021EB028(u8 *p);
extern void func_021E91C8(void *p);
extern u32 func_021CD9E0(u8 *p);
extern void func_021EB32C(u8 *p, u32 flag);
extern int func_021EB52C(u8 *p);
extern u32 func_021CD9C8(u8 *p);
extern u16 func_021CD9DC(u8 *p);
extern void func_021E91D8(void *a, void *b);

int func_021E9104(u8 *p, int *st)
{
    void *r;

    switch (*st) {
    case 0:
        r = func_021F745C(*(u8 **)p, *(int *)(p + 0x17c), *(u16 *)(p + 0x184));
        func_021F7544(r, *(int *)(p + 0xb4), *(u16 *)(p + 0x184));
        func_020307B0(r);
        func_021EB028(*(u8 **)(p + 0x17c));
        func_021E91C8(*(void **)(p + 0x180));
        (*st)++;
        break;
    case 1:
        func_021EB32C(*(u8 **)(p + 0x17c), func_021CD9E0(*(u8 **)(p + 4)));
        (*st)++;
        break;
    case 2:
        if (func_021EB52C(*(u8 **)(p + 0x17c)) != 0) {
            if (func_021CD9C8(*(u8 **)(p + 4)) != 0) {
                *(int *)(p + 0x160) = 1;
                *(int *)(p + 0x164) = 1;
                *(u32 *)(p + 0x168) = func_021CD9DC(*(u8 **)(p + 4));
                *(int *)(p + 0x16c) = 0;
                if (func_021CD9E0(*(u8 **)(p + 4)) == 0) {
                    func_021E91D8(*(void **)(p + 0x180), p + 0x160);
                }
            }
            return 1;
        }
        break;
    }
    return 0;
}
