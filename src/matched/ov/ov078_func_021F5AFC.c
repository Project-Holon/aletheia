/*
 * function: ENCEFF_StartRippleBurst
 * address:  0x021F5AFC
 * packet:   pkt_ov078_021F5AFC
 * region:   ov078
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Twin of ov078 ENCEFF_StartRipple with different constants.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   ENCEFF_AllocWork  0x021CF52C  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   ENCEFF_RippleEventMain  0x021F5748  thumb  ov078
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03672.h"

typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;

struct Ctx;
struct Desc;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetEncEff(unsigned char *p);
extern u32 ENCEFF_AllocWork(u32 *p, int size, int heap);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int ENCEFF_RippleEventMain(void *task, int *st);

void *ENCEFF_StartRippleBurst(void *a)
{
    u8 *w;
    void *h;
    int i;

    w = (u8 *)ENCEFF_AllocWork((u32 *)FIELDMAP_GetEncEff((unsigned char *)((int)GAMESYSTEM_GetFieldMap(a))), 0x19E0, 0x50);
    h = func_020122C0(a, 0, (void (*)(void))ENCEFF_RippleEventMain, 0);
    ((struct Obj03672 *)w)->f19CA = 7;
    ((struct Obj03672 *)w)->f19C8 = 0;
    ((struct Obj03672 *)w)->f19CC = 2;
    ((struct Obj03672 *)w)->f19D0 = 0x555;
    ((struct Obj03672 *)w)->f19CE = 0x2d;
    ((struct Obj03672 *)w)->f19D8 = 0x37;
    ((struct Obj03672 *)w)->f19DC = 0;
    for (i = 0; i < 0x339; i++) {
        s16 *e = (s16 *)(w + i * 6);

        e[0] = ((i % 33) << 12) / 16;
        e[1] = ((i / 33) << 12) / 16;
        e[2] = 0;
    }
    ((struct Obj03672 *)w)->f19D4 = 3;
    return h;
}
