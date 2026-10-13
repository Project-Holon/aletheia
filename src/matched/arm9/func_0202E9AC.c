/*
 * function: BLINK_PALANM_LoadPalettes
 * address:  0x0202E9AC
 * packet:   pkt_0202E940
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * TU: blink_palanm.c (__FILE__ 0x020A7804, lines 0x83 and 0x84).
 *
 * symbols:
 *   func_02030734      0x02030734  arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle      0x02049F78  arm
 *   MI_CpuCopy8      0x02082D44  arm
 *   func_020307B0      0x020307B0  arm
 *   blink_palanm_File  0x020A7804  data
 */
#include "../include/Obj15860.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const char blink_palanm_File[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern void  MI_CpuCopy8(void *dst, const void *src, int size);
extern u32 func_020307B0(void *p);

struct CodeIn {
    void *w00;    /* 0x00 */
    void *w04;    /* 0x04 */
    void *buf;    /* 0x08 */
    u16 h0c;      /* 0x0c */
    u16 h0e;      /* 0x0e */
    u16 h10;      /* 0x10 */
    u16 h12;      /* 0x12 */
    u32 w14;      /* 0x14 */
    u16 h18;      /* 0x18 */
};

struct Blink;

void BLINK_PALANM_LoadPalettes(struct CodeIn *p, u8 *a1, u32 a2, u32 a3, u32 a4)
{
    void *tmp;
    void *handle;
    u8 *base;

    p->w00 = func_02030734(p->h18, (u32)p->h0e * 2, 0, blink_palanm_File,
                           0x83);
    p->w04 = func_02030734(p->h18, (u32)p->h0e * 2, 0, blink_palanm_File,
                           0x84);
    handle = ARC_UTIL_LoadPaletteBlockFromHandle(a1, a2, (u32)(&tmp), p->h18);
    base = *(u8 * *)&((struct Obj15860 *)tmp)->fC;
    MI_CpuCopy8(base + a3 * 2, p->w00, (int)((u32)p->h0e * 2));
    MI_CpuCopy8(base + a4 * 2, p->w04, (int)((u32)p->h0e * 2));
    func_020307B0(handle);
}
