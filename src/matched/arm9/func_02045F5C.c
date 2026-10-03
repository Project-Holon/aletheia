/*
 * function: func_02045F5C
 * address:  0x02045F5C
 * packet:   pkt_02045F5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02046180  0x02046180  arm
 *   func_0204960C  0x0204960C  arm
 *   func_020495F4  0x020495F4  arm
 *   func_02045E3C  0x02045E3C  arm
 *   func_02045A98  0x02045A98  arm
 *
 * msgdata.c: read string msgIndex into str (at most maxLen characters),
 * either from the resident bank (mode != 0) or by seeking the archive file,
 * then decode it in place (func_02045E3C) and terminate it with the EOM
 * code (func_02045A98).
 *
 * The 11-byte scheduling residue of docs/notes/pkt_02045F5C.c.txt was the
 * first test's polarity: written `mode == 0` with the file arm first, the
 * compiler predicates the else arm (ldrne/addne/addne/bne) and schedules
 * the file arm's loads in the image's order.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct MsgEntry {
    u32 offset;
    u16 count;
    u16 pad;
};

struct MsgArchive {
    u16 bankCount;
    u16 unk02;
    u32 unk04;
    u32 unk08;
    u32 bankOffset[1];
};

struct MsgData {
    struct MsgArchive *archive; /* +0x00 */
    void *bank;                 /* +0x04 */
    struct MsgEntry entry;      /* +0x08 */
    u32 baseOffset;             /* +0x10 */
    void *file;                 /* +0x14 */
    u16 unk18;                  /* +0x18 */
    u8 bankIndex;               /* +0x1A */
    u8 mode;                    /* +0x1B */
};

extern void func_02046180(struct MsgData *msg);
extern void func_0204960C(void *file, u32 pos);
struct ArcFile;
extern void func_020495F4(struct ArcFile *arc, u32 size, void *dst);
extern u32  func_02045E3C(u16 *str, u32 count, u32 msgIndex);
extern u16  func_02045A98(void);

void func_02045F5C(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen)
{
    const struct MsgEntry *entry;
    u32 count;
    u32 len;

    func_02046180(msg);

    if (msg->mode == 0) {
        u32 bankOffset = msg->archive->bankOffset[msg->bankIndex];
        func_0204960C(msg->file, (msg->baseOffset + bankOffset) + (msgIndex * 8 + 4));
        func_020495F4(msg->file, 8, &msg->entry);
        entry = &msg->entry;
    } else {
        entry = (const struct MsgEntry *)((u8 *)msg->bank + 4 + msgIndex * 8);
    }

    count = entry->count;
    if (count > maxLen) {
        count = maxLen;
    }

    if (msg->mode == 0) {
        u32 readBytes = count * 2;
        if (readBytes > maxLen * 2) {
            readBytes = maxLen * 2;
        }
        {
            u32 bankOffset = msg->archive->bankOffset[msg->bankIndex];
            func_0204960C(msg->file, (msg->baseOffset + bankOffset) + entry->offset);
            func_020495F4(msg->file, readBytes, str);
        }
    } else {
        const u16 *src = (const u16 *)((u8 *)msg->bank + entry->offset);
        u32 i;
        for (i = 0; i < count; i++) {
            str[i] = src[i];
        }
    }

    len = func_02045E3C(str, count, msgIndex);
    str[len] = func_02045A98();
}
