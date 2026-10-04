/*
 * function: func_02164E04
 * address:  0x02164E04
 * packet:   pkt_ov010_02164E04
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Scans 16 slots for the best usable entry, stores its index through *out
 * and returns its record; 0 when none.
 *
 * symbols:
 *   func_02178098  0x02178098  thumb ov014
 *   func_0203CF10  0x0203CF10  arm
 *   func_02164F9C  0x02164F9C  thumb ov010
 *   func_02177BF4  0x02177BF4  thumb ov014
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Ent {
    u8 b0;
    u8 lo : 4;
    u8 hi : 4;
    u8 flag : 1;
    u8 kind : 5;
    u8 rest : 2;
} Ent;

extern int   func_02178098(u8 a);
extern u32 func_0203CF10(u32 a);
extern Ent  *func_02164F9C(Ent *a, Ent *b);
extern void func_02177BF4(unsigned int idx);

Ent *func_02164E04(u8 *obj, int *out)
{
    int none = -1;
    int best = -1;
    int i;
    Ent *p;
    int r;
    for (i = 0; i < 16; i++) {
        r = func_02178098(i);
        if ((u32)(r - 2) > 1) {
            continue;
        }
        if (r == 2 && *(u32 *)(obj + 0xc) != 0) {
            continue;
        }
        p = (Ent *)func_0203CF10(i);
        if (p == 0) {
            continue;
        }
        if (p->lo < p->hi) {
            if (best == none) {
                best = i;
            } else if (func_02164F9C(p, (Ent *)func_0203CF10(best)) == p) {
                best = i;
            }
        } else {
            func_02177BF4(i);
        }
    }
    if (best != -1) {
        *out = best;
        return (Ent *)func_0203CF10(best);
    }
    return 0;
}
