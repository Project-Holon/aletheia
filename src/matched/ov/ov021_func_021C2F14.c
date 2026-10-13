/*
 * function: FLD3D_CI_FindPalette
 * address:  0x021C2F14
 * packet:   pkt_ov021_021C2F14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Builds a request block and dispatches FLD3D_CI_GetPlttDataOffset on success (EXACT*: pad).
 *
 * symbols:
 *   FLD3D_CI_CopyName  0x021C2F50  thumb  ov021
 *   FLD3D_CI_GetPlttDataOffset  0x021C2ECC  thumb  ov021
 */
#include "../include/Obj12922.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u32 v[4]; } T;

extern void FLD3D_CI_CopyName(char *dst, const char *src);
extern int func_0206E62C(void *a, T *t);
extern int FLD3D_CI_GetPlttDataOffset(u32 a, u32 b);

int FLD3D_CI_FindPalette(u8 *p, const char *name)
{
    T t;
    int r;

    FLD3D_CI_CopyName((char *)&t, name);
    if (p != 0 && ((struct Obj12922 *)p)->f34 != 0)
        r = func_0206E62C(p + ((struct Obj12922 *)p)->f34, &t);
    else
        r = 0;
    if (r == 0)
        return 0;
    return FLD3D_CI_GetPlttDataOffset((u32)p, r);
}
