/*
 * function: func_021B65B8
 * address:  0x021B65B8
 * packet:   pkt_ov091_021B65B8
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B68F0  0x021B68F0  thumb
 *   d_021BED80     0x021BED80  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x60];
    u16 v60;
    u8 pad62[0x90 - 0x62];
    u32 v90;
} Q;

typedef struct {
    u8 pad[640];
    Q *q;
} P;

extern int func_021B68F0(u8 *p);
extern u8 d_021BED80;

int func_021B65B8(int a0, int a1, int a2, P *p)
{
    Q *q;

    if (a2 == 0) {
        q = p->q;
        if (q->v90 == 1 && q->v60 != 0) {
            d_021BED80++;
            if (d_021BED80 > 0x3c) {
                d_021BED80 = 0;
                q->v60 = q->v60 - 1;
            }
        }
    }
    if (func_021B68F0((u8 *)p) == 1)
        return 1;
    return 0;
}
