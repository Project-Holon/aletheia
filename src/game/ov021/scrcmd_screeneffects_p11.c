/*
 * file:     scrcmd_screeneffects_p11.c
 * unit:     yes
 * function: func_021AF844, func_021AF878, func_021AF8A8, func_021AF8D8
 * address:  0x021AF844
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

typedef struct Ctx { u32 f0; u32 f4; u32 f8; u32 fc; u32 f10; u8 *pc; } Ctx;

typedef struct {
    u8 pad[0x14];
    u8 *cur;
} Script;

extern void *func_0215A5F4(void *p);
extern void *func_02158F74(void *p);
extern unsigned int func_02159B10(void *a, void *b);
extern u32 func_020212B0(u32 a);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201F020(struct WordSet *p, u32 i, u32 v);
int func_021AF844(Ctx *s, u32 b);
int func_021AF878(Ctx *s, u32 b);
int func_021AF8A8(Ctx *s, u32 b);
int func_021AF8D8(Script *a, u32 b, void (*fn)(u32, u32, u32));


static inline u8 Ctx_ReadByte(Ctx *s)
{
    u8 v = *s->pc;

    s->pc++;
    return v;
}


int func_021AF844(Ctx *s, u32 b)
{
    u32 w = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 c = Ctx_ReadByte(s);

    func_0201EF34((struct WordSet *)w, c, func_020212B0(func_02159B10(s, (void *)b)));
    return 0;
}


int func_021AF878(Ctx *s, u32 b)
{
    u32 w = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 c = Ctx_ReadByte(s);

    func_0201EF34((struct WordSet *)w, c, func_02159B10(s, (void *)b));
    return 0;
}


int func_021AF8A8(Ctx *s, u32 b)
{
    u32 w = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 c = Ctx_ReadByte(s);

    func_0201F020((struct WordSet *)w, c, func_02159B10(s, (void *)b));
    return 0;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021AF8D8(Script *a, u32 b, void (*fn)(u32, u32, u32))
{
    u32 x = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 *p = a->cur;
    u32 v = *p;
    a->cur = p + 1;
    fn(x, v, func_02159B10(a, (void *)b));
    return 0;
}
