/*
 * function: func_02161214
 * address:  0x02161214
 * packet:   pkt_ov010_02161214
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Allocates a 0x18-byte record (func_02030734: heap 4, size 0x18, clear,
 * site string, tag 0x68A) and fills it from the work's 0x18 sub-object.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_020128B8  0x020128B8  thumb
 *   d_02172978     0x02172978  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct Rec {
    u32 f00;            /* 0x00 */
    u32 f04;            /* 0x04 */
    u16 f08;            /* 0x08 */
    s16 f0A;            /* 0x0A */
    u32 f0C;            /* 0x0C */
    u32 f10;            /* 0x10 */
    u32 f14;            /* 0x14 */
} Rec;

typedef struct Sub {
    void *f00;          /* 0x00 */
    u32 f04;
    u32 f08;
    u32 f0C;            /* 0x0C */
} Sub;

typedef struct Work {
    u8 pad00[0x18];
    Sub *f18;           /* 0x18 */
} Work;

extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
struct BigObj;
struct Ctx;
struct Rec1C;
struct Rec44;
struct SaveBlock;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern struct Rec1C *func_020128B8(const struct BigObj *p);

extern const char d_02172978[];

Rec *func_02161214(Work *w)
{
    Rec *r = func_02030734(4, 0x18, 1, d_02172978, 0x68A);
    void *a;
    void *b;
    r->f00 = 1;
    r->f14 = (u32)w->f18->f00;
    a = func_020127A4(func_020120F4(w->f18->f00));
    b = func_020120F4(w->f18->f00);
    r->f08 = func_02012AC8(a);
    r->f0A = *(s16 *)((u8 *)func_020128B8(b) + 4);
    if (w->f18->f0C == 0)
        r->f00 = 0;
    else
        r->f00 = 1;
    return r;
}
