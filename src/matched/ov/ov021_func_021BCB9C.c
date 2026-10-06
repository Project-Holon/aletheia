/*
 * function: func_021BCB9C
 * address:  0x021BCB9C
 * packet:   pkt_ov021_021BCB9C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD0A0  0x021BD0A0  thumb  ov021
 *   func_021BD0A8  0x021BD0A8  thumb  ov021
 *   func_021BD0C8  0x021BD0C8  thumb  ov021
 *   func_02040588  0x02040588  arm
 *   func_021BC92C  0x021BC92C  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

void func_021BD0A0(void *p, int v);
void func_021BD0A8(char *p);
void func_021BD0C8(char *p);
extern void func_02040588(unsigned char which, unsigned char enable);
void func_021BC92C(void *p);

void func_021BCB9C(void *p, int keep)
{
    func_021BD0A0(p, keep);
    func_021BD0A8(p);
    func_021BD0C8(p);
    if (keep == 0) {
        func_02040588(3, 0);
        func_021BC92C(p);
    }
}
