/*
 * file:     eventdata_system_p31.c
 * unit:     yes
 * function: func_02163E34, func_02163E58
 * address:  0x02163E34
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
 *   func_02163E1C  0x02163E1C  thumb  ov010
 */
#include "../../matched/include/Obj17719.h"
#include "../../matched/include/Obj17720.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int x, y, z; } VecFx32;

extern int func_02163E1C(void *a, char *b, void *c);
int func_02163E34(void *a0, VecFx32 *a1, u32 *a2);
int func_02163E58(void *a0, VecFx32 *a1, int *a2);


int func_02163E34(void *a0, VecFx32 *a1, u32 *a2)
{
    unsigned char fr[16];
    u32 *t4;
    int t5;
    int r;
t4 = a2;
t5 = 0;
*t4 = t5;
    r = func_02163E1C(a0, (char *)a1, fr);
loc_02163E44:
    if (r != 1) goto loc_02163E52;
loc_02163E48:
*t4 = ((struct Obj17719 *)fr)->f8;
    return 1;
loc_02163E52:
    return t5;
}


int func_02163E58(void *a0, VecFx32 *a1, int *a2)
{
    unsigned char fr[16];
    int *t4;
    int t5;
    int r;
t4 = a2;
t5 = 0;
*t4 = t5;
    r = func_02163E1C(a0, (char *)a1, fr);
loc_02163E68:
    if (r != 1) goto loc_02163E76;
loc_02163E6C:
*t4 = ((struct Obj17720 *)fr)->fC;
    return 1;
loc_02163E76:
    return t5;
}
