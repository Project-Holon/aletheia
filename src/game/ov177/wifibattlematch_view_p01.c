/*
 * file:     wifibattlematch_view_p01.c
 * unit:     yes
 * function: func_021E5440, func_021E54E0, func_021E5534, func_021E5548, func_021E5554, func_021E5568, func_021E55C8, func_021E5600, func_021E5604, func_021E560C, func_021E564C, func_021E5668, func_021E5670, func_021E5678, func_021E567C, func_021E5868, func_021E58A4, func_021E5978, func_021E5980, func_021E5A30, func_021E5ADC, func_021E5C20, func_021E5D40, func_021E5D68, func_021E5EF8, func_021E5F24, func_021E6118, func_021E62A0, func_021E62CC, func_021E64C0, func_021E64C8
 * address:  0x021E5440
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   d_021E8DA0 0x021E8DA0 data a1
 *   d_021E8B2C 0x021E8B2C data a4
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021E8B00 0x021E8B00 data a4
 *   d_021E8B5C 0x021E8B5C data a4
 *   func_020403F4  0x020403F4  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_020419E4  0x020419E4  arm
 *   d_021E8B10      0x021E8B10  data
 *   func_0204A48C   0x0204A48C  arm
 *   func_0204B100   0x0204B100  arm
 *   func_0204B270   0x0204B270  arm
 *   func_020434DC   0x020434DC  arm
 *   func_02043598   0x02043598  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_0204A600  0x0204A600  arm
 *   func_0204A648  0x0204A648  arm
 *   d_021E8DBC 0x021E8DBC data a1
 *   func_02082D44 0x02082D44 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02049658 0x02049658 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02049238 0x02049238 arm
 *   func_02040C14 0x02040C14 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02040618 0x02040618 arm
 *   FX_SinCosTable_  0x020A1B38  data  a2
 *   func_02061CA4    0x02061CA4  arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045738 0x02045738 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021E7CF0 0x021E7CF0 thumb ov177
 *   func_021E6718 0x021E6718 thumb ov177
 *   func_021E72FC 0x021E72FC thumb ov177
 *   func_0204B404 0x0204B404 arm
 *   func_021E7464 0x021E7464 thumb ov177
 *   func_020413B0 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021E74FC  0x021E74FC  thumb ov177
 *   func_021E73B8  0x021E73B8  thumb ov177
 *   func_021E6EFC  0x021E6EFC  thumb ov177
 *   func_021E6940 0x021E6940 thumb ov177
 *   func_021E6F20 0x021E6F20 thumb ov177
 *   func_021E73E4 0x021E73E4 thumb ov177
 *   func_021E7454  0x021E7454  thumb ov177
 *   func_021E7270  0x021E7270  thumb ov177
 *   func_02043B5C 0x02043B5C arm
 *   func_020407E8 0x020407E8 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0201C724 0x0201C724 thumb
 *   func_021E6BE8 0x021E6BE8 thumb ov177
 *   func_021E6E8C   0x021E6E8C  thumb ov177
 */
#include "../../matched/include/Obj24443.h"
#include "../../matched/include/Obj24444.h"
#include "../../matched/include/Obj00133.h"
#include "../../matched/include/Obj05464.h"
#include "../../matched/include/Obj05465.h"

struct DispVram;
struct Node;
struct BgTemplate;
struct DispConfig;
struct Bank;
struct Cfg;
struct MsgBank;
struct WordSet;
struct U16Vec;
struct Descriptor;
struct PrintSys;
struct Rec;
struct StrObj;
struct Obj;
struct Vec2;
struct CharBuf;
struct Actor;
struct PtS;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { unsigned id; unsigned template[8]; unsigned type; unsigned enable; } Entry_021E5568;

typedef struct { u32 id; u32 template[8]; u32 type; u32 enable; } Entry_021E55C8;

typedef struct { int a, b, c, d, e, f; } S5868;

typedef struct { char pad[0x18]; unsigned short out[16], original[16], target[16], phase; } State;

typedef struct { short x, y; } Point;

typedef struct {
    u32 f0; u16 h4, pad6; u32 f8; void *fC; u16 h10, h12;
} Info_021E5440;

typedef struct {
    char pad0[0x188];
    void *f188;
    char pad18c[0x230 - 0x18c];
    u8 c230, c231, c232, c233;
    u32 f234;
    char pad238[0x244 - 0x238];
} Work;

typedef enum 
{
  BG2 = 2,
  BG6 = 6
} Layer;

typedef struct 
{
  short x;
  short y;
} Pt_021E5D68;

typedef struct Work_021E5D68 Work_021E5D68;

typedef struct Info_021E5D68 Info_021E5D68;

typedef struct {short x,y;} Pt_021E5EF8;

typedef struct {short x,y;} Pt_021E62CC;

typedef struct { short x, y; } Pt;

