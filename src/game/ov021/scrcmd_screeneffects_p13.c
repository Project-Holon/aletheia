/*
 * file:     scrcmd_screeneffects_p13.c
 * unit:     yes
 * function: func_021AFA80, func_021AFAC8, func_021AFAFC, func_021AFB2C
 * address:  0x021AFA80
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0201EFA4  0x0201EFA4  thumb
 */
struct WordSet;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u8 pad[0x14];
    u8 *cur;
} Script;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Ctx { u32 f0; u32 f4; u32 f8; u32 fc; u32 f10; u8 *pc; } Ctx;

extern void *func_0215A5F4(void *p);
extern void *func_02158F74(void *p);
extern unsigned int func_02159B10(void *a, void *b);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 func_02013E4C(u32 a);
extern void func_0201F158(struct WordSet *p, u32 i, u32 v);
extern void func_0201EFC8(struct WordSet *p, u32 i, u32 v);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
int func_021AFA80(Script *a, u32 b);
int func_021AFAC8(Ctx *s, u32 b);
int func_021AFAFC(Ctx *s, u32 b);
int func_021AFB2C(Ctx *s, u32 b);


/*
 * Addresses are Black-image addresses.
 */
int func_021AFA80(Script *a, u32 b)
{
    u32 x = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 *p = a->cur;
    u32 v = *p;
    u32 e, f;
    a->cur = p + 1;
    e = func_02159B10(a, (void *)b);
    f = func_02159B10(a, (void *)b);
    func_0201EFA4((struct WordSet *)x, v, e, f, 0, 1);
    return 0;
}


static inline u8 Ctx_ReadByte(Ctx *s)
{
    u8 v = *s->pc;

    s->pc++;
    return v;
}


int func_021AFAC8(Ctx *s, u32 b)
{
    u32 w = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 c = Ctx_ReadByte(s);

    func_0201F158((struct WordSet *)w, c, func_02013E4C(func_02159B10(s, (void *)b)));
    return 0;
}


int func_021AFAFC(Ctx *s, u32 b)
{
    u32 w = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 c = Ctx_ReadByte(s);

    func_0201EFC8((struct WordSet *)w, c, func_02159B10(s, (void *)b));
    return 0;
}


int func_021AFB2C(Ctx *s, u32 b)
{
    u32 w = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 c = Ctx_ReadByte(s);

    func_0201F048((struct WordSet *)w, c, func_02159B10(s, (void *)b));
    return 0;
}
