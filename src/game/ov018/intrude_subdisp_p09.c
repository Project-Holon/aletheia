/*
 * file:     intrude_subdisp_p09.c
 * unit:     yes
 * function: func_0217E524, func_0217E638
 * address:  0x0217E524
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0217F1E8  0x0217F1E8  thumb  ov018
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0217F214  0x0217F214  thumb  ov018
 *   func_0217F240  0x0217F240  thumb  ov018
 *   func_020127B8  0x020127B8  thumb
 *   func_020061E4  0x020061E4  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   MIi_CpuCopy32  0x02082A90  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02012950  0x02012950  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_0201C724  0x0201C724  thumb
 */
struct Ctx;
struct Obj_0217E524;
struct BigObj;
struct CharBuf;
struct MsgBank;
struct PrintSys;
struct Rec44;
struct Sub24;
struct WordSet;
struct Descriptor;
typedef unsigned char u8;

typedef short s16;

typedef struct {
    u8 pad00[0x14];
    u8 *f14;
} Gfx;

typedef struct {
    int f00;
    u8 pad04[0xAC - 0x04];
    int fAC;
    u8 padB0[0xCC - 0xB0];
    Gfx *fCC;
    u8 *fD0;
    u8 padD4[0xDC - 0xD4];
    int fDC;
    int fE0;
    u8 padE4[0x10A - 0xE4];
    s16 f10A;
    u8 pad10C[0x10F - 0x10C];
    u8 f10F;
} Obj_0217E524;

typedef unsigned int   u32;

typedef struct {
    int f00;
    u8 pad04[0x1C - 0x04];
    int f1C;
    u8 pad20[0x24 - 0x20];
    int f24;
    int f28;
    int f2C;
    u8 pad30[0x38 - 0x30];
    int f38;
    u8 pad3C[0x40 - 0x3C];
    int f40;
    int f44;
    u8 f48;
    u8 pad49[0xD8 - 0x49];
    u8 fD8;
    u8 padD9[0x10C - 0xD9];
    u8 f10C;
} Obj_0217E638;

typedef unsigned short u16;

extern void *func_020120F4(const struct Ctx *p);
extern int func_0217F1E8(u8 *p);
extern unsigned int func_0204B3F4(struct Obj_0217E524 *p);
extern void func_0204B3DC(struct Obj_0217E524 *a0, unsigned int a1);
extern void func_0217F214(void);
extern void func_0217F240(u8 *p, int mode);
extern void *func_020127B8(void *p);
extern void func_020061E4(u32 a);
extern void MIi_CpuCopy32(const void *src, void *dst, int size);
void *func_02045770(struct Descriptor *a0);
u32 func_0201C6C4(struct PrintSys *p, void *v);
int func_02012B70(const struct BigObj *p);
u8 func_02012B58(const struct BigObj *p);
void func_02043B5C(struct CharBuf *buf, u8 value);
void func_02045334(struct Descriptor *a0);
struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
void func_0201F250(struct WordSet *ws, void *dst, void *src);
void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_0217E524(Obj_0217E524 *p);
void func_0217E638(Obj_0217E638 *p);


void func_0217E524(Obj_0217E524 *p)
{
    int h;
    int v;
    int i;
    int rem;
    u8 *base;

    h = (int)func_020120F4((const struct Ctx *)p->f00);
    if (func_0217F1E8((u8 *)p) == 0) {
        if (func_0204B3F4((struct Obj_0217E524 *)p->fAC) == 1) {
            func_0204B3DC((struct Obj_0217E524 *)p->fAC, 0);
            func_0217F214();
        }
        return;
    }
    if (func_0204B3F4((struct Obj_0217E524 *)p->fAC) == 0) {
        func_0204B3DC((struct Obj_0217E524 *)p->fAC, 1);
        func_0217F240((u8 *)p, 1);
    }
    func_020127B8((void *)h);
    v = p->fE0;
    if (p->f10A != -1 && p->f10A != v && v <= 5 && p->fDC == 3) {
        func_020061E4(0x550);
    }
    if (p->f10A == v) {
        return;
    }
    base = p->fCC->f14;
    p->f10A = v;
    for (i = 0; i < 3; i++) {
        rem = v % 10;
        v = v / 10;
        MIi_CpuCopy32(base + rem * 0x40, p->fD0 + (2 - i) * 0x40, 0x40);
        MIi_CpuCopy32(base + (rem * 0x40 + 0x280), p->fD0 + ((2 - i) * 0x40 + 0x100), 0x40);
    }
    p->f10F = 1;
}


void func_0217E638(Obj_0217E638 *p)
{
    int h;
    int anim;
    int mode;
    int v;

    h = (int)func_020120F4((const struct Ctx *)p->f00);
    if (func_0201C6C4((struct PrintSys *)p->f28, (void *)((int)func_02045770((struct Descriptor *)p->f44))) == 1) {
        return;
    }
    if (func_02012B70((const struct BigObj *)h) == 1) {
        v = p->fD8;
        if (v == func_02012B58((const struct BigObj *)h)) {
            mode = 2;
            anim = 0x43;
        } else {
            mode = v + 3;
            anim = 0x44;
        }
    } else {
        mode = 7;
    }
    if (p->f10C == mode || mode == 0) {
        return;
    }
    p->f10C = mode;
    if (mode == 7) {
        func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)p->f44)), 0);
        func_02045334((struct Descriptor *)p->f44);
        return;
    }
    if (mode >= 3 && mode <= 6) {
        func_0201F02C((struct WordSet *)p->f24, 0, func_02012950((struct Sub24 *)h, p->fD8));
    }
    func_02045CAC((struct MsgBank *)p->f2C, anim, (void *)p->f38);
    func_0201F250((struct WordSet *)p->f24, (void *)p->f40, (void *)p->f38);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)p->f44)), 0);
    v = p->f28;
    func_0201C724((void *)v, (int)func_02045770((struct Descriptor *)p->f44), 0, 0, p->f40, p->f1C, 0x3C40);
    p->f48 = 1;
}
