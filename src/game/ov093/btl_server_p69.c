/*
 * file:     btl_server_p69.c
 * unit:     yes
 * function: func_021C557C, func_021C5604
 * address:  0x021C557C
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
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D61F0  0x021D61F0  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 */
#include "../../matched/include/Obj06227.h"
#include "../../matched/include/Obj00003.h"

struct UtilSlots;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern void func_021D61F0(struct UtilSlots *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021CD64C(void *w, u8 id, ...);
void func_021C557C(u8 *p, u8 *a, int k, int flag);
void func_021C5604(u8 *p, u8 *a, int b);


void func_021C557C(u8 *p, u8 *a, int k, int flag)
{
    u8 n = func_021D5440(a);
    func_021D61F0((struct UtilSlots *)a);
    func_021CD4B0(((struct Obj06227 *)p)->fC, 0x10, n);
    func_021CD4B0(((struct Obj06227 *)p)->fC, 0x35, n, 0);
    if (flag != 0) {
        switch (k) {
        case 2:
            func_021CD64C(((struct Obj06227 *)p)->fC, 0x5b, 0x138, n, 0xffff0000);
            break;
        case 3:
            func_021CD64C(((struct Obj06227 *)p)->fC, 0x5b, 0x126, n, 0xffff0000);
            break;
        default:
            func_021CD64C(((struct Obj06227 *)p)->fC, 0x5b, 0x156, n, 0xffff0000);
            break;
        }
    }
}


void func_021C5604(u8 *p, u8 *a, int b)
{
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x59, func_021D5440(a), b);
}
