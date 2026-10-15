/*
 * file:     wf2dmap_objcmd.c
 * unit:     yes
 * function: func_021C4CB4, func_021C4CE4, func_021C4D34, func_021C4D98, func_021C4E2C, func_021C4EC0, func_021C4F10, func_021C4F74, func_021C5008, func_021C509C, func_021C5100, func_021C5164, func_021C51C8, func_021C522C, func_021C5230, func_021C5238, func_021C5278, func_021C52CC, func_021C5300, func_021C5334, func_021C5370, func_021C539C, func_021C53C8, func_021C5404, func_021C5478, func_021C5488, func_021C54B4, func_021C54C4, func_021C54EC
 * address:  0x021C4CB4
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C49A4 0x021C49A4 thumb ov127
 *   d_021C604C 0x021C604C data a4
 *   func_021C4B7C 0x021C4B7C thumb ov127
 *   func_021C4B90 0x021C4B90 thumb ov127
 *   func_021C4A00 0x021C4A00 thumb ov127
 *   func_021C4AC4 0x021C4AC4 thumb ov127
 *   func_021C4A54 0x021C4A54 thumb ov127
 *   func_021C4994 0x021C4994 thumb ov127
 *   d_021C607C 0x021C607C data a4
 *   func_021C5564 0x021C5564 thumb ov127
 *   WF2DMAP_ACTOR_FIND_HasMatch 0x021C5550 thumb ov127
 *   func_021C4844 0x021C4844 thumb ov127
 */
#include "../../matched/include/Obj00535.h"
#include "../../matched/include/Obj10473.h"
#include "../../matched/include/Obj08124.h"
#include "../../matched/include/Obj04502.h"
#include "../../matched/include/Obj10474.h"
#include "../../matched/include/Obj10475.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { short x, y; } Pos;

typedef int (*Callback)(void *,void *,void *,const u8 *,void *);

extern int func_021C49A4(u8 *,unsigned);
extern void func_021C4B7C(char *, Pos);
extern void func_021C4B90(char *, Pos);
extern void func_021C4A00(void *, int, int);
extern Pos func_021C4AC4(void *);
extern Pos func_021C4A54(Pos,int);
extern char *func_021C4994(unsigned *p, unsigned id);
extern void func_021C5564(u8 *,void *,int,int,int);
extern int WF2DMAP_ACTOR_FIND_HasMatch(void *, void *, int);
extern int func_021C4844(u8 *p, u16 x, u16 y);
void func_021C4CB4(u8 *p);
void func_021C4CE4(char *p, Pos v, int n);
void func_021C4D34(char *p, Pos v, int n);
void func_021C4D98(char *p, Pos v, int n);
void func_021C4E2C(char *p, Pos v, int n);
void func_021C4EC0(char *p, Pos v, int n);
void func_021C4F10(char *p, Pos v, int n);
void func_021C4F74(char *p, Pos v, int n);
void func_021C5008(char *p, Pos v, int n);
void func_021C509C(char *p, Pos v, int n);
void func_021C5100(char *p, Pos v, int n);
void func_021C5164(char *p, Pos v, int n);
void func_021C51C8(void *p, Pos v, int n);
int func_021C522C(void);
int func_021C5230(void *p);
int func_021C5238(void *p);
int func_021C5278(void *p);
int func_021C52B8(void);
int func_021C52BC(void *p);
int func_021C52C4(void *p);
Pos func_021C52CC(Pos p,int i);
int func_021C5300(u8 *p);
void func_021C5334(char *p);
int func_021C5370(void *a, void *b, const u8 *desc, int *out);
int func_021C539C(u8 *p,int a,int b,const u8 *desc,u8 *out);
int func_021C53C8(u8 *p,int a,int b,const u8 *desc,u8 *out);
int func_021C5404(void *p, void *q, void *r, const u8 *s, void *t);
void func_021C5478(int a, int b, int c, int d, int e);
int func_021C5488(u8 *p,int a,int b,const u8 *desc,u8 *out);
int func_021C54B0(void);
void func_021C54B4(int a, int b, int c, int d, int e);
int func_021C54C4(u8 *p,int a,int b,const u8 *desc,u8 *out);
int func_021C54EC(void *p, void *q, int n);
extern const Callback d_021C607C[];







