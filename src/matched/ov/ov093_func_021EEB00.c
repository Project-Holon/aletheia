/*
 * function: BTL_ADAPTER_SetSendData
 * address:  0x021EEB00
 * packet:   pkt_ov093_021EEB00
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[4];
    u32 w4;
    u32 w8;
    u8 st : 4;
    u8 hi : 4;
    u8 f0d;
    u8 mode;
    u8 f0f;
    u16 h10;
    u16 h12;
    u8 d[1];
} W;

extern void MI_CpuCopy8(const void *, void *, int);

void BTL_ADAPTER_SetSendData(W *p, u16 a, const void *src, u16 n)
{
    p->mode = 1;
    p->f0f = a;
    p->h10 = a;
    p->h12 = n;
    MI_CpuCopy8(src, p->d, n);
    p->w4 = 0;
    p->w8 = 0;
    p->st = 0;
}
