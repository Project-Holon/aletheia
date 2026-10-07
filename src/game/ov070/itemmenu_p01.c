/*
 * file:     itemmenu_p01.c
 * unit:     yes
 * function: func_021B7128, func_021B7250
 * address:  0x021B7128
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B61B8  0x021B61B8  thumb  ov070
 *   func_021B616C  0x021B616C  thumb  ov070
 *   func_02020FE4  0x02020FE4  thumb
 *   func_020213E0  0x020213E0  thumb
 *   func_0202136C  0x0202136C  thumb
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_02045CAC  0x02045CAC  arm
 *   func_021B61F4  0x021B61F4  thumb  ov070
 *   func_0201F250  0x0201F250  thumb
 *   func_021BADAC  0x021BADAC  thumb  ov070
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 *   func_021BB580  0x021BB580  thumb  ov070
 *   func_021B7688  0x021B7688  thumb  ov070
 *   func_021B795C  0x021B795C  thumb  ov070
 *   func_021B832C  0x021B832C  thumb  ov070
 *   func_021BADB8  0x021BADB8  thumb  ov070
 *   func_0204B92C  0x0204B92C  arm
 *   func_021B6EF8  0x021B6EF8  thumb  ov070
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_02035C38  0x02035C38  arm
 *   func_02051C88  0x02051C88  arm
 *   func_0202EA40  0x0202EA40  thumb
 *   func_021B63F8  0x021B63F8  thumb  ov070
 *   func_021B6138  0x021B6138  thumb  ov070
 *   func_020355C4  0x020355C4  arm
 *   func_020362DC  0x020362DC  arm
 *   func_021B61C8  0x021B61C8  thumb  ov070
 *   func_020061E4  0x020061E4  thumb
 *   func_021B9850  0x021B9850  thumb  ov070
 *   func_021B80C4  0x021B80C4  thumb  ov070
 *   func_020355D8  0x020355D8  arm
 *   func_021B8C1C  0x021B8C1C  thumb  ov070
 *   func_021B811C  0x021B811C  thumb  ov070
 *   func_021B8134  0x021B8134  thumb  ov070
 *   func_021B81B8  0x021B81B8  thumb  ov070
 *   func_021B8080  0x021B8080  thumb  ov070
 *   func_021B8EA8  0x021B8EA8  thumb  ov070
 *   func_021B8B7C  0x021B8B7C  thumb  ov070
 *   func_02082BCC  0x02082BCC  arm
 *   func_02007CC8  0x02007CC8  thumb
 *   func_0204B878  0x0204B878  arm
 *   func_021BB5DC  0x021BB5DC  thumb  ov070
 *   func_021B8B0C  0x021B8B0C  thumb  ov070
 *   func_021B6554  0x021B6554  thumb  ov070
 *   func_021BA6A4  0x021BA6A4  thumb  ov070
 *   func_0203633C  0x0203633C  arm
 *   func_021B8CE4  0x021B8CE4  thumb  ov070
 *   func_021B8F90  0x021B8F90  thumb  ov070
 */
struct WordSet;
struct MsgBank;
struct PrintSys;
struct Ctx;
struct Row;
typedef unsigned short u16;

typedef struct Obj_021B7128 {
    unsigned char pad000[0x10];
    int f010;
    unsigned char pad014[0x51C - 0x014];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x544 - 0x52C];
    u16 f544;
    unsigned char pad546[0x6A8 - 0x546];
    void *f6A8;
    unsigned char pad6AC[0x844 - 0x6AC];
    int f844;
    unsigned char pad848[0x84C - 0x848];
    unsigned int f84C;
} Obj_021B7128;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct Obj_021B7250 Obj_021B7250;

