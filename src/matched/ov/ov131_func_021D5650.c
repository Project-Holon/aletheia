/*
 * function: func_021D5650
 * address: 0x021D5650
 * packet: pkt_ov131_021D5650
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02061CA4 0x02061CA4 arm
 *   d_021DBFA8 0x021DBFA8 data a2
 *   d_021DBFB8 0x021DBFB8 data a2
 *   FX_SinCosTable_ 0x020A1B38 data
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _ffix 0x0209C494 arm
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Col4 { u16 c[4]; };
struct W {
    char pad[0x1a4];
    u16 ang;
    u16 x4[4];
    u16 pal4[4];
    u16 a16[16];
    u16 b16[16];
    u16 o16[16];
    u16 o3[16];
    u16 i3[16];
};
extern const struct Col4 d_021DBFA8;
extern const struct Col4 d_021DBFB8;
extern const s16 FX_SinCosTable_[];
typedef signed int     s32;
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
s32 func_021D5650(struct W *p)
{
    struct Col4 A;
    struct Col4 B;
    u16 ang;
    float t;
    u8 n_1;
    u16 ca_1, cb_1;
    s8 r_1, g_1, b_1;
    u16 ca_2, cb_2;
    s8 r_2, g_2, b_2;
    u16 ca_3;
    s8 r_3, g_3, b_3, r2_3, g2_3, b2_3;
    int IR_3, IG_3, IB_3;

    ang = p->ang;
    if (ang + 0x400 >= 0x10000) {
        p->ang = ang - 0xfc00;
    } else {
        p->ang = ang + 0x400;
    }
    A = d_021DBFA8;
    B = d_021DBFB8;
    t = (float)((FX_SinCosTable_[(p->ang >> 4) * 2] + 0x1000) / 2) / 4096.0f;

    for (n_1 = 0; n_1 < 4; n_1++) {
        ca_1 = A.c[n_1];
        r_1 = (s8)(ca_1 & 0x1f);
        g_1 = (s8)((ca_1 & 0x3e0) >> 5);
        b_1 = (s8)((ca_1 & 0x7c00) >> 10);
        cb_1 = B.c[n_1];
        r_1 = (s8)(int)((float)r_1 + t * (float)((s8)(cb_1 & 0x1f) - r_1));
        g_1 = (s8)(int)((float)g_1 + t * (float)((s8)((cb_1 & 0x3e0) >> 5) - g_1));
        b_1 = (s8)(int)((float)b_1 + t * (float)((s8)((cb_1 & 0x7c00) >> 10) - b_1));
        if (r_1 < 0) r_1 = 0;
        if (g_1 < 0) g_1 = 0;
        if (b_1 < 0) b_1 = 0;
        if (r_1 > 31) r_1 = 31;
        if (g_1 > 31) g_1 = 31;
        if (b_1 > 31) b_1 = 31;
        p->pal4[n_1] = (b_1 << 10) | ((g_1 << 5) | r_1);
    }
    func_02061CA4((void *)14, 0x6c, (u32)p->pal4, 8);

    for (n_1 = 0; n_1 < 16; n_1++) {
        ca_2 = p->a16[n_1];
        r_2 = (s8)(ca_2 & 0x1f);
        g_2 = (s8)((ca_2 & 0x3e0) >> 5);
        b_2 = (s8)((ca_2 & 0x7c00) >> 10);
        cb_2 = p->b16[n_1];
        r_2 = (s8)(int)((float)r_2 + t * (float)((s8)(cb_2 & 0x1f) - r_2));
        g_2 = (s8)(int)((float)g_2 + t * (float)((s8)((cb_2 & 0x3e0) >> 5) - g_2));
        b_2 = (s8)(int)((float)b_2 + t * (float)((s8)((cb_2 & 0x7c00) >> 10) - b_2));
        if (r_2 < 0) r_2 = 0;
        if (g_2 < 0) g_2 = 0;
        if (b_2 < 0) b_2 = 0;
        if (r_2 > 31) r_2 = 31;
        if (g_2 > 31) g_2 = 31;
        if (b_2 > 31) b_2 = 31;
        p->o16[n_1] = (b_2 << 10) | ((g_2 << 5) | r_2);
    }
    func_02061CA4((void *)14, 0x180, (u32)p->o16, 0x20);

    for (n_1 = 12; n_1 <= 14; n_1++) {
        ca_3 = p->i3[n_1];
        IR_3 = ca_3 & 0x1f;
        r_3 = (s8)IR_3;
        IG_3 = (ca_3 & 0x3e0) >> 5;
        g_3 = (s8)IG_3;
        IB_3 = (ca_3 & 0x7c00) >> 10;
        b_3 = (s8)IB_3;
        r2_3 = (s8)(IR_3 + 10);
        g2_3 = (s8)(IG_3 + 10);
        b2_3 = (s8)(IB_3 + 10);
        if (r2_3 > 31) r2_3 = 31;
        if (g2_3 > 31) g2_3 = 31;
        if (b2_3 > 31) b2_3 = 31;
        r_3 = (s8)(int)((float)r_3 + t * (float)(r2_3 - r_3));
        g_3 = (s8)(int)((float)g_3 + t * (float)(g2_3 - g_3));
        b_3 = (s8)(int)((float)b_3 + t * (float)(b2_3 - b_3));
        if (r_3 < 0) r_3 = 0;
        if (g_3 < 0) g_3 = 0;
        if (b_3 < 0) b_3 = 0;
        if (r_3 > 31) r_3 = 31;
        if (g_3 > 31) g_3 = 31;
        if (b_3 > 31) b_3 = 31;
        p->o3[n_1] = (b_3 << 10) | ((g_3 << 5) | r_3);
    }
    return func_02061CA4((void *)14, 0x1a0, (u32)p->o3, 0x20);
}
