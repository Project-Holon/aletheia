/*
 * file:     zukan_detail_graphic_p21.c
 * unit:     yes
 * function: func_021BF308, func_021BF41C, func_021BF450, func_021BF4C4, func_021BF4FC, func_021BF5B8, func_021BF61C, func_021BF620, func_021BF63C, func_021BF664, func_021BF784, func_021BF788, func_021BF8E0, func_021BF9B0
 * address:  0x021BF308
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BC3B4 0x021BC3B4 thumb ov208
 *   func_021BC3A8 0x021BC3A8 thumb ov208
 *   func_021BCF4C 0x021BCF4C thumb ov208
 *   func_021BDC80 0x021BDC80 thumb ov208
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B688 0x0204B688 arm
 *   d_021C851C 0x021C851C data ov208 a1
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B878 0x0204B878 arm
 *   func_021BDC48 0x021BDC48 thumb ov208
 *   func_021BC3A4 0x021BC3A4 thumb ov208
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_021BC3C0 0x021BC3C0 thumb ov208
 *   func_0200CC40 0x0200CC40 thumb
 *   func_0200D288 0x0200D288 thumb
 *   func_0200CED4 0x0200CED4 thumb
 *   func_0200D3C0 0x0200D3C0 thumb
 *   func_02049F34 0x02049F34 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02061CA4 0x02061CA4 arm
 *   tbl_020A1B38 0x020A1B38 data
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_021BC32C 0x021BC32C thumb ov208
 *   func_021BC3AC 0x021BC3AC thumb ov208
 *   func_021C0048 0x021C0048 thumb ov208
 *   func_021BFFEC 0x021BFFEC thumb ov208
 *   func_021C06C8 0x021C06C8 thumb ov208
 *   func_021BC448 0x021BC448 thumb ov208
 *   func_021BC518 0x021BC518 thumb ov208
 *   func_021BC508 0x021BC508 thumb ov208
 *   func_021BC560 0x021BC560 thumb ov208
 *   func_021BBB24 0x021BBB24 thumb ov072
 *   func_02012984 0x02012984 thumb
 *   func_02034AC4 0x02034AC4 arm
 *   func_020056A0 0x020056A0 thumb
 *   ov072_id 0x00000048 data a1
 *   func_021C1F44 0x021C1F44 thumb ov208
 *   func_021C0C00 0x021C0C00 thumb ov208
 *   func_021C0B58 0x021C0B58 thumb ov208
 *   func_021C0950 0x021C0950 thumb ov208
 *   func_021C0898 0x021C0898 thumb ov208
 *   func_021BC97C 0x021BC97C thumb ov208
 *   func_021C06A0 0x021C06A0 thumb ov208
 *   func_021C0524 0x021C0524 thumb ov208
 *   func_021C03C4 0x021C03C4 thumb ov208
 *   func_021BC61C 0x021BC61C thumb ov208
 *   func_021BC464 0x021BC464 thumb ov208
 *   func_021C06EC 0x021C06EC thumb ov208
 *   func_021BBB34 0x021BBB34 thumb ov072
 *   func_021BC34C 0x021BC34C thumb ov208
 *   func_02030EAC 0x02030EAC arm
 *   func_02034A5C 0x02034A5C arm
 *   ov208_func_021BC3B4  0x021BC3B4  thumb  ov208
 *   ov208_func_021BC3B8  0x021BC3B8  thumb  ov208
 *   func_0207D4B0  0x0207D4B0  arm
 *   data_021C85C0  0x021C85C0  data
 *   data_021C8618  0x021C8618  data
 *   func_020403F4  0x020403F4  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414AC  0x020414AC  arm
 *   func_02040588  0x02040588  arm
 *   func_02040618  0x02040618  arm
 *   func_0204047C  0x0204047C  arm
 *   ov208_func_021C0090  0x021C0090  thumb  ov208
 *   ov208_func_021C0134  0x021C0134  thumb  ov208
 *   ov208_func_021C0450  0x021C0450  thumb  ov208
 *   ov208_func_021C0544  0x021C0544  thumb  ov208
 *   ov208_func_021BC844  0x021BC844  thumb  ov208
 *   ov208_func_021C0788  0x021C0788  thumb  ov208
 *   ov208_func_021C08E8  0x021C08E8  thumb  ov208
 *   ov208_func_021C0B10  0x021C0B10  thumb  ov208
 *   ov208_func_021C1AD4  0x021C1AD4  thumb  ov208
 *   ov208_func_021C0C50  0x021C0C50  thumb  ov208
 *   ov208_func_021C0C8C  0x021C0C8C  thumb  ov208
 *   ov208_func_021BC758  0x021BC758  thumb  ov208
 *   ov208_func_021BC718  0x021BC718  thumb  ov208
 *   ov208_func_021BC4F4  0x021BC4F4  thumb  ov208
 *   ov208_func_021C24F0  0x021C24F0  thumb  ov208
 *   ov208_func_021BC4D8  0x021BC4D8  thumb  ov208
 *   ov208_func_021BC6D8  0x021BC6D8  thumb  ov208
 *   ov208_func_021BDAD0  0x021BDAD0  thumb  ov208
 *   ov208_func_021BC3BC  0x021BC3BC  thumb  ov208
 *   ov208_func_021BDAAC  0x021BDAAC  thumb  ov208
 *   ov208_func_021BDAD4  0x021BDAD4  thumb  ov208
 *   ov208_func_021BDBB8  0x021BDBB8  thumb  ov208
 *   ov208_func_021BDC48  0x021BDC48  thumb  ov208
 *   ov208_func_021BC3A4  0x021BC3A4  thumb  ov208
 *   func_02012BF8  0x02012BF8  thumb
 *   ov208_func_021BDC14  0x021BDC14  thumb  ov208
 *   ov208_func_021BE840  0x021BE840  thumb  ov208
 *   ov208_func_021BE82C  0x021BE82C  thumb  ov208
 *   ov208_func_021BE844  0x021BE844  thumb  ov208
 *   ov208_func_021BC4C8  0x021BC4C8  thumb  ov208
 *   ov208_func_021BC6C8  0x021BC6C8  thumb  ov208
 *   ov208_func_021BDBA0  0x021BDBA0  thumb  ov208
 *   ov208_func_021C2458  0x021C2458  thumb  ov208
 *   ov208_func_021C1D0C  0x021C1D0C  thumb  ov208
 *   ov208_func_021C1D24  0x021C1D24  thumb  ov208
 *   ov208_func_021C23BC  0x021C23BC  thumb  ov208
 *   ov208_func_021C10B8  0x021C10B8  thumb  ov208
 *   ov208_func_021C24A4  0x021C24A4  thumb  ov208
 *   ov208_func_021BC4E4  0x021BC4E4  thumb  ov208
 *   ov208_func_021BC6F8  0x021BC6F8  thumb  ov208
 *   ov208_func_021BE854  0x021BE854  thumb  ov208
 *   ov208_func_021BDAE8  0x021BDAE8  thumb  ov208
 *   ov208_func_021C252C  0x021C252C  thumb  ov208
 *   ov208_func_021BC508  0x021BC508  thumb  ov208
 *   ov208_func_021C0130  0x021C0130  thumb  ov208
 *   ov208_func_021BC99C  0x021BC99C  thumb  ov208
 *   ov208_func_021C0968  0x021C0968  thumb  ov208
 *   ov208_func_021C0A8C  0x021C0A8C  thumb  ov208
 *   ov208_func_021C1810  0x021C1810  thumb  ov208
 *   ov208_func_021BC46C  0x021BC46C  thumb  ov208
 *   ov208_func_021BC678  0x021BC678  thumb  ov208
 *   ov208_func_021C0714  0x021C0714  thumb  ov208
 */
