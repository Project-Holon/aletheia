/*
 * function: func_021C6CA8
 * address:  0x021C6CA8
 * packet:   pkt_ov021_021C6CA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u16 fC;
    u16 fE;
    u16 f10[8];
    u8 f20;
} D;
extern void func_020307B0(void *p);
extern void func_02030EAC(void *p);
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
typedef struct { u32 f0; u32 *f4; u32 f8; } Q;
void func_021C6CA8(Q *q)
{
    func_020307B0(q->f4);
    func_020307B0(q);
}
