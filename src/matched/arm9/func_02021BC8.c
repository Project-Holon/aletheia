/*
 * function: PALANM_ApplyFade
 * address:  0x02021BC8
 * packet:   pkt_02021B6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   PALANM_CheckBit   0x02021930  thumb
 *   PALANM_CalcFadeColors   0x02021C20  thumb
 *   PALANM_StepFadeValue   0x02021CA8  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 PALANM_CheckBit(u32 val, int bit);
struct C02021C20;
extern void PALANM_CalcFadeColors(u16 *src, u16 *dst, struct C02021C20 *c, u32 count);
struct S;
extern void PALANM_StepFadeValue(u8 *p, u32 idx, struct S *s);

struct S02021BC8 {
    u8  *p0;
    u8  *p1;
    u16  f8;
    u16  fA;
    u16  field0xc;
};

void PALANM_ApplyFade(u8 *p, u32 idx, u32 arg)
{
    u32 i;
    struct S02021BC8 *s = (struct S02021BC8 *)(p + idx * 0x14);

    for (i = 0; i < 0x10; i++) {
        if (PALANM_CheckBit(s->field0xc, (u16)i)) {
            u32 off = (i * arg) * 2;
            PALANM_CalcFadeColors((u16 *)(s->p0 + off),
                          (u16 *)(s->p1 + off),
                          (struct C02021C20 *)((u8 *)s + 0xc),
                          arg);
        }
    }

    PALANM_StepFadeValue(p, (u8)idx, (struct S *)((u8 *)s + 0xc));
}
