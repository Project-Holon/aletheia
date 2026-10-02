/*
 * function: func_021CEE48
 * address:  0x021CEE48
 * packet:   pkt_ov021_021CEE48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_021CEE78 takes three arguments: the entry itself is the third, which
 * is why the 0203CF10 result lives in r2 and is copied to r1 for the +0x20
 * address.  (The earlier two-argument prototype left it in r1.)
 *
 * symbols:
 *   func_0203CF10  0x0203CF10  arm
 *   func_021CEE78  0x021CEE78  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *func_0203CF10(int i);
extern void func_021CEE78(u8 *p, u8 *a, u32 b);

typedef struct Sub021CEE48 {
    u8 pad0[6];
    u16 id;
} Sub021CEE48;

typedef struct Ent021CEE48 {
    u8 pad0[0x20];
    Sub021CEE48 sub;
} Ent021CEE48;

void func_021CEE48(u8 *p)
{
    int i;
    Ent021CEE48 *e;

    for (i = 0; i < 0x10; i++) {
        e = (Ent021CEE48 *)func_0203CF10(i);
        if (e != 0 && e->sub.id == 0x3a0b) {
            func_021CEE78(p, (u8 *)&e->sub, (u32)e);
        }
    }
}
