/*
 * function: SHINKA_DEMO_SetupScene
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
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02040588 0x02040588 arm
 *   func_0204047C 0x0204047C arm
 *   func_02040EBC 0x02040EBC arm
 *   func_0207D63C 0x0207D63C arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   SHINKA_DEMO_GRAPHIC_Create 0x022058F8 thumb ov195
 *   SHINKA_DEMO_GRAPHIC_SetupSubBg 0x02205A34 thumb ov195
 *   SHINKA_DEMO_SetupWindows 0x022051FC thumb ov195
 *   SHINKA_DEMO_CreateConfirmMenu 0x02205530 thumb ov195
 *   SHINKA_DEMO_LoadSprites 0x02205010 thumb ov195
 *   SHINKA_DEMO_CreateActors 0x02205070 thumb ov195
 *   SHINKA_DEMO_VIEW_Create 0x02205C74 thumb ov195
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

extern void GFL_HEAP_CreateChildHeap(u32 parent, u32 id, u32 size);
extern u8 ov067_id[];
typedef signed int     s32;
struct Anim;
struct Owner;
extern int func_02034AC4(s32 handle);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040EBC(u32 a0, u32 a1);
extern void func_0207D63C(int, int, int, int, int);
struct GfFont;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *p);
extern char *SHINKA_DEMO_GRAPHIC_Create(u32 a, u32 b);
extern void SHINKA_DEMO_GRAPHIC_SetupSubBg(void);
extern void SHINKA_DEMO_SetupWindows(int a, char *b);
extern void SHINKA_DEMO_CreateConfirmMenu(int a, char *b);
extern void SHINKA_DEMO_LoadSprites(int a, char *b);
extern void SHINKA_DEMO_CreateActors(int a, char *b);
extern struct Owner *SHINKA_DEMO_VIEW_Create(u16 heap, u32 f08, void *res0, u16 f0c);
extern struct Anim *func_0220871C(u16 heap, u32 x);

void SHINKA_DEMO_SetupScene(App *a, Scene *s)
{
    u8 i;
    u8 b;

    GFL_HEAP_CreateChildHeap(1, 0x68, 0x70000);
    s->heap = 0x68;
    func_02034AC4((u32)ov067_id);
    for (i = 0; i <= 7; i++)
        func_02040588(i, 0);
    s->f04 = SHINKA_DEMO_GRAPHIC_Create(1, s->heap);
    SHINKA_DEMO_GRAPHIC_SetupSubBg();
    s->f08 = (u32)GF_FONT_Create(0x17, 0, 0, 0, s->heap);
    s->f0c = (void *)PRINTSYS_QUE_Create((void *)s->heap);
    SHINKA_DEMO_SetupWindows((int)a, (char *)s);
    s->f9c = 0;
    SHINKA_DEMO_CreateConfirmMenu((int)a, (char *)s);
    SHINKA_DEMO_LoadSprites((int)a, (char *)s);
    s->f60 = 0;
    if (s->f28 == 0)
        SHINKA_DEMO_CreateActors((int)a, (char *)s);
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
        s->f104 = SHINKA_DEMO_VIEW_Create(s->heap, 0, s->f10, a->f08);
    else
        s->f104 = SHINKA_DEMO_VIEW_Create(s->heap, 1, s->f10, a->f08);
    if (s->f28 == 0)
        s->f108 = func_0220871C(s->heap, 0);
    else
        s->f108 = func_0220871C(s->heap, 1);
    func_0207D63C(0x04000050, 1, 0x3e, 0, 0);
}
