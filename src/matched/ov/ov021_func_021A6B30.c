/*
 * function: func_021A6B30
 * address:  0x021A6B30
 * packet:   pkt_ov021_021A6B30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02006148  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 b0;
    u8 b1;
    short h2;
} P;

typedef unsigned int   u32;
extern int func_02006148(u32 a0);
extern void func_020061F8(void);

void func_021A6B30(P *p)
{
    if (p->b0) {
        p->b0 = 0;
        p->h2 = 0;
        func_02006148(0x6d1);
        func_020061F8();
    }
}
