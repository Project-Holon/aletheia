/*
 * file:     un_select_p08.c
 * unit:     yes
 * function: func_021BA138, func_021BA1A0, func_021BA1C0, func_021BA208, func_021BA21C
 * address:  0x021BA138
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
 *   func_021B991C 0x021B991C thumb ov218
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021B9F98 0x021B9F98 thumb ov218
 *   func_021B9944 0x021B9944 thumb ov218
 *   func_021B9C74 0x021B9C74 thumb ov218
 *   func_021B9914 0x021B9914 thumb ov218
 *   func_021B61F8 0x021B61F8 thumb ov067
 *   func_0204E804 0x0204E804 arm
 *   func_02024004 0x02024004 thumb
 *   func_021B61FC 0x021B61FC thumb ov067
 *   func_021B6200 0x021B6200 thumb ov067
 *   func_021B9924 0x021B9924 thumb ov218
 *   func_021B9B78 0x021B9B78 thumb ov218
 *   func_021B9C00  0x021B9C00  thumb  ov218
 */
#include "../../matched/include/Obj04644.h"
#include "../../matched/include/Obj26046.h"
#include "../../matched/include/Obj26047.h"
#include "../../matched/include/Obj26048.h"

struct TaskMenu;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short s16;

extern void func_021B991C(void *);
extern u32 func_020279E8(struct TaskMenu *m);
extern unsigned char func_02027A04(const unsigned char *);
extern void func_021B9F98(u8 *p, int mode);
extern void func_021B9944(void);
extern void func_021B9C74(u8 *p);
extern void func_021B9914(struct TaskMenu *p);
extern void func_021B61F8(unsigned char *task, int value);
extern int func_0204E804(void);
extern int func_02024004(int);
extern unsigned func_021B61FC(const unsigned char *);
extern void func_021B6200(unsigned char *);
extern int func_021B9924(void);
extern void func_021B9B78(char *p, u32 id);
extern int func_021B9C00(char *p);
int func_021BA138(unsigned char *task, char *ctx);
int func_021BA1A0(void);
int func_021BA1C0(unsigned char *task, char *ctx);
int func_021BA208(void *unused, char *p);
int func_021BA21C(unsigned char *task, char *ctx);
void func_021BA238(void);

int func_021BA138(unsigned char *task, char *ctx)
{
    func_021B991C(((struct Obj04644 *)ctx)->f1C);
    if (func_020279E8(((struct Obj04644 *)ctx)->f1C) != 0) {
        switch (func_02027A04(((struct Obj04644 *)ctx)->f1C)) {
        case 0:
            func_021B9F98((u8 *)ctx, 0);
            func_021B9944();
            func_021B9C74(((struct Obj04644 *)ctx)->f28);
            func_021B9914(((struct Obj04644 *)ctx)->f1C);
            func_021B61F8(task, 65534);
            break;
        case 1:
            func_021B9944();
            func_021B9C74(((struct Obj04644 *)ctx)->f28);
            func_021B9914(((struct Obj04644 *)ctx)->f1C);
            func_021B61F8(task, 0);
            break;
        }
        return 1;
    }
    return 0;
}

int func_021BA1A0(void){if(func_0204E804()==1 || func_02024004(1)==0)return 0;return 1;}

int func_021BA1C0(unsigned char *task, char *ctx)
{
    switch (func_021B61FC(task)) {
    case 0:
        func_021B9924();
advance:
        func_021B6200(task);
        break;
    case 1:
        if (func_0204E804() == 1)
            break;
        if (func_02024004(1) == 0)
            break;
        func_021B9B78(((struct Obj26046 *)ctx)->f28, 0xef);
        goto advance;
    case 2:
        return 1;
    }
    return 0;
}


int func_021BA208(void *unused, char *p)
{
    return func_021B9C00((char *)(((struct Obj26047 *)p)->f28)) != 0;
}

int func_021BA21C(unsigned char *task, char *ctx)
{
    func_021B9944();
    func_021B9C74(((struct Obj26048 *)ctx)->f28);
    func_021B61F8(task, 0);
    return 1;
}

void func_021BA238(void)
{
    int count = *(volatile unsigned short *)0x04000006;
    if (count >= 152)
        *(volatile unsigned short *)0x04001052 = 0x050b;
    else if (count >= 112)
        *(volatile unsigned short *)0x04001052 = 0x060a;
    else if (count >= 72)
        *(volatile unsigned short *)0x04001052 = 0x0709;
    else if (count >= 32)
        *(volatile unsigned short *)0x04001052 = 0x0808;
    else
        *(volatile unsigned short *)0x04001052 = 0x0a06;
}
