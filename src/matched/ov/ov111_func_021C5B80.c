/*
 * function: func_021C5B80
 * address:  0x021C5B80
 * packet:   pkt_ov111_021C5B80
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02035BA4  0x02035BA4  arm
 *   d_021C8534     0x021C8534  data  a1
 *   d_021C854C     0x021C854C  data  a1
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x3034];
    u32 f3034;
    u8 pad3038[0x305E - 0x3038];
    u16 h305E;
    u8 pad3060[0x330F - 0x3060];
    u8 b330F;
} Work;

extern int func_02035BA4(const void *p);
extern const u8 d_021C8534[];
extern const u8 d_021C854C[];

void func_021C5B80(Work *p)
{
    if ((p->f3034 != 0 && p->h305E == 0 && func_02035BA4(d_021C8534))
        || (p->h305E == 1 && func_02035BA4(d_021C854C))) {
        p->b330F = 0;
    }
}