extern int (*d_021C604C)(u8 *);







void func_021C4CB4(u8 *p)
{
 int i=func_021C49A4(p,5); int r=(*(int (**)(u8 *))((unsigned)&d_021C604C+i*4))(p);
 (((struct Obj00535 *)p)->f16)++;
 if(r==1) {func_021C5334((char *)p); ((struct Obj00535 *)p)->f16=0;}
}







/*
 * extent: next larger wrapper starts at 0x021C4D34, its initial push
 *         is included by the stale label extent; filed separately.
 */
void func_021C4CE4(char *p, Pos v, int n)
{
    func_021C4B7C(p, v);
    func_021C4B90(p, v);
    func_021C4A00(p, 6, n);
    func_021C4A00(p, 5, 0);
}







/*
 * start: corrected from second label at initial push plus two bytes.
 */
void func_021C4D34(char *p, Pos v, int n)
{
    func_021C4B7C(p, v);
    func_021C4B90(p, v);
    func_021C4A00(p, 6, n);
    func_021C4A00(p, 5, 1);
    func_021C4A00(p, 8, 0);
    func_021C4A00(p, 9, 2);
}







void func_021C4D98(char *p, Pos v, int n)
{
    Pos x = func_021C52CC(v, n);
    func_021C4B90(p, v);
    func_021C4B7C(p, x);
    func_021C4A00(p, 6, n);
    func_021C4A00(p, 5, 2);
    func_021C4A00(p, 8, 0);
    func_021C4A00(p, 9, 8);
}







void func_021C4E2C(char *p, Pos v, int n)
{
    Pos x = func_021C52CC(v, n);
    func_021C4B90(p, v);
    func_021C4B7C(p, x);
    func_021C4A00(p, 6, n);
    func_021C4A00(p, 5, 3);
    func_021C4A00(p, 8, 0);
    func_021C4A00(p, 9, 4);
}







void func_021C4EC0(char *p, Pos v, int n)
{
    func_021C4B7C(p, v);
    func_021C4B90(p, v);
    func_021C4A00(p, 6, n);
    func_021C4A00(p, 5, 4);
}







void func_021C4F10(char *p, Pos v, int n)
{
    func_021C4B7C(p, v);
    func_021C4B90(p, v);
    func_021C4A00(p, 6, n);
    func_021C4A00(p, 5, 5);
    func_021C4A00(p, 8, 0);
    func_021C4A00(p, 9, 16);
}







void func_021C4F74(char *p, Pos v, int n)
{
    Pos x = func_021C52CC(v, n);
    func_021C4B90(p, v);
    func_021C4B7C(p, x);
    func_021C4A00(p, 6, n);
    func_021C4A00(p, 5, 6);
    func_021C4A00(p, 8, 0);
    func_021C4A00(p, 9, 16);
}







void func_021C5008(char *p, Pos v, int n)
{
    Pos x = func_021C52CC(v, n);
    func_021C4B90(p, v);
    func_021C4B7C(p, x);
    func_021C4A00(p, 6, n);
    func_021C4A00(p, 5, 7);
    func_021C4A00(p, 8, 0);
    func_021C4A00(p, 9, 4);
}






void func_021C509C(char *p, Pos v, int n)
{
    func_021C4B90(p, v);
    func_021C4B7C(p, v);
    func_021C4A00(p, 6, n);
    func_021C4A00(p, 5, 8);
    func_021C4A00(p, 8, 0);
    func_021C4A00(p, 9, 2);
}






void func_021C5100(char *p, Pos v, int n)
{
    func_021C4B90(p, v);
    func_021C4B7C(p, v);
    func_021C4A00(p, 6, n);
    func_021C4A00(p, 5, 9);
    func_021C4A00(p, 8, 0);
    func_021C4A00(p, 9, 4);
}




void func_021C5164(char *p, Pos v, int n)
{
    func_021C4B90(p, v);
    func_021C4B7C(p, v);
    func_021C4A00(p, 6, n);
    func_021C4A00(p, 5, 10);
    func_021C4A00(p, 8, 0);
    func_021C4A00(p, 9, 8);
}




