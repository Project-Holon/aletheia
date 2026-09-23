/*
 * function: func_02031F54
 * address:  0x02031F54
 * packet:   pkt_02031F54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02031EE8  0x02031EE8  arm
 *   func_02031E7C  0x02031E7C  arm
 *
 * backup_system.c.  Writes the footer descriptor that func_02031EF8 verifies,
 * at func_02031EE8(p, buf) (buf + p->unk30 - 0x10): generation p->unk28,
 * size p->unk30, id p->unk0C, then the CRC-16/CCITT from func_02031E7C at
 * +0x0E.  Closed wave 12: the record pointer is `const`.  With a non-const
 * pointer every field load stays below the previous footer store (the
 * compiler must assume they alias) and six instructions come out in the
 * wrong order; with const the loads float above the stores exactly as the
 * image has them (docs/idioms/const-pointer-lets-a-field-load-survive-a-
 * store.md).  dsi/1.1p1 only; ../2.0/sp2 keeps the 16-byte residue.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02031F54.c \
 *       --func func_02031F54 --addr 0x02031F54 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct SaveBackup {
    u8  pad00[0x0C];
    u32 unk0C;
    u8  pad10[0x18];
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
};

struct Footer {
    u32 gen;
    u32 size;
    u32 id;
    u16 pad;
    u16 crc;
};

extern struct Footer *func_02031EE8(const struct SaveBackup *p, u8 *buf);
extern u16 func_02031E7C(const struct SaveBackup *p, u8 *buf);

void func_02031F54(const struct SaveBackup *p, u8 *buf)
{
    struct Footer *q = func_02031EE8(p, buf);
    q->gen = p->unk28;
    q->size = p->unk30;
    q->id = p->unk0C;
    q->crc = func_02031E7C(p, buf);
}
