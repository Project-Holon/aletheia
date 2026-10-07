/*
 * function: func_021A3CE8
 * address:  0x021A3CE8
 * packet:   pkt_ov021_021A3CE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3C94  0x021A3C94  thumb  ov021
 *   func_021A3C6C  0x021A3C6C  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x24];
    u32 mask;
    u8 pad28[4];
    u16 timer;
    u16 count;
    short step;
    u16 done;
} Obj021A3CE8;

int func_021A3C94(u32 x);
u16 func_021A3C6C(Obj021A3CE8 *p, int idx);

void func_021A3CE8(Obj021A3CE8 *p)
{
    int i = func_021A3C94(p->mask);

    if (i < 10) {
        while (func_021A3C6C(p, i) == 0)
            ;
    }
}