struct Obj_021B7250 {
    unsigned char pad000[0x10];
    int f010;
    unsigned char pad014[0x18 - 0x14];
    void *f018;
    unsigned char pad01C[0x20 - 0x1C];
    unsigned char f020[0x4D8];
    void (*f4F8)(Obj_021B7250 *o);
    unsigned char pad4FC[0x50C - 0x4FC];
    void *f50C;
    unsigned char pad510[0x694 - 0x510];
    void *f694;
    unsigned char pad698[0x6A4 - 0x698];
    void *f6A4;
    unsigned char pad6A8[0x80C - 0x6A8];
    int f80C;
    int f810;
    unsigned char pad814[0x818 - 0x814];
    int f818;
    int f81C;
    unsigned char pad820[0x844 - 0x820];
    int f844;
    unsigned char pad848[0x84C - 0x848];
    int f84C;
    void *f850;
    unsigned char pad854[0x85C - 0x854];
    int f85C;
};

typedef signed int     s32;

extern int func_021B61B8(unsigned char *p);
extern void *func_021B616C(unsigned char *p, int i);
extern unsigned int func_02020FE4(u16 id, unsigned int sel, u16 heap);
extern u32 func_020213E0(u16 v);
extern unsigned int func_0202136C(u16 v);
extern void func_021B6100(char *p, int k);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021B61F4(u8 *p, int a, unsigned int b);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021BADAC(void *p);
extern void func_021BB3F4(int p, int mode);
extern void func_021BB580(char *p, int v);
extern void func_021B7688(struct Obj_021B7128 *o);
extern void func_021B795C(struct Obj_021B7128 *o);
extern void func_021B832C(struct Obj_021B7128 *p);
extern void func_021BADB8(char *p, unsigned v);
extern void func_0204B92C(struct Obj_021B7128 *p, u32 v);
extern void func_021B6EF8(u8 *p);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern int func_02035C38(void);
extern s32 func_02051C88(struct Ctx *c);
extern s32 func_0202EA40(struct Row *p);
extern u32 func_021B63F8(u8 *p);
extern void func_021B6138(char *p);
extern u8 func_020355C4(void);
extern u32 func_020362DC(void);
extern int func_021B61C8(u8 *p);
extern void func_020061E4(unsigned int se);
extern void func_021B9850(char *p);
extern void func_021B80C4(struct Obj_021B7250 *o, int flag);
extern void func_020355D8(u8 v);
extern void func_021B8C1C(int p, int a, int b);
extern int func_021B811C(u8 *p);
extern int func_021B8134(struct Obj_021B7250 *o, int k);
extern void func_021B81B8(u8 *p);
extern void func_021B8080(u8 *p);
extern void func_021B8EA8(int p);
extern void func_021B8B7C(int p);
extern void func_02082BCC(void *p, int v, int n);
extern void func_02007CC8(u8 *base, void *buf, u32 id, int save);
extern void func_0204B878(struct Obj_021B7250 *p, u16 value);
extern void func_021BB5DC(int p, int mode);
extern int func_021B8B0C(void *p);
extern int func_021B6554(void *o);
extern void func_021BA6A4(char *p);
extern unsigned int func_0203633C(void);
extern void func_021B8CE4(int p, int u, int a, int b);
extern void func_021B8F90(void *o);
void func_021B7128(Obj_021B7128 *o);
void func_021B7250(Obj_021B7250 *o);


void func_021B7128(Obj_021B7128 *o)
{
    u16 *p;
    int s;

    p = func_021B616C((unsigned char *)o, func_021B61B8((unsigned char *)o));
    o->f84C = 0;
    if (p != 0)
        o->f84C = *p;
    s = o->f010;
    if (s == 2) {
        if (func_02020FE4(o->f84C, 3, o->f544) == 0 && func_020213E0(o->f84C) == 1) {
            if (func_0202136C(o->f84C) != 0)
                o->f844 = 0x12;
            else
                o->f844 = 3;
            func_021B6100((char *)o, 0);
            return;
        }
        func_02045CAC(o->f51C, 0x2F, (void *)o->f524);
        func_021B61F4((u8 *)o, 0, o->f84C);
        func_0201F250(o->f520, o->f528, (void *)o->f524);
        func_021BADAC(o);
        func_021BB3F4((int)o, 0);
        func_021BB580((char *)o, 0);
        func_021B6100((char *)o, (int)((void *)func_021B7688));
    } else if (s == 5) {
        o->f844 = 1;
        func_021B6100((char *)o, 0);
    } else if (s == 4) {
        func_021B6100((char *)o, (int)((void *)func_021B795C));
    } else {
        func_021B832C((struct Obj_021B7128 *)o);
        func_021BADB8((char *)o, o->f84C);
        func_021BADAC(o);
        func_0204B92C(o->f6A8, 0);
        func_021B6100((char *)o, (int)((void *)func_021B6EF8));
    }
}


