/*
 * function: func_02159B48
 * address:  0x02159B48
 * packet:   pkt_ov010_02159B48
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02082A7C  0x02082A7C  arm
 *   d_021728AC  0x021728AC  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082A7C(int, void *, int);
extern const char d_021728AC[];

u16 *func_02159B48(int a)
{
    u16 *p = func_02030734(a, 0x152c, 1, d_021728AC, 0x4b);
    *p = a;
    func_02082A7C(-1, (u8 *)p + 0x71c, 0xe10);
    func_02082A7C(0xffff, (u8 *)p + 0x14, 0x708);
    return p;
}
