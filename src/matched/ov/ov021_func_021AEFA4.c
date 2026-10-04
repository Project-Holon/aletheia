/*
 * function: func_021AEFA4
 * address:  0x021AEFA4
 * packet:   pkt_ov021_021AEFA4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u32 func_020120F4(u32 a);
struct BigObj;
extern u32 func_02012A30(const struct BigObj *p);
extern void func_02028A58(u32 a, u32 b, u32 c);

int func_021AEFA4(u32 *a, u32 *st)
{
    u32 r = func_02012A30((const struct BigObj *)func_020120F4(*a));

    switch (*st) {
    case 0:
        func_02028A58(r, 0x7f, 0);
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
