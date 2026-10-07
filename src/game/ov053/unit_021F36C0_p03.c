/*
 * file:     unit_021F36C0_p03.c
 * unit:     yes
 * function: func_021F3978, func_021F39BC, func_021F39D0, func_021F3A04
 * address:  0x021F3978
 * region:   ov053
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02048F60  0x02048F60  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021F3CF0     0x021F3CF0  data  a4
 *   func_02048F74 0x02048F74 arm
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_021C4E20 0x021C4E20 thumb ov021
 *   func_021C4E08 0x021C4E08 thumb ov021
 */
#include "../../matched/include/Obj09845.h"

struct Big;
struct Ctx;
struct Rec94;
typedef struct { int v[5]; } T5;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed int     s32;

extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern u32 func_020307B0(void *p);
extern void func_02048F74(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern unsigned func_021C4E20(void *);
extern void func_021C4E08(void *, int);
void func_021F3978(char *a);
void func_021F39BC(char *a);
void func_021F39D0(char *a, int b);
void func_021F3A04(char *a, int b);
extern T5 d_021F3CF0;


void func_021F3978(char *a)
{
    T5 t = d_021F3CF0;
    int i;

    for (i = 0; i < 5; i++) {
        int *p = func_02048F60(0x94, t.v[i], ((struct Obj09845 *)a)->f0);
        ((int *)(a + 0x30))[i] = p[0];
        ((int *)(a + 0x44))[i] = p[1];
        func_020307B0(p);
    }
}


void func_021F39BC(char *a)
{
    func_02048F74(a + 0x58, 0x94, 0, 0, (u32 *)12);
}


void func_021F39D0(char *a, int b)
{
    int i;
    int *p = (int *)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80((void *)b))), 1);
    for (i = 0; i < 5; i++)
        p[i] = (int)func_021C4E20(((void **)(a + 8))[i]) >> 12;
}


void func_021F3A04(char *a, int b)
{
    int i;
    int *p = (int *)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80((void *)b))), 1);
    for (i = 0; i < 5; i++)
        func_021C4E08(((void **)(a + 8))[i], (int)((unsigned)p[i] << 12));
}
