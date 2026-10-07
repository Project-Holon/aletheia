/*
 * file:     field_place_name_p05.c
 * unit:     yes
 * function: func_021BC63C, func_021BC654, func_021BC664, func_021BC6B4, func_021BC6D0, func_021BC6E8
 * address:  0x021BC63C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BC704  0x021BC704  thumb  ov021
 *   func_021BD07C  0x021BD07C  thumb  ov021
 *   func_021BC5E4  0x021BC5E4  thumb  ov021
 *   func_021BD090  0x021BD090  thumb  ov021
 *   func_021BD094  0x021BD094  thumb  ov021
 *   func_020493D4  0x020493D4  arm
 *   func_02030734  0x02030734  arm
 *   func_0204932C  0x0204932C  arm
 *   func_02062A98  0x02062A98  arm
 */
struct ArcFile;
struct NitroFileHeader;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct S {
    char pad[0x14c];
    int a;
    int b;
} S;

typedef struct {
    char pad[0x14C];
    void *f14C;
    int f150;
} Obj_021BC6B4;

typedef struct {
    char pad[0xC];
    int fC;
} Inner;

typedef struct {
    char pad[0x150];
    Inner *f150;
} Obj_021BC6D0;

typedef struct {
    char pad[0x28];
    int f28;
} Obj_021BC6E8;

extern void func_020414AC(int a);
extern void func_021BC704(void *p);
extern void func_021BD07C(void *p);
extern void func_021BC5E4(int *p);
extern u16 func_021BD090(u8 *p);
extern u32 func_021BD094(u8 *p);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern u32 func_020307B0(void *p);
extern void func_02040E78(u32 r7, void *r6, u32 r5, u32 r4);
extern u32 func_0203FA08(u32 layer, u32 size, u32 top);
void func_021BC63C(void *p);
void func_021BC654(u8 *p);
void func_021BC664(S *p);
void func_021BC6B4(Obj_021BC6B4 *p);
void func_021BC6D0(Obj_021BC6D0 *p);
void func_021BC6E8(Obj_021BC6E8 *p);


void func_021BC63C(void *p)
{
    func_020414AC(3);
    func_021BC704(p);
    func_021BD07C(p);
}


void func_021BC654(u8 *p)
{
    func_021BC63C(p);
    func_021BC5E4((int *)p);
}


void func_021BC664(S *p)
{
    int r4, r6, h;

    r4 = func_021BD090((u8 *)((int)p));
    r6 = func_021BD094((u8 *)((int)p));
    h = (int)func_02030734(r4, func_020493D4((struct ArcFile *)r6, 1), 0, (const char *)0x021DE354, 0x2c8);
    p->a = h;
    func_0204932C((struct ArcFile *)r6, 1, (void *)h);
    func_02062A98((struct NitroFileHeader *)p->a, (void **)((int)&p->b));
}


void func_021BC6B4(Obj_021BC6B4 *p)
{
    if (p->f14C != 0) {
        func_020307B0(p->f14C);
        p->f14C = 0;
        p->f150 = 0;
    }
}


void func_021BC6D0(Obj_021BC6D0 *p)
{
    func_02040E78(3, (void *)p->f150->fC, 0x20, 0);
}


void func_021BC6E8(Obj_021BC6E8 *p)
{
    if (p->f28 == -1) {
        p->f28 = func_0203FA08(3, 0x20, 0);
    }
}
