/*
 * function: func_0218AA74
 * address:  0x0218AA74
 * packet:   pkt_ov021_0218AA74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * For every egg in the party, lowers field 9 (the step counter) by the amount
 * from func_0218AA2C, clamping at zero.
 *
 * symbols:
 *   func_0218AA2C  0x0218AA2C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern int func_0201AA18(void *party);
extern void *func_0201AB28(void *party, int i);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void func_02017E40(void *mon, u32 id, u32 v);
extern u32 func_0218AA2C(void *party);

void func_0218AA74(void *party)
{
    int count = func_0201AA18(party);
    u32 amount = func_0218AA2C(party);
    int i;

    for (i = 0; i < count; i++) {
        void *mon = func_0201AB28(party, i);
        u32 flag = func_02017E1C(mon, 0x4C, 0);
        u32 v = func_02017E1C(mon, 9, 0);
        if (flag == 1) {
            u32 nv = 0;
            if (v >= amount)
                nv = v - amount;
            func_02017E40(mon, 9, nv);
        }
    }
}
