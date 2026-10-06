/*
 * function: func_021E3E84
 * address:  0x021E3E84
 * packet:   pkt_ov170_021E3E84
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E8F50 0x021E8F50 thumb
 *   func_020362DC 0x020362DC arm
 *   func_021DD238 0x021DD238 thumb
 *   func_021EF170 0x021EF170 thumb
 *   func_020260F4 0x020260F4 thumb
 *   func_021EE008 0x021EE008 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_02035D20 0x02035D20 arm
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021EA064 0x021EA064 thumb
 *   func_021EE754 0x021EE754 thumb
 *   func_021EE3E4 0x021EE3E4 thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_021EF1D4 0x021EF1D4 thumb
 *   func_021EA808 0x021EA808 thumb
 *   func_021EE96C 0x021EE96C thumb
 *   func_021EF1A4 0x021EF1A4 thumb
 *   func_021EA0BC 0x021EA0BC thumb
 *   func_021DF0BC 0x021DF0BC thumb
 *   func_021ECC1C 0x021ECC1C thumb
 *   func_021E9C94 0x021E9C94 thumb
 *   func_021E9CE0 0x021E9CE0 thumb
 *   func_021E949C 0x021E949C thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_021E954C 0x021E954C thumb
 *   func_021EA14C 0x021EA14C thumb
 *   func_021DD1C4 0x021DD1C4 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E1A28 0x021E1A28 thumb
 *   func_021E19D4 0x021E19D4 thumb
 *   func_021E8FE0 0x021E8FE0 thumb
 *   func_021E8FD0 0x021E8FD0 thumb
 *   func_021EA798 0x021EA798 thumb
 *   func_021ECB84 0x021ECB84 thumb
 *   func_021EA114 0x021EA114 thumb
 */

typedef unsigned int u32;

typedef struct {
    void *top;
    unsigned char pad4[0x13 - 4];
    unsigned char b13;
    unsigned char b14;
    unsigned char b15;
    unsigned char b16;
    unsigned char b17;
    unsigned char b18;
    unsigned char b19;
    unsigned char b1A;
    unsigned char b1B;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char b1D;
    unsigned char pad1E[0x28 - 0x1E];
    int x28;
    char *work;
} Obj;

typedef unsigned char  u8;
struct Sound;
struct Struct_02025CD0;
extern int func_021E8F50(char *p, int v);
extern u32 func_020362DC(void);
extern void func_021DD238(char *p);
extern unsigned func_021EF170(void);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern void func_021EE008(char *p, int a, int b);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void func_020061E4(unsigned se);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_021DEFEC(Obj *p, unsigned b);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern int func_021EA064(unsigned char *p, int i, int v);
extern void func_021EE754(unsigned char *p, unsigned r);
extern void func_021EE3E4(char **p, unsigned idx);
extern void func_021DF040(char *p);
extern int func_021EF1D4(unsigned *a, unsigned *b);
extern void func_021EA808(char *p);
extern unsigned func_021EE96C(char *p);
extern unsigned func_021EF1A4(void);
extern int func_021EA0BC(unsigned char *p, unsigned char i);
extern void func_021DF0BC(unsigned char *p);
extern void func_021ECC1C(unsigned char *p);
extern int func_021E9C94(Obj *p, int a, int n);
extern int func_021E9CE0(char *p, int a, int n);
extern int func_021E949C(char *p, int a, int b);
extern u8 func_020260E0(struct Sound *obj);
extern int func_021E954C(Obj *p, int id, int lo, int arg);
extern int func_021EA14C(unsigned char *p, unsigned i, int v);
extern void func_021DD1C4(char *p, int a);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E1A28(char *p);
extern int func_021E19D4(char *p);
extern int func_021E8FE0(char *p, int v);
extern int func_021E8FD0(char *p, int a);
extern int func_021EA798(unsigned char *p, int sel);
extern void func_021ECB84(char *w, unsigned i);
extern int func_021EA114(char *p, int a);

#define OBJ(p) (*(void **)((p)->work + 0x70))

