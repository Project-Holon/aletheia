/*
 * function: func_021C581C
 * address:  0x021C581C
 * packet:   pkt_ov111_021C581C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5B34  0x021C5B34  thumb  ov111
 *   func_021C4F80  0x021C4F80  thumb  ov111
 *   func_02040618  0x02040618  arm
 *   func_020419E4  0x020419E4  arm
 *   func_0204A648  0x0204A648  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x32CA];
    u8 f0 : 1;
    u8 f1 : 1;
    u8 dirty : 1;
    u8 pad32CB[0x32D6 - 0x32CB];
    u8 shake;
} Work;

extern void func_021C5B34(Work *p);
extern void func_021C4F80(Work *p);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_020419E4(void);
extern void func_0204A648(void);

void func_021C581C(void *task, Work *p)
{
    int ofs;

    func_021C5B34(p);
    ofs = -(p->shake / 2);
    func_02040618(5, 0, ofs);
    func_02040618(5, 3, ofs);
    func_02040618(3, 0, ofs);
    func_02040618(3, 3, ofs);
    if (p->dirty) {
        func_021C4F80(p);
    }
    func_020419E4();
    func_0204A648();
}
