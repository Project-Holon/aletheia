/*
 * function: func_021BAE28
 * address:  0x021BAE28
 * packet:   pkt_ov068_021BAE28
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA31C  0x021BA31C  thumb  ov068
 *   func_02027778  0x02027778  thumb
 *   func_02027974  0x02027974  thumb
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_02027858  0x02027858  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct TaskMenu;
extern int func_021BA31C(u8 *p);
extern void *func_02027778(void *tmpl, void *arg1);
extern void  func_02027974(void *p);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8    func_02027A04(const u8 *p);
extern void func_02027858(struct TaskMenu *m);

void func_021BAE28(u8 *p)
{
    switch (*(u16 *)(p + 0x56)) {
    case 0:
        if (func_021BA31C(p) != 0) {
            *(u16 *)(p + 0x56) = 1;
        }
        break;
    case 1:
        *(void **)(p + 0x38) = func_02027778(p + 0x58, *(void **)(p + 0x6c));
        *(u16 *)(p + 0x56) = 2;
        break;
    case 2:
        func_02027974(*(void **)(p + 0x38));
        if (func_020279E8(*(void **)(p + 0x38)) != 0) {
            *(u16 *)(p + 0x54) = func_02027A04(*(u8 **)(p + 0x38)) + 1;
            *(u16 *)(p + 0x56) = 3;
            func_02027858(*(void **)(p + 0x38));
        }
        break;
    }
}
