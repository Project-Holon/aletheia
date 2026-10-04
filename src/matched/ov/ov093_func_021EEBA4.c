/*
 * function: func_021EEBA4
 * address:  0x021EEBA4
 * packet:   pkt_ov093_021EEBA4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D4B98  0x021D4B98  thumb  ov093
 *   func_021D4BD4  0x021D4BD4  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[4];
    u32 w4;
    u32 w8;
    u8 st : 4;
    u8 hi : 4;
    u8 f0d;
    u8 mode;
    u8 f0f;
    u16 h10;
    u16 h12;
    u8 d[1];
} W;

extern int func_021D4B98(void);
extern u16 func_021D4BD4(int a, u8 **q);

u32 func_021EEBA4(W *p)
{
    if (p->hi != 0) {
        if (func_021D4B98() != 0) {
            p->w8 = func_021D4BD4(p->f0d, (u8 **)(&p->w4));
            p->st = 1;
            return 1;
        }
        return 0;
    }
    return p->st;
}
