/*
 * function: func_021BE20C
 * address: 0x021BE20C
 * packet: pkt_ov208_021BE20C
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02061CA4 0x02061CA4 arm
 *   tbl_020A1B38 0x020A1B38 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Ov208Pal {
    char pad[0xb6];
    u16 a[16];
    u16 b[16];
    u16 out[16];
    int phase;
};
extern s16 tbl_020A1B38[];
typedef signed int     s32;
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
void func_021BE20C(struct Ov208Pal *m)
{
    s16 t;
    u8 i;
    if (m->phase + 0x400 >= 0x10000)
        m->phase -= 0xfc00;
    else
        m->phase += 0x400;
    t = (tbl_020A1B38[2 * (m->phase >> 4) + 1] + 0x1000) / 2;
    for (i = 0; i < 16; i++) {
        u16 c1 = m->a[i];
        u16 c2 = m->b[i];
        u8 r1 = c1 & 0x1f;
        u8 g1 = (c1 & 0x3e0) >> 5;
        u8 b1 = (c1 & 0x7c00) >> 10;
        u8 r2 = c2 & 0x1f;
        u8 g2 = (c2 & 0x3e0) >> 5;
        u8 b2 = (c2 & 0x7c00) >> 10;
        u8 r = r1 + ((r2 - r1) * t >> 12);
        u8 g = g1 + ((g2 - g1) * t >> 12);
        u8 b = b1 + ((b2 - b1) * t >> 12);
        m->out[i] = r | g << 5 | b << 10;
    }
    func_02061CA4((void *)14, 0x1a0, (u32)m->out, 0x20);
}
