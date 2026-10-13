/*
 * function: func_021DFAD0
 * address:  0x021DFAD0
 * packet:   pkt_ov119_021DFAD0
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: the non-SDK callee of ov119 func_021DFC28
 * (+0038) and a dependency of the func_021D7130 tree.  Copies two constant
 * eight-byte-record tables from 0x021E7754 (two records) and 0x021E7764 (six
 * records) to the stack, gates on two bytes of the second argument, then
 * calls GFL_USE_PlaySeDefaultVolume on each record whose id matches arg0.  Both table
 * addresses are literal pool words, so they carry no relocation; the byte at
 * +0x11ED picks the six-record table (the `== 0` arm is the fall-through, the
 * unsigned counter is what makes the loop `blo`, not `blt`).
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume   0x020061E4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern void GFL_USE_PlaySeDefaultVolume(u32 a);

typedef struct { int fn; int id; } Ent;
typedef struct { Ent e[2]; } T2;
typedef struct { Ent e[6]; } T6;

void func_021DFAD0(int a0, u8 *a1)
{
    T2 t1 = *(T2 *)0x021E7754;
    T6 t2 = *(T6 *)0x021E7764;
    unsigned int i;

    if (a1[0x11EF] != 0)
        return;
    if (a1[0x11ED] == 0) {
        for (i = 0; i < 2; i++)
            if (a0 == t1.e[i].id)
                GFL_USE_PlaySeDefaultVolume(t1.e[i].fn);
    } else {
        for (i = 0; i < 6; i++)
            if (a0 == t2.e[i].id)
                GFL_USE_PlaySeDefaultVolume(t2.e[i].fn);
    }
}
