/*
 * function: func_0219EB4C
 * address:  0x0219EB4C
 * packet:   pkt_ov021_0219EB4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0219EA10  0x0219EA10  thumb  ov021
 *   func_0219EA24  0x0219EA24  thumb  ov021
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0219EA78  0x0219EA78  thumb  ov021
 *   d_021D84AC     0x021D84AC  data  ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    u8  pad[0xc];
    s16 cnt;
    u16 val;
} E;

extern u8 d_021D84AC[];

extern E *func_0216D69C();
extern int func_0219EA10();
extern u32 func_0219EA24(u32 a, u32 b);
extern void func_0216D5E0(u32, u16);
extern int func_0219EA78();

int func_0219EB4C(u32 o)
{
    E *e;

    e = func_0216D69C(o);
    e->cnt = e->cnt - 1;
    if (e->cnt <= 0) {
        e->cnt = func_0219EA10(d_021D84AC, -1);
        func_0216D5E0(o, func_0219EA24(e->val, 9));
    }
    return func_0219EA78(e, o);
}
