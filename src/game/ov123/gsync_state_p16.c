/*
 * file:     gsync_state_p16.c
 * unit:     yes
 * function: func_021D7BDC, func_021D7C54, func_021D7CB4, func_021D7CEC, func_021D7D18, func_021D7DE8, func_021D7E20, func_021D7E58
 * address:  0x021D7BDC
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D7B68 0x021D7B68 thumb ov123
 *   func_021D746C 0x021D746C thumb ov123
 *   func_02009390 0x02009390 thumb
 *   func_020093A8 0x020093A8 thumb
 *   func_020093F0 0x020093F0 thumb
 *   func_0203EFC8 0x0203EFC8 arm
 *   func_02009348 0x02009348 thumb
 *   func_0202A128 0x0202A128 thumb
 *   func_02019D30 0x02019D30 thumb
 *   func_02019C90 0x02019C90 thumb
 *   func_02019D58 0x02019D58 thumb
 *   func_020056EC 0x020056EC thumb
 *   func_0202A19C 0x0202A19C thumb
 *   func_0200E0B0 0x0200E0B0 thumb
 *   func_0200E1A8 0x0200E1A8 thumb
 *   func_0202A170 0x0202A170 thumb
 *   func_021D6AA8 0x021D6AA8 thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   func_020093D0 0x020093D0 thumb
 *   func_021D6A70 0x021D6A70 thumb ov123
 *   func_021D6AB8 0x021D6AB8 thumb ov123
 */
#include "../../matched/include/Obj05366.h"
#include "../../matched/include/Obj10446.h"
#include "../../matched/include/Obj05367.h"
#include "../../matched/include/Obj22962.h"
#include "../../matched/include/Obj00063.h"
#include "../../matched/include/Obj03794.h"

struct Sub02009210Ent;
struct Sub02009210Obj;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef signed int     s32;

typedef unsigned short u16;

extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D7B68(char *p);
extern void func_021D746C(int a);
extern struct Sub02009210Ent *func_02009390(struct Sub02009210Obj *obj, int i);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void func_020093A8(struct Sub02009210Obj *obj, int i, const void *src);
extern void func_020093F0(struct Sub02009210Obj *obj, int value);
extern void func_02009348(struct Sub02009210Obj *obj, int i, u16 a, u8 b);
extern void *func_0202A128(int);
extern u32 func_02019D30(u32 a, u32 n);
extern int func_02019C90(u16, int, int);
extern int func_02019D58(u16, int);
extern u32 func_020056EC(u32 range);
extern int func_0202A19C(u32, void *, u16, u16, int);
extern void *func_0200E0B0(void *);
extern void func_0200E1A8(void *, u16, u16, u8, int, u8, u32);
extern void func_0202A170(void *);
extern void func_021D6AA8(char *,int,u16);
extern void func_021D6FF0(char *p);
extern s32 func_020093D0(const struct Sub02009210Obj *obj);
extern void func_021D6A70(u8 *p, int i, int a, int b, int c);
extern void func_021D6AB8(u8 *p);
void func_021D7BDC(char *p);
void func_021D7C54(void *p, char *q);
int func_021D7CB4(int a,u8 *p);
int func_021D7CEC(int a,u8 *p);
void func_021D7D18(u8 *p, int unused, int species, int gender, int form, int n, int value);
void func_021D7DE8(u8 *p,int a,u8 *records);
void func_021D7E20(u8 *p,u8 *list);
void func_021D7E58(u8 *p, void *h, u8 *q, int *r);

void func_021D7BDC(char *p)
{
    if (((struct Obj05366 *)p)->fA5) {
        p[0xa7] = 0;
        func_021D6EE0((u8 *)p, (int)func_021D7B68, 0x465);
        return;
    }
    if (((struct Obj05366 *)p)->fA4) {
        p[0xa7] = 1;
        func_021D6EE0((u8 *)p, (int)func_021D7B68, 0x46a);
        return;
    }
    if (((struct Obj05366 *)p)->fA6) {
        p[0xa7] = 2;
        func_021D6EE0((u8 *)p, (int)func_021D7B68, 0x46f);
        return;
    }
    func_021D6EE0((u8 *)p, (int)func_021D746C, 0x472);
}

/*
 * extent: two zero alignment bytes at 021D7CB2 follow the return.
 */
