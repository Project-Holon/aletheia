/*
 * file:     unit_021BF050_p26.c
 * unit:     yes
 * function: func_021C2370, func_021C23B8
 * address:  0x021C2370
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02009864  0x02009864  thumb
 *   func_020099E4  0x020099E4  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_02156860  0x02156860  thumb  ov009
 */
struct Sub020097BCObj;
struct WordSet;
typedef struct {
    int pad00;
    void *f4;               /* 0x04 */
    char pad08[0xd4];
    int fdc;                /* 0xdc */
    char pade0[0x10];
    int ff0;                /* 0xf0 */
    char padf4[0x8b0 - 0xf4];
    int f8b0;               /* 0x8b0 */
} Work;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern void func_020099E4(struct Sub020097BCObj *obj, int i, void *dest);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern int func_02156860(int i);
void func_021C2370(Work *w, int id);
int func_021C23B8(int i);


void func_021C2370(Work *w, int id)
{
    int r;

    if (id != -1) {
        r = func_02009864(w->f4, id, 9);
        func_020099E4(w->f4, id, (void *)w->ff0);
        func_0201EE0C((struct WordSet *)w->f8b0, 0, (const void *)w->ff0, r, 1, 2);
    }
}

/*
 * Unblocked (was MATCH on one witness).
 * +0004 ABS32 func_02156860          -> resolved as `matched` by
 * src/matched/ov009_func_02156860.c after fixing the ISA/region hint: the
 * target is Thumb code in ov009 (ov010 opens with adds r3,r7,#0 and an
 * immediate branch), declared as `func_02156860 0x02156860 thumb ov009` below.
 */
int func_021C23B8(int i) { return func_02156860(i); }
