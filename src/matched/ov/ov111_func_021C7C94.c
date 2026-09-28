/*
 * function: func_021C7C94
 * address:  0x021C7C94
 * packet:   pkt_ov111_021C7C94
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0xC];
    void *fC;
} Res;

typedef struct {
    u8 pad0[4];
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x58 - 0x18];
    void *f58;
    void *f5C[8];
    void *f7C[24];
    u8 padDC[0xF8 - 0xDC];
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    void *f108;
    int state;
    u8 pad110[4];
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x140 - 0x120];
    int f140;
    u8 pad144[0x14C - 0x144];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    u8 pad170[0x17C - 0x170];
    u8 f17C[8];
} Work;

void func_021C7C94(Work *p, int unused)
{
    int v = p->f140;

    if (v > 0x1000) {
        p->f140 = v - 0x190;
    } else if (v < -0x1000) {
        p->f140 = v + 0x190;
    } else if (v == 0) {
        p->f140 = 0x1000;
    }
}
