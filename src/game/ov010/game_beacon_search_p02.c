/*
 * file:     game_beacon_search_p02.c
 * unit:     yes
 * function: func_02164E04, func_02164E8C
 * address:  0x02164E04
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02178098  0x02178098  thumb ov014
 *   func_0203CF10  0x0203CF10  arm
 *   func_02164F9C  0x02164F9C  thumb ov010
 *   func_02177BF4  0x02177BF4  thumb ov014
 *   func_02164EB4 0x02164EB4 thumb ov010
 *   func_020267E4 0x020267E4 thumb
 */
#include "../../matched/include/Obj18986.h"

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

typedef struct Hdr { u8 x[2]; u8 b0:1; u8 b1:5; u8 b6:1; u8 b7:1; } Hdr;

typedef struct Obj { void *src; u8 gap[12]; Hdr hdr; } Obj;

extern u8 func_02178098(u8 i);
extern u32 func_0203CF10(u32 a);
extern Ent  *func_02164F9C(Ent *a, Ent *b);
extern void func_02177BF4(unsigned int idx);
extern void func_02164EB4(Hdr *,void *);
extern void func_020267E4(void *);
Ent *func_02164E04(u8 *obj, int *out);
void *func_02164E8C(Obj *p);


/*
 * Scans 16 slots for the best usable entry, stores its index through *out
 * and returns its record; 0 when none.
 *
 * Addresses are Black-image addresses.
 */
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
        if (r == 2 && ((struct Obj18986 *)obj)->fC != 0) {
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

/*
 * diagnostic: tu --suggest-split found one image-wide witness, at 02164E9C inside this caller; no viable partition.
 * extent: trailing two zero alignment bytes at 02164EB2; next labelled function 02164EB4.
 *
 * 2026-10-05 (D8 lane 15): 020267E4 now filed EXACT as src/matched/arm9/func_020267E4.c (MI_CpuCopy8(d_02146940+4, p, 0x5C)).
 * Re-run after the integrator regenerates the layout; expected EXACT.
 */
void *func_02164E8C(Obj *p) { func_02164EB4(&p->hdr,p->src); func_020267E4((u8 *)p+0x18); p->hdr.b1=2; return &p->hdr; }
