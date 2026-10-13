/*
 * function: func_021E2CBC
 * address:  0x021E2CBC
 * packet:   pkt_ov170_021E2CBC
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E8F50 0x021E8F50 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   func_021DD238 0x021DD238 thumb
 *   func_021EF170 0x021EF170 thumb
 *   func_020260F4 0x020260F4 thumb
 *   func_021EE008 0x021EE008 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021EA064 0x021EA064 thumb
 *   func_021EE754 0x021EE754 thumb
 *   func_021EE3E4 0x021EE3E4 thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_021EF1D4 0x021EF1D4 thumb
 *   func_021EA808 0x021EA808 thumb
 *   func_021EE850 0x021EE850 thumb
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
extern u32 KEY_GetTrg(void);
extern void func_021DD238(char *p);
extern unsigned func_021EF170(void);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern void func_021EE008(char *p, int a, int b);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern void func_021DEFEC(char *p, int b);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern int func_021EA064(unsigned char *p, int i, int v);
extern void func_021EE754(unsigned char *p, unsigned r);
extern void func_021EE3E4(char **p, unsigned idx);
extern void func_021DF040(char *p);
extern int func_021EF1D4(unsigned *a, unsigned *b);
extern void func_021EA808(char *p);
extern unsigned func_021EE850(char *p);
extern void func_021DF0BC(unsigned char *p);
extern void func_021ECC1C(unsigned char *p);
extern int func_021E9C94(char *p, int a, int n);
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

int func_021E2CBC(Obj *p)
{
    unsigned r;
    unsigned x;
    unsigned y;
    if (p->hi == 1) {
        p->lo = 0;
        p->hi = 0;
        return func_021E8F50((char *)p, 0x16);
    }
    if ((KEY_GetTrg() & 4) && p->lo != 0 && p->b18 == 0) {
        func_021DD238((char *)p);
        p->lo = 0;
        return func_021E8F50((char *)p, 0x16);
    }
    if (p->b18 == 0) {
        r = func_021EF170();
        if (r != -1) {
            func_020260F4(OBJ(p), 0);
            func_021EE008((char *)p, 0, 0);
            if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
                GFL_USE_PlaySeDefaultVolume(0x666);
                TOUCHPANEL_GetPointTrg((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
                func_021DEFEC((char *)p, r);
                func_020260E4(OBJ(p), r);
                return func_021EA064((unsigned char *)p, r, 0x15);
            }
            func_020260E4(OBJ(p), r);
            func_021EE754((unsigned char *)p, r);
            *(int *)(p->work + 0xA168) = r;
            func_021EE3E4((char **)p, r);
            func_021DF040((char *)p);
            return 0x15;
        }
    }
    if (func_021EF1D4(&x, &y) == 1) {
        *(unsigned *)(p->work + 0xA184) = y;
        p->x28 = 0x15;
        func_021EA808((char *)p);
        return 0xF;
    }
    r = func_021EE850((char *)p);
    switch (r) {
    case 0x1E:
        func_021EE008((char *)p, 0, 0);
        if (p->b18 != 0)
            break;
        GFL_USE_PlaySeDefaultVolume(0x54C);
        func_021DF040((char *)p);
        return func_021E8F50((char *)p, 0x5D);
    case 0x1F:
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_021EE008((char *)p, 0, 0);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        func_021EE754((unsigned char *)p, 0x1E);
        *(int *)(p->work + 0xA168) = 0x1E;
        if (p->b18 == 0)
            func_021DF0BC((unsigned char *)p);
        else
            func_021ECC1C((unsigned char *)p);
        return func_021E9C94((char *)p, 0, 0x15);
    case 0x20:
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_021EE008((char *)p, 0, 0);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        func_021EE754((unsigned char *)p, 0x1E);
        *(int *)(p->work + 0xA168) = 0x1E;
        if (p->b18 == 0)
            func_021DF0BC((unsigned char *)p);
        else
            func_021ECC1C((unsigned char *)p);
        return func_021E9CE0((char *)p, 0, 0x15);
    case 0x27:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (p->b18 == 0)
            func_021DF040((char *)p);
        return func_021E949C((char *)p, 0xA, func_021E8F50((char *)p, 0x19));
    case 0x28:
        if (p->b18 == 0) {
            unsigned char v = func_020260E0(OBJ(p));
            if (v >= 0x1E || func_021DD25C((void ***)p, v, p->b14, 0xA9, 0) == 0)
                break;
            p->b16 = v;
            p->b17 = p->b14;
            p->b13 = 2;
        } else {
            p->b13 = 3;
            p->b1D = func_020260E0(OBJ(p));
        }
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return func_021E954C(p, 8, 1, 0x4F);
    case 0x29:
        if (p->b18 != 0)
            break;
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->lo = 0;
        return func_021E954C(p, 6, 9, func_021E8F50((char *)p, 0x16));
    case 0x2A:
        if (p->lo == 0 || p->b18 != 0)
            break;
        p->lo = 0;
        return func_021E8F50((char *)p, 0x16);
    case -2:
        if (p->b18 == 1)
            return func_021EA14C((unsigned char *)p, 0xFF, 0x15);
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->lo = 0;
        return func_021E954C(p, 6, 9, func_021E8F50((char *)p, 0x16));
    case -8:
        if (func_020260E0(OBJ(p)) != 0x22)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_021DD1C4((char *)p, -1);
        return func_021E8FC0((char *)p, (int)func_021E1A28, 0x15);
    case -7:
        if (func_020260E0(OBJ(p)) != 0x25)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_021DD1C4((char *)p, 1);
        return func_021E8FC0((char *)p, (int)func_021E19D4, 0x15);
    case -6:
        if (func_020260E0(OBJ(p)) != 0x1E)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        return func_021E9C94((char *)p, 0, 0x15);
    case -5:
        if (func_020260E0(OBJ(p)) != 0x1E)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        return func_021E9CE0((char *)p, 0, 0x15);
    case -3: {
        unsigned char v;
        GFL_USE_PlaySeDefaultVolume(0x548);
        v = func_020260E0(OBJ(p));
        if (p->b18 == 0) {
            if (v < 0x1E)
                func_021DEFEC((char *)p, v);
            else
                func_021DF040((char *)p);
        }
        if (v >= 0x22 && v <= 0x25)
            func_021EE008((char *)p, v - 0x22, 1);
        else
            func_021EE008((char *)p, 0, 0);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x15));
    }
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case 0x21:
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_021DD1C4((char *)p, -1);
        return func_021E8FC0((char *)p, (int)func_021E1A28, 0x15);
    case 0x26:
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_021DD1C4((char *)p, 1);
        return func_021E8FC0((char *)p, (int)func_021E19D4, 0x15);
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
        func_021EE008((char *)p, r - 0x22, 1);
        if (p->b18 == 1)
            return func_021EA14C((unsigned char *)p, r + 2, 0x15);
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_021DF040((char *)p);
        *(unsigned char *)(p->work + 0xA17F) = p->b19 + r - 0x22;
        if (*(unsigned char *)(p->work + 0xA17F) >= p->b15)
            *(unsigned char *)(p->work + 0xA17F) -= p->b15;
        if (*(unsigned char *)(p->work + 0xA17F) != p->b14)
            return func_021EA798((unsigned char *)p, 0);
        break;
    case -1:
        break;
    default:
        func_021EE008((char *)p, 0, 0);
        if (p->b18 == 1)
            return func_021EA14C((unsigned char *)p, r, 0x15);
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            p->b16 = r;
            p->b17 = p->b14;
            func_021ECB84(p->work, p->b16);
            return func_021EA114((char *)p, p->b16);
        }
        break;
    }
    return 0x15;
}
