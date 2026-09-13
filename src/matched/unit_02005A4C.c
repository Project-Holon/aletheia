/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02005A4C
 * packet:   pkt_02005924
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02005A4C
 *
 * symbols:
 *   sub_02005A4C_Cur    0x020AA1AC  data
 *   sub_02005A4C_Table  0x020AA1B8  data
 *   sub_02005858        0x02005858  thumb
 *   func_02074894       0x02074894  arm
 *   func_02074AC4       0x02074AC4  arm
 *
 * Pop one slot off the stack of connection slots that src/matched/
 * unit_020057DC.c pushes onto.  It is its own byte range rather than part
 * of that unit for an evidence reason and not a source one: func_02074AC4
 * is reached from exactly three `blx` sites image wide, 0x0200593A,
 * 0x02005958 and 0x02005A7A, and the first two are inside
 * unit_020057DC.c's range.  Splitting here leaves each file a witness for
 * the other's calls, which is what the honesty rule in docs/MATCHING.md
 * asks for.
 *
 * `Cur.index` is signed: the guard is `cmp r0, #0` / `bgt`, and written
 * against an unsigned field this compiler emits `bne` instead.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub02005A4CSlot {
    u32 unk00;
    u16 unk04;
    u16 unk06;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
};

struct Sub02005A4CCur {
    u16   unk00;
    u16   unk02;
    int   index;
    u32 **unk08;
};

extern struct Sub02005A4CCur  sub_02005A4C_Cur;
extern struct Sub02005A4CSlot sub_02005A4C_Table[];

extern void sub_02005858(void);
extern u32  func_02074894(u32 *a);
extern int  func_02074AC4(u32 a, int b, u32 *c);

int sub_02005A4C(void)
{
    struct Sub02005A4CSlot *slot;
    int i;
    u16 v;

    if (sub_02005A4C_Cur.index <= 0) {
        return 0;
    }
    sub_02005858();
    i = sub_02005A4C_Cur.index - 1;
    slot = &sub_02005A4C_Table[i];
    v = slot->unk04;
    sub_02005A4C_Cur.index = i;
    if (v != 0xFFFF) {
        func_02074AC4(v, 6, *sub_02005A4C_Cur.unk08);
        slot->unk18 = func_02074894(*sub_02005A4C_Cur.unk08);
    }
    return 1;
}
