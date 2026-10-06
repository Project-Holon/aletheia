/*
 * function: func_0200F234
 * address:  0x0200F234
 * packet:   pkt_0200F17C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id sites
 *           ov_id_72 (114) and ov_id_0E (14) resolve as `overlay_id` (a
 *           layout overlay index, loaded by a pc-relative load of this
 *           function, reaching the id register of a known overlay loader),
 *           which was the last blocker.
 *
 * symbols:
 *   func_02034A5C  0x02034A5C  arm
 *   func_02034AC4  0x02034AC4  arm
 *   ov_id_72       0x00000072  data
 *   ov_id_09       0x00000009  data
 *   ov_id_0D       0x0000000D  data
 *   ov_id_0A       0x0000000A  data
 *   ov_id_0B       0x0000000B  data
 *   ov_id_0E       0x0000000E  data
 *   ov_id_0F       0x0000000F  data
 *
 * The argument constants are absolute symbols, not numbers: every one of the
 * fifteen argument positions in the image loads its value from a literal pool
 * (`ldr r0, [pc]`), and mwccarm materialises any literal in 0..255 with
 * `movs`.  See docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 * The cases are written in the memory order of the arms (6, 1, 2, 0/5, 3/4).
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef signed int     s32;
extern void func_02034A5C(s32 handle);
extern int func_02034AC4(s32 handle);

extern u8 ov_id_72[];
extern u8 ov_id_09[];
extern u8 ov_id_0D[];
extern u8 ov_id_0A[];
extern u8 ov_id_0B[];
extern u8 ov_id_0E[];
extern u8 ov_id_0F[];

void func_0200F234(u32 sel)
{
    switch (sel) {
    case 6:
        func_02034A5C((u32)ov_id_72);
        func_02034A5C((u32)ov_id_09);
        func_02034A5C((u32)ov_id_0D);
        func_02034AC4((u32)ov_id_0A);
        func_02034AC4((u32)ov_id_0B);
        break;
    case 1:
        func_02034A5C((u32)ov_id_09);
        func_02034A5C((u32)ov_id_0D);
        func_02034AC4((u32)ov_id_0A);
        func_02034AC4((u32)ov_id_0B);
        break;
    case 2:
        func_02034A5C((u32)ov_id_09);
        func_02034A5C((u32)ov_id_0D);
        func_02034AC4((u32)ov_id_0A);
        func_02034AC4((u32)ov_id_0B);
        break;
    case 0:
    case 5:
        func_02034A5C((u32)ov_id_0E);
        break;
    case 3:
    case 4:
        func_02034A5C((u32)ov_id_0F);
        break;
    }
}
