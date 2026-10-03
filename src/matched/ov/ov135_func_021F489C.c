/*
 * function: func_021F489C
 * address:  0x021F489C
 * packet:   pkt_021F489C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
 * symbols:
 *   func_021F4EC0  0x021F4EC0  thumb
 *   str_02203B08  0x02203B08  data  a1
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    void *a0;
    void *a4;
    void *a8;
    void *aC;
    u8 pad10[4];
    void *a14;
    void *a18;
    void *a1C;
    void *a20;
    void *a24;
    u8 pad28[0x3C - 0x28];
    void *a3C;
} Args;

typedef struct {
    Args *args;
    u8 pad4[0x10 - 4];
    u32 x10;
    u8 pad14[0xC0 - 0x14];
    u16 xC0;
    u8 padC2[0xC4 - 0xC2];
    u16 box;
    u8 padC6[0xB56 - 0xC6];
    u16 xB56;
    u8 xB58;
    u8 xB59;
    u8 xB5A;
    u8 padB5B;
    u16 xB5C;
    u8 padB5E[0xDF8 - 0xB5E];
    u32 xDF8;
    u8 padDFC[0xE18 - 0xDFC];
    u16 xE18;
    u16 xE1A;
    u8 padE1C[0xEB0 - 0xE1C];
    u16 xEB0;
    u16 xEB2;
    u8 padEB4[0xF84 - 0xEB4];
    u32 xF84;
} Work;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_021F4EC0(Work *p, u32 a, u32 b);
extern const char str_02203B08[];

#define ASSERT(x) if (!(x)) func_02034714(str_02203B08, 0, str_02203B08)

void func_021F489C(Work *p, Args *args)
{
    ASSERT(args->a3C);
    ASSERT(args->a0);
    ASSERT(args->a4);
    ASSERT(args->a8);
    ASSERT(args->aC);
    ASSERT(args->a14);
    ASSERT(args->a18);
    ASSERT(args->a1C);
    ASSERT(args->a20);
    ASSERT(args->a24);
    p->args = args;
    p->x10 = 0;
    func_021F4EC0(p, 0, 0x13);
    p->xC0 = 0;
    p->xB56 = 0;
    p->xB58 = 3;
    p->xB59 = 0;
    p->xB5A = 0;
    p->xB5C = 0;
    p->xE18 = 0;
    p->box = 0xFF;
    p->xEB0 = 0;
    p->xEB2 = 0;
    p->xE1A = 0;
    p->xDF8 = 0;
    p->xF84 = 0;
}