void func_021D7C54(void *p, char *q)
{
    int changed = 0;
    int i;
    for (i = 0; i < 5; i++) {
        if (func_0203EFC8((const u8 *)func_02009390(p, i), (const u8 *)(q + 0x98 + i * 26), 26)) {
            changed = 1;
            break;
        }
    }
    if (changed) {
        for (i = 0; i < 5; i++) func_020093A8(p, i, q + 0x98 + i * 26);
        func_020093F0(p, 127);
    }
}

int func_021D7CB4(int a,u8 *p) { int i,result; u16 n; result=0; for(i=0;i<20;i++) { n=*(u16 *)(p+92+i*2); if(n!=0 && n<=626) { func_02009348((struct Sub02009210Obj *)a,i,n,p[132+i]); result=1; } } return result; }

int func_021D7CEC(int a,u8 *p) { int i,result; u16 n; result=0; for(i=0;i<20;i++) { n=*(u16 *)(p+92+i*2); if(n!=0 && n<=626) result=1; } return result; }

void func_021D7D18(u8 *p, int unused, int species, int gender, int form, int n, int value)
{
    int f;
    u8 v = value;
    void *h;
    int kind;
    int mapped;
    int g;
    if (species == 0 || species > 493) return;
    h = func_0202A128(((struct Obj10446 *)p)->f0);
    kind = 3;
    f = (int)func_02019D30((u16)species, (u8)form);
    g = func_02019C90(species, f, 20);
    mapped = func_02019D58(species, f);
    switch (g) {
    case 0: gender = 0; break;
    case 254: gender = 1; break;
    case 255: gender = 2; break;
    default: if (gender > 1) gender = func_020056EC(2); break;
    }
    if (func_0202A19C(((struct Obj10446 *)p)->f2C, h, species, gender, mapped)) kind = 2;
    if (v > 8) v = 0;
    func_0200E1A8(func_0200E0B0(((struct Obj10446 *)p)->f28), species, n, gender, mapped, v, kind);
    func_0202A170(h);
}

void func_021D7DE8(u8 *p,int a,u8 *records) { int i; u8 *r; for(i=0;i<10;i++) { r=records+i*8; if(((struct Obj05367 *)r)->f4==0) break; func_021D7D18(p,a,((struct Obj05367 *)r)->f4,r[9],r[8],((struct Obj05367 *)r)->f6,r[10]); } }

void func_021D7E20(u8 *p,u8 *list) { int i; u16 n; for(i=0;i<20;i++) { n=*(u16 *)(list+92+i*2); if(n!=0 && list[132+i]!=0 && n<=626) func_021D6AA8(*(char * *)&((struct Obj22962 *)p)->f14,i,n); } }

/*
 * lever: bind the record word before the call and use shared goto guards.
 */
void func_021D7E58(u8 *p, void *h, u8 *q, int *r)
{
    int i;
    int v;
    if (*r != 0) {
        ((struct Obj00063 *)p)->f80 = *r;
        func_021D6EE0(p, (int)func_021D6FF0, 0x500);
        return;
    }
    if (q[0x5b] != 0) goto unchanged;
    v = *(int *)q;
    if (v == func_020093D0(h)) goto unchanged;
    {
        ((struct Obj00063 *)p)->f7C = v;
        p[0xa4] = q[0x57];
        p[0xa5] = q[0x58];
        p[0xa6] = q[0x59];
        ((struct Obj00063 *)p)->f6C = ((struct Obj03794 *)q)->f54;
        if (p[0xa5]) p[0xa8] |= 1;
        if (p[0xa4]) p[0xa8] |= 2;
        if (p[0xa6]) p[0xa8] |= 4;
        for (i = 0; i < 10; i++) {
            if (*(u16 *)(q+i*8+4) == 0) break;
            func_021D6A70(((struct Obj00063 *)p)->f14, i+20, *(u16 *)(q+i*8+4), q[i*8+8], q[i*8+9]);
        }
        p[0xa9] = func_021D7CEC((int)h,q);
        func_021D7E20(p,q);
        func_021D6AB8(((struct Obj00063 *)p)->f14);
    }
    goto done;
unchanged:
    p[0xa9] = 0;
done:
    func_021D7BDC((char *)p);
}
