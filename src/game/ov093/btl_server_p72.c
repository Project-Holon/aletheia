/*
 * file:     btl_server_p72.c
 * unit:     yes
 * function: func_021C5A1C, func_021C5A34, func_021C5A4C
 * address:  0x021C5A1C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj13335.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021CD64C(void *w, u8 id, ...);
void func_021C5A1C(u8 *p, u8 *a);
void func_021C5A34(u8 *p, u8 *a);
void func_021C5A4C(u8 *p, u8 *a, int b, int c);

void func_021C5A1C(u8 *p, u8 *a)
{
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x57, func_021D5440(a));
}

void func_021C5A34(u8 *p, u8 *a)
{
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x58, func_021D5440(a));
}


void func_021C5A4C(u8 *p, u8 *a, int b, int c)
{
    u8 n = func_021D5440(a);
    if (c > 0) {
        func_021CD64C(((struct Obj13335 *)p)->fC, 0x5b, 0x99, n, b, 0xffff0000);
    } else {
        func_021CD64C(((struct Obj13335 *)p)->fC, 0x5b, 0xae, n, b, 0xffff0000);
    }
}
