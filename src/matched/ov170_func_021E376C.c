/*
 * function: func_021E376C
 * address:  0x021E376C
 * packet:   pkt_ov170_021E376C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sibling of src/matched/ov170_func_021E2650.c.  The image computes r + 0x1E
 * separately for func_021DEFEC and for the call after it; the (int) cast on
 * the first keeps the two expressions apart so they are not CSEd.
 *
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_021EA9F4 0x021EA9F4 thumb
 *   func_021EF194 0x021EF194 thumb
 *   func_020260F4 0x020260F4 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_02035D20 0x02035D20 arm
 *   func_021EF5E8 0x021EF5E8 thumb
 *   func_021EB988 0x021EB988 thumb
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_021E9EC0 0x021E9EC0 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021EE3E4 0x021EE3E4 thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_021EF57C 0x021EF57C thumb
 *   func_021ED6E4 0x021ED6E4 thumb
 *   func_021EBA5C 0x021EBA5C thumb
 *   func_021DD14C 0x021DD14C thumb
 *   func_021EF68C 0x021EF68C thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E0190 0x021E0190 thumb
 *   func_021EE8A8 0x021EE8A8 thumb
 *   func_021E8F50 0x021E8F50 thumb
 *   func_021E949C 0x021E949C thumb
 *   func_021E954C 0x021E954C thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_021EEF74 0x021EEF74 thumb
 *   func_021EAA3C 0x021EAA3C thumb
 *   func_021E8FE0 0x021E8FE0 thumb
 *   func_021E8FD0 0x021E8FD0 thumb
 *   func_021EA020 0x021EA020 thumb
 *   d_021EFA10 0x021EFA10 data a1
 */

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

extern unsigned func_020362DC(void);
extern int func_021EA9F4(Obj *p, int v);
extern unsigned func_021EF194(void);
extern void func_020260F4(void *obj, int state);
extern unsigned func_021DD25C(Obj *p, unsigned short a, int box, unsigned id, unsigned v);
extern void func_020061E4(unsigned se);
extern int func_02035D20(void *x, void *y);
extern int func_021EF5E8(int p);
extern void func_021EB988(Obj *p, const void *e, unsigned n);
extern void func_021DEFEC(Obj *p, int b);
extern int func_021E9EC0(Obj *p, int i);
extern void func_020260E4(void *obj, unsigned char sel);
extern void func_021EE3E4(Obj *p, unsigned idx);
extern void func_021DF040(Obj *p);
extern void func_021EF57C(int mgr);
extern void func_021ED6E4(Obj *p, int v);
extern void func_021EBA5C(char *w, int v);
extern void func_021DD14C(Obj *p);
extern void func_021EF68C(char *w);
extern int func_021E8FC0(Obj *p, int (*cb)(Obj *), int n);
extern int func_021E0190(Obj *p);
extern unsigned func_021EE8A8(Obj *p);
extern int func_021E8F50(Obj *p, int v);
extern int func_021E949C(Obj *p, int a, int b);
extern int func_021E954C(Obj *p, int id, int lo, int arg);
extern unsigned char func_020260E0(void *obj);
extern void func_021EEF74(char *w, int k, int v);
extern int func_021EAA3C(Obj *p, int v);
extern int func_021E8FE0(Obj *p, int v);
extern int func_021E8FD0(Obj *p, int a);
extern int func_021EA020(Obj *p, int i, int v);
extern const unsigned char d_021EFA10[];

#define OBJ(p) (*(void **)((p)->work + 0x70))
#define MGR(p) (*(int *)((p)->work + 0x74))

int func_021E376C(Obj *p)
{
    unsigned r;
    if (func_020362DC() & 4) {
        p->b1B = 1;
        return func_021EA9F4(p, 0x1F);
    }
    r = func_021EF194();
    if (r != -1) {
        func_020260F4(OBJ(p), 0);
        if (func_021DD25C(p, r + 0x1E, p->b14, 0xA9, 0)) {
            func_020061E4(0x666);
            func_02035D20(p->work + 0xA180, p->work + 0xA184);
            if (func_021EF5E8(MGR(p)) == 0)
                func_021EB988(p, d_021EFA10, 6);
            func_021DEFEC(p, (int)r + 0x1E);
            return func_021E9EC0(p, r + 0x1E);
        }
        func_020260E4(OBJ(p), r);
        func_021EE3E4(p, r);
        func_021DF040(p);
        if (func_021EF5E8(MGR(p)) == 1) {
            func_021EF57C(MGR(p));
            func_021ED6E4(p, 0);
            func_021EBA5C(p->work, 0x18);
            func_021DD14C(p);
            func_021EF68C(p->work);
            return func_021E8FC0(p, func_021E0190, 0x1B);
        }
        return 0x1B;
    }
    r = func_021EE8A8(p);
    switch (r) {
    case 6:
        func_020061E4(0x54C);
        return func_021E949C(p, 0xA, func_021E8F50(p, 0x1C));
    case 7:
        func_020061E4(0x556);
        p->top->h28 = 1;
        return func_021E954C(p, 7, 8, 0x10);
    case 8:
        func_020061E4(0x551);
        return func_021E954C(p, 6, 9, func_021E8F50(p, 0x1C));
    case 9:
        func_020061E4(0x54C);
        p->b1B = 1;
        p->lo = 0;
        return func_021E949C(p, 0, func_021E8F50(p, 0x1F));
    case 10:
        func_020061E4(0x54C);
        p->b17 = p->b14;
        p->b13 = 1;
        return func_021E949C(p, 1, 0x4F);
    case 11:
        func_020061E4(0x54C);
        p->b13 = 1;
        return func_021E949C(p, 2, func_021E8F50(p, 0x50));
    case 12:
        func_020061E4(0x54C);
        return func_021E949C(p, 3, func_021E8F50(p, 0x55));
    case 13:
        func_020061E4(0x54C);
        return func_021E949C(p, 4, func_021E8F50(p, 0x59));
    case 14: {
        unsigned char k;
        func_020061E4(0x551);
        k = p->b16 - 0x1E;
        func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), k);
        return func_021E949C(p, 5, 0x1D);
    }
    case 15:
        p->b1B = 1;
        return func_021EAA3C(p, 0x1F);
    case -4:
        func_020061E4(0x548);
        break;
    case -3: {
        unsigned char v = func_020260E0(OBJ(p));
        if (v < 6)
            func_021DEFEC(p, v + 0x1E);
        else if (v == 6)
            func_021DF040(p);
        func_020061E4(0x548);
        return func_021E8FD0(p, func_021E8FE0(p, 0x1B));
    }
    case -2:
        func_020061E4(0x551);
        if (func_021EF5E8(MGR(p)) == 1) {
            unsigned char k = p->b16 - 0x1E;
            func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), k);
            return func_021E949C(p, 5, 0x1D);
        }
        return func_021E954C(p, 6, 9, func_021E8F50(p, 0x1C));
    case -1:
    case -5:
    case -6:
    case -7:
    case -8:
        break;
    default:
        if (func_021DD25C(p, r + 0x1E, p->b14, 0xA9, 0)) {
            func_020061E4(0x54C);
            func_021EB988(p, d_021EFA10, 6);
            func_021DEFEC(p, (int)r + 0x1E);
            func_021EEF74(p->work, 9, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), 9);
            return func_021EA020(p, r + 0x1E, 0x1B);
        }
        break;
    }
    return 0x1B;
}
