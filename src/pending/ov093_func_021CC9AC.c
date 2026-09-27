/*
 * function: func_021CC9AC
 * address:  0x021CC9AC
 * packet:   pkt_ov093_021CC9AC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Bottom-up unblocker for the tail-call target of func_021C88A4 (and the five
 * parked callers of that wrapper).  Small record packer: look `key` up in a
 * 0x3b-entry (key,size) byte pair table, round the size up to 4, append a
 * record at the header's 9-bit used-offset field, and return a pointer to it.
 * Addresses are Black-image addresses.
 *
 * Re-verified 2026-09-27 (recursive MATCH unblocker, ov212/ov093 band).  The
 * two data relocations DO resolve, contrary to the earlier park note: both
 * pool words at +0xB0/+0xB4 resolve `sole-ref` (`self:0x021EFE9C`,
 * `self:0x021EFE9D`) because the ROM word at each site already names the
 * table.  The verdict is DIFF, same 200-byte size, ~141-168 concrete bytes:
 * the allocator keeps `p` in r0 and `key` in r5 (image), while mwcc moves
 * `p` to r3 and `key` to r0 and puts `size` in r5 instead of r3.  Every
 * semantically equivalent spelling tried (param/local key, void-pointer or
 * struct-pointer param, one 2D table vs two arrays, two loop counters, declaration-order
 * permutations, `-proc arm7tdmi`) reproduces the swapped colouring, so this
 * is a codegen residue, not a witness gap.  Matching it would witness
 * src/pending/ov093_func_021C88A4.c via `matched`.
 * symbols:
 *   tbl_021EFE9C  0x021EFE9C  data  ov093
 *   tbl_021EFE9D  0x021EFE9D  data  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Hdr021CC9AC {
    u32 lo : 10;
    u32 off : 9;
    u32 hi : 13;
} Hdr021CC9AC;

typedef struct Rec021CC9AC {
    u32 key : 8;
    u32 b : 5;
    u32 size : 10;
    u32 f23 : 1;
    u32 f24 : 1;
    u32 f25 : 1;
    u32 f26 : 1;
    u32 f27 : 5;
} Rec021CC9AC;

extern const u8 tbl_021EFE9C[];
extern const u8 tbl_021EFE9D[];

void *func_021CC9AC(void *vp, int key, int b)
{
    Hdr021CC9AC *p = (Hdr021CC9AC *)vp;
    u32 i;
    u32 size = 0;
    u32 off = p->off;
    Rec021CC9AC *r;

    for (i = 0; i < 0x3b; i++) {
        if (key == tbl_021EFE9C[i * 2]) {
            size = tbl_021EFE9D[i * 2];
            break;
        }
    }
    if (size == 0)
        return 0;
    while (size & 3)
        size++;
    if (off + size > 500)
        return 0;
    for (i = 0; i < size; i++)
        ((u8 *)p)[4 + p->off + i] = (u8)i;
    r = (Rec021CC9AC *)((u8 *)p + 4 + off);
    r->key = key;
    r->size = size;
    r->b = b;
    r->f23 = 0;
    r->f26 = 1;
    p->off = off + size;
    return (u8 *)p + 4 + off;
}
