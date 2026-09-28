/*
 * function: func_02030A7C
 * address:  0x02030A7C
 * packet:   pkt_02030A7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *           8 of 10 relocation sites resolved.  Down from 3 unresolved sites to 2.
 * blocker:  ABS32 g_02146970 at +0xC8: 0x02146970 has 1 witness image-wide (a pool word at 0x02030B44), inside this extent
 * blocker:  (CLEARED 2026-09-21) ABS32 str_system_name at +0xCC now RESOLVES on
 *           sole-ref x1 -- the class was widened 2026-09-21 to accept an address that
 *           lands on something the layout recognises, and 0x020A7824 is the start of a
 *           NUL-terminated printable run (sole-ref/string).  The note below about
 *           attest_string() refusing it is still accurate for the OLD `string` class
 *           and is kept for the record, but it no longer blocks this file.
 * blocker:  ABS32 g_0214697C at +0xD0: 0x0214697C has 1 witness image-wide (a pool word at 0x02030B4C), inside this extent
 * symbols:
 *   g_02146970      0x02146970  data
 *   g_0214697C      0x0214697C  data
 *   str_system_name 0x020A7824  data
 *   func_020304C0   0x020304C0  arm
 *   func_02060F90   0x02060F90  arm
 *   func_020308B8   0x020308B8  arm
 *   func_0203F004   0x0203F004  arm
 *   MI_CpuCopy8     0x02082D44  arm
 *
 * Fills in the allocator's bookkeeping object at 0x02146970 (u16 tag, two
 * pointers, then an 18-character name buffer at 0x0214697C) and names the
 * block it was handed.  The block's own id is read out of the block header
 * (+0x12, a u16 halfword) when func_020308B8 finds a name for the scratch
 * buffer, and the buffer is otherwise loaded with the 13-byte default
 * "SYSTEM ALLOC" at 0x020A7824 and tagged 0.  That name is then copied into
 * the object's name buffer (length + 1) and space-padded out to 18 columns
 * with the terminator at the padding boundary, which is why the loop is
 * written as a guarded `do` with the index left over for the final store.
 *
 * Every byte of the 212-byte extent matches, relocation fields aside: this
 * file compiles to 212 bytes of which 200 are code, exactly the original's
 * shape, and match.py's only complaint is the three wildcarded pool words
 * below.  All three are data:
 *
 *  - 0x02146970 and 0x0214697C are bss addresses (bss runs from 0x020A9E80
 *    to 0x021542C0 and is not part of this image), so nothing disassembles
 *    there and the only evidence class that can ever name them is `literal`.
 *  - 0x020A7824 is the "SYSTEM ALLOC" string.  The `string` class refuses
 *    it: the four bytes immediately before it are FF FF FF FF (a word
 *    alignment filler between it and the preceding "time_icon.c"), and
 *    attest_string() requires NUL padding directly before the run, not
 *    another string's terminator four bytes away.  `data_table` refuses it
 *    as well -- 0x54535953 is not a pointer into a loaded region.
 *
 * So the function's own literal pool is the only thing in the image that
 * holds these three values: each has exactly one pool word image-wide
 * (0x02030B44, 0x02030B48, 0x02030B4C) and all three sit inside the
 * function's own extent, where the honesty rule refuses them as witnesses.
 * `--suggest-split` returns 0 pieces and leaves the single function out:
 * there is no cut that frees a site, because this function is the whole
 * range.  The three addresses are unwitnessable at any spelling of the C --
 * the pass is only reachable when some *other* matched function happens to
 * pool one of them, and nothing else in the image references them.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02030A7C.c \
 *       --func func_02030A7C --addr 0x02030A7C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

struct AllocInfo {
    u16 unk_00;
    u16 pad_02;
    void *unk_04;
    void *unk_08;
    char name[0x13];
};

extern struct AllocInfo g_02146970;
extern char g_0214697C[0x13];
extern const char str_system_name[];

extern void *func_020304C0(void *p);
extern void *func_02060F90(void *p);
extern s32 func_020308B8(void *buf, void *h);
extern u32 func_0203F004(const u8 *s);
extern void MI_CpuCopy8(const void *src, void *dst, u32 n);

void func_02030A7C(void *heap)
{
    u8 buf[0x14];
    u8 *p = (u8 *)heap + 0x1c;
    void *h = func_020304C0(p);
    u16 v;
    s32 n;
    s32 k;
    s32 i;

    g_02146970.unk_08 = func_02060F90(heap);
    g_02146970.unk_04 = p;
    if (func_020308B8(buf, h) != 0) {
        v = *(u16 *)((u8 *)h + 0x12);
    } else {
        MI_CpuCopy8(str_system_name, buf, 0xd);
        v = 0;
    }
    n = func_0203F004(buf);
    MI_CpuCopy8(buf, g_0214697C, n + 1);
    g_02146970.unk_00 = v;
    k = 0x12 - func_0203F004(buf);
    i = 0;
    if (k > 0) {
        do {
            buf[i] = ' ';
            i++;
        } while (i < k);
    }
    buf[i] = 0;
}
