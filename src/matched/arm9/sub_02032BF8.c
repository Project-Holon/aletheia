/*
 * function: sub_02032BF8
 * address:  0x02032BF8
 * packet:   pkt_020328E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020319A4  0x020319A4  arm
 *   func_02031EAC  0x02031EAC  arm
 *   func_02031ECC  0x02031ECC  arm
 *   func_020332A4  0x020332A4  arm
 *   func_02033B68  0x02033B68  arm
 *   func_02033BAC  0x02033BAC  arm
 *   func_020336B8  0x020336B8  arm
 *   unk_02146994   0x02146994  data
 *
 * savedata.c.  Commits one record of a backup generation: refresh the
 * record's CRC through sub_020332A4 (src/matched/sub_020332A4.c) and file
 * it in the halfword table 0x02031ECC owns, then write the record itself,
 * four bytes longer than its payload, to the Flash offset that 0x02031EAC
 * and 0x02033B68 name between them.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02032BF8.c \
 *       --func sub_02032BF8 --addr 0x02032BF8 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct SaveBackup {
    u8 pad00[0x2C];
    u32 unk2C;
};

extern struct { u8 pad000[0x208]; u32 unk208; } *unk_02146994;

extern u32 func_020319A4(struct SaveBackup *p, u32 id);
extern u32 func_02031EAC(struct SaveBackup *p, u32 x);
extern u16 *func_02031ECC(struct SaveBackup *p);
extern u16 func_020332A4(struct SaveBackup *p, u32 id);
extern u32 func_02033B68(u8 *p, u32 i);
extern u32 func_02033BAC(u8 *p, u32 i);
extern int func_020336B8(u32 a0, u32 a1, u32 a2, void *a3);

void sub_02032BF8(struct SaveBackup *p, u32 id, u32 x)
{
    u16 *tbl;
    u32 base;
    u32 off;
    u32 len;
    u32 src;

    tbl = func_02031ECC(p);
    tbl[id] = func_020332A4(p, id);
    base = func_02031EAC(p, x);
    off = func_02033B68((u8 *)p->unk2C, id);
    len = func_02033BAC((u8 *)p->unk2C, id);
    src = func_020319A4(p, id);
    func_020336B8(base + off, src, len + 4, (void *)unk_02146994->unk208);
}
