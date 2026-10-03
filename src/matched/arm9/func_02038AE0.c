/*
 * unit:     no
 * function: func_02038AE0
 * address:  0x02038AE0
 * packet:   pkt_02038AE0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D798  0x0203D798  arm
 *   func_0203D788  0x0203D788  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_020366A8  0x020366A8  arm
 *   func_02036A50  0x02036A50  arm
 *   func_0203F1FC  0x0203F1FC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

struct Hdr
{
    u8 f00;
    u8 f01;
    u8 f02;
    u8 f03;
    u8 f04;
    u8 f05;
    u8 f06;
    u8 body[1];
};

struct Glob
{
    u8 pad_00[0x65];
    u8 f65;
};

struct Conn
{
    u8 pad_00[0x24];
    u32 f24;
};

struct Vt
{
    u8 pad_00[0x7c];
    u8 (*f7c)(void);
    u8 pad_80[0x30];
    s32 (*fb0)(void);
};

struct Sys
{
    u8 pad_00[0x340];
    struct Vt *f340;
};

extern void *func_0203D798(void);
extern void *func_0203D788(void);
extern void MI_CpuFill8(void *, u8, u32);
extern s32 func_020366A8(struct Conn *);
struct Buf
{
    void *ptr;
    u16 len;
};

extern s32 func_02036A50(struct Conn *, struct Buf *);
extern u16 func_0203F1FC(const u8 *src, u32 len);

s32 func_02038AE0(struct Hdr *h, struct Conn *c, s32 len, u8 a3)
{
    struct Glob *g;
    struct Sys *sys;
    struct Buf buf;
    s32 n;
    u16 v;

    g = func_0203D798();
    sys = func_0203D788();

    MI_CpuFill8(h, 0, (u32)len);

    if (c->f24 == 0)
        h->f04 = 1;
    else
        h->f04 = 2;
    c->f24 = 0;

    h->f03 = sys->f340->f7c();

    if (func_020366A8(c) == 0)
    {
        if ((u8)(g->f65 + 0xfd) > 1)
            goto body;
        if (sys->f340->fb0() != 1)
            goto body;
    }
    h->f04 = 0xff;
    return 0;

body:
    ;

    buf.len = (u16)(len - 7);
    buf.ptr = &h->body[0];
    if (func_02036A50(c, &buf) == 0)
        c->f24 = 1;

    if (buf.len != 0xffff)
        n = (len - buf.len) - 7;
    else
        n = len - 7;

    if (n > 0xff)
    {
        n = n + 1;
        h->f04 = h->f04 | 8;
    }

    h->f02 = (u8)n;
    h->f05 = a3;

    v = func_0203F1FC(&h->f02, len - 2);
    h->f00 = (u8)v;
    h->f01 = (u8)((v & 0xff00) >> 8);

    return 1;
}
