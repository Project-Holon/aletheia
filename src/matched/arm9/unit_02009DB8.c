/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x02009DB8
 * packet:   pkt_02009DB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02009DB8, sub_02009DE8, sub_02009E40, sub_02009E54,
 *           sub_02009E74, sub_02009E8C, sub_02009EA8, sub_02009EB0
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *   MI_CpuMove   0x02083194  arm
 *
 * alias: the body of the 0xD54-byte record whose head is
 * src/matched/unit_02009D9C.c.  It is a hundred-slot most-recently-used list
 * of the 0x20-byte object of src/matched/unit_0200852C.c, plus one counter:
 *
 *   +0x000  Sub0200852CObj[100]   0x20 bytes each
 *   +0xD50  u32                   a use count, saturating at 99999
 *
 * sub_02008468, four bytes returning 0x20, is the element size, and
 * sub_02009DE8 uses it for both of its block moves rather than spelling 0x20
 * out.  The insert shifts the whole list up by one slot with MI_CpuMove and
 * copies the new object into slot 0, so slot 0 is the most recent; when the
 * object is already in the list only its +0x1C byte is refreshed.
 *
 * sub_02009DB8 returns -1 for "not found", materialised as `movs r0, #0` and
 * `mvns r0, r0` rather than as a pool word, and every caller compares against
 * that same pair.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009DB8.c \
 *       --addr 0x02009DB8 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void MI_CpuMove(const void *src, void *dest, u32 size);

struct Sub0200852CObj {
    u8 unk00[0x1B];
    u8 unk1B;
    u8 unk1C;
    u8 unk1D[3];
};

extern int sub_02008468(void);
extern u32 sub_02008530(const struct Sub0200852CObj *obj);
extern u8  sub_02008554(const struct Sub0200852CObj *obj);
extern void sub_02008558(struct Sub0200852CObj *obj, u8 value);
extern u8  sub_0200855C(const struct Sub0200852CObj *obj);

struct Sub02009D9CObj {
    struct Sub0200852CObj unk000[100];
    u8  unkC80[0xD0];
    u32 unkD50;
};

int sub_02009DB8(struct Sub02009D9CObj *obj, u32 id);
u32 sub_02009E40(struct Sub02009D9CObj *obj, u32 i);

int sub_02009DB8(struct Sub02009D9CObj *obj, u32 id)
{
    int i;

    for (i = 0; i < 100; i++) {
        if (sub_0200855C(&obj->unk000[i]) != 0
            && id == sub_02008530(&obj->unk000[i])) {
            return i;
        }
    }
    return -1;
}

void sub_02009DE8(struct Sub02009D9CObj *obj, struct Sub0200852CObj *p)
{
    u32 id = sub_02008530(p);
    u32 size = sub_02008468();
    int i;

    if (id == 0) {
        return;
    }
    i = sub_02009DB8(obj, id);
    if (i != -1) {
        sub_02008558(&obj->unk000[i], sub_02008554(p));
        return;
    }
    MI_CpuMove(obj->unk000, &obj->unk000[1], size * 99);
    MI_CpuCopy8(p, obj->unk000, size);
}

u32 sub_02009E40(struct Sub02009D9CObj *obj, u32 i)
{
    if (i >= 100) {
        i = 0;
    }
    return sub_02008530(&obj->unk000[i]);
}

struct Sub0200852CObj *sub_02009E54(struct Sub02009D9CObj *obj, u32 i)
{
    if (i >= 100) {
        return 0;
    }
    if (sub_02009E40(obj, i) == 0) {
        return 0;
    }
    return &obj->unk000[i];
}

u32 sub_02009E74(struct Sub02009D9CObj *obj, u32 id)
{
    if (sub_02009DB8(obj, id) != -1) {
        return 1;
    }
    return 0;
}

int sub_02009E8C(struct Sub02009D9CObj *obj)
{
    int i;

    for (i = 0; i < 100; i++) {
        if (sub_0200855C(&obj->unk000[i]) == 0) {
            break;
        }
    }
    return i;
}

u32 sub_02009EA8(const struct Sub02009D9CObj *obj)
{
    return obj->unkD50;
}

void sub_02009EB0(struct Sub02009D9CObj *obj)
{
    obj->unkD50 = obj->unkD50 + 1;
    if (obj->unkD50 > 99999) {
        obj->unkD50 = 99999;
    }
}
