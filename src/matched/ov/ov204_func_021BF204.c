/*
 * function: func_021BF204
 * address:  0x021BF204
 * packet:   pkt_021BF204
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045C04 0x02045C04 arm
 *   func_02045B38 0x02045B38 arm
 */

struct Rec;
extern void func_02045C04(struct Rec *rec);
extern void *func_02045B38(void *, int, void *, int);

void func_021BF204(char *p, void *a, void *b)
{
    if (*(void **)(p + 0xc) != 0)
    {
        func_02045C04(*(void **)(p + 0xc));
    }
    *(void **)(p + 0xc) = func_02045B38(a, 2, b, *(unsigned short *)p);
}
