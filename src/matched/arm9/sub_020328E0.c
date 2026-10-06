/*
 * PARKED AT MATCH.  Every concrete byte is right.  The one open site is the
 * `bl` to 0x02031F54: the image holds exactly one branch to that address,
 * the one inside this function, so the `label` class has no outside witness
 * and no split can make one.  It closes the day a second caller turns up or
 * 0x02031F54 itself is matched.
 *
 * function: sub_020328E0
 * address:  0x020328E0
 * packet:   pkt_020328E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02031EAC  0x02031EAC  arm
 *   func_02031F54  0x02031F54  arm
 *   func_020336B8  0x020336B8  arm
 *   unk_02146994   0x02146994  data
 *
 * savedata.c.  Writes the sixteen byte footer of a backup record: the
 * destination is the last sixteen bytes of the area that starts at +0x30
 * and runs for the length 0x02031EAC reports, the source is the matching
 * sixteen bytes of the staging buffer at +0x34, and the fourth argument is
 * the handle the global at 0x02146994 keeps at +0x208.  The call to
 * 0x02031F54 in between is made for its effect only; its result is dropped.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_020328E0.c  *       --func sub_020328E0 --addr 0x020328E0 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct SaveBackup {
    u8 pad00[0x10];
    u32 unk10;
    u32 unk14;
    u8 unk18;
    u8 unk19;
    u8 pad1A[2];
    u8 unk1C;
    u8 pad1D[11];
    u32 unk28;
    u8 pad2C[4];
    u32 unk30;
    u32 unk34;
    u8 pad38[0x10C];
    u32 unk144;
};

struct SaveMain {
    u8 pad000[0x208];
    u32 unk208;
};

extern struct SaveMain *unk_02146994;

extern u32 func_02031EAC(u32 *p, u32 sel);
extern void func_02031F54(const struct SaveBackup *p, u8 *buf);
extern int func_020336B8(u32 a0, u32 a1, u32 a2, void *a3);

int sub_020328E0(struct SaveBackup *p, u32 sel)
{
    u32 dst;
    u32 area;
    u32 buf;

    area = p->unk30;
    dst = area + func_02031EAC((u32 *)p, sel) - 0x10;
    buf = p->unk34;
    func_02031F54(p, (u8 *)buf);
    return func_020336B8(dst, buf + (area - 0x10), 0xF, (void *)unk_02146994->unk208);
}
