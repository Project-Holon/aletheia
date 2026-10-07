/*
 * file:     b_bag_main_p03.c
 * unit:     yes
 * function: func_0220C3B4, func_0220C40C, func_0220C448, func_0220C4D4, func_0220C4EC
 * address:  0x0220C3B4
 * region:   ov197
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   sub_0204B100 0x0204B100 arm
 *   d_0220DBBC 0x0220DBBC data a4
 *   func_0220C6E8 0x0220C6E8 thumb ov197
 *   func_0220C6C0 0x0220C6C0 thumb ov197
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_0220C714 0x0220C714 thumb ov197
 *   func_0220C538 0x0220C538 thumb ov197
 *   func_0220C574 0x0220C574 thumb ov197
 *   func_0220C618 0x0220C618 thumb ov197
 */
#include "../../matched/include/Obj00315.h"
#include "../../matched/include/Obj25033.h"
#include "../../matched/include/Obj25034.h"
#include "../../matched/include/Obj25035.h"

struct Obj;
struct Bank;
struct Vec2;
typedef unsigned short u16;

typedef struct { u16 a,b,c; unsigned char d,e; } Config;

typedef unsigned char u8;

typedef short s16;

typedef unsigned int u32;

extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern struct Bank *sub_0204B100(int,u8,u32);
extern void func_0220C6E8(char *);
extern void func_0220C6C0(char *);
extern void func_0204B3B4(struct Obj *);
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
extern void func_0204AFD8(unsigned);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0220C714(char *);
extern void func_0220C538(char *);
extern void func_0220C574(char *);
extern void func_0220C618(char *);
struct Obj *func_0220C3B4(char *p,const int *indices);
void func_0220C40C(char *p);
void func_0220C448(char *p);
void func_0220C4D4(int a, int b);
void func_0220C4EC(char *p, int mode);
extern const int d_0220DBBC[];

/*
 * matching: const indices restores the load/store scheduling; mutable indices differ in 29 bytes.
 */
struct Obj *func_0220C3B4(char *p,const int *indices)
{
    Config c;
    c.a=0;c.b=0;c.c=0;c.d=1;c.e=1;
    return func_0204B294((void *)*(unsigned *)&((struct Obj00315 *)p)->f420,*(unsigned *)(p+indices[0]*4+0x544),*(unsigned *)(p+indices[1]*4+0x568),*(unsigned *)(p+indices[2]*4+0x58c),&c,1,((struct Obj25033 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
}

/*
 * Raw byte stride i*12 emits muls rather than the flat word-index shift/add.
 * The caller stores live r0 from C3B4; its owner declaration is void.
 */
void func_0220C40C(char *p) { u32 i; *(struct Bank * *)&((struct Obj00315 *)p)->f420=sub_0204B100(67,0,((struct Obj25034 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC); for(i=0;i<63;i++) *(u32 *)(p+i*4+0x424)=(u32)func_0220C3B4(p,(const int *)((u32)d_0220DBBC+i*12)); }

void func_0220C448(char *p)
{
    unsigned i;
    func_0220C6E8(p);
    for (i = 0; i < 63; i++) func_0204B3B4(*(struct Obj **)(p + i * 4 + 0x424));
    func_0220C6C0(p);
    for (i = 0; i < 9; i++) if (*(int *)(p + i * 4 + 0x544) != -1) func_0204A8D4(*(int *)(p + i * 4 + 0x544));
    for (i = 0; i < 9; i++) if (*(int *)(p + i * 4 + 0x568) != -1) func_0204ADA4(*(int *)(p + i * 4 + 0x568));
    for (i = 0; i < 3; i++) if (*(int *)(p + i * 4 + 0x58c) != -1) func_0204AFD8(*(int *)(p + i * 4 + 0x58c));
    func_0204B1CC(*(struct Bank * *)&((struct Obj25035 *)p)->f420);
}


void func_0220C4D4(int a, int b)
{
    func_0204B3DC((struct Obj *)a, 1);
    func_0204B404((struct Obj *)a, (const struct Vec2 *)b, 1);
}

void func_0220C4EC(char *p, int mode)
{
    unsigned int i;
    for (i = 0; i < 63; i++) func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x424), 0);
    func_0220C714(p);
    switch (mode) {
    case 0: func_0220C538(p); break;
    case 1: func_0220C574(p); break;
    case 2: func_0220C618(p); break;
    }
}
