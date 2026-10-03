/*
 * function: func_021E18EC
 * address:  0x021E18EC
 * packet:   pkt_ov093_021E18EC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D69AC  0x021D69AC  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern u8 func_021D69AC(u8 *a, int i);
extern int func_021D76BC(int key, u32 val);

void func_021E18EC(int a, void *p, int id)
{
    int two = 2;
    int v;
    if (id == func_021D775C(2)) {
        switch (func_021D69AC(func_021C7CF4(p, id), 0)) {
        case 1:
        default:
            v = 1 << 10;
            break;
        case 2:
            v = two << 10;
            break;
        case 3:
            v = two << 11;
            break;
        }
        func_021D76BC(0x35, v);
    }
}
