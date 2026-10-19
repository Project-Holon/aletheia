/*
 * file:     msl_stdio.c
 * unit:     yes
 * function: __prep_buffer, __load_buffer, __flush_buffer, fread, __fread, fclose, MSL_C_LIB_FlushStream, MSL_C_LIB_StrNICmp, __ftell, ftell, __fseek, fseek, rewind, MSL_C_LIB_PopCount64, __signbitd, __fpclassifyd, MSL_C_LIB_MbrToWc, MSL_C_LIB_WcToMb, MSL_C_LIB_CallFormatHook, MSL_C_LIB_WideToNarrow
 * address:  0x0209159C
 * region:   arm9
 * compiler: dsi/1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from msl_c_lib.c by tools/splitfile.py.
 *
 * symbols:
 *   OS_LockMutex  0x02086028  arm
 *   OS_TryLockMutex  0x020860D0  arm
 *   OS_UnlockMutex  0x02086078  arm
 *   gMslRefToken  0x02150FEC  data
 *   gMslMutexTable  0x02153BD4  data
 *   gMslStream0  0x020A8730  data
 *   gMslRefGen  0x02153B8C  data
 *   gMslRefCount  0x02153BB0  data
 *   __tolower_map  0x020A60DC  data
 *   errno  0x02153FAC  data
 *   gMslStream1  0x020A877C  data
 *   gMslStream2  0x020A87C8  data
 *   gMslFormatHook  0x020A8878  data
 *   MSL_C_LIB_FlushAllGated 0x0209149C arm arm9
 *   MSL_C_LIB_FlushAll 0x02091524 arm arm9
 *   MSL_C_LIB_NopBufferHookA 0x02091594 arm arm9
 *   MSL_C_LIB_NopBufferHookB 0x02091598 arm arm9
 *   memcpy 0x02092344 arm arm9
 *   strncpy 0x02094860 arm arm9
 *   fwide 0x02096508 arm arm9
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "msl_crt_shared_types.h"
#include "msl_stdio_shared_types.h"

struct FILE;

typedef struct {
    u32 open_mode        : 2;
    u32 io_mode          : 3;
    u32 buffer_mode      : 2;
    u32 file_kind        : 3;
    u32 file_orientation : 2;
    u32 binary_io        : 1;
} file_modes;

typedef struct {
    u32 io_state    : 3;
    u32 free_buffer : 1;
} file_state;

typedef struct FILE {
    u32        handle;              /* 0x00 */
    file_modes mode;                /* 0x04 */
    file_state state;               /* 0x08 */
    u8         eof;                 /* 0x0c */
    u8         error;               /* 0x0d */
    u8         char_buffer;         /* 0x0e */
    u8         char_buffer_overflow;/* 0x0f */
    u8         pad10[2];            /* 0x10 */
    u8         ungetc_buffer[2];    /* 0x12 */
    wchar_t    ungetwc_buffer[2];   /* 0x14 */
    u32        position;            /* 0x18 */
    u8        *buffer;              /* 0x1c */
    u32        buffer_size;         /* 0x20 */
    u8        *buffer_ptr;          /* 0x24 */
    u32        buffer_len;          /* 0x28 */
    u32        buffer_alignment;    /* 0x2c */
    u32        saved_buffer_len;    /* 0x30 */
} FILE;

struct MslFileIoBits {
    u32 pad     : 2;
    u32 io_mode : 3;
    u32 rest    : 27;
};

struct MslFileModeBits {
    u32 pad         : 2;
    u32 io_mode     : 3;
    u32 buffer_mode : 2;
    u32 kind        : 3;
    u32 rest        : 22;
};

typedef u32 (*MslReadFn)(u32, u32, u32 *, u32);

typedef u32 (*MslWriteFn)(u32, u32, u32 *, u32);

typedef struct {
    unsigned char pad[4];
    u32 (*proc)(u32 *dst, u32 c);
} MslFormatHook;

typedef struct {
    unsigned char pad[8];
    MslFormatHook *hook;
} MslFormatHookHolder;
#include "../sdk_os.h"

extern void OS_LockMutex(struct OSMutex *mutex);

extern int OS_TryLockMutex(struct OSMutex *mutex);

extern void OS_UnlockMutex(struct OSMutex *mutex);


int MSL_C_LIB_FlushAllGated(void);

int MSL_C_LIB_FlushAll(void);

void MSL_C_LIB_NopBufferHookA(int a, void *b);

void MSL_C_LIB_NopBufferHookB(int a, void *b);

void __prep_buffer(struct MslStream *stream);

int __load_buffer(struct MslStream *stream, u32 *bytes_loaded, int mode);

int __flush_buffer(struct MslStream *stream, u32 *bytes_flushed);

int fread(void *ptr, u32 memb_size, u32 num_memb, u32 stream);

