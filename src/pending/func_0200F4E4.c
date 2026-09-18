/*
 * function: func_0200F4E4
 * address:  0x0200F4E4
 * packet:   pkt_0200F38C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * symbols:
 *   func_0203D610  0x0203D610  arm
 *   func_0200F38C  0x0200F38C  thumb
 *   func_02082D44  0x02082D44  arm
 * blocker:  unresolved relocation(s): 0200F38C (thumb, from header)*/

typedef unsigned int u32;

extern void *func_0203D610(void);
extern int   func_0200F38C(void *o, u32 *out);
extern void  func_02082D44(void *dst, const void *src, u32 n);

int func_0200F4E4(void *o)
{
    u32 out;
    int r = 0;
    void *base = func_0203D610();
    int v = func_0200F38C(o, &out);

    if (v == 0) {
        /* nothing */
    } else if (v == 1) {
        func_02082D44(o, (unsigned char *)base + out * 0xc, 0xc);
    } else if (v == 2) {
        r = 1;
    }
    return r;
}
