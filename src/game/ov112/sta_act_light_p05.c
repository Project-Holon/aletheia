/*
 * file:     sta_act_light_p05.c
 * unit:     yes
 * function: func_021F732C, func_021F75A0, func_021F75D8, func_021F75DC, func_021F760C, func_021F77A0
 * address:  0x021F732C
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F5450 0x021F5450 thumb ov112
 *   func_021F545C 0x021F545C thumb ov112
 *   func_021F4B30 0x021F4B30 thumb ov112
 *   func_021F4B24 0x021F4B24 thumb ov112
 *   func_021F4E8C 0x021F4E8C thumb ov112
 *   func_021F4ED4 0x021F4ED4 thumb ov112
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 *   func_021F4E6C 0x021F4E6C thumb ov112
 *   func_0207AF38 0x0207AF38 thumb
 *   func_0207B51C 0x0207B51C arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_0204F638 0x0204F638 arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   table 0x020A1B38 data a2
 *   func_021F8120 0x021F8120 thumb ov112
 *   func_021F5204 0x021F5204 thumb ov112
 *   func_0201ADE4 0x0201ADE4 thumb
 *   func_0201AE1C 0x0201AE1C thumb
 *   func_0201AE14 0x0201AE14 thumb
 *   func_021F77EC 0x021F77EC thumb ov112
 *   func_021F4B3C 0x021F4B3C thumb ov112
 *   func_021F4B88 0x021F4B88 thumb ov112
 *   func_0204F428 0x0204F428 arm
 *   func_0204F720 0x0204F720 arm
 *   func_020056EC 0x020056EC thumb
 *   func_0204F5A8 0x0204F5A8 arm
 *   func_021F4D40 0x021F4D40 thumb ov112
 *   func_021F4B4C 0x021F4B4C thumb ov112
 *   func_021F5330 0x021F5330 thumb ov112
 */
#include "../../matched/include/Obj00723.h"
#include "../../matched/include/Obj02824.h"
#include "../../matched/include/Obj03762.h"
#include "../../matched/include/Obj10319.h"
#include "../../matched/include/Obj10320.h"
#include "../../matched/include/Obj10321.h"

#define E (*(u8 **)(q + off + 0x84))
#define EA (*(u8 **)(q + off + 0xA8))
#define FXR(x) ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))
struct Trip;
struct Personal;
struct Board;
struct Vec3;
struct Tagged;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

typedef struct { int x, y, z; } Vec;

typedef struct { int m[9]; } Mtx;

typedef signed char s8;

typedef int s32_021F75D8;

typedef signed int     s32_021F760C;

typedef struct { int pad[24]; int value; int pad2[8]; int other; } Slot;

extern u8 *func_021F5450(u8 *, int);
extern u8 *func_021F545C(u8 *);
extern int func_021F4B30(u8 *);
extern int func_021F4B24(u8 *);
extern void func_021F4E8C(u32, u8 *, const Vec *);
extern void func_021F4ED4(u32 unused, u32 p, u16 v);
extern void func_021F4EB4(u32 unused, u32 p, s16 a, s16 b);
extern void func_021F4E6C(u8 *, u8 *, u32);
extern void func_0207AF38(Mtx *, int, int);
extern void func_0207B51C(const Vec *, const Mtx *, Vec *);
extern void func_0207CA00(const Vec *, const Vec *, Vec *);
extern void func_0204F638(u8 *a0, int i, struct Trip *src);
extern int func_021F8120(int a, u8 *p);
extern u8 *func_021F5204(void *,u8 *,u32);
extern void *func_0201ADE4(unsigned int species, int form, unsigned int heap);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *);
extern void func_021F77EC(u32,u8 *,u32);
extern void *func_021F4B3C(int type);
extern void *func_021F4B88(void *,int,u32,int *);
extern s32_021F760C func_0204F428(struct Board *b, u32 id, u16 v12, u16 v14, struct Vec3 *src, u8 k, u32 w, u32 mode);
extern void func_0204F720(void *,u32,u32 *);
extern u32 func_020056EC(u32);
extern void func_0204F5A8(void *p, u32 idx);
extern void func_021F4D40(u8 *p, u8 *e);
extern void func_021F4B4C(struct Tagged *a0);
extern void func_021F5330(int, int);
void func_021F732C(u8 *self, u8 *q);
void func_021F75A0(u8 *p);
void func_021F75D8(u8 *a0, u8 *a1);
void func_021F75DC(u8 *p, u16 v);
void func_021F760C(u8 *p,u8 *input);
void func_021F77A0(char *p, char *q);
extern s16 table[];


