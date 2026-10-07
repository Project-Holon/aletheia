/*
 * file:     br_codein_p10.c
 * unit:     yes
 * function: func_021DD2FC, func_021DD33C, func_021DD37C
 * address:  0x021DD2FC
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_020061E4 0x020061E4 thumb
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02025538 0x02025538 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021DDE2C 0x021DDE2C thumb ov183
 *   func_021DD5C8 0x021DD5C8 thumb ov183
 */
#include "../../matched/include/Obj24577.h"
#include "../../matched/include/Obj24578.h"
#include "../../matched/include/Obj00631.h"
#include "../../matched/include/Obj00632.h"

struct Obj24810;
struct Obj0203159C;
typedef unsigned int   u32;

typedef unsigned short u16;

extern void func_021FD860(int obj, int one, int *args);
extern void func_020061E4(u32 a);
extern unsigned func_021F9B9C(struct Obj24810 *p);
extern void *func_0203159C(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void func_02082BCC(void *, int, unsigned int);
extern void *func_02025538(unsigned int a0, void *a1);
extern u32 func_0201C440(void *p);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern void func_021FBE54(char *, unsigned int, unsigned int);
extern void func_021DDE2C(char *, char *);
extern void func_021DD5C8(char *, char *);
int func_021DD2FC(char *p, int a, int b);
int func_021DD33C(char *p, int a, int b);
int func_021DD37C(void *a, int unused, char *q);

int func_021DD2FC(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x20) <= 0x48) &
             ((unsigned int)(b - 0x30) <= 0x10);
    if (ok) {
        int args[2];
        args[0] = a;
        args[1] = b;
        func_021FD860(((struct Obj24577 *)p)->f10, 1, args);
        func_020061E4(0x703);
    }
    return ok;
}

int func_021DD33C(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x90) <= 0x48) &
             ((unsigned int)(b - 0x30) <= 0x10);
    if (ok) {
        int args[2];
        args[0] = a;
        args[1] = b;
        func_021FD860(((struct Obj24578 *)p)->f10, 1, args);
        func_020061E4(0x703);
    }
    return ok;
}

/*
 * trailing: 2 zero alignment bytes at 0x021DD3F6
 */
int func_021DD37C(void *a, int unused, char *q)
{
    char *p = func_0203159C(a, 0x80, func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct Obj00632 *)q)->fC)));
    func_02082BCC(p, 0, 0x80);
    ((struct Obj00631 *)p)->f7C = func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct Obj00632 *)q)->fC));
    ((struct Obj00631 *)p)->f0 = func_02025538(((struct Obj00631 *)p)->f7C, ((struct Obj00632 *)q)->f4);
    ((struct Obj00631 *)p)->f4 = (void *)func_0201C440((void *)(((struct Obj00631 *)p)->f7C));
    ((struct Obj00631 *)p)->f74 = func_021FD760((unsigned int)(((struct Obj00632 *)q)->f4), (char *)(*(int *)&((struct Obj00632 *)q)->f8), 1, ((struct Obj00631 *)p)->f7C);
    func_021FBE54(*(char * *)&((struct Obj00632 *)q)->f8, 13, ((struct Obj00631 *)p)->f7C);
    func_021DDE2C(p, q);
    func_021DD5C8(p, q);
    return 1;
}