size_t __fread(void *ptr, size_t memb_size, size_t num_memb, FILE *file);

int fclose(u8 *stream);

int MSL_C_LIB_FlushStream(struct MslStream *stream);

int MSL_C_LIB_StrNICmp(const u8 *s1, const u8 *s2, int n);

int __ftell(struct MslStream *stream);

int ftell(u32 stream);

int __fseek(MslStream *stream, u32 pos, u32 whence);

int fseek(u32 stream, u32 pos, u32 whence);

int rewind(void *stream);

u32 MSL_C_LIB_PopCount64(u64 x);

int __signbitd(double x);

int __fpclassifyd(double x);

int MSL_C_LIB_MbrToWc(unsigned short *pwc, const unsigned char *s, unsigned int n);

int MSL_C_LIB_WcToMb(char *s, unsigned short wc);

u32 MSL_C_LIB_CallFormatHook(u32 *dst, u32 c);

u32 MSL_C_LIB_WideToNarrow(u8 *dst, const u16 *src, u32 max);

void *memcpy(void *dest, const void *src, size_t n);

u8 *strncpy(u8 *dest, const u8 *src, u32 n);

int fwide(u8 *stream, int orientation);

extern struct MslRefBlock gMslRefToken;

extern u8 gMslMutexTable[];

extern u8 gMslStream0[];

extern u32 gMslRefGen[];

extern u32 gMslRefCount[];

extern const u8 __tolower_map[];

extern u8  gMslStream1[];

extern u8  gMslStream2[];

extern unsigned char gMslFormatHook[];

extern int errno;

/*
 * Three field moves on the object, in source order and nothing else:
 * `p->buffer_ptr = p->buffer; p->buffer_len = p->buffer_size - (p->position & p->buffer_alignment); p->saved_buffer_len = p->position;`.
 *
 * The load order (0x18, 0x2c, 0x1c, 0x20) is the scheduler hoisting the
 * second statement's two loads above the first statement's store, and the
 * register numbering ([r2, r1, ip, r3] for the four loads) follows from the
 * object being a struct: reading the fields through a `struct FILE *` keeps the
 * word loads independent, and the whole function is then a straight line with
 * no prologue at all.  No relocation sites, so the 40 bytes are compared
 * byte for byte with nothing wildcarded.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/__prep_buffer.c \
 *       --func __prep_buffer --addr 0x0209159C --cc 1.1p1 --arm
 *   EXACT, 40 bytes, no relocation sites.
 */
void __prep_buffer(struct MslStream *stream)
{
    stream->buffer_ptr = stream->buffer;
    stream->buffer_len = stream->buffer_size - (stream->position & stream->buffer_alignment);
    stream->saved_buffer_len = stream->position;
}

/*
 * One deferred transaction against the object: re-derive the working fields
 * (__prep_buffer), optionally preload the amount from the object's f20 when
 * the mode argument is 1, run the object's own f3c handler with four
 * arguments (f00, f1c, &f28 and f48 - the fourth is only visible as the dead
 * `ldr r3, [r4, #0x48]` the call does not otherwise need), publish f28 to the
 * caller's out parameter, and on success fold f28 into the running f18.
 *
 * The handler is called through a plain cast of the field
 * (`((Fn)p->read_proc)(...)`, i.e. the field itself declared as a function
 * pointer).  Spelling it as a guarded indirect call (`p->read_proc ? ... : 0`)
 * compiles to a branchy 102-byte-different body: the original is a bare
 * `blx ip`.
 *
 * The flag test is `((p->mode << 19) >> 31) == 0`, one bit selected out of the
 * word at +4; the unequal shift pair keeps both shifts (a mask would fold to
 * `tst #0x1000`).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/__load_buffer.c \
 *       --func __load_buffer --addr 0x020915C4 --cc 1.1p1 --arm
 *   EXACT, 140 bytes, 2 relocation sites, both resolved.
 */
int __load_buffer(struct MslStream *stream, u32 *bytes_loaded, int mode)
{
    u32 r;

    __prep_buffer((struct MslStream *)stream);
    if (mode == 1)
        stream->buffer_len = stream->buffer_size;
    r = ((MslReadFn)stream->read_proc)(stream->handle, stream->buffer, &stream->buffer_len, stream->ref_con);
    if (r == 2)
        stream->buffer_len = 0;
    if (bytes_loaded != 0)
        *bytes_loaded = stream->buffer_len;
    if (r != 0)
        return r;
    stream->position += stream->buffer_len;
    if (((stream->mode << 19) >> 31) == 0)
        MSL_C_LIB_NopBufferHookB(stream->buffer, &stream->buffer_len);
    return 0;
}

