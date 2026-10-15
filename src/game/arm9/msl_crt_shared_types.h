#ifndef MSL_CRT_SHARED_TYPES_H
#define MSL_CRT_SHARED_TYPES_H

typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned int   size_t;

struct MslRefBlock {
    u32 reserved00;
    u32 *refs;
};

typedef struct MslStream {
    u32 handle;             /* 0x00 */
    u32 mode;               /* 0x04 */
    u32 state;              /* 0x08 */
    u8  eof;                /* 0x0c */
    u8  error;              /* 0x0d */
    u8  pad0e[0x0a];
    u32 position;           /* 0x18 */
    u32 buffer;             /* 0x1c */
    u32 buffer_size;        /* 0x20 */
    u32 buffer_ptr;         /* 0x24 */
    u32 buffer_len;         /* 0x28 */
    u32 buffer_alignment;   /* 0x2c */
    u32 pad30;              /* 0x30 */
    u32 saved_buffer_len;   /* 0x34 */
    u32 (*seek_proc)(u32, u32 *, u32, u32);  /* 0x38 */
    u32 read_proc;          /* 0x3c */
    u32 write_proc;         /* 0x40 */
    u32 close_proc;         /* 0x44 */
    u32 ref_con;            /* 0x48 */
} MslStream;

struct MslFileKind {
    u32 pad  : 7;
    u32 kind : 3;
    u32 rest : 22;
};

struct MslStateBits {
    u32 mode : 3;
    u32 rest : 29;
};

#endif
