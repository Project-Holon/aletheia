/*
 * file:     unit_021BA81C_p02.c
 * unit:     yes
 * function: func_021BA874, func_021BA8BC
 * address:  0x021BA874
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
 *   func_0201F7A8  0x0201F7A8  thumb
 *   sub_020452E8  0x020452E8  arm
 */
struct Sub020097BCObj;
struct WordSet;
struct Descriptor;
typedef struct {
    int pad00;
    void *f4;               /* 0x04 */
    char pad08[0xd4];
    int fdc;                /* 0xdc */
    char pade0[0x10];
    int ff0;                /* 0xf0 */
} Work;

typedef unsigned int   u32_021BA874;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021BA8BC;

typedef signed short   s16;

typedef int BOOL;

extern u32_021BA874 func_02009864(const struct Sub020097BCObj *obj, u32_021BA874 i, u32_021BA874 field);
extern void func_020099E4(struct Sub020097BCObj *obj, int i, void *dest);
extern void func_0201EE0C(struct WordSet *p, u32_021BA874 i, const void *src, u32_021BA874 n, u32_021BA874 f, u32_021BA874 c);
extern void func_0201F7A8(void *desc, u32_021BA8BC kind);
extern u32_021BA8BC sub_020452E8(struct Descriptor *d);
void func_021BA874(Work *w, int id);
int func_021BA8BC(void *p);


void func_021BA874(Work *w, int id)
{
    int r;

    if (id != -1) {
        r = func_02009864(w->f4, id, 9);
        func_020099E4(w->f4, id, (void *)w->ff0);
        func_0201EE0C((struct WordSet *)w->fdc, 0, (const void *)w->ff0, r, 1, 2);
    }
}


int func_021BA8BC(void *p)
{
    if (p != 0) {
        func_0201F7A8(p, 0);
        sub_020452E8(p);
    }

    return 0;
}
