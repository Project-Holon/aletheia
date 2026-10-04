/*
 * function: sub_02033200
 * address:  0x02033200
 * packet:   pkt_020328E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02031EAC  0x02031EAC  arm
 *   func_020335AC  0x020335AC  arm
 *   unk_02146994   0x02146994  data
 *
 * savedata.c.  Blanks the sixteen byte footer of a backup record by
 * pushing an all-0xFF block from the stack over it.  The 0x10 is kept in a
 * callee-saved register because it is both the fill length and the write
 * length, one on each side of the MI_CpuFill8 call.
 *
 * 0x02031EAC takes two arguments here.  sub_020328E0 in the same file
 * reaches it with only r0 set, which is the leftover-argument shape of
 * docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md
 * seen from the caller side; two arguments is the honest prototype.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02033200.c \n *       --func sub_02033200 --addr 0x02033200 --cc 1.1p1 --arm
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

extern struct { u8 pad000[0x208]; u32 unk208; } *unk_02146994;

extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern u32 func_02031EAC(struct SaveBackup *p, u32 id);
extern u32 func_020335AC(u32 a, u32 b, u32 c, u32 d);

void sub_02033200(struct SaveBackup *p, u32 id)
{
    u8 tmp[0x10];

    MI_CpuFill8(tmp, 0xFF, sizeof(tmp));
    func_020335AC(p->unk30 + func_02031EAC(p, id) - 0x10, (u32)tmp, sizeof(tmp),
                  unk_02146994->unk208);
}
