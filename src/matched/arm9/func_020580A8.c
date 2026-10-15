/*
 * function: func_020580A8
 * address:  0x020580A8
 * packet:   pkt_02057F8C
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   FX_SinCosTable_     0x020A1B38  data
 *   func_0207AF00  0x0207AF00  thumb
 *   func_0207AF1C  0x0207AF1C  thumb
 *   func_0207AF38  0x0207AF38  thumb
 *   MTX_MultVec33  0x0207B51C  arm
 *
 * wave r8 lane rigD: first compile, EXACT under ../1.2/sp2 -proc arm946e.
 * The r6 note called this row "untouched" and predicted five label-class
 * relocation sites; all five resolve (four branch, one literal), and the
 * shared table is one symbol for all three cases.
 *
 * The two spellings that matter:
 *  - the three cases are identical apart from the callee, so each arm
 *    re-reads `idx = o->f00 >> 4;` (hoisting it above the switch costs the
 *    asr slot).
 *  - the subscripts are `idx * 2` and `idx * 2 + 1`, not `idx`/`idx + 1`:
 *    both address the same halfwords, but the image forms the byte offsets
 *    from `lsl r2, r1, #1` + `add r1, r2, #1` + two `lsl #1`s, which is the
 *    `idx * 2` spelling (the `idx`/`idx + 1` spelling is 12 bytes short).
 */

typedef unsigned short u16;
typedef short s16;
typedef unsigned char u8;

struct Obj {
    u16 f00;
    u16 f02;
};

extern s16 FX_SinCosTable_[];
extern void func_0207AF00(u8 *buf, int a, int b);
extern void func_0207AF1C(u8 *buf, int a, int b);
extern void func_0207AF38(u8 *buf, int a, int b);
extern void MTX_MultVec33(u8 *a, u8 *b, u8 *c);

void func_020580A8(struct Obj *o, u8 *dst)
{
    u8 buf[0x28];
    int idx;

    switch (o->f02) {
    case 0:
        idx = o->f00 >> 4;
        func_0207AF00(buf, FX_SinCosTable_[idx * 2], FX_SinCosTable_[idx * 2 + 1]);
        break;
    case 1:
        idx = o->f00 >> 4;
        func_0207AF1C(buf, FX_SinCosTable_[idx * 2], FX_SinCosTable_[idx * 2 + 1]);
        break;
    case 2:
        idx = o->f00 >> 4;
        func_0207AF38(buf, FX_SinCosTable_[idx * 2], FX_SinCosTable_[idx * 2 + 1]);
        break;
    }

    MTX_MultVec33(dst + 8, buf, dst + 8);
}
