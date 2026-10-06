/*
 * function: func_021C78F8
 * address:  0x021C78F8
 * packet:   pkt_ov111_021C78F8
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020452E8  0x020452E8  arm
 *   func_020450C8  0x020450C8  arm
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

struct Descriptor;
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);

void func_021C78F8(Work *p)
{
    func_020452E8(p->f8);
    func_020450C8();
}
