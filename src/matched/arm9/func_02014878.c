/*
 * function: func_02014878
 * address:  0x02014878
 * packet:   pkt_02014808
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id sites
 *           ov091_id (91) and ov131_id (131) resolve as `overlay_id` (a
 *           layout overlay index, loaded by a pc-relative load of this
 *           function, reaching the id register of a known overlay loader),
 *           which was the last blocker.
 *
 * symbols:
 *   ov091_id        0x0000005B  data
 *   ov131_id        0x00000083  data
 *   g_021BED00      0x021BED00  data
 *   g_021DC800      0x021DC800  data
 *
 * A six-state machine on obj->f1e.  Every concrete byte matches: 152 of 152
 * against the listing extent, the two relocation sites that are attestable
 * (both calls) resolve as `label`, and both 0x021BED00/0x021DC800 pool words
 * resolve as `literal`; only the two small pooled words stay wildcarded.
 *
 * The small pooled words are the SDK's FS_OVERLAY_ID() shape (see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md): a
 * value that mwccarm materialises with `movs` for any literal in 0..255, and
 * therefore cannot be written as a number - the source passes an address the
 * linker resolved to 91 / 131, and is declared here as a symbol of that
 * absolute value.
 *
 * Two levers mattered, both from the wave-r6 list:
 *   * the switch value is read once into a local before the dispatch
 *     (`ldr r1, [r4]` before `cmp r1, #5`), which is what puts p[0] in r0;
 *   * a case that ends in "return 0" must `break` instead, so every arm
 *     shares the one epilogue at 0x020148FC instead of duplicating it.
 * The state-2 arm is three statements - `if (v == 0) { *mode = 5; break; }`,
 * `if (v == 1) { ...; *mode = 3; break; }` and a trailing `*mode = 5;` - and
 * only that spelling reproduces the arm's out-of-line `movs r0, #5` block at
 * 0x020148D2 with the second test as `bne` rather than `beq`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02014878.c \
 *       --func func_02014878 --addr 0x02014878 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Ctx;
struct IcaAnime;
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx *p);
extern u8   ov091_id[];
extern u8   ov131_id[];

u32 func_02014878(u32 a0, u32 *mode, u32 *p)
{
    u32 v = p[0];

    switch (*mode) {
    case 0:
        func_020120B4((struct IcaAnime *)v, (u32)ov091_id, (void *)0x021BED00, (void *)p[2]);
        *mode = 1;
        break;
    case 1:
        if (func_020120F0((const struct Ctx *)v) != 0)
            break;
        *mode = 2;
        break;
    case 2:
        if (*(u32 *)(p[2] + 0x40) == 0) {
            *mode = 5;
            break;
        }
        if (*(u32 *)(p[2] + 0x40) == 1) {
            *(u8 *)(p[3] + 0xf) = (u8)*(u32 *)(p[2] + 0x3c);
            *mode = 3;
            break;
        }
        *mode = 5;
        break;
    case 3:
        func_020120B4((struct IcaAnime *)v, (u32)ov131_id, (void *)0x021DC800, (void *)p[3]);
        *mode = 4;
        break;
    case 4:
        if (func_020120F0((const struct Ctx *)v) != 0)
            break;
        *(u32 *)(p[2] + 0x3c) = *(u8 *)(p[3] + 0xf);
        *mode = 0;
        break;
    case 5:
        return 1;
    default:
        break;
    }
    return 0;
}
