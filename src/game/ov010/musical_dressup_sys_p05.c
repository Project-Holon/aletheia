/*
 * file:     musical_dressup_sys_p05.c
 * unit:     yes
 * function: func_021569EC, func_02156A3C
 * address:  0x021569EC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021568E8  0x021568E8  thumb  ov010
 *   func_021568A8  0x021568A8  thumb  ov010
 *   func_02157374  0x02157374  thumb  ov010
 *   func_021FCE28  0x021FCE28  thumb  ov132
 *   func_02008550  0x02008550  thumb
 *   func_02157384  0x02157384  thumb  ov010
 *   func_02012944  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 */
struct Deal;
struct Sub0200852CObj;
struct MsgBank;
struct Rec;
struct Table;
struct U16Vec;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef short s16;

typedef struct Work {
    u8 pad00[4];
    void *f04;          /* 0x04 */
    u8 pad08[0x14 - 0x08];
    u32 f14;            /* 0x14 */
    u32 f18;            /* 0x18 */
    u8 pad1C[0x28 - 0x1C];
    void *f28;          /* 0x28 */
    u8 pad2C[0x38 - 0x2C];
    void *f38;          /* 0x38 */
    u8 pad3C[0x4C - 0x3C];
    u8 f4c;             /* 0x4C */
} Work;

extern u8 func_021568E8(Work *w, u8 j);
extern u8 func_021568A8(Work *w, u8 n);
extern u8 func_02157374(struct Deal *d, u8 i);
extern int func_021FCE28(char *, u32);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02157384(struct Table *, int);
extern u8 *func_02012944(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
u8 func_021569EC(Work *w, u8 j);
void func_02156A3C(Work *w, u8 j, void *ws, u32 slot);


/*
 * Result class of member j: 0 for the local player, 1 or 4 from the
 * link peer record when linked, else the table value of its slot.
 *
 * Byte-correct. Blocker: 0x021FCE28 (ov132) has no func_ label.
 */
u8 func_021569EC(Work *w, u8 j)
{
    u8 k = func_021568E8(w, j);
    void *p;

    if (j == w->f4c)
        return 0;
    if (w->f14 == 1) {
        p = (void *)func_021FCE28(w->f28, k);
        if (p != 0) {
            if (func_02008550(p) == 0)
                return 1;
            return 4;
        }
    }
    return func_02157374(w->f38, func_021568A8(w, k));
}


void func_02156A3C(Work *w, u8 j, void *ws, u32 slot)
{
    int done = 0;
    u8 k = func_021568E8(w, j);
    void *p;

    if (j == w->f4c) {
        func_0201F02C(ws, slot, func_02012944(w->f04));
        done = 1;
    } else if (w->f14 == 1) {
        p = (void *)func_021FCE28(w->f28, k);
        if (p != 0) {
            func_0201F02C(ws, slot, p);
            done = 1;
        }
    }
    if (!done) {
        u8 n = func_02157384(w->f38, func_021568A8(w, k));
        void *bank = func_02045B38(0, 2, 0x4C, 4);
        void *str = func_02045EC0(bank, n);

        func_0201EE0C(ws, slot, str, 0, 1, 2);
        func_02045808(str);
        func_02045C04(bank);
    }
}
