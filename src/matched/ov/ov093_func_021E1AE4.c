/*
 * function: func_021E1AE4
 * address:  0x021E1AE4
 * packet:   pkt_ov093_021E1AE4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D6940  0x021D6940  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_0201C1E8  0x0201C1E8  thumb
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct Ent { u16 a; u16 b; u8 c; u8 d; u8 e; u8 f; } Ent;

extern u8 func_021D5440(void *m);
extern int func_021D6940(void *m, int a, int b, Ent *out);
extern int func_021B9A24(u8 c, int k);
extern int func_0201C1E8(u16 x);

int func_021E1AE4(void *m, int x, Ent *out)
{
    u8 q = func_021D5440(m);
    u8 i = 0;
    while (func_021D6940(m, 0, i++, out)) {
        if (func_021B9A24(q, out->d) == 0) {
            if (x == 0 || x == func_0201C1E8(out->a))
                return 1;
        }
    }
    return 0;
}
