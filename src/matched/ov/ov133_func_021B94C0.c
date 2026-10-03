/*
 * function: func_021B94C0
 * address: 0x021B94C0
 * packet: pkt_ov133_021B94C0
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA258 0x021BA258 thumb ov133
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 *   func_021F5450 0x021F5450 thumb ov112
 *   func_021F4ED4 0x021F4ED4 thumb ov112
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_021BA184(char *p);
extern int func_021BA258(u8 *);
extern u8 *func_021BA218(u8 *);
extern u8 *func_021BA208(u8 *);
extern u8 *func_021F5450(u8 *, int);
extern void func_021F4ED4(void *, void *, int);
void func_021B94C0(u8 *p)
{
    u8 i;
    u8 *e, *q;
    u16 index;
    for (i = 0; i < 9; i++)
        *(u16 *)(*(u8 **)(*(u8 **)(p + 4) + 4) + 0x16 + i * 6) = 0;
    e = func_021BA184(*(void **)(p + 0x1824));
    while (e) {
        index = func_021BA258(e);
        q = func_021F5450(*(u8 **)(p + 0x1880), index);
        func_021F4ED4(*(void **)(p + 0x1884), func_021BA218(e), *(u16 *)(q + 0x36));
        e = func_021BA208(e);
    }
}