#include "../../matched/include/Obj02254.h"
#include "../../matched/include/Obj05538.h"
#include "../../matched/include/Obj12120.h"
#include "../../matched/include/Obj10901.h"
#include "../../matched/include/Obj18262.h"
#include "../../matched/include/Obj25493.h"
#include "../../matched/include/Obj00442.h"
#include "../../matched/include/Obj00510.h"
#include "../../matched/include/Obj03933.h"
#include "../../matched/include/Obj08396.h"

#define W(o) (*(u32 *)(p + (o)))
struct Actor;
struct Obj;
struct Ov208Scene;
struct Blk37;
struct Ov208Heap;
struct BigObj;
struct Ov208Buf;
struct Node;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

enum Index { INDEX_ZERO = 0 };

struct Pos { u16 x, y, z, pad; };

struct Ov208Pltt { u32 pad0[3]; u8 *data; };

typedef struct {
    char pad0[0x98];
    int f98;
    char pad9c[0xa8 - 0x9c];
    unsigned short srcA[0x10];
    unsigned short srcB[0x10];
    unsigned short dst[0x10];
    int f108;
    int f10c;
} Ent;

typedef signed int     s32_021BF664;

typedef int            s32_021BF9B0;

struct BgTemplate {
    u32 w[8];
};

struct BgEntry {
    u32 bg;
    struct BgTemplate tmpl;
    u32 type;
    u32 on;
};