/*
 * The commit half of the pair whose prepare half is __load_buffer: work out
 * the amount still to apply (f24 - f1c), and if there is one, publish it to
 * f28, pre-process it through MSL_C_LIB_NopBufferHookA, run the object's f40 handler with
 * the same four arguments __load_buffer uses, hand f28 back through the out
 * parameter, and fold the applied amount into f18 on success.  The trailing
 * __prep_buffer and `return 0` are shared by both paths, which is why the
 * body's early exit is the loop-free `if (d != 0) { ... }` shape rather than a
 * `goto`.
 *
 * The handler is again a bare `blx ip` off a cast field; the f04 flag bit is
 * the same unequal-shift-pair test as in __load_buffer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/__flush_buffer.c \
 *       --func __flush_buffer --addr 0x02091650 --cc 1.1p1 --arm
 *   EXACT, 132 bytes, 2 relocation sites, both resolved.
 */
int __flush_buffer(struct MslStream *stream, u32 *bytes_flushed)
{
    u32 d;
    u32 r;

    d = stream->buffer_ptr - stream->buffer;
    if (d != 0) {
        stream->buffer_len = d;
        if (((stream->mode << 19) >> 31) == 0)
            MSL_C_LIB_NopBufferHookA(stream->buffer, &stream->buffer_len);
        r = ((MslWriteFn)stream->write_proc)(stream->handle, stream->buffer, &stream->buffer_len, stream->ref_con);
        if (bytes_flushed != 0)
            *bytes_flushed = stream->buffer_len;
        if (r != 0)
            return r;
        stream->position += stream->buffer_len;
    }
    __prep_buffer((struct MslStream *)stream);
    return 0;
}

/*
 * A refcounted-resource wrapper: the 4-argument twin of
 * src/matched/fseek.c (which is the 3-argument one with a three-way
 * id dispatch).  The id here is the FOURTH argument and the dispatch is
 * two-way, `a3 == gMslStream0 ? 2 : 5`, which is what the image's
 * `mov r6,#2 / cmp r7,r4 / movne r6,#5` is.
 *
 * docs/notes/pkt_020916D4.c.txt records an earlier pass that got to 248
 * bytes against 256 and diagnosed the residue as a register tie on the
 * `mul` destination plus an unreachable CSE of the 0x02153B8C base.  Both
 * readings were wrong: the shortfall was an arm structure difference, not
 * an allocator tie.  The sibling's exact shape -- the `cur`/`ref` pair named
 * as two locals in the else arm, the two table stores written out in full in
 * BOTH the then arm and the inner else arm rather than factored, and
 * `gMslRefToken.refs[0x1b]` re-read at each of its three use sites -- closes
 * it with no permuter run at all.  The `str r3,[r2,r6,lsl #2]` addressing-
 * mode store and the per-site pool reloads the note despaired of follow from
 * writing the arms out rather than from any register hint.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/fread.c \
 *       --func fread --addr 0x020916D4 --arm --cc 1.1p1
 */
int fread(void *ptr, u32 memb_size, u32 num_memb, u32 stream)
{
    u32 idx = (stream == (u32)gMslStream0) ? 2 : 5;
    u8 *blk = gMslMutexTable + idx * 0x18;
    int r;

    if (OS_TryLockMutex((struct OSMutex *)blk) == 0) {
        gMslRefGen[idx] = gMslRefToken.refs[0x1b];
        gMslRefCount[idx] = 1;
    } else {
        u32 cur = gMslRefGen[idx];
        u32 ref = gMslRefToken.refs[0x1b];

        if (cur == ref) {
            gMslRefCount[idx]++;
        } else {
            OS_LockMutex((struct OSMutex *)blk);
            gMslRefGen[idx] = gMslRefToken.refs[0x1b];
            gMslRefCount[idx] = 1;
        }
    }
    r = __fread((void *)ptr, memb_size, num_memb, (struct FILE *)stream);
    gMslRefCount[idx]--;
    if (gMslRefCount[idx] == 0) OS_UnlockMutex((struct OSMutex *)blk);
    return r;
}

enum { __neutral, __writing, __reading, __rereading };

enum { __no_io_error, __io_error, __io_EOF };

/*
 * MSL C `__fread` (buffered stdio read), transcribed from the Metrowerks MSL
 * shape: fwide orientation probe, pushback drain through ungetc_buffer /
 * ungetwc_buffer, buffered copy loop through __load_buffer (__load_buffer)
 * and memcpy (memcpy), then the unbuffered direct read that borrows
 * buffer/buffer_size.  Returns bytes_read / memb_size.
 * The two levers over the earlier 788/456 note body were (1) writing it as
 * MSL writes it (always_buffer = !binary_io || buffer_mode == _IOFBF, the
 * set_error / set_eof bodies spelled out in each arm) and (2) the FILE
 * layout: eof/error are plain u8 members at +0x0c/+0x0d, NOT inside an
 * 8-byte state struct, which puts ungetc_buffer at +0x12 and ungetwc_buffer
 * at +0x14.  Project default compiler; EXACT on the first full transcription.
 */
