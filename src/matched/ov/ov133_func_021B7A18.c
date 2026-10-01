/*
 * function: func_021B7A18
 * address: 0x021B7A18
 * packet: pkt_ov133_021B7A18
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA20C 0x021BA20C thumb ov133
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 *   func_021F4D74 0x021F4D74 thumb ov112
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *func_021BA184(void *);
extern u8 *func_021BA20C(u8 *);
extern u8 *func_021BA218(u8 *);
extern u8 *func_021BA208(u8 *);
extern void func_021F4D74(u8 *, u8 *, int, u16);
void func_021B7A18(u8 *p)
{
    u8 *e = func_021BA184(*(void **)(p + 0x181c));
    u8 *q;
    u8 *s;
    while (e) {
        q = func_021BA20C(e);
        s = func_021BA218(e);
        if (*(int *)(q + 12) == 1)
            func_021F4D74(*(u8 **)(p + 0x1884), s, *(u16 *)q, *(int *)(q + 8));
        else
            func_021F4D74(*(u8 **)(p + 0x1884), s, *(u16 *)q, *(int *)(q + 4));
        e = func_021BA208(e);
    }
}
