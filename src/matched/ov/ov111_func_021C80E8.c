/*
 * function: func_021C80E8
 * address:  0x021C80E8
 * packet:   pkt_ov111_021C80E8
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
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
    void *f7C[12];
    u8 padAC[0xF8 - 0xAC];
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    u8 pad108[4];
    int state;
} Work;

struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);

void func_021C80E8(Work *p, int row, int v)
{
    int i;

    for (i = 0; i < 3; i++) {
        CLACT_SetActorDrawEnable(p->f7C[row * 3 + i], v);
    }
}
