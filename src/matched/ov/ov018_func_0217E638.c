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

int func_020120F4(int a0);
struct Descriptor;
void *func_02045770(struct Descriptor *a0);
int func_0201C6C4(int a0, int a1);
int func_02012B70(int a0);
int func_02012B58(int a0);
void func_02043B5C(int a0, int a1);
void func_02045334(int a0);
int func_02012950(int a0, int a1);
void func_0201F02C(int a0, int a1, int a2);
void func_02045CAC(int a0, int a1, int a2);
void func_0201F250(int a0, int a1, int a2);
void func_0201C724(int a0, int a1, int a2, int a3, int a4, int a5, int a6);

void func_0217E638(Obj *p)
{
    int h;
    int anim;
    int mode;
    int v;

    h = func_020120F4(p->f00);
    if (func_0201C6C4(p->f28, (int)func_02045770((struct Descriptor *)p->f44)) == 1) {
        return;
    }
    if (func_02012B70(h) == 1) {
        v = p->fD8;
        if (v == func_02012B58(h)) {
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
        func_02043B5C((int)func_02045770((struct Descriptor *)p->f44), 0);
        func_02045334(p->f44);
        return;
    }
    if (mode >= 3 && mode <= 6) {
        func_0201F02C(p->f24, 0, func_02012950(h, p->fD8));
    }
    func_02045CAC(p->f2C, anim, p->f38);
    func_0201F250(p->f24, p->f40, p->f38);
    func_02043B5C((int)func_02045770((struct Descriptor *)p->f44), 0);
    v = p->f28;
    func_0201C724(v, (int)func_02045770((struct Descriptor *)p->f44), 0, 0, p->f40, p->f1C, 0x3C40);
    p->f48 = 1;
}
