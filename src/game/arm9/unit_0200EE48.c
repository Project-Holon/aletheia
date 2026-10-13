/*
 * file:     unit_0200EE48.c
 * unit:     yes
 * function: func_0200EE48, func_0200EE50, func_0200EE64, sub_0200EEAC, func_0200EED8, func_0200EF78, func_0200F0CC, func_0200F104, func_0200F128, func_0200F168, func_0200F16C, func_0200F17C
 * address:  0x0200EE48
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *   MI_CpuFill8     0x02082BCC  arm
 *   FLDMMDL_LoadObjCodeParam   0x0216E2E8  thumb  ov010
 *   func_02034A5C  0x02034A5C  arm
 *   func_02034AC4  0x02034AC4  arm
 *   GFL_NET_DEVWIFI_GetDeviceTable  0x0215536C  thumb  ov009
 *   GFL_NET_DEVWIRELESS_GetDeviceTable  0x02177020  thumb  ov014
 *   func_021798D4  0x021798D4  thumb  ov015
 *   ov_id_0A       0x0000000A  data
 *   ov_id_0B       0x0000000B  data
 *   ov_id_09       0x00000009  data
 *   ov_id_0D       0x0000000D  data
 *   ov_id_72       0x00000072  data
 *   ov_id_0E       0x0000000E  data
 *   ov_id_0F       0x0000000F  data
 */
#include "../../matched/include/Obj00607.h"
#include "../../matched/include/Obj00606.h"
#include "../../matched/include/Obj00648.h"
#include "../../matched/include/Obj11712.h"
#include "../../matched/include/Obj16720.h"
#include "../../matched/include/Obj16721.h"
#include "../../matched/include/Obj00192.h"

struct Record;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

typedef signed char    s8;

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

struct Sub0200F16CHdr {
    u32 tag;
    u32 size;
    u32 count;
};

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void FLDMMDL_LoadObjCodeParam(const char *ctx, u32 id, struct Record *out);
extern void func_02034A5C(s32 handle);
extern int func_02034AC4(s32 handle);
extern void *GFL_NET_DEVWIFI_GetDeviceTable(void);
extern void *GFL_NET_DEVWIRELESS_GetDeviceTable(void);
extern void *func_021798D4(void);
int func_0200F17C(u32 sel);
u32 sub_0200EE48(void);
void sub_0200EE50(void *dest);
void func_0200EE64(u32 a0, u8 *a1);
void sub_0200EEAC(void *ctx, void *list);
void sub_0200EED8(const void *item, void *record);
void func_0200EF78(DstStruct *dst, const SrcStruct *src, void *arg2);
u32 sub_0200F0CC(const void *obj, void *out, u32 *idxptr);
void *sub_0200F104(void *ctx);
u32 sub_0200F128(u32 x);
u32 sub_0200F168(void);
extern u8 ov_id_0A[];
extern u8 ov_id_0B[];
extern u8 ov_id_09[];
extern u8 ov_id_0D[];
extern u8 ov_id_72[];
extern u8 ov_id_0E[];
extern u8 ov_id_0F[];


u32 sub_0200EE48(void)
{
    return 5 << 10;
}



void sub_0200EE50(void *dest)
{
    MI_CpuFill8(dest, 0, sub_0200EE48());
}



/*
 * Drain loop over a producer: while the enumerator at 0x0200F0CC still hands
 * back 1, take the item at the out-slot and, unless bit 20 of its +4 word is
 * set, retire the 0x50-byte destination cursor through sub_0200EED8.  The
 * enumerator call is rotated (first test above the loop body) so this is a
 * plain `while`, not a do/while.
 */
void func_0200EE64(u32 a0, u8 *a1)
{
    u32 hint = 0;
    void *item;

    sub_0200EE50(a1);

    while (sub_0200F0CC((const void *)a0, &item, &hint) == 1) {
        if ((((struct Obj00607 *)item)->f4 & 0x100000) == 0) {
            sub_0200EED8(item, a1);
            a1 += 0x50;
        }
    }
}


