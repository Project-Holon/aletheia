/*
 * function: func_0200F17C
 * address:  0x0200F17C
 * packet:   pkt_0200F17C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 *
 * symbols:
 *   func_02034A5C  0x02034A5C  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_0215536C  0x0215536C  thumb
 *   func_02177020  0x02177020  thumb
 *   func_021798D4  0x021798D4  thumb
 *   ov_id_0A       0x0000000A  data
 *   ov_id_0B       0x0000000B  data
 *   ov_id_09       0x00000009  data
 *   ov_id_0D       0x0000000D  data
 *   ov_id_72       0x00000072  data
 *   ov_id_0E       0x0000000E  data
 *   ov_id_0F       0x0000000F  data
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
 * blocker:  five sites stay wildcarded, all of them calls into overlays whose
 *           only branch anywhere in the image is the one inside this range:
 *           0x0215536C (x3), 0x02177020 and 0x021798D4.  Two overlays hold
 *           each address (ov009, ov010) and neither carries a func_ label, so
 *           the `label` class has no site to point at and no cut helps.
 *           Blocking class: label (overlay), permanent.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0200F17C.c \
 *       --func func_0200F17C --addr 0x0200F17C --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02034A5C(u32 v);
extern void func_02034AC4(u32 v);
extern int  func_0215536C(void);
extern int  func_02177020(void);
extern int  func_021798D4(void);

extern u8 ov_id_0A[];
extern u8 ov_id_0B[];
extern u8 ov_id_09[];
extern u8 ov_id_0D[];
extern u8 ov_id_72[];
extern u8 ov_id_0E[];
extern u8 ov_id_0F[];

int func_0200F17C(u32 sel)
{
    switch (sel) {
    case 6:
        func_02034A5C((u32)ov_id_0A);
        func_02034A5C((u32)ov_id_0B);
        func_02034AC4((u32)ov_id_09);
        func_02034AC4((u32)ov_id_0D);
        func_02034AC4((u32)ov_id_72);
        return func_0215536C();
    case 1:
        func_02034A5C((u32)ov_id_0A);
        func_02034A5C((u32)ov_id_0B);
        func_02034AC4((u32)ov_id_09);
        func_02034AC4((u32)ov_id_0D);
        return func_0215536C();
    case 2:
        func_02034A5C((u32)ov_id_0A);
        func_02034A5C((u32)ov_id_0B);
        func_02034AC4((u32)ov_id_09);
        func_02034AC4((u32)ov_id_0D);
        return func_0215536C();
    case 0:
    case 5:
        func_02034AC4((u32)ov_id_0E);
        return func_02177020();
    case 3:
    case 4:
        func_02034AC4((u32)ov_id_0F);
        return func_021798D4();
    }
    return 0;
}
