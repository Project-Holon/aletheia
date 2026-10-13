/*
 * function: func_021F91CC
 * address: 0x021F91CC
 * packet: pkt_ov132_021F91CC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Palette fade, 16 colours. The object holds a u16 phase at +0x168 (advanced by 0x160, wrapped at
 * 0x10000), 16 base colours at +0x16A, s8 red, green and blue deltas at +0x18A, +0x19A, +0x1AA,
 * and 16 output colours at +0x1BA. The factor is (cos table entry + 0x1000) / 2. Each channel gets
 * (s8 delta * factor >> 12) added, then the colours go to func_02061CA4(31, 0, out, 32).
 * Twins for the channel pack: ov068 021B9D68, ov104 021B89DC.
 * What closed it: a struct view of the object (p->phase, p->base[i], p->out[i]) with no colour
 * local (every channel reads p->base[i], CSE keeps one load), which makes the allocator spill p
 * instead of p + 2i; compound assignment `p->phase += 0x160` in the else wrap
 * arm (the else arm then recomputes the sum, as the image does); `u8 i` declared before
 * `int factor`. final push 2026-10-05 G9L6.
 * symbols:
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   func_02061CA4 0x02061CA4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef struct {
    u8 pad[0x168];
    u16 phase;
    u16 base[16];
    s8 dr[16];
    s8 dg[16];
    s8 db[16];
    u16 out[16];
} Fade;
extern const s16 FX_SinCosTable_[];
extern int func_02061CA4(void *, u32, u32, int);
void func_021F91CC(Fade *p)
{
    u8 i;
    int factor;
    if (p->phase + 0x160 >= 0x10000)
        p->phase = p->phase - 0xFEA0;
    else
        p->phase += 0x160;
    factor = (FX_SinCosTable_[(p->phase >> 4) * 2] + 0x1000) / 2;
    for (i = 0; i < 16; i++) {
        u8 b = (p->base[i] & 0x7C00) >> 10;
        u8 r = p->base[i] & 0x1F;
        u8 g = (p->base[i] & 0x3E0) >> 5;
        int B = b + (s8)((p->db[i] * factor) >> 12);
        int R = r + (s8)((p->dr[i] * factor) >> 12);
        int G = g + (s8)((p->dg[i] * factor) >> 12);
        p->out[i] = (B << 10) | (R | (G << 5));
    }
    func_02061CA4((void *)31, 0, (u32)p->out, 32);
}
