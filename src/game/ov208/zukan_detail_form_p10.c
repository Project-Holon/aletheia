/*
 * file:     zukan_detail_form_p10.c
 * unit:     yes
 * function: func_021C5B00, func_021C5C64, func_021C5CF0
 * address:  0x021C5B00
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
 *   func_02014CEC 0x02014CEC thumb
 *   ov208_func_021C569C 0x021C569C thumb ov208
 *   func_021C51C8 0x021C51C8 thumb ov208
 *   func_021C80AC 0x021C80AC thumb ov208
 *   func_02015C48 0x02015C48 thumb
 *   func_021C7534 0x021C7534 thumb ov208
 *   func_021C51A0  0x021C51A0  thumb
 *   func_021C4EAC  0x021C4EAC  thumb
 *   ov208_func_021C6A10  0x021C6A10  thumb
 *   func_0204B3DC        0x0204B3DC  arm
 *   func_021C53E0        0x021C53E0  thumb
 *   ov208_func_021C57A4  0x021C57A4  thumb
 */
#define W(o) (*(u32 *)(p + (o)))
#define MDL(i) ((struct Ov208Mdl *)(p + 0xc + (i) * sizeof(struct Ov208Mdl)))
#define H(o) (*(u16 *)(p + (o)))
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int fx32;

typedef struct { fx32 x; fx32 y; fx32 z; } Vec;

struct Ov208Mdl {
    u32 obj;
    u32 f4;
    u8 pos[0x3c];
};

struct Ov208Ent {
    u32 kind;
    u32 mode;
    u16 pad8;
    u8  forms;
    u8  padb;
    u16 species;
    u16 pade;
};

struct Ov208Menu {
    u32 owner;
    u8  pad4[0x124];
    u32 arc;
    u32 res[2];
    u32 j;
    u32 k;
    u32 obj[2];
    int cur;
    struct Ov208Ent ents[8];
    u8  pad1c8[0x386];
    u16 sel;
};

extern void func_02014CEC(u8 *p, u32 value);
extern void ov208_func_021C569C(u16 *heap, u8 *p, int key, int a, int b, int pose, u16 idx);
extern void func_021C51C8(u32 st, int i, u8 *p);
extern void func_021C80AC(int a, int b, int c);
extern void func_02015C48(void *p, u32 *src);
extern void func_021C7534(u16 *heap, u8 *p, int key);
extern void func_021C51A0(char *p, int a);
extern void func_021C4EAC(void *a0, u8 *p, int key);
extern void ov208_func_021C6A10(void *a0, u8 *p, int key);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_021C53E0(int a, int b);
extern void ov208_func_021C57A4(u16 *heap, struct Ov208Menu *p, int key, u16 idx);
void func_021C5B00(u16 *heap, u8 *p, int key);
void ov208_func_021C5C64(void *a0, u8 *p, int key);
void ov208_func_021C5CF0(u16 *heap, struct Ov208Menu *p, int key);

/*
 * note: 2026-10-05 (D4-11): EXACT. pose set with the goto form of sibling 021C595C;
 *   MDL(i) as one byte offset (p + 0xc + i*0x44) so MDL(1) folds to p+0x50.
 */
void func_021C5B00(u16 *heap, u8 *p, int key)
{
    Vec v;
    int a;
    int b;
    int pose;
    a = 0;
    func_02014CEC((u8 *)W(8), 0);
    if (MDL(0)->obj != 0) a = 4;
    b = 1;
    if (MDL(1)->obj != 0) b = 4;
    pose = 0;
    if (W(0x6B8) != 4) goto skip;
    if (*(u16 *)(p + 0x548) < 2) goto skip;
    pose = 1;
skip:
    ov208_func_021C569C(heap, p, key, a, b, pose, *(u16 *)(p + 0x54E));
    if (a != 4) func_021C51C8(MDL(0)->f4, 0, p);
    else {
        func_021C80AC((int)MDL(0), pose, (int)(&v));
        func_02015C48((void *)MDL(0)->obj, (u32 *)(&v));
    }
    if (b != 4) func_021C51C8(MDL(1)->f4, 1, p);
    else {
        func_021C80AC((int)MDL(1), pose, (int)(&v));
        func_02015C48((void *)MDL(1)->obj, (u32 *)(&v));
    }
    a = 2;
    if (MDL(2)->obj != 0) a = 4;
    b = 3;
    if (MDL(3)->obj != 0) b = 4;
    ov208_func_021C569C(heap, p, key, a, b, 2, *(u16 *)(p + 0x550));
    if (a != 4) func_021C51C8(MDL(2)->f4, 2, p);
    else {
        func_021C80AC((int)MDL(2), 2, (int)(&v));
        func_02015C48((void *)MDL(2)->obj, (u32 *)(&v));
    }
    if (b != 4) func_021C51C8(MDL(3)->f4, 3, p);
    else {
        func_021C80AC((int)MDL(3), 2, (int)(&v));
        func_02015C48((void *)MDL(3)->obj, (u32 *)(&v));
    }
    func_02014CEC((u8 *)W(8), W(0x120));
    if (W(0x6B8) == 0) {
        W(0x6C8) = 1;
        func_021C7534(heap, p, key);
    }
}


void ov208_func_021C5C64(void *a0, u8 *p, int key)
{
    int a;
    int b;

    func_021C51A0((char *)(p + 0x94), W(8));
    func_021C51A0((char *)(p + 0xd8), W(8));
    a = W(0x124) != 0 ? 2 : 4;
    b = W(0x124) != 0 ? 4 : 3;
    ov208_func_021C569C(a0, p, key, a, b, 2, H(0x550));
    if (a != 4)
        func_021C51C8(W(0x98), 2, p);
    if (b != 4)
        func_021C51C8(W(0xdc), 3, p);
    func_021C4EAC(a0, p, key);
    ov208_func_021C6A10(a0, p, key);
}


void ov208_func_021C5CF0(u16 *heap, struct Ov208Menu *p, int key)
{
    if (p->obj[p->cur] != 0)
        func_0204B3DC((struct Obj *)p->obj[p->cur], 0);
    p->cur = (p->cur + 1) % 2;
    if (p->obj[p->cur] != 0) {
        if (p->obj[p->cur] != 0)
            func_021C53E0(p->res[p->cur], p->obj[p->cur]);
        p->obj[p->cur] = 0;
    }
    ov208_func_021C57A4(heap, p, key, p->sel);
}
