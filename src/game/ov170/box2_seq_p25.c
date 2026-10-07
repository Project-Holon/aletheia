/*
 * file:     box2_seq_p25.c
 * unit:     yes
 * function: func_021EA0BC, func_021EA114, func_021EA14C, func_021EA1C0, func_021EA1E8
 * address:  0x021EA0BC
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021EC768 0x021EC768 thumb
 *   func_021ED594 0x021ED594 thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_021EF680 0x021EF680 thumb
 *   func_021EF69C 0x021EF69C thumb
 *   func_02026124 0x02026124 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E0778 0x021E0778 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_020077B8 0x020077B8 thumb
 *   func_021E087C 0x021E087C thumb
 *   func_020307B0  0x020307B0  arm  arm9
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23957.h"
#include "../../matched/include/Obj18479.h"
#include "../../matched/include/Obj18480.h"

#define WORK(p) (*(char **)((p) + 0x2C))
struct Sound;
typedef struct {
    int pad[9];
    int x24;
} Top_021EA0BC;

typedef unsigned int   u32;

typedef struct {
    int pad0;
    void *x4;
} Top_021EA14C;

extern void func_021EC768(char *p, unsigned i, int flag);
extern void func_021ED594(char *p, unsigned i);
extern void func_021EE038(char *p, int a, int b, int c);
extern void func_021EF680(char *w);
extern void func_021EF69C(char *w);
extern void func_02026124(struct Sound *obj, u32 idx);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E0778(unsigned char *p);
extern void func_020061E4(unsigned se);
extern int func_020077B8(void *save, unsigned box);
extern int func_021E087C(unsigned char *p);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern u32 func_020307B0(void *p);
int func_021EA0BC(unsigned char *p, unsigned char i);
int func_021EA114(char *p, int a);
int func_021EA14C(unsigned char *p, unsigned i, int v);
void func_021EA1C0(void *p);
void func_021EA1E8(char *p);


int func_021EA0BC(unsigned char *p, unsigned char i)
{
    p[0x18] = 1;
    p[0x16] = i;
    func_021EC768(WORK(p), 0x24, 0);
    func_021ED594((char *)p, 0x24);
    func_021EE038((char *)p, 2, 1, 0);
    if ((*(Top_021EA0BC * *)&((struct Obj00000 *)p)->f0)->x24 == 4) {
        func_021EF680(WORK(p));
        func_021EF69C(WORK(p));
        func_02026124(*(void **)(WORK(p) + 0x70), 0x27);
    }
    return func_021E8FC0((char *)p, (int)func_021E0778, 0x20);
}

/*
 * Arm the flag, store the state byte, zero the 0x24 queue entry,
 *   re-stage it, publish (2,1,0) and set selector 0x021E0779.
 */
int func_021EA114(char *p, int a)
{
    ((struct Obj00000 *)p)->f18 = 1;
    ((struct Obj00000 *)p)->f16 = a;
    func_021EC768((char *)(*(int *)&((struct Obj00000 *)p)->f2C), 0x24, 0);
    func_021ED594(p, 0x24);
    func_021EE038(p, 2, 1, 0);
    return func_021E8FC0(p, 0x021E0779, 0x15);
}


int func_021EA14C(unsigned char *p, unsigned i, int v)
{
    if (i >= 0x1E && i >= 0x24 && i != 0xFF) {
        unsigned k = p[0x19] + i - 0x24;
        if (k >= p[0x15])
            k -= p[0x15];
        if (k == p[0x14]) {
            func_020061E4(0x557);
            return 0x15;
        }
        if (func_020077B8((*(Top_021EA14C * *)&((struct Obj00000 *)p)->f0)->x4, k) == 0) {
            func_020061E4(0x557);
            return 0x15;
        }
    }
    ((struct Obj23957 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA17E = i;
    p[0x1A] = 2;
    ((struct Obj00000 *)p)->f28 = v;
    func_021EA1C0(p);
    return func_021E8FC0((char *)p, (int)func_021E087C, 0x17);
}



/*
 * Allocate (0x4c, 0xb8, 1) into the 0x021F140C buffer and store
 * the handle at sub-object +0x60.
 */
void func_021EA1C0(void *p)
{
    int v = (int)func_02030734(0x4c, 0xb8, 1, (const char *)0x021F140C, 0x2130);
    *(int *)(((struct Obj18479 *)p)->f2C + 0x60) = v;
}


/*
 * Tail call func_020307B0 with the word at +0x2c/+0x60.
 */
void func_021EA1E8(char *p)
{
    func_020307B0(((struct Obj18480 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f60);
}
