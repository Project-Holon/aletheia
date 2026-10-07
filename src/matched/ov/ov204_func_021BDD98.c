/*
 * function: func_021BDD98
 * address: 0x021BDD98
 * packet: pkt_ov204_021BDD98
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021BFD80 0x021BFD80 data a4
 *   d_021BFF1C 0x021BFF1C data a4
 */

#include "../include/G_DispConfig.h"

struct DispConfig; struct BgTemplate;
extern const unsigned d_021BFF1C[][11];
extern struct DispConfig d_021BFD80;
extern void func_02082BCC(void *, unsigned, unsigned);
extern void func_0203F8F4(unsigned);
extern void func_02045088(unsigned);
extern void func_0203FC28(struct DispConfig *);
typedef unsigned int   u32;
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
void func_021BDD98(void *p, unsigned heap)
{
    const unsigned *row;
    unsigned i, layer;
    func_02082BCC(p, 0, 4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28(&(*(struct DispConfig *)&d_021BFD80));
    for (i = 0; i < 4; i++) {
        row = d_021BFF1C[i];
        layer = row[0];
        func_0203FCA0((unsigned char)layer, (const struct BgTemplate *)(row + 1), (unsigned char)row[9]);
        func_020414AC(layer);
        func_02040588(layer, row[10]);
    }
}
