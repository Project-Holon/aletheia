/*
 * unit:     no
 * function: sub_02045EC0
 * address:  0x02045EC0
 * packet:   pkt_02045EC0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_02046180  0x02046180  arm
 *   sub_0204960C  0x0204960C  arm
 *   sub_020495F4  0x020495F4  arm
 *   sub_020457B0  0x020457B0  arm
 *   sub_02045CAC  0x02045CAC  arm
 *
 * Message bank string allocator and loader: given a bank and an entry index,
 * reads the entry descriptor (from the resident array or stream), allocates
 * a buffer sized for the string length, decodes the string into it via
 * sub_02045CAC, and returns the allocated buffer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045EC0.c \
 *       --func sub_02045EC0 --addr 0x02045EC0 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct MsgEntry {
    u32 off;
    u16 len;
    u16 pad_06;
};

struct MsgFile {
    u16 langCount;
    u16 count;
    u32 unk_04;
    u32 unk_08;
    u32 langOff[1];
};

struct MsgBank {
    const struct MsgFile *file;
    void                 *base;
    struct MsgEntry       cache;
    u32                   origin;
    void                 *stream;
    u16                   heapId;
    u8                    langIndex;
    u8                    resident;
};

extern void  sub_02046180(struct MsgBank *bank);
extern void  sub_0204960C(void *stream, u32 offset);
struct ArcFile;
struct U16Vec;
extern void sub_020495F4(struct ArcFile *arc, u32 size, void *dst);
extern struct U16Vec *sub_020457B0(u32 capacity, u32 heapId);
extern void  sub_02045CAC(struct MsgBank *bank, u32 index, void *buf);

void *sub_02045EC0(struct MsgBank *bank, u32 index)
{
    struct MsgEntry *e;
    void *buf;

    sub_02046180(bank);

    if (bank->resident == 0) {
        u32 pos = bank->origin + bank->file->langOff[bank->langIndex];

        sub_0204960C(bank->stream, pos + (index * 8 + 4));
        sub_020495F4(bank->stream, 8, &bank->cache);
        e = &bank->cache;
    } else {
        e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
    }

    buf = sub_020457B0(e->len, bank->heapId);
    sub_02045CAC(bank, index, buf);
    return buf;
}