/*
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT*.
 *
 * Walks 64 0x50-byte records; for each whose leading word has bit 0 set,
 * looks up a free slot with func_0200F104 and hands it, the record and
 * the context to func_0200EF78. Stores the record count (always 0x40)
 * into the context at +6 once the walk finishes.
 *
 * Every concrete byte matches; func_0200F104 (a documented near miss,
 * still open) and func_0200EF78 are each called from exactly this one
 * site in the whole ROM, so both relocations stay unresolved under the
 * honesty rule.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200EEAC.c \
 *       --func sub_0200EEAC --addr 0x0200EEAC --cc 1.1p1
 *
 * The `matched` class does not reach it: neither func_0200F104 nor
 * func_0200EF78 is matched, so no EXACT entry covers either address.  It closes
 * when one of the two is matched, or when the image acquires a second caller.
 */
void sub_0200EEAC(void *ctx, void *list)
{
    u8 *rec = (u8 *)list;
    u32 i;

    for (i = 0; i < 0x40; i++, rec += 0x50) {
        if (((struct Obj00606 *)rec)->f0 & 1) {
            func_0200EF78((DstStruct *)sub_0200F104(ctx), (const SrcStruct *)rec, ctx);
        }
    }

    *(unsigned short *)((u8 *)ctx + 6) = (unsigned short)i;
}


/*
 * A field-by-field marshal from a source record into a differently laid
 * out destination record: several 16-bit source fields narrow to 8-bit
 * destination fields, several signed-halfword source fields (loaded with
 * ldrsh, register-offset addressing being Thumb's only encoding for a
 * signed halfword load, see docs/idioms/ldrsh-register-offset-is-signedness.md)
 * widen back into unsigned destination halfwords, and the tail of the
 * record is two flat 0x10-byte blocks copied with MI_CpuCopy8.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200EED8.c \
 *       --func sub_0200EED8 --addr 0x0200EED8 --cc 1.1p1
 */
void sub_0200EED8(const void *item, void *record)
{
    const u8 *src = (const u8 *)item;
    u8 *dest = (u8 *)record;

    ((struct Obj00648 *)dest)->f0 = *(const u32 *)&((struct Obj00607 *)src)->f0;
    dest[4] = src[0x7c];
    dest[5] = src[0x7d];
    dest[8] = (u8)*(const u16 *)&((struct Obj00607 *)src)->f8;
    ((struct Obj00648 *)dest)->f10 = *(const u16 *)&((struct Obj00607 *)src)->fA;
    ((struct Obj00648 *)dest)->f12 = *(const u16 *)&((struct Obj00607 *)src)->fC;
    dest[9] = (u8)*(const u16 *)&((struct Obj00607 *)src)->fE;
    ((struct Obj00648 *)dest)->f14 = *(const u16 *)&((struct Obj00607 *)src)->f10;
    ((struct Obj00648 *)dest)->f16 = *(const u16 *)&((struct Obj00607 *)src)->f12;
    ((struct Obj00648 *)dest)->f18 = *(const u16 *)&((struct Obj00607 *)src)->f14;
    dest[0xc] = (u8)*(const u16 *)&((struct Obj00607 *)src)->f16;
    dest[0xd] = (u8)*(const u16 *)&((struct Obj00607 *)src)->f18;
    dest[0xe] = (u8)*(const u16 *)&((struct Obj00607 *)src)->f1A;
    ((struct Obj00648 *)dest)->f1A = *(const u16 *)&((struct Obj00607 *)src)->f20;
    ((struct Obj00648 *)dest)->f1C = *(const u16 *)&((struct Obj00607 *)src)->f22;
    ((struct Obj00648 *)dest)->f1E = *(const u16 *)&((struct Obj00607 *)src)->f24;
    dest[0xa] = (u8)*(const s16 *)&((struct Obj00607 *)src)->f2C;
    dest[0xb] = (u8)*(const s16 *)&((struct Obj00607 *)src)->f2E;
    ((struct Obj00648 *)dest)->f20 = (u16)*(const s16 *)&((struct Obj00607 *)src)->f30;
    ((struct Obj00648 *)dest)->f22 = (u16)*(const s16 *)&((struct Obj00607 *)src)->f32;
    ((struct Obj00648 *)dest)->f24 = (u16)*(const s16 *)&((struct Obj00607 *)src)->f34;
    ((struct Obj00648 *)dest)->f26 = (u16)*(const s16 *)&((struct Obj00607 *)src)->f3C;
    ((struct Obj00648 *)dest)->f28 = (u16)*(const s16 *)&((struct Obj00607 *)src)->f3E;
    ((struct Obj00648 *)dest)->f2A = (u16)*(const s16 *)&((struct Obj00607 *)src)->f40;
    ((struct Obj00648 *)dest)->f2C = *(const u32 *)&((struct Obj00607 *)src)->f48;

    MI_CpuCopy8(src + 0x94, dest + 0x30, 0x10);
    MI_CpuCopy8(src + 0xa4, dest + 0x40, 0x10);
}



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
    FLDMMDL_LoadObjCodeParam(arg2, dst->fc, (struct Record *)&dst->fe4);
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



