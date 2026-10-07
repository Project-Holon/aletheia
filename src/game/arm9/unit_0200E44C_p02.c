/*
 * file:     unit_0200E44C_p02.c
 * unit:     yes
 * function: func_0200E7BC, func_0200E874, func_0200E878, func_0200E884, func_0200E89C, func_0200E8B0, func_0200E8B8, func_0200E8CC, func_0200E8D0, func_0200E8D8, func_0200E8E0, func_0200E8F8, func_0200E904, func_0200E918, func_0200E938, func_0200E958, func_0200E978, sub_0200E994
 * address:  0x0200E7BC
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
 *   func_02017E1C   0x02017E1C  thumb
 *   func_02045F5C   0x02045F5C  arm
 *   func_0201F41C   0x0201F41C  thumb
 *   g_020A7370      0x020A7370  data
 *   func_02082BCC   0x02082BCC  arm
 *   sub_020071CC  0x020071CC  thumb
 *   func_02082A90 0x02082A90  arm
 *   MI_CpuFill8   0x02082BCC  arm
 *   func_02087C6C 0x02087C6C  arm
 *   _u32_div_f    0x0209C2B0  arm
 *   MI_CpuCopy8   0x02082D44  arm
 *   func_0200E918  0x0200E918  thumb
 *   func_0200E938  0x0200E938  thumb
 *   func_0203EFC8  0x0203EFC8  arm
 */
#include "../../matched/include/Obj17085.h"
#include "../../matched/include/Obj17086.h"

struct MsgData;
struct Sub020071CCCtrl;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Bits0200E7BC {
    u8 flag : 1;
    u8 level : 7;
};

struct Rec0200E7BC {
    u32 f00;
    u16 name[11];
    struct Bits0200E7BC bits;
    u8  f1b;
    u32 f1c;
};

typedef signed int     s32;

