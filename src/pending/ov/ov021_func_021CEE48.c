/*
 * function: func_021CEE48
 * address:  0x021CEE48
 * packet:   pkt_ov021_021CEE48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: body is right; the original keeps the 0203CF10 result in r2 and
 * copies it to r1 for the call (2 bytes longer), ours keeps it in r1.  Tried
 * nested ifs, declaration order, a const id local, an Ent/Sub struct.
 *
 * symbols:
 *   func_0203CF10  0x0203CF10  arm
 *   func_021CEE78  0x021CEE78  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *func_0203CF10(int i);
extern void func_021CEE78(u8 *p, void *e);

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
            func_021CEE78(p, &e->sub);
        }
    }
}