typedef struct {
    char pad0[0x16c];
    void *objs[22];      /* 0x16c */
    char pad1c4[0x200 - 0x1c4];
    unsigned count;      /* 0x200 */
    short baseX[22];     /* 0x204 */
    unsigned char bg;    /* 0x230 */
    char pad231[3];
    unsigned layer;      /* 0x234 */
} Work_021E64C0;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, unsigned, unsigned);
extern void func_0204335C(unsigned);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(unsigned);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern int func_020056A0(void (*)(int, int *), int *, int);
extern void func_02030EAC(struct Node *n);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_0203F8F4(unsigned short);
extern void func_02045088(unsigned short);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, unsigned int heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_02082D44(const void *, void *, u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern u32 func_0204AF28(void *, u32, u32, u16);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02049238(void *);
extern void func_02040C14(u32, u32, u32, u32);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020498F4(void *a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, u16 g);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u16 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u16 heapId);
extern u8 func_02045738(struct Descriptor *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02045C04(struct Rec *rec);
extern void func_0207D63C(void *, int, int, int, int);
extern u32 func_021E7CF0(void *, u16, u16);
extern void func_021E6718(Work *, u32, const Info_021E5440 *, void *, int, void *, void *, void *, int, u16);
extern void func_021E72FC(u8 *, u32, u32, u16);
extern void func_0204B404(void *, const Pt_021E5D68 *, u16);
extern void func_021E7464(char *, char *, u32, void *, u16);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32);
extern void func_021E74FC(char *p);
extern void func_021E73B8(char *p);
extern void func_021E6EFC(unsigned *p);
extern void func_021E6940(Work_021E5D68 *, u32, const Info_021E5D68 *, void *, int, void *, void *, void *, u16);
extern void func_021E6F20(Work_021E5D68 *, void *, void *, u16);
extern void func_021E73E4(char *, unsigned, void *, unsigned);
extern void func_021E7454(int *p);
extern void func_021E7270(char *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32 func_020407E8(u32 layer);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_021E6BE8(Work_021E5D68 *, const Info_021E5D68 *, void *, int, void *, void *, void *, u16);
extern int func_021E6E8C(unsigned char *p, void *mgr);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_020061E4(unsigned);
extern unsigned func_0209C2B0(unsigned, unsigned);
extern void func_02041EE4(u32 index, u32 a, u32 b);
int *func_021E5440(unsigned swap, u16 heap);
void func_021E54E0(char *p);
void func_021E5534(u8 *p);
int func_021E5548(int *p);
void func_021E5554(int a, int *p);
void func_021E5568(void *p, unsigned short heap);
void func_021E55C8(void *p);
void func_021E5600(void *p);
void func_021E5604(int *a0);
void func_021E560C(int *p, int b, int c);
void func_021E564C(int *p);
void func_021E5668(void *p);
void func_021E5670(int *a0);
int func_021E5678(int *p);
u32 *func_021E567C(int unused, int mode, int heap);
void func_021E5868(S5868 *p);
void func_021E58A4(int unused, int mode, unsigned color);
int func_021E5978(int *p, int i);
void func_021E5980(State *p);
void func_021E5A30(u32 slot, u16 *out, const u16 *phase, u32 unused, u8 a, u8 b, u16 c0, u16 c1);
void func_021E5ADC(u32 *p, struct PrintSys *win, u32 str, u32 c2, u32 c1, u16 heap);
Work *func_021E5C20(const Info_021E5440 *info, u32 a1, void *a2, int owner, void *table, int a5, void *a6, void *a7, void *a8, u16 heap);
void func_021E5D40(void *p);
char *func_021E5D68(char *info, u32 a, void *b, void *owner, void *table, int c, void *d, void *e, void *f, void *record, int mode, u16 heap);
void func_021E5EF8(void *p);
void func_021E5F24(char *p, int mode, void *mgr, void *print, int font, u16 a5);
char *func_021E6118(char *info, void *a, void *owner, void *table, int b, void *c, void *d, void *e, void *record, int mode, u16 heap);
void func_021E62A0(void *p);
void func_021E62CC(char *p, int mode, void *mgr, void *print, int font, u32 a5);
int func_021E64C0(unsigned char *p, void *mgr);
int func_021E64C8(Work_021E64C0 *w);
extern const char d_021E8DA0[];
extern const unsigned d_021E8B2C[];
extern const unsigned d_021E8B00[];
extern const Entry_021E5568 d_021E8B5C[];
extern unsigned char d_021E8B10[];
extern const char d_021E8DBC[];
extern const short FX_SinCosTable_[];



int *func_021E5440(unsigned swap, u16 heap)
{
    int *p = func_02030734(heap, 16, 0, d_021E8DA0, 0x1BB);
    func_02082BCC(p, 0, 16);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021E8B2C);
    func_0204363C(swap);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_021E5568(p, heap);
    func_021E560C(p + 1, (int)d_021E8B2C, heap);
    p[3] = func_020056A0(func_021E5554, p, 0);
    return p;
}



