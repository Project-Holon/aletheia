/*
 * file:     vs_multi_list_p03.c
 * unit:     yes
 * function: func_021F6B7C, func_021F6CE4, func_021F6D70, func_021F6EE8, func_021F6F24
 * address:  0x021F6B7C
 * region:   ov097
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_02045738 0x02045738 arm
 *   func_02045808 0x02045808 arm
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017F00 0x02017F00 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02043AF4 0x02043AF4 arm
 *   func_021F6F50 0x021F6F50 thumb ov097
 *   func_021F6F88 0x021F6F88 thumb ov097
 *   func_021F714C 0x021F714C thumb ov097
 */
#include "../../matched/include/Obj05257.h"
#include "../../matched/include/Obj07929.h"
#include "../../matched/include/Obj13675.h"

struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
struct Bmp;
struct P;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_021F6B7C;

typedef unsigned int u32;

typedef enum { ZERO } Zero;

typedef enum { INDEX_ZERO } Index;

typedef struct { struct Descriptor *text; unsigned char dirty; unsigned char pad05[3]; } Window;

typedef struct {
    unsigned char pad00[0x10];
    u32 ink;
    struct MsgBank *catalogue;
    struct WordSet *formatter;
    void *renderer;
    Window window[6];
} Owner;

typedef signed short   s16_021F6D70;

extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern u8 func_02045738(struct Descriptor *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C724(void *, u32, u32, u32, u32, u32, u16);
extern u32 func_02017E1C(void *, u32, u32);
extern u8 func_02017F00(void *);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201EFA4(struct WordSet *, u32, u32, u32, u32, u32);
extern void func_02043AF4(struct Bmp *, unsigned, unsigned, unsigned, unsigned, unsigned);
extern void func_021F6F50(void);
extern void func_021F6F88(int);
extern void func_021F714C(struct P *);
void func_021F6B7C(int p, int i);
void func_021F6CE4(Owner *a, Index b);
void func_021F6D70(char *p, int idx);
void func_021F6EE8(unsigned p, unsigned i);
void func_021F6F24(struct P *p);

static inline void print_text(int p, u32 windows, u32 dirty, int i, void *s, int x, int y, u16 color)
{
    void *owner = ((struct Obj13675 *)p)->f1C;
    func_0201C724(owner, (u32)func_02045770(*(void **)(windows + i * 8)), x, y, (u32)s, ((struct Obj13675 *)p)->fC, color);
    *(u8 *)(dirty + i * 8) = 1;
}

static inline void print_right(int p, u32 windows, u32 dirty, int i, void *window, u32 id, u16 color)
{
    void *s = func_02045EC0(((struct Obj07929 *)p)->f14, id);
    u32 font = ((struct Obj07929 *)p)->fC;
    u32 w = func_02045738(window);
    s16_021F6B7C x = (s16_021F6B7C)(w * 8 - func_0201D304(s, ((struct Obj07929 *)p)->fC, 0));
    void *owner = ((struct Obj07929 *)p)->f1C;
    func_0201C724(owner, (u32)func_02045770(*(void **)(windows + i * 8)), x, 7, (u32)s, font, color);
    *(u8 *)(dirty + i * 8) = 1;
    func_02045808(s);
}

/*
 * lever: Named monster base/index and byte gender if/else retain the original scheduling; inline print helpers retain owner spills.
 * note 2026-10-05 (wave D9r lane 131): removed the 2 dead first assignments
 * (`windows = p;` before `windows = p + 0x20;`; `dirty = p;` before `dirty =
 * p + 0x24;`). Game code has no line table, so these were stand-ins. The
 * plain single assignment gives EXACT in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void func_021F6B7C(int p, int i)
{
    u32 windows, dirty, mons, mi;
    u8 gender;
    void *window, *t, *s;
    windows = p + 0x20;
    window = *(void **)(windows + i * 8);
    t = func_020457B0(0xc, 0x8071);
    s = func_02045EC0(((struct Obj05257 *)p)->f14, 0);
    mons = p + 0xf8;
    mi = i * 4;
    func_0201EEF4(((struct Obj05257 *)p)->f18, 0, *(void **)(mons + mi));
    func_0201F250(((struct Obj05257 *)p)->f18, t, s);
    dirty = p + 0x24;
    print_text(p, windows, dirty, i, t, 0x20, 7, 0x3dc0);
    func_02045808(s);
    func_02045808(t);
    if (func_02017E1C(*(void **)(mons + mi), 0xad, 0) == 1 &&
        func_02017E1C(*(void **)(mons + mi), 0x4c, 0) == 0) {
        gender = func_02017F00(*(void **)(mons + mi));
        if (gender == 0) print_right(p, windows, dirty, i, window, 0x16, 0x2960);
        else if (gender == 1) print_right(p, windows, dirty, i, window, 0x17, 0x31a0);
    }
}


static inline void print_window(Owner *a, Index b, void *t)
{
    void *owner = a->renderer;
    func_0201C724(owner,
                  (u32)func_02045770(a->window[(u32)b].text), 8, 0x20, (u32)t,
                  a->ink, 0x3dc0);
    a->window[(u32)b].dirty = 1;
}

/*
 * lever: six Window records initialized by matched 021F6A98; direct per-field Owner.window[b] accesses retain index scaling and recompute the dirty-byte address.
 * checks: 1 every callee copied from its own matched definition; 2 021F6A98 initializes six 8-byte records and gives the fixed bound; 3 enum zero gave84, readonly header38; 4 struct-array-per-field idiom closes38 to EXACT; 5 fresh idiom directory and matched neighbours read.
 * permuter: historical once-only types300 consumed; no repeat in wave77.
 */
void func_021F6CE4(Owner *a, Index b)
{
    struct U16Vec *t;
    void *u;
    unsigned char z = ZERO;

    t = func_020457B0(0x20, 0x8071);
    u = func_02045EC0(a->catalogue, 0xb);
    func_0201EFA4(a->formatter, 0,
                  func_02017E1C(*(void **)((u32)a + (u32)b * 4 + 0xf8), 0x9e, 0), 3, z, 1);
    func_0201F250(a->formatter, t, u);
    print_window(a, b, t);
    func_02045808(u);
    func_02045808(t);
}


static inline u8 center_x(u32 w)
{
    return 0x5c - (w >> 1);
}


/*
 * lever: 2026-10-05 (wD9r lane136): w8 is a narrow local (u8). mwcc does not schedule the reload of a
 *   spilled narrow local above the outgoing stack stores, so the block-3 x sum comes after them as in the
 *   image; a u32 w8 reload is hoisted (25 bytes in waves D3 to D9r). The centre shift is unsigned
 *   (lsrs), so the u8 width is widened to u32 before the shift; a plain u8 `w8 >> 1` gives asrs. An inline
 *   helper `center_x(u32 w)` gives the same EXACT bytes. Diagnostic that found it: the block-2 s16 local x
 *   used as the block-3 operand gave the image order, a u32/int x did not.
 */
void func_021F6D70(char *p, int idx)
{
    void *buf;
    void *t1;
    void *t2;
    void *t3;
    u8 w8;
    u8 r7;
    u32 f1;
    u32 f2;
    s16_021F6D70 x;
    u32 f3;
    u32 h;

    buf = func_020457B0(0x20, 0x8071);
    t1 = func_02045EC0(*(void **)(p + 0x14), 0xc);
    w8 = func_0201D304(t1, *(u32 *)(p + 0x10), 0);
    r7 = center_x(w8);
    {
        u32 y;
        f1 = *(u32 *)(p + 0x1c);
        y = (u32)func_02045770((struct Descriptor *)(*(u32 *)(p + 0x20 + idx * 8)));
        func_0201C724((void *)f1, y, (s16_021F6D70)r7, 0x20, (u32)t1, *(u32 *)(p + 0x10), 0x3dc0);
    }
    *(u8 *)(p + 0x24 + idx * 8) = 1;
    func_02045808(t1);

    t2 = func_02045EC0(*(void **)(p + 0x14), 0xd);
    func_0201EFA4((struct WordSet *)(*(u32 *)(p + 0x18)), 0, func_02017E1C((void *)(*(u32 *)(p + 0xf8 + idx * 4)), 0xa0, 0), 3, 0, 1);
    func_0201F250((struct WordSet *)(*(u32 *)(p + 0x18)), buf, t2);
    {
        u32 y;
        h = *(u32 *)(p + 0x10);
        x = r7 - func_0201D304(buf, h, 0);
        f2 = *(u32 *)(p + 0x1c);
        y = (u32)func_02045770((struct Descriptor *)(*(u32 *)(p + 0x20 + idx * 8)));
        func_0201C724((void *)f2, y, x, 0x20, (u32)buf, h, 0x3dc0);
    }
    *(u8 *)(p + 0x24 + idx * 8) = 1;
    func_02045808(t2);

    t3 = func_02045EC0(*(void **)(p + 0x14), 0xd);
    func_0201EFA4((struct WordSet *)(*(u32 *)(p + 0x18)), 0, func_02017E1C((void *)(*(u32 *)(p + 0xf8 + idx * 4)), 0xa1, 0), 3, 0, 1);
    func_0201F250((struct WordSet *)(*(u32 *)(p + 0x18)), buf, t3);
    {
        u32 y;
        f3 = *(u32 *)(p + 0x1c);
        y = (u32)func_02045770((struct Descriptor *)(*(u32 *)(p + 0x20 + idx * 8)));
        func_0201C724((void *)f3, y, (s16_021F6D70)(r7 + w8), 0x20, (u32)buf, *(u32 *)(p + 0x10), 0x3dc0);
    }
    *(u8 *)(p + 0x24 + idx * 8) = 1;
    func_02045808(t3);
    func_02045808(buf);
}

void func_021F6EE8(unsigned p, unsigned i)
{
    unsigned base = p + 0x20;
    func_02043AF4(func_02045770(*(void **)(base + i * 8)), 0x40, 0x1b, 0x30, 1, 1);
    func_02043AF4(func_02045770(*(void **)(base + i * 8)), 0x40, 0x1c, 0x30, 1, 2);
}

void func_021F6F24(struct P *p)
{
    func_021F6F50();
    func_021F6F88((int)p);
    func_021F714C(p);
}
