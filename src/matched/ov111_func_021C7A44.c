/*
 * function: func_021C7A44
 * address:  0x021C7A44
 * packet:   pkt_ov111_021C7A44
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0202208C  0x0202208C  thumb
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

extern void func_0202208C(int a, int b, int c, int d, int e, int f, int heap);

int func_021C7A44(Work *p)
{
    func_0202208C(0, 0, 0, 0, 6, 1, 0x27);
    p->state = 4;
    return 1;
}
