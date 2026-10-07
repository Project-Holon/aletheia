/*
 * file:     field_menu_p04.c
 * unit:     yes
 * function: func_021A81DC, func_021A81EC, func_021A8200, func_021A8214
 * address:  0x021A81DC
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
 *   func_02188C98  0x02188C98  thumb
 *   func_0218DC6C  0x0218DC6C  thumb
 *   func_0218C7D8  0x0218C7D8  thumb
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Work_021A81EC {
    u8 pad00[0x2C];
    u8 step[10];
    u8 f36;
} Work_021A81EC;

typedef struct Work_021A8200 {
    u8 pad00[0x18];
    u16 f18;
    u8 pad1A[0x36 - 0x1A];
    u8 f36;
} Work_021A8200;

typedef struct {
    int pad[3];
    int fc;
} R;

typedef struct {
    R *f0;
    int pad[6];
    int f1c[3];
    int f28;
} S;

extern u32 func_02188C98(u8 *p);
extern u32 func_0218DC6C(u8 *p);
extern int func_0218C7D8(void *p, int b, int c);
u8 func_021A81DC(u32 a);
u8 func_021A81EC(Work_021A81EC *w);
void func_021A8200(Work_021A8200 *w);
void func_021A8214(S *s);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
u8 func_021A81DC(u32 a)
{
return *(u8 *)((u8 *)(((a + *(u8 *)((u8 *)((a + 54)))) + 44)));
}


/*
 * Unlabelled leaf: the Work step table entry after the current one
 * (step[f36 + 1]); func_021A81DC reads step[f36].
 */
u8 func_021A81EC(Work_021A81EC *w)
{
    return w->step[(u8)(w->f36 + 1)];
}


/*
 * Unlabelled leaf: advance the Work step index and clear its frame counter.
 */
void func_021A8200(Work_021A8200 *w)
{
    w->f36++;
    w->f18 = 0;
}


void func_021A8214(S *s)
{
    s->f28 = func_0218C7D8((void *)func_0218DC6C((u8 *)func_02188C98((u8 *)s->f0->fc)), 1, (int)s->f1c);
}
