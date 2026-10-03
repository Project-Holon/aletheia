/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02007AC8
 * packet:   pkt_020075B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02007AC8, sub_02007AD0, sub_02007AEC, sub_02007AF4,
 *           sub_02007B00, sub_02007B08, sub_02007B20, sub_02007B44,
 *           sub_02007B50
 *
 * symbols:
 *   sub_02007B20_File  0x020A707C  data
 *   sub_020071CC       0x020071CC  thumb
 *   sub_02017550       0x02017550  thumb
 *   func_02030734      0x02030734  arm
 *   func_020307B0      0x020307B0  arm
 *   func_02082A7C      0x02082A7C  arm
 *
 * The two block lookups everything above goes through, the page clear, and
 * a constructor.  sub_02007B20 passes 0x020A707C to the debug allocator at
 * 0x02030734 with the line number 0x57, and the bytes at 0x020A707C spell
 * "perapvoice.c", so the second half of this range is that file.  The
 * string is named by one pool word in the whole image and it is this
 * function's own, so the `literal` class discards its only witness; the
 * `string` class closes it, because "box_savedata.c" ends with its NUL at
 * 0x020A707A and one byte of padding puts the next string at 0x020A707C by
 * construction.
 *
 * Three of the nine carry no label, all because they save nothing.
 * sub_02007AEC and sub_02007B00 return the two object sizes, 0xFF0 and
 * 0x3EC, each as `movs` plus `lsls` rather than a pool word; 0x3EC is what
 * sub_02007B08 clears and what sub_02007B20 allocates, which is how the
 * three tie together.  sub_02007AF4 is a tail call through a pool word, and
 * it is the function every accessor above reaches the entry array with.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub02007AC8Entry {
    u8 data[0x88];
};

extern const char sub_02007B20_File[];

typedef unsigned short u16;
struct Sub020071CCCtrl;
extern void *sub_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
struct Sav;
extern void sub_02017550(struct Sav *entry);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020307B0(void *p);
extern void func_02082A7C(u32 value, void *dest, u32 size);

void sub_02007B08(void *p);

void sub_02007AC8(void *p)
{
    func_020307B0(p);
}

void sub_02007AD0(struct Sub02007AC8Entry *base)
{
    u32 i;

    for (i = 0; i < 30; i++) {
        sub_02017550((struct Sav *)&base[i]);
    }
}

u32 sub_02007AEC(void)
{
    return 0xFF0;
}

struct Sub02007AC8Entry *sub_02007AF4(void **save, u32 box)
{
    return sub_020071CC(*save, box + 1);
}

u32 sub_02007B00(void)
{
    return 0x3EC;
}

void sub_02007B08(void *p)
{
    func_02082A7C(0, p, 0x3EC);
    *(u32 *)p = 0;
}

void *sub_02007B20(u32 heap)
{
    void *p = func_02030734(heap, 0x3EC, 1, sub_02007B20_File, 0x57);

    sub_02007B08(p);
    return p;
}

struct Sub02007AC8Entry *sub_02007B44(void *sys)
{
    return sub_020071CC(sys, 0x24);
}

void *sub_02007B50(void **p)
{
    return *p;
}