/*
 * volatile: display registers 04000050/04001050 cleared; DISPCNT 04000000/04001000 read-modify-write at 021E5506-021E5514.
 */
void func_021E54E0(char *p)
{
    func_02030EAC(((struct Obj24443 *)p)->fC);
    func_021E564C((int *)(p + 4));
    func_021E55C8(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_02082BCC(p, 0, 0x10);
    func_020307B0(p);
}




void func_021E5534(u8 *p)
{
    func_021E5668(p + 4);
    func_021E5600(p);
}




/*
 * Unlabelled ov177 thunk hidden in a word run: tail-calls func_021E5678 with
 * its pointer argument advanced by one word.  Matched to supply the `matched`
 * witness for the pending ov176 caller func_0217AF2C.
 */
int func_021E5548(int *p)
{
    return func_021E5678(p + 1);
}




void func_021E5554(int a, int *p)
{
    func_021E5604(p);
    func_021E5670((int *)((char *)p + 4));
}








void func_021E5568(void *p, unsigned short heap)
{
    unsigned i;
    func_02082BCC(p, 0, 4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)d_021E8B00);
    for (i = 0; i < 8; i++) {
        const Entry_021E5568 *e = &d_021E8B5C[i];
        unsigned id = e->id;
        func_0203FCA0((unsigned char)id, (const struct BgTemplate *)(&e->template), (unsigned char)e->type);
        func_020414AC(id);
        func_02040588(id, e->enable);
    }
}









void func_021E55C8(void *p)
{
    u32 i;
    for (i = 0; i < 8; i++)
        func_020403F4((u8)d_021E8B5C[i].id);
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(p, 0, 4);
}









void func_021E5600(void *p)
{
}









void func_021E5604(int *a0)
{
    func_020419E4();
}









/*
 * Bring up the graphics object: clear four words, submit the table and
 *   latch the 0x80-byte handle.
 */
void func_021E560C(int *p, int b, int c)
{
    func_02082BCC((void *)((int)p), 0, 4);
    func_0204A48C((const struct Cfg *)d_021E8B10, b, c);
    p[0] = (int)func_0204B100(0x80, 0, c);
    func_0204B270((void *)p[0]);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}








void func_021E564C(int *p)
{
    func_0204B1CC((struct Bank *)(((struct Obj24444 *)p)->f0));
    func_0204A5AC();
    func_02082BCC(p, 0, 4);
}








void func_021E5668(void *p)
{
    func_0204A600();
}







void func_021E5670(int *a0)
{
    func_0204A648();
}






/*
 * Unlabelled ov177 leaf: loads the word its argument points at.  Matched as
 * the bottom-up dependency of the ov177 thunk func_021E5548.
 */
int func_021E5678(int *p)
{
    return *p;
}







/*
 * note 2026-10-05 (wP4 S8): EXACT first compile. Twin shape from ov177 021E58A4 (same heap-id mask) and ov172 021BBA94. 0x85 kept in a local (reused as k + 0x9b), 02030734 heap parameter u32 (no halfword truncate before the call).
 */
u32 *func_021E567C(int unused, int mode, int heap)
{
    u32 *w;
    u32 c;
    u32 k;
    void *h;
    void *hd;
    u32 *out;
    u8 *data;
    u32 l, m;
    w = func_02030734(heap, 0x7c, 0, d_021E8DBC, 0x7d);
    func_02082BCC(w, 0, 0x7c);
    k = 0x85;
    c = (heap & 0x7fff) | 0x8000;
    h = func_020490F4(k, (u16)c);
    func_02049B68(h, 0, 0, 0, 0, c);
    func_02049B68(h, 0, 4, 0, 0, c);
    func_02049658(h, 2, 3, 0, 0, 0, c);
    func_02049658(h, 2, 7, 0, 0, 0, c);
    func_021E58A4((int)w, mode, heap);
    w[0] = func_0204ABF0(h, 1, 0, 0, c);
    w[2] = func_0204A6C8(h, 3, 0, 0, c);
    w[4] = func_0204AF28(h, 4, 0xb, c);
    w[1] = func_0204ABF0(h, 1, 1, 0, c);
    w[3] = func_0204A6C8(h, 3, 0, 1, c);
    w[5] = func_0204AF28(h, 4, 0xb, c);
    hd = func_02049F78(h, 0, (u32)&out, heap);
    data = (u8 *)out[3];
    func_02082D44(data, (u8 *)w + 0x38, 0x20);
    k += 0x9b;
    func_02082D44(data + k, (u8 *)w + 0x58, 0x20);
    func_020307B0(hd);
    func_02049238(h);
    l = 0x17;
    m = 5;
    func_02049B40(l, m, 0, 0x1e0, 0x20, c);
    func_02049B40(l, m, 4, 0x1e0, 0x20, c);
    func_02040C14(0, 0, 1, 0);
    func_0201F5BC(0, 1, 0xd, 0, c);
    func_0201F5BC(0, 0xa, 0xe, 0, c);
    func_02040618(2, 0, -256);
    func_02040618(1, 0, -256);
    func_02040618(6, 0, -256);
    func_02040618(m, 0, -256);
    return w;
}





