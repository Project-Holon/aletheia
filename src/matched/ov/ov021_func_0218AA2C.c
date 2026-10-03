/*
 * function: func_0218AA2C
 * address:  0x0218AA2C
 * packet:   pkt_ov021_0218AA2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns 2 when a non-egg party member holds item 0x31 or 0x28, else 1.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);

int func_0218AA2C(void *party)
{
    int count = func_0201AA18(party);
    int i;

    for (i = 0; i < count; i++) {
        void *mon = func_0201AB28(party, i);
        u32 item = func_02017E1C(mon, 0xA, 0);
        if (func_02017E1C(mon, 0x4C, 0) == 0 && (item == 0x31 || item == 0x28))
            return 2;
    }
    return 1;
}
