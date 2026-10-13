/*
 * function: FIELD_FLASH_StepTween
 * address:  0x021C7E90
 * packet:   pkt_ov021_021C7E90
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0207C768  0x0207C768  arm
 *   _ll_mul        0x0209C054  arm
 *   _s32_div_f     0x0209C0A4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct {
    int f0;
    u8 f4;
    u8 pad5;
    u16 f6;
    u16 f8;
    u8 padA[2];
    int fC;
    int f10;
    s16 f14;
    s16 f16;
} Obj;

typedef unsigned int   u32;
extern u32 func_0207C768(u32 a, u32 b);

int FIELD_FLASH_StepTween(Obj *p)
{
    if (p->f6 < p->f8) {
        p->f6 = p->f6 + 1;
        p->f0 = p->fC + func_0207C768((int)(((long long)p->f10 * (p->f6 << 12) + 0x800) >> 12), p->f8 << 12);
        p->f4 = p->f14 + p->f16 * p->f6 / p->f8;
        return 0;
    }
    return 1;
}