void func_021E5868(S5868 *p)
{
    func_0204ADA4(p->a);
    func_0204A8D4(p->c);
    func_0204AFD8(p->e);
    func_0204ADA4(p->b);
    func_0204A8D4(p->d);
    func_0204AFD8(p->f);
    func_02040DA8(0, 1, 0);
    func_020307B0(p);
}





void func_021E58A4(int unused, int mode, unsigned color)
{
    int h;
    unsigned c = (color & 0x7fff) | 0x8000;
    h = (int)func_020490F4((int)0x85, (unsigned short)c);
    func_020498F4((void *)h, 5, 3, 0, 0, 0, c);
    func_020498F4((void *)h, 6, 7, 0, 0, 0, c);
    switch (mode) {
    case 2:
        func_020498F4((void *)h, 8, 6, 0, 0, 0, c);
        break;
    case 3:
        func_020498F4((void *)h, 10, 2, 0, 0, 0, c);
        break;
    case 0:
    case 1:
        func_020498F4((void *)h, 10, 6, 0, 0, 0, c);
        break;
    }
    func_02040618(2, 0, -256);
    func_02040618(1, 0, -256);
    func_02040618(6, 0, -256);
    func_02040618(5, 0, -256);
    func_02049238((void *)h);
}





int func_021E5978(int *p, int i)
{
    return p[i];
}





/*
 * lever: observed three color arrays; cached phase on wrap, compound increment reload on no-wrap.
 */
void func_021E5980(State *p)
{
    int i;
    unsigned short phase = p->phase;
    if (phase + 0x200 >= 0x10000)
        p->phase = phase - 0xfe00;
    else
        p->phase += 0x200;
    for (i = 0; i < 16; i++) {
        func_021E5A30(15, &p->out[i], &p->phase, 0, 0, i, p->original[i], p->target[i]);
        func_021E5A30(31, &p->out[i], &p->phase, 0, 0, i, p->original[i], p->target[i]);
        func_021E5A30(14, &p->out[i], &p->phase, 0, 2, i, p->original[i], p->target[i]);
    }
}





/*
 * note: 2026-10-02 lane07: DIFF, 172 bytes. Channel unpack/blend scheduling differs (orig reads c0 via add r1,sp,#0x18 before table load, builds 0x1f<<10 mask by reusing the 0x1f register, blend order B,R,G). Tried u8 locals, decl orders, shifted-mask forms.
 * note 2026-10-05: orig packs `(g << 5) | r | (b << 10)` (orrs g5,r then b10); tried that order:
 * the compiler then rebuilds 0x1f from a shifted register and the function shrinks to 156 B (orig 172).
 * The original keeps c0 in r6 and c1 in r1 and builds each mask with its own movs/lsls; no source form
 * found that reproduces this. Still DIFF.
 * 2026-10-05 (wave D9 lane10): DIFF, now 172 bytes (same size as the original), 94 bytes differ
 *   (was 157 with a 164-byte body). New form: c1 channels in u8 locals (b1, r1, g1) as separate
 *   statements, blends written back into the c0 locals in order b, r, g, pack "r | (g << 5) | (b << 10)".
 *   This reproduces every u8 truncation, every mask constant (0x3e<<4, 0x1f, 0x1f<<10, no 0x1f held in
 *   a register), the blend order and out in r7. Residue: register colouring only. Ours keeps c0 in r1
 *   and hoists c1's 0x1f<<10 mask into r6 at the top; the original keeps c0 in r6 (loaded before the
 *   table read) and builds that mask in r6 after c0 dies. Also g0/r0 swap r3/r4 and b0 is r1 (orig r2).
 *   Tried: declaration order of the locals (no change, all propagated), c0 extraction before t (worse,
 *   100), u8 casts inline in the blends (CSE of 0x1f into r7 when all six channels are u8 inline),
 *   a static inline u8 Blend helper (120), U-suffixed masks (no change).
 * 2026-10-05 (wave D9r lane06): DIFF, 172 bytes, 77 bytes differ (was 94). New form: copy c0 into an
 *   `int col` local as the first statement, before t. This puts `add r1,sp,#0x18` at +6 as in the image.
 *   Residue: colouring only. The image loads c0 into r6 at +0x12 (before the table ldrsh) and c1 into r1;
 *   ours loads col into r1 after t, c1 into r2, and hoists c1's 0x1f<<10 mask into r6. g0/r0 also swap
 *   r3/r4. Tried without gain: u16 col (94), u32 col (77), short col (176 B), col reused for c1 (77),
 *   a second int col1 for c1 (137), statement order of the six channel locals (all 94, mwcc rebuilds the
 *   trees per use), g0 or g0+r0 extracted before t with and without col (100/106), static inline Blend
 *   (u16 c0, u16 c1, int t / short t / u16 phase) (94/96), short t (96), pack (g<<5)|r|(b<<10) (109).
 * 2026-10-05 (wave D9r lane33): DIFF, code unchanged (77 bytes differ). Listing reading: the image
 *   colours c0 last (r6, the only free register), so c0 is a short, low-degree value in the image and the
 *   post-RA scheduler then lifts its ldrh to +0x12 and builds c1's 0x7c00 mask in r6 only after c0 dies.
 *   Ours colours c0 (or col) first into r1, leaving r6 free, so the scheduler hoists that mask to the top.
 *   Tried: t through a static inline CalcT(phase) helper (77, same code); blends into three new u8 locals
 *   bb/rr/gg instead of writing back (90); int c0 channel locals with (u8) casts at each assignment (81);
 *   mask-first operand order `0x3e0 & c0` with and without col (94/77, no change).
 *
 * 2026-10-05 (wave D9r lane37): EXACT. Closed with the form of the matched twin ov068 func_021B9D68
 *   (arm9 twin func_0202EA40, blink_palanm.c): f as an s16 local, all six channels as u8 locals extracted
 *   mask-then-shift, the blends as s32 locals with a u8 cast, and the pack (b << 10) | (r | (g << 5)).
 */
