/*
 * file:     pokemontrade_proc_p12.c
 * unit:     yes
 * function: func_021DB4B4, func_021DB4EC, func_021DB52C, func_021DB7AC, func_021DB89C, func_021DB998, func_021DB9B4
 * address:  0x021DB4B4
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _s32_div_f 0x0209C0A4 arm
 *   func_0203633C 0x0203633C arm
 *   func_020355D8 0x020355D8 arm
 *   func_021DD018 0x021DD018 thumb ov119
 *   func_021E4E0C 0x021E4E0C thumb ov119
 *   func_020061E4 0x020061E4 thumb
 *   d_021E7FE0 0x021E7FE0 data a4
 *   func_021E4E64 0x021E4E64 thumb ov119
 *   func_021E42B4 0x021E42B4 thumb ov119
 *   func_021E4598 0x021E4598 thumb ov119
 *   func_02006238 0x02006238 thumb
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_0203D29C 0x0203D29C arm
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_02035CB8 0x02035CB8 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_02035C38 0x02035C38 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DBE70 0x021DBE70 thumb ov119
 *   func_021DD34C 0x021DD34C thumb ov119
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021D94A0 0x021D94A0 thumb ov119
 *   func_021D8B38 0x021D8B38 thumb ov119
 */
#include "../../matched/include/Obj13893.h"
#include "../../matched/include/Obj00130.h"
#include "../../matched/include/Obj00001.h"

#define H(o) (*(s16 *)(p+(o)))
#define I(o) (*(int *)(p+(o)))
struct Entry;
struct Obj;
typedef unsigned int   u32_021DB52C;

typedef unsigned char  u8;

typedef short s16;

typedef unsigned u32_021DB7AC;

typedef unsigned int   u32_021DB89C;

typedef unsigned short u16;

typedef unsigned int   u32_021DB9B4;

extern unsigned int func_0203633C(void);
extern void func_020355D8(u8 v);
extern void func_021DD018(char *, int);
extern int func_021E4E0C(char *, int *);
extern void func_020061E4(u32_021DB52C a);
extern void func_021E4E64(int,char *,int);
extern void func_021E42B4(char *);
extern void func_021E4598(char *);
extern int func_02006238(void);
extern int func_021D8A24(void *);
extern u32_021DB7AC func_0203D29C(void);
extern struct Entry *func_020399A8(void);
extern u32_021DB7AC func_0203D3F8(u32_021DB7AC,u32_021DB7AC,u32_021DB7AC,u32_021DB7AC,u32_021DB7AC,u32_021DB7AC,u32_021DB7AC,u32_021DB7AC);
extern u32_021DB89C func_02035CB8(u32_021DB89C *outA, u32_021DB89C *outB);
extern int func_02035C38(void);
extern void func_021D8E84(void *, int);
extern void func_021DBE70(char *p);
extern int func_021DD34C(char *,int,int);
extern int func_0203D3A8(struct Entry *a, u32_021DB9B4 b, u32_021DB9B4 c, u32_021DB9B4 d);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern void func_021D94A0(void *,int);
extern void func_021D8B38(char *p);
int func_021DB4B4(int a);
int func_021DB4EC(char *p, int index);
void func_021DB52C(char *p);
void func_021DB7AC(char *p,int a,int b);
void func_021DB89C(char *p);
void func_021DB998(char *p);
void func_021DB9B4(char *p);
extern const int d_021E7FE0[];

/*
 * Position of a slot: 0 and 1 are special, the rest on a 6-column grid.
 * Lever: the remainder is stored back into the same local as the dividend
 * (b = b % 6); a separate remainder local stays in r1 and changes colours.
 */
int func_021DB4B4(int a)
{
    int b, q;

    if (a == 0)
        return 0;
    if (a == 1)
        return 0x30;
    b = a - 2;
    q = b / 6;
    b = b % 6;
    return q * 0xa0 + 0x60 + b * 0x1a;
}

int func_021DB4EC(char *p, int index)
{
    int position = func_021DB4B4(index);
    int start = ((struct Obj13893 *)p)->f107C;
    if (start < position && start + 0xe0 > position)
        return 1;
    position += ((struct Obj13893 *)p)->f63C;
    if (start < position && start + 0xe0 > position)
        return 1;
    return 0;
}

