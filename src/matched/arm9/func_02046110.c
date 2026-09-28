/*
 * function: func_02046110
 * address:  0x02046110
 * packet:   pkt_02046110
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020495F4  0x020495F4  arm
 *   func_0204960C  0x0204960C  arm
 *
 * msgdata.c: point the MsgData object at the selected language bank.  The
 * archive header holds one u32 bank offset per language at +0x0C; with no
 * file handle the bank is resident and the object records archive +
 * offset, otherwise it seeks, reads the leading u32 size, seeks back and
 * reads the whole bank.
 *
 * The four bytes the earlier notes could not reach (docs/notes/
 * func_02046110.c.txt, pkt_02046110.c.txt) are the `ldreq r0, [r4]`
 * reload of the archive pointer in the resident arm.  Every plain spelling
 * CSEs it into the load already made for the offset table; declaring the
 * member `volatile` keeps both loads and leaves every other instruction,
 * the predication included, unchanged.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct MsgArchive {
    u16 bankCount;
    u16 unk02;
    u32 unk04;
    u32 unk08;
    u32 bankOffset[1];
};

struct MsgData {
    struct MsgArchive * volatile archive;
    void *bank;
    u32 unk08;
    u32 unk0C;
    u32 baseOffset;
    void *file;
    u16 unk18;
    u8 bankIndex;
    u8 mode;
};

extern void func_020495F4(void *file, u32 size, void *dst);
extern void func_0204960C(void *file, u32 pos);

void func_02046110(struct MsgData *msg)
{
    u32 size;
    u32 offset = msg->archive->bankOffset[msg->bankIndex];

    if (msg->file == 0) {
        msg->bank = (u8 *)msg->archive + offset;
    } else {
        func_0204960C(msg->file, msg->baseOffset + offset);
        func_020495F4(msg->file, 4, &size);
        func_0204960C(msg->file, msg->baseOffset + offset);
        func_020495F4(msg->file, size, msg->bank);
    }
}
