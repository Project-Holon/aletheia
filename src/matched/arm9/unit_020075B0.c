/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x020075B0
 * packet:   pkt_020075B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_020075B0, sub_02007610
 *
 * symbols:
 *   sub_020075B0_File  0x020A7068  data
 *   sub_020074CC       0x020074CC  thumb
 *   sub_02007AF4       0x02007AF4  thumb
 *   sub_020181A0       0x020181A0  thumb
 *   func_02034714      0x02034714  arm
 *
 * Writing one box entry and swapping two of them.  Both reach the entry
 * array through sub_02007AF4 the way every function of this file does, and
 * both copy a whole 0x88 byte entry with the inline eight byte ldm/stm loop
 * of docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md: 0x11
 * iterations of two words.  The entry struct is therefore declared as an
 * array of u32 and not of u8, because a one aligned struct would have given
 * a 0x88 iteration ldrb/strb loop instead.
 *
 * sub_020075B0 bounds the box index against the header byte at 0x3DD rather
 * than against the constant 0x18 the rest of the file uses, and that byte is
 * past every Thumb immediate, so it arrives as a pool word and a register
 * offset ldrb.  The failure arm passes 0x020A7068 twice to func_02034714,
 * the same empty string and the same three argument assert shape as
 * sub_020077B8 in unit_02007774.c.
 *
 * sub_02007610 is the three assignment swap through a 0x88 byte stack
 * temporary, and its fifth argument arrives on the stack: `ldr r1, [sp,
 * #0xa0]` is 0x88 of locals plus the six saved registers, not a local.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub020075B0Entry {
    u32 data[0x22];
};

struct Sub020075B0Header {
    u32 unk00;
    u8  pad04[0x3C4 - 4];
    u8  unk3C4[0x18];
    u8  unk3DC;
    u8  unk3DD;
};

extern const char sub_020075B0_File[];

extern struct Sub020075B0Header *sub_020074CC(void *save);
extern struct Sub020075B0Entry  *sub_02007AF4(void *save, u32 box);
extern void sub_020181A0(void *p);
extern void func_02034714(const char *expr, u32 line, const char *file);

int sub_020075B0(void *save, u32 box, u32 slot,
                 const struct Sub020075B0Entry *src)
{
    struct Sub020075B0Header *h = sub_020074CC(save);

    if (box == -1) {
        box = h->unk00;
    }
    if (box < h->unk3DD && slot < 30) {
        struct Sub020075B0Entry *base = sub_02007AF4(save, box);

        base[slot] = *src;
        sub_020181A0(&base[slot]);
        return 1;
    }
    func_02034714(sub_020075B0_File, 0, sub_020075B0_File);
    return 0;
}

void sub_02007610(void *save, u32 box1, u32 slot1, u32 box2, u32 slot2)
{
    struct Sub020075B0Entry tmp;
    struct Sub020075B0Entry *p1 = sub_02007AF4(save, box1);
    struct Sub020075B0Entry *p2 = sub_02007AF4(save, box2);

    tmp = p1[slot1];
    p1[slot1] = p2[slot2];
    p2[slot2] = tmp;
}
