/*
 * function: func_0217E638
 * address:  0x0217E638
 * packet:   pkt_ov018_0217E638
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020120F4  0x020120F4  thumb
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

typedef unsigned char u8;

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
} Obj;

typedef unsigned int   u32;
struct BigObj;
struct CharBuf;
struct Ctx;
struct MsgBank;
struct PrintSys;
struct Rec44;
struct Sub24;
struct WordSet;
void *func_020120F4(const struct Ctx *p);
struct Descriptor;
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
void func_0201C724(int a0, int a1, int a2, int a3, int a4, int a5, int a6);

void func_0217E638(Obj *p)
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
    func_0201C724(v, (int)func_02045770((struct Descriptor *)p->f44), 0, 0, p->f40, p->f1C, 0x3C40);
    p->f48 = 1;
}
