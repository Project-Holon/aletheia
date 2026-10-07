/*
 * file:     itemmenu_p03.c
 * unit:     yes
 * function: func_021B7640, func_021B7688, func_021B76E4, func_021B7700, func_021B77E4, func_021B7804, func_021B7868
 * address:  0x021B7640
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
 *   func_02021350  0x02021350  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_021BACF0  0x021BACF0  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B761C  0x021B761C  thumb  ov070
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_020414EC  0x020414EC  arm
 *   func_021B6138  0x021B6138  thumb  ov070
 *   func_021BA6A4  0x021BA6A4  thumb  ov070
 *   func_0204B92C  0x0204B92C  arm
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 *   func_021B8AF4  0x021B8AF4  thumb  ov070
 *   func_021BADF0 0x021BADF0 thumb ov070
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_021BB1AC  0x021BB1AC  thumb  ov070
 *   func_020061E4  0x020061E4  thumb
 *   func_021B7D20  0x021B7D20  thumb  ov070
 *   func_021B6204  0x021B6204  thumb  ov070
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021BADAC  0x021BADAC  thumb  ov070
 *   func_020355C4  0x020355C4  arm
 *   func_021B80C4  0x021B80C4  thumb  ov070
 *   func_021BB0F8 0x021BB0F8 thumb ov070
 *   func_021B7D9C  0x021B7D9C  thumb  ov070
 *   func_021B7DF4  0x021B7DF4  thumb  ov070
 *   func_021B8DAC  0x021B8DAC  thumb  ov070
 *   func_020355D8  0x020355D8  arm
 *   func_021B7DD0  0x021B7DD0  thumb  ov070
 *   func_021B8C1C  0x021B8C1C  thumb  ov070
 *   func_021B8DCC  0x021B8DCC  thumb  ov070
 */
struct MsgBank;
struct Obj;
struct TaskMenu;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct Obj_021B7640 {
    unsigned char pad000[0x51C];
    void *f51C;
    unsigned char pad520[0x528 - 0x520];
    unsigned int f528;
    unsigned char pad52C[0x84C - 0x52C];
    unsigned int f84C;
} Obj_021B7640;

typedef unsigned int   u32;

typedef struct Obj_021B7688 {
    unsigned char pad000[0x6A8];
    void *f6A8;
    unsigned char pad6AC[0x818 - 0x6AC];
    int f818;
    unsigned char pad81C[0x83E - 0x81C];
    u16 f83E;
} Obj_021B7688;

typedef struct Obj_021B7700 {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x6A8 - 0x52C];
    void *f6A8;
    unsigned char pad6AC[0x77C - 0x6AC];
    void *f77C;
    unsigned char pad780[0x7F4 - 0x780];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj_021B7700;

typedef struct Obj_021B7804 {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x7F4 - 0x52C];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj_021B7804;

typedef struct Obj_021B7868 {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x7F4 - 0x52C];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj_021B7868;

extern u8 func_02021350(u16 id);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021BACF0(int p, int mode);
extern void func_021B6100(char *p, int k);
extern void func_021B761C(int p);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_020414EC(u32 i);
extern void func_021B6138(char *p);
extern void func_021BA6A4(char *p);
extern void func_0204B92C(struct Obj_021B7688 *p, u32 v);
extern void func_021BB3F4(int p, int mode);
extern void func_021B8AF4(void *p);
extern int func_021BADF0(int p);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_021BB1AC(char *p);
extern void func_020061E4(unsigned int se);
extern void func_021B7D20(struct Obj_021B7700 *o, int x);
extern void func_021B6204(u8 *p, int a, unsigned int b, int c, int d);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021BADAC(void *p);
extern u8 func_020355C4(void);
extern void func_021B80C4(Obj_021B7700 *o, int v);
extern void func_021BB0F8(int p);
extern void func_021B7D9C(u8 *p, int v);
extern int func_021B7DF4(Obj_021B7868 *o);
extern int func_021B8DAC(void);
extern void func_020355D8(u8 v);
extern void func_021B7DD0(u8 *p);
extern void func_021B8C1C(int p, int a, int b);
extern void func_021B8DCC(char *p);
void func_021B7640(Obj_021B7640 *o);
void func_021B7688(Obj_021B7688 *o);
void func_021B76E4(int p);
void func_021B7700(Obj_021B7700 *o);
void func_021B77E4(int p);
void func_021B7804(Obj_021B7804 *o);
void func_021B7868(Obj_021B7868 *o);


