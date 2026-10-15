/*
 * function: FIELD_PLACE_NAME_InitWork
 * address:  0x021BCFA4
 * packet:   pkt_ov021_021BCFA4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u32 f4; u32 pad8[8]; int f28; u32 pad2C[6]; u16 f44; u16 f46; u32 f48; u32 f4C; } X;
extern void MI_CpuFill8(void *, int, int);
struct Ctx;
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
void FIELD_PLACE_NAME_InitWork(X *x, u32 b)
{
    MI_CpuFill8(x, 0, 0x154);
    x->f0 = b;
    x->f4 = (u32)ICA_ANIME_GetField1C((const struct Ctx *)b);
    x->f28 = -1;
    x->f4C = 0;
    x->f48 = 0;
    x->f44 = 0x1AB;
    x->f46 = 0x1AB;
}
