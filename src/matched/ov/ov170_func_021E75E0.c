/*
 * function: func_021E75E0
 * address:  0x021E75E0
 * packet:   pkt_ov170_021E75E0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sibling of src/matched/ov170_func_021E5E68.c (the switch tail without the preamble).
 *
 * symbols:
 *   func_021DD25C 0x021DD25C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021EF5E8 0x021EF5E8 thumb
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_021EEF74 0x021EEF74 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021EE3E4 0x021EE3E4 thumb
 *   func_021E8F50 0x021E8F50 thumb
 *   func_021DF0BC 0x021DF0BC thumb
 *   func_021E9C94 0x021E9C94 thumb
 *   func_021E9CE0 0x021E9CE0 thumb
 *   func_021E949C 0x021E949C thumb
 *   func_021E954C 0x021E954C thumb
 *   func_021E8FE0 0x021E8FE0 thumb
 *   func_021E8FD0 0x021E8FD0 thumb
 *   func_021EEEA4 0x021EEEA4 thumb
 *   func_021ED588 0x021ED588 thumb
 *   func_021E78F4 0x021E78F4 thumb
 *   func_021E070C 0x021E070C thumb
 *   func_021E0190 0x021E0190 thumb
 *   func_021EB988 0x021EB988 thumb
 *   func_021EF57C 0x021EF57C thumb
 *   func_021ED6E4 0x021ED6E4 thumb
 *   func_021EBA5C 0x021EBA5C thumb
 *   func_021DD14C 0x021DD14C thumb
 *   func_021EF534 0x021EF534 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   d_021EF8EC 0x021EF8EC data a1
 */

typedef struct {
    unsigned char pad0[2];
    unsigned char pad2[0x26];
    unsigned short h28;
    unsigned char b2A;
    unsigned char b2B;
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
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern int func_021EF5E8(struct WinMgr *mgr);
extern void func_021DEFEC(char *p, int b);
typedef unsigned char  u8;
struct Sound;
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE3E4(char **p, unsigned idx);
extern void func_021DF040(char *p);
extern int func_021E8F50(char *p, int v);
extern void func_021DF0BC(unsigned char *p);
extern int func_021E9C94(char *p, int a, int n);
extern int func_021E9CE0(char *p, int a, int n);
extern int func_021E949C(char *p, int a, int b);
extern int func_021E954C(Obj *p, int id, int lo, int arg);
extern u8 func_020260E0(struct Sound *obj);
extern void func_021EEF74(char *w, int k, int v);
extern int func_021E8FE0(char *p, int v);
extern int func_021E8FD0(char *p, int a);

#define OBJ(p) (*(void **)((p)->work + 0x70))
#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))

extern unsigned func_021EEEA4(char *p);
extern void func_021ED588(char *p);
extern int func_021E78F4(char *p);
extern int func_021E070C(char *p);
extern int func_021E0190(char *p);
extern void func_021EB988(Obj *p, const void *e, unsigned n);
extern const unsigned char d_021EF8EC[];
extern void func_021EF57C(struct WinMgr *mgr);
extern void func_021ED6E4(char **p, int v);
extern void func_021EBA5C(char *w, int v);
extern void func_021DD14C(char *p);
extern void func_021EF534(struct WinMgr *mgr);
extern int func_021E8FC0(char *p, int a, int b);

int func_021E75E0(Obj *p)
{
    unsigned r = func_021EEEA4((char *)p);
    switch (r) {
    case 0x1E:
        func_021DF0BC((unsigned char *)p);
        break;
    case 0x1F:
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_021DF0BC((unsigned char *)p);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        return func_021E9C94((char *)p, 0, 0x4B);
    case 0x20:
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_021DF0BC((unsigned char *)p);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        return func_021E9CE0((char *)p, 0, 0x4B);
    case 0x21:
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->top->h28 = 0;
        p->top->b2A = 0xFF;
        p->top->b2B = 0xFF;
        return func_021E954C(p, 6, 9, 0x68);
    case 0x22:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x4D));
    case 0x23: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = p->b16;
        func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), k);
        return func_021E949C((char *)p, 5, 0x4E);
    }
    case -6:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            func_021DF0BC((unsigned char *)p);
            return func_021E9C94((char *)p, 0, 0x4B);
        }
        break;
    case -5:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            func_021DF0BC((unsigned char *)p);
            return func_021E9CE0((char *)p, 0, 0x4B);
        }
        break;
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -3: {
        unsigned char v = func_020260E0(OBJ(p));
        if (v < 0x1E)
            func_021DEFEC((char *)p, v);
        else if (v != 0x22 && v != 0x23)
            func_021DF040((char *)p);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x4B));
    }
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (func_021EF5E8(MGR(p)) == 1) {
            unsigned char k = p->b16;
            func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), k);
            return func_021E949C((char *)p, 5, 0x4E);
        }
        p->top->h28 = 0;
        p->top->b2A = 0xFF;
        p->top->b2B = 0xFF;
        return func_021E954C(p, 6, 9, 0x68);
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            p->b16 = r;
            func_021EB988(p, d_021EF8EC, 2);
            func_021DEFEC((char *)p, r);
            func_021ED588((char *)p);
            func_020260E4(OBJ(p), 0x22);
            if (func_021EF5E8(MGR(p)) == 1)
                return func_021E78F4((char *)p);
            func_021EEF74(p->work, 0x22, r);
            func_021EF534(MGR(p));
            return func_021E8FC0((char *)p, (int)func_021E070C, func_021E8FE0((char *)p, 0x4C));
        }
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_021DEFEC((char *)p, r);
        if (func_021EF5E8(MGR(p)) == 1) {
            func_021EF57C(MGR(p));
            func_021ED6E4((char **)p, 0);
            func_021EBA5C(p->work, 0x18);
            func_021DD14C((char *)p);
            return func_021E8FC0((char *)p, (int)func_021E0190, 0x4B);
        }
        break;
    }
    return 0x4B;
}
