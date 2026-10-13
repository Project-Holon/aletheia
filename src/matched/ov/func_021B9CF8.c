/*
 * function: WIFICLUBACTOR_FindActorFacing
 * address:  0x021B9CF8
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C4BA4  0x021C4BA4  thumb  ov127
 *
 * Asks the ov127 routine at 0x021C4BA4 for a handle (the word the caller
 * points at, plus the pointer at +0x58C) and then walks the 0x30 records of
 * 0x1C bytes at +0x30 looking for it; returns the record address or zero.
 * The record expression is written field-constant-first on the return
 * (`p + 0x30 + i * 0x1C`), which is the spelling whose register choice the
 * image has.
 */
#include "../include/Obj18152.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern u8 *func_021C4BA4(u8 *p, void *list, int n);

void *WIFICLUBACTOR_FindActorFacing(char *p, u32 *q, int c)
{
    void *v = func_021C4BA4((void *)*q, ((struct Obj18152 *)p)->f58C, c);
    int i;

    if (v != 0) {
        for (i = 0; i < 0x30; i++) {
            if (*(void **)(p + i * 0x1C + 0x30) == v) {
                return (char *)(p + 0x30) + i * 0x1C;
            }
        }
    }
    return 0;
}
