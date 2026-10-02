/*
 * function: func_02185824
 * address:  0x02185824
 * packet:   pkt_02185824
 * region:   ov219
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02048BC4 0x02048BC4 arm
 *   func_02048C58 0x02048C58 arm
 *   d_02185DD4    0x02185DD4 data ov219
 */

extern void *func_02048BC4(void *, int);
extern void func_02048C58(void *);
extern char d_02185DD4[];

void func_02185824(char *p)
{
    *(void **)(p + 0xc370) = func_02048BC4(d_02185DD4, (unsigned short)*(unsigned int *)p);
    func_02048C58(*(void **)(p + 0xc370));
}
