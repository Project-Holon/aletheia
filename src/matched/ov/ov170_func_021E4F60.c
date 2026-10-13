/*
 * function: func_021E4F60
 * address:  0x021E4F60
 * packet:   pkt_ov170_021E4F60
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   func_021EA9F4 0x021EA9F4 thumb
 *   func_021EF170 0x021EF170 thumb
 *   func_020260F4 0x020260F4 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   func_021EF5E8 0x021EF5E8 thumb
 *   func_021EB988 0x021EB988 thumb
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_021E9D2C 0x021E9D2C thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021EE3E4 0x021EE3E4 thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_021EF57C 0x021EF57C thumb
 *   func_021ED6E4 0x021ED6E4 thumb
 *   func_021EBA5C 0x021EBA5C thumb
 *   func_021DD14C 0x021DD14C thumb
 *   func_021EF670 0x021EF670 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E0190 0x021E0190 thumb
 *   func_021EE57C 0x021EE57C thumb
 *   func_021E9DF8 0x021E9DF8 thumb
 *   func_021E9D98 0x021E9D98 thumb
 *   func_021E8F50 0x021E8F50 thumb
 *   func_021DF0BC 0x021DF0BC thumb
 *   func_021E9C94 0x021E9C94 thumb
 *   func_021E9CE0 0x021E9CE0 thumb
 *   func_021E949C 0x021E949C thumb
 *   func_021E954C 0x021E954C thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_021EEF74 0x021EEF74 thumb
 *   func_021EAA3C 0x021EAA3C thumb
 *   func_021E8FE0 0x021E8FE0 thumb
 *   func_021E8FD0 0x021E8FD0 thumb
 *   func_021E9E7C 0x021E9E7C thumb
 *   d_021EF9B4 0x021EF9B4 data a1
 */

typedef unsigned int u32;

typedef struct {
    unsigned char pad0[2];
    unsigned char pad2[0x26];
    unsigned short h28;
} Top;

typedef struct {
    Top *top;
    unsigned char pad4[0x13 - 4];
    unsigned char b13;
    unsigned char b14;
    unsigned char pad15;
    unsigned char b16;
    unsigned char b17;
    unsigned char pad18[3];
    unsigned char b1B;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char pad1D[0x24 - 0x1D];
    int x24;
    int x28;
    char *work;
} Obj;

struct WinMgr;
extern u32 KEY_GetTrg(void);
extern int func_021EA9F4(Obj *p, int v);
extern unsigned func_021EF170(void);
typedef unsigned char  u8;
struct Sound;
struct Struct_02025CD0;
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int func_021EF5E8(struct WinMgr *mgr);
extern void func_021EB988(Obj *p, const void *e, unsigned n);
extern void func_021DEFEC(char *p, int b);
extern int func_021E9D2C(Obj *p, int i);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE3E4(char **p, unsigned idx);
extern void func_021DF040(char *p);
extern void func_021EF57C(struct WinMgr *mgr);
extern void func_021ED6E4(char **p, int v);
extern void func_021EBA5C(char *w, int v);
extern void func_021DD14C(char *p);
extern void func_021EF670(char *w);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E0190(char *p);
extern unsigned func_021EE57C(char *p);
extern int func_021E9DF8(Obj *p, int i);
extern int func_021E9D98(Obj *p, int i);
extern int func_021E8F50(char *p, int v);
extern void func_021DF0BC(unsigned char *p);
extern int func_021E9C94(char *p, int a, int n);
extern int func_021E9CE0(char *p, int a, int n);
extern int func_021E949C(char *p, int a, int b);
extern int func_021E954C(Obj *p, int id, int lo, int arg);
extern u8 func_020260E0(struct Sound *obj);
extern void func_021EEF74(char *w, int k, int v);
extern int func_021EAA3C(Obj *p, int v);
extern int func_021E8FE0(char *p, int v);
extern int func_021E8FD0(char *p, int a);
extern int func_021E9E7C(Obj *p, int i, int v);
extern const unsigned char d_021EF9B4[];

#define OBJ(p) (*(void **)((p)->work + 0x70))
#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))

int func_021E4F60(Obj *p)
{
    unsigned r;
    r = func_021EF170();
    if (r != -1) {
        func_020260F4(OBJ(p), 0);
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x666);
            TOUCHPANEL_GetPointTrg((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
            if (func_021EF5E8(MGR(p)) == 0)
                func_021EB988(p, d_021EF9B4, 5);
            func_021DEFEC((char *)p, r);
            return func_021E9DF8(p, r);
        }
        func_020260E4(OBJ(p), r);
        func_021EE3E4((char **)p, r);
        func_021DF040((char *)p);
        if (func_021EF5E8(MGR(p)) == 1) {
            func_021EF57C(MGR(p));
            func_021ED6E4((char **)p, 0);
            func_021EBA5C(p->work, 0x18);
            func_021DD14C((char *)p);
            return func_021E8FC0((char *)p, (int)func_021E0190, 0x2C);
        }
        return 0x2C;
    }
    r = func_021EE57C((char *)p);
    switch (r) {
    case 0x1E:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        func_021DF040((char *)p);
        return func_021E8F50((char *)p, 0x5D);
    case 0x1F:
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_021DF0BC((unsigned char *)p);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        return func_021E9C94((char *)p, 0, 0x2C);
    case 0x20:
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_021DF0BC((unsigned char *)p);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        return func_021E9CE0((char *)p, 0, 0x2C);
    case 0x21:
        GFL_USE_PlaySeDefaultVolume(0x556);
        p->top->h28 = 1;
        return func_021E954C(p, 7, 8, 0x10);
    case 0x22:
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->top->h28 = 0;
        return func_021E954C(p, 6, 9, 0x68);
    case 0x23:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return func_021E949C((char *)p, 1, func_021E8F50((char *)p, 0x2E));
    case 0x24:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        p->b17 = p->b14;
        p->x24 = 0x24;
        return func_021E949C((char *)p, 2, 0x4F);
    case 0x25:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return func_021E949C((char *)p, 3, func_021E8F50((char *)p, 0x55));
    case 0x26:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x59));
    case 0x27: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = p->b16;
        func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), k);
        return func_021E949C((char *)p, 5, 0x2D);
    }
    case -6:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            func_021DF0BC((unsigned char *)p);
            return func_021E9C94((char *)p, 0, 0x2C);
        }
        break;
    case -5:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            func_021DF0BC((unsigned char *)p);
            return func_021E9CE0((char *)p, 0, 0x2C);
        }
        break;
    case -3: {
        unsigned char v = func_020260E0(OBJ(p));
        if (v < 0x1E)
            func_021DEFEC((char *)p, v);
        else if (v != 0x23 && v != 0x24 && v != 0x25 && v != 0x26 && v != 0x27)
            func_021DF040((char *)p);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x2C));
    }
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (func_021EF5E8(MGR(p)) == 1) {
            unsigned char k = p->b16;
            func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), k);
            return func_021E949C((char *)p, 5, 0x2D);
        }
        p->top->h28 = 0;
        return func_021E954C(p, 6, 9, 0x68);
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            func_021EB988(p, d_021EF9B4, 5);
            func_021DEFEC((char *)p, r);
            func_021EEF74(p->work, 0x23, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), 0x23);
            return func_021E9E7C(p, r, 0x2C);
        }
        break;
    }
    return 0x2C;
}
