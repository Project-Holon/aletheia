/*
 * function: func_02201DB4
 * address:  0x02201DB4
 * packet:   pkt_ov094_02201DB4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_GetPaletteVramAddress  0x0204AEF4  arm
 *   func_021F86E0  0x021F86E0  thumb  ov094
 *   func_021F86D4  0x021F86D4  thumb  ov094
 *   PALANM_RequestFade  0x0202173C  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern int CLACT_GetPaletteVramAddress(u32 idx, u32 alternate);
extern int func_021F86E0(void);
extern void *func_021F86D4(void);
extern int PALANM_RequestFade(void *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);

void func_02201DB4(char *base, int idx, u8 b, u8 c, s8 step, u16 d)
{
    u16 m = 1 << (((u32)CLACT_GetPaletteVramAddress((u32)(*(void **)(base + idx * 16 + 0x10)), (int)0) & 0x3FF) >> 5);
    void *p = (void *)func_021F86E0();

    PALANM_RequestFade(p, 4, m, step, b, c, d, func_021F86D4());
}
