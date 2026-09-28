/*
 * function: func_02157E34
 * address:  0x02157E34
 * packet:   pkt_ov010_02157E34
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02157E08  0x02157E08  thumb
 *   func_02157960  0x02157960  thumb
 *   func_02157DB8  0x02157DB8  thumb
 */

typedef unsigned char u8;

extern int func_02157E08(void *);
extern void func_02157960(void *, void *, int);
extern void func_02157DB8(void);

int func_02157E34(void *p)
{
    int r = func_02157E08(p);
    *((u8 *)p + 0x675) = 0;
    *((u8 *)p + 0x676) = 0;
    *((u8 *)p + 0x677) = 0;
    *(int *)((u8 *)p + 0x66C) = 0;
    func_02157960(p, (void *)func_02157DB8, 0x231);
    return r;
}
