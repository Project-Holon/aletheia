/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x020057DC
 * packet:   pkt_02005768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_020057DC, sub_020057E8, sub_02005834, sub_02005858,
 *           sub_02005888, sub_020058D0, sub_02005900, sub_0200590C,
 *           sub_02005924, sub_0200597C, sub_020059A0, sub_020059C8,
 *           sub_02005A00
 *
 * symbols:
 *   sub_020057DC_Cur    0x020AA1AC  data
 *   sub_020057DC_Table  0x020AA1B8  data
 *   func_02072DB0       0x02072DB0  arm
 *   func_02072E9C       0x02072E9C  arm
 *   func_02072EA8       0x02072EA8  arm
 *   func_02074894       0x02074894  arm
 *   func_020748E0       0x020748E0  arm
 *   func_02074AC4       0x02074AC4  arm
 *
 * The accessors of a six element table of 0x1C byte connection slots at
 * 0x020AA1B8 and of the one word "which slot is current" record at
 * 0x020AA1AC.  sub_0200590C, which returns the address of the current
 * slot's payload, was already matched as a single function in
 * arm9/legacy.json; it is the last function of this range and is absorbed
 * here.  func_02072E9C is NHTTPi_InitRequestInfo in layout/symbols_sdk.txt,
 * which is what the payload at offset 8 of a slot is.
 *
 * What the range teaches:
 *
 *  - a field of `table[i]` with a run time `i` puts the field offset in the
 *    relocation addend rather than in the instruction.  sub_020057E8 stores
 *    to five different fields of one slot and loads five different pool
 *    words, 0x020AA1B8, 0x020AA1BC, 0x020AA1C4, 0x020AA1C8, 0x020AA1CC and
 *    0x020AA1D0, which are the table's address plus 0, 4, 0xC, 0x10, 0x14
 *    and 0x18.  Thumb's register-offset `str` has no immediate to spare, so
 *    the compiler folds the member offset into the symbol instead.  Reading
 *    those pool words as six separate objects would be the wrong conclusion.
 *  - the constant -1 is never materialised on its own.  sub_020057E8 needs
 *    a 0 for the first store and derives the -1 for the next four from it
 *    with `subs r1, r4, #1`.
 *
 * The near miss this header used to record, the run
 * 0x02005794..0x020057D8, is now closed as far as the evidence allows.  The
 * `veneer` attestation class carries 0x02072788, so the two twelve byte
 * thunks and the function at 0x020057AC that passes both of their addresses
 * to func_0203508C are src/matched/unit_02005794.c and are EXACT.
 *
 * What is left open is 0x020057C4 alone, 20 bytes, and the reason is
 * unchanged and structural: func_02035108 has exactly one caller anywhere in
 * the 3.9 MB image and it is the `blx` at 0x020057C6 inside that very
 * function.  Shrinking the range cannot help, because the witness is the call
 * itself, and the target is ARM library code that cannot be made `local`.
 * The function also needs sub_02005794 `local`, for the pool word at
 * 0x020057D8 that holds its address.  It closes the day anything else in the
 * image calls 0x02035108.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub020057DCSlot {
    u32 unk00;
    u16 unk04;
    u16 unk06;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
};

struct Sub020057DCCur {
    u16   unk00;
    u16   unk02;
    int   index;
    u32 **unk08;
};

extern struct Sub020057DCCur  sub_020057DC_Cur;
extern struct Sub020057DCSlot sub_020057DC_Table[];

extern void func_02072DB0(int idx, int v);
extern void  func_02072E9C(u32 *info);
extern void  func_02072EA8(u32 *info);
struct S;
extern int   func_02074894(struct S *a);
extern void  func_020748E0(u32 *a, u32 b);
extern int   func_02074AC4(u32 a, int b, u32 *c);

void sub_020057E8(u32 i);
void sub_02005834(u32 v);

void sub_020057DC(u32 **a)
{
    sub_020057DC_Cur.unk08 = a;
}

