/*
 * file:     cg_help_p03.c
 * unit:     yes
 * function: func_021D485C, func_021D48A4
 * address:  0x021D485C
 * region:   ov124
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   d_021D4BE4 0x021D4BE4 data a1
 *   func_02035C08 0x02035C08 arm
 *   func_021D4940 0x021D4940 thumb ov124
 *   func_0202822C 0x0202822C thumb
 *   func_02012204 0x02012204 thumb
 */
#include "../../matched/include/Obj00991.h"
#include "../../matched/include/Obj00122.h"
#include "../../matched/include/Obj22992.h"

struct Descriptor;
struct PrintSys;
struct Rec;
struct TaskMenuState;
struct Ctx;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef struct { u8 bytes[16]; } Table16;

extern void func_02028148(u8 *p);
extern unsigned int func_02027FD8(struct TaskMenuState *s);
extern void func_0201C4C0(struct PrintSys *p);
extern unsigned int func_020452E8(struct Descriptor *d);
extern unsigned int func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_0201DD68(void *);
extern int func_02035C08(const void *p);
extern void func_021D4940(char *,int);
extern void func_0202822C(char *p, int v);
extern void func_020061E4(u32 a);
extern u32 func_02012204(const struct Ctx *p);
void func_021D485C(char *p);
void func_021D48A4(char *p);
extern const Table16 d_021D4BE4;

void func_021D485C(char *p)
{
    if (((struct Obj00991 *)p)->f3C) func_02028148(((struct Obj00991 *)p)->f3C);
    if (((struct Obj00991 *)p)->f38) func_02028148(((struct Obj00991 *)p)->f38);
    func_02028148(((struct Obj00991 *)p)->f40);
    func_02027FD8(((struct Obj00991 *)p)->f34);
    func_0201C4C0(((struct Obj00991 *)p)->f30);
    func_020452E8(((struct Obj00991 *)p)->f20);
    func_020452E8(((struct Obj00991 *)p)->f24);
    func_02045C04(((struct Obj00991 *)p)->f2C);
    func_0201DD68((void *)func_0201D83C(((struct Obj00991 *)p)->f28));
}

void func_021D48A4(char *p)
{
    Table16 table;
    table = d_021D4BE4;
    switch (func_02035C08(&table)) {
    case 0:
        if (((struct Obj00122 *)p)->f18 != 0) {
            (((struct Obj00122 *)p)->f18)--;
            func_021D4940(p,((struct Obj00122 *)p)->f18);
            func_0202822C(((struct Obj00122 *)p)->f38,1);
            func_020061E4(0x54c);
        }
        break;
    case 1:
        if (((struct Obj00122 *)p)->f18 < 11) {
            (((struct Obj00122 *)p)->f18)++;
            func_021D4940(p,((struct Obj00122 *)p)->f18);
            func_0202822C(((struct Obj00122 *)p)->f3C,1);
            func_020061E4(0x54c);
        }
        break;
    case 2:
        func_0202822C(((struct Obj00122 *)p)->f40,1);
        *(int *)&((struct Obj00122 *)p)->f10 = 2;
        func_020061E4(0x551);
        break;
    }
    if (func_02012204(((struct Obj22992 *)(*(char * *)&((struct Obj00122 *)p)->f4))->f4) == 1) {
        func_0202822C(((struct Obj00122 *)p)->f40,1);
        *(int *)&((struct Obj00122 *)p)->f10 = 2;
    }
}
