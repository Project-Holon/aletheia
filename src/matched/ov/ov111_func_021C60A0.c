/*
 * function: func_021C60A0
 * address:  0x021C60A0
 * packet:   pkt_ov111_021C60A0
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_020452E8  0x020452E8  arm
 *   func_020450C8  0x020450C8  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad0[4];
    void *bg[8];
    u8 pad24[0x32CC - 0x24];
    void *f32CC;
} Work;

struct Descriptor;
struct PrintSys;
extern void func_0201C4C0(struct PrintSys *p);
typedef unsigned int   u32;
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);

void func_021C60A0(Work *p)
{
    u16 i;

    func_0201C4C0(p->f32CC);
    for (i = 0; i < 8; i++) {
        func_020452E8(p->bg[i]);
    }
    func_020450C8();
}
