/*
 * file:     systemfont.c
 * unit:     yes
 * function: func_020461F4, func_02046300, func_0204638C, func_020463C0, func_020463D8, func_020463E0
 * address:  0x020461F4
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
 *   g_02146A58         0x02146A58  data
 *   g_020A08D0         0x020A08D0  data
 *   func_020461F4_File 0x020A7E98  data
 *   func_02030734      0x02030734  arm
 *   func_020788AC      0x020788AC  arm
 *   func_02078C18      0x02078C18  arm
 *   func_02078C28      0x02078C28  arm
 *   func_02078B70      0x02078B70  arm
 *   func_02078A80      0x02078A80  arm
 *   OS_Terminate       0x02088234  arm
 */
struct FSFile;
typedef unsigned char u8;

typedef unsigned int  u32;

struct Record020461F4 {
    void *data;
    u32 unk04;
    u32 unk08;
    u32 builtin;
};

struct File020461F4 {
    u32 words[18];
};

typedef unsigned short u16;

typedef signed int     s32;

struct Rec02046300 {
    void *data;
    u32 unk04;
    u32 unk08;
    u32 builtin;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  func_020788AC(struct File020461F4 *f);
extern u32   func_02078C18(struct File020461F4 *f, u32 id);
extern u32 func_02078C28(struct FSFile *a0);
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);
extern void  func_02078A80(struct File020461F4 *f);
extern void  OS_Terminate(void);
void func_020461F4(u32 id);
void func_02046300(int idx, u8 *out);
u32 func_0204638C(u32 bits);
int func_020463C0(void);
int func_020463D8(void);
void func_020463E0(u32 x, u32 y);
extern const char func_020461F4_File[];
extern const u8 g_020A08D0[];
extern struct Record020461F4 *g_02146A58;



/*
 * One-time load of the module's 16-byte record.  Returns at once if the
 * record already exists; otherwise allocates it from heap 0 and either
 * points it at the built-in table at 0x020A08D0 (argument 0) or reads the
 * named archive member into a second allocation sized from the file.
 *
 * The 0x48-byte stack local is the file handle the 0x0207xxxx archive
 * calls take: init, open, length, read, close.  A failed open terminates.
 *
 * The +0xC flag records which of the two sources was used: 1 for the
 * built-in table, 0 for the file.
 *
 * Two shapes the bytes pinned down: the file arm is the `if` and the
 * built-in arm the `else` (writing the `id == 0` test first makes the
 * built-in arm fall through and moves 140 bytes), and the flag store that
 * ends the file arm is inside it, not after the whole `if`.
 *
 * PARKED AT MATCH.  Every concrete byte is right; the one wildcard is the
 * ABS32 at +0x108, the pool word holding 0x020A08D0.
 *
 * That address has no witness of any class.  It is data, not code, so
 * `label` and `veneer` are out; the bytes there are binary (a 0x10-word
 * header followed by packed values), not a NUL-terminated run, so `string`
 * is out; and the pool word at 0x020462FC is the only occurrence of the
 * word 0x020A08D0 anywhere in the image, so `literal` discards its only
 * witness for being inside the compared range.  The function is atomic, so
 * --suggest-split has nothing to cut, and `matched` cannot apply to a data
 * address with no code defining it.  Spelling the pool word as a cast
 * constant would make the file EXACT by reading the answer out of the
 * bytes under test, which is exactly what the honesty rule forbids.
 *
 * Consequence for the chain: src/pending/func_0204E130.c (fan-in 121) was
 * blocked only on 0x020461F4, and the `matched` class needs an EXACT entry
 * here, so it stays at MATCH too.  Both unstick together if a second
 * reference to 0x020A08D0 turns up, most likely in an overlay's pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020461F4.c \
 *       --func func_020461F4 --addr 0x020461F4 --cc 1.1p1 --arm
 */
void func_020461F4(u32 id)
{
    struct File020461F4 file;
    u32 size;

    if (g_02146A58 != 0) {
        return;
    }

    g_02146A58 = func_02030734(0, 0x10, 0, func_020461F4_File, 68);

    if (id != 0) {
        func_020788AC(&file);
        if (func_02078C18(&file, id) == 1) {
            size = func_02078C28((struct FSFile *)(&file));
            g_02146A58->data = func_02030734(0, size, 0, func_020461F4_File,
                                             77);
            func_02078B70((struct FSFile *)(&file), g_02146A58->data, size);
            func_02078A80(&file);
        } else {
            OS_Terminate();
        }

        g_02146A58->builtin = 0;
    } else {
        g_02146A58->data = (void *)g_020A08D0;
        g_02146A58->builtin = 1;
        func_020463E0(1, 15);
    }
}



