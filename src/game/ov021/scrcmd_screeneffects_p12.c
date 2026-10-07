/*
 * file:     scrcmd_screeneffects_p12.c
 * unit:     yes
 * function: func_021AF928, func_021AF958, func_021AF9A4, func_021AF9F0, func_021AFA38
 * address:  0x021AF928
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
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201EE84  0x0201EE84  thumb
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D50  0x02188D50  thumb  ov021
 *   func_021C34F8  0x021C34F8  thumb  ov021
 */
struct WordSet;
struct BigObj;
struct Ctx;
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
extern void func_0201F14C(struct WordSet *p, u32 i, u32 v);
extern void *func_0215A5E4(void *a0);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *, u32);
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188D50(u8 *);
extern void *func_021C34F8(void *, u32);
int func_021AF928(Ctx *s, u32 b);
int func_021AF958(Script *a, u32 b);
int func_021AF9A4(Script *a, u32 b);
int func_021AF9F0(Script *a, u32 b);
int func_021AFA38(Script *a, u32 b);


static inline u8 Ctx_ReadByte(Ctx *s)
{
    u8 v = *s->pc;

    s->pc++;
    return v;
}


int func_021AF928(Ctx *s, u32 b)
{
    u32 w = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 c = Ctx_ReadByte(s);

    func_0201F14C((struct WordSet *)w, c, func_02159B10(s, (void *)b));
    return 0;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021AF958(Script *a, u32 b)
{
    void *c = func_0215A5F4((void *)b);
    void *d = func_0215A5E4((void *)b);
    u32 x = (u32)func_02158F74(c);
    u8 *p = a->cur;
    u32 v = *p;
    u32 e;
    a->cur = p + 1;
    e = func_02159B10(a, (void *)b);
    func_0201EE84((void *)x, v, func_0201AB28(func_02012934((void *)d), e));
    return 0;
}


int func_021AF9A4(Script *a, u32 b)
{
    void *c = func_0215A5F4((void *)b);
    void *d = func_0215A5E4((void *)b);
    u32 x = (u32)func_02158F74(c);
    u8 *p = a->cur;
    u32 v = *p;
    u32 e;
    a->cur = p + 1;
    e = func_02159B10(a, (void *)b);
    func_0201EEF4((void *)x, v, func_0201AB28(func_02012934((void *)d), e));
    return 0;
}


int func_021AF9F0(Script *a, u32 b)
{
    u32 x = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 *p = a->cur;
    u32 v = *p;
    u32 e;
    a->cur = p + 1;
    e = func_02159B10(a, (void *)b);
    func_0201EE84((void *)x, v, func_021C34F8(func_02188D50(func_0201210C(func_0215A5DC((void *)b))), e));
    return 0;
}


int func_021AFA38(Script *a, u32 b)
{
    u32 x = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 *p = a->cur;
    u32 v = *p;
    u32 e;
    a->cur = p + 1;
    e = func_02159B10(a, (void *)b);
    func_0201EEF4((void *)x, v, func_021C34F8(func_02188D50(func_0201210C(func_0215A5DC((void *)b))), e));
    return 0;
}
