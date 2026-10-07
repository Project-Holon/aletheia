/*
 * file:     fldmmdl_p36.c
 * unit:     yes
 * function: func_0216E2AC, func_0216E2E0
 * address:  0x0216E2AC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj12404.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u16 w[14];
} Rec;

void func_0216E2AC(void *p, u32 i, Rec *out);
u16 func_0216E2E0(void *p);


/*
 * Unlabelled leaf, blocker of ov021 func_0219C680: copies record i (28 bytes) from the table at +0x44.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
void func_0216E2AC(void *p, u32 i, Rec *out)
{
    u16 *t = *(u16 * *)&((struct Obj12404 *)p)->f44;

    if (i < t[0]) {
        u16 k = (t[0] + 1) / 2 * 2;
        Rec *r = (Rec *)(t + (k + 2));

        *out = r[i];
    }
}


/*
 * Unlabelled leaf, blocker of ov021 func_0219C680: count halfword of the table at +0x44.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u16 func_0216E2E0(void *p)
{
    return **(u16 * *)&((struct Obj12404 *)p)->f44;
}
