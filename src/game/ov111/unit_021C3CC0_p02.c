/*
 * file:     unit_021C3CC0_p02.c
 * unit:     yes
 * function: func_021C3F54, func_021C40DC, func_021C41C4
 * address:  0x021C3F54
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020221A4  0x020221A4  thumb
 *   func_021C56E8  0x021C56E8  thumb
 *   func_021C5718  0x021C5718  thumb
 *   func_021C5AEC  0x021C5AEC  thumb
 *   func_021C5F64  0x021C5F64  thumb
 *   func_021C3F18  0x021C3F18  thumb
 *   func_0204B98C  0x0204B98C  arm
 *   func_0202208C  0x0202208C  thumb
 *   func_021C4B9C  0x021C4B9C  thumb
 *   func_021C4E0C  0x021C4E0C  thumb
 *   func_0204A600  0x0204A600  arm
 *   func_0202DBC4  0x0202DBC4  thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_020310C4  0x020310C4  arm
 *   func_021C59B0  0x021C59B0  thumb  ov111
 *   func_02012F5C  0x02012F5C  thumb
 *   func_020089CC  0x020089CC  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_02012944  0x02012944  thumb
 *   func_02008558  0x02008558  thumb
 *   func_02008A14  0x02008A14  thumb
 *   func_02008A1C  0x02008A1C  thumb
 *   func_0202DC08  0x0202DC08  thumb
 *   func_021C5874  0x021C5874  thumb  ov111
 *   func_021C42C0  0x021C42C0  thumb  ov111
 *   func_021C6F4C  0x021C6F4C  thumb  ov111
 *   func_020307B0  0x020307B0  arm
 *   func_021C60A0  0x021C60A0  thumb  ov111
 *   func_021C46F0  0x021C46F0  thumb  ov111
 *   func_02030EAC  0x02030EAC  arm
 *   func_02031140  0x02031140  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201EC64  0x0201EC64  thumb
 */
struct Actor;
struct PrintSys;
struct Tcbl;
struct Node;
struct Obj;
struct S020315D4;
struct Sub0200852CObj;
struct Sub020089A8Obj;
struct S02031140;
struct GfFont;
struct MsgBank;
struct U16Vec;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
    u8 f4_6 : 1;
} Cfg;

typedef struct {
    Cfg *cfg;
    void *f4;
    u8 pad8[4];
    u32 fC;
    u32 f10;
} Args_021C3F54;

typedef struct {
    u8 x;
    u8 y;
    u8 size;
    u8 active;
} TouchPos;

typedef struct {
    u16 heap;
    u8 pad2[0x24 - 2];
    Args_021C3F54 *args;
    void *info;
    u8 pix[0x305C - 0x2C];
    u16 f305C;
    u16 f305E;
    u8 pad3060[0x3108 - 0x3060];
    void *f3108;
    void *f310C;
    void *f3110;
    u8 pad3114[0x31F8 - 0x3114];
    void *f31F8;
    u8 pad31FC[0x32B0 - 0x31FC];
    void *f32B0;
    u8 pad32B4[0x32CC - 0x32B4];
    void *f32CC;
    u8 pad32D0[0x32D6 - 0x32D0];
    u8 b32D6;
    u8 pad32D7[0x32EE - 0x32D7];
    TouchPos cur;
    TouchPos prev;
} Work_021C3F54;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
    u8 pad5;
    u8 b6;
    u8 pad7[0x48 - 7];
    u32 f48;
    u8 pad4C[0x74 - 0x4C];
    u8 bitmap[0x600];
} Info;

typedef struct {
    void *f0;
    void *f4;
    u32 f8;
} Args_021C40DC;

typedef struct {
    u16 heap;
} Anim;

typedef struct {
    u16 heap;
    u8 pad2[0x24 - 2];
    Args_021C40DC *args;
    Info *info;
    u8 pix[0x302C - 0x2C];
    void *f302C;
    u8 pad3030[0x3060 - 0x3030];
    u32 f3060;
    u8 pad3064[0x3070 - 0x3064];
    Anim anim;
    u8 pad3072[0x31D8 - 0x3072];
    void *f31D8;
    u8 pad31DC[0x31E8 - 0x31DC];
    void *f31E8;
    u8 pad31EC[0x31F4 - 0x31EC];
    void *f31F4;
    u32 f31F8;
    u8 pad31FC[0x32B0 - 0x31FC];
    void *f32B0;
} Work_021C40DC;

typedef struct {
    u16 heap;
    u8 pad2[0x31FC - 2];
    void *f31FC;
    void *f3200;
    void *f3204;
    void *f3208;
    void *f320C;
    void *f3210;
    void *f3214;
    void *f3218[3];
    void *f3224[2];
    void *f322C[26];
    void *f3294[5];
} Work_021C41C4;