void func_021B7250(Obj_021B7250 *o)
{
    unsigned int k;
    int v;

    if (func_0201C6B4(o->f50C) == 0)
        return;
    if (func_02035C38() == 0)
        o->f85C = 0;
    func_02051C88(o->f694);
    func_0202EA40(o->f850);
    if (o->f4F8 != func_021B7250)
        return;
    if (func_021B63F8((u8 *)o) != 0) {
        o->f818 = 0xFFFF;
        func_021B6138((char *)o);
        return;
    }
    if (o->f85C == 1)
        return;
    if (func_020355C4() == 1) {
        k = func_020362DC();
        if (k == 0)
            return;
        if (func_021B61C8((u8 *)o) != 0) {
            if ((k & 0xC0A) == 0) {
                func_020061E4(0x548);
                func_021B9850((char *)o);
                func_021B80C4(o, 1);
                return;
            }
        } else {
            func_021B80C4(o, 1);
            if (k & 0xCD)
                return;
        }
    }
    if (func_020362DC() & 2) {
        o->f844 = 1;
        o->f84C = 0;
        func_020355D8(0);
        func_021B8C1C((int)o, 4, 0);
        return;
    }
    if (func_020362DC() & 0x400) {
        if (o->f010 == 2)
            return;
        o->f844 = 0;
        o->f84C = 0;
        func_020355D8(0);
        func_021B8C1C((int)o, 3, 0);
        return;
    }
    if (func_020362DC() & 0x800) {
        if (func_021B811C((u8 *)o) != 1)
            return;
        if (o->f80C == 4) {
            func_021B8134(o, o->f810);
            func_021B6138((char *)o);
        } else {
            func_021B81B8((u8 *)o);
        }
        if (func_020355C4() != 1)
            return;
        func_021B9850((char *)o);
        func_021B80C4(o, 1);
        return;
    }
    if ((func_020362DC() & 8) && o->f80C != 2 && o->f80C != 3 && func_021B61C8((u8 *)o) > 1) {
        func_021B8080((u8 *)o);
        func_021B80C4(o, 1);
        o->f818 = 0xFFFF;
        func_021B6138((char *)o);
        func_021B6100((char *)o, (int)((void *)func_021B8EA8));
        return;
    }
    if (func_020362DC() & 1) {
        if (func_021B61C8((u8 *)o) > 0) {
            func_021B6100((char *)o, (int)((void *)func_021B8B7C));
            return;
        }
    } else if (func_020362DC() & 4) {
        if (o->f80C != 2 && o->f80C != 3 && func_021B61C8((u8 *)o) > 1) {
            func_02082BCC(o->f020, 0, 0x4D8);
            func_02007CC8(o->f018, o->f020, o->f80C, 1);
            func_0204B878(o->f6A4, 2);
            func_021BB5DC((int)o, 0);
            o->f81C = 1;
            func_021B8B0C(o);
        }
        return;
    } else if (func_021B6554(o) != 0) {
        func_021BA6A4((char *)o);
        func_020061E4(0x548);
        func_021B6138((char *)o);
        return;
    }
    if (func_0203633C() & 0x10) {
        v = o->f80C;
        o->f80C = v + 1;
        if (o->f80C >= 5)
            o->f80C = 0;
        func_020355D8(0);
        func_021B8CE4((int)o, v, 1, (int)((void *)func_021B8F90));
        return;
    }
    if (func_0203633C() & 0x20) {
        v = o->f80C;
        o->f80C = v - 1;
        if (o->f80C < 0)
            o->f80C = 4;
        func_020355D8(0);
        func_021B8CE4((int)o, v, 0, (int)((void *)func_021B8F90));
    }
}