void func_021E5A30(u32 slot, u16 *out, const u16 *phase, u32 unused, u8 a, u8 b, u16 c0, u16 c1)
{
    s16 f;
    u8 r0, g0, b0, r1, g1, b1;
    s32 r, g, bl;

    f = (FX_SinCosTable_[((*phase >> 4) << 1) + 1] + 0x1000) / 2;
    r0 = c0 & 0x1f;
    g0 = (c0 & 0x3e0) >> 5;
    b0 = (c0 & 0x7c00) >> 10;
    r1 = c1 & 0x1f;
    g1 = (c1 & 0x3e0) >> 5;
    b1 = (c1 & 0x7c00) >> 10;
    bl = (u8)(b0 + (((b1 - b0) * f) >> 12));
    r = (u8)(r0 + (((r1 - r0) * f) >> 12));
    g = (u8)(g0 + (((g1 - g0) * f) >> 12));
    *out = (u16)((bl << 10) | (r | (g << 5)));
    func_02061CA4((void *)slot, a * 32 + b * 2, (u32)out, 2);
}






/*
 * note 2026-10-05 (final push G6L3): EXACT*. The three running x values are separate locals (x, x1 = x - w, x2 = x1 - w, third draw x2 - w), not one x updated in place; the separate values give each its own live range and the original colours (str r4, p r5, heap-base temp and buf r6, x r7). Earlier notes (all pragmas, declaration orders, inline helpers, u8/u16 widths) did not move the colours.
 */
void func_021E5ADC(u32 *p, struct PrintSys *win, u32 str, u32 c2, u32 c1, u16 heap)
{
    struct MsgBank *msg;
    struct WordSet *ws;
    struct U16Vec *buf;
    void *e;
    int x, x1, x2;
    u16 w;

    msg = func_02045B38(0, 2, 0xa3, heap);
    ws = func_0201EC64(heap);
    buf = func_020457B0(0x20, heap);
    x = (u16)(func_02045738((void *)p[0]) << 3);

    e = func_02045EC0(msg, 2);
    func_0201EFA4(ws, 0, c1, 8, 0, 1);
    func_0201F250(ws, buf, e);
    w = func_0201D304((struct StrObj *)buf, str, 0);
    x1 = x - w;
    func_0201C6FC(win, (u32)func_02045770((struct Descriptor *)p[0]), (s16)x1, 0, buf, str);
    ((u8 *)p)[4] = 1;
    func_02045808((struct U16Vec *)e);

    e = func_02045EC0(msg, 0);
    w = func_0201D304(e, str, 0);
    x2 = x1 - w;
    func_0201C6FC(win, (u32)func_02045770((struct Descriptor *)p[0]), (s16)x2, 0, e, str);
    ((u8 *)p)[4] = 1;
    func_02045808((struct U16Vec *)e);

    e = func_02045EC0(msg, 1);
    func_0201EFA4(ws, 0, c2, 8, 0, 1);
    func_0201F250(ws, buf, e);
    w = func_0201D304((struct StrObj *)buf, str, 0);
    func_0201C6FC(win, (u32)func_02045770((struct Descriptor *)p[0]), (s16)(x2 - w), 0, buf, str);
    ((u8 *)p)[4] = 1;
    func_02045808((struct U16Vec *)e);
    func_02045808(buf);
    func_0201ED04(ws);
    func_02045C04((struct Rec *)msg);
}




/*
 * note 2026-10-05 (recoup R4): EXACT. Lever: heap parameter u16 with u16 heap parameters on every callee (02030734 first, 021E6718 last, 021E72FC fourth, 021E7464 fifth), no heapId local. u8 also gives EXACT; u16 chosen to match the sibling constructors 5D68/6118/7520. The earlier u16-only try changed only this function and gave 264 B.
 */
