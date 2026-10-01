/*
 * function: func_021C93D0
 * address:  0x021C93D0
 * packet:   pkt_ov021_021C93D0
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
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void func_020307B0(void *p);
void func_021C93D0(void **q)
{
    func_020307B0(q[0]);
    func_020307B0(q);
}
