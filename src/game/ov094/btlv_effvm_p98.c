/*
 * file:     btlv_effvm_p98.c
 * unit:     yes
 * function: func_022053DC, func_0220558C
 * address:  0x022053DC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D5528 0x021D5528 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_02204CC0 0x02204CC0 thumb ov094
 *   func_02205F88 0x02205F88 thumb ov094
 *   func_02021848 0x02021848 thumb
 *   d_0220A386 0x0220A386 data a1
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201DE00 0x0201DE00 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_02021728 0x02021728 thumb
 *   func_020215BC 0x020215BC thumb
 */
#include "../../matched/include/Obj00168.h"
#include "../../matched/include/Obj02440.h"

#define INDEX (((Flags *)m)->index)
#define OBJECT (*(u8 **)(m + INDEX * 4 + 0x2a4))
struct QG;
struct Slots;
struct Work;
struct PalAnmSlot;
struct WordSet;
struct MsgBank;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef struct { u16 value[4]; u8 a[4], b[4]; u8 pad10[8]; } Buffer;

typedef struct { u8 first, second; } Palette;

typedef struct { char pad[0x68]; u32 lo : 19; u32 index : 2; } Flags;

extern u8 func_021D5448(struct QG *p);
extern u16 func_021D5528(u8 *, u8, u8 *, u8 *);
extern int func_021D5B68(void *);
extern void func_02204CC0(struct Work *p, const struct Slots *q);
extern void func_02205F88(char *p);
extern int func_02021848(void *, u16, u16, s16, u8, u8, u16, void *);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201DE00(u8 *, u8 *, u8 *);
extern void func_0201DD78(u32, u32, u32);
extern void func_0201EFA4(u32, u32, u32, u32, u32, u32);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern int func_021F86E0(void);
extern int func_02021728(char *, int);
extern void func_020215BC(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
void func_022053DC(char *m);
void func_0220558C(char *s, const int *b);
extern const Palette d_0220A386[];

/*
 * lever: 022053DE reserves 0x28 bytes: 16 outgoing argument bytes plus
 *   a 24-byte local. Only its first 16 bytes are read/initialized here;
 *   pad10 preserves the observed allocation without naming unknown fields.
 *   Palette field reads retain the A386/A387 pools as one extern plus addend.
 */
void func_022053DC(char *m)
{
    int i;
    Buffer buf;
    for (i = 0; i < 4; i++) {
        buf.value[i] = 0;
        buf.a[i] = 0;
        buf.b[i] = 0;
    }
    for (i = 0; i < func_021D5448((struct QG *)OBJECT); i++)
        buf.value[i] = func_021D5528(OBJECT, i, &buf.a[i], &buf.b[i]);
    func_02204CC0((struct Work *)m, (const struct Slots *)(&buf));
    ((struct Obj00168 *)m)->f25F = d_0220A386[INDEX].first;
    ((struct Obj00168 *)m)->f260 = d_0220A386[INDEX].second;
    ((struct Obj00168 *)m)->f220 = 1;
    for (i = 0; i < 4; i++) {
        if (*(int *)(m + INDEX * 16 + i * 4 + 0x2b0) == 1)
            ((struct Obj00168 *)m)->f220 = 0;
    }
    if (func_021D5B68(OBJECT)) {
        for (i = 0; i < 4; i++)
            *(u8 *)(m + i + 0x25a) = 0;
        ((struct Obj00168 *)m)->f220 = 0;
        func_02021848(((struct Obj00168 *)m)->f64, 2, 0x3e00, 0, 8, 8, 0, ((struct Obj00168 *)m)->f0);
        func_02021848(((struct Obj00168 *)m)->f64, 8, 0x700, 0, 8, 8, 0, ((struct Obj00168 *)m)->f0);
        return;
    }
    if (((struct Obj00168 *)m)->f220 == 1) {
        ((struct Obj00168 *)m)->f25A = 1;
        func_02205F88(m);
        func_02021848(((struct Obj00168 *)m)->f64, 2, 0x3e00, 0, 8, 8, 0, ((struct Obj00168 *)m)->f0);
        func_02021848(((struct Obj00168 *)m)->f64, 8, 0x700, 0, 8, 8, 0, ((struct Obj00168 *)m)->f0);
        return;
    }
    func_02021848(((struct Obj00168 *)m)->f64, 2, 0x3e00, 0, 0, 0, 0, ((struct Obj00168 *)m)->f0);
    func_02021848(((struct Obj00168 *)m)->f64, 8, 0x700, 0, 0, 0, 0, ((struct Obj00168 *)m)->f0);
}

/*
 * trailing: 022056B2..022056B4 is two-byte alignment padding.
 * blocker (cleared 2026-10-01, arm9 leaf filed): ARM9 0x02021728 lacks an outside witness at +010C.
 * Verified EXACT C copied from ov029_func_021F0DB4.c:
 * int func_02021728(char *p, int i) { return *(int *)(p + i * 0x14); }
 */
void func_0220558C(char *s, const int *b)
{
    int h;
    void *v;
    void *w;
    void *extra;
    u8 c[3];
    h = (int)func_0201EC64(((struct Obj02440 *)s)->f240);
    v = func_020457B0(8, ((struct Obj02440 *)s)->f240);
    w = func_02045EC0(((struct Obj02440 *)s)->f5C, 6);
    func_0201DE00(&c[2], &c[1], &c[0]);
    func_0201DD78(9, 10, 0);
    func_0201EFA4(h, 0, b[2], 3, 2, 1);
    func_0201F250((void *)h, v, w);
    func_0201C7A4((void *)(((struct Obj02440 *)s)->f22C), 0x8c, 8, v, (void *)(((struct Obj02440 *)s)->f224));
    if (b[0] != b[1])
        func_0201DD78(7, 8, 0);
    func_0201EFA4(h, 0, b[1], 3, 2, 1);
    func_0201F250((void *)h, v, w);
    func_0201C7A4((void *)(((struct Obj02440 *)s)->f22C), 0x60, 8, v, (void *)(((struct Obj02440 *)s)->f224));
    func_0201DD78(1, 2, 0);
    extra = func_02045EC0(((struct Obj02440 *)s)->f5C, 7);
    func_0201C7A4((void *)(((struct Obj02440 *)s)->f22C), 0x7c, 8, extra, (void *)(((struct Obj02440 *)s)->f224));
    func_02045808(extra);
    func_0201DD78(c[2], c[1], c[0]);
    func_0201ED04((struct WordSet *)h);
    func_02045808(w);
    func_02045808(v);
    func_020215BC((struct PalAnmSlot *)(((struct Obj02440 *)s)->f64), (u16 *)(func_02021728((char *)func_021F86E0(), 1) + 0x40), 1, 0x70, 0x20);
}