size_t __fread(void *ptr, size_t memb_size, size_t num_memb, FILE *file)
{
    u8 *read_ptr;
    size_t num_bytes, bytes_requested, bytes_read;
    int ioresult, always_buffer;

    if (fwide((u8 *)file, 0) == 0)
        fwide((u8 *)file, -1);

    bytes_requested = memb_size * num_memb;

    if (!bytes_requested || file->error || file->mode.file_kind == 0)
        return 0;

    always_buffer = !file->mode.binary_io || file->mode.buffer_mode == 2;

    if (file->state.io_state == __neutral) {
        if (file->mode.io_mode & 1) {
            file->state.io_state = __reading;
            file->buffer_len = 0;
        }
    }

    if (file->state.io_state < __reading) {
        file->error = 1;
        file->buffer_len = 0;
        return 0;
    }

    if (file->mode.buffer_mode & 1) {
        if (MSL_C_LIB_FlushAllGated()) {
            file->error = 1;
            file->buffer_len = 0;
            return 0;
        }
    }

    read_ptr = (u8 *)ptr;
    bytes_read = 0;

    if (bytes_requested && file->state.io_state >= __rereading) {
        do {
            if (fwide((u8 *)file, 0) == 1) {
                *(u16 *)read_ptr = file->ungetwc_buffer[file->state.io_state - __rereading];
                read_ptr += sizeof(wchar_t);
                bytes_read += sizeof(wchar_t);
                bytes_requested -= sizeof(wchar_t);
            } else {
                *read_ptr++ = file->ungetc_buffer[file->state.io_state - __rereading];
                bytes_read++;
                bytes_requested--;
            }
            file->state.io_state--;
        } while (bytes_requested && file->state.io_state >= __rereading);

        if (file->state.io_state == __reading)
            file->buffer_len = file->saved_buffer_len;
    }

    if (bytes_requested && (file->buffer_len || always_buffer)) {
        do {
            if (!file->buffer_len) {
                ioresult = __load_buffer((struct MslStream *)file, 0, 0);
                if (ioresult) {
                    if (ioresult == __io_error) {
                        file->error = 1;
                        file->buffer_len = 0;
                    } else {
                        file->state.io_state = __neutral;
                        file->eof = 1;
                        file->buffer_len = 0;
                    }
                    bytes_requested = 0;
                    break;
                }
            }

            num_bytes = file->buffer_len;
            if (num_bytes > bytes_requested)
                num_bytes = bytes_requested;

            memcpy(read_ptr, file->buffer_ptr, num_bytes);

            read_ptr += num_bytes;
            bytes_read += num_bytes;
            bytes_requested -= num_bytes;

            file->buffer_ptr += num_bytes;
            file->buffer_len -= num_bytes;
        } while (bytes_requested && always_buffer);
    }

    if (bytes_requested && !always_buffer) {
        u8 *save_buffer = file->buffer;
        size_t save_size = file->buffer_size;

        file->buffer = read_ptr;
        file->buffer_size = bytes_requested;

        ioresult = __load_buffer((struct MslStream *)file, &num_bytes, 1);
        if (ioresult) {
            if (ioresult == __io_error) {
                file->error = 1;
                file->buffer_len = 0;
            } else {
                file->state.io_state = __neutral;
                file->eof = 1;
                file->buffer_len = 0;
            }
        }

        bytes_read += num_bytes;

        file->buffer = save_buffer;
        file->buffer_size = save_size;

        __prep_buffer((struct MslStream *)file);

        file->buffer_len = 0;
    }

    return bytes_read / memb_size;
}

int fclose(u8 *stream)
{
    u32 mode;
    int r;
    int x;

    if (stream == 0)
        return -1;
    mode = (((struct MslStream *)stream)->mode << 22) >> 29;
    if (mode == 0)
        return 0;
    r = (int)MSL_C_LIB_FlushStream((struct MslStream *)stream);
    x = ((int (*)(u32))*(u32 *)(stream + 0x44))(((struct MslStream *)stream)->handle);
    ((struct MslStream *)stream)->mode &= ~0x380u;
    ((struct MslStream *)stream)->handle = 0;
    if ((((struct MslStream *)stream)->state << 28) >> 31)
        return -1;
    return (r != 0 || x != 0) ? -1 : 0;
}

