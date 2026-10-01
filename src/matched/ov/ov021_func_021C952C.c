/*
 * function: func_021C952C
 * address:  0x021C952C
 * packet:   pkt_ov021_021C952C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_020470D0  0x020470D0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void func_020307B0(void *p);
typedef struct { u32 f0; u32 f4; u32 f8[3]; } Q;
extern void func_02046EFC(u32 h);
extern void func_020470D0(u32 h);
void func_021C952C(Q *q)
{
    int i;
    for (i = 0; i < 3; i++)
        func_02046EFC(q->f8[i]);
    func_020470D0(q->f4);
    func_02046EFC(q->f4);
}
