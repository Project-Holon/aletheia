/*
 * function: func_021DA978
 * address:  0x021DA978
 * packet:   pkt_021DA978
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02043B5C  0x02043B5C  arm
 *   func_020257D0  0x020257D0  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

extern void func_02043B5C(int, int);
struct Obj;
extern void func_020257D0(struct Obj *o);

void func_021DA978(char *p)
{
    func_02043B5C(*(int *)p, (unsigned char)(*(u16 *)(p + 4) & 0x1f));
    func_020257D0(*(void **)(p + 0x1c));
}
