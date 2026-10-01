/*
 * function: func_021A2CC8
 * address:  0x021A2CC8
 * packet:   pkt_ov021_021A2CC8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u8 pad[0x77C];
    u8 active;
    u8 mode;
    u8 half;
    u8 pad77F;
    u32 value;
} Obj021A2CC8;

void func_021A2CC8(Obj021A2CC8 *p, u8 mode, u32 value, int n)
{
    p->active = 1;
    p->mode = mode;
    p->value = value;
    p->half = n / 2;
}
