/*
 * file:     unit_0204F2FC.c
 * unit:     yes
 * function: func_0204F2FC, func_0204F32C, func_0204F344, func_0204F428, func_0204F5A8, func_0204F5E4, func_0204F604, func_0204F638, func_0204F654, func_0204F66C, func_0204F684, func_0204F6B4
 * address:  0x0204F2FC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 */
#include "../../matched/include/Obj16133.h"
#include "../../matched/include/Obj16135.h"
#include "../../matched/include/Obj16136.h"
#include "../../matched/include/Obj08866.h"
#include "../../matched/include/Obj16139.h"
#include "../../matched/include/Obj16141.h"
#include "../../matched/include/Obj16142.h"
#include "../../matched/include/Obj17359.h"
#include "../../matched/include/Obj17361.h"
#include "../../matched/include/Obj17363.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

struct Rec_0204F344 {
    u8  pad00[4];
    u16 hw;         /* +0x04 */
    u8  pad06[2];
    u8  x;          /* +0x08 */
    u8  y;          /* +0x09 */
    u8  pad0a[0xa];
    u32 f14;        /* +0x14 */
};

typedef signed int     s32;

struct Vec3 { s32 a, b, c; };

struct Elem {
    u16 id   : 14;
    u16 mode : 2;
    u16 f02;
    struct Vec3 f04;
    u16 f10;
    u16 f12;
    u16 f14;
    u16 f16;
    u16 k    : 5;
    u16 b5   : 4;
    u16 b9   : 1;
    u16 b10  : 1;
    u16 b11  : 1;
    u16 w    : 4;
    u16 f1a;
};

struct Board {
    u8 pad00[8];
    struct Elem *ptr1;
    u16 count0;
    u16 count1;
};

struct Rec {
    u16 lo : 14;
    u16 hi : 2;
};

struct F14 {
    u16 f0 : 14;
    u16 f1 : 2;
};

struct Trip {
    u32 a;
    u32 b;
    u32 c;
};

struct Ent_0204F638 {
    u8  pad_00[0x18];
    u16 f18;
    u8  pad_1a[2];
};

typedef struct { char pad[0x10]; u16 f10; char pad2[0xA]; } E1C_0204F654;

typedef struct { int pad[2]; E1C_0204F654 *f8; } Mgr_0204F654;

typedef short s16;

struct Item0204F684 {
    char pad[0x12];
    s16 field_12;
    s16 field_14;
    char pad2[6];
};

struct Manager0204F684 {
    char pad[8];
    struct Item0204F684 *items;
};

struct Ent_0204F6B4 {
    u8  pad_00[0x18];
    u16 f0 : 5;      /* +0x18 bit 0, five bits  */
    u16 f1 : 4;      /* +0x18 bit 5, four bits  */
    u16 f2 : 1;      /* +0x18 bit 9             */
    u16 f3 : 6;      /* +0x18 bit 10, the rest  */
    u8  pad_1a[2];
};

void func_0204F2FC(u8 *p, int i, u32 value);
void func_0204F32C(int p0, int p1, int p2);
void func_0204F344(void *a0, u32 a1, int a2, int *out, int *in, u8 flag);
void func_0204F5A8(void *p, u32 idx);
void func_0204F5E4(u8 *a0, u32 i, u16 *out);
void func_0204F604(void *p, u32 idx, u16 *src);
void func_0204F654(Mgr_0204F654 *p, int i, u16 *out);
void func_0204F66C(int p0, int p1, int p2);
void func_0204F6B4(u8 *a0, int i, u8 *px);
void func_0204F6DC(u8 *a0, int i, u8 *px);
u32 func_0204F704(u8 *a0, int i);

void func_0204F2FC(u8 *p, int i, u32 value)
{
    u32 off = i * 40;
    *(u32 *)(*(u8 **)(p + 4) + off + 32) = value;
    *(u32 *)(*(u8 **)(p + 4) + off + 12) = (*(u32 *)(*(u8 **)(p + 4) + off + 32) << 16) >> 13;
}

void func_0204F32C(int p0, int p1, int p2){ *(int *)p2 = *(int *)(((p1 * 0x28 + *(int *)(p0 + 4)) + 36)); }


