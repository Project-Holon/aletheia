/*
 * file:     palette_anime_p04.c
 * unit:     yes
 * function: func_021C1638, func_021C1648, func_021C1658, func_021C1670, func_021C1680
 * address:  0x021C1638
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C16FC  0x021C16FC  thumb  ov217
 *   func_021C0E64  0x021C0E64  thumb  ov217
 *   func_021C16E8  0x021C16E8  thumb  ov217
 */
#include "../../matched/include/Obj04641.h"
#include "../../matched/include/Obj26011.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef struct {
    u32 w0;
    u32 w4;
    u32 type;
    u32 wc;
    u32 counter;
} Rec;

extern void *func_021C16FC(void *p, u32 v);
extern u32 func_021C0E64();
extern void func_021C16E8(u32 a0);
void func_021C1638(u8 *a0);
void func_021C1648(u8 *a0);
void func_021C1658(u32 a0);
void func_021C1670(u8 *a0);
void func_021C1680(Rec *p);

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
void func_021C1638(u8 *a0)
{
    if (((struct Obj04641 *)(((u8*)a0)))->f10 >= 30) {
    func_021C16FC(a0, 4);
    }
}

void func_021C1648(u8 *a0)
{
    if (((struct Obj04641 *)(((u8*)a0)))->f10 >= 20) {
    func_021C16FC(a0, 0);
    }
}

/*
 * When the +0x0c handle is idle, runs func_021C16E8().
 *
 * Addresses are Black-image addresses.
 */
void func_021C1658(u32 a0)
{
    if (func_021C0E64(((struct Obj26011 *)(((u8*)a0)))->fC) == 0) {
    func_021C16E8(a0);
    }
}

void func_021C1670(u8 *a0)
{
    if (((struct Obj04641 *)(((u8*)a0)))->f10 >= 60) {
    func_021C16FC(a0, 4);
    }
}


/*
 * Bumps the record's +0x10 counter, then selects a ceiling by the word at
 * +8 and clamps the counter to it (the ceiling is uninitialised on the
 * default path, which is how the image reads too).  Called once from
 * 0x021C1604 with only r0 live.
 *
 * Addresses are Black-image addresses.
 */
void func_021C1680(Rec *p)
{
    u32 v;

    p->counter++;
    switch (p->type) {
    case 0:
        v = (u32)-1;
        break;
    case 1:
        v = 0x78;
        break;
    case 2:
        v = 0x1e;
        break;
    case 3:
        v = 0x14;
        break;
    case 4:
        v = (u32)-1;
        break;
    case 5:
        v = 0x3c;
        break;
    }
    if (v < p->counter)
        p->counter = v;
}
