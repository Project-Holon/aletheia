/*
 * function: sub_020332A4
 * address:  0x020332A4
 * packet:   pkt_020328E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02033B68        0x02033B68  arm
 *   func_02033BAC        0x02033BAC  arm
 *   MATH_CalcCRC16CCITT  0x02081B8C  arm
 *   unk_02146994         0x02146994  data
 *
 * savedata.c.  Recomputes the CRC-16/CCITT of one record in the staging
 * buffer and stores it in the halfword that follows the record.  The table
 * argument is the global at 0x02146994 plus four, i.e. a MATHCRC16Table
 * that lives inline at +4 of that object rather than a pointer kept there.
 * As in sub_02033264 the answer is read back out of the halfword it was
 * just stored into.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020332A4.c \n *       --func sub_020332A4 --addr 0x020332A4 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct SaveBackup {
    u8 pad00[0x2C];
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u8 pad38[0x108];
    u32 unk140;
};

extern struct { u8 pad000[4]; u8 crcTable[1]; } *unk_02146994;

extern u32 func_02033B68(u32 table);
extern u32 func_02033BAC(u32 table, u32 id);
extern u16 MATH_CalcCRC16CCITT(const void *table, const void *data, u32 len);

u16 sub_020332A4(struct SaveBackup *p, u32 id)
{
    u32 base;
    u32 len;
    u16 *q;
    u32 buf;

    base = func_02033B68(p->unk2C);
    len = func_02033BAC(p->unk2C, id);
    buf = p->unk34;
    q = (u16 *)(buf + (base + len));
    q[1] = MATH_CalcCRC16CCITT(unk_02146994->crcTable, (void *)(buf + base), len);
    return q[1];
}
