/*
 * file:     unit_021BA81C_p01.c
 * unit:     yes
 * function: func_021BA81C, func_021BA828, func_021BA858
 * address:  0x021BA81C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   data_021C39E0  0x021C39E0  data  a4
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201FDA0 0x0201FDA0 thumb
 *   data_021C371A 0x021C371A data a2
 *   func_0201FEBC 0x0201FEBC thumb
 */
#include "../../matched/include/Obj00008.h"

struct WinDat;
struct BmpMenu;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021BA81C;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef unsigned int u32_021BA828;

typedef unsigned int u32_021BA858;

extern void func_0201DD68(void);
extern struct BmpMenu *func_0201FDA0(const struct WinDat *, u16, u8, u8, u16);
extern u32_021BA858 func_0201FEBC(u8 *);
u32_021BA81C func_021BA81C(int i);
void func_021BA828(char *p);
u32_021BA858 func_021BA858(char *p);
extern u32_021BA81C data_021C39E0[];
extern const struct WinDat data_021C371A;


u32_021BA81C func_021BA81C(int i)
{
    return data_021C39E0[i];
}

void func_021BA828(char *p)
{
    func_0201DD68();
    *(struct BmpMenu * *)&((struct Obj00008 *)p)->f108 = func_0201FDA0(&data_021C371A, ((struct Obj00008 *)p)->f1334, 14, 0, 0x21);
}

u32_021BA858 func_021BA858(char *p)
{
    u32_021BA858 r = func_0201FEBC(*(u8 * *)&((struct Obj00008 *)p)->f108);
    if (r != 0xFFFFFFFF)
        *(u32_021BA858 *)&((struct Obj00008 *)p)->f108 = 0;
    return r;
}
