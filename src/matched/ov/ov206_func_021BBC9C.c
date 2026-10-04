/*
 * function: func_021BBC9C
 * address: 0x021BBC9C
 * packet: pkt_ov206_021BBC9C
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   tbl_020A1B38 0x020A1B38 data
 *   func_02061CA4 0x02061CA4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct S {
    char pad0[0x1c];
    int f1c;
    char pad20[0x194 - 0x20];
    u16 phase;
    u16 pal[5];
    u16 a[5];
    u16 b[5];
} S;
extern s16 tbl_020A1B38[];
typedef signed int     s32;
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
void func_021BBC9C(S *p)
{
    s16 f;
    u8 i;

    if (p->phase + 0x400 >= 0x10000)
        p->phase = p->phase + 0x400 - 0x10000;
    else
        p->phase += 0x400;
    f = (tbl_020A1B38[(p->phase >> 4) * 2 + 1] + 0x1000) / 2;
    for (i = 0; i < 5; i++) {
        u16 a = p->a[i];
        u16 b = p->b[i];
        u8 a1 = a & 0x1f;
        u8 a2 = (a & 0x3e0) >> 5;
        u8 a3 = (a & 0x7c00) >> 10;
        u8 b1 = b & 0x1f;
        u8 b2 = (b & 0x3e0) >> 5;
        u8 b3 = (b & 0x7c00) >> 10;
        u8 c1 = a1 + (((b1 - a1) * f) >> 12);
        u8 c2 = a2 + (((b2 - a2) * f) >> 12);
        u8 c3 = a3 + (((b3 - a3) * f) >> 12);
        p->pal[i] = c1 | (c2 << 5) | (c3 << 10);
    }
    func_02061CA4((void *)(p->f1c == 0 ? 0xf : 0x1f), 0x22, (u32)p->pal, 0xa);
}
