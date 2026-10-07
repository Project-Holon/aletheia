/*
 * file:     unit_021B95A0_p12.c
 * unit:     yes
 * function: func_021BA248, func_021BA264
 * address:  0x021BA248
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
 *   func_021BA4C8  0x021BA4C8  thumb
 *   func_021BA2D4  0x021BA2D4  thumb
 *   func_020056EC  0x020056EC  thumb
 *   func_021BA5B4  0x021BA5B4  thumb  ov099
 *   func_021C57D8  0x021C57D8  thumb  ov127
 *   func_021BA538  0x021BA538  thumb  ov099
 *   func_021BA2D0  0x021BA2D0  thumb  ov099
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef struct {
    char pad[8];
    u16 f08;
    char pad2[2];
    u16 f0C;
    void *f10;
    void *f14;
    void *f18;
} S_021BA248;

typedef struct {
    void *f0;
    void *f4;
    s16 f8;
    s16 fa;
    s16 fc;
    s16 fe;
    void *f10;
    void *f14;
    void *f18;
} S_021BA264;

extern void func_021BA4C8(void);
extern void func_021BA2D4(void);
extern u32 func_020056EC(u32 x);
extern void func_021BA5B4(void *a, int b, u8 **p);
extern void func_021C57D8(u8 *p, int v);
extern int func_021BA538(void *w, S_021BA264 *s);
extern void func_021BA2D0(void);
void func_021BA248(int unused, S_021BA248 *s);
void func_021BA264(void *w, S_021BA264 *s);


void func_021BA248(int unused, S_021BA248 *s)
{
    s->f10 = (void *)func_021BA4C8;
    s->f18 = (void *)func_021BA2D4;
    s->f08 = 0x2D;
    s->f0C = 1;
}


/*
 * Lever: n = 0x400 in a u32 local keeps 0x400>>2 a runtime lsrs.
 * func_021BA2D0 is the empty callback filed as its own ov099 leaf.
 */
void func_021BA264(void *w, S_021BA264 *s)
{
    u32 n;

    s->f10 = (void *)func_021BA538;
    s->f18 = (void *)func_021BA2D0;
    n = 0x400;
    s->f8 = func_020056EC(n) + (n >> 2);
    s->fc = 3;
    func_021BA5B4(w, 0, (u8 **)s);
    func_021C57D8(s->f4, 1);
}