extern int func_021BC3B4(int *p);
extern int func_021BC3A8(int *p);
extern int func_021BCF4C(char *);
extern int func_021BDC80(char *p);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern int func_0204AF28(void *,u32,u32,u32);
extern void func_02049238(void *);
extern void func_02082BCC(void *,int,u32);
/* Caller consumes r0 from the legacy void-returning allocation wrapper. */
extern u32 func_0204B294(u32,u32,u32,u32,struct Pos *,u16,u16);
extern void func_0204B92C(struct Obj *,u32);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern unsigned func_0204B98C(struct Actor *);
extern void func_0204B878(struct Obj *, u16);
extern void func_021BDC48(struct Ov208Scene *, unsigned);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern int func_021BC3A4(int *p);
extern void *func_0200CA1C(void *a);
extern u16 func_021BC3C0(int);
extern void func_0200CC40(u8 *, u32, u32 *, u32 *, u32 *, u16);
extern u32 func_0200D288(struct Blk37 *, u32);
extern u32 func_0200CED4(struct Blk37 *, u32);
extern u32 func_0200D3C0(struct Blk37 *, u32, u32);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(void *, void *, u32);
extern u32 func_020307B0(void *p);
extern int func_02061CA4(void *, u32, u32, int);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void *func_021BC32C(struct Ov208Buf *p, u32 size, u32 heap);
extern int func_021BC3AC(int *p);
extern int func_02034AC4(int);
extern u8 func_02012984(const struct BigObj *p);
extern int func_021BBB24(int);
extern void func_021C0048(u16 *,char *,int);
extern void func_021C06C8(u16 *,char *,int);
extern void func_021BFFEC(void *,char *);
extern void *func_020056A0(u32,u32,u32);
extern void *func_021BC448(u32);
extern void func_021BC518(int *p);
extern void func_021BC508(int flag, int *p);
extern void *func_021BC560(u32,u16);
extern void func_021C1F44(int a);
extern void func_021C0C00(void *a, void *b);
extern void func_021C0B58(void *, char *, void *);
extern void func_021C0950(void *unused, u8 *p, void *a2);
extern void func_021C0898(void *, char *, void *);
extern void func_021C06A0(void *, char *, void *);
extern void func_021C0524(void *, char *, void *);
extern void func_021C03C4(void *, char *, void *);
extern void func_021C06EC(void *, char *, void *);
extern void func_021BC97C(char *p);
extern void func_021BC61C(char *p);
extern void func_021BC464(void *);
extern void func_021BBB34(void *);
extern void func_021BC34C(char *p);
extern void func_02030EAC(struct Node *n);
extern void func_02034A5C(int);
extern void *ov208_func_021BC3B4(int key);
extern void *ov208_func_021BC3B8(int key);
extern void func_0207D4B0(int dispMode, int bgMode, int bg0_2d3d);
extern void func_020403F4(u32 i);
extern void func_0203FCA0(u8 bgId, const struct BgTemplate *tmpl, u8 type);
extern void func_020414AC(u8 bgId);
extern void func_02040588(u8 which, u8 enable);
extern void func_02040618(u32 bgId, u32 which, u32 value);
extern void func_0204047C(int idx, unsigned short val);
extern void ov208_func_021C0090(u16 *heap, u8 *p, int key);
extern void ov208_func_021C0134(u16 *heap, u8 *p, int key);
extern void ov208_func_021C0450(u16 *heap, u8 *p, int key);
extern void ov208_func_021C0544(u16 *heap, u8 *p, int key);
extern u32  ov208_func_021BC844(u16 heap, u32 kind, u8 layer, u8 pal, u8 objPal);
extern void ov208_func_021C0788(u16 *heap, u8 *p, int key);
extern void ov208_func_021C08E8(u16 *heap, u8 *p, int key);
extern void ov208_func_021C0B10(u16 *heap, u8 *p, int key);
extern void ov208_func_021C1AD4(u16 *heap, u8 *p, int key);
extern void ov208_func_021C0C50(u16 *heap, u8 *p, int key);
extern void ov208_func_021C0C8C(u16 *heap, u8 *p, int key, int on);
extern void ov208_func_021BC758(u32 fade);
extern void ov208_func_021BC718(u32 fade);
extern void ov208_func_021BC4F4(int sub, u32 blend);
extern void ov208_func_021C24F0(u16 *heap, u8 *p, int key);
extern void ov208_func_021BC4D8(u32 blend);
extern void ov208_func_021BC6D8(u32 fade);
extern int  ov208_func_021BDAD0(void *s);
extern u16  ov208_func_021BC3BC(char *p);
extern void ov208_func_021BDAAC(void *s, u32 mode, u32 kind, u32 flag);
extern void ov208_func_021BDAD4(void *s, int v);
extern void ov208_func_021BDBB8(void *s, u32 kind);
extern void ov208_func_021BDC48(void *s, u32 on);
extern int  ov208_func_021BC3A4(int key);
extern int func_02012BF8(int a0, int a1);
extern void ov208_func_021BDC14(void *s, int b);
extern int  ov208_func_021BE840(void *icon);
extern void ov208_func_021BE82C(void *icon, int kind);
extern void ov208_func_021BE844(void *icon);
extern int  ov208_func_021BC4C8(u32 blend);
extern int  ov208_func_021BC6C8(u32 fade);
extern void ov208_func_021BDBA0(void *s);
extern void ov208_func_021C2458(u16 *heap, u8 *p, int key);
extern void ov208_func_021C1D0C(u16 *heap, u8 *p, int key);
extern void ov208_func_021C1D24(u16 *heap, u8 *p, int key);
extern void ov208_func_021C23BC(u8 *p);
extern void ov208_func_021C10B8(u16 *heap, u8 *p, int key);
extern void ov208_func_021C24A4(u16 *heap, u8 *p, int key);
extern void ov208_func_021BC4E4(u32 blend);
extern void ov208_func_021BC6F8(u32 fade);
extern void ov208_func_021BE854(void *icon);
extern void ov208_func_021BDAE8(void *s, int v);
extern void ov208_func_021C252C(u16 *heap, u8 *p, int key);
extern void ov208_func_021BC508(int sub, u32 blend);
extern void ov208_func_021C0130(u16 *heap, u8 *p, int key);
extern void ov208_func_021BC99C(u32 win);
extern void ov208_func_021C0968(u16 *heap, u8 *p, int key);
extern void ov208_func_021C0A8C(u16 *heap, u8 *p, int key);
extern void ov208_func_021C1810(u16 *heap, u8 *p, int key);
extern void ov208_func_021BC46C(u32 main, u32 sub);
extern void ov208_func_021BC678(u32 fade);
extern void ov208_func_021C0714(u16 *heap, u8 *p, int key);
void func_021BF308(u16 *heap, char *p, int key);
void func_021BF41C(int unused, char *q, u32 a2);
void func_021BF450(void *unused, char *p, int key);
void func_021BF4C4(int unused, char *q, int c, int *tbl);
void func_021BF4FC(const u16 *heap, u8 *p, int key, u16 *out1, u16 *out2, u16 *out3, u16 *out4, u32 *out5, u32 *out6, u32 *out7);
void func_021BF5B8(u16 *heap, u8 *p, int *ctx);
void func_021BF61C(void);
void func_021BF620(struct Ov208Heap *unused, int *p, int *ctx);
void func_021BF63C(int unused, char *p);
void func_021BF664(int a0, Ent *e);
void func_021BF784(u16 *p, u16 v);
/* Caller explicitly loads r2 for setup helpers whose filed bodies omit it. */ u32 func_021BF788(void *a0,u32 a1,u16 *heap,u32 a3,int key);
/* Caller explicitly loads r2 for the three-argument teardown helpers. */ u32 func_021BF8E0(void *a0, u32 a1, void *a2, char *p, void *a4);
int ov208_func_021BF9B0(void *proc, int *seq, u16 *heap, u8 *p, int key);
extern const u8 d_021C851C[];
extern short tbl_020A1B38[];
extern u8 ov072_id[];
extern const struct BgEntry data_021C85C0[2];
extern const struct BgEntry data_021C8618[2];