Work *func_021E5C20(const Info_021E5440 *info, u32 a1, void *a2, int owner,
                    void *table, int a5, void *a6, void *a7, void *a8, u16 heap)
{
    Work *w;
    u32 kind;
    u32 size;
    int alt;
    Point pos;
    size = 0x229 + 0x1b;
    w = func_02030734(heap, size, 0, d_021E8DBC, 0x229);
    func_02082BCC(w, 0, size);
    w->c230 = 5;
    w->c231 = 15;
    w->c232 = 3;
    w->c233 = 7;
    w->f234 = 1;
    alt = 1;
    func_0207D63C((void *)0x04001050, 4, 8, 15, 3);
    kind = func_021E7CF0(info->fC, info->h10, info->h12);
    if (kind != 5) alt = 0;
    func_021E6718(w, a1, info, a2, a5, a6, a7, a8, alt, heap);
    func_021E72FC((u8 *)w, info->f8, owner, heap);
    pos.x = 0x120;
    pos.y = 0x44;
    func_0204B404(w->f188, (const Pt_021E5D68 *)&pos, 1);
    func_021E7464((char *)w, (char *)info, owner, table, heap);
    func_020413B0(6, 0, 0, 0x20, 6, 1);
    func_020413B0(6, 0, 6, 0x20, 18, kind + 3);
    func_020409B4(6);
    func_0207D63C((void *)0x04001050, 4, 8, 15, 3);
    return w;
}




void func_021E5D40(void *p)
{
    *(unsigned short *)0x04001050 = 0;
    func_021E74FC(p);
    func_021E73B8(p);
    func_021E6EFC(p);
    func_020307B0(p);
}





char *func_021E5D68(char *info, u32 a, void *b, void *owner, void *table, int c, void *d, void *e, void *f, void *record, int mode, u16 heap)
{
  char *w;
  Layer layer;
  Pt_021E5D68 pos;
  Info_021E5D68 *tmp;
  w = func_02030734(heap, 0x244, 0, d_021E8DBC, 0x27f);
  func_02082BCC(w, 0, 0x244);
  *((void **) (w + 0x238)) = record;
  *((u16 *) (w + 0x23c)) = heap;
  *((void **) (w + 0x240)) = owner;
  if (mode)
  {
    layer = 2;
    *((u8 *) (w + 0x230)) = 1;
    *((u8 *) (w + 0x231)) = 15;
    *((u8 *) (w + 0x232)) = 5;
    *((u8 *) (w + 0x233)) = 9;
    *((u32 *) (w + 0x234)) = 0;
    func_0207D63C((void *) 0x04000050, 4, 8, 15, 3);
  }
  else
  {
    *((u8 *) (w + 0x230)) = 5;
    *((u8 *) (w + 0x231)) = 15;
    *((u8 *) (w + 0x232)) = 3;
    *((u8 *) (w + 0x233)) = 7;
    *((u32 *) (w + 0x234)) = 1;
    layer = 6;
    func_0207D63C((void *) 0x04001050, 4, 8, 15, 3);
  }
  tmp = (Info_021E5D68 *) info;
  switch (*((u16 *) (info + 0xaa)))
  {
    case 0:
      func_020413B0(layer, 0, 0, 32, 5, 1);
      func_020413B0(layer, 0, 5, 32, 18, 3);
      func_020409B4((u8) layer);
      break;

    case 1:
      func_020413B0(layer, 0, 0, 32, 5, 1);
      func_020413B0(layer, 0, 5, 32, 18, 7);
      func_020409B4((u8) layer);
      break;

  }

  func_021E6940((Work_021E5D68 *) w, a, tmp, b, c, d, e, f, heap);
  func_021E6F20((Work_021E5D68 *) w, owner, record, heap);
  info += 0x9c;
  func_021E72FC((u8 *) w, *((u32 *) info), (u32) owner, heap);
  pos.x = 0x120;
  pos.y = 0x6e;
  func_0204B404(*((void **) (w + 0x188)), (const Pt_021E5D68 *)&pos, *((u32 *) (w + 0x234)));
  func_021E73E4(w, (u32) owner, table, heap);
  return w;
}






void func_021E5EF8(void *p)
{
    *(unsigned short *)0x04001050 = 0;
    func_021E7454(p);
    func_021E73B8(p);
    func_021E7270(p);
    func_021E6EFC(p);
    func_020307B0(p);
}






