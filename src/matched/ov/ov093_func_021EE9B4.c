/*
 * function: BTL_REC_LoadPacket
 * address:  0x021EE9B4
 * packet:   pkt_ov093_021EE9B4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082D44  0x02082D44  arm
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

extern void func_02082D44(const void *, void *, int);

void BTL_REC_LoadPacket(B *p, const void *src, int n)
{
    func_02082D44(src, p->d, n);
    p->len = n;
    p->mask = 0;
    p->cnt = 0;
    p->x = 0;
    p->f = 0;
    p->g = 0;
}
