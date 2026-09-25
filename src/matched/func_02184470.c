/*
 * function: func_02184470
 * address:  0x02184470
 * packet:   pkt_02184470
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0208B500  0x0208B500  arm
 */

extern void func_0208B500(int *);

void func_02184470(int *p)
{
    if (*(int *)((char *)p + 0x30) == 0) {
        func_0208B500(p);
        *(int *)((char *)p + 0x28) = 1;
    } else {
        *(int *)((char *)p + 0x2c) = 1;
    }
}
