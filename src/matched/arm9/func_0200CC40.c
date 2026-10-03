/*
 * function: func_0200CC40
 * address:  0x0200CC40
 * packet:   pkt_0200CC40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The reader half of func_0200CA98: find which form bit (rows +0x30E /
 * +0x317) and which of the four per-species rows (+0x1AC/+0x200/+0x254/
 * +0x2A8) are set for species `id`, report them through out1/out2/outForm,
 * then look the result up through func_0201ADE4 (docs/notes/
 * pkt_0200CC40.c.txt has the decode and the wave-11 form-loop work).
 *
 * Closed in wave 13 by two declaration facts:
 *   - `id` is a u16 PARAMETER.  The image homes r1 to [sp] and then RELOADS
 *     it for the first call (`str r1, [sp] ... ldr r0, [sp]`), the
 *     narrow-parameter tell (docs/idioms/a-narrow-parameter-pins-its-home-
 *     store-to-the-front-of-the-prologue.md); a u32 id copies r1 instead.
 *   - the per-species row tests go through their OWN helper that takes the
 *     1-based species id and forms `u16 x = id - 1` inside.  Each inlined
 *     copy has its own `x`, so the subtraction is shared but `x & 7` and
 *     `x >> 3` are rebuilt at every test, exactly the "rebuild at every
 *     join" the wave-11 note could not reproduce with one shared index.
 *     The two tests of an `||` pair still share the mask, as in the image.
 *
 * symbols:
 *   func_0200C7F4        0x0200C7F4  thumb
 *   func_0200C7C0        0x0200C7C0  thumb
 *   func_0200CA98_Table  0x0209DE4C  data
 *   func_0201ADE4        0x0201ADE4  thumb
 *   func_0201AE1C        0x0201AE1C  thumb
 *   func_0201AE14        0x0201AE14  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct FormCount {
    u16 id;
    u16 count;
};

extern const struct FormCount func_0200CA98_Table[];
extern u32 func_0200C7F4(u16 id);
extern u32 func_0200C7C0(u16 id);
extern void *func_0201ADE4(u32 a, int b, u32 c);
struct Personal;
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);

static inline u32 TestBit(const u8 *row, u16 x)
{
    return row[x >> 3] & (1 << (x & 7));
}

static inline u32 TestSpecies(const u8 *row, u32 id)
{
    u16 x = id - 1;
    return row[x >> 3] & (1 << (x & 7));
}

void func_0200CC40(u8 *p, u16 id, u32 *out1, u32 *out2, u32 *outForm, u16 a5)
{
    u32 idx;
    u32 base;
    u32 form;
    void *h;

    idx = func_0200C7F4(id);
    if (idx != (u32)-1) {
        base = func_0200C7C0(id);
        for (form = 0; form < func_0200CA98_Table[idx].count; form++) {
            if (TestBit(p + 0x30E, base + form)) {
                *outForm = form;
                *out2 = 0;
                break;
            }
            if (TestBit(p + 0x317, base + form)) {
                *outForm = form;
                *out2 = 1;
                break;
            }
        }
        if (TestSpecies(p + 0x1AC, id) || TestSpecies(p + 0x254, id)) {
            *out1 = 0;
        }
        if (TestSpecies(p + 0x200, id) || TestSpecies(p + 0x2A8, id)) {
            *out1 = 1;
        }
    } else {
        *outForm = 0;
        if (TestSpecies(p + 0x1AC, id)) {
            *out1 = 0;
            *out2 = 0;
        }
        if (TestSpecies(p + 0x200, id)) {
            *out1 = 1;
            *out2 = 0;
        }
        if (TestSpecies(p + 0x254, id)) {
            *out1 = 0;
            *out2 = 1;
        }
        if (TestSpecies(p + 0x2A8, id)) {
            *out1 = 1;
            *out2 = 1;
        }
    }
    h = func_0201ADE4(id, (u16)*outForm, a5);
    if (func_0201AE1C(h, 0x14) == 0xFF) {
        *out1 = 2;
    }
    func_0201AE14(h);
}