void sub_020057E8(u32 i)
{
    sub_020057DC_Table[i].unk00 = 0;
    sub_020057DC_Table[i].unk04 = 0xFFFF;
    func_02072EA8(&sub_020057DC_Table[i].unk08);
    sub_020057DC_Table[i].unk0C = -1;
    sub_020057DC_Table[i].unk10 = -1;
    sub_020057DC_Table[i].unk14 = -1;
    sub_020057DC_Table[i].unk18 = -1;
}

void sub_02005834(u32 v)
{
    struct Sub020057DCSlot *slot =
        &sub_020057DC_Table[sub_020057DC_Cur.index];

    slot->unk0C = v;
    slot->unk10 = v;
    slot->unk14 = v;
    slot->unk18 = v;
    slot->unk00 = 1;
}

void sub_02005858(void)
{
    struct Sub020057DCSlot *slot =
        &sub_020057DC_Table[sub_020057DC_Cur.index];

    func_02072EA8(&slot->unk08);
    func_020748E0(*sub_020057DC_Cur.unk08, slot->unk0C);
    sub_020057E8(sub_020057DC_Cur.index);
}

void sub_02005888(u16 a)
{
    int i;

    sub_020057DC_Cur.unk00 = a;
    sub_020057DC_Cur.index = 0;
    for (i = 0; i < 6; i++) {
        sub_020057E8(i);
        func_02072E9C(&sub_020057DC_Table[i].unk08);
    }
    func_02072DB0(sub_020057DC_Cur.unk00, 6);
    sub_02005834(func_02074894((struct S *)*sub_020057DC_Cur.unk08));
}

u16 sub_020058D0(void)
{
    struct Sub020057DCSlot *slot =
        &sub_020057DC_Table[sub_020057DC_Cur.index];
    u16 v;

    if (slot->unk00 == 0) {
        return 0;
    }
    v = slot->unk04;
    if (v == 0xFFFF) {
        v = 0;
    }
    return v;
}

u32 sub_02005900(void)
{
    return sub_020057DC_Cur.index;
}

u32 *sub_0200590C(void)
{
    return &sub_020057DC_Table[sub_020057DC_Cur.index].unk08;
}

int sub_02005924(u32 a)
{
    struct Sub020057DCSlot *slot =
        &sub_020057DC_Table[sub_020057DC_Cur.index];
    int r;

    if (func_02074AC4(a, 3, *sub_020057DC_Cur.unk08) == 0) {
        return 0;
    }
    slot->unk14 = func_02074894((struct S *)*sub_020057DC_Cur.unk08);
    r = func_02074AC4(a, 4, *sub_020057DC_Cur.unk08);
    if (r == 0) {
        return 0;
    }
    slot->unk18 = func_02074894((struct S *)*sub_020057DC_Cur.unk08);
    slot->unk04 = a;
    return r;
}

void sub_0200597C(void)
{
    struct Sub020057DCSlot *slot =
        &sub_020057DC_Table[sub_020057DC_Cur.index];

    slot->unk14 = func_02074894((struct S *)*sub_020057DC_Cur.unk08);
}

int sub_020059A0(u32 a)
{
    struct Sub020057DCSlot *slot =
        &sub_020057DC_Table[sub_020057DC_Cur.index];

    slot->unk18 = func_02074894((struct S *)*sub_020057DC_Cur.unk08);
    slot->unk04 = a;
    return 1;
}

void sub_020059C8(void)
{
    struct Sub020057DCSlot *slot =
        &sub_020057DC_Table[sub_020057DC_Cur.index];

    if (slot->unk00 == 0) {
        return;
    }
    slot->unk04 = 0xFFFF;
    func_020748E0(*sub_020057DC_Cur.unk08, slot->unk10);
    slot->unk14 = slot->unk10;
    slot->unk18 = slot->unk10;
}

int sub_02005A00(void)
{
    struct Sub020057DCSlot *slot =
        &sub_020057DC_Table[sub_020057DC_Cur.index];
    u32 v;

    if (sub_020057DC_Cur.index >= 5) {
        return 0;
    }
    if (slot->unk14 != -1) {
        func_020748E0(*sub_020057DC_Cur.unk08, slot->unk14);
        slot->unk18 = -1;
        v = slot->unk14;
    } else {
        v = slot->unk10;
    }
    sub_020057DC_Cur.index++;
    sub_02005834(v);
    return 1;
}