void func_021B7640(Obj_021B7640 *o)
{
    if (func_02021350(o->f84C) == 0xFF)
        func_02045CAC(o->f51C, 0x3C, (void *)o->f528);
    else
        func_02045CAC(o->f51C, 0x3D, (void *)o->f528);
    func_021BACF0((int)o, 1);
    func_021B6100((char *)o, (int)((void *)func_021B761C));
}


void func_021B7688(Obj_021B7688 *o)
{
    if ((func_020362DC() & 3) || func_02035C60() != 0) {
        func_020414EC(3);
        o->f818 = 0xFFFF;
        func_021B6138((char *)o);
        o->f83E = 1;
        func_021BA6A4((char *)o);
        func_0204B92C(o->f6A8, 1);
        func_021BB3F4((int)o, 1);
        func_021B8AF4(o);
    }
}

void func_021B76E4(int p) { if (func_021BADF0(p)) func_021B6100((void *)p,(int)((void *)func_021B7688)); }


void func_021B7700(Obj_021B7700 *o)
{
    int r;
    int v;

    if (func_020279E8(o->f77C) == 0)
        return;
    r = func_02027A04(o->f77C);
    func_021BB1AC((char *)o);
    func_020414EC(3);
    if (r == 0) {
        func_020061E4(0x647);
        func_021B7D20(o, o->f7F4);
        func_02045CAC(o->f51C, 0x36, (void *)o->f524);
        func_021B6204((u8 *)o, 0, o->f84C, o->f7F4 > 1, 0);
        func_0201EFA4(o->f520, 1, o->f7F4, 3, 0, 1);
        func_0201F250(o->f520, o->f528, (void *)o->f524);
        func_021BADAC(o);
        func_021B6100((char *)o, (int)((void *)func_021B76E4));
    } else {
        func_0204B92C(o->f6A8, 1);
        v = 1;
        func_021BB3F4((int)o, 1);
        if (func_020355C4() != 0)
            v = 0;
        func_021B80C4(o, v);
        func_021B8AF4(o);
    }
}

void func_021B77E4(int p) { if (func_021BADF0(p)) { func_021BB0F8(p); func_021B6100((void *)p,(int)((void *)func_021B7700)); } }


void func_021B7804(Obj_021B7804 *o)
{
    o->f7F4 = 1;
    func_021B7D9C((u8 *)o, 1);
    func_02045CAC(o->f51C, 0x35, (void *)o->f524);
    func_021B6204((u8 *)o, 0, o->f84C, 1, 0);
    func_0201F250(o->f520, o->f528, (void *)o->f524);
    func_021BADAC(o);
    func_021B6100((char *)o, (int)((void *)func_021B7868));
}


void func_021B7868(Obj_021B7868 *o)
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
        func_02045CAC(o->f51C, 0x37, (void *)o->f524);
        func_021B6204((u8 *)o, 0, o->f84C, o->f7F4 > 1, 0);
        func_0201EFA4(o->f520, 1, o->f7F4, 3, 0, 1);
        func_0201F250(o->f520, o->f528, (void *)o->f524);
        func_021BADAC(o);
        func_021B6100((char *)o, (int)((void *)func_021B77E4));
        return;
    }
    if (r == 1) {
        func_020061E4(0x551);
        func_021B8C1C((int)o, 4, (int)((void *)func_021B8DCC));
    }
}
