/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x0200785C
 * packet:   pkt_020075B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0200785C, sub_02007898, sub_020078C4, sub_0200791C,
 *           sub_02007984, sub_020079A0
 *
 * symbols:
 *   sub_0200785C_File  0x020A7068  data
 *   sub_020074CC       0x020074CC  thumb
 *   sub_02007AF4       0x02007AF4  thumb
 *   sub_02017E88       0x02017E88  thumb
 *   func_02034714      0x02034714  arm
 *   func_02045924      0x02045924  arm
 *   func_02045A38      0x02045A38  arm
 *
 * The box name getter and setter, two per box counts, and the whole-storage
 * totals that sum each of them over all 24 boxes.
 *
 * The range has to be exactly these six functions.  sub_020078C4 is called
 * from one place in the image and sub_0200791C from one place, and those two
 * places are sub_02007984 and sub_020079A0 respectively, so a file that
 * stopped before the summing loops would leave both counts with no witness
 * outside the compared range and cap at MATCH.  Inside one range they are
 * `local` and cost no image evidence at all.  It cuts the other way too: the
 * file cannot start any later than 0x0200785C, because that is where the
 * 0x28 byte name array's first user is.
 *
 * The header's layout falls out of the two shapes.  The name accessors do
 * `adds r2, r1, #4` and then multiply the box index by 0x28, so the names
 * are an array of 24 0x28 byte entries starting at offset 4 and ending at
 * 4 + 24 * 0x28 = 0x3C4, which is exactly where the per box byte the rest of
 * the file reads begins.
 *
 * Two of the six needed their locals reordering before they matched, and the
 * evidence is only ever which register a value lands in.  sub_0200791C
 * declares its slot counter before the entry base, the reverse of
 * sub_020078C4 immediately above it, and that one line is the whole
 * difference between r4/r5 and r5/r4 throughout its loop.  The two summing
 * loops initialise the box index before the running total, which is why
 * they are written `for (box = 0, n = 0; ...)` rather than initialising the
 * total at its declaration: the order of the two `movs rN, #0` follows the
 * order of the initialisers, and nothing else in either function does.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub0200785CName {
    u8 data[0x28];
};

struct Sub0200785CEntry {
    u8 data[0x88];
};

struct Sub0200785CHeader {
    u32 unk00;
    struct Sub0200785CName unk04[0x18];
    u8  unk3C4[0x18];
    u8  unk3DC;
    u8  unk3DD;
};

extern const char sub_0200785C_File[];

typedef unsigned short u16;
struct Strbuf;
struct Sub02007454Header;
struct Sub02007AC8Entry;
extern struct Sub02007454Header *sub_020074CC(void **save);
extern struct Sub02007AC8Entry *sub_02007AF4(void **save, u32 box);
extern u32 sub_02017E88(void *p, u32 id, u32 v);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02045924(struct Strbuf *o, const u16 *src);
struct U16Vec;
extern void func_02045A38(struct U16Vec *src, unsigned short *dest,
                          u32 n);

int sub_020078C4(void *save, u32 box);
int sub_0200791C(void *save, u32 box);

void sub_0200785C(void *save, u32 box, void *dest)
{
    struct Sub0200785CHeader *h = (struct Sub0200785CHeader *)sub_020074CC(save);

    if (box == -1) {
        box = h->unk00;
    }
    if (box < 0x18) {
        func_02045924(dest, (const u16 *)(&h->unk04[box]));
        return;
    }
    func_02034714(sub_0200785C_File, 0, sub_0200785C_File);
}

void sub_02007898(void *save, u32 box, const void *src)
{
    struct Sub0200785CHeader *h = (struct Sub0200785CHeader *)sub_020074CC(save);

    if (box == -1) {
        box = h->unk00;
    }
    if (box < 0x18) {
        func_02045A38((struct U16Vec *)src, (unsigned short *)&h->unk04[box], 0x14);
    }
}

int sub_020078C4(void *save, u32 box)
{
    struct Sub0200785CHeader *h = (struct Sub0200785CHeader *)sub_020074CC(save);
    struct Sub0200785CEntry *base;
    int slot;
    int n;

    if (box == -1) {
        box = h->unk00;
    }
    if (box < 0x18) {
        n = 0;
        base = (struct Sub0200785CEntry *)sub_02007AF4(save, box);
        for (slot = 0; slot < 30; slot++) {
            if (sub_02017E88(&base[slot], 0xA9, 0) != 0) {
                n++;
            }
        }
        return n;
    }
    func_02034714(sub_0200785C_File, 0, sub_0200785C_File);
    return 0;
}

int sub_0200791C(void *save, u32 box)
{
    struct Sub0200785CHeader *h = (struct Sub0200785CHeader *)sub_020074CC(save);
    int slot;
    struct Sub0200785CEntry *base;
    int n;

    if (box == -1) {
        box = h->unk00;
    }
    if (box < 0x18) {
        n = 0;
        base = (struct Sub0200785CEntry *)sub_02007AF4(save, box);
        for (slot = 0; slot < 30; slot++) {
            if (sub_02017E88(&base[slot], 0xA9, 0) != 0 &&
                sub_02017E88(&base[slot], 0x4C, 0) == 0) {
                n++;
            }
        }
        return n;
    }
    func_02034714(sub_0200785C_File, 0, sub_0200785C_File);
    return 0;
}

int sub_02007984(void *save)
{
    int n;
    u32 box;

    for (box = 0, n = 0; box < 0x18; box++) {
        n += sub_020078C4(save, box);
    }
    return n;
}

int sub_020079A0(void *save)
{
    int n;
    u32 box;

    for (box = 0, n = 0; box < 0x18; box++) {
        n += sub_0200791C(save, box);
    }
    return n;
}
