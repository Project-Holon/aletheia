/*
 * unit: yes
 * function: func_021DD3F4, func_021DD498
 * address: 0x021DD3F4
 * packet: pkt_ov171_021DD3F4
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD774 0x021DD774 thumb ov171
 *   func_021DCBE8 0x021DCBE8 thumb ov171
 *   func_021DDC28 0x021DDC28 thumb ov171
 *   func_021DCBA4 0x021DCBA4 thumb ov171
 *   func_021DD4D0 0x021DD4D0 thumb ov171
 */
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021DD774(char *);
extern int func_021DCBE8(char *);
extern void func_021DDC28(char *);
extern void func_021DCBA4(char *);
extern int func_021DD4D0(char *, int);
int func_021DD3F4(char *p)
{
    unsigned i;
    if (!func_021DD774(p)) {
        for (i = 0; i < *(u16 *)(p + *(s8 *)(p + 0xc5e) * 0xbc + 0xc4); ++i)
            *(u8 *)(p + i + 0xb34) = *(u8 *)(p + i + 0xb40);
        func_021DCBE8(p);
        func_021DDC28(p);
        return 7;
    } else {
        for (i = 0; i < *(u16 *)(p + *(s8 *)(p + 0xc5e) * 0xbc + 0xc4); ++i) {
            if (*(u8 *)(p + i + 0xb3a) > *(u8 *)(p + i + 0xb40))
                --*(u8 *)(p + i + 0xb3a);
            else if (*(u8 *)(p + i + 0xb3a) < *(u8 *)(p + i + 0xb40))
                ++*(u8 *)(p + i + 0xb3a);
        }
        func_021DCBA4(p);
        return 9;
    }
}
int func_021DD498(char *p)
{
    return func_021DD4D0(p, 1);
}
