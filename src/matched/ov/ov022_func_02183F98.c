/*
 * function: func_02183F98
 * address:  0x02183F98
 * packet:   pkt_ov022_02183F98
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * leaf:     Sole game blocker of assigned ov012 caller; root claim granted.
 * symbols:
 *   func_02082D44  0x02082D44  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_02082D44(const void *src, void *dst, u32 len);

void func_02183F98(void *p, const void *value)
{
    func_02082D44(value, p, 4);
}