void func_021DB52C(char *p)
{
    int changed = 0;
    int i, v;
    unsigned int k = func_0203633C();
    if (((struct Obj00130 *)p)->fF60 != 0)
        return;
    if (k & 0x100) {
        func_020355D8(0);
        for (i = 0; i < ((struct Obj00130 *)p)->f630 + 1; i++) {
            if (d_021E7FE0[i] > ((struct Obj00130 *)p)->f107C) {
                ((struct Obj00130 *)p)->f107C = d_021E7FE0[i];
                changed = 1;
                break;
            }
        }
        if (!changed) {
            changed = 1;
            ((struct Obj00130 *)p)->f107C = d_021E7FE0[0];
        }
        func_021DD018(p, changed);
    } else if (k & 0x200) {
        func_020355D8(0);
        for (i = ((struct Obj00130 *)p)->f630; i >= 0; i--) {
            if (d_021E7FE0[i] < ((struct Obj00130 *)p)->f107C) {
                ((struct Obj00130 *)p)->f107C = d_021E7FE0[i];
                changed = 1;
                break;
            }
        }
        if (!changed) {
            changed = 1;
            ((struct Obj00130 *)p)->f107C = d_021E7FE0[((struct Obj00130 *)p)->f630];
        }
        func_021DD018(p, changed);
    } else if (func_0203633C() == 0x40) {
        func_020355D8(0);
        if (func_021E4E0C(p, &v) == 0)
            ((struct Obj00130 *)p)->fF74 = v;
        if (--((struct Obj00130 *)p)->fF78 < 0) {
            if (((struct Obj00130 *)p)->fF74 < 2)
                ((struct Obj00130 *)p)->fF78 = 2;
            else
                ((struct Obj00130 *)p)->fF78 = 4;
        }
        ((struct Obj00130 *)p)->f1080 = ((struct Obj00130 *)p)->f1080 - 1;
        changed = 1;
    } else if (func_0203633C() == 0x80) {
        int x;
        func_020355D8(0);
        if (func_021E4E0C(p, &v) == 0)
            ((struct Obj00130 *)p)->fF74 = v;
        x = ++((struct Obj00130 *)p)->fF78;
        if (((struct Obj00130 *)p)->fF74 < 2) {
            if (x >= 3)
                ((struct Obj00130 *)p)->fF78 = 0;
        } else if (x >= 5)
            ((struct Obj00130 *)p)->fF78 = 0;
        ((struct Obj00130 *)p)->f1080 = ((struct Obj00130 *)p)->f1080 - 1;
        changed = 1;
    } else if (func_0203633C() == 0x10) {
        func_020355D8(0);
        ((struct Obj00130 *)p)->f1080 = ((struct Obj00130 *)p)->f1080 - 1;
        changed = 1;
        if (func_021E4E0C(p, &v) == 0) {
            ((struct Obj00130 *)p)->fF74 = v;
        } else {
            ((struct Obj00130 *)p)->fF74 = ((struct Obj00130 *)p)->fF74 + 1;
            if (func_021DB4EC(p, ((struct Obj00130 *)p)->fF74) == 0) {
                ((struct Obj00130 *)p)->f107C = func_021DB4B4(((struct Obj00130 *)p)->fF74 + 1) - 0x100;
                ((struct Obj00130 *)p)->f1080 = -1;
            }
        }
        if (((struct Obj00130 *)p)->fF74 >= ((struct Obj00130 *)p)->f634)
            ((struct Obj00130 *)p)->fF74 = 0;
        if (((struct Obj00130 *)p)->fF74 < 2 && ((struct Obj00130 *)p)->fF78 >= 3)
            ((struct Obj00130 *)p)->fF78 = 2;
    } else if (func_0203633C() == 0x20) {
        func_020355D8(0);
        ((struct Obj00130 *)p)->f1080 = ((struct Obj00130 *)p)->f1080 + 1;
        changed = 1;
        if (func_021E4E0C(p, &v) == 0) {
            ((struct Obj00130 *)p)->fF74 = v;
        } else {
            ((struct Obj00130 *)p)->fF74 = ((struct Obj00130 *)p)->fF74 - 1;
            if (((struct Obj00130 *)p)->fF74 < 0)
                ((struct Obj00130 *)p)->fF74 = ((struct Obj00130 *)p)->f634 - 1;
            if (func_021DB4EC(p, ((struct Obj00130 *)p)->fF74) == 0) {
                ((struct Obj00130 *)p)->f107C = func_021DB4B4(((struct Obj00130 *)p)->fF74);
                ((struct Obj00130 *)p)->f1080 = -1;
            }
        }
        if (((struct Obj00130 *)p)->fF74 < 0)
            ((struct Obj00130 *)p)->fF74 = ((struct Obj00130 *)p)->f634 - 1;
        if (((struct Obj00130 *)p)->fF74 < 2 && ((struct Obj00130 *)p)->fF78 >= 3)
            ((struct Obj00130 *)p)->fF78 = 2;
    }
    if (changed) {
        ((struct Obj00130 *)p)->f1084 = 1;
        func_020061E4(0x548);
        func_021DB7AC(p, 0, 1);
    }
}

