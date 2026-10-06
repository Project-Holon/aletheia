/*
 * function: func_021C40DC
 * address:  0x021C40DC
 * packet:   pkt_ov111_021C40DC
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocking arm9 callees labelled and matched by seeds_3 (2026-09-28)
 *
 * symbols:
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
 *
 * Addresses are Black-image addresses.
 */

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
} Args;

typedef struct {
    u16 heap;
} Anim;

typedef struct {
    u16 heap;
    u8 pad2[0x24 - 2];
    Args *args;
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
} Work;

extern void func_021C59B0(const u8 *src, u8 *dst);
struct Node;
struct Obj;
struct S020315D4;
struct Sub0200852CObj;
struct Sub020089A8Obj;
extern void *func_02012F5C(void **h);
extern void *func_020089CC(void *p);
extern void func_02082D44(const void *src, void *dst, u32 size);
extern u8 *func_02012944(void *p);
extern void func_02008558(struct Sub0200852CObj *obj, u8 value);
extern void func_02008A14(void *p, u32 v);
extern void func_02008A1C(struct Sub020089A8Obj *obj, u8 value);
extern void func_0202DC08(struct Obj *p);
extern void func_021C5874(void);
extern void func_021C42C0(Work *p);
extern void func_021C6F4C(Anim *a);
extern u32 func_020307B0(void *p);
extern void func_021C60A0(Work *p);
extern void func_021C46F0(void);
extern void func_02030EAC(struct Node *n);
struct S02031140;
extern void func_02031140(struct S02031140 *p);
extern void func_020355D8(u32 v);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);

int func_021C40DC(void *man, int *state, Args *args, Work *p)
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
