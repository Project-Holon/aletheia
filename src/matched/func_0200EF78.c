/*
 * function: func_0200EF78
 * address:  0x0200EF78
 * packet:   pkt_0200EF78
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MI_CpuFill8     0x02082BCC  arm
 *   MI_CpuCopy8     0x02082D44  arm
 *   func_0216E2E8   0x0216E2E8  thumb  ov010
 */

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} VecFx32;

typedef struct {
    u32 flags;
    u32 flags4;
    u16 f8;
    u16 fa;
    u16 fc;
    u16 fe;
    u16 f10;
    u16 f12;
    u16 f14;
    s16 f16;
    s16 f18;
    s16 f1a;
    u8 pad1c[4];
    s16 f20;
    s16 f22;
    s16 f24;
    u8 pad26[6];
    s16 f2c;
    s16 f2e;
    s16 f30;
    s16 f32;
    s16 f34;
    s16 f36;
    s16 f38;
    s16 f3a;
    s16 f3c;
    s16 f3e;
    s16 f40;
    u8 pad42[2];
    VecFx32 f44;
    u8 pad50[0x7c - 0x50];
    u8 f7c;
    u8 f7d;
    s8 f7e;
    s8 f7f;
    s8 f80;
    u8 pad81[7];
    void *f88;
    u8 pad8c[0x94 - 0x8c];
    u8 f94[0x10];
    u8 fa4[0x10];
    u8 padb4[0xe4 - 0xb4];
    u8 fe4[0x1c];
} DstStruct;

typedef struct {
    u32 f0;
    u8 f4;
    u8 f5;
    u8 pad6[2];
    u8 f8;
    u8 f9;
    s8 fa;
    s8 fb;
    s8 fc;
    s8 fd;
    s8 fe;
    u8 padf;
    u16 f10;
    u16 f12;
    u16 f14;
    u16 f16;
    u16 f18;
    u16 f1a;
    u16 f1c;
    u16 f1e;
    s16 f20;
    s16 f22;
    s16 f24;
    s16 f26;
    s16 f28;
    s16 f2a;
    s32 f2c;
    u8 f30[0x10];
    u8 f40[0x10];
} SrcStruct;

extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void func_0216E2E8(void *arg0, u16 arg1, void *arg2);

void func_0200EF78(DstStruct *dst, const SrcStruct *src, void *arg2) {
    MI_CpuFill8(dst, 0, 0x100);

    dst->flags = src->f0;
    dst->f7c = src->f4;
    dst->f7d = src->f5;

    dst->f8 = src->f8;
    dst->fa = src->f10;
    dst->fc = src->f12;
    dst->fe = src->f9;
    dst->f10 = src->f14;
    dst->f12 = src->f16;
    dst->f14 = src->f18;

    dst->f16 = src->fc;
    dst->f18 = src->fd;
    dst->f1a = src->fe;

    dst->f20 = src->f1a;
    dst->f22 = src->f1c;
    dst->f24 = src->f1e;

    dst->f2c = src->fa;
    dst->f2e = src->fb;

    dst->f30 = src->f20;
    dst->f32 = src->f22;
    dst->f34 = src->f24;

    dst->f3c = src->f26;
    dst->f3e = src->f28;
    dst->f40 = src->f2a;

    MI_CpuCopy8(&src->f30, &dst->f94, 0x10);
    MI_CpuCopy8(&src->f40, &dst->fa4, 0x10);

    dst->f88 = arg2;
    {
        VecFx32 vec = { 0 };
        dst->f36 = dst->f3c;
        vec.x = (dst->f3c << 16) + 0x8000;
        dst->f38 = dst->f3e;
        vec.y = src->f2c;
        dst->f3a = dst->f40;
        vec.z = (dst->f40 << 16) + 0x8000;
        dst->f44 = vec;
    }

    dst->flags &= ~1;
    func_0216E2E8(arg2, dst->fc, &dst->fe4);
    dst->flags |= 1;

    {
        s8 *sub = (s8 *)dst + 0xe4;
        u8 *d = (u8 *)dst;
        d[0x7e] = sub[0xd];
        d[0x7f] = sub[0xe];
        d[0x80] = sub[0xf];
    }

    dst->flags |= 1;
    dst->flags4 |= 0x800;
    if (dst->flags & 2) {
        dst->flags4 |= 1;
    }
}