/*
 * The state machine the gMslStream0 sweep calls per record (and the entry the
 * null argument routes to MSL_C_LIB_FlushAll).  A record is rejected when its +0xd
 * byte is set or when its +4 field at bits 7..9 is zero, is a no-op when the
 * +4 field at bits 2..4 is 1, otherwise its +8 three-bit mode is forced to 2
 * when it is 3 or more (clearing the low three bits first), the record is
 * cleared when that mode is 2, and anything but mode 1 clears the mode and
 * returns.  Mode 1 runs the transaction __flush_buffer, and either sets the
 * +0xd byte and returns -1 or clears mode, +0x18 and +0x28 and returns 0.
 *
 * Every one of the five field accesses is a bitfield read/write against a
 * view struct cast onto the word, and that is load-bearing: written as
 * `(p->state << 29) >> 29` the three-mode tests are re-derived as `and #7` and
 * the whole tail renumbers, while a bitfield extraction is emitted as the
 * shift pair directly and is never folded (this is the same finding as
 * src/matched/MSL_C_LIB_FlushAllGated.c and MSL_C_LIB_FlushAll.c's neighbour).  The mode
 * writes come out as exactly `bic`/`orr` on the low three bits, which is what
 * a bitfield assignment emits, and the constant -1 the failure path returns is
 * derived by the compiler from the 1 it has just stored (`subne r0, r0, #2`).
 *
 * The `||` over the two rejection tests is what shares the `mvn r0, #0`
 * epilogue; two separate `if`s cost 20 bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSL_C_LIB_FlushStream.c \
 *       --func MSL_C_LIB_FlushStream --addr 0x02091B5C --cc 1.1p1 --arm
 *   EXACT, 228 bytes, 2 relocation sites, both resolved.
 */
int MSL_C_LIB_FlushStream(struct MslStream *stream)
{
    int r;

    if (stream == 0)
        return MSL_C_LIB_FlushAll();
    if (stream->error != 0 || ((struct MslFileKind *)&stream->mode)->kind == 0)
        return -1;
    if (((struct MslFileIoBits *)&stream->mode)->io_mode == 1)
        return 0;
    if (((struct MslStateBits *)&stream->state)->mode >= 3)
        ((struct MslStateBits *)&stream->state)->mode = 2;
    if (((struct MslStateBits *)&stream->state)->mode == 2)
        stream->buffer_len = 0;
    if (((struct MslStateBits *)&stream->state)->mode != 1) {
        ((struct MslStateBits *)&stream->state)->mode = 0;
        return 0;
    }
    r = __flush_buffer((struct MslStream *)stream, 0);
    if (r != 0) {
        stream->error = 1;
        stream->buffer_len = 0;
        return -1;
    }
    ((struct MslStateBits *)&stream->state)->mode = 0;
    stream->position = 0;
    stream->buffer_len = 0;
    return 0;
}

/*
 * Bounded case-insensitive string compare (the `strncmp` twin of
 * src/matched/stricmp.c, which is the unbounded `strcmp`): each byte is
 * mapped through the 256-byte table at 0x020A60DC when it is below 0x80, then
 * compared as unsigned, for at most n bytes.
 *
 * Three spellings are load-bearing, and docs/notes/pkt_02091C40.c.txt records
 * a whole earlier pass that got the first two but not the third:
 *
 *  - the guard is `if (n > 0) { <loop> } return 0;`, not `if (n <= 0)
 *    return 0;`.  The early-return spelling predicates the guard
 *    (`movle r0,#0` / `pople`) and is 128 bytes; the block spelling branches
 *    to the single shared epilogue the image has at 0x02091CB0.
 *  - the two byte temps are the interleaved `int c1; u8 m1; int c2; u8 m2;`
 *    of the sibling, which is what colours the masked c1 into r4 and the raw
 *    c2 into r5.  Declaring the two masks together swaps those registers.
 *    Writing the masks as `c1 &= 0xff` on the `int`s instead (the earlier
 *    pass's spelling) leaves the same 26-byte register swap that note
 *    describes: lr/ip carry the loop counter and the table there, r4/ip here.
 *  - THE TABLE BASE IS ASSIGNED INSIDE THE GUARD.  `const u8 *tab =
 *    __tolower_map;` at the top of the function hoists its pool load above the
 *    `ble`, which is the last 12-byte residue: the image emits
 *    `mov lr,#0 / ble / ldr ip,[pc,#0x60]`, i.e. the table is not loaded at
 *    all on the n <= 0 path.  Declaring it at the top and assigning it in
 *    the block reproduces that order exactly.
 *
 * Also measured by the earlier pass, and still true: mwccarm 1.1p1 in
 * `-lang c99` mode REJECTS a C99 for-statement declaration
 * (`for (int i = 0; ...)` -> "expression syntax error"), so the counter is
 * declared at block scope.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/MSL_C_LIB_StrNICmp.c \
 *       --func MSL_C_LIB_StrNICmp --addr 0x02091C40 --arm --cc 1.1p1
 */
