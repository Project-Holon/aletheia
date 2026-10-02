/*
 * function: func_021C13E8
 * address:  0x021C13E8
 * packet:   pkt_ov217_021C13E8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Note 2026-10-02: DIFF draft (GX FIFO writes: 0x040004A4 polygon attr, +0x5C BEGIN_VTXS,
 * -0x24 COLOR, -0x18 VTX_16, +0x60 END_VTXS). Structure decoded, compiles to 252 vs 244 bytes;
 * original spills six base+offset address constants to the stack. Needs an Opus pass.
 *
 * symbols:
 *   func_021C1D28  0x021C1D28  thumb  ov217
 *   func_021C1AB4  0x021C1AB4  thumb  ov217
 *   func_021C1B28  0x021C1B28  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

extern int func_021C1D28(u8 *p);
extern u8 *func_021C1AB4(u8 *p, int i);
extern void func_021C1B28(u8 *e, u8 *a, u8 *b);

void func_021C13E8(u8 *p)
{
    u8 b[2];
    volatile u32 *r;
    u8 *e;
    u8 *q;
    int n;
    int i;
    s16 x;
    s16 y;

    if (func_021C1D28(p) == 0) {
        r = (volatile u32 *)0x040004A4;
        *r = 0x001F00C0;
        n = p[0x1AC];
        for (i = 0; i < n; i++) {
            e = func_021C1AB4(p, i);
            func_021C1B28(e, &b[1], &b[0]);
            if (e[8] >= 3) {
                q = p + b[1] * 6;
                x = *(s16 *)(p + 0x1B4) + *(s16 *)(q + 0x1BA);
                y = *(s16 *)(p + 0x1B6) + *(s16 *)(q + 0x1BC);
                *(volatile u32 *)((u32)r + 0x5C) = 0;
                *(volatile u32 *)((u32)r - 0x24) = 0;
                u32 va = ((u32)(u16)*(s16 *)(p + 0x1B6) << 16) | (u16)*(s16 *)(p + 0x1B4);
                u32 vb = ((u32)(u16)y << 16) | (u16)x;
                *(volatile u32 *)((u32)r - 0x18) = va;
                *(volatile u32 *)((u32)r - 0x18) = (u32)r >> 12;
                *(volatile u32 *)((u32)r - 0x18) = va;
                *(volatile u32 *)((u32)r - 0x18) = (u32)r >> 12;
                *(volatile u32 *)((u32)r - 0x18) = vb;
                *(volatile u32 *)((u32)r - 0x18) = (u32)r >> 12;
                *(volatile u32 *)((u32)r + 0x60) = 0;
            }
        }
    }
}