void func_021C51C8(void *p, Pos v, int n)
{
    func_021C4B90(p, v);
    func_021C4B7C(p, v);
    func_021C4A00(p, 6, n);
    func_021C4A00(p, 5, 11);
    func_021C4A00(p, 8, 0);
    func_021C4A00(p, 9, 16);
}




/*
 * extent: handed 021C51CA is the second push after 0F B4 at 021C51C8.
 */
int func_021C522C(void) { return 0; }




int func_021C5230(void *p) { return func_021C5300(p); }





int func_021C5238(void *p)
{
    int r = func_021C5300(p);
    if (r == 1) {
        Pos v = func_021C4AC4(p);
        func_021C4B90(p, v);
    }
    return r;
}





int func_021C5278(void *p)
{
    int r = func_021C5300(p);
    if (r == 1) {
        Pos v = func_021C4AC4(p);
        func_021C4B90(p, v);
    }
    return r;
}





int func_021C52B8(void) { return 0; }





int func_021C52BC(void *p) { return func_021C5300(p); }





int func_021C52C4(void *p) { return func_021C5300(p); }





Pos func_021C52CC(Pos p,int i)
{
 return func_021C4A54(p,i);
}



int func_021C5300(u8 *p)
{
 int a=func_021C49A4(p,8), b=func_021C49A4(p,9);
 if(a<b) { func_021C4A00(p,8,a+1); if(a+1<b) return 0; }
 return 1;
}



void func_021C5334(char *p) { Pos v=func_021C4AC4(p); func_021C4CE4(p,v,func_021C49A4((u8 *)p,6)); }



int func_021C5370(void *a, void *b, const u8 *desc, int *out) { return d_021C607C[*(u16 *)desc](func_021C4994(b,desc[3]),a,b,desc,out); }



int func_021C539C(u8 *p,int a,int b,const u8 *desc,u8 *out) { int v=func_021C49A4(p,5);  if(v==0 || v==4) { func_021C5564(out,p,((struct Obj10473 *)desc)->f0,desc[3],desc[2]); return 1; } return 0; }


int func_021C53C8(u8 *p,int a,int b,const u8 *desc,u8 *out) { int v=func_021C49A4(p,5); int w=func_021C49A4(p,6); if(v==0 && w!=desc[2]) { func_021C5564(out,p,((struct Obj08124 *)desc)->f0,desc[3],desc[2]); return 1; } return 0; }


int func_021C5404(void *p, void *q, void *r, const u8 *s, void *t)
{
    int v = func_021C49A4(p, 5);
    if (v == 0 && func_021C54EC(p, q, s[2]) != 1 && WF2DMAP_ACTOR_FIND_HasMatch(p, r, s[2]) != 1) {
        func_021C5564(t, p, ((struct Obj04502 *)s)->f0, s[3], s[2]);
        return 1;
    }
    if (v == 0 && func_021C49A4(p, 10) >= 8) {
        func_021C5564(t, p, 5, s[3], s[2]);
        return 1;
    }
    return 0;
}



/*
 * Addresses are Black-image addresses.
 */
void func_021C5478(int a, int b, int c, int d, int e)
{
    func_021C5404((void *)a, (void *)b, (void *)c, (const u8 *)d, (void *)e);
}


int func_021C5488(u8 *p,int a,int b,const u8 *desc,u8 *out) { int v=func_021C49A4(p,5);  if(v==0) { func_021C5564(out,p,((struct Obj10474 *)desc)->f0,desc[3],desc[2]); return 1; } return 0; }


int func_021C54B0(void) { return 0; }



void func_021C54B4(int a, int b, int c, int d, int e)
{
    func_021C5404((void *)a, (void *)b, (void *)c, (const u8 *)d, (void *)e);
}


int func_021C54C4(u8 *p,int a,int b,const u8 *desc,u8 *out) { int v=func_021C49A4(p,5);  if(v==0) { func_021C5564(out,p,((struct Obj10475 *)desc)->f0,desc[3],desc[2]); return 1; } return 0; }


int func_021C54EC(void *p, void *q, int n)
{
    Pos b = func_021C4AC4(p);
    Pos d = func_021C4A54(b, n);
    return func_021C4844(q, d.x / 16, d.y / 16);
}
