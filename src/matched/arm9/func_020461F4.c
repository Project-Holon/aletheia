/*
 * function: func_020461F4
 * address:  0x020461F4
 * packet:   pkt_020461F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A58         0x02146A58  data
 *   g_020A08D0         0x020A08D0  data
 *   func_020461F4_File 0x020A7E98  data
 *   func_02030734      0x02030734  arm
 *   func_020463E0      0x020463E0  arm
 *   func_020788AC      0x020788AC  arm
 *   func_02078C18      0x02078C18  arm
 *   func_02078C28      0x02078C28  arm
 *   func_02078B70      0x02078B70  arm
 *   func_02078A80      0x02078A80  arm
 *   OS_Terminate       0x02088234  arm
 *
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

extern const char func_020461F4_File[];
extern const u8 g_020A08D0[];

extern struct Record020461F4 *g_02146A58;

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  func_020463E0(u32 a, u32 b);
extern void  func_020788AC(struct File020461F4 *f);
extern u32   func_02078C18(struct File020461F4 *f, u32 id);
extern u32   func_02078C28(struct File020461F4 *f);
typedef signed int     s32;
struct FSFile;
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);
extern void  func_02078A80(struct File020461F4 *f);
extern void  OS_Terminate(void);

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
            size = func_02078C28(&file);
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