int func_021E3E84(Obj *p)
{
    unsigned r;
    if (p->hi == 1) {
        p->lo = 0;
        p->hi = 0;
        return func_021E8F50((char *)p, 0x21);
    }
    if ((func_020362DC() & 4) && p->lo != 0 && p->b18 == 0) {
        func_021DD238((char *)p);
        p->lo = 0;
        return func_021E8F50((char *)p, 0x21);
    }
    if (p->b18 == 0) {
        r = func_021EF170();
        if (r != -1) {
            func_020260F4(OBJ(p), 0);
            if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
                func_020061E4(0x666);
                func_02035D20((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
                func_021DEFEC(p, r);
                return func_021EA064((unsigned char *)p, r, 0x20);
            }
            func_020260E4(OBJ(p), r);
            func_021EE754((unsigned char *)p, r);
            *(int *)(p->work + 0xA168) = r;
            func_021EE3E4((char **)p, r);
            func_021DF040((char *)p);
            return 0x20;
        }
        r = func_021EF1A4();
        if (r != -1) {
            func_020260F4(OBJ(p), 0);
            if (func_021DD25C((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
                func_020061E4(0x666);
                func_02035D20((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
                func_021DEFEC(p, r + 0x1E);
                return func_021EA064((unsigned char *)p, r + 0x1E, 0x20);
            }
            func_020260E4(OBJ(p), r + 0x1E);
            func_021EE754((unsigned char *)p, r + 0x1E);
            *(int *)(p->work + 0xA168) = r + 0x1E;
            func_021EE3E4((char **)p, r + 0x1E);
            func_021DF040((char *)p);
            return 0x20;
        }
    }
    r = func_021EE96C((char *)p);
    switch (r) {
    case 0x24:
        if (p->b18 != 0)
            break;
        func_020061E4(0x54C);
        func_021DF040((char *)p);
        return func_021E8F50((char *)p, 0x5D);
    case 0x25:
        func_020061E4(0x548);
        func_020260E4(OBJ(p), 0x24);
        func_021EE3E4((char **)p, 0x24);
        func_021EE754((unsigned char *)p, 0x24);
        *(int *)(p->work + 0xA168) = 0x24;
        if (p->b18 == 0)
            func_021DF0BC((unsigned char *)p);
        else
            func_021ECC1C((unsigned char *)p);
        return func_021E9C94(p, 0, 0x20);
    case 0x26:
        func_020061E4(0x548);
        func_020260E4(OBJ(p), 0x24);
        func_021EE3E4((char **)p, 0x24);
        func_021EE754((unsigned char *)p, 0x24);
        *(int *)(p->work + 0xA168) = 0x24;
        if (p->b18 == 0)
            func_021DF0BC((unsigned char *)p);
        else
            func_021ECC1C((unsigned char *)p);
        return func_021E9CE0((char *)p, 0, 0x20);
    case 0x27:
        func_020061E4(0x54C);
        if (p->b18 == 0)
            func_021DF040((char *)p);
        return func_021E949C((char *)p, 0xB, func_021E8F50((char *)p, 0x22));
    case 0x28:
        if (p->b18 == 0) {
            unsigned char v = func_020260E0(OBJ(p));
            if (v >= 0x24 || func_021DD25C((void ***)p, v, p->b14, 0xA9, 0) == 0)
                break;
            p->b16 = v;
            p->b17 = p->b14;
            p->b13 = 4;
        } else {
            p->b13 = 5;
            p->b1D = func_020260E0(OBJ(p));
        }
        func_020061E4(0x54C);
        return func_021E954C(p, 8, 1, 0x4F);
    case 0x29:
        if (p->b18 != 0)
            break;
        func_020061E4(0x551);
        p->lo = 0;
        return func_021E954C(p, 6, 9, func_021E8F50((char *)p, 0x21));
    case 0x2A:
        if (p->lo == 0 || p->b18 != 0)
            break;
        p->lo = 0;
        return func_021E8F50((char *)p, 0x21);
    case -2:
        if (p->b18 == 1)
            return func_021EA14C((unsigned char *)p, 0xFF, 0x20);
        func_020061E4(0x551);
        p->lo = 0;
        return func_021E954C(p, 6, 9, func_021E8F50((char *)p, 0x21));
    case -6:
        if (func_020260E0(OBJ(p)) != 0x24)
            break;
        func_020061E4(0x548);
        return func_021E9C94(p, 0, 0x20);
    case -5:
        if (func_020260E0(OBJ(p)) != 0x24)
            break;
        func_020061E4(0x548);
        return func_021E9CE0((char *)p, 0, 0x20);
    case -4:
        func_020061E4(0x548);
        break;
    case -3:
        func_020061E4(0x548);
        if (p->b18 == 0) {
            unsigned char v = func_020260E0(OBJ(p));
            if (v < 0x24)
                func_021DEFEC(p, v);
            else
                func_021DF040((char *)p);
        }
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x20));
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (p->b18 == 1)
            return func_021EA14C((unsigned char *)p, r, 0x20);
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            p->b16 = r;
            p->b17 = p->b14;
            func_021ECB84(p->work, p->b16);
            return func_021EA0BC((unsigned char *)p, p->b16);
        }
        break;
    }
    return 0x20;
}