void func_021DB7AC(char *p,int a,int b)
{
    if(H(0x107c)<0) H(0x107c)+=(s16)I(0x63c);
    if(I(0x63c)<=H(0x107c)) H(0x107c)-=(s16)I(0x63c);
    func_021E4E64(I(0x828),p,1);
    func_021E42B4(p);
    func_021E4598(p);
    if(func_02006238()==0 && a) func_020061E4(0x72b);
    if(func_021D8A24(p) && b) {
        if(func_0203D29C()) {
            if(H(0x107c)%16==0) {
                func_0203D3F8((u32_021DB7AC)func_020399A8(),255,0xc0c,2,(u32_021DB7AC)(p+0x107c),0,1,1);
                return;
            }
        } else {
            func_0203D3F8((u32_021DB7AC)func_020399A8(),255,0xc0c,2,(u32_021DB7AC)(p+0x107c),0,1,1);
            return;
        }
    } else {
        if(func_021D8A24(p)==0) H(0x107e)=H(0x107c);
    }
}

void func_021DB89C(char *p)
{
    int x,y,i;
    if(I(0xf60)) return;
    if(func_02035CB8((u32_021DB89C *)(&x),(u32_021DB89C *)(&y))) {
        if(I(0x1088)) {
            if((unsigned)x>=64 && (unsigned)x<192 && (unsigned)y>=168 && (unsigned)y<188) {
                int previous;
                func_0204B92C((struct Obj *)I(0xf04),1);
                previous=H(0x1078);
                H(0x107a)=(x-previous)*2;
                H(0x1078)=x;
                H(0x107c)-=H(0x107a);
                if(H(0x107a)>12) func_021DB7AC(p,1,1);
                else func_021DB7AC(p,0,1);
            } else H(0x107a)=0;
        }
        H(0x1078)=x;
    } else H(0x1078)=0;
    if(func_02035C38()==0 && H(0x107a)!=0) {
        for(i=2;i!=0 && H(0x107a)!=0;i--) {
            if(H(0x107a)<0) H(0x107a)++;
            if(H(0x107a)>0) H(0x107a)--;
        }
        H(0x107c)-=H(0x107a);
        func_021DB7AC(p,1,1);
    }
}

void func_021DB998(char *p)
{
    if (func_02035C38() == 0)
        func_021D8E84(p, (int)func_021DBE70);
}

void func_021DB9B4(char *p)
{
    func_021DD34C(p,((struct Obj00001 *)p)->fF98,((struct Obj00001 *)p)->fF94);
    if(func_021D8A24(p)) {
        if(!func_0203D3A8(func_020399A8(),0xc06,0,0)) return;
    }
    func_021B6558((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),8,0);
    ((struct Obj00001 *)p)->fF84=-1;
    ((struct Obj00001 *)p)->fF88=-1;
    ((struct Obj00001 *)p)->fF7C=-1;
    ((struct Obj00001 *)p)->fF80=-1;
    ((struct Obj00001 *)p)->fF94=-1;
    ((struct Obj00001 *)p)->fF98=-1;
    func_021D94A0(p,0);
    func_021D8B38(p);
    func_021D8E84(p,(int)func_021DB998);
}
