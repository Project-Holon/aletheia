/*
 * file:     field_effect_p20.c
 * unit:     yes
 * function: func_021AAB48, func_021AAB54
 * address:  0x021AAB48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012A38  0x02012A38  thumb
 */
#include "../../matched/include/Obj19848.h"
#include "../../matched/include/Obj19849.h"

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct {
    u8 pad[0xd];
    u8 lo : 4;
    u8 mid : 2;
    u8 hi : 2;
} Sub;

typedef struct {
    u8 pad[0x10];
    Sub sub;
} T;

typedef struct {
    char pad[0x5b4];
    int f5b4;
} D;

typedef struct {
    int pad[2];
    int f8;
    int fc;
    D *f10;
} S;

extern T *func_02012A38(int a);
u16 func_021AAB48(char *p);
void func_021AAB54(S *s);


u16 func_021AAB48(char *p)
{
    return ((struct Obj19849 *)(*(char * *)&((struct Obj19848 *)p)->f10))->f5BC;
}


void func_021AAB54(S *s)
{
    Sub *b = &func_02012A38(s->f8)->sub;
    if (b->lo) {
        b->mid = 1;
    }
}
