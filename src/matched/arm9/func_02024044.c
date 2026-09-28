/*
 * unit:     no
 * function: func_02024044
 * address:  0x02024044
 * packet:   pkt_02024044
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * pmsi_param.c's constructor (the __FILE__ anchor at 0x020A745C reads
 * "pmsi_param.c", line 0x56).  Allocates the 0x20-byte parameter object,
 * hangs two sub-objects off it, seeds the flag byte at +3 and then takes
 * one of two initialisation paths on `kind`.
 *
 * Four spellings are load-bearing and each was isolated against the bytes:
 *   - `hh` is a u32 parameter narrowed by an EXPLICIT (u16) cast at the
 *     allocator call.  A u16 parameter gives `ldrh` at +0x08 where the
 *     original loads a full word and narrows with lsls/lsrs #0x10.
 *   - func_020142E8 returns u32 and the result is narrowed by an explicit
 *     (u8) cast before the bitfield store.  Declaring the return u8 folds
 *     the `lsls #0x18 / lsrs #0x18` pair away and loses 4 bytes.
 *   - `flag` is likewise u32 with an explicit (u8) cast into the bitfield:
 *     the original's `lsls r2,r7,#0x18 / lsrs r2,r2,#0x18` is that cast,
 *     and the following `lsls #0x1f / lsrs #0x1c` is the 1-bit bitfield at
 *     bit 3 (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 *   - 0x02082D44 is called (src, dest, size), i.e. MI_CpuCopy8's order, not
 *     memcpy's: the original loads r0 from `src` and r1 from `o + 0x10`.
 *     Spelling it memcpy(dst, src, n) swaps r0/r1 and costs two bytes.
 *
 * `o->b0 = ...` and `o->b1 = 0` must stay two separate bitfield writes
 * (bics/orrs then bics), not a folded mask.
 *
 * EXACT*: the inferred extent runs to 344 bytes because the follower at
 * 0x020240F4 is the unlabelled 8-byte thunk func_020240FC and the run of
 * unlabelled leaf accessors after it (they save no lr, so disasm.py never
 * labels them).  The compiled 184 bytes are byte-identical.  Unlabelled
 * follower to seed into layout/function_starts.txt: 0x020240F4.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020071CC  0x020071CC  thumb
 *   func_02024988  0x02024988  thumb
 *   func_02012FE4  0x02012FE4  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_020242A4  0x020242A4  thumb
 *   MI_CpuCopy8    0x02082D44  arm
 *   file_020A745C  0x020A745C  data
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02024044.c \
 *       --func func_02024044 --addr 0x02024044 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct Obj {
    u8  kind;        /* +0x00 */
    u8  f01;         /* +0x01 */
    u8  f02;         /* +0x02 */
    u8  b0 : 1;      /* +0x03 */
    u8  b1 : 1;
    u8  b2 : 1;
    u8  b3 : 1;
    u8  rest : 4;
    u8  pad04[4];
    void *f08;       /* +0x08 */
    void *f0c;       /* +0x0c */
    u8  slot[8];     /* +0x10 */
    u16 f18[2];      /* +0x18 */
};

extern void *func_02030734(u32 heap, u32 sz, u32 c, void *file, u32 line);
extern void *func_020071CC(void *sys, u32 id);
extern void *func_02024988(void *sys);
extern u32   func_02012FE4(void *sys);
extern u32   func_020142E8(u32 a, u32 b);
extern void  func_020242A4(void *obj, u32 id);
extern void MI_CpuCopy8(const void *src, void *dst, u32 n);

extern u8 file_020A745C[];

struct Obj *func_02024044(u32 kind, u32 a1, void *src, u32 flag,
                          void *sys, u32 hh)
{
    struct Obj *o;
    s32 i;

    o = (struct Obj *)func_02030734((u16)hh, 0x20, 1, file_020A745C, 0x56);
    o->kind = (u8)kind;
    o->f08 = func_020071CC(sys, 0x37);
    o->f0c = func_02024988(sys);
    o->b0 = (u8)func_020142E8(func_02012FE4(sys), 0x960);
    o->b1 = 0;
    o->f01 = 1;
    o->f02 = 0;
    o->b3 = (u8)flag;
    if (kind == 2) {
        if (src == 0) {
            func_020242A4(o->slot, 0);
        } else {
            MI_CpuCopy8(src, o->slot, 8);
            o->b2 = 1;
        }
    } else {
        for (i = 0; i < 2; i++) {
            o->f18[i] = 0xFFFF;
        }
    }
    return o;
}
