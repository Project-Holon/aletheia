/*
 * file:     box2_seq_p29.c
 * unit:     yes
 * function: func_021EA66C, func_021EA728, func_021EA750
 * address:  0x021EA66C
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
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_021EA878 0x021EA878 thumb
 *   func_021EF534 0x021EF534 thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021ED164 0x021ED164 thumb
 *   func_021ED094 0x021ED094 thumb
 *   func_021ED1C8 0x021ED1C8 thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_021EEF74 0x021EEF74 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021E8FE0 0x021E8FE0 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E0A40 0x021E0A40 thumb
 *   func_020307B0  0x020307B0  arm  arm9
 */
#include "../../matched/include/Obj18488.h"
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj18489.h"

#define OBJ(p) (*(void **)((p)->work + 0x70))
#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))
#define CNT(p) (*(unsigned short *)((p)->work + 0xA16C))
struct WinMgr;
struct Sound;
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

typedef unsigned char  u8;

typedef unsigned int   u32;

extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void func_021EBA5C(char *w, int v);
extern void func_021DD14C(char *p);
extern void func_021EC000(char *p, int i, int v);
extern void func_021ED164(char *w, int i, int v);
extern void func_021ED094(char *w, unsigned item);
extern void func_021ED1C8(char *w);
extern void func_021EE038(char *p, int a, int b, int c);
extern u32 func_021EC01C(char *p, int i);
extern void func_021ED6E4(char **p, int v);
extern void func_021EC548(unsigned i, short *x, short *y, int mode);
extern int func_021E8FE0(char *p, int v);
extern int func_021E8FC0(char *p, int a, int b);
extern void func_021EF508(struct WinMgr *mgr);
extern void func_021EF534(struct WinMgr *mgr);
extern void func_021EA878(Obj *p, int v);
extern void func_021DEFEC(char *p, int b);
extern u8 func_020260E0(struct Sound *obj);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EEF74(char *w, int k, int v);
extern int func_021E0ABC(unsigned char *p);
extern int func_021E0A40(char *p);
extern void *func_02030734(unsigned int heap, unsigned int size, int clear, const char *site, unsigned short tag);
extern u32 func_020307B0(void *p);
int func_021EA66C(Obj *p, int i);
void func_021EA728(void *p);
void func_021EA750(char *p);


int func_021EA66C(Obj *p, int i)
{
    p->b16 = i;
    p->b17 = p->b14;
    p->work[0xA172] = 1;
    func_021DEFEC((char *)p, p->b16);
    CNT(p) = func_021DD25C((void ***)p, p->b16, p->b14, 6, 0);
    func_021EA878(p, (short)CNT(p));
    func_021EF534(MGR(p));
    if (CNT(p) != 0) {
        func_021EC000(p->work, 10, 0);
        func_021ED164(p->work, p->b16, 1);
        func_021ED094(p->work, CNT(p));
        func_021ED1C8(p->work);
        func_021EEF74(p->work, 9, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), 9);
    } else {
        func_021EEF74(p->work, 10, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), 10);
    }
    return func_021E8FC0((char *)p, (int)func_021E0A40, func_021E8FE0((char *)p, 0x46));
}



/*
 * Sibling of func_021EA1C0 with (0x1c, 0) and the 0x228F buffer.
 */
void func_021EA728(void *p)
{
    int v = (int)func_02030734(0x4c, 0x1c, 0, (const char *)0x021F140C, 0x228F);
    *(int *)(((struct Obj18488 *)p)->f2C + 0x60) = v;
}


/*
 * Tail call func_020307B0 with the word at +0x2c/+0x60.
 */
void func_021EA750(char *p)
{
    func_020307B0(((struct Obj18489 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f60);
}
