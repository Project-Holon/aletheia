/*
 * function: BTL_REC_InitPacket
 * address:  0x021EE8B4
 * packet:   pkt_ov093_021EE8B4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */

typedef unsigned char u8;

typedef struct {
    u8 len;
    u8 mask;
    u8 cnt;
    u8 x : 6;
    u8 f : 1;
    u8 g : 1;
    u8 d[60];
} B;

extern void MI_CpuFill8(void *, int, int);

void BTL_REC_InitPacket(B *p, int b)
{
    MI_CpuFill8(p, 0, 0x40);
    p->f = (u8)b;
}