void func_021BF308(u16 *heap, char *p, int key)
{
    struct Pos pos;
    void *scene;
    int owner;
    void *arc;
    enum Index i;
    u16 flag;
    scene = (void *)func_021BC3B4((int *)key);
    owner = func_021BCF4C((char *)func_021BC3A8((int *)key));
    i = 0;
    arc = func_020490F4(0x9f, *heap);
    ((struct Obj05538 *)p)->f9C = func_021BDC80(scene);
    ((struct Obj05538 *)p)->fA0 = func_0204A6C8(arc, 0xd, 0, 0, *heap);
    ((struct Obj05538 *)p)->fA4 = func_0204AF28(arc, 0x1b, 0x2c, *heap);
    func_02049238(arc);
    flag = (u16)i;
    do {
        char *q;
        const u8 *t;
        func_02082BCC(&pos, 0, 8);
        t = d_021C851C + i * 9;
        q = p + i * 20;
        q[0x20] = t[2];
        q[0x21] = t[3];
        q[0x22] = t[4];
        q[0x23] = t[5];
        ((struct Obj02254 *)q)->f24 = t[6];
        ((struct Obj02254 *)q)->f26 = t[7];
        q[0x28] = t[8];
        ((struct Obj02254 *)q)->f2C = 0;
        pos.x = t[0];
        pos.y = t[1];
        pos.z = ((struct Obj02254 *)q)->f24;
        ((struct Obj02254 *)q)->f1C = func_0204B294(owner, ((struct Obj05538 *)p)->fA0, ((struct Obj05538 *)p)->f9C, ((struct Obj05538 *)p)->fA4, &pos, flag, *heap);
        func_0204B92C((struct Obj *)((struct Obj02254 *)q)->f1C, 1);
        func_0204B688((struct Actor *)(((struct Obj02254 *)q)->f1C), 1);
        i = (u8)(i + 1);
    } while ((u32)i < 6);
}


