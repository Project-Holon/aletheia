/*
 * docs/families/msgdata.h -- shared declarations for the msgdata.c family
 * (0x02045B38..0x020461E4 in the ARM9 image, ARM code, dsi/1.1p1 -O4,p).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file.  Fields are
 * evidenced by EXACT files in src/matched: func_02045F5C, func_02046110
 * (wave 15), sub_02045B38, unit_02045C44, sub_02046180, func_02045E3C.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct MsgEntry {               /* one 8-byte string descriptor */
    u32 offset;                 /* bank-relative */
    u16 count;                  /* UTF-16 characters */
    u16 pad;
};

struct MsgArchive {             /* archive header */
    u16 bankCount;
    u16 unk02;
    u32 unk04;
    u32 unk08;
    u32 bankOffset[1];          /* +0x0C, one per language bank */
};

struct MsgData {
    struct MsgArchive *archive; /* +0x00 (func_02046110 needs it volatile) */
    void *bank;                 /* +0x04 resident bank, or read buffer */
    struct MsgEntry entry;      /* +0x08 descriptor read from file */
    u32 baseOffset;             /* +0x10 archive position in the file */
    void *file;                 /* +0x14 file handle, 0 when resident */
    u16 unk18;
    u8  bankIndex;              /* +0x1A */
    u8  mode;                   /* +0x1B 0 = file-backed, else resident */
};

void func_02046180(struct MsgData *msg);                /* select bank */
void func_02046110(struct MsgData *msg);                /* load bank */
void func_02045F5C(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
u32  func_02045E3C(u16 *str, u32 count, u32 msgIndex);  /* decode in place */
u16  func_02045A98(void);                               /* EOM code */
void func_0204960C(void *file, u32 pos);                /* seek */
void func_020495F4(void *file, u32 size, void *dst);    /* read */

/*
 * Levers (wave 15):
 *  - func_02045F5C: `if (mode == 0) { file } else { resident }` predicates
 *    the else arm and places it first; the `!= 0` spelling is 11 bytes out.
 *  - func_02046110: the resident arm reloads archive (`ldreq r0, [r4]`);
 *    only a volatile member keeps that second load.
 */
