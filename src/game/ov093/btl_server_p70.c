/*
 * file:     btl_server_p70.c
 * unit:     yes
 * function: func_021C572C, func_021C5750
 * address:  0x021C572C
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
 *   func_021CD64C 0x021CD64C thumb ov093
 */
#include "../../matched/include/Obj07752.h"
#include "../../matched/include/Obj21098.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u8 func_021D5440(u8 *p);
extern void func_021CD64C(void *, u8, ...);
void func_021C572C(u8 *p, u8 *a, u32 v);
void func_021C5750(u8 *p, u8 *a);

void func_021C572C(u8 *p, u8 *a, u32 v)
{
    func_021CD64C(((struct Obj07752 *)p)->fC, 0x5b, 213, func_021D5440(a), 0xffff0000);
}

void func_021C5750(u8 *p, u8 *a)
{
    func_021CD64C(((struct Obj21098 *)p)->fC, 0x5b, 210, func_021D5440(a), 0xffff0000);
}