/*
 * Releases the sixth 0x14-byte element handle at +0x1C and the two at +0xA0 and +0xA4.
 */
void func_021BF41C(int unused, char *q, u32 a2)
{
    unsigned char i;

    for (i = 0; i < 6; i++)
        func_0204B3B4((struct Obj *)(*(int *)(q + i * 0x14 + 0x1c)));
    func_0204A8D4(((struct Obj12120 *)q)->fA0);
    func_0204AFD8(((struct Obj12120 *)q)->fA4);
}

/*
 * Byte-based state indexing preserves the shared 20-byte stride; u32 indexing changes it to shift/add.
 */
void func_021BF450(void *unused, char *p, int key)
{
    void *scene = (void *)func_021BC3B4((int *)key);
    if (((struct Obj10901 *)p)->f94 != 6) {
        u8 i = ((struct Obj10901 *)p)->f94;
        char *states = p + 0x2c;
        switch (*(unsigned *)(states + i * 20)) {
        case 0: break;
        case 1: *(unsigned *)(states + i * 20) = 2; break;
        case 2:
            if (func_0204B98C(*(struct Actor **)(p + i * 20 + 0x1c)) == 0)
                *(unsigned *)(states + i * 20) = 3;
            break;
        case 3:
            func_0204B878(*(struct Obj **)(p + i * 20 + 0x1c), *(u16 *)(p + i * 20 + 0x24));
            *(unsigned *)(states + i * 20) = 0;
            ((struct Obj10901 *)p)->f94 = 6;
            func_021BDC48(scene, 1);
            break;
        }
    }
}


void func_021BF4C4(int unused, char *q, int c, int *tbl)
{
    unsigned char i;

    for (i = 0; i < 6; i++) {
        func_0204B3DC((struct Obj *)*(int *)(q + i * 0x14 + 0x1c), tbl[i]);
        *(int *)(q + i * 0x14 + 0x2c) = 0;
        func_0204B878((struct Obj *)(*(int *)(q + i * 0x14 + 0x1c)), *(unsigned short *)(q + i * 0x14 + 0x24));
    }
    ((struct Obj18262 *)q)->f94 = 6;
}

/*
 * Species local and CC40/CED4 species arguments are u32: this caller has no u16 truncation before either call.
 */
void func_021BF4FC(const u16 *heap, u8 *p, int key, u16 *out1, u16 *out2, u16 *out3, u16 *out4, u32 *out5, u32 *out6, u32 *out7)
{
    u32 values[6];
    u32 a, b, c, special, value;
    struct Blk37 *ctx;
    u32 id;
    u8 i;
    ctx = func_0200CA1C((void *)func_021BC3A4((int *)key));
    id = func_021BC3C0(key);
    special = 0;
    func_0200CC40((u8 *)ctx, id, &b, &c, &a, *heap);
    if (id == 327) special = func_0200D288(ctx, special);
    value = func_0200CED4(ctx, id);
    for (i = 0; i < 6; i++) values[i] = func_0200D3C0(ctx, id, p[i * 20 + 0x28]);
    *out1 = id;
    *out2 = a;
    *out3 = b;
    *out4 = c;
    *out5 = special;
    *out6 = value;
    for (i = 0; i < 6; i++) out7[i] = values[i];
}

