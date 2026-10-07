/*
 * function: func_021BA04C
 * address:  0x021BA04C
 * packet:   pkt_ov099_021BA04C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note (2026-10-04): func_021C4864 is declared as returning a pointer: int, u32 and u16 returns give cmp r1,r0 (operands swapped); a pointer return compared with (void *)(lo+7) gives the original cmp r0,r1.
 *
 * symbols:
 *   func_021C47F8  0x021C47F8  thumb  ov127
 *   func_021C47FC  0x021C47FC  thumb  ov127
 *   func_021C4864  0x021C4864  thumb  ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_021C47F8(u16 *p);
extern u16 func_021C47FC(u16 *p);
extern void *func_021C4864(void *o, u16 x, u16 y);

void func_021BA04C(char *p, u16 *out, u32 c)
{
    u32 y, h, x, w;
    u32 hi = c >> 3;
    u32 lo = c & 7;

    w = func_021C47F8(*(void **)(p + 0x588));
    h = func_021C47FC(*(void **)(p + 0x588));
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            if (func_021C4864(*(void **)(p + 0x588), x, y) == (void *)(lo + 7)
                && func_021C4864(*(void **)(p + 0x588), x, y + 1) == (void *)(hi + 3)) {
                out[0] = x << 4;
                out[1] = y << 4;
                return;
            }
        }
    }
}