extern u32 func_020221A4(void);
extern int func_021C56E8(Work_021C3F54 *p);
extern void func_021C5718(Work_021C3F54 *p, int sel, int *seq);
extern void func_021C5AEC(Work_021C3F54 *p);
extern int func_021C5F64(u8 *pix, TouchPos *cur, TouchPos *prev, int flush, const void *src, u8 clip, u8 side);
extern void func_021C3F18(Work_021C3F54 *p, int speed);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern int func_021C4B9C(Work_021C3F54 *p);
extern int func_021C4E0C(char *p);
extern void func_0204A600(void);
extern void func_0202DBC4(u8 *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_020310C4(struct Tcbl *p);
extern void func_021C59B0(const u8 *src, u8 *dst);
extern void *func_02012F5C(void **h);
extern void *func_020089CC(void *p);
extern void func_02082D44(const void *src, void *dst, u32 size);
extern u8 *func_02012944(void *p);
extern void func_02008558(struct Sub0200852CObj *obj, u8 value);
extern void func_02008A14(void *p, u32 v);
extern void func_02008A1C(struct Sub020089A8Obj *obj, u8 value);
extern void func_0202DC08(struct Obj *p);
extern void func_021C5874(void);
extern void func_021C42C0(Work_021C40DC *p);
extern void func_021C6F4C(Anim *a);
extern u32 func_020307B0(void *p);
extern void func_021C60A0(Work_021C40DC *p);
extern void func_021C46F0(void);
extern void func_02030EAC(struct Node *n);
extern void func_02031140(struct S02031140 *p);
extern void func_020355D8(u32 v);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct WordSet *func_0201EC64(u32 heap);
int func_021C3F54(void *proc, int *seq, int c, Work_021C3F54 *p);
int func_021C40DC(void *man, int *state, Args_021C40DC *args, Work_021C40DC *p);
void func_021C41C4(Work_021C41C4 *p);


/*
 * Addresses are Black-image addresses.
 */
int func_021C3F54(void *proc, int *seq, int c, Work_021C3F54 *p)
{
    switch (*seq) {
    case 0:
        if (func_020221A4()) {
            *seq = 1;
        }
        break;
    case 1:
        func_021C5718(p, func_021C56E8(p), seq);
        func_021C5AEC(p);
        if (p->args->cfg->f4_6) {
            func_021C3F18(p, func_021C5F64(p->pix, &p->cur, &p->prev, 1, p->pix, p->f305E, p->f305C));
        }
        break;
    case 2:
        if (func_0204B98C(p->f3108) == 0) {
            func_0202208C((void *)2, 4, 4, 0, 6, 1, p->heap);
            *seq = 4;
        }
        break;
    case 3:
        if (func_0204B98C(p->f310C) == 0) {
            func_0202208C((void *)2, 4, 4, 0, 6, 1, p->heap);
            *seq = 4;
        }
        break;
    case 4:
        if (func_020221A4()) {
            return 1;
        }
        break;
    case 5:
        if (func_021C4B9C(p)) {
            *seq = 1;
        }
        break;
    case 9:
        if (func_021C4E0C((char *)p)) {
            *seq = 1;
        }
        break;
    case 6:
        func_0202208C((void *)2, 4, 4, 0, 6, 1, p->heap);
        p->args->fC = 1;
        *seq = 4;
        break;
    case 7:
        if (func_0204B98C(p->f3110) == 0) {
            func_0202208C((void *)2, 4, 4, 0, 6, 1, p->heap);
            p->args->fC = 2;
            *seq = 4;
        }
        break;
    case 8:
        break;
    }
    p->b32D6++;
    if (p->b32D6 >= 0x100) {
        p->b32D6 = 0;
    }
    func_0204A600();
    func_0202DBC4(p->f32B0);
    func_0201C4E4(p->f32CC);
    if (p->f31F8) {
        func_020310C4(p->f31F8);
    }
    return 0;
}


/*
 * closed:   blocking arm9 callees labelled and matched by seeds_3 (2026-09-28)
 *
 * Addresses are Black-image addresses.
 */
int func_021C40DC(void *man, int *state, Args_021C40DC *args, Work_021C40DC *p)
{
    void *a;
    void *b;

    if (!p->info->f4_5) {
        func_021C59B0(p->pix, p->info->bitmap);
        func_02082D44(p->info->bitmap, func_020089CC(func_02012F5C(p->args->f4)), 0x600);
    }
    if (args->f8 != 0) {
        a = func_02012944(p->args->f4);
        b = func_02012F5C(p->args->f4);
        func_02008558(a, p->info->b6);
        func_02008A14(b, p->info->f48);
        func_02008A1C(b, p->info->f4_4);
    }
    func_0202DC08(p->f32B0);
    func_021C5874();
    func_021C42C0(p);
    func_021C6F4C(&p->anim);
    func_020307B0(p->f302C);
    func_020307B0(p->f31D8);
    func_020307B0(p->f31E8);
    func_021C60A0(p);
    func_021C46F0();
    func_02030EAC(p->f31F4);
    func_02031140((struct S02031140 *)p->f31F8);
    func_020355D8(p->f3060);
    func_020315D4(man);
    func_020306F0(0x27);
    return 1;
}


void func_021C41C4(Work_021C41C4 *p)
{
    int i;

    p->f31FC = func_0201D7EC(0x17, 0, 0, 0, p->heap);
    p->f3200 = func_02045B38(0, 2, 0xBB, p->heap);
    p->f3208 = func_020457B0(4, p->heap);
    p->f3210 = func_020457B0(0x20, p->heap);
    p->f3214 = func_020457B0(0x21, p->heap);
    p->f320C = func_020457B0(5, p->heap);
    func_02045CAC(p->f3200, 0x17, p->f320C);
    for (i = 0; i < 3; i++) {
        p->f3218[i] = func_02045EC0(p->f3200, i + 0x1A);
    }
    for (i = 0; i < 2; i++) {
        p->f3224[i] = func_02045EC0(p->f3200, i + 0x1D);
    }
    for (i = 0; i < 26; i++) {
        p->f322C[i] = func_02045EC0(p->f3200, i);
    }
    for (i = 0; i < 5; i++) {
        p->f3294[i] = func_02045EC0(p->f3200, i + 0x38);
    }
    p->f3204 = func_0201EC64(p->heap);
}
