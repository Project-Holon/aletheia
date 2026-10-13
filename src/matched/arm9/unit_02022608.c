/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02022608
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: WIPE_SUB_GetEndColor, WIPE_SUB_ResetBrightnessTask
 *
 * symbols:
 *   WIPE_SetBrightness  0x020222CC  thumb
 *   func_02030EAC  0x02030EAC  arm
 *
 * WIPE_SUB_GetEndColor picks one of two sub-objects at fixed offsets (0x14, 0x44)
 * of its argument depending on a mode field at +0xc, then returns a
 * halfword out of that sub-object when its own flag at +0x28 is 1, or
 * else falls back to a halfword 0x150 bytes into the *original* argument
 * (0x15 << 4), untouched by the sub-object selection.
 *
 * func_02022628 alone comes out EXACT* against `one`: its own extent runs
 * two bytes into the ordinary linker fill in front of WIPE_SUB_ResetBrightnessTask, a
 * real, separately meaningful function.  Pairing the two in one
 * translation unit lets `tu` lay out both sections with that fill in
 * between, which reproduces cleanly.
 *
 * WIPE_SUB_ResetBrightnessTask reads a field 0x10 bytes into its second argument and
 * forwards it, with a fixed 0, to WIPE_SetBrightness (whose own second
 * argument it never reads: see src/matched/WIPE_SetBrightness.c), then calls
 * func_02030EAC on the first argument.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02022608.c \
 *       --addr 0x02022608 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub {
    u8  pad00[0x24];
    u16 unk24;
    u8  pad26[2];
    u32 unk28;
};

struct Obj {
    u8  pad00[0xC];
    u32 unk0C;
    u8  pad10[0x150 - 0x10];
    u16 unk150;
};

u16 WIPE_SUB_GetEndColor(struct Obj *p)
{
    struct Sub *b;

    if (p->unk0C == 1) {
        b = (struct Sub *)((u8 *)p + 0x14);
    } else {
        b = (struct Sub *)((u8 *)p + 0x44);
    }
    if (b->unk28 == 1) {
        return b->unk24;
    }
    return p->unk150;
}

struct Q {
    u8  pad[0x10];
    u32 unk10;
};

struct Node;
extern void WIPE_SetBrightness(u32 which, int brightness);
extern void func_02030EAC(struct Node *n);

void WIPE_SUB_ResetBrightnessTask(void *obj, struct Q *q)
{
    WIPE_SetBrightness(q->unk10, 0);
    func_02030EAC(obj);
}
