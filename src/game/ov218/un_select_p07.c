/*
 * file:     un_select_p07.c
 * unit:     yes
 * function: func_021B9FD8, func_021BA0B0
 * address:  0x021B9FD8
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_021B7AB0 0x021B7AB0 thumb ov067
 *   func_021B93A4 0x021B93A4 thumb ov067
 *   func_021B93B0 0x021B93B0 thumb ov067
 *   func_021B9280 0x021B9280 thumb ov067
 *   func_020061E4 0x020061E4 thumb
 *   func_021B61F8 0x021B61F8 thumb ov067
 *   func_021B9890 0x021B9890 thumb ov218
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_021B9F98 0x021B9F98 thumb ov218
 *   func_021B61FC 0x021B61FC thumb ov067
 *   func_021B6200 0x021B6200 thumb ov067
 *   func_021B9924 0x021B9924 thumb ov218
 *   func_021B9B78 0x021B9B78 thumb ov218
 *   func_021B9C00 0x021B9C00 thumb ov218
 *   func_021B9C88 0x021B9C88 thumb ov218
 *   func_021B9898 0x021B9898 thumb ov218
 *   func_0204E804 0x0204E804 arm
 *   func_02024004 0x02024004 thumb
 *   func_0201F048 0x0201F048 thumb
 *   tbl_021BAC80 0x021BAC80 data ov218 a4
 */
#include "../../matched/include/Obj02931.h"

struct S;
struct MsgBank;
struct TaskMenu;
struct WordSet;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

extern u32 func_020362DC(void);
extern int func_021B7AB0(struct S *p);
extern int func_021B93A4(char *);
extern int func_021B93B0(char *);
extern void func_021B9280(u8 *p, int a, u32 b);
extern void func_020061E4(u32);
extern void func_021B61F8(unsigned char *,int);
extern void func_021B9890(void *);
extern int func_021B6448(unsigned char *);
extern void func_021B9F98(u8 *p, int mode);
extern unsigned func_021B61FC(const unsigned char *p);
extern void func_021B6200(u8 *a);
extern int func_021B9924(void);
extern void func_021B9B78(char *p, u32 id);
extern int func_021B9C00(char *p);
extern u32 func_021B9C88(char *p);
extern struct TaskMenu *func_021B9898(void *arg, struct MsgBank *bank, u32 heap);
extern int func_0204E804(void);
extern int func_02024004(int a);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
int func_021B9FD8(unsigned char *task,char *p);
int func_021BA0AC(void);
u32 func_021BA0B0(u8 *a, u8 *b);
extern int tbl_021BAC80[];

int func_021B9FD8(unsigned char *task,char *p)
{
    int active=0;
    int selected;
    ((struct Obj02931 *)p)->f32C=0;
    if(func_020362DC()&0x200)active=1;
    else if(func_020362DC()&0x100)active=1;
    if(active) ((struct Obj02931 *)p)->f32C=1;
    if((u32)func_021B7AB0(((struct Obj02931 *)p)->f2C)<4){
        selected=func_021B93A4(*(char * *)&((struct Obj02931 *)p)->f2C);
        if(*(u32 *)((u32)p+0x34+(u32)selected*4)==1){
            ((struct Obj02931 *)p)->f30=selected;
            func_021B9280(((struct Obj02931 *)p)->f2C,(unsigned short)func_021B93B0(*(char * *)&((struct Obj02931 *)p)->f2C),3);
            func_020061E4(1356);
            func_021B61F8(task,**(unsigned char * *)&((struct Obj02931 *)p)->f20==131-selected ? 2 : 1);
            return 1;
        }
    }
    func_021B9890(((struct Obj02931 *)p)->f8);
    switch(func_021B6448(*(unsigned char * *)&((struct Obj02931 *)p)->f8)){
    case -1:case 0:case 2:case 3:case 4:case 5:break;
    case 1:
        func_021B9F98((u8 *)p,1);
        func_021B61F8(task,65534);
        return 1;
    }
    return 0;
}

int func_021BA0AC(void) { return 1; }

u32 func_021BA0B0(u8 *a, u8 *b)
{
    switch (func_021B61FC(a)) {
    case 0:
        func_021B9924();
    tail:
        func_021B6200(a);
        break;
    case 1:
        if (func_0204E804() == 1) break;
        if (func_02024004(1) == 0) break;
        func_0201F048((struct WordSet *)(*(u32 *)(*(u8 **)(b + 0x28) + 0x14)), 0, tbl_021BAC80[*(int *)(b + 0x30)]);
        func_021B9B78((char *)(*(u8 **)(b + 0x28)), 0xEA);
        goto tail;
    case 2:
        if (func_021B9C00((char *)(*(u8 **)(b + 0x28))) == 0) break;
        goto tail;
    case 3:
        *(u32 *)(b + 0x1C) = (u32)func_021B9898((void *)(*(u32 *)(b + 0x18)), (struct MsgBank *)func_021B9C88((char *)(*(u8 **)(b + 0x28))), *(u16 *)b);
        return 1;
    }
    return 0;
}
