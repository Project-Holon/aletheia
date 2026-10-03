/*
 * function: func_02173CB4
 * address:  0x02173CB4
 * packet:   pkt_ov012_02173CB4
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef unsigned short u16;
struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);

void func_02173CB4(void)
{
    func_0203D3A8(func_020399A8(), 0x1409, 0, 0);
}
