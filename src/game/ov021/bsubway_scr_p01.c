/*
 * file:     bsubway_scr_p01.c
 * unit:     yes
 * function: func_021C87A0, func_021C87AC, func_021C87B8, func_021C87C8, func_021C87D4, func_021C87E0, func_021C8810, func_021C881C, func_021C8848
 * address:  0x021C87A0
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
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012ED0  0x02012ED0  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_021C8608  0x021C8608  thumb  ov021
 *   func_021666A4  0x021666A4  thumb  ov010
 */
struct Ctx;
struct Big;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed short s16;

typedef struct { u32 f0; s16 f4; s16 f6; int f8; } P;

typedef signed char    s8;

extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012ED0(struct Big *p);
extern char *func_021C8608(void);
extern void func_021666A4(int a0);
u32 func_021C87A0(void *p, u32 i);
u32 func_021C87AC(void *p, u32 i);
u32 func_021C87B8(void *p, u32 i, u32 j);
u32 func_021C87C8(void *p, u32 i);
void func_021C87D4(char *p, int i, int v);
int func_021C87E0(P *p);
u32 func_021C8810(u32 a);
int func_021C881C(void *task, u32 a);
int func_021C8848(u32 a, u32 b, u32 c, u32 d);


u32 func_021C87A0(void *p, u32 i)
{
    return *(u32 *)((u8 *)p + i * 0x1C + 0x18);
}


/*
 * Unlabelled leaf in the 0x1C-byte record accessor run; called from ov010
 * func_02166734 case 6. 10 bytes plus 2 bytes of padding.
 */
u32 func_021C87AC(void *p, u32 i)
{
    return *(u32 *)((u8 *)p + i * 0x1C + 0x10);
}


/*
 * Unlabelled leaf in the 0x1C-byte record accessor run; called from ov010
 * func_02166734 case 7. 14 bytes plus 2 bytes of padding.
 * lever: the record pointer as its own local; the flat
 *   `p + i*0x1C + j*4 + 0x1C` spelling is DIFF4 (adds order).
 */
u32 func_021C87B8(void *p, u32 i, u32 j)
{
    u8 *e = (u8 *)p + i * 0x1C;
    return ((u32 *)(e + 0x1C))[j];
}


/*
 * Unlabelled leaf in the 0x1C-byte record accessor run; called from ov010
 * func_02166734 case 8. 10 bytes plus 2 bytes of padding.
 */
u32 func_021C87C8(void *p, u32 i)
{
    return *(u32 *)((u8 *)p + i * 0x1C + 0x24);
}

void func_021C87D4(char *p, int i, int v)
{
    *(int *)(p + i * 0x1c + 0x24) = v;
}

int func_021C87E0(P *p)
{
    if (p->f4 >= 5400 && p->f8 >= 4)
        return 2;
    return p->f4 % 1350 == 0;
}


u32 func_021C8810(u32 a)
{
*(u32 *)((u8 *)(a) + ((109 << 2))) = 1;
return a;
}

int func_021C881C(void *task, u32 a)
{
    u32 *p = (u32 *)func_02012ED0(func_020120F4((void *)func_02188C80(func_0201210C(func_0215A5DC((void *)a)))));
    if (*p == 0)
        *p = (u32)func_021C8608();
    return 0;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C8848(u32 a, u32 b, u32 c, u32 d)
{
func_021666A4((int)func_02012ED0(func_020120F4(func_02188C80(func_0201210C(func_0215A5DC((void *)b))))));
return 0;
}
