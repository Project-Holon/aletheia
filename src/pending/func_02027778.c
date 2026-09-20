/*
 * function: func_02027778
 * address:  0x02027778
 * packet:   pkt_02027778
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note:     re-verified 2026-09-20: DIFF; see verify output
 *
 * symbols:
 *   func_02030734     0x02030734  arm
 *   MIi_CpuCopy16     0x02082A60  arm
 *   func_02027a24     0x02027A24  thumb
 *   func_020355c4     0x020355C4  arm
 *   func_02027b30     0x02027B30  thumb
 *   sFile_020A74E0    0x020A74E0  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct TaskMenuTmpl {
    u32 heapId;
    u8  count;
    u8  pad05[3];
    const void *unk08;
    u32 unk0c;
    u8  pad10[2];
    u8  unk12;
    u8  unk13;
};

struct TaskMenu {
    u8  unk00;
    u8  unk01;
    u16 unk02;
    u32 pad04;
    u32 unk08;
    u32 unk0c;
    u32 unk10;
    u32 unk14;
    void *buf1;
    void *buf2;
    struct TaskMenuTmpl tmpl;
    void *arg1;
};

extern void *func_02030734(u32 heapId, u32 size, u32 clear, const char *file, u32 line);
extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);
extern void func_02027a24(struct TaskMenu *m, void *arg1);
extern u32  func_020355c4(void);
extern void func_02027b30(void *a0, void *arg1, u32 flag);
extern char sFile_020A74E0[];

struct TaskMenu *func_02027778(const struct TaskMenuTmpl *tmpl, void *arg1)
{
    struct TaskMenu *m;
    const u8 *p;

    m = func_02030734((u16)tmpl->heapId, 0x38, 0, sFile_020A74E0, 162);
    m->tmpl = *tmpl;
    m->arg1 = arg1;

    p = (const u8 *)m + 0x24;

    m->buf1 = func_02030734((u16)m->tmpl.heapId, *p * 4, 0, sFile_020A74E0, 168);
    m->buf2 = func_02030734((u16)m->tmpl.heapId, *p * 12, 0, sFile_020A74E0, 169);

    MIi_CpuCopy16(m->tmpl.unk08, m->buf2, *p * 12);

    m->unk0c = 0;
    m->unk10 = 0;
    m->unk00 = 0;
    m->unk01 = 0;
    m->unk02 = 0;
    m->unk14 = 1U;

    {
        u8 *dst12 = &m->tmpl.unk12;
        u8 *dst13;
        if (tmpl->unk12 == 0) {
            *dst12 = 13;
        }

        dst13 = &m->tmpl.unk13;
        if (tmpl->unk13 == 0) {
            *dst13 = 3;
        }
    }

    func_02027a24(m, arg1);

    if (func_020355c4() == 0) {
        func_02027b30(((void **)m->buf1)[m->unk00], m->arg1, 1);
    }

    m->unk08 = 1;
    return m;
}
