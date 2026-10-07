/*
 * file:     shinka_demo_p02.c
 * unit:     yes
 * function: func_02204C24, func_02204D5C
 * address:  0x02204C24
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   func_02208770  0x02208770  thumb
 *   func_02205D28  0x02205D28  thumb
 *   func_02205100  0x02205100  thumb
 *   func_0220506C  0x0220506C  thumb
 *   func_02205580  0x02205580  thumb
 *   func_022052E8  0x022052E8  thumb
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02205A84  0x02205A84  thumb
 *   func_022059A0  0x022059A0  thumb
 *   func_02034A5C  0x02034A5C  arm
 *   func_020306F0  0x020306F0  arm
 */
struct Anim;
struct Owner;
struct GfFont;
struct PrintSys;
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

typedef signed int     s32;

extern void func_0203064C(u32 parent, u32 id, u32 size);
extern int func_02034AC4(s32 handle);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040EBC(u32 a0, u32 a1);
extern void func_0207D63C(int, int, int, int, int);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern char *func_022058F8(u32 a, u32 b);
extern void func_02205A34(void);
extern void func_022051FC(int a, char *b);
extern void func_02205530(int a, char *b);
extern void func_02205010(int a, char *b);
extern void func_02205070(int a, char *b);
extern struct Owner *func_02205C74(u16 heap, u32 f08, void *res0, u16 f0c);
extern struct Anim *func_0220871C(u16 heap, u32 x);
extern void func_02208770(char *a);
extern void func_02205D28(char *p);
extern void func_02205100(void *unused, char *p);
extern void func_0220506C(int, int *);
extern void func_02205580(void *unused, char *p);
extern void func_022052E8(int, int *);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern void func_02205A84(int);
extern void func_022059A0(char *p);
extern void func_02034A5C(int);
extern void func_020306F0(unsigned int);
void func_02204C24(App *a, Scene *s);
void func_02204D5C(int a, int *p);
extern u8 ov067_id[];


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
    s->f08 = (u32)func_0201D7EC(0x17, 0, 0, 0, s->heap);
    s->f0c = (void *)func_0201C440((void *)s->heap);
    func_022051FC((int)a, (char *)s);
    s->f9c = 0;
    func_02205530((int)a, (char *)s);
    func_02205010((int)a, (char *)s);
    s->f60 = 0;
    if (s->f28 == 0)
        func_02205070((int)a, (char *)s);
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


/*
 * Leaf of the func_022040E0 dependency tree: the scene object's teardown.
 * It releases the two +0x104/+0x108 sub-objects, tears the controller links
 * down, then frees the +0x0c/+0x08/+0x04 allocations and drops the 0x43 /
 * 0x68 pools.
 */
void func_02204D5C(int a, int *p)
{
    func_02208770((char *)p[0x42]);
    func_02205D28((char *)p[0x41]);
    func_02205100((void *)a, (char *)p);
    func_0220506C(a, p);
    func_02205580((void *)a, (char *)p);
    func_022052E8(a, p);
    func_0201C6EC((struct PrintSys *)p[3]);
    func_0201C4C0((struct PrintSys *)p[3]);
    func_0201D83C((void *)p[2]);
    func_02205A84(p[1]);
    func_022059A0((char *)p[1]);
    func_02034A5C((int)ov067_id);
    func_020306F0(0x68);
}
