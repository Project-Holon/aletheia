/*
 * file:     scrcmd_screeneffects_p15.c
 * unit:     yes
 * function: func_021AFBC4, func_021AFBEC
 * address:  0x021AFBC4
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
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 */
struct WordSet;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Ctx_021AFBC4 { u32 f0; u32 f4; u32 f8; u32 fc; u32 f10; u8 *pc; } Ctx_021AFBC4;

typedef signed int     s32;

typedef struct {
    char pad[0x14];
    u8 *cur;
} Ctx_021AFBEC;

extern void *func_0215A5F4(void *p);
extern void *func_02158F74(void *p);
extern unsigned int func_02159B10(void *a0, void *a1);
extern void func_0201F184(struct WordSet *p, u32 i, s32 v);
int func_021AFBC4(Ctx_021AFBC4 *s, u32 b);
int func_021AFBEC(Ctx_021AFBEC *a0, int a1, int (*fn)());


static inline u8 Ctx_ReadByte(Ctx_021AFBC4 *s)
{
    u8 v = *s->pc;

    s->pc++;
    return v;
}


int func_021AFBC4(Ctx_021AFBC4 *s, u32 b)
{
    u8 c = Ctx_ReadByte(s);
    u32 x = func_02159B10(s, (void *)b);

    func_0201F184(func_02158F74(func_0215A5F4((void *)b)), c, x);
    return 0;
}


int func_021AFBEC(Ctx_021AFBEC *a0, int a1, int (*fn)())
{
    u8 *p = a0->cur;
    int b = *p;
    int t;

    a0->cur = p + 1;
    t = (int)func_02159B10(a0, (void *)a1);
    fn(func_02158F74(func_0215A5F4((void *)a1)), b, (u8)t);
    return 0;
}
