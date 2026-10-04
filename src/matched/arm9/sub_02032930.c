/*
 * function: sub_02032930
 * address:  0x02032930
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
 *   func_020336B8  0x020336B8  arm
 *   unk_02146994   0x02146994  data
 *
 * savedata.c.  The one byte twin of sub_020328E0: same area and staging
 * buffer, but it rewrites only the single trailing byte of the record.
 * Unlike sub_020328E0 it does not touch 0x02031F54 first, so nothing has to
 * survive the call and the function gets away with three saved registers.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02032930.c  *       --func sub_02032930 --addr 0x02032930 --cc 1.1p1 --arm
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

extern u32 func_02031EAC(struct SaveBackup *p, u32 sel);
extern int func_020336B8(u32 a0, u32 a1, u32 a2, void *a3);

int sub_02032930(struct SaveBackup *p, u32 sel)
{
    u32 area = p->unk30;
    u32 end = area + func_02031EAC(p, sel);

    return func_020336B8(end - 1, p->unk34 + (area - 1), 1, (void *)unk_02146994->unk208);
}
