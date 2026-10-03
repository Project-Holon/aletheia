/*
 * function: func_021899C4
 * address: 0x021899C4
 * packet: pkt_ov096_021899C4
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5584 0x021D5584 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct UtilWork;
extern u8 func_021D5584(struct UtilWork *p, u32 i);
int func_021899C4(u8 *a, u8 *b)
{
    *(int *)(b + 0x38) = func_021D5584(*(void **)(b + 0xbc), b[1]); return *(int *)(b + 0xc4);
}