extern u32  func_02017E1C(void *mon, u32 id, u32 buf);
extern void func_02045F5C(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern void func_0201F41C(const u16 *src, u16 *dst, u32 n);
extern void func_02082BCC(void *dst, int value, u32 size);
int sub_0200E874(void);
void sub_0200E878(void *dst);
extern void *sub_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void  func_02082A90(void *dest, const void *src, u32 size);
extern void  MI_CpuFill8(void *dest, u8 data, u32 size);
extern void  func_02087C6C(void *obj);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
void sub_0200E884(void *sys, void *src);
void sub_0200E89C(void *sys, void *dest);
u32 sub_0200E8B0(void);
void sub_0200E8B8(void *dest);
void sub_0200E8CC(void);
void *sub_0200E8D0(void *obj);
u32 sub_0200E8D8(const void *obj);
void sub_0200E8E0(void *obj, u32 value);
u32 sub_0200E8E8(void);
void sub_0200E8EC(void *dest);
void *sub_0200E8F8(void *sys);
void sub_0200E904(void *obj);
u8 sub_0200E918(const u8 *base, u32 idx);
void sub_0200E920(u8 *base, u32 idx, int delta);
void sub_0200E938(u8 *obj, u32 id, void *dest);
void sub_0200E958(u8 *obj, u32 id, const void *src);
void sub_0200E978(u8 *obj, u32 id, u32 extra, u8 value);
extern u8 func_0200E918(const u8 *base, u32 idx);
extern void func_0200E938(u8 *obj, u32 id, void *dest);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
u32 sub_0200E994(void *base, void *key);
extern void *g_020A7370;




/*
 * Fill slot idx of the 0x20-byte-stride record array that unit_0200E730's
 * ten accessors read (level in bits 1..7 of +0x1a, a "set" flag in bit 0,
 * the +0x1b byte or 0xff, words at +0 and +0x1c, an 11-u16 name at +4)
 * from a Pokemon via func_02017E1C: fields 0x9e, 0x71/0xa, 0, 7, then the
 * nickname (0x74) when field 0x75 says there is one, else the species name
 * (field 5) read out of the message bank at g_020A7370 into a stack buffer
 * and copied in.
 *
 * Two facts closed the 133-135-byte "pointer permutation" of the earlier
 * notes: the notes' struct had a stray pad byte before +0x1a (every field
 * from the bitfield on was one byte off), and every field is written as
 * o[idx].field rather than through a hoisted record pointer.  Written that
 * way mwcc keeps o and idx*32 in r5/r7 across all nine calls and CSEs
 * o + idx*32 into r4 for most, but not all, of the uses -- the image's
 * `adds r1, r5, r7` before the +0x1c store is exactly that.
 *
 * EXACT* because the listing extent runs over the unlabelled followers at
 * 0x0200E874/0x0200E878 (unit_0200E874.c); compiled bytes match exactly.
 */
void func_0200E7BC(struct Rec0200E7BC *o, int idx, void *mon)
{
    o[idx].bits.level = func_02017E1C(mon, 0x9e, 0);
    if (func_02017E1C(mon, 0x71, 0) != 0)
        o[idx].f1b = func_02017E1C(mon, 0xa, 0);
    else
        o[idx].f1b = 0xff;
    o[idx].f00 = func_02017E1C(mon, 0, 0);
    o[idx].f1c = func_02017E1C(mon, 7, 0);
    if (func_02017E1C(mon, 0x75, 0) != 0) {
        func_02017E1C(mon, 0x74, (u32)o[idx].name);
    } else {
        u16 buf[12];

        func_02045F5C(g_020A7370, func_02017E1C(mon, 5, 0), buf, 0xb);
        func_0201F41C(buf, o[idx].name, 0xb);
    }
    o[idx].bits.flag = 1;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * The twelve bytes after func_0200E7BC: two unlabelled leaves that save
 * nothing at all, so their bytes print as part of the same `.word` run as
 * the pool word in front of them (docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).  The first is a size
 * getter returning 0x10, the second is a tail call to the SDK's
 * MI_CpuFill8 (arm: the pool word is even, so `bx r3` switches to ARM) that
 * clears 0x10 bytes from whatever pointer it is handed.
 */
int sub_0200E874(void)
{
    return 0x10;
}


void sub_0200E878(void *dst)
{
    func_02082BCC(dst, 0, 0x10);
}



/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0200E8CC, sub_0200E8D0, sub_0200E8D8, sub_0200E8E0,
 *           sub_0200E8E8, sub_0200E8EC, sub_0200E8F8, sub_0200E904
 *
 * alias: twelve functions on the same big object as unit_0200E938.c, all
 * working the same field at +0x6200/+0x6204.  sub_0200E884 and sub_0200E89C
 * are a copy-in/copy-out pair around a 0x10-byte scratch object obtained
 * from sub_020071CC(id 0x40); sub_0200E8B0 hands back the constant 0x6204,
 * which sub_0200E8B8 uses as the zero-fill size for the whole object;
 * sub_0200E8CC is an empty hook; sub_0200E8D0 hands out the address 0x6000
 * bytes into the object; sub_0200E8D8/sub_0200E8E0 are a plain word
 * getter/setter on the field at +0x6200; sub_0200E8E8 returns the constant
 * 0x5c, which sub_0200E8EC's tail call to MI_CpuFill8 also uses directly
 * (the same 0x5c constant this compiler would otherwise route through
 * sub_0200E8E8, but the tail call inlines it); sub_0200E8F8 tail calls
 * sub_020071CC(sys, 0x41); sub_0200E904 zero-fills a separate 0x5a-byte
 * scratch object and hands it to func_02087C6C.
 *
 * Four of the twelve carry no label in the generated listing: they are
 * two- and three-instruction leaves with no register-saving prologue, so
 * disasm.py's sweep never fires on them and the listing prints them as a
 * run of .word data between two literal pools.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * This file merges what used to be four single-function files
 * (sub_0200E884.c, sub_0200E89C.c, sub_0200E8B0.c, sub_0200E904.c) and
 * unit_0200E8B8.c: the five are contiguous in the image with no gap and no
 * intervening matched/sdk address, and the whole 0x0200E884..0x0200E918
 * range still reproduces EXACT as a single translation unit.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E884.c \
 *       --addr 0x0200E884 --thumb
 */
void sub_0200E884(void *sys, void *src)
{
    void *obj = sub_020071CC(src, 0x40);
    func_02082A90(sys, obj, 0x10);
}



void sub_0200E89C(void *sys, void *dest)
{
    void *obj = sub_020071CC(sys, 0x40);
    func_02082A90(obj, dest, 0x10);
}



u32 sub_0200E8B0(void)
{
    return 0x6204;
}



void sub_0200E8B8(void *dest)
{
    MI_CpuFill8(dest, 0, sub_0200E8B0());
}



void sub_0200E8CC(void)
{
}



void *sub_0200E8D0(void *obj)
{
    return (u8 *)obj + 0x6000;
}



u32 sub_0200E8D8(const void *obj)
{
    return *(const u32 *)&((struct Obj17085 *)obj)->f6200;
}



void sub_0200E8E0(void *obj, u32 value)
{
    ((struct Obj17086 *)obj)->f6200 = value;
}



u32 sub_0200E8E8(void)
{
    return 0x5c;
}



void sub_0200E8EC(void *dest)
{
    MI_CpuFill8(dest, 0, 0x5c);
}



void *sub_0200E8F8(void *sys)
{
    return sub_020071CC(sys, 0x41);
}



void sub_0200E904(void *obj)
{
    MI_CpuFill8(obj, 0, 0x5a);
    func_02087C6C(obj);
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: a byte array at offset 6 of some base object, indexed by the second
 * parameter.  sub_0200E918 is the plain getter; sub_0200E920 adds a signed
 * delta to one element and clamps the result to 0..255 before storing it
 * back.  sub_0200E918 has no register-saving prologue (two instructions, no
 * push), so disasm.py's sweep never labelled it; it sits in the listing as a
 * .word between two functions.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E918.c \
 *       --addr 0x0200E918 --thumb
 */
u8 sub_0200E918(const u8 *base, u32 idx)
{
    return (base + idx)[6];
}



void sub_0200E920(u8 *base, u32 idx, int delta)
{
    u8 *p = base + 6;
    int v = p[idx] + delta;

    if (v > 0xff) {
        v = 0xff;
    } else if (v < 0) {
        v = 0;
    }
    p[idx] = (u8)v;
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: three accessors on an array of 6-byte records that starts 0xa bytes
 * into the object, indexed by "id mod 10".  sub_0200E938 reads a record out,
 * sub_0200E958 stores one in, and sub_0200E978 writes a single byte field at
 * +0x10 past an extra caller-given offset from the same slot.  Each divides
 * by 10 for the remainder only; the
 * quotient the helper also returns is never used, per
 * docs/idioms/div-and-mod-are-two-calls.md and
 * docs/idioms/runtime-helper-reloc.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E938.c \
 *       --addr 0x0200E938 --thumb
 */
void sub_0200E938(u8 *obj, u32 id, void *dest)
{
    u32 idx = id % 10;

    MI_CpuCopy8(obj + 0xa + idx * 8, dest, 6);
}



void sub_0200E958(u8 *obj, u32 id, const void *src)
{
    u32 idx = id % 10;

    MI_CpuCopy8(src, obj + 0xa + idx * 8, 6);
}



void sub_0200E978(u8 *obj, u32 id, u32 extra, u8 value)
{
    u32 idx = id % 10;
    u8 *p = obj + idx * 8;

    p += extra;
    p[0x10] = value;
}


/*
 * Linear search over up to 10 stored 6-byte keys: func_0200E918(base, 0)
 * gives the stored count (capped at 10), func_0200E938 copies the i'th key
 * into a stack buffer, and func_0203EFC8 (DWC's own key comparator)
 * compares it against the caller's key. Returns 1 on the first match, 0
 * if none of the stored keys match.
 *
 * EXACT* because the 70 compiled bytes fall six short of the disasm.py
 * extent: sub_0200E9DC, a four-byte constant getter with no
 * register-saving prologue, hides in the two trailing pad bytes plus this
 * function's own alignment filler (see "the two missing labels" in
 * docs/MATCHING.md); it is matched separately.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200E994.c \
 *       --func sub_0200E994 --addr 0x0200E994 --cc 1.1p1
 */
u32 sub_0200E994(void *base, void *key)
{
    int i;
    int count = func_0200E918(base, 0);
    u8 buf[6];

    if (count > 10) {
        count = 10;
    }

    for (i = 0; i < count; i++) {
        func_0200E938(base, i, buf);
        if (func_0203EFC8(key, buf, 6) == 0) {
            return 1;
        }
    }
    return 0;
}
