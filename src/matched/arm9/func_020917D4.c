/*
 * function: __fread
 * address:  0x020917D4
 * packet:   pkt_020917D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * MSL C `__fread` (buffered stdio read), transcribed from the Metrowerks MSL
 * shape: fwide orientation probe, pushback drain through ungetc_buffer /
 * ungetwc_buffer, buffered copy loop through __load_buffer (__load_buffer)
 * and memcpy (func_02092344), then the unbuffered direct read that borrows
 * buffer/buffer_size.  Returns bytes_read / memb_size (func_0209C2B0).
 * The two levers over the earlier 788/456 note body were (1) writing it as
 * MSL writes it (always_buffer = !binary_io || buffer_mode == _IOFBF, the
 * set_error / set_eof bodies spelled out in each arm) and (2) the FILE
 * layout: eof/error are plain u8 members at +0x0c/+0x0d, NOT inside an
 * 8-byte state struct, which puts ungetc_buffer at +0x12 and ungetwc_buffer
 * at +0x14.  Project default compiler; EXACT on the first full transcription.
 *
 * symbols:
 *   fwide  0x02096508  arm
 *   MSL_C_LIB_FlushAllGated  0x0209149C  arm
 *   __load_buffer  0x020915C4  arm
 *   func_02092344  0x02092344  arm
 *   __prep_buffer  0x0209159C  arm
 *   func_0209C2B0  0x0209C2B0  arm
 */
#include "../include/Obj16696.h"
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned int   size_t;
typedef unsigned short wchar_t;

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

enum { __neutral, __writing, __reading, __rereading };
enum { __no_io_error, __io_error, __io_EOF };

struct S0209159C;
struct S020915C4;
extern int fwide(u8 *p, int v);                 /* fwide */
extern int  MSL_C_LIB_FlushAllGated(void);                                 /* __flush_line_buffered_output_files */
extern int __load_buffer(struct S020915C4 *p, u32 *a1, int a2); /* __load_buffer */
extern void *func_02092344(void *dest, const void *src, unsigned int n); /* memcpy */
extern void __prep_buffer(struct S0209159C *p);                           /* __prep_buffer */
extern u32  func_0209C2B0(u32 a, u32 b);                         /* udiv */

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
                ((struct Obj16696 *)read_ptr)->f0 = file->ungetwc_buffer[file->state.io_state - __rereading];
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
                ioresult = __load_buffer((struct S020915C4 *)file, 0, 0);
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

            func_02092344(read_ptr, file->buffer_ptr, num_bytes);

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

        ioresult = __load_buffer((struct S020915C4 *)file, &num_bytes, 1);
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

        __prep_buffer((struct S0209159C *)file);

        file->buffer_len = 0;
    }

    return func_0209C2B0(bytes_read, memb_size);
}
