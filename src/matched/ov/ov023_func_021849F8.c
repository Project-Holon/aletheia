/*
 * function: func_021849F8
 * address:  0x021849F8
 * packet:   pkt_ov023_021849F8
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02186558  0x02186558  thumb  ov023
 *   func_02039338  0x02039338  arm
 *   func_02186444  0x02186444  thumb  ov023
 *   func_02045CAC  0x02045CAC  arm
 *   func_02030734  0x02030734  arm
 *   d_02186F58     0x02186F58  data  ov023  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u8 e:3; u8 f:3; u8 g:2; u8 h[5]; } Rec;

extern char d_02186F58[];
extern int  func_020457B0(int, int);
extern int  func_02186558(u8 *);
extern u16 func_02039338(void);
extern void func_02186444(u8 *, u32);
extern void func_02045CAC(int, u16, int);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

void func_021849F8(u8 *p)
{
    int i = 0;
    int z = i;

    for (; i < 5; i++) {
        *(u32 *)(p + i * 4 + 0x18) = func_020457B0(8, 0x28);
        ((Rec *)(p + 0x4216))[i].f = 0;
        *(u16 *)(p + i * 4 + 0x4232) = z;
        *(u32 *)(p + 0x1C8 + i * 8) = z;
        *(u32 *)(p + 0x1CC + i * 8) = z;
    }
    *(u32 *)(p + 0x2C) = func_020457B0(0xA, 0x28);
    *(u32 *)(p + 0x30) = func_020457B0(0x50, 0x28);
    *(u8 *)(p + 0x420A) = z;
    *(u8 *)(p + 0x420B) = 1;
    *(u32 *)(p + 0x9E6C) = 1;
    *(u32 *)(p + 0x9E70) = z;
    *(u32 *)(p + 0x1AC) = 2;
    *(u32 *)(p + 0x1B0) = func_02186558(p);
    *(u32 *)(p + 0x9E74) = z;
    *(u32 *)(p + 0x9E78) = z;
    *(u32 *)(p + 0x198) = z;
    *(u32 *)(p + 0x9E7C) = z;
    *(u32 *)(p + 0x9E80) = z;
    *(u32 *)(p + 0x178) = z;
    func_02039338();
    func_02186444(p, 4);
    func_02045CAC(*(u32 *)(p + 0x14), 7, *(u32 *)(p + 0x2C));
    *(void **)(p + 0x4288) = func_02030734(0x28, 0x3C00, z, d_02186F58, 0x31D);
    *(u32 *)(p + 0x1A8) = z;
}
