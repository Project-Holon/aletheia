/*
 * function: func_021D11B0
 * address:  0x021D11B0
 * packet:   pkt_ov021_021D11B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056A0  0x020056A0  thumb
 *   func_020414AC  0x020414AC  arm
 *   func_021D1400  0x021D1400  thumb  ov021
 *   func_021D1488  0x021D1488  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_020414AC(int a);
extern void func_021D1400(void *p);
extern void *func_020056A0(void *, void *, int);
struct Anim021D1488;
extern void func_021D1488(void *task, struct Anim021D1488 *p);

void func_021D11B0(u32 *p)
{
    func_020414AC(3);
    p[5] = 0;
    func_021D1400(p);
    p[3] = (u32)func_020056A0(func_021D1488, p, 0x80);
}
