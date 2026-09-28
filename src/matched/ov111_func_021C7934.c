/*
 * function: func_021C7934
 * address:  0x021C7934
 * packet:   pkt_ov111_021C7934
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x7C - 0x18];
    void *f7C[4][3];
    u8 padAC[0xF8 - 0xAC];
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    u8 pad108[4];
    int state;
} Work;

extern void *func_0201D7EC(int a, int b, int c, int d, int heap);
extern void *func_0201C440(int heap);

void func_021C7934(Work *p)
{
    p->f4 = func_0201D7EC(0x17, 0, 0, 0, 0x27);
    p->f14 = func_0201C440(0x27);
    p->fC = p->f8;
    p->f10 = 0;
}