void func_021BF5B8(u16 *heap, u8 *p, int *ctx)
{
    struct Ov208Pltt *pltt;
    u32 file;
    u8 *data;
    file = (u32)func_02049F34(159, 3, (u32)(&pltt), *heap);
    data = pltt->data;
    func_02082D44(data + 0x20, p + 0xa8, 32);
    func_02082D44(data + 0x60, p + 0xc8, 32);
    func_020307B0((void *)file);
    ((struct Obj25493 *)p)->f108 = 0;
    func_02082D44(p + 0xa8, p + 0xe8, 32);
    func_02061CA4((void *)14, 192, (u32)(p + 0xe8), 32);
}

void func_021BF61C(void)
{
}


/*
 * Zeroes word 0x42 and sets word 0x43 when word 0x26 is not 6.
 */
void func_021BF620(struct Ov208Heap *unused, int *p, int *ctx)
{
    if (p[0x26] == 6)
        return;
    p[0x42] = 0;
    p[0x43] = 1;
}


/*
 * Frees the 0x14-byte record at the index held in +0x98.
 */
void func_021BF63C(int unused, char *p)
{
    int i = ((struct Obj00442 *)p)->f98;

    if (i == 6)
        return;
    func_0204B6F4((struct Obj *)(*(int *)(p + i * 0x14 + 0x1c)), 0, 0);
    ((struct Obj00442 *)p)->f10C = 0;
}


/*
 * note: 2026-10-05 (D5-03): closed by u8 channel locals for colour A, the store as
 *   r | g << 5 | b << 10 (GX_RGB order) with the three lerps inline, and the f108 wrap
 *   written on the field directly (no x/y locals).
 */
void func_021BF664(int a0, Ent *e)
{
    if (e->f10c != 0) {
        int v = e->f98;

        if (v != 6)
            func_0204B6F4((struct Obj *)(*(int *)((char *)e + v * 0x14 + 0x1c)), 2, 0);
        e->f10c = 0;
    }

    if (e->f108 + 0x400 >= 0x10000)
        e->f108 = e->f108 + 0x400 - 0x10000;
    else
        e->f108 = e->f108 + 0x400;

    {
        unsigned char i;
        int t = e->f108;
        short ratio;

        t = ((t >> 4) << 1) + 1;
        ratio = (tbl_020A1B38[t] + 0x1000) / 2;

        for (i = 0; i < 0x10; i++) {
            unsigned short A = e->srcA[i];
            unsigned short B = e->srcB[i];
            unsigned char g = (A & 0x3e0) >> 5;
            unsigned char r = A & 0x1f;
            unsigned char b = (A & 0x7c00) >> 10;

            e->dst[i] = (unsigned short)((unsigned char)(r + ((ratio * ((unsigned char)(B & 0x1f) - r)) >> 12))
                | ((unsigned char)(g + ((ratio * ((unsigned char)((B & 0x3e0) >> 5) - g)) >> 12)) << 5)
                | ((unsigned char)(b + ((ratio * ((unsigned char)((B & 0x7c00) >> 10) - b)) >> 12)) << 10));
        }

        func_02061CA4((void *)0xe, 0xc0, (int)e->dst, 0x20);
    }
}

void func_021BF784(u16 *p, u16 v)
{
    *p = v;
}