int MSL_C_LIB_StrNICmp(const u8 *s1, const u8 *s2, int n)
{
    const u8 *tab;
    int i = 0;
    int c1;
    u8 m1;
    int c2;
    u8 m2;

    if (n > 0)
    {
        tab = __tolower_map;
        do
        {
            c1 = *s1++;
            if (c1 >= 0 && c1 < 0x80)
                c1 = tab[c1];
            m1 = (u8)c1;

            c2 = *s2++;
            if (c2 >= 0 && c2 < 0x80)
                c2 = tab[c2];
            m2 = (u8)c2;

            if (m1 < m2)
                return -1;
            if (m1 > m2)
                return 1;
            if (m1 == 0)
                return 0;
            i++;
        } while (i < n);
    }
    return 0;
}

/*
 * Reads back the amount a record still owes: reject the record when its +4
 * bits 7..9 mode is neither 0 nor 1 or when its +0xd byte is set (leaving
 * 0x28 in the reserved word and returning -1), return the running f18 when
 * the +8 three-bit mode is 0, otherwise f34 + (f24 - f1c), reduced by
 * (mode - 2) for modes of 3 or more.
 *
 * Two spellings are pinned here and neither is the obvious one:
 *
 *  - `u8 sel = mode + 0xff;` is the decrement.  `mode - 1` compiles to
 *    `sub r1, r1, #1`; the original has `and #0xff; add r1, r1, #0xff;
 *    and #0xff`, i.e. the wrap-around add the source wrote, narrow once on
 *    being stored into the `u8 mode` and once on the sum
 *    (docs/idioms/a-u8-decrement-is-spelled-as-the-wraparound-add.md).
 *  - the +8 mode is read through a bitfield view struct.  A shift-pair
 *    spelling that feeds a `== 0` test is folded to `ands`, which loses both
 *    the second `lsr` and the register the original keeps.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/__ftell.c \
 *       --func __ftell --addr 0x02091CBC --cc 1.1p1 --arm
 *   EXACT, 124 bytes, 1 relocation site, resolved.
 */
int __ftell(struct MslStream *stream)
{
    struct MslStateBits *m08 = (struct MslStateBits *)&stream->state;
    u8 mode;
    u8 sel;
    u32 m;
    u32 v;

    mode = ((struct MslFileKind *)&stream->mode)->kind;
    sel = mode + 0xff;
    if (sel > 1 || stream->error != 0) {
        errno = 0x28;
        return -1;
    }
    m = m08->mode;
    if (m == 0)
        return stream->position;
    v = stream->saved_buffer_len + (stream->buffer_ptr - stream->buffer);
    if (m >= 3)
        v -= m - 2;
    return v;
}

/*
 * The one-argument member of the refcounted-resource wrapper family
 * (src/matched/fseek.c is the three-argument one, and
 * src/matched/fread.c the four-argument one with a two-way dispatch).
 * Three-way id dispatch on a0, block base 0x02153BD4 with a 0x18 stride, the
 * two parallel arrays gMslRefGen / gMslRefCount, and the reference token
 * gMslRefToken.refs[0x1b].
 *
 * docs/notes/pkt_02091D38.c.txt left this at 265 of 268 bytes with a
 * three-instruction residue on the equality compare, and named the fix it had
 * not tried: bind BOTH sides to named locals in a nested if/else inside the
 * outer else, ARRAY ELEMENT FIRST --
 *
 *     u32 cur = gMslRefGen[idx];
 *     u32 ref = gMslRefToken.refs[0x1b];
 *     if (cur == ref) ... else ...
 *
 * not an `else if` on the bare expression.  Two live named temporaries on the
 * compare is what lands arr in r1 and the field in r0; the `else if` spelling
 * canonicalises either operand order to the swapped pair.  That spelling
 * closes it, exactly as the note predicted from 0x02092004.
 *
 * gMslRefToken is a two-word object whose SECOND word is the pointer: the pool
 * word is 0x02150FEC itself, so the field must be reached through
 * `gMslRefToken.refs`, never through a symbol named for 0x02150FF0.  The three
 * id constants are ADDRESSES compared against a0, so they are declared as
 * objects and their address taken; declaring them `u32` makes the compiler
 * dereference them.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/ftell.c \
 *       --func ftell --addr 0x02091D38 --arm --cc 1.1p1
 */
int ftell(u32 stream)
{
    u32 idx = (stream == (u32)gMslStream0) ? 2 : (stream == (u32)gMslStream1) ? 3
            : (stream == (u32)gMslStream2) ? 4 : 5;
    u8 *blk = gMslMutexTable + idx * 0x18;
    int r;

    if (OS_TryLockMutex((struct OSMutex *)blk) == 0) {
        gMslRefGen[idx] = gMslRefToken.refs[0x1b];
        gMslRefCount[idx] = 1;
    } else {
        u32 cur = gMslRefGen[idx];
        u32 ref = gMslRefToken.refs[0x1b];

        if (cur == ref) {
            gMslRefCount[idx]++;
        } else {
            OS_LockMutex((struct OSMutex *)blk);
            gMslRefGen[idx] = gMslRefToken.refs[0x1b];
            gMslRefCount[idx] = 1;
        }
    }
    r = __ftell((struct MslStream *)stream);
    gMslRefCount[idx]--;
    if (gMslRefCount[idx] == 0) OS_UnlockMutex((struct OSMutex *)blk);
    return r;
}

