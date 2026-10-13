/*
 * function: func_021E65E4
 * address:  0x021E65E4
 * packet:   pkt_ov170_021E65E4
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sibling of src/matched/ov170_func_021E3E84.c.
 *
 * symbols:
 *   func_021E8F50 0x021E8F50 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   func_021DD238 0x021DD238 thumb
 *   func_021EF1A4 0x021EF1A4 thumb
 *   func_020260F4 0x020260F4 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021EA39C 0x021EA39C thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021EF170 0x021EF170 thumb
 *   func_021EE96C 0x021EE96C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021EE3E4 0x021EE3E4 thumb
 *   func_021DF0BC 0x021DF0BC thumb
 *   func_021ECC1C 0x021ECC1C thumb
 *   func_021E9C94 0x021E9C94 thumb
 *   func_021E9CE0 0x021E9CE0 thumb
 *   func_021E954C 0x021E954C thumb
 *   func_021EA514 0x021EA514 thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_021E8FE0 0x021E8FE0 thumb
 *   func_021E8FD0 0x021E8FD0 thumb
 *   func_021EA458 0x021EA458 thumb
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

extern int func_021E8F50(char *p, int v);
extern u32 KEY_GetTrg(void);
extern void func_021DD238(char *p);
extern unsigned func_021EF1A4(void);
typedef unsigned char  u8;
struct Sound;
struct Struct_02025CD0;
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void func_021DEFEC(char *p, int b);
extern void func_021EC000(char *p, int i, int v);
extern int func_021EA39C(Obj *p, unsigned i);
extern void func_021DF040(char *p);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern unsigned func_021EF170(void);
extern unsigned func_021EE96C(char *p);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern void func_021EE3E4(char **p, unsigned idx);
extern void func_021DF0BC(unsigned char *p);
extern void func_021ECC1C(unsigned char *p);
extern int func_021E9C94(char *p, int a, int n);
extern int func_021E9CE0(char *p, int a, int n);
extern int func_021E954C(Obj *p, int id, int lo, int arg);
extern int func_021EA514(Obj *p, unsigned i);
extern u8 func_020260E0(struct Sound *obj);
extern int func_021E8FE0(char *p, int v);
extern int func_021E8FD0(char *p, int a);
extern int func_021EA458(Obj *p, unsigned i);

#define OBJ(p) (*(void **)((p)->work + 0x70))

int func_021E65E4(Obj *p)
{
    unsigned r;
    if (p->hi == 1) {
        p->lo = 0;
        p->hi = 0;
        return func_021E8F50((char *)p, 0x41);
    }
    if ((KEY_GetTrg() & 4) && p->lo != 0 && p->b18 == 0) {
        func_021DD238((char *)p);
        p->lo = 0;
        return func_021E8F50((char *)p, 0x41);
    }
    if (p->b18 == 0) {
        r = func_021EF1A4();
        if (r != -1) {
            func_020260F4(OBJ(p), 0);
            if (func_021DD25C((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
                func_021DEFEC((char *)p, (int)r + 0x1E);
                func_021EC000(p->work, 4, 0);
                return func_021EA39C(p, r + 0x1E);
            }
            func_021DF040((char *)p);
            func_020260E4(OBJ(p), r + 0x1E);
            return 0x40;
        }
        r = func_021EF170();
        if (r != -1) {
            func_020260F4(OBJ(p), 0);
            if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
                func_021DEFEC((char *)p, r);
                func_021EC000(p->work, 4, 0);
                return func_021EA39C(p, r);
            }
            func_021DF040((char *)p);
            func_020260E4(OBJ(p), r);
            return 0x40;
        }
    }
    r = func_021EE96C((char *)p);
    switch (r) {
    case 0x24:
        if (p->b18 != 0)
            break;
        GFL_USE_PlaySeDefaultVolume(0x54C);
        func_021DF040((char *)p);
        return func_021E8F50((char *)p, 0x5D);
    case 0x25:
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_020260E4(OBJ(p), 0x24);
        func_021EE3E4((char **)p, 0x24);
        if (p->b18 == 0)
            func_021DF0BC((unsigned char *)p);
        else
            func_021ECC1C((unsigned char *)p);
        return func_021E9C94((char *)p, 0, 0x40);
    case 0x26:
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_020260E4(OBJ(p), 0x24);
        func_021EE3E4((char **)p, 0x24);
        if (p->b18 == 0)
            func_021DF0BC((unsigned char *)p);
        else
            func_021ECC1C((unsigned char *)p);
        return func_021E9CE0((char *)p, 0, 0x40);
    case 0x29:
        if (p->b18 != 0)
            break;
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->lo = 0;
        return func_021E954C(p, 6, 9, func_021E8F50((char *)p, 0x41));
    case 0x2A:
        if (p->lo == 0 || p->b18 != 0)
            break;
        p->lo = 0;
        return func_021E8F50((char *)p, 0x41);
    case -2:
        if (p->b18 == 1)
            return func_021EA514(p, 0xFF);
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->lo = 0;
        return func_021E954C(p, 6, 9, func_021E8F50((char *)p, 0x41));
    case -6:
        if (func_020260E0(OBJ(p)) != 0x24)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        return func_021E9C94((char *)p, 0, 0x40);
    case -5:
        if (func_020260E0(OBJ(p)) != 0x24)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        return func_021E9CE0((char *)p, 0, 0x40);
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -3:
        GFL_USE_PlaySeDefaultVolume(0x548);
        if (p->b18 == 0) {
            unsigned char v = func_020260E0(OBJ(p));
            if (v < 0x24)
                func_021DEFEC((char *)p, v);
            else
                func_021DF040((char *)p);
        }
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x40));
    case -1:
    case -7:
    case -8:
    case 0x27:
    case 0x28:
        break;
    default:
        if (p->b18 == 1)
            return func_021EA514(p, r);
        return func_021EA458(p, r);
    }
    return 0x40;
}
