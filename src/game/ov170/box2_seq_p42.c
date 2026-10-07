/*
 * file:     box2_seq_p42.c
 * unit:     yes
 * function: func_021ECDF4, func_021ECF78
 * address:  0x021ECDF4
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020275E4 0x020275E4 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_020275F8 0x020275F8 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_020275FC 0x020275FC thumb
 *   func_02027600 0x02027600 thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_020275E8 0x020275E8 thumb
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0202774C 0x0202774C thumb
 *   func_02027750 0x02027750 thumb
 *   func_02027754 0x02027754 thumb
 *   func_02027748 0x02027748 thumb
 *   func_0202776C 0x0202776C thumb
 *   func_02027770 0x02027770 thumb
 *   func_02027774 0x02027774 thumb
 *   func_02027768 0x02027768 thumb
 *   func_02049238 0x02049238 arm
 *   d_021EFD34 0x021EFD34 data a4
 *   func_021EBEE0 0x021EBEE0 thumb ov170
 *   func_020275EC 0x020275EC thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_021EC000 0x021EC000 thumb ov170
 */
#define SLOT(w, o) (*(void **)((w) + (o)))
struct Obj;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct { short x, y; unsigned char pad4[2], b6, b7; int a, b, c; unsigned short e, d; } Desc;

typedef unsigned char  u8;

extern unsigned func_020275E4(void);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern unsigned int func_020275F8(unsigned int a);
extern signed int func_0204A6C8(void *a, unsigned int b, unsigned int c, unsigned int a3, u16 flags);
extern u32 func_020275FC(u32 a);
extern u32 func_02027600(u32 a);
extern signed int func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern unsigned func_020275E8(void);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern int func_0202774C(int a);
extern int func_02027750(int a);
extern int func_02027754(int a);
extern int func_02027748(void);
extern int func_0202776C(int a);
extern int func_02027770(int a);
extern int func_02027774(int a);
extern int func_02027768(void);
extern void func_02049238(void *h);
extern void *func_021EBEE0(char *, const Desc *);
extern u8 func_020275EC(int i);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_021EC000(char *, int, int);
void func_021ECDF4(char *w);
void func_021ECF78(char *p);
extern const Desc d_021EFD34;


/*
 * Loads the box screen graphics from the shared archive into the work
 * slots at 0xA094 (seventeen palettes) and 0xA0FC..0xA160 (character,
 * cell and animation resources), then closes the archive.
 */
void func_021ECDF4(char *w)
{
    void *h;
    unsigned i;

    h = func_020490F4(func_020275E4(), 0x804C);
    for (i = 0; i < 0x11; i++)
        *(void **)(w + i * 4 + 0xA094) = (void *)func_0204A6C8(h, func_020275F8((unsigned char)i), (int)0, (int)1, (unsigned)0x4C);
    SLOT(w, 0xA144) = (void *)func_0204AF28(h, func_020275FC(2), func_02027600(2), 0x4C);
    SLOT(w, 0xA118) = (void *)func_0204ABF0(h, func_020275E8(), 1, 0, 0x4C);
    SLOT(w, 0xA100) = (void *)func_0204A6C8(h, func_0202774C(2), (int)0, (int)1, (unsigned)0x4C);
    SLOT(w, 0xA15C) = (void *)func_0204AF28(h, func_02027750(2), func_02027754(2), 0x4C);
    SLOT(w, 0xA12C) = (void *)func_0204ABF0(h, func_02027748(), 1, 0xA0, 0x4C);
    SLOT(w, 0xA104) = (void *)func_0204A6C8(h, func_0202776C(2), (int)0, (int)1, (unsigned)0x4C);
    SLOT(w, 0xA160) = (void *)func_0204AF28(h, func_02027770(2), func_02027774(2), 0x4C);
    SLOT(w, 0xA130) = (void *)func_0204ABF0(h, func_02027768(), 1, 0xC0, 0x4C);
    SLOT(w, 0xA0FC) = (void *)func_0204A6C8(h, func_0202774C(2), (int)0, (int)0, (unsigned)0x4C);
    SLOT(w, 0xA158) = (void *)func_0204AF28(h, func_02027750(2), func_02027754(2), 0x4C);
    SLOT(w, 0xA128) = (void *)func_0204ABF0(h, func_02027748(), 0, 0x1A0, 0x4C);
    func_02049238(h);
}

/*
 * Verified scratch-only with one --thumb, no --region: EXACT, 12 bytes.
 * symbols for blocker: d_0209FCF8 0x0209FCF8 data a1
 * extern const unsigned char d_0209FCF8[];
 * unsigned func_020275EC(unsigned char i) { return d_0209FCF8[i]; }
 */
void func_021ECF78(char *p)
{
    Desc d = d_021EFD34;
    unsigned i;
    for (i = 0; i < 0x11; i++) {
        d.a = i + 0x28;
        *(void **)(p + i * 4 + 0x9EE4) = func_021EBEE0(p, &d);
        func_0204B6F4(*(void **)(p + i * 4 + 0x9EE4), (unsigned)func_020275EC((unsigned char)i), 1);
        func_021EC000(p, i + 0x1C, 0);
    }
}
