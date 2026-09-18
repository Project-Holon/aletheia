/*
 * function: func_02030238
 * address:  0x02030238
 * packet:   pkt_02030164
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * BLOCKED on one relocation site: all 100 concrete code bytes (108 with the
 * trailing pool) are correct, but the call to func_02061358 at +0048 has no
 * witness. 0x02061358 is the 20-byte record-initialiser in the NNS-shaped
 * library block around 0x02060000; it has exactly one branch reference in
 * the whole image and it is this call, so class `label` cannot carry it
 * (every witness would sit inside the compared range), no pool word
 * anywhere holds the address so `literal` is unavailable too, and the
 * bytes at 0x02061358 (ldr ip,[pc,#12]; mov r3,#0; str r12,[r0];
 * stmia r0,{r1,r2,r3}; bx lr) are not one of the recognised veneer
 * encodings. No cut exists inside a single function section, so a
 * --suggest-split over 0x02030164..0x020302A4 offers nothing either: that
 * two-function unit was run and caps at MATCH for this same one site
 * (8 of 9 relocations resolved, zero concrete byte differences). An EXACT
 * entry for 0x02061358 promotes this file unchanged.
 *
 * Initialise a block in the heap: the heap id is bit-15-flagged like
 * sub_02030098's, and the low fifteen bits select the arena to store.
 *
 *   u32 func_02030238(void *p, u32 heapId, s32 size)
 *
 * The length is normalised to positive and then re-signed by the heap's
 * direction flag, which is what the two conditional negations around the
 * `tst r1, #0x8000` are: `movs r5, r2` / `rsbmi r5, r5, #0` is abs() on a
 * named local (not the parameter -- the parameter stays in r2), and the
 * second `rsbne r5, r5, #0` is signed from the flag. The `and r0, r1, r0`
 * mask with 0x7fff is scheduled after the tst, so the mask constant costs
 * a pool word while the flag test is immediate.
 *
 * The arena is passed straight from sub_0202FBAC's return into r1 with no
 * local bound in between, so the call is the nested form
 * func_02061358(p, sub_0202FBAC(heapId & 0x7fff), len).
 *
 * symbols:
 *   g_EnvModule           0x02146954  data
 *   sub_0202FBAC          0x0202FBAC  arm
 *   func_02061358         0x02061358  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02030238.c \
 *       --func func_02030238 --addr 0x02030238 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

struct EnvEntry {
    void *ptr00;
    u32 field04;
    u32 field08;
    u16 field0c;
    u8  field0e;
};

struct EnvModule {
    struct EnvEntry *entries;
    u8 *ids;
    u16 count;
    u16 field0a;
    u16 field0c;
    u16 error;
};

extern struct EnvModule g_EnvModule;
extern void *sub_0202FBAC(u32 idx);
extern void func_02061358(void *p, void *arena, s32 len);

u32 func_02030238(void *p, u32 heapId, s32 size)
{
    s32 len;

    len = size;
    if (len < 0) {
        len = -len;
    }
    if (heapId & 0x8000) {
        len = -len;
    }
    if ((heapId & 0x7FFF) >= g_EnvModule.count) {
        g_EnvModule.error = 1;
        goto fail;
    }
    func_02061358(p, sub_0202FBAC(heapId & 0x7FFF), len);
    g_EnvModule.error = 0;
    return 1;

fail:
    return 0;
}