/*
 * The seek (fseek shape) of the buffered-stdio object documented in
 * docs/families/cluster_02091588.h and cluster_02091AE8.h.  The real entry is
 * the push {r0-r3} home area at 0x02091E44 (the +0x38 handler takes &pos); the
 * listing's label at 0x02091E48 is the body, hence EXACT* against a 4-byte
 * listing extent until the seed at 0x02091E44 replaces it.
 *
 * Closed wave 12 after four lanes stalled at 448/28.  The two coupled residues
 * were both in the declarations, not the allocator:
 *   - the f08 state is a BITFIELD MEMBER OF THE STRUCT and is ASSIGNED as one
 *     (`((struct MslStateBits *)&p->state)->mode = 2;` / `= 0;`).  That is the `bic ip, #7 / orr #2` read-
 *     modify-write off the word the mode test already loaded, and the plain
 *     re-read after the store; no volatile view is involved.
 *   - the in-window test is `if (pos >= f18 || pos < f34) mode = 0; else
 *     {...}`: the disjunction's THEN arm is the `b` the image keeps between
 *     the two compares.  The positive `&&` form cross-jumps it away.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/__fseek.c \
 *       --func __fseek --addr 0x02091E44 --arm --cc 1.1p1
 *   EXACT*, 448 bytes, 3 of 3 relocation sites resolved.
 *   ../2.0/sp2 and ../2.0/sp2p2: 488 bytes, DIFF.
 */
int __fseek(MslStream *stream, u32 pos, u32 whence)
{
    u8 mode;

    mode = ((struct MslFileModeBits *)&stream->mode)->kind;
    if (mode != 1 || stream->error != 0) {
        errno = 0x28;
        return -1;
    }
    if (((struct MslStateBits *)&stream->state)->mode == 1 && __flush_buffer((struct MslStream *)stream, 0) != 0) {
        stream->error = 1;
        stream->buffer_len = 0;
        errno = 0x28;
        return -1;
    }
    if (whence == 1) {
        whence = 0;
        pos += __ftell((struct MslStream *)stream);
    }
    if (whence != 2 && ((struct MslFileModeBits *)&stream->mode)->io_mode != 3 && ((struct MslStateBits *)&stream->state)->mode - 2 <= 1) {
        if (pos >= stream->position || pos < stream->saved_buffer_len) {
            ((struct MslStateBits *)&stream->state)->mode = 0;
        } else {
            stream->buffer_ptr = stream->buffer + (pos - stream->saved_buffer_len);
            stream->buffer_len = stream->position - pos;
            ((struct MslStateBits *)&stream->state)->mode = 2;
        }
    } else {
        ((struct MslStateBits *)&stream->state)->mode = 0;
    }
    if (((struct MslStateBits *)&stream->state)->mode == 0) {
        if (stream->seek_proc != 0 && stream->seek_proc(stream->handle, &pos, whence, stream->ref_con) != 0) {
            stream->error = 1;
            stream->buffer_len = 0;
            errno = 0x28;
            return -1;
        }
        stream->eof = 0;
        stream->position = pos;
        stream->buffer_len = 0;
    }
    return 0;
}

/*
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * blocking: label, no outside witness -- the one wildcard site is +0x00D4
 *           PC24 __fseek, whose only branch in the image is this call
 *           (match.py: "has no witness outside 02092004..02092120").  Cut
 *           does not help: the site is inside the single function, so
 *           --suggest-split has nothing to offer.  Byte-correct as it
 *           stands: converts with no edit the moment 0x02091E44 has a
 *           manifest entry of its own.
 */
int fseek(u32 stream, u32 pos, u32 whence)
{
    u32 idx = (stream == (u32)gMslStream0) ? 2 : (stream == (u32)gMslStream1) ? 3
            : (stream == (u32)gMslStream2) ? 4 : 5;
    u8 *blk = gMslMutexTable + idx * 0x18;
    int r;

    if (OS_TryLockMutex((struct OSMutex *)blk) == 0) {
        gMslRefGen[idx] = gMslRefToken.refs[0x1b];
        gMslRefCount[idx] = 1;
    } else {
        u32 cur = gMslRefGen[idx];
        u32 ref = gMslRefToken.refs[0x1b];

        if (cur == ref) {
            gMslRefCount[idx]++;
        } else {
            OS_LockMutex((struct OSMutex *)blk);
            gMslRefGen[idx] = gMslRefToken.refs[0x1b];
            gMslRefCount[idx] = 1;
        }
    }
    r = __fseek((MslStream *)stream, pos, whence);
    gMslRefCount[idx]--;
    if (gMslRefCount[idx] == 0) OS_UnlockMutex((struct OSMutex *)blk);
    return r;
}

