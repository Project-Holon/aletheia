/*
 * file:     itemmenu_p04.c
 * unit:     yes
 * function: func_021B795C, func_021B7A7C, func_021B7B08
 * address:  0x021B795C
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
 *   func_0204B92C  0x0204B92C  arm
 *   func_02020FE4  0x02020FE4  thumb
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 *   func_02045CAC  0x02045CAC  arm
 *   func_021B61F4  0x021B61F4  thumb  ov070
 *   func_0201F250  0x0201F250  thumb
 *   func_021BADAC  0x021BADAC  thumb  ov070
 *   func_021BB580  0x021BB580  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B7C88  0x021B7C88  thumb  ov070
 *   func_021BB08C  0x021BB08C  thumb  ov070
 *   func_021B61B8  0x021B61B8  thumb  ov070
 *   func_021B616C  0x021B616C  thumb  ov070
 *   func_021B7D9C  0x021B7D9C  thumb  ov070
 *   func_021BADF0  0x021BADF0  thumb  ov070
 *   func_021B7DF4  0x021B7DF4  thumb  ov070
 *   func_021B8DAC  0x021B8DAC  thumb  ov070
 *   func_020362DC  0x020362DC  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021B7DD0  0x021B7DD0  thumb  ov070
 *   func_021B8C1C  0x021B8C1C  thumb  ov070
 *   func_021B8E08  0x021B8E08  thumb  ov070
 *   func_021BB0F8  0x021BB0F8  thumb  ov070
 *   func_021B619C  0x021B619C  thumb  ov070
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_021B7B80  0x021B7B80  thumb  ov070
 */
struct WordSet;
struct MsgBank;
typedef unsigned short u16;

typedef struct Obj_021B795C {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x544 - 0x52C];
    u16 f544;
    unsigned char pad546[0x6A8 - 0x546];
    void *f6A8;
    unsigned char pad6AC[0x7F4 - 0x6AC];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj_021B795C;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct Obj_021B7A7C Obj_021B7A7C;

typedef struct Obj_021B7B08 {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x544 - 0x52C];
    u16 f544;
    unsigned char pad546[0x7F4 - 0x546];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj_021B7B08;

extern void func_0204B92C(struct Obj_021B795C *p, u32 v);
extern unsigned int func_02020FE4(u16 id, unsigned int sel, u16 heap);
extern void func_021BB3F4(int p, int mode);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021B61F4(u8 *p, int a, unsigned int b);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021BADAC(void *p);
extern void func_021BB580(char *p, int v);
extern void func_021B6100(char *p, int k);
extern void func_021B7C88();
extern void func_021BB08C(char *p);
extern int func_021B61B8(u8 *p);
extern u16 *func_021B616C(Obj_021B795C *o, int k);
extern void func_021B7D9C(u8 *p, int v);
extern int func_021BADF0(int p);
extern int func_021B7DF4(struct Obj_021B7A7C *o);
extern int func_021B8DAC(void);
extern u32 func_020362DC(void);
extern void func_020355D8(u8 v);
extern void func_020061E4(unsigned int id);
extern void func_021B7DD0(u8 *p);
extern void func_021B8C1C(int p, int a, int b);
extern void func_021B8E08(unsigned char *p);
extern void func_021BB0F8(int p);
extern int func_021B619C(int a, int b, unsigned int id);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_021B7B80(struct Obj_021B7B08 *o);
void func_021B795C(Obj_021B795C *o);
void func_021B7A7C(Obj_021B7A7C *o);
void func_021B7B08(Obj_021B7B08 *o);


void func_021B795C(Obj_021B795C *o)
{
    unsigned int a;
    unsigned int b;

    func_0204B92C(o->f6A8, 0);
    a = func_02020FE4(o->f84C, 0, o->f544);
    b = func_02020FE4(o->f84C, 3, o->f544);
    if (a == 0 || b != 0) {
        func_021BB3F4((int)o, 0);
        func_02045CAC(o->f51C, 0x4D, (void *)o->f524);
        func_021B61F4((u8 *)o, 0, o->f84C);
        func_0201F250(o->f520, o->f528, (void *)o->f524);
        func_021BADAC(o);
        func_021BB580((char *)o, 0);
        func_021B6100((char *)o, (int)((void *)func_021B7C88));
        return;
    }
    o->f7F4 = 1;
    func_021BB08C((char *)o);
    func_021BB3F4((int)o, 0);
    if (func_021B616C(o, func_021B61B8((u8 *)o))[1] == 1) {
        func_021B6100((char *)o, (int)((void *)func_021B7B08));
        return;
    }
    func_021B7D9C((u8 *)o, 2);
    func_02045CAC(o->f51C, 0x4E, (void *)o->f524);
    func_021B61F4((u8 *)o, 0, o->f84C);
    func_0201F250(o->f520, o->f528, (void *)o->f524);
    func_021BADAC(o);
    func_021B6100((char *)o, (int)((void *)func_021B7A7C));
}


void func_021B7A7C(Obj_021B7A7C *o)
{
    int r;

    if (func_021BADF0((int)o) == 0)
        return;
    if (func_021B7DF4(o) == 1)
        return;
    r = func_021B8DAC();
    if (r == -1) {
        if (func_020362DC() & 1) {
            r = 0;
            func_020355D8(0);
        } else if (func_020362DC() & 2) {
            func_020355D8(0);
            r = 1;
        }
    }
    if (r == 0) {
        func_020061E4(0x54C);
        func_021B7DD0((u8 *)o);
        func_021B6100((char *)o, (int)((void *)func_021B7B08));
        return;
    }
    if (r == 1) {
        func_020061E4(0x551);
        func_021B8C1C((int)o, 4, (int)((void *)func_021B8E08));
    }
}


void func_021B7B08(Obj_021B7B08 *o)
{
    int v;

    func_021BB0F8((int)o);
    v = func_021B619C(o->f84C, o->f7F4, o->f544);
    func_02045CAC(o->f51C, 0x4F, (void *)o->f524);
    func_0201EFA4(o->f520, 0, v, 7, 0, 1);
    func_0201F250(o->f520, o->f528, (void *)o->f524);
    func_021BADAC(o);
    func_021B6100((char *)o, (int)((void *)func_021B7B80));
}
