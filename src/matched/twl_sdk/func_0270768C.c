/*
 * function: AESi_Rand
 * address:  0x0270768C
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02735AE0  0x02735AE0  data twl a2
 *   data_02735B00  0x02735B00  data twl a2
 *   AESi_RandUnit  0x02707458  arm twl a2
 *   AESi_InitRand  0x02707570  arm twl a2
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u32 initialized;
    u32 f4;
    u32 f8;
} SysBuf;

extern SysBuf data_02735AE0;
extern u8 data_02735B00[];
extern void AESi_InitRand(void);
extern u32 AESi_RandUnit(u8 *buf, ...);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

u32 AESi_Rand(u8 *dst, u32 n) {
    u32 count;
    u32 pos;
    u32 r;

    if (data_02735AE0.initialized == 0) {
        AESi_InitRand();
    }
    count = data_02735AE0.f8;
    if (count != 0) {
        if (count > n) {
            count = n;
        }
        data_02735AE0.f8 -= count;
        pos = data_02735AE0.f8;
        MI_CpuCopy8(data_02735B00 + pos, dst, count);
        n -= count;
        dst += count;
    }
    while ((n >= 0x10) ? 1 : 0) {
        r = AESi_RandUnit(data_02735B00);
        if (r != 1) {
            return r;
        }
        MI_CpuCopy8(data_02735B00, dst, 0x10);
        dst += 0x10;
        n -= 0x10;
    }
    if (n != 0) {
        r = AESi_RandUnit(data_02735B00);
        if (r != 1) {
            return r;
        }
        pos = 0x10 - n;
        data_02735AE0.f8 = pos;
        MI_CpuCopy8(data_02735B00 + pos, dst, n);
    }
    return 1;
}
