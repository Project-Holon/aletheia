/*
 * file:     script_command_p02.c
 * unit:     yes
 * function: func_021FA0D4, func_021FA0D8, func_021FA278, func_021FA27C, func_021FA2A0, func_021FA3A8, func_021FA4AC, func_021FA528
 * address:  0x021FA0D4
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215725C 0x0215725C thumb ov010
 *   func_02005728 0x02005728 thumb
 *   func_021F9E04 0x021F9E04 thumb ov132
 *   func_021F9DA0 0x021F9DA0 thumb ov132
 *   func_021F9DA4 0x021F9DA4 thumb ov132
 *   func_021F9DD4 0x021F9DD4 thumb ov132
 *   func_021F9DDC 0x021F9DDC thumb ov132
 *   func_021F8044 0x021F8044 thumb ov112
 *   func_021F6F04 0x021F6F04 thumb ov112
 *   _fflt 0x0209BDBC arm
 *   _ffltu 0x0209BE04 arm
 *   _fdiv 0x0209CE10 arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   table 0x021FDC16 data a2
 */
#include "../../matched/include/Obj00995.h"
#include "../../matched/include/Obj04514.h"
#include "../../matched/include/Obj14091.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef struct {int x,y,z;} Vec;

extern u8 func_0215725C(u8 *, int);
extern u32 func_02005728(u32 range);
extern u16 func_021F9E04(u8 *p);
extern void *func_021F9DA0(char *p);
extern void *func_021F9DA4(char *p, u32 i);
extern void *func_021F9DD4(void *);
extern void *func_021F9DDC(void *,u8);
extern void func_021F8044(void *unused, u32 *p, u32 *q);
extern void func_021F6F04(void *,void *,Vec *);
extern void func_02041300(u32,u16,u8,u8,u8,u8,u8);
extern void func_02041B6C(u32);
void func_021FA0D4(void *p);
void func_021FA0D8(char *p, char *q);
void func_021FA278(void *a0);
void func_021FA27C(char *p);
void func_021FA2A0(char *p,u8 *rec);
void func_021FA3A8(char *p,u8 *rec,unsigned type);
void func_021FA4AC(char *p);
void func_021FA528(char *p);
extern u16 table[];

void func_021FA0D4(void *p) { }

#pragma opt_common_subs off

/*
 * note 2026-10-05: needs per-function opt_common_subs off (the original does not share
 * idx*8 between the record stores and the call argument; without the pragma only
 * the rec/off register pair is swapped). Callee func_021FA3A8 takes (p, rec, type).
 * Caller passes q as a pointer: field 0x14 is a byte table read by func_0215725C.
 */
void func_021FA0D8(char *p, char *q)
{
    u16 sum = 0;
    u8 b[4];
    u8 a[4] = {0, 0, 0, 0};
    u8 c[60];
    u8 n = 0;
    u8 i, j, k, g, x, idx;
    int base;
    u8 r;
    int off;
    u8 *rec;
    for (i = 0; i < 4; i++) {
        b[i] = func_0215725C(*(u8 **)(q + 0x14), i);
        sum = sum + b[i];
    }
    for (i = 0; i < 4; i++) {
        a[i] = (b[i] * 60) / sum;
        n = n + a[i];
    }
    for (; n < 60; n++)
        a[func_02005728(4)]++;
    k = 0;
    for (i = 0; i < 4; i++)
        for (j = 0; j < a[i]; j++) {
            c[k] = i;
            k++;
        }
    for (r = 0; r < 3; r++) {
        for (i = 0; i < 60; i++) {
            u8 t;
            x = func_02005728(60);
            t = c[i];
            c[i] = c[x];
            c[x] = t;
        }
    }
    for (g = 0; g < 5; g++) {
        i = 0;
        base = g * 12;
        for (; i < 12; i++) {
            idx = i + base;
            off = idx * 8;
            rec = (u8 *)(p + off);
            rec[0x20A] = i + 2;
            rec[0x20B] = g;
            rec[0x206] = c[idx];
            rec[0x205] = func_02005728(60) + 1;
            rec[0x204] = 0xff;
            if (i < 2)
                func_021FA3A8(p, (u8 *)(p + 0x204 + off), 3);
            else if (i < 4)
                func_021FA3A8(p, (u8 *)(p + 0x204 + off), 2);
            else if (i < 6)
                func_021FA3A8(p, (u8 *)(p + 0x204 + off), 1);
            else
                func_021FA3A8(p, (u8 *)(p + 0x204 + off), 0);
        }
    }
}


