/*
 * function: func_021C7FC0
 * address:  0x021C7FC0
 * packet:   pkt_ov021_021C7FC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_021C7DAC  0x021C7DAC  thumb  ov021
 *   func_021C7E50  0x021C7E50  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u8 sub[0x18]; u16 f1C; u16 f1E; } M;
extern void func_020307B0(void *p);
extern M *func_021C7DAC(u32 heap);
extern void func_021C7E50(M *m, u32 v);
void func_021C7FC0(M **pp, u32 flags, u32 heap)
{
    if (flags & 3) {
        *pp = func_021C7DAC(heap);
        if (flags & 2)
            func_021C7E50(*pp, 2);
        else
            func_021C7E50(*pp, 0);
    } else {
        *pp = 0;
    }
}