/*
 * note 2026-10-05 (wD7 lane15): closed. The else arm of func_021F4B24 writes the whole v3.z store in
 *   each arm of the k - 7 test (q+0x20 plus 0xA000 or 0x5000, minus EA[4] << 11). The zz local that
 *   merged at the join was what swapped off (r4) and t (r6); tail merging rebuilds the shared add.
 */
void func_021F732C(u8 *self, u8 *q)
{
    Vec v3;
    Mtx mtx;
    Vec v2;
    Vec v1;
    int i;
    int off;
    int k;
    int ang2;
    int z;
    int ang0;
    int neg;
    u8 *t;
    u16 h;

    for (i = 0; i < 9; i++) {
        k = i;
        if (*(int *)(q + 0x54) == 1) {
            if (i == 7) {
                k = 8;
            } else if (i == 8) {
                k = 7;
            } else if (i == 0) {
                k = 1;
            } else if (i == 1) {
                k = 0;
            }
        }
        off = i * 4;
        if (E != 0 && *(int *)(q + off + 0xCC) == 1) {
            if (*(int *)(q + 0xC) == 1 && *(int *)(q + 8) == 1) {
                t = func_021F5450(*(u8 **)(q + 0x58), k);
                if (*(int *)t == 1) {
                    neg = (*(int *)(t + 0x1C) < 0) ? 1 : 0;
                    ang0 = (u16)(0x10000 - *(u16 *)(t + 0x34));
                    ang2 = (u16)((0x10000 + *(u16 *)(t + 0x36) + *(s16 *)(EA + 2)) % 0x10000);
                    func_021F545C(*(u8 **)(q + 0x58));
                    z = *(int *)(t + 0x1C);
                    func_0207AF38(&mtx, -table[(ang0 >> 4) * 2], table[(ang0 >> 4) * 2 + 1]);
                    func_0207B51C((Vec *)(t + 0x10), &mtx, &v1);
                    if (neg == 1) {
                        ang2 = (u16)(0x10000 - ang2);
                    }
                    if (func_021F4B30(E) == 0 && neg == 1) {
                        z = -z;
                    }
                    func_0207B51C((Vec *)(t + 0x28), &mtx, &v2);
                    func_0207CA00((Vec *)(t + 0x28), &v2, &v2);
                    h = *(u16 *)(self + 0x434);
                    v3.x = *(int *)(t + 4) + v1.x + 0x80000 + FXR(h);
                    v3.y = *(int *)(t + 8) + v1.y + 0x60000;
                    if (func_021F4B24(E) == 1) {
                        v3.z = *(int *)(q + 0x20) - 0x14000;
                    } else {
                        if (k - 7 <= 1u) {
                            v3.z = *(int *)(q + 0x20) + 0xA000 - (*(u8 *)(EA + 4) << 11);
                        } else {
                            v3.z = *(int *)(q + 0x20) + 0x5000 - (*(u8 *)(EA + 4) << 11);
                        }
                    }
                    func_021F4E8C(*(u32 *)(self + 0x10), E, &v3);
                    func_021F4ED4(*(u32 *)(self + 0x10), (u32)E, (u16)(ang2 - ang0));
                    func_021F4EB4(*(u32 *)(self + 0x10), (u32)E, (s16)(z / 16 / 4), (s16)(*(int *)(t + 0x20) / 16 / 4));
                    func_021F4E6C(*(u8 **)(self + 0x10), E, 1);
                }
            } else {
                func_021F4E6C(*(u8 **)(self + 0x10), E, 0);
            }
        }
    }
    func_021F545C(*(u8 **)(q + 0x58));
    v3.x = *(int *)(q + 0x18) / 16;
    v3.y = (0xC0000 - *(int *)(q + 0x1C)) / 16;
    v3.z = 0x32;
    func_0204F638(*(void **)(self + 8), *(u32 *)(q + 0x5C), (struct Trip *)(&v3));
}

/*
 * extent: two zero alignment bytes follow code.
 */
void func_021F75A0(u8 *p) { int i; for(i=0;i<4;i++) if(*(int *)(p+i*264+20)==1) { if(func_021F8120((int)p,p+20+i*264)==1) func_021F75D8(p,p+20+i*264); } }


void func_021F75D8(u8 *a0, u8 *a1) { }

void func_021F75DC(u8 *p, u16 v)
{
    u8 i;
    *(u16 *)(p + 0x434) = v;
    for (i = 0; i < 9; i++) {
        u8 *e = p + i * 0x108;
        if (*(u32 *)(e + 0x14) == 1) *(u32 *)(e + 0x18) = 1;
    }
}

/*
 * ABI: 4B3C forwards full r0 to4AA8(int); its extern remains int despite superseded i5 narrow score.
 * lever: split records/record pointer steps, expand immutable position at4B88, record/id declaration swap (permuter183).
 */