/*
 * Expand one 8-byte record of the loaded module table into eight words and
 * store the record's flag byte next to them.
 *
 * g_02146A58 is the module record src/pending/func_020461F4.c allocates:
 * its `data` field points at a header whose first two words are byte
 * offsets, the first to the record array, the second to the flag bytes.
 * `idx` selects one 8-byte record of that array; its eight bytes are each
 * run through func_0204638C and the results are merged with the two masks
 * at +04/+08 of the record before being written out as eight words.
 *
 * Shape notes (each cost real bytes):
 *  - The head offsets are spelled `idx * 32 / 4`.  That literal
 *    multiply-then-divide is what makes mwcc emit the four-instruction
 *    `lsl #5 / asr #1 / add lsr #30 / add asr #2` signed-scale sequence
 *    the original shows; the algebraically identical `idx * 8` compiles to
 *    a single `lsl #3` and reallocates the whole function.
 *  - `~v` has to be spelled `v ^ 0xFFFFFFFF`: with the `~` operator the
 *    compiler rematerialises `mvn r1, r0` inside the loop, but the mask
 *    form is strength-reduced to one `mvn r4, #0` hoisted above it plus an
 *    `eor`, which is what the original does.
 *  - The flag store groups its sum as `t = hdr + hdr[1]; t[idx]`.  Writing
 *    the same sum as one subscript expression associates the other way and
 *    emits `add r0, r0, sl` / `ldrb r0, [r1, r0]` instead of
 *    `add r0, r1, r0` / `ldrb r0, [sl, r0]` -- two bytes of diff, but no
 *    other spacing reproduces the register pair.
 *  - The record pointer is re-derived from the global at the tail (six
 *    instructions) rather than kept in a register: the loop calls out, so
 *    the cached `data` cannot legally survive, and binding it to a local
 *    loses the second pool load.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046300.c \
 *       --func func_02046300 --addr 0x02046300 --cc 1.1p1 --arm
 */
void func_02046300(int idx, u8 *out)
{
    u8 *p = (u8 *)g_02146A58->data + ((u32 *)g_02146A58->data)[0]
            + idx * 32 / 4;
    u32 m0 = g_02146A58->unk04;
    u32 m1 = g_02146A58->unk08;
    u32 *q = (u32 *)out;
    u8 *t;
    int i;

    for (i = 0; i < 8; i++) {
        u32 v = func_0204638C(*p++);
        u32 nv = v ^ 0xFFFFFFFF;
        *q++ = (m0 & v) | (m1 & nv);
    }

    t = (u8 *)g_02146A58->data + ((u32 *)g_02146A58->data)[1];
    out[0x20] = t[idx];
}



/*
 * Expand the low eight bits of the argument into a nibble mask: bit i set
 * turns nibble i into 0xf, so bit 0 gives 0x0000000f and bit 7 gives
 * 0xf0000000.  The 0xf0000000 sits in a register outside the loop and the
 * per-iteration shift is a register (i * 4) rather than a constant, which
 * is why the loop carries a second index register: the count itself would
 * not do, the shift needs it scaled.
 *
 * The loop is a plain `for` from zero to eight; the compiler folds the test
 * into `cmp #8` / `blt` with both the test and the or predicated on a `tst`,
 * and the accumulator lives in lr.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204638C.c  *       --func func_0204638C --addr 0x0204638C --cc 1.1p1 --arm
 */
u32 func_0204638C(u32 bits)
{
    int i;
    u32 out = 0;

    for (i = 0; i < 8; i++) {
        if (bits & (1 << i))
            out |= 0xF0000000 >> (i * 4);
    }
    return out;
}


int func_020463C0(void){ return ((u8 *)g_02146A58->data)[13]; }


int func_020463D8(void){ return 7; }



/*
 * Replicate a fill byte across a word, twice: both arguments are multiplied
 * by 0x11111111 and the two products go into the context's +4 and +8 words.
 * mwccarm expands the constant multiply into a chain of `orr`s with shifted
 * operands rather than spending a `mul`, and the left-associative nesting
 * puts the bare copy of the value in the last `orr` of each chain, so the
 * shift amounts run 24, 28, 20, 16, 12, 8, 4 and then a plain register.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020463E0.c \
 *       --func func_020463E0 --addr 0x020463E0 --cc 1.1p1 --arm
 */
void func_020463E0(u32 x, u32 y)
{
    g_02146A58->unk04 = (x << 28) | (x << 24) | (x << 20) | (x << 16) |
                         (x << 12) | (x << 8) | (x << 4) | x;
    g_02146A58->unk08 = (y << 28) | (y << 24) | (y << 20) | (y << 16) |
                         (y << 12) | (y << 8) | (y << 4) | y;
}
