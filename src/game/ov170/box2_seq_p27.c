/*
 * file:     box2_seq_p27.c
 * unit:     yes
 * function: func_021EA39C, func_021EA458, func_021EA4DC
 * address:  0x021EA39C
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
 *   func_021ED6E4 0x021ED6E4 thumb
 *   func_021EC548 0x021EC548 thumb
 *   func_021EA728 0x021EA728 thumb
 *   func_021E8FE0 0x021E8FE0 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E0FD8 0x021E0FD8 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021E1324 0x021E1324 thumb
 *   func_021ED198 0x021ED198 thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_021E152C 0x021E152C thumb
 */
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
} Obj_021EA39C;

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef struct {
    Top *top;
    unsigned char pad4[0x13 - 4];
    unsigned char b13;
    unsigned char b14;
    unsigned char pad15;
    unsigned char b16;
    unsigned char b17;
    unsigned char b18;
    unsigned char pad19[2];
    unsigned char b1B;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char pad1D[0x24 - 0x1D];
    int x24;
    int x28;
    char *work;
} Obj_021EA458;

typedef struct {
    unsigned char pad0[0x2C];
    char *work;
} Obj_021EA4DC;

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
extern void func_021EA728(void *p);
extern void func_021EA878(Obj_021EA39C *p, int v);
extern void func_021DEFEC(char *p, int b);
extern u8 func_020260E0(struct Sound *obj);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EEF74(char *w, int k, int v);
extern int func_021E0ABC(unsigned char *p);
extern int func_021E0FD8(unsigned char *p);
extern void func_020061E4(unsigned se);
extern int func_021E0A40(char *p);
extern int func_021E1324(char *p);
extern void func_021ED198(char *w, int i, int v);
extern void func_021DF040(char *p);
extern int func_021E152C(unsigned char *p);
int func_021EA39C(Obj_021EA39C *p, unsigned i);
int func_021EA458(Obj_021EA458 *p, unsigned i);
int func_021EA4DC(Obj_021EA4DC *p);


int func_021EA39C(Obj_021EA39C *p, unsigned i)
{
    short t[2];
    p->b16 = i;
    p->b17 = i < 0x1E ? p->b14 : 0xFF;
    CNT(p) = func_021DD25C((void ***)p, p->b16, p->b14, 6, 0);
    if (CNT(p) == 0) {
        func_020260E4(OBJ(p), p->b16);
        return 0x40;
    }
    func_020061E4(0x666);
    func_021EC000(p->work, 10, 0);
    func_021ED164(p->work, p->b16, 2);
    func_021ED094(p->work, CNT(p));
    func_021ED1C8(p->work);
    func_021EE038((char *)p, 2, 1, 1);
    func_021EC548(p->b16, &t[1], &t[0], 2);
    *(int *)(p->work + 0xA180) = t[1] + 8;
    *(int *)(p->work + 0xA184) = t[0] + 8;
    func_021EA728(p);
    return func_021E8FC0((char *)p, (int)func_021E0FD8, 0x42);
}


int func_021EA458(Obj_021EA458 *p, unsigned i)
{
    p->b16 = i;
    *(unsigned short *)(p->work + 0xA16E) = i;
    p->b17 = i < 0x1E ? p->b14 : 0xFF;
    CNT(p) = func_021DD25C((void ***)p, p->b16, p->b14, 6, 0);
    if (CNT(p) == 0)
        return 0x40;
    p->b18 = 1;
    func_021EC000(p->work, 10, 0);
    func_021ED198(p->work, p->b16, 2);
    func_021ED094(p->work, CNT(p));
    func_021EE038((char *)p, 2, 1, 1);
    return func_021E8FC0((char *)p, (int)func_021E1324, 0x40);
}


int func_021EA4DC(Obj_021EA4DC *p)
{
    unsigned char v = func_020260E0(OBJ(p));
    if (v < 0x24)
        func_021DEFEC((char *)p, v);
    else
        func_021DF040((char *)p);
    func_021EA728(p);
    return func_021E8FC0((char *)p, (int)func_021E152C, 0x43);
}
