/*
 * function: func_021C94F4
 * address:  0x021C94F4
 * packet:   pkt_ov021_021C94F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE56C  0x021DE56C  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_021ABE24  0x021ABE24  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
typedef struct { u32 f0; u32 f4; u32 f8[3]; } Q;
extern u32 d_021DE56C[3];
extern u32 func_021ABE24(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern int func_02046FF8(int *self);
void func_021C94F4(Q *q)
{
    u32 h = func_021ABE24((u8 *)q->f0);
    int i;
    q->f4 = (u32)func_02046E24(h, 0x52);
    func_02046FF8((int *)q->f4);
    for (i = 0; i < 3; i++)
        q->f8[i] = (u32)func_02046E24(h, d_021DE56C[i]);
}
