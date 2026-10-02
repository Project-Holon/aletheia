/*
 * function: func_0217D918
 * address:  0x0217D918
 * packet:   pkt_ov018_0217D918
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_02049238  0x02049238  arm
 *   func_02049DF4  0x02049DF4  arm
 *   func_0204ABBC  0x0204ABBC  arm
 *   func_02030734  0x02030734  arm
 *   func_02082A60  0x02082A60  arm
 *   d_02183B14     0x02183B14  data   a1
 */

typedef unsigned char u8;

typedef unsigned short u16;

extern void *func_0204AC18(void *, int, int, int, int, int, int);
extern void *func_0204A6C8(void *, int, int, int, int);
extern void *func_0204AF28(void *, int, int, int);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void *func_0204ACEC(void *, int, int, int, int);
extern void func_02049238(void *);
extern void *func_02049DF4(void *, int, int, void *, int);
extern void *func_0204ABBC(void *, int);
extern void *func_02030734(int, int, int, const char *, int);
extern void func_02082A60(const void *, void *, int);
extern const char d_02183B14[];

void func_0217D918(u8 *p, void *bg)
{
    void *t;

    *(void **)(p + 0x08) = func_0204AC18(bg, 3, 1, 0, 0, 9, 0x15);
    *(void **)(p + 0x04) = func_0204A6C8(bg, 0, 1, 1, 0x15);
    *(void **)(p + 0x10) = func_0204AF28(bg, 1, 2, 0x70);
    t = func_020490F4(0x17, 0x15);
    *(void **)(p + 0x0c) = func_0204ACEC(t, 5, 1, 0x1a0, 0x15);
    func_02049238(t);
    *(void **)(p + 0x14) = func_0204A6C8(bg, 10, 1, 1, 0x15);
    *(void **)(p + 0x18) = func_0204AF28(bg, 12, 13, 0x70);
    *(void **)(p + 0xc8) = func_02049DF4(bg, 10, 1, p + 0xcc, 0x70);
    *(void **)(p + 0xd4) = func_0204ABBC(*(void **)(p + 0x14), 2);
    *(void **)(p + 0xd0) = func_02030734(0x70, 0x200, 1, d_02183B14, 0x495);
    func_02082A60((void *)0x050006E2, p + 0x120, 8);
    func_02082A60(p + 0x120, p + 0x130, 8);
    func_02082A60((void *)0x05000702, p + 0x128, 8);
}
