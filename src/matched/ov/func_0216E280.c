/*
 * function: func_0216E280
 * address:  0x0216E280
 * packet:   pkt_0216E280
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 16 compiled 14
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_020490F4(unsigned int id, unsigned int heap);

void *func_0216E280(int a0, int a1)
{
    int t4;
    void *p;

t4 = a0 + 0;
    p = func_020490F4(0x30, a1);
loc_0216E28A:
*(void **)((char *)t4 + 0x14) = p;
    return p;}