/*
 * note 2026-10-05 (wave D9r lane 131): removed the 3 dead first assignments
 * (`layer1=0x240;` before `layer1=0x234;`; `layer2=0x240;` before
 * `layer2=0x234;` and 1 more). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
void func_021E5F24(char *p, int mode, void *mgr, void *print, int font, u16 a5)
{
    int i;
    void *s;
    int x;
    int base,layer1,secondary,layer2;
    Pt_021E5EF8 pos;
    func_02043B5C(func_02045770(((struct Obj00133 *)p)->f20),0);
    i=0;
    func_021E7270(p);
    base=0x240;
    func_021E6F20((Work_021E5D68 *)p,*(void **)(p+base),*(void **)(p+base-8),*(u16 *)(p+base-4));
    x=32-func_020407E8(*(u8 *)(p+base-16));
    layer1=0x234;
    layer2=0x234;
    secondary=0x1a8;
    base=0x16c;
    for(;i<6;i++) {
        void *o;
        char *q;
        pos.y=168;pos.x=x+i*32;
        q=p+i*4;
        o=*(void **)(q+base);
        if(o)func_0204B404(o, (const Pt_021E5D68 *)&pos, *(unsigned *)(p+layer1));
        o=*(void **)(q+secondary);
        if(o) {
            pos.x+=12;pos.y+=8;
            func_0204B404(o, (const Pt_021E5D68 *)&pos, *(unsigned *)(p+layer2));
        }
    }
    switch(mode) {
    case 0:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((struct Obj05464 *)q)->f1A8;
            if(o)func_0204B3DC(o,1);
            o=((struct Obj05464 *)q)->f16C;
            if(o)func_0204B3DC(o,1);
        }
        func_0204B3DC(((struct Obj00133 *)p)->f18C,1);
        s=func_02045EC0(mgr,17);
        func_0201C724(print,(u32)func_02045770(((struct Obj00133 *)p)->fB4),0,0,(u32)s,font,0x3c40);
        ((struct Obj00133 *)p)->fB8=1;
        break;
    case 1:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((struct Obj05464 *)q)->f1A8;
            if(o)func_0204B3DC(o,1);
            o=((struct Obj05464 *)q)->f16C;
            if(o)func_0204B3DC(o,1);
        }
        func_0204B3DC(((struct Obj00133 *)p)->f18C,0);
        s=func_02045EC0(mgr,18);
        func_0201C724(print,(u32)func_02045770(((struct Obj00133 *)p)->fB4),0,0,(u32)s,font,0x3c40);
        ((struct Obj00133 *)p)->fB8=1;
        break;
    case 2:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((struct Obj05464 *)q)->f1A8;
            if(o)func_0204B3DC(o,0);
            o=((struct Obj05464 *)q)->f16C;
            if(o)func_0204B3DC(o,0);
        }
        func_0204B3DC(((struct Obj00133 *)p)->f18C,0);
        s=func_02045EC0(mgr,19);
        func_0201C724(print,(u32)func_02045770(((struct Obj00133 *)p)->fB4),0,0,(u32)s,font,0x3c40);
        ((struct Obj00133 *)p)->fB8=1;
        break;
    }
    func_02045808(s);
}





char *func_021E6118(char *info, void *a, void *owner, void *table, int b, void *c, void *d, void *e, void *record, int mode, u16 heap)
{
  char *w;
  Layer layer;
  Pt_021E5D68 pos;
  Info_021E5D68 *tmp;
  w = func_02030734(heap, 0x244, 0, d_021E8DBC, 0x354);
  func_02082BCC(w, 0, 0x244);
  *((void **) (w + 0x238)) = record;
  *((u16 *) (w + 0x23c)) = heap;
  *((void **) (w + 0x240)) = owner;
  if (mode)
  {
    layer = 2;
    *((u8 *) (w + 0x230)) = 1;
    *((u8 *) (w + 0x231)) = 15;
    *((u8 *) (w + 0x232)) = 5;
    *((u8 *) (w + 0x233)) = 9;
    *((u32 *) (w + 0x234)) = 0;
    func_0207D63C((void *) 0x04000050, 4, 8, 15, 3);
  }
  else
  {
    *((u8 *) (w + 0x230)) = 5;
    *((u8 *) (w + 0x231)) = 15;
    *((u8 *) (w + 0x232)) = 3;
    *((u8 *) (w + 0x233)) = 7;
    *((u32 *) (w + 0x234)) = 1;
    layer = 6;
    func_0207D63C((void *) 0x04001050, 4, 8, 15, 3);
  }
  tmp = (Info_021E5D68 *) info;
  switch (*((u16 *) (info + 0xa8)))
  {
    case 0:
      func_020413B0(layer, 0, 0, 32, 5, 1);
      func_020413B0(layer, 0, 5, 32, 18, 3);
      func_020409B4((u8) layer);
      break;

    case 1:
      func_020413B0(layer, 0, 0, 32, 5, 1);
      func_020413B0(layer, 0, 5, 32, 18, 7);
      func_020409B4((u8) layer);
      break;

  }

  func_021E6BE8((Work_021E5D68 *) w, tmp, a, b, c, d, e, heap);
  func_021E6F20((Work_021E5D68 *) w, owner, record, heap);
  info += 0x9c;
  func_021E72FC((u8 *) w, *((u32 *) info), (u32) owner, heap);
  pos.x = 0x120;
  pos.y = 0x6e;
  func_0204B404(*((void **) (w + 0x188)), (const Pt_021E5D68 *)&pos, *((u32 *) (w + 0x234)));
  func_021E73E4(w, (u32) owner, table, heap);
  return w;
}





void func_021E62A0(void *p)
{
    *(unsigned short *)0x04001050 = 0;
    func_021E7454(p);
    func_021E73B8(p);
    func_021E7270(p);
    func_021E6EFC(p);
    func_020307B0(p);
}



void func_021E62CC(char *p, int mode, void *mgr, void *print, int font, u32 a5)
{
    int i;
    void *s;
    int x;
    int base,layer1,secondary,layer2;
    Pt_021E62CC pos;
    func_02043B5C(func_02045770(((struct Obj00133 *)p)->f28),0);
    i=0;
    func_021E7270(p);
    base=0x240;
    func_021E6F20((Work_021E5D68 *)p,*(void **)(p+base),*(void **)(p+base-8),*(u16 *)(p+base-4));
    x=32-func_020407E8(*(u8 *)(p+base-16));
    layer1=0x234;
    layer2=0x234;
    secondary=0x1a8;
    base=0x16c;
    for(;i<6;i++) {
        void *o;
        char *q;
        pos.y=168;pos.x=x+i*32;
        q=p+i*4;
        o=*(void **)(q+base);
        if(o)func_0204B404(o, (const Pt_021E5D68 *)&pos, *(unsigned *)(p+layer1));
        o=*(void **)(q+secondary);
        if(o) {
            pos.x+=12;pos.y+=8;
            func_0204B404(o, (const Pt_021E5D68 *)&pos, *(unsigned *)(p+layer2));
        }
    }
    switch(mode) {
    case 0:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((struct Obj05465 *)q)->f1A8;
            if(o)func_0204B3DC(o,1);
            o=((struct Obj05465 *)q)->f16C;
            if(o)func_0204B3DC(o,1);
        }
        func_0204B3DC(((struct Obj00133 *)p)->f18C,1);
        s=func_02045EC0(mgr,17);
        func_0201C724(print,(u32)func_02045770(((struct Obj00133 *)p)->fC4),0,0,(u32)s,font,0x3c40);
        ((struct Obj00133 *)p)->fC8=1;
        break;
    case 1:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((struct Obj05465 *)q)->f1A8;
            if(o)func_0204B3DC(o,1);
            o=((struct Obj05465 *)q)->f16C;
            if(o)func_0204B3DC(o,1);
        }
        func_0204B3DC(((struct Obj00133 *)p)->f18C,0);
        s=func_02045EC0(mgr,18);
        func_0201C724(print,(u32)func_02045770(((struct Obj00133 *)p)->fC4),0,0,(u32)s,font,0x3c40);
        ((struct Obj00133 *)p)->fC8=1;
        break;
    case 2:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((struct Obj05465 *)q)->f1A8;
            if(o)func_0204B3DC(o,0);
            o=((struct Obj05465 *)q)->f16C;
            if(o)func_0204B3DC(o,0);
        }
        func_0204B3DC(((struct Obj00133 *)p)->f18C,0);
        s=func_02045EC0(mgr,19);
        func_0201C724(print,(u32)func_02045770(((struct Obj00133 *)p)->fC4),0,0,(u32)s,font,0x3c40);
        ((struct Obj00133 *)p)->fC8=1;
        break;
    }
    func_02045808(s);
}




/*
 * Unlabelled ov177 thunk hidden in a word run: forwards to func_021E6E8C.
 * Matched to supply the `matched` witness for the pending ov176 caller
 * func_0217D434.
 */
