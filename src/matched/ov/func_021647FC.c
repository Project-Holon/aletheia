/*
 * function: func_021647FC
 * address:  0x021647FC
 * packet:   pkt_021647FC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_020490F4(unsigned int id, unsigned int heap);

void *func_021647FC(int a0, int a1)
{
    int t4;
    void *rec;

t4 = a0 + 0;
a1 = *(u16 *)((char *)t4);
a0 = 0x61;
    rec = func_020490F4(a0, a1);
loc_02164808:
*(void **)((char *)t4 + 8) = rec;
    return rec;}