/*
 * Scans an array of 0x100-byte records starting at *idxptr, looking for one
 * whose leading word has bit 0 set. obj+4 holds a u16 record count and
 * obj+0x18 holds the array base. On a hit, *out gets the record pointer,
 * *idxptr is left one past the hit, and the function returns 1; scanning
 * to the end without a hit returns 0, leaving *idxptr == count. The two
 * "return 0" paths (guard and loop exhaustion) are separate, out-of-line
 * blocks rather than a shared tail; see
 * docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200F0CC.c \
 *       --func sub_0200F0CC --addr 0x0200F0CC --cc 1.1p1
 */
u32 sub_0200F0CC(const void *obj, void *out, u32 *idxptr)
{
    u32 count = *(const u16 *)&((struct Obj11712 *)obj)->f4;
    u32 idx = *idxptr;
    u8 *rec;

    if (idx < count) {
        rec = *(u8 * *)&((struct Obj11712 *)obj)->f18 + idx * 0x100;
        do {
            *idxptr = *idxptr + 1;
            if (((struct Obj16721 *)rec)->f0 & 1) {
                ((struct Obj16720 *)out)->f0 = rec;
                return 1;
            }
            rec += 0x100;
        } while (*idxptr < count);
    }
    return 0;
}



/*
 * Scans a run of fixed-stride slots for the first one whose leading word
 * has bit 0 clear (a free-slot search); ctx+4 is the slot count (halfword)
 * and ctx+0x18 is the base pointer, stride 0x100 bytes. Returns the slot
 * pointer, or NULL if every slot up to the count is occupied. The loop
 * enters unconditionally and only checks the count after the first slot
 * has already been tested, so it is written as an infinite loop with two
 * breaks rather than a pre-tested while. The pointer argument is reused
 * in place for the slot cursor, which is what keeps it in r0 through to
 * the return and lets the found-slot path fall straight into the shared
 * epilogue with no register shuffle.
 *
 * EXACT* because the 34 compiled bytes fall two bytes short of the
 * disasm.py extent: a trailing "movs r0, r0" filler halfword between this
 * function and the next label, the ordinary inter-function padding, not a
 * byte difference (see "the two missing labels" in docs/MATCHING.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200F104.c \
 *       --func sub_0200F104 --addr 0x0200F104 --cc 1.1p1
 */
void *sub_0200F104(void *ctx)
{
    u16 count = *(u16 *)&((struct Obj00192 *)ctx)->f4;
    int i = 0;

    ctx = ((struct Obj00192 *)ctx)->f18;

    for (;;) {
        if ((((struct Obj00192 *)ctx)->f0 & 1) == 0) {
            break;
        }
        i++;
        ctx = (u8 *)ctx + 0x100;
        if (i >= count) {
            ctx = 0;
            break;
        }
    }
    return ctx;
}



/*
 * A piecewise remap of one id space onto another: below 0xdf the id passes
 * through unchanged; two disjoint windows (0x1000..0x1235 and
 * 0x2000..0x2009) are rebased by subtracting a fixed offset (0xf21 and
 * 0x1ceb respectively, read as u16); everything else, including the gap
 * between the two windows, maps to the constant 0xa.  Each `if` here has to
 * be written with the in-window case as the `then` and the fallback as the
 * trailing `return`, not the other way around, or the branch polarity comes
 * out reversed; see docs/idioms/the-fall-through-arm-is-the-source-order.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200F128.c \
 *       --func sub_0200F128 --addr 0x0200F128 --cc 1.1p1
 */