/* Caller explicitly loads r2 for setup helpers whose filed bodies omit it. */
u32 func_021BF788(void *a0,u32 a1,u16 *heap,u32 a3,int key)
{
    u8 *p;
    int save;
    u8 i;
    save = func_021BC3A4((int *)key);
    func_02034AC4((int)ov072_id);
    p = (u8 *)func_021BC32C(a0,0x438,*heap);
    i = 0;
    func_02082BCC(p,0,0x438);
    ((struct Obj00510 *)p)->f0 = func_021BCF4C((char *)func_021BC3A8((int *)key));
    ((struct Obj00510 *)p)->f4 = func_021BC3AC((int *)key);
    for (;i<2;i++) *(u32 *)(p+i*4+0x5c)=0;
    ((struct Obj00510 *)p)->f64=0;
    ((struct Obj00510 *)p)->f8C=0;
    ((struct Obj00510 *)p)->f90=1;
    ((struct Obj00510 *)p)->f94=0;
    ((struct Obj00510 *)p)->f6C=0;
    ((struct Obj00510 *)p)->f70=0;
    ((struct Obj00510 *)p)->f74=0;
    p[0x78]=func_02012984((const struct BigObj *)save);
    p[0x79]=0xff;
    ((struct Obj00510 *)p)->f84=0;
    ((struct Obj00510 *)p)->f88=1;
    ((struct Obj00510 *)p)->f3C8=func_021BBB24(*heap);
    func_021C0048(heap,(char *)p,key);
    ((struct Obj00510 *)p)->f40C=func_020490F4(0xb2,*heap);
    ((struct Obj00510 *)p)->f410=func_020056A0((u32)func_021BFFEC,(u32)p,1);
    p[0x414]=0;
    func_021C06C8(heap,(char *)p,key);
    ((struct Obj00510 *)p)->f418=func_021BC448(*heap);
    ((struct Obj00510 *)p)->f41C=func_021BC448(*heap);
    func_021BC518((int *)(*(u32 * *)&((struct Obj00510 *)p)->f418));
    func_021BC518((int *)(*(u32 * *)&((struct Obj00510 *)p)->f41C));
    func_021BC508(0,(int *)(*(u32 * *)&((struct Obj00510 *)p)->f418));
    func_021BC508(1,(int *)(*(u32 * *)&((struct Obj00510 *)p)->f41C));
    ((struct Obj00510 *)p)->f420=func_021BC560(*heap,0xa);
    ((struct Obj00510 *)p)->f424=0;
    ((struct Obj00510 *)p)->f428=1;
    ((struct Obj00510 *)p)->f42C=0;
    ((struct Obj00510 *)p)->f430=1;
    ((struct Obj00510 *)p)->f434=1;
    return 1;
}

/* Caller explicitly loads r2 for the three-argument teardown helpers. */
u32 func_021BF8E0(void *a0, u32 a1, void *a2, char *p, void *a4)
{
    u8 i;
    func_021C1F44(((struct Obj03933 *)p)->f94);
    for (i = 0; i < 2; i++) {
        char *q = p + i * 4;
        if (((struct Obj08396 *)q)->f5C != 0) func_021C0C00((void *)(((struct Obj08396 *)q)->f4C), (void *)(((struct Obj08396 *)q)->f5C));
        ((struct Obj08396 *)q)->f5C = 0;
    }
    func_021C0B58(a2, p, a4);
    func_021C0950(a2, (u8 *)p, a4);
    func_021C0898(a2, p, a4);
    func_021BC97C(((struct Obj03933 *)p)->f8);
    func_021C06A0(a2, p, a4);
    func_021C0524(a2, p, a4);
    func_021C03C4(a2, p, a4);
    func_021BC61C(((struct Obj03933 *)p)->f420);
    func_021BC464(((struct Obj03933 *)p)->f41C);
    func_021BC464(((struct Obj03933 *)p)->f418);
    func_021C06EC(a2, p, a4);
    func_02030EAC(((struct Obj03933 *)p)->f410);
    func_02049238(((struct Obj03933 *)p)->f40C);
    func_021BBB34(((struct Obj03933 *)p)->f3C8);
    func_021BC34C(a0);
    func_02034A5C((int)ov072_id);
    return 1;
}


