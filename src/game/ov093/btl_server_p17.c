/*
 * file:     btl_server_p17.c
 * unit:     yes
 * function: func_021C9178, func_021C9250, func_021C9394, func_021C9448, func_021C947C, func_021C94C8
 * address:  0x021C9178
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021C8828 0x021C8828 thumb ov093
 *   func_021C9240 0x021C9240 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021C27A0 0x021C27A0 thumb ov093
 *   func_021C2910 0x021C2910 thumb ov093
 *   func_021C5A1C 0x021C5A1C thumb ov093
 *   func_021C5A34 0x021C5A34 thumb ov093
 *   func_021C9374 0x021C9374 thumb ov093
 *   func_021C9384 0x021C9384 thumb ov093
 *   func_021D5D14 0x021D5D14 thumb ov093
 *   func_021C3008 0x021C3008 thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 *   func_021C9438  0x021C9438  thumb  ov093
 *   func_021D5EA8  0x021D5EA8  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021D5EFC 0x021D5EFC thumb ov093
 *   func_021D5F08  0x021D5F08  thumb  ov093
 *   func_021C95C0 0x021C95C0 thumb ov093
 *   func_021D5970 0x021D5970 thumb ov093
 */
#include "../../matched/include/Obj00003.h"

struct Msg;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { u32 value; } S;

typedef struct { u32 low:8, index:5, pad:10, flag:1, high:8; u32 kind; S value; u8 a,b,c,id,d; u8 pad11[3]; u8 msg[36]; } Ent_021C9178;

typedef signed char s8;

typedef unsigned short u16;

enum Kind { K0, K1, K10=10 };

typedef struct { u32 low:8,index:5,pad:10,flag:1,high:8; enum Kind kind; u32 value; s8 a; u8 b,c,count; u8 ids[8]; u8 msg[36]; } Ent_021C9250;

typedef struct {
    u32 w; u8 b[8];
} Ent;

typedef struct { int pad0; int pad1; char *f8; void *fc; } P;

typedef struct { u32 w; u8 n; u8 ids[1]; } Ent_021C9448;

typedef struct { u32 w; u16 values[5]; u8 id; u8 f0:1,f1:1,f2:1,f3:1,f4:1,pad:3; u8 msg[36]; } Ent_021C94C8;

extern u8 *func_021B9934(char *p, int i);
extern u32 func_021C8828(u8 *p);
extern int func_021C9240(void *, u8);
extern int func_021D5B68(void *);
extern int func_021C27A0(u8 *, u8 *, u8 *, u32, S, u8, u32);
extern void func_021C2910(u8 *, u8 *, u8 *, int, S, int, int, const void *);
extern void func_021C5A1C(u8 *p, u8 *a);
extern void func_021C5A34(u8 *p, u8 *a);
extern int func_021C9374(void *, u8);
extern int func_021C9384(void *, u8);
extern int func_021D5D14(s8 *p, int i, int sign);
extern int func_021C3008(u8 *, u8, u8 *, enum Kind, int, u8, u16, u32, int, u32);
extern int func_021C99A0(void *w, const struct Msg *m);
extern int func_021C9438(int a, u8 b);
extern void func_021D5EA8(u8 *p, int i, u8 n);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021D5EFC(char *);
extern void func_021D5F08(char *p);
extern int func_021C95C0(void *, u8);
extern void func_021D5970(u8 *, int, u16);
int func_021C9178(u8 *p, const Ent_021C9178 *e);
int func_021C9250(u8 *p, const Ent_021C9250 *e, u16 arg);
int func_021C9394(int p, const Ent *e);
int func_021C9448(u8 *p, u8 *e);
int func_021C947C(P *p, const Ent_021C9448 *e);
int func_021C94C8(u8 *p, const Ent_021C94C8 *e);



int func_021C9178(u8 *p, const Ent_021C9178 *e)
{
    u8 *a;
    u8 f;
    u8 *b;
    if (e->index != 31) a = func_021B9934(((struct Obj00003 *)p)->f8, (u8)e->index);
    else a = 0;
    f = (int)func_021C8828((u8 *)e->msg) == 0 && e->b == 0;
    if (func_021C9240(p + 0x1ab8, e->id)) {
        b = func_021B9934(((struct Obj00003 *)p)->f8, (u8)e->id);
        if (!func_021D5B68(b)) {
            if (!func_021C27A0(p, b, a, e->kind, e->value, e->d, e->a)) {
                if (e->flag) func_021C5A1C(p, a);
                func_021C2910(p, b, a, e->kind, e->value, f, e->c, e->msg);
                if (e->flag) func_021C5A34(p, a);
                return 1;
            }
        }
    }
    return 0;
}



