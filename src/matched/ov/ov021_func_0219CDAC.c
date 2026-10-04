/*
 * function: func_0219CDAC
 * address:  0x0219CDAC
 * packet:   pkt_ov021_0219CDAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Commits pending 0xC-byte entries through func_0219CE60, then compacts the
 * table so the free (0xFFFF) entries sit at the end.
 *
 * symbols:
 *   func_0219CE60  0x0219CE60  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03579.h"
#include "../include/Obj04224.h"
#include "../include/Obj05011.h"
#include "../include/Obj19665.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 a, b, c; } E12;

extern int func_0219CE60(u8 *, u32, u32, u32, u16, u32);

void func_0219CDAC(u8 *o)
{
    u8 *ctx = *(u8 * *)&((struct Obj03579 *)o)->f1C;
    u32 j = 0;
    u32 k = 0;
    u8 *e = *(u8 * *)&((struct Obj05011 *)ctx)->fC;
    u8 *base;
    for (; j < ((struct Obj05011 *)ctx)->f4; j++, e += 0xc) {
        if (((struct Obj04224 *)e)->f0 != 0xFFFF) {
            if (func_0219CE60(o, ((struct Obj04224 *)e)->f0, e[4], e[5], ((struct Obj04224 *)e)->f2, ((struct Obj04224 *)e)->f8) == 0)
                break;
            ((struct Obj04224 *)e)->f0 = 0xFFFF;
            k++;
            if (k >= ((struct Obj05011 *)ctx)->f6)
                break;
        }
    }
    if (k != 0) {
        j = 0;
        base = *(u8 * *)&((struct Obj05011 *)ctx)->fC;
        for (; j < (u32)((struct Obj05011 *)ctx)->f4 - 1; j++) {
            E12 *ent = (E12 *)(base + 12 * j);
            if (((struct Obj19665 *)ent)->f0 == 0xFFFF) {
                for (k = j + 1; k < ((struct Obj05011 *)ctx)->f4; k++) {
                    if (*(u16 *)(base + 12 * k) != 0xFFFF) {
                        *ent = *(E12 *)(base + 12 * k);
                        *(u16 *)(base + 12 * k) = 0xFFFF;
                        break;
                    }
                }
            }
        }
    }
}
