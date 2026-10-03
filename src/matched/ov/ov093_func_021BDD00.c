/*
 * function: func_021BDD00
 * address:  0x021BDD00
 * packet:   pkt_ov093_021BDD00
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C6190  0x021C6190  thumb  ov093
 *   func_021BD0C0  0x021BD0C0  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021BDD7C  0x021BDD7C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Fl { u8 f : 1; };
extern int func_021C6190(u8 *p, u8 *a);
extern int func_021BD0C0(u8 *p, u8 x, u32 y);
extern u8 func_021D5440(u8 *p);
extern int func_021D5B68(void *p);
extern void func_021BDD7C(u8 *p, u8 *a, u32 c);

int func_021BDD00(u8 *p, u8 *a, int c)
{
    u32 n, i;
    if (c == 0) {
        n = func_021C6190(p, a);
        if (n != 0) {
            ((struct Fl *)(p + 0x78A))->f = 1;
            for (i = 0; i < n; i++) {
                func_021BD0C0(p, p[0x78B + i], func_021D5440(a));
                if (func_021D5B68(a)) break;
            }
            ((struct Fl *)(p + 0x78A))->f = 0;
        }
    }
    if (func_021D5B68(a) == 0) {
        func_021BDD7C(p, a, 0x26C);
        return 1;
    }
    return 0;
}
