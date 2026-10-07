/*
 * file:     musical_dressup_sys_p02.c
 * unit:     yes
 * function: func_02155A4C, func_02155A6C
 * address:  0x02155A4C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02005D90  0x02005D90  thumb
 *   func_02005DF8  0x02005DF8  thumb
 */
typedef unsigned char u8;

struct Ctx_02155A4C {
    u8 pad00[0x38];
    void *f38;
    void *f3c[4];
};

typedef unsigned int   u32;

typedef unsigned short u16;

struct Ctx_02155A6C {
    u8 pad00[0x54];
    u32 f54;
};

extern u32 func_020307B0(void *p);
extern void func_02005D90(u32 a, u16 b);
extern void func_02005DF8(u32 a);
void func_02155A4C(struct Ctx_02155A4C *ctx);
void func_02155A6C(struct Ctx_02155A6C *ctx);


/*
 * Frees the four lists at +0x3c and then the list at +0x38.
 */
void func_02155A4C(struct Ctx_02155A4C *ctx)
{
    int i;

    for (i = 0; i < 4; i++)
        func_020307B0(ctx->f3c[i]);
    func_020307B0(ctx->f38);
}


/*
 * Stops the sound handle at +0x54 (if any) and clears it.
 */
void func_02155A6C(struct Ctx_02155A6C *ctx)
{
    if (ctx->f54 != 0) {
        func_02005D90(ctx->f54, 0xFFFF);
        func_02005DF8(0x3c);
        ctx->f54 = 0;
    }
}
