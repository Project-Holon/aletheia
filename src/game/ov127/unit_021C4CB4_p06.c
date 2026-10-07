/*
 * file:     unit_021C4CB4_p06.c
 * unit:     yes
 * function: func_021C53C8, func_021C5404, func_021C5478, func_021C5488, func_021C54B4, func_021C54C4, func_021C54EC
 * address:  0x021C53C8
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
 *   func_021C5564 0x021C5564 thumb ov127
 *   func_021C5550 0x021C5550 thumb ov127
 *   func_021C4AC4 0x021C4AC4 thumb ov127
 *   func_021C4A54 0x021C4A54 thumb ov127
 *   func_021C4844 0x021C4844 thumb ov127
 */
#include "../../matched/include/Obj08124.h"
#include "../../matched/include/Obj04502.h"
#include "../../matched/include/Obj10474.h"
#include "../../matched/include/Obj10475.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { short x, y; } Pos;

extern int func_021C49A4(u8 *,unsigned int);
extern void func_021C5564(u8 *,void *,int,int,int);
extern int func_021C5550(void *, void *, int);
extern Pos func_021C4AC4(void *);
extern Pos func_021C4A54(Pos, int);
extern int func_021C4844(u8 *p, u16 x, u16 y);
int func_021C53C8(u8 *p,int a,int b,const u8 *desc,u8 *out);
int func_021C5404(void *p, void *q, void *r, const u8 *s, void *t);
void func_021C5478(int a, int b, int c, int d, int e);
int func_021C5488(u8 *p,int a,int b,const u8 *desc,u8 *out);
int func_021C54B0(void);
void func_021C54B4(int a, int b, int c, int d, int e);
int func_021C54C4(u8 *p,int a,int b,const u8 *desc,u8 *out);
int func_021C54EC(void *p, void *q, int n);

int func_021C53C8(u8 *p,int a,int b,const u8 *desc,u8 *out) { int v=func_021C49A4(p,5); int w=func_021C49A4(p,6); if(v==0 && w!=desc[2]) { func_021C5564(out,p,((struct Obj08124 *)desc)->f0,desc[3],desc[2]); return 1; } return 0; }

int func_021C5404(void *p, void *q, void *r, const u8 *s, void *t)
{
    int v = func_021C49A4(p, 5);
    if (v == 0 && func_021C54EC(p, q, s[2]) != 1 && func_021C5550(p, r, s[2]) != 1) {
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