u32 sub_0200F128(u32 x)
{
    if (x < 0xdf) {
        return x;
    }
    if (x >= 0x1000 && x < 0x1236) {
        return (u16)(x - 0xf21);
    }
    if (x >= 0x2000 && x < 0x200a) {
        return (u16)(x - 0x1ceb);
    }
    return 0xa;
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: sub_0200F168 is a stub returning 0; sub_0200F16C stamps a
 * three-word header (a type tag, a size, a count) into the caller's struct.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200F168.c \
 *       --addr 0x0200F168 --thumb
 */
u32 sub_0200F168(void)
{
    return 0;
}



void sub_0200F16C(struct Sub0200F16CHdr *hdr)
{
    hdr->tag = 2;
    hdr->size = 4;
    hdr->count = 1;
}


/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id sites
 *           ov_id_72 (114) and ov_id_0E (14) resolve as `overlay_id` (a
 *           layout overlay index, loaded by a pc-relative load of this
 *           function, reaching the id register of a known overlay loader),
 *           which was the last blocker.
 *
 * The jump table at 0x0200F18E (base 0x0200F190, selector order 0..6) is
 * 0x006c, 0x0030, 0x004e, 0x0078, 0x0078, 0x006c, 0x000c, i.e. selectors 0
 * and 5 share the arm at 0x0200F1FC, selectors 3 and 4 the one at
 * 0x0200F208, and 6, 1, 2 have their own (0x0200F19C, 0x0200F1C0,
 * 0x0200F1DE).  The cases below are written in that memory order, which is
 * what decides the arm layout (the sibling function func_0200F234, same
 * packet, closes the same way).
 *
 * The arguments are absolute symbols, not numbers: every one of them arrives
 * in a literal pool (`ldr r0, [pc]`), and mwccarm writes any literal in
 * 0..255 with `movs`
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).  The
 * seven words of the pool are, in order, 0x0A, 0x0B, 9, 0x0D, 0x72, 0x0E,
 * 0x0F -- all seven are loaded.
 *
 * seed round 9: the five overlay call sites now resolve (0x0215536C,
 *           0x02177020 and 0x021798D4 seeded in layout/function_starts.txt);
 *           25 of 27 sites resolved.  The two left are the pooled overlay-id
 *           constants ov_id_72 and ov_id_0E, which have no witness outside
 *           this range, so the file stayed MATCH until the wave 17
 *           `overlay_id` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200F17C.c \
 *       --func func_0200F17C --addr 0x0200F17C --cc 1.1p1 --thumb
 */
int func_0200F17C(u32 sel)
{
    switch (sel) {
    case 6:
        func_02034A5C((u32)ov_id_0A);
        func_02034A5C((u32)ov_id_0B);
        func_02034AC4((u32)ov_id_09);
        func_02034AC4((u32)ov_id_0D);
        func_02034AC4((u32)ov_id_72);
        return (int)GFL_NET_DEVWIFI_GetDeviceTable();
    case 1:
        func_02034A5C((u32)ov_id_0A);
        func_02034A5C((u32)ov_id_0B);
        func_02034AC4((u32)ov_id_09);
        func_02034AC4((u32)ov_id_0D);
        return (int)GFL_NET_DEVWIFI_GetDeviceTable();
    case 2:
        func_02034A5C((u32)ov_id_0A);
        func_02034A5C((u32)ov_id_0B);
        func_02034AC4((u32)ov_id_09);
        func_02034AC4((u32)ov_id_0D);
        return (int)GFL_NET_DEVWIFI_GetDeviceTable();
    case 0:
    case 5:
        func_02034AC4((u32)ov_id_0E);
        return (int)GFL_NET_DEVWIRELESS_GetDeviceTable();
    case 3:
    case 4:
        func_02034AC4((u32)ov_id_0F);
        return (int)func_021798D4();
    }
    return 0;
}
