/*
 * function: func_021B9BD8
 * address:  0x021B9BD8
 * packet:   pkt_ov092_021B9BD8
 * region:   ov092
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017F9C  0x02017F9C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0201AA18(void *party);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *mon, u32 id, u32 buf);
extern void func_02017F9C(void *mon, u32 v);

void func_021B9BD8(void *party)
{
    int i;
    void *mon;
    u16 a;
    u8 b;

    for (i = 0; i < (int)func_0201AA18(party); i++) {
        mon = func_0201AB28(party, i);
        a = func_02017E1C(mon, 0xab, 0);
        b = func_02017E1C(mon, 0xa, 0);
        if (b == 0x1e && a != 0 && a != 0x28a) {
            func_02017F9C(mon, 0);
        }
    }
}