void func_0204F344(void *a0, u32 a1, int a2, int *out, int *in, u8 flag)
{
    struct Rec_0204F344 *p =
        (struct Rec_0204F344 *)(*(u8 * *)&((struct Obj16133 *)a0)->f4 + a1 * 0x28);
    int q;

    switch (p->f14) {
    case 3:
        *in = p->y * ((p->x << 5) / 8) / 8;
        break;
    case 1:
    case 4:
    case 6:
        *in = p->y * ((p->x << 6) / 8) / 8;
        break;
    case 2:
        *in = p->y * ((p->x << 4) / 8) / 8;
        break;
    }
    if (flag == 0) {
        *out = a2 * *in;
        return;
    }
    q = a2 / p->hw;
    *out = *in * q + p->x * (a2 % p->hw);
}


/*
 * billboard.c: allocate a free 0x1c-byte element (id field 0x3FFF = free)
 * and initialise it.  Every earlier residue came from spelling the two
 * packed halfwords as hand masks; the source is plain bitfield assignment
 * (14/2 at +0x00, 5/4/1/1/1/4 at +0x18), in the image's store order.
 */
s32 func_0204F428(struct Board *b, u32 id, u16 v12, u16 v14, struct Vec3 *src, u8 k, u32 w, u32 mode)
{
    s32 i;

    for (i = 0; i < b->count1; i++) {
        if (b->ptr1[i].id == 0x3FFF) {
            b->ptr1[i].id = (u16)id;
            b->ptr1[i].mode = (u16)mode;
            b->ptr1[i].f12 = v12;
            b->ptr1[i].f14 = v14;
            b->ptr1[i].f16 = 0;
            b->ptr1[i].f04 = *src;
            b->ptr1[i].k = k;
            b->ptr1[i].b5 = 0;
            b->ptr1[i].b9 = 0;
            b->ptr1[i].w = (u16)w;
            b->ptr1[i].b10 = 0;
            b->ptr1[i].b11 = 0;
            b->ptr1[i].f10 = 0;
            return i;
        }
    }
    return 0;
}


/*
 * If the low 14 bits of the u16 at the record field are not already all ones,
 * set them and leave the top two bits alone.  The 14-bit width only survives to
 * a plain lsl/lsr pair as a bitfield: a mask in C would need the value in a
 * register first (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 */
void func_0204F5A8(void *p, u32 idx)
{
    struct Rec *r = (struct Rec *)(*(u8 * *)&((struct Obj16135 *)p)->f8 + idx * 0x1c);

    if (r->lo != 0x3fff) {
        r->lo = 0x3fff;
    }
}


/*
 * Fourteen-bit field getter on the 0x1c-byte entries at +8: the shift pair
 * is an equal `lsl #0x12` / `lsr #0x12`, i.e. a mask that is not an ARM
 * immediate, and the stride is spelled as byte arithmetic so it comes out as
 * `mul` rather than `mla`.
 */
void func_0204F5E4(u8 *a0, u32 i, u16 *out)
{
    *out = ((struct F14 *)((u8 *)((struct Obj16136 *)a0)->f8 + i * 0x1c))->f0;
}


/*
 * Same record and field as func_0204F5A8, but the low 14 bits are copied
 * in from the caller's u16.  The compiler reuses the inverted mask it
 * already needed as `lsr #18` rather than materialising 0x3fff twice.
 */
void func_0204F604(void *p, u32 idx, u16 *src)
{
    u16 *q = (u16 *)(*(u8 * *)&((struct Obj08866 *)p)->f8 + idx * 0x1c);

    *q = (u16)((*q & ~0x3fff) | (*src & 0x3fff));
}


/*
 * Twelve-byte aggregate copy out of the caller's record into offset +4 of
 * one 0x1c-byte entry: one `ldm`/`stm` of three registers.
 */
void func_0204F638(u8 *a0, int i, struct Trip *src)
{
    struct Ent_0204F638 *e = &((struct Ent_0204F638 *)((struct Obj16139 *)a0)->f8)[i];

    *(struct Trip *)((u8 *)e + 4) = *src;
}


/*
 * Leaf witness for ov021 0x021BBF10 / 0x021BC138 (lane wA1-12).
 */
void func_0204F654(Mgr_0204F654 *p, int i, u16 *out)
{
    *out = p->f8[i].f10;
}


