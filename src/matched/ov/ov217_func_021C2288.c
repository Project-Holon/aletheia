/*
 * function: ARROW_BuildParts
 * address:  0x021C2288
 * packet:   pkt_ov217_021C2288
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Element i of a 0x18-byte array at p+0x28; the half==0 flag stores are
 * written through that element base (p + 0x28 + i*0x18 + 8 / + 0xc). Colours
 * come from f += 1.0f (f first in _fadd), i declared before f with i = 0 as a
 * statement, half2 declared before w2, and y += 8 before f += 1.0f.
 * EXACT* = 690 bytes compiled, listing extent 692 (trailing pad).
 *
 * symbols:
 *   ARROW_InitPart  0x021C253C  thumb  ov217
 *   _ffixu  0x0209C4C8  arm
 *   _fadd   0x0209C95C  arm
 *   _fsub   0x0209CB8C  arm
 *   _fmul   0x0209C77C  arm
 *   _fdiv   0x0209CE10  arm
 *   _fflt   0x0209BDBC  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void ARROW_InitPart(void *p, u8 a, u8 b, u32 c, u32 d);

void ARROW_BuildParts(u8 *p, int a, int b, int c, int d)
{
    int i;
    float f = 0.0f;
    int j;
    int yb;
    int w = a - c;
    int half = (w - 4) / 8;
    int half2;
    int w2;
    int xx;
    int y;
    int r;

    i = 0;
    yb = b - 4;
    a -= 8;

    for (j = 0; j < half; j++) {
        ARROW_InitPart(p + 0x28 + i * 0x18, a, yb, (u32)f, 0);
        a -= 8;
        f += 1.0f;
        i++;
    }
    if (half == 0) {
        if (w - 4 > 0) {
            ARROW_InitPart(p + 0x28 + i * 0x18, a, yb, (u32)f, 0);
            if (w - 4 < 4) {
                *(u32 *)(p + 0x28 + i * 0x18 + 8) = 1;
                *(u16 *)(p + 0x28 + i * 0x18 + 0xc) = 1;
            }
            f = f + (2.0f * (float)(w - 4) / 8.0f - 1.0f);
            i++;
        }
    } else if ((w - 4) % 8 != 0) {
        r = (w - 4) - half * 8;
        f = f - (2.0f - 2.0f * (float)r / 8.0f);
        ARROW_InitPart(p + 0x28 + i * 0x18, c + 4, yb, (u32)f, 0);
        f += 1.0f;
        i++;
    }
    ARROW_InitPart(p + 0x28 + i * 0x18, c - 4, b - 4, (u32)f, 2);
    f += 1.0f;
    i++;
    w2 = d - b;
    half2 = (w2 - 4) / 8;
    xx = c - 4;
    y = b + 4;
    for (j = 0; j < half2; j++) {
        ARROW_InitPart(p + 0x28 + i * 0x18, xx, y, (u32)f, 1);
        y += 8;
        f += 1.0f;
        i++;
    }
    if ((w2 - 4) % 8 != 0) {
        r = (w2 - 4) - half2 * 8;
        f = f - (2.0f - 2.0f * (float)r / 8.0f);
        ARROW_InitPart(p + 0x28 + i * 0x18, xx, d - 8, (u32)f, 1);
        f += 1.0f;
        i++;
    }
    ARROW_InitPart(p + 0x28 + i * 0x18, c - 4, d - 4, (u32)f, 3);
    p[0x298] = i + 1;
}
