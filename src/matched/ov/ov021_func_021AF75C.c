/*
 * function: func_021AF75C
 * address:  0x021AF75C
 * packet:   pkt_ov021_021AF75C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Ctx { u32 f0; u32 f4; u32 f8; u32 fc; u32 f10; u8 *pc; } Ctx;

static inline u8 Ctx_ReadByte(Ctx *s)
{
    u8 v = *s->pc;

    s->pc++;
    return v;
}

extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
struct WordSet;
extern int func_02158F58(int a0);
extern void *func_02158F74(void *p);
extern u8 *func_02012944(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);

int func_021AF75C(Ctx *s, u32 b)
{
    void *x = func_0215A5F4((void *)b);
    u32 y;
    u32 w;

    func_02158F58((int)x);
    y = (u32)func_02012944(func_0215A5E4((void *)b));
    w = (u32)func_02158F74(x);
    func_0201F02C((struct WordSet *)w, Ctx_ReadByte(s), (void *)y);
    return 0;
}