void func_0204F66C(int p0, int p1, int p2){ *(unsigned short *)(((p1 * 0x1c + ((struct Obj16141 *)p0)->f8) + 16)) = (unsigned short)((struct Obj16142 *)p2)->f0; }


void func_0204F684(struct Manager0204F684 *mgr, int idx, const s16 *p12, const s16 *p14)
{
    mgr->items[idx].field_12 = *p12;
    mgr->items[idx].field_14 = *p14;
}


/*
 * The three accessors that follow func_0204F684, 0x0204F6B4..0x0204F720, on
 * the three bitfields of the packed halfword at +0x18 of one 0x1c-byte entry
 * of the descriptor's +8 array: five bits at bit 0, four bits at bit 5, and
 * the single bit at bit 9.
 *
 * All three are unlabelled in the generated listing, because none of them
 * saves a register in a prologue and `disasm.py` only auto-labels a function
 * whose prologue saves `lr`
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  They were
 * read out of the bytes; the range is contiguous and this unit reproduces all
 * 108 bytes of it.
 *
 * Each one is a read-modify-write of the whole halfword, which is what a
 * bitfield assignment costs: `ldrh` the word, `bic` the field's mask out,
 * `orr` the shifted new value in, `strh` it back.  The widths and positions of
 * the three fields are exactly the masks in the image (0x1f at bit 0,
 * 0x1e0 at bit 5, bit 9 read with `lsl #22` / `lsr #31`), so nothing about the
 * field layout is guessed.
 */
void func_0204F6B4(u8 *a0, int i, u8 *px)
{
    struct Ent_0204F6B4 *e = &((struct Ent_0204F6B4 *)((struct Obj17359 *)a0)->f8)[i];

    e->f0 = *px;
}


/*
 * The three accessors that follow func_0204F684, 0x0204F6B4..0x0204F720, on
 * the three bitfields of the packed halfword at +0x18 of one 0x1c-byte entry
 * of the descriptor's +8 array: five bits at bit 0, four bits at bit 5, and
 * the single bit at bit 9.
 *
 * All three are unlabelled in the generated listing, because none of them
 * saves a register in a prologue and `disasm.py` only auto-labels a function
 * whose prologue saves `lr`
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  They were
 * read out of the bytes; the range is contiguous and this unit reproduces all
 * 108 bytes of it.
 *
 * Each one is a read-modify-write of the whole halfword, which is what a
 * bitfield assignment costs: `ldrh` the word, `bic` the field's mask out,
 * `orr` the shifted new value in, `strh` it back.  The widths and positions of
 * the three fields are exactly the masks in the image (0x1f at bit 0,
 * 0x1e0 at bit 5, bit 9 read with `lsl #22` / `lsr #31`), so nothing about the
 * field layout is guessed.
 */
void func_0204F6DC(u8 *a0, int i, u8 *px)
{
    struct Ent_0204F6B4 *e = &((struct Ent_0204F6B4 *)((struct Obj17361 *)a0)->f8)[i];

    e->f1 = *px;
}


/*
 * The three accessors that follow func_0204F684, 0x0204F6B4..0x0204F720, on
 * the three bitfields of the packed halfword at +0x18 of one 0x1c-byte entry
 * of the descriptor's +8 array: five bits at bit 0, four bits at bit 5, and
 * the single bit at bit 9.
 *
 * All three are unlabelled in the generated listing, because none of them
 * saves a register in a prologue and `disasm.py` only auto-labels a function
 * whose prologue saves `lr`
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  They were
 * read out of the bytes; the range is contiguous and this unit reproduces all
 * 108 bytes of it.
 *
 * Each one is a read-modify-write of the whole halfword, which is what a
 * bitfield assignment costs: `ldrh` the word, `bic` the field's mask out,
 * `orr` the shifted new value in, `strh` it back.  The widths and positions of
 * the three fields are exactly the masks in the image (0x1f at bit 0,
 * 0x1e0 at bit 5, bit 9 read with `lsl #22` / `lsr #31`), so nothing about the
 * field layout is guessed.
 */
u32 func_0204F704(u8 *a0, int i)
{
    struct Ent_0204F6B4 *e = &((struct Ent_0204F6B4 *)((struct Obj17363 *)a0)->f8)[i];

    return e->f2;
}
