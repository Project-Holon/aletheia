/*
 * function: func_02204C24
 * address:  0x02204C24
 * packet:   pkt_02204C24
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ov067_id 0x00000043 data
 *   func_0203064C 0x0203064C arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02040588 0x02040588 arm
 *   func_0204047C 0x0204047C arm
 *   func_02040EBC 0x02040EBC arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_022058F8 0x022058F8 thumb ov195
 *   func_02205A34 0x02205A34 thumb ov195
 *   func_022051FC 0x022051FC thumb ov195
 *   func_02205530 0x02205530 thumb ov195
 *   func_02205010 0x02205010 thumb ov195
 *   func_02205070 0x02205070 thumb ov195
 *   func_02205C74 0x02205C74 thumb ov195
 *   func_0220871C 0x0220871C thumb ov195
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct App {
    u8 pad00[8];
    u16 f08;
    u8 f0a;
    u8 f0b;
    u8 pad0c[4];
    u32 f10;
} App;

typedef struct Scene {
    u16 pad00;
    u16 heap;
    void *f04;
    u32 f08;
    void *f0c;
    void *f10;
    u8 pad14[0x28 - 0x14];
    u32 f28;
    u8 pad2c[0x60 - 0x2c];
    u32 f60;
    u8 pad64[0x9c - 0x64];
    u32 f9c;
    u8 padA0[0x104 - 0xa0];
    void *f104;
    void *f108;
} Scene;

extern void func_0203064C(u32 parent, u32 id, u32 size);
extern u8 ov067_id[];
typedef signed int     s32;
struct Anim;
struct Owner;
extern int func_02034AC4(s32 handle);
extern void func_02040588(u32 which, u32 enable);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040EBC(u32 a0, u32 a1);
extern void func_0207D63C(int, int, int, int, int);
extern u32 func_0201D7EC(u32 a, u32 b, u32 c, u32 d, u16 heap);
extern void *func_0201C440(u16 heap);
extern char *func_022058F8(u32 a, u32 b);
extern void func_02205A34(void);
extern void func_022051FC(App *a, Scene *s);
extern void func_02205530(App *a, Scene *s);
extern void func_02205010(App *a, Scene *s);
extern void func_02205070(App *a, Scene *s);
extern struct Owner *func_02205C74(u16 heap, u32 f08, void *res0, u16 f0c);
extern struct Anim *func_0220871C(u16 heap, u32 x);

void func_02204C24(App *a, Scene *s)
{
    u8 i;
    u8 b;

    func_0203064C(1, 0x68, 0x70000);
    s->heap = 0x68;
    func_02034AC4((u32)ov067_id);
    for (i = 0; i <= 7; i++)
        func_02040588(i, 0);
    s->f04 = func_022058F8(1, s->heap);
    func_02205A34();
    s->f08 = func_0201D7EC(0x17, 0, 0, 0, s->heap);
    s->f0c = func_0201C440(s->heap);
    func_022051FC(a, s);
    s->f9c = 0;
    func_02205530(a, s);
    func_02205010(a, s);
    s->f60 = 0;
    if (s->f28 == 0)
        func_02205070(a, s);
    func_0204047C(0, 2);
    func_0204047C(2, 1);
    func_0204047C(1, 0);
    func_0204047C(4, 2);
    func_02040588(0, 1);
    func_02040588(2, 1);
    func_02040588(4, 1);
    func_02040EBC(0, 0);
    func_02040EBC(4, 0);
    if (s->f28 == 0) {
        b = a->f0b;
        if (b == 8 || (u8)(b + 0xef) <= 1)
            a->f10 = 0;
    }
    if (s->f28 == 0)
        s->f104 = func_02205C74(s->heap, 0, s->f10, a->f08);
    else
        s->f104 = func_02205C74(s->heap, 1, s->f10, a->f08);
    if (s->f28 == 0)
        s->f108 = func_0220871C(s->heap, 0);
    else
        s->f108 = func_0220871C(s->heap, 1);
    func_0207D63C(0x04000050, 1, 0x3e, 0, 0);
}
