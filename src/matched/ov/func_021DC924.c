/*
 * function: func_021DC924
 * address:  0x021DC924
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *
 * Push the record's id and its 0x14 byte to channel 4, release
 *   d[1], then hand the frame over; 1 when done.
 */


extern void func_0200780C(int, int);
struct S020314B8;
extern void func_0203133C(struct S020314B8 *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
int func_021DC924(int a, int b, int c, int *d)
{
    func_0200780C(*(int *)(*d + 4), *(unsigned char *)((char *)d + 0x14));
    func_0203133C((struct S020314B8 *)d[1]);
    func_020315D4((struct S020315D4 *)a);
    func_020306F0(0x4b);
    return 1;
}
