/*
 * function: func_021F00C8
 * address:  0x021F00C8
 * packet:   pkt_ov032_021F00C8
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct; blocked only by two unlabelled arm9 Thumb leaves (Ilias's,
 * no witness outside this range: label/literal/sole-ref all refuse):
 *   func_020275D0 (12 bytes, EXACT verified with `one --region arm9 --thumb`):
 *     u16 *func_020275D0(int p) { return (u16 *)(p + 0xB0C); }
 *   func_020275C4 (12 bytes, EXACT verified likewise):
 *     int func_020275C4(int p) { return *(int *)(p + 0xB08); }
 *
 * symbols:
 *   func_021F00C8  0x021F00C8  thumb
 *   func_020275D0  0x020275D0  thumb
 *   func_020275C4  0x020275C4  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_021F18C4  0x021F18C4  thumb  ov032
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u16 *func_020275D0(int);
extern void *func_020275C4(int);
extern void func_0201EE0C(void *win, u32 slot, void *str, u32 a, u32 b, u32 c);
extern void func_021F18C4(void *p, int v);

int func_021F00C8(char *p)
{
    u16 *f;

    f = func_020275D0(*(int *)(p + 0x34));
    if (*f == 0)
        return 0;
    *f = 0;
    func_0201EE0C(*(void **)(p + 0x110), 0, func_020275C4(*(int *)(p + 0x34)),
                  *(u8 *)(p + 0x30), 1, 2);
    func_021F18C4(p, 0xB);
    return 1;
}
