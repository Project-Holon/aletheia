/*
 * file:     box2_seq_p28.c
 * unit:     yes
 * function: func_021EA514, func_021EA598
 * address:  0x021EA514
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021EC0B0 0x021EC0B0 thumb
 *   func_021EC08C 0x021EC08C thumb
 *   func_021ED6E4 0x021ED6E4 thumb
 *   func_021EA4DC 0x021EA4DC thumb
 *   func_021DDE80 0x021DDE80 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E1458 0x021E1458 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_021EF508 0x021EF508 thumb
 *   func_021EBA5C 0x021EBA5C thumb
 *   func_021DD14C 0x021DD14C thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021ED164 0x021ED164 thumb
 *   func_021ED094 0x021ED094 thumb
 *   func_021ED1C8 0x021ED1C8 thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_021EC01C 0x021EC01C thumb
 *   func_021EC548 0x021EC548 thumb
 *   func_021EA728 0x021EA728 thumb
 *   func_021E8FE0 0x021E8FE0 thumb
 *   func_021E1628 0x021E1628 thumb
 */
#define SEL(p) (*(unsigned char *)((p)->work + 0xA17E))
#define OBJ(p) (*(void **)((p)->work + 0x70))
#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))
#define CNT(p) (*(unsigned short *)((p)->work + 0xA16C))
struct WinMgr;
struct Sound;
typedef struct {
    unsigned char pad0[0x16];
    unsigned char b16;
    unsigned char pad17;
    unsigned char b18;
    unsigned char pad19[0x2C - 0x19];
    char *work;
} Obj_021EA514;

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
} Obj_021EA598;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
extern void func_021EC08C(char *p, int i, int a, int b, unsigned short c);
extern void func_021ED6E4(char **p, int v);
extern int func_021EA4DC(Obj_021EA514 *p);
extern int func_021DDE80(unsigned char *p, unsigned a, unsigned b);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E1458(char *p);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void func_021EBA5C(char *w, int v);
extern void func_021DD14C(char *p);
extern void func_021EC000(char *p, int i, int v);
extern void func_021ED164(char *w, int i, int v);
extern void func_021ED094(char *w, unsigned item);
extern void func_021ED1C8(char *w);
extern void func_021EE038(char *p, int a, int b, int c);
extern u32 func_021EC01C(char *p, int i);
extern void func_021EC548(unsigned i, short *x, short *y, int mode);
extern int func_021E8FE0(char *p, int v);
extern void func_021EF508(struct WinMgr *mgr);
extern void func_021EF534(struct WinMgr *mgr);
extern void func_021EA728(void *p);
extern void func_021EA878(Obj_021EA598 *p, int v);
extern void func_021DEFEC(char *p, int b);
extern u8 func_020260E0(struct Sound *obj);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EEF74(char *w, int k, int v);
extern int func_021E0ABC(unsigned char *p);
extern int func_021E1628(unsigned char *p);
extern int func_021E0A40(char *p);
int func_021EA514(Obj_021EA514 *p, unsigned i);
int func_021EA598(Obj_021EA598 *p, int i);


int func_021EA514(Obj_021EA514 *p, unsigned i)
{
    short t[2];
    SEL(p) = i;
    p->b18 = 0;
    func_021EC0B0(p->work, 4, &t[1], &t[0], 0);
    func_021EC08C(p->work, 10, (short)t[1], (short)(t[0] + 8), (short)0);
    func_021ED6E4((char **)p, 0);
    if (SEL(p) == 0xFF)
        return func_021EA4DC(p);
    if (func_021DDE80((unsigned char *)p, p->b16, i) == 0)
        return func_021EA4DC(p);
    return func_021E8FC0((char *)p, (int)func_021E1458, 0x45);
}


int func_021EA598(Obj_021EA598 *p, int i)
{
    short t[2];
    p->b16 = i;
    p->b17 = 0xFF;
    CNT(p) = func_021DD25C((void ***)p, p->b16, p->b14, 6, 0);
    func_021EF508(MGR(p));
    func_021EBA5C(p->work, 0x18);
    func_021DD14C((char *)p);
    if (CNT(p) != 0) {
        func_021EC000(p->work, 10, 0);
        func_021ED164(p->work, p->b16, 1);
        func_021ED094(p->work, CNT(p));
        func_021ED1C8(p->work);
        func_021EE038((char *)p, 2, 2, 1);
    } else if (func_021EC01C(p->work, 10) == 1) {
        func_021EC000(p->work, 10, 0);
        func_021ED6E4((char **)p, 0);
    }
    func_021EC548(p->b16, &t[1], &t[0], 1);
    *(int *)(p->work + 0xA180) = t[1] + 8;
    *(int *)(p->work + 0xA184) = t[0] + 8;
    func_021EA728(p);
    return func_021E8FC0((char *)p, (int)func_021E1628, 0x48);
}
