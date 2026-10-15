/*
 * function: ENCEFF_DrawScreenTexEffect
 * address:  0x021F52D8
 * packet:   pkt_ov075_021F52D8
 * region:   ov075
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * volatile: 0x021F5348 str to hardware register 0x040004A8 (G3 TEXIMAGE_PARAM)
 *
 * G3i_PerspectiveW_ is G3i_PerspectiveW_; the call goes through the SDK inline
 * G3_Perspective (scaleW FX32_ONE, TRUE and the mtx argument bound inside the
 * inline), which is what schedules the NULL mtx stack store after the table
 * loads. Calling G3i_PerspectiveW_ directly stores it right after the first
 * pool load (6 instructions out of place).
 *
 * symbols:
 *   G3i_PerspectiveW_  0x0207D704  arm
 *   G3X_Reset  0x0207DA8C  arm
 *   G3i_LookAt_  0x0207D7C4  arm
 *   d_020A1EB8     0x020A1EB8  data  a4
 *   d_021F55F8     0x021F55F8  data  ov075  a4
 */
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

struct V { int x; int y; int z; };

extern const s16 d_020A1EB8[];
extern struct V d_021F55F8;

extern void G3i_PerspectiveW_(int a, int b, int c, int d, int e, int f, int g, int h);
extern void G3X_Reset(void);
extern void G3i_LookAt_(struct V *a, struct V *b, struct V *c, int d, int e);

static inline void G3_Perspective(int fs, int fc, int aspect, int n, int f, void *mtx)
{
    G3i_PerspectiveW_(fs, fc, aspect, n, f, 0x1000, 1, (int)mtx);
}

void ENCEFF_DrawScreenTexEffect(u32 *p)
{
    struct V a;

    G3_Perspective(d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0x1000, 0x400000, 0);
    G3X_Reset();
    a = d_021F55F8;
    {
        struct V c = {0, 0, 0};
        struct V b;

        b = *(struct V *)(p + 6);
        G3i_LookAt_(&b, &a, &c, 1, 0);
    }
    *(volatile u32 *)0x040004A8 = ((u16)p[5] & 0x1FFFFFFF) | 0x5ED00000;
    ((void (*)(u32))p[11])(p[9]);
}
