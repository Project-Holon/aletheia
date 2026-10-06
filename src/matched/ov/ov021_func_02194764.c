/*
 * function: func_02194764
 * address:  0x02194764
 * packet:   pkt_ov021_02194764
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0206DB80  0x0206DB80  arm
 *   func_021953D4  0x021953D4  thumb  ov021
 *   func_02194CE8  0x02194CE8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct { u16 kind; u8 f2; u8 rest[97]; } Ent;
typedef struct { u8 pad[0x18]; Ent ents[32]; } Top;
extern void func_0206DB80(void);
extern void func_021953D4(u8 *p, int m);
extern void func_02194CE8(int a, u16 *b);

void func_02194764(Top *a)
{
    int i;

    func_0206DB80();
    func_021953D4((u8 *)a, 1);
    for (i = 0; i < 32; i++) {
        if (a->ents[i].f2 == 0) {
            func_02194CE8((int)a, (u16 *)(&a->ents[i]));
        }
    }
}
