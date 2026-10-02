/*
 * function: func_021AFB2C
 * address:  0x021AFB2C
 * packet:   pkt_ov021_021AFB2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
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
extern u32 func_02158F74(u32 a);
extern u32 func_02159B10(Ctx *a, u32 b);

extern void func_0201F048(u32 a, u32 b, u32 c);

int func_021AFB2C(Ctx *s, u32 b)
{
    u32 w = func_02158F74(func_0215A5F4((void *)b));
    u8 c = Ctx_ReadByte(s);

    func_0201F048(w, c, func_02159B10(s, b));
    return 0;
}
