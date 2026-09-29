/*
 * function: func_021DA5BC
 * address:  0x021DA5BC
 * packet:   pkt_ov093_021DA5BC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D57FC   0x021D57FC  thumb ov093
 *   func_021D5448   0x021D5448  thumb ov093
 *   func_021D54C0   0x021D54C0  thumb ov093
 *   sub_0201C1BC    0x0201C1BC  thumb
 *   func_0201C314   0x0201C314  thumb
 *   sub_0201C1C8    0x0201C1C8  thumb
 *   func_021D799C   0x021D799C  thumb ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u16 func_021D57FC(void *p);
extern u8 func_021D5448(void *p);
extern u16 func_021D54C0(void *p, int i);
extern u32 sub_0201C1BC(u16 move);
extern u32 func_0201C314(u32 c);
extern u8 sub_0201C1C8(void *p);
extern int func_021D799C(int a, int b);

int func_021DA5BC(void *a, void *b)
{
    u16 s;
    u8 n;
    u8 i;
    u16 t;

    s = func_021D57FC(a);
    n = func_021D5448(b);
    for (i = 0; i < n; i++) {
        t = func_021D54C0(b, i);
        if (sub_0201C1BC(t) == 9)
            return 1;
        if (func_0201C314(t) != 0) {
            if (func_021D799C(sub_0201C1C8((void *)t), s) > 3)
                return 1;
        }
    }
    return 0;
}
