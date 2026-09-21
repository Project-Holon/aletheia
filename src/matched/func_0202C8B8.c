/*
 * unit:     no
 * function: func_0202C8B8
 * address:  0x0202C8B8
 * packet:   pkt_0202C8B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201296C  0x0201296C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02013D74  0x02013D74  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_0215843C  0x0215843C  thumb
 *   gTbl_0209FFF4  0x0209FFF4  data
 *
 * blocker: MATCH, evidence class 'literal'. Every concrete byte matches.
 * The two ABS32 pool words holding 0x0209FFF4 / 0x0209FFF6 are both inside
 * this function; grep over asm/ finds no third pool word anywhere in the
 * image, so the data table has no witness outside the compared range and
 * both relocation sites stay wildcarded. Unstuck by any other function that
 * also points at gTbl_0209FFF4, or by a data-symbol table entry.
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

extern u32 func_0201296C(u32 a);
extern u32 func_02012138(void *a);
extern s32 func_02013D74(u16 a);
extern s32 func_020142E8(u32 a, u16 b);
extern s32 func_0215843C(u32 a);

struct Pair {
    u16 a;
    u16 b;
};

extern struct Pair gTbl_0209FFF4[];

s32 func_0202C8B8(void *a0, u32 a1, u32 a2)
{
    u32 r6;
    u32 r4;
    u32 i;

    r6 = func_0201296C(a1);
    r4 = func_02012138(a0);
    if (func_02013D74((u16)a2) == 0 || r4 == 0) {
        goto done;
    }
    for (i = 0; i < 0x19; i++) {
        if (a2 == gTbl_0209FFF4[i].a) {
            if (func_020142E8(r6, gTbl_0209FFF4[i].b) == 0) {
                if (func_0215843C(r4) == 0x14) return 0xd;
                return 0xe;
            }
            if (func_0215843C(r4) == 0x14) return 0xa;
            return 0xb;
        }
    }
done:
    return 0xffff;
}