int func_021E64C0(unsigned char *p, void *mgr)
{
    return func_021E6E8C(p, mgr);
}



int func_021E64C8(Work_021E64C0 *w)
{
    int ret;
    int level;
    int i;
    Pt cur, pos;
    if (func_020407E8(w->bg) == 0)
        return 1;
    ret = 0;
    if (w->count == 0) {
        for (i = 0; i < 22; i++) {
            if (w->objs[i] != 0) {
                func_0204B454(w->objs[i], (struct PtS *)&cur, (unsigned short)w->layer);
                w->baseX[i] = cur.x;
            }
        }
        func_020061E4(0x63b);
    }
    level = func_0209C2B0(w->count << 8, 20) - 0x100;
    for (i = 0; i < 22; i++) {
        if (w->objs[i] != 0) {
            func_0204B454(w->objs[i], (struct PtS *)&pos, (unsigned short)w->layer);
            pos.x = w->baseX[i] - func_0209C2B0(w->count << 8, 20);
            func_0204B404(w->objs[i], (const Pt_021E5D68 *)&pos, w->layer);
        }
    }
    if (w->count++ >= 20) {
        level = 0;
        w->count = 0;
        ret = 1;
    }
    func_02041EE4((unsigned char)(w->bg + 1), (int)0, (int)level);
    func_02041EE4((unsigned char)w->bg, (int)0, (int)level);
    return ret;
}
