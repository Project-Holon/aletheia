/*
 * file:     unit_021BC240_p01.c
 * unit:     yes
 * function: func_021BC240, func_021BC274, func_021BC288, func_021BC298, func_021BC2B0
 * address:  0x021BC240
 * region:   ov209
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BCC58 0x021BCC58 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021BC2BC 0x021BC2BC thumb ov209
 *   func_02030EAC 0x02030EAC arm
 */
#include "../../matched/include/Obj00123.h"
#include "../../matched/include/Obj25533.h"

struct Obj0203159C;
struct S020315D4;
struct Node;
extern void func_0203064C(unsigned,unsigned,unsigned);
extern void *func_0203159C(struct Obj0203159C *,unsigned,unsigned);
extern void func_02082BCC(void *,int,int);
extern int func_021BCC58(char *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern void func_021BC2BC(void *,char *);
extern void func_02030EAC(struct Node *);
int func_021BC240(struct Obj0203159C *p,int unused,unsigned v);
int func_021BC274(int a, int b, int c, int d);
int func_021BC288(void *p);
void func_021BC298(char *p);
void func_021BC2B0(char *p);

int func_021BC240(struct Obj0203159C *p,int unused,unsigned v){unsigned *q;func_0203064C(1,107,0x60000);q=func_0203159C(p,0xc44,107);func_02082BCC(q,0,0xc44);*q=v;return 1;}


int func_021BC274(int a, int b, int c, int d)
{
    if (func_021BCC58((char *)d) == 0)
        return 1;
    return 0;
}


int func_021BC288(void *p)
{
    func_020315D4(p);
    func_020306F0(0x6b);
    return 1;
}

void func_021BC298(char *p){((struct Obj00123 *)p)->f4=func_020056A0((unsigned)func_021BC2BC,(unsigned)p,0);}

void func_021BC2B0(char *p){func_02030EAC(*(struct Node * *)&((struct Obj25533 *)p)->f4);}