int ov208_func_021BF9B0(void *proc, int *seq, u16 *heap, u8 *p, int key)
{
    void *scene;
    void *icon;
    u32 j;
    u32 k;
    u8 i;
    int ready;

    scene = ov208_func_021BC3B4(key);
    icon = ov208_func_021BC3B8(key);
    switch (*seq) {
    case 0:
        *seq = 1;
        func_0207D4B0(1, 5, 0);
        for (j = 0; j < 2; j++) {
            func_020403F4((u8)data_021C85C0[j].bg);
            func_0203FCA0(data_021C85C0[j].bg, &data_021C85C0[j].tmpl, data_021C85C0[j].type);
            func_020414AC(data_021C85C0[j].bg);
            func_02040588(data_021C85C0[j].bg, data_021C85C0[j].on);
        }
        for (i = 0; i <= 7; i++) {
            if (i != 1 && i != 5) {
                func_02040618(i, 0, 0);
                func_02040618(i, 3, 0);
                func_020414AC(i);
            }
        }
        func_0204047C(2, 2);
        func_0204047C(3, 3);
        func_0204047C(0, 1);
        func_0204047C(6, 1);
        func_0204047C(7, 2);
        func_0204047C(4, 3);
        ov208_func_021C0090(heap, p, key);
        ov208_func_021C0134(heap, p, key);
        ov208_func_021C0450(heap, p, key);
        ov208_func_021C0544(heap, p, key);
        W(8) = ov208_func_021BC844(*heap, 1, 4, 9, 10);
        ov208_func_021C0788(heap, p, key);
        ov208_func_021C08E8(heap, p, key);
        ov208_func_021C0B10(heap, p, key);
        ov208_func_021C1AD4(heap, p, key);
        func_0204B688((struct Actor *)(*(u32 *)(p + W(0x64) * 4 + 0x5c)), 1);
        ov208_func_021C0C50(heap, p, key);
        if (W(0x90) == 1)
            ov208_func_021C0C8C(heap, p, key, 1);
        ov208_func_021BC758(W(0x420));
        ov208_func_021BC718(W(0x420));
        break;
    case 1:
        *seq = 2;
        ov208_func_021BC4F4(1, W(0x41c));
        ov208_func_021C24F0(heap, p, key);
        break;
    case 2:
        *seq = 3;
        ov208_func_021BC4D8(W(0x418));
        ov208_func_021BC6D8(W(0x420));
        if (ov208_func_021BDAD0(scene) != 2) {
            ov208_func_021BDAAC(scene, 0, 1, ov208_func_021BC3BC((char *)key) > 1);
            ov208_func_021BDAD4(scene, 0);
        } else {
            ov208_func_021BDBB8(scene, 1);
        }
        ov208_func_021BDC48(scene, 0);
        W(0x88) = 0;
        ov208_func_021BDC14(scene, func_02012BF8(ov208_func_021BC3A4(key), 18));
        if (ov208_func_021BE840(icon) != 2) {
            ov208_func_021BE82C(icon, 1);
            ov208_func_021BE844(icon);
        }
        break;
    case 3:
        if (ov208_func_021BC4C8(W(0x418)) == 0 && ov208_func_021BC6C8(W(0x420)) == 0
            && ov208_func_021BDAD0(scene) == 2 && ov208_func_021BE840(icon) == 2) {
            ov208_func_021BDBA0(scene);
            ov208_func_021C2458(heap, p, key);
            ov208_func_021C1D0C(heap, p, key);
            *seq = 4;
        }
        break;
    case 4:
        if (W(0x84) == 0) {
            ov208_func_021BDC48(scene, 1);
            W(0x88) = 1;
            *seq = 5;
        }
        break;
    case 5:
        if (W(0x424) != 0) {
            ov208_func_021C1D24(heap, p, key);
            *seq = 6;
        } else {
            if (W(0x90) == 1)
                ov208_func_021C23BC(p);
            ov208_func_021C10B8(heap, p, key);
        }
        break;
    case 6:
        if (W(0x84) == 0) {
            ov208_func_021C24A4(heap, p, key);
            *seq = 7;
            ov208_func_021BC4E4(W(0x418));
            ov208_func_021BC6F8(W(0x420));
            ov208_func_021BE854(icon);
            if (W(0x424) == 2)
                ov208_func_021BDAE8(scene, 0);
        }
        break;
    case 7:
        ready = 0;
        if (ov208_func_021BC4C8(W(0x418)) == 0 && ov208_func_021BC6C8(W(0x420)) == 0
            && ov208_func_021BE840(icon) == 0) {
            if (W(0x424) == 2) {
                if (ov208_func_021BDAD0(scene) == 0)
                    ready = 1;
            } else {
                ready = 1;
            }
        }
        if (ready)
            *seq = 8;
        break;
    case 8:
        *seq = 9;
        ov208_func_021C252C(heap, p, key);
        ov208_func_021BC508(1, W(0x41c));
        break;
    case 9:
        ov208_func_021C0130(heap, p, key);
        func_0207D4B0(1, 0, 0);
        for (k = 0; k < 2; k++) {
            func_020403F4((u8)data_021C8618[k].bg);
            func_0203FCA0(data_021C8618[k].bg, &data_021C8618[k].tmpl, data_021C8618[k].type);
            func_020414AC(data_021C8618[k].bg);
            func_02040588(data_021C8618[k].bg, data_021C8618[k].on);
        }
        return 1;
    }
    if (*seq >= 2) {
        ov208_func_021BC99C(W(8));
        ov208_func_021C0968(heap, p, key);
        ov208_func_021C0A8C(heap, p, key);
    }
    ov208_func_021C1810(heap, p, key);
    ov208_func_021BC46C(W(0x418), W(0x41c));
    ov208_func_021BC678(W(0x420));
    ov208_func_021C0714(heap, p, key);
    return 0;
}