void func_021F760C(u8 *p,u8 *input)
{
    u8 i;
    void *personal;
    int *position;
    u8 *records;
    u8 *q;
    u8 *row;
    u32 id;
    int scale;
    u8 *record;
    u32 flag;
    for(i=0;i<9;i++) {
        if(*(int *)(p+20+264*i)==0) break;
    }
    q=p+20+264*i;
    ((struct Obj00723 *)q)->f0=1;
    ((struct Obj00723 *)q)->f4=1;
    ((struct Obj00723 *)q)->f8=1;
    ((struct Obj00723 *)q)->fC=0;
    ((struct Obj00723 *)q)->f10=0;
    ((struct Obj00723 *)q)->f14=0;
    ((struct Obj00723 *)q)->f104=0;
    *(u8 * *)&((struct Obj00723 *)q)->f58=func_021F5204(((struct Obj03762 *)p)->fC,input,1);
    personal=func_0201ADE4((u32)((struct Obj10319 *)input)->f8,(u32)input[11],(u32)((struct Obj03762 *)p)->f0);
    if(func_0201AE1C(personal,16)==1) ((struct Obj00723 *)q)->f10=1;
    if(func_0201AE1C(personal,34)==1) ((struct Obj00723 *)q)->f14=1;
    func_0201AE14(personal);
    ((struct Obj00723 *)q)->f18=0;
    ((struct Obj00723 *)q)->f1C=0;
    ((struct Obj00723 *)q)->f20=0;
    ((struct Obj00723 *)q)->f30=0;
    ((struct Obj00723 *)q)->f34=0;
    ((struct Obj00723 *)q)->f38=0;
    ((struct Obj00723 *)q)->f24=4096;
    ((struct Obj00723 *)q)->f28=4096;
    ((struct Obj00723 *)q)->f2C=4096;
    func_021F77EC((u32)p,q,((struct Obj10319 *)input)->f8);
    ((struct Obj00723 *)q)->f48=0;
    position=(int *)(q+24);
    scale=1024;
    records=input;
    records=records+20;
    for(i=0;i<9;i++) {
        id=*(u16 *)(input+20+6*i);
        record=records;
        record=record+6*i;
        row=q+4*i;
        *(u8 * *)&((struct Obj02824 *)row)->fA8=record;
        if(id!=255) {
            ((struct Obj02824 *)row)->fCC=1;
            ((struct Obj02824 *)row)->f60=(int)func_021F4B3C(id);
            ((struct Obj02824 *)row)->f84=func_021F4B88(((struct Obj03762 *)p)->f10,id,*(u32 *)&((struct Obj02824 *)row)->f60,(int *)(q+24));
            func_021F4EB4(*(int *)&((struct Obj03762 *)p)->f10,*(int *)&((struct Obj02824 *)row)->f84,scale,scale);
            func_021F4E6C((u8 *)(*(int *)&((struct Obj03762 *)p)->f10),(u8 *)(*(int *)&((struct Obj02824 *)row)->f84),0);
        } else {
            ((struct Obj02824 *)row)->fCC=0;
            ((struct Obj02824 *)row)->f60=0;
            *(int *)&((struct Obj02824 *)row)->f84=0;
        }
    }
    *(int *)&((struct Obj00723 *)q)->f5C=func_0204F428(((struct Obj03762 *)p)->f8,((struct Obj03762 *)p)->f438,1024,768,(struct Vec3 *)(q+24),30,0,0);
    flag=1;
    func_0204F720(((struct Obj03762 *)p)->f8,((struct Obj00723 *)q)->f5C,&flag);
    ((struct Obj00723 *)q)->f50=func_020056EC(150)>>1;
    ((struct Obj00723 *)q)->f4C=1;
}

/*
 * extent: trailing two-byte zero padding before 021F77EC.
 */
void func_021F77A0(char *p, char *q) {
    u8 i;
    func_0204F5A8((void *)(((struct Obj10320 *)p)->f8), ((struct Obj10321 *)q)->f5C);
    for (i = 0; i < 9; i++) {
        if (((Slot *)(q + i * 4))->other != 0) {
            func_021F4D40((u8 *)(((struct Obj10320 *)p)->f10), (u8 *)(((Slot *)(q + i * 4))->other));
            func_021F4B4C((struct Tagged *)(((Slot *)(q + i * 4))->value));
            ((Slot *)(q + i * 4))->value = 0;
            ((Slot *)(q + i * 4))->other = 0;
        }
    }
    func_021F5330(((struct Obj10320 *)p)->fC, ((struct Obj10321 *)q)->f58);
    ((struct Obj10321 *)q)->f0 = 0;
}