int rewind(void *stream){ int result; ((struct MslStream *)((char *)(stream)))->error = (unsigned char)0; result = fseek((int)stream, (int)0, (int)0); ((struct MslStream *)((char *)(stream)))->error = (unsigned char)0; return result; }

/*
 * 64-bit population count: the four SWAR stages of the standard bit-count
 * idiom over an unsigned long long, then the horizontal fold.  The last three
 * folds are unmasked (`x += x >> 8`, `>> 16`, `>> 32`) because the count of
 * 64 bits can never carry out of a byte, so no 0x00FF00FF mask is needed.
 *
 * The 32-bit halves of the 64-bit shifts are what pin the type: `orr r3, r3,
 * r1, lsl #31` after `lsr r3, r0, #1` is a 64-bit `>> 1`, and `and r2, r2,
 * r1, lsr #1` masks the high word separately.  The three masks are 64-bit
 * constants whose two halves happen to be equal, which is why one pool word
 * each (0x55555555, 0x33333333, 0x0F0F0F0F) serves both words.
 *
 * `x + (x >> 32)` is not emitted as a shift at all: at that point the value
 * is under 0x100, so only the low half matters and mwcc folds the 64-bit add
 * to `adds r0, r1, r0` (low word plus high word) with the carry dropped.
 *
 * The listing extent (148 bytes) includes this function's three-word pool at
 * 0x020921CC..0x020921D4; nothing here is a relocation, so the whole range is
 * compared byte for byte.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSL_C_LIB_PopCount64.c \
 *       --func MSL_C_LIB_PopCount64 --addr 0x02092144 --cc 1.1p1 --arm
 *   EXACT, 148 bytes, no relocation sites.
 */
u32 MSL_C_LIB_PopCount64(u64 x)
{
    x = x - ((x >> 1) & 0x5555555555555555ULL);
    x = (x & 0x3333333333333333ULL) + ((x >> 2) & 0x3333333333333333ULL);
    x = (x + (x >> 4)) & 0x0F0F0F0F0F0F0F0FULL;
    x = x + (x >> 8);
    x = x + (x >> 16);
    x = x + (x >> 32);
    return (u32)x & 0xFF;
}

int __signbitd(double x)
{
    u32 *w = (u32 *)&x;

    return (w[1] & 0x80000000u) ? 1 : 0;
}

/*
 * note:     the trailing star is the unlabelled leaf at 0x02092264 (and the
 *           word-run of unlabelled leaves after it), not a byte difference:
 *           the listing extent runs to the next func_ label at 0x020922B0.
 *           Wants a seed at 0x02092264 in layout/function_starts.txt.
 */
int __fpclassifyd(double x)
{
    if ((*(u32 *)((char *)&x + 4) & 0x7FF00000u) != 0) {
        if ((*(u32 *)((char *)&x + 4) & 0x7FF00000u) == 0x7FF00000u)
            return ((*(u32 *)((char *)&x + 4) & 0xFFFFFu) != 0 ||
                    *(u32 *)&x != 0) ? 1 : 2;
    } else {
        return ((*(u32 *)((char *)&x + 4) & 0xFFFFFu) != 0 ||
                *(u32 *)&x != 0) ? 5 : 3;
    }
    return 4;
}

int MSL_C_LIB_MbrToWc(unsigned short *pwc, const unsigned char *s, unsigned int n)
{
    if (s == 0) {
        return 0;
    }
    if (n == 0) {
        return -1;
    }
    if (pwc != 0) {
        *pwc = *s;
    }
    if (*s == 0) {
        return 0;
    }
    return 1;
}

int MSL_C_LIB_WcToMb(char *s, unsigned short wc)
{
    if (s == 0) {
        return 0;
    }
    *s = wc;
    return 1;
}

u32 MSL_C_LIB_CallFormatHook(u32 *dst, u32 c)
{
    return ((MslFormatHookHolder *)gMslFormatHook)->hook->proc(dst, c);
}

u32 MSL_C_LIB_WideToNarrow(u8 *dst, const u16 *src, u32 max)
{
    u32 n = 0;
    u32 tmp;

    if (dst == 0 || src == 0)
        return 0;

    do {
        u32 k;

        if (*src == 0) {
            dst[n] = 0;
            break;
        }
        k = MSL_C_LIB_CallFormatHook(&tmp, *src++);
        if (n + k > max)
            break;
        strncpy(dst + n, (const u8 *)&tmp, k);
        n += k;
    } while (n <= max);

    return n;
}