#pragma opt_common_subs reset

void func_021FA278(void *a0)
{
}

/*
 * Lever: keep the declared base but expand p+0x204 at the call; named base left a four-byte r5/r6 swap.
 * trailing: Two zero alignment bytes.
 */
void func_021FA27C(char *p)
{
  u8 i = 0;
  u8 *base = (u8 *) (p + 0x204);
  for (; i < 60; i++)
    func_021FA2A0(p, ((u8 *) (p + 0x204)) + (i * 8));

}

void func_021FA2A0(char *p,u8 *rec)
{
    Vec v;
    void *a,*b;
    u16 x;
    s16 delta;
    if(rec[1]!=0) rec[1]--;
    if(rec[1]==0) {
        if(rec[0]==255 && ((struct Obj04514 *)p)->f1FC==255) {
            ((struct Obj00995 *)rec)->f4=65535;
            if(rec[6]<2) func_021FA3A8(p,rec,3);
            else if(rec[6]<4) func_021FA3A8(p,rec,2);
            else if(rec[6]<6) func_021FA3A8(p,rec,1);
            else func_021FA3A8(p,rec,0);
        } else {
            func_021F9E04(((struct Obj04514 *)p)->f1E8);
            x=((rec[6]*32-64)*4)/3;
            if(rec[0]!=255) {
                a=func_021F9DA0(((struct Obj04514 *)p)->f1E8);
                func_021F8044(a,func_021F9DA4(((struct Obj04514 *)p)->f1E8,rec[0]),(u32 *)(&v));
            } else {
                b=func_021F9DD4(((struct Obj04514 *)p)->f1E8);
                func_021F6F04(b,func_021F9DDC(((struct Obj04514 *)p)->f1E8,((struct Obj04514 *)p)->f1FC),&v);
            }
            delta=(float)v.x/4096.f-(float)(u32)x;
            if(delta < -64) func_021FA3A8(p,rec,0);
            else if(delta >64) func_021FA3A8(p,rec,3);
            else if(delta<0) func_021FA3A8(p,rec,1);
            else func_021FA3A8(p,rec,2);
        }
        rec[1]=func_02005728(60)+1;
    }
}

/*
 * ABI: 41300 caller truncates tile to u16 and coordinates to u8 before each call.
 */
void func_021FA3A8(char *p,u8 *rec,unsigned type)
{
    u16 tile;
    int reverse=0;
    u8 row,col,x;
    u32 t;
    switch(type) {
    case 3: reverse=1; tile=*(u16 *)((u32)table+rec[2]*2)+0x400; break;
    case 2: reverse=1; tile=*(u16 *)((u32)table+rec[2]*2)+0x404; break;
    case 1: tile=*(u16 *)((u32)table+rec[2]*2)+4; break;
    case 0: tile=*(u16 *)((u32)table+rec[2]*2); break;
    }
    for(row=0;row<4;row++) {
        for(col=0;col<4;col++) {
            if(reverse==1) x=3-col+rec[6]*4;
            else x=col+rec[6]*4;
            t=tile+col+row*32;
            func_02041300(4,tile+col+row*32,x,row+rec[7]*4+2,1,1,0);
            func_02041300(6,t,x,row+rec[7]*4+5,1,1,0);
        }
    }
    func_02041B6C(4);
    func_02041B6C(6);
}

void func_021FA4AC(char *p)
{
    u8 i;
    u8 n = 0;
    u8 choices[4] = {0, 0, 0, 0};
    for (i = 0; i < 4; i++) {
        if (*(int *)(p + i * 4 + 0x1ec) == 1) { choices[n] = i; n++; }
    }
    if (n == 0) func_021FA528(p);
    else {
        for (i = 0; i < 60; i++) {
            *(u8 *)(p + i * 8 + 0x205) = func_02005728(60) + 1;
            *(u8 *)(p + i * 8 + 0x204) = choices[func_02005728(n)];
        }
    }
}

void func_021FA528(char *p)
{
    u8 i;
    for (i = 0; i < 60; i++) {
        char *q = p + i * 8;
        ((struct Obj14091 *)q)->f205 = func_02005728(60) + 1;
        ((struct Obj14091 *)q)->f204 = 255;
    }
}
