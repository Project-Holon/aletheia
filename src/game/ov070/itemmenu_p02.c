/*
 * file:     itemmenu_p02.c
 * unit:     yes
 * function: func_021B7504, func_021B7584, func_021B75A4, func_021B761C
 * address:  0x021B7504
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
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_021BA9AC  0x021BA9AC  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_020414EC  0x020414EC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 *   func_020355C4  0x020355C4  arm
 *   func_021B9AAC  0x021B9AAC  thumb  ov070
 *   func_021B80C4  0x021B80C4  thumb  ov070
 *   func_021B8AF4  0x021B8AF4  thumb  ov070
 *   func_021BB1AC  0x021BB1AC  thumb  ov070
 *   func_021BADF0 0x021BADF0 thumb ov070
 *   func_021BB0F8 0x021BB0F8 thumb ov070
 *   func_02006238  0x02006238  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_020212B0  0x020212B0  thumb
 *   func_0201EF34  0x0201EF34  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021BACF0  0x021BACF0  thumb  ov070
 *   func_020061E4 0x020061E4 thumb
 */
struct TaskMenu;
struct Obj;
struct MsgBank;
struct WordSet;
typedef struct Obj_021B7504 {
    unsigned char pad000[0x6A8];
    void *f6A8;
    unsigned char pad6AC[0x77C - 0x6AC];
    void *f77C;
    unsigned char pad780[0x844 - 0x780];
    int f844;
} Obj_021B7504;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct Obj_021B75A4 {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x84C - 0x52C];
    unsigned int f84C;
} Obj_021B75A4;

extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_021BA9AC(char *p);
extern void func_021B6100(char *p, int k);
extern void func_020414EC(u32 i);
extern void func_0204B92C(struct Obj_021B7504 *p, u32 v);
extern void func_021BB3F4(int p, int mode);
extern u8 func_020355C4(void);
extern void func_021B9AAC(char *p);
extern void func_021B80C4(Obj_021B7504 *o, int v);
extern void func_021B8AF4(void *p);
extern void func_021BB1AC(char *p);
extern int func_021BADF0(int p);
extern void func_021BB0F8(int p);
extern int func_02006238(void);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u16 func_020212B0(u16 id);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021BACF0(int p, int mode);
extern void func_020061E4(unsigned int id);
void func_021B7504(Obj_021B7504 *o);
void func_021B7584(int p);
void func_021B75A4(Obj_021B75A4 *o);
void func_021B761C(int p);


void func_021B7504(Obj_021B7504 *o)
{
    if (func_020279E8(o->f77C) == 0)
        return;
    if (func_02027A04(o->f77C) == 0) {
        func_021BA9AC((char *)o);
        o->f844 = 6;
        func_021B6100((char *)o, 0);
    } else {
        func_021BA9AC((char *)o);
        func_020414EC(3);
        func_0204B92C(o->f6A8, 1);
        func_021BB3F4((int)o, 1);
        if (func_020355C4() == 1) {
            func_021B9AAC((char *)o);
            func_021B80C4(o, 0);
        } else {
            func_021B80C4(o, 1);
        }
        func_021B8AF4(o);
    }
    func_021BB1AC((char *)o);
}

void func_021B7584(int p) { if (func_021BADF0(p)) { func_021BB0F8(p); func_021B6100((void *)p,(int)((void *)func_021B7504)); } }


void func_021B75A4(Obj_021B75A4 *o)
{
    if (func_02006238() == 1)
        return;
    if ((func_020362DC() & 3) == 0 && func_02035C60() == 0)
        return;
    func_02045CAC(o->f51C, 0x3E, (void *)o->f524);
    func_0201EF34(o->f520, 0, func_020212B0(o->f84C));
    func_0201F250(o->f520, o->f528, (void *)o->f524);
    func_021BACF0((int)o, 1);
    func_021B6100((char *)o, (int)((void *)func_021B7584));
}

void func_021B761C(int p) { if (func_021BADF0(p)) { func_020061E4(0x55C); func_021B6100((void *)p,(int)((void *)func_021B75A4)); } }