int func_021C9250(u8 *p, const Ent_021C9250 *e, u16 arg)
{
    u8 *a;
    int f;
    int result;
    u32 i;
    u8 *b;
    const u8 *m;
    a = func_021B9934(((struct Obj00003 *)p)->f8, (u8)e->index);
    f = 0;
    result = 0;
    for (i = 0; i < e->count; i++) {
        if (func_021C9374(p + 0x1ab8, e->ids[i])) {
            b = func_021B9934(((struct Obj00003 *)p)->f8, (u8)e->ids[i]);
            if (!func_021D5B68(b)) {
                if (func_021D5D14((s8 *)b, (u32)e->kind, e->a)) {
                    f = 1;
                    break;
                }
            }
        }
    }
    if (f && e->flag) func_021C5A1C(p, a);
    m = (const u8 *)e;
    m += 24;
    for (i = 0; i < e->count; i++) {
        if (func_021C9384(p + 0x1ab8, e->ids[i])) {
            b = func_021B9934(((struct Obj00003 *)p)->f8, (u8)e->ids[i]);
            if (!func_021D5B68(b)) {
                if (func_021C3008(p, e->index, b, e->kind, e->a, 31, arg, e->value, e->c, e->b == 0)) {
                    func_021C99A0(p, (const struct Msg *)m);
                    result = 1;
                }
            }
        }
    }
    if (f && e->flag) func_021C5A34(p, a);
    return result;
}



int func_021C9394(int p, const Ent *e)
{
    u8 *a;

    if (func_021C9438(p + 0x1ab8, e->b[0])) {
        a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, e->b[0]);
        if (func_021D5B68(a) == 0) {
            func_021D5EA8(a, 1, e->b[1]);
            func_021D5EA8(a, 2, e->b[2]);
            func_021D5EA8(a, 3, e->b[3]);
            func_021D5EA8(a, 4, e->b[4]);
            func_021D5EA8(a, 5, e->b[5]);
            func_021D5EA8(a, 6, e->b[6]);
            func_021D5EA8(a, 7, e->b[7]);
            func_021CD4B0(((struct Obj00003 *)p)->fC, 0xb, e->b[0], e->b[1], e->b[2], e->b[3], e->b[4], e->b[5], e->b[6], e->b[7]);
            return 1;
        }
    }
    return 0;
}



/*
 * extent: compiled 50 bytes; 021C947A..021C947C is alignment padding.
 * note: caller consumes live r0 after void-declared func_021D5EFC;
 *       return interface follows its explicit u8 truncation at 021C9470.
 */
int func_021C9448(u8 *p, u8 *e)
{
    char *a;
    a = (char *)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, e[4]);
    if (func_021D5B68(a) == 0) {
        func_021CD4B0(((struct Obj00003 *)p)->fC, 12, e[4]);
        return (u8)func_021D5EFC(a);
    }
    return 0;
}




int func_021C947C(P *p, const Ent_021C9448 *e)
{
    int r = 0;
    u32 i;
    u8 *a;

    for (i = 0; i < e->n; i++) {
        a = func_021B9934(p->f8, e->ids[i]);
        if (func_021D5B68(a) == 0) {
            func_021CD4B0(p->fc, 0xd, e->ids[i]);
            func_021D5F08((char *)a);
            r = 1;
        }
    }
    return r;
}


int func_021C94C8(u8 *p, const Ent_021C94C8 *e)
{
    u8 *a;
    if (func_021C95C0(p + 0x1ab8, e->id)) {
        a = func_021B9934(((struct Obj00003 *)p)->f8, e->id);
        if (e->f0) { func_021D5970(a, 8, e->values[0]); func_021CD4B0(((struct Obj00003 *)p)->fC, 19, e->id, 8, (u8)e->values[0]); }
        if (e->f1) { func_021D5970(a, 9, e->values[1]); func_021CD4B0(((struct Obj00003 *)p)->fC, 19, e->id, 9, (u8)e->values[1]); }
        if (e->f2) { func_021D5970(a, 10, e->values[2]); func_021CD4B0(((struct Obj00003 *)p)->fC, 19, e->id, 10, (u8)e->values[2]); }
        if (e->f3) { func_021D5970(a, 11, e->values[3]); func_021CD4B0(((struct Obj00003 *)p)->fC, 19, e->id, 11, (u8)e->values[3]); }
        if (e->f4) { func_021D5970(a, 12, e->values[4]); func_021CD4B0(((struct Obj00003 *)p)->fC, 19, e->id, 12, (u8)e->values[4]); }
        func_021C99A0(p, (const struct Msg *)e->msg);
        return 1;
    }
    return 0;
}
