/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x02009A34
 * packet:   pkt_020095E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02009A34, sub_02009A54, sub_02009A74, sub_02009AE4,
 *           sub_02009B3C, sub_02009B80, sub_02009BB8
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0203F4E4  0x0203F4E4  arm
 *
 * alias: wifilist.c's list maintenance.  The two parallel arrays of
 * src/matched/unit_02009860.c hold 32 slots each, an 0x0C-byte DWC friend
 * record at +0x40 and an 0x30-byte entry at +0x1C0, and every function here
 * moves both together.
 *
 * sub_02009B3C is the compaction pass and is the one worth reading.  It scans
 * the 32 slots keeping `j` at the first hole it has seen, and when it finds a
 * used slot after a hole it moves it down with sub_02009AE4 and then sets
 * `i = -1` so the `i++` restarts the scan from zero.  The compiler cross-jumps
 * the two assignments to `j`: the restart arm's `j = -1` and the hole arm's
 * `j = i` become one `adds r5, r4, #0` reached from both, which is only
 * correct because `i` has just been set to -1 on the first path.  Reading that
 * shared instruction as a single statement is what makes the restart visible.
 *
 * -1 costs three materialisations here, one in a register and two in stack
 * slots, because the function is out of callee-saved registers: the same
 * constant is the loop's sentinel, the value assigned to `i`, and the value
 * compared against in the other arm.
 *
 * The tail of sub_02009A74 is where the shape of the source is visible.  It
 * clears slot 31 of both arrays, and the original reaches it as base plus
 * offset in two separate adds: `obj + 0x1C0` and then `+ 0x5D0`, with the
 * friend array's `+ 0x174` derived from that same 0x5D0 by a `lsrs #2`.
 * Written as `&obj->unk1C0[31]` the compiler folds the two constants into one
 * 0x790 and the tail is 34 bytes different; only a local pointer, assigned
 * from the array *after* the loop and indexed with the literal 31, keeps them
 * apart.  Assigning the same pointers before the loop is wrong too: they then
 * stay live in callee-saved registers and the reload of `obj` from its stack
 * slot disappears.
 *
 * sub_02009B80 stamps the entry with the date.  func_0203F4E4 fills a 0x10-byte
 * record on the stack whose first three words are year, month and day, and the
 * year is stored as `year + 2000`, which is the `movs r0, #0x7D; lsls r0, #4`
 * in front of the `strh`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009A34.c \
 *       --addr 0x02009A34 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

struct Sub020097BCFriend {
    u8 unk00[0xC];
};

struct Sub020097BCEnt {
    u8  unk00[0x1C];
    u32 unk1C;
    u32 unk20;
    u16 unk24;
    u16 unk26;
    u16 unk28;
    u16 unk2A;
    u8  unk2C;
    u8  unk2D;
    u8  unk2E;
    u8  unk2F_0 : 2;
    u8  unk2F_2 : 6;
};

struct Sub020097BCObj {
    u8 unk000[0x40];
    struct Sub020097BCFriend unk040[0x20];
    struct Sub020097BCEnt    unk1C0[32];
    u8 unk7C0[4];
};

struct Sub0203F4E4Date {
    s32 year;
    s32 month;
    s32 day;
    s32 week;
};

extern void func_0203F4E4(struct Sub0203F4E4Date *date);
extern int  sub_02009A1C(struct Sub020097BCObj *obj, u32 i);

void sub_02009AE4(struct Sub020097BCObj *obj, u32 dest, u32 src);
void sub_02009B80(struct Sub020097BCObj *obj, int i);

u32 sub_02009A34(struct Sub020097BCObj *obj)
{
    int i;
    u32 count = 0;

    for (i = 0; i < 0x20; i++) {
        if (sub_02009A1C(obj, i) != 0) {
            count++;
        }
    }
    return count;
}

u32 sub_02009A54(struct Sub020097BCObj *obj)
{
    int i;
    u32 last = 0;

    for (i = 0; i < 0x20; i++) {
        if (sub_02009A1C(obj, i) != 0) {
            last = i + 1;
        }
    }
    return last;
}

void sub_02009A74(struct Sub020097BCObj *obj, u32 i)
{
    struct Sub020097BCEnt *ents;
    struct Sub020097BCFriend *friends;

    if (i >= 0x20) {
        return;
    }
    for (; (int)i < 0x1F; i++) {
        MI_CpuCopy8(&obj->unk1C0[i + 1], &obj->unk1C0[i],
                    sizeof(obj->unk1C0[0]));
        MI_CpuCopy8(&obj->unk040[i + 1], &obj->unk040[i],
                    sizeof(obj->unk040[0]));
    }
    ents = obj->unk1C0;
    friends = obj->unk040;
    MI_CpuFill8(&ents[0x1F], 0, sizeof(ents[0]));
    MI_CpuFill8(&friends[0x1F], 0, sizeof(friends[0]));
}

void sub_02009AE4(struct Sub020097BCObj *obj, u32 dest, u32 src)
{
    MI_CpuCopy8(&obj->unk1C0[src], &obj->unk1C0[dest], sizeof(obj->unk1C0[0]));
    MI_CpuCopy8(&obj->unk040[src], &obj->unk040[dest], sizeof(obj->unk040[0]));
    MI_CpuFill8(&obj->unk1C0[src], 0, sizeof(obj->unk1C0[0]));
    MI_CpuFill8(&obj->unk040[src], 0, sizeof(obj->unk040[0]));
}

void sub_02009B3C(struct Sub020097BCObj *obj)
{
    int i;
    int j = -1;

    for (i = 0; i < 0x20; i++) {
        if (sub_02009A1C(obj, i) != 0) {
            if (j != -1) {
                sub_02009AE4(obj, j, i);
                i = -1;
                j = -1;
            }
        } else {
            if (j == -1) {
                j = i;
            }
        }
    }
}

void sub_02009B80(struct Sub020097BCObj *obj, int i)
{
    struct Sub0203F4E4Date date;

    func_0203F4E4(&date);
    obj->unk1C0[i].unk2A = date.year + 2000;
    obj->unk1C0[i].unk2C = date.month;
    obj->unk1C0[i].unk2D = date.day;
}

void sub_02009BB8(struct Sub020097BCObj *obj, int i, int a, int b, int c)
{
    if (i < 0 || i >= 0x20) {
        return;
    }
    obj->unk1C0[i].unk24 += (u16)a;
    if (obj->unk1C0[i].unk24 > 9999) {
        obj->unk1C0[i].unk24 = 9999;
    }
    obj->unk1C0[i].unk26 += (u16)b;
    if (obj->unk1C0[i].unk26 > 9999) {
        obj->unk1C0[i].unk26 = 9999;
    }
    obj->unk1C0[i].unk28 += (u16)c;
    if (obj->unk1C0[i].unk28 > 9999) {
        obj->unk1C0[i].unk28 = 9999;
    }
    sub_02009B80(obj, i);
}
