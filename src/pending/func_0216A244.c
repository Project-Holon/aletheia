/*
 * function: func_0216A244
 * address:  0x0216A244
 * packet:   pkt_0216A244
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocked:  listing 32 compiled 30 wild=4
 *
 * The overlay's own status call takes the arm9 handle; anything but one
 * reads as failure.
 *
 * symbols:
 *   func_02188CB4   0x02188CB4  thumb
 *   func_021A3208   0x021A3208  thumb
 *   func_021A3244   0x021A3244  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02188CB4(int);
extern int func_021A3208(void *);
extern int func_021A3244(void *);

int func_0216A244(void *a0)
{
    void *v = func_02188CB4(*(int *)((char *)a0 + 8));

    if (func_021A3208(v) == 1)
        return func_021A3244(v);

    return 1;
}
