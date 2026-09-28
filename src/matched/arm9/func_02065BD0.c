/*
 * function: func_02065BD0
 * address:  0x02065BD0
 * packet:   pkt_02064B68
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Resets the cell-actor manager g_02147B88: attaches the object, clears the
 * matrix slot, writes the 0xFFFE sentinel to g_020A81F8, fills the 0x10-byte
 * tail of every live 0x20-byte record at g_02148318 with -1, zeroes the
 * count pair, clears the 0x100-byte slot table g_02147C18, writes the GX
 * MTX_PUSH / MTX_IDENTITY command registers (0x04000444 / 0x04000454, plain
 * hardware addresses, no relocation) and rebuilds the slot-0 matrices via
 * func_02064E3C.  The body is the one docs/notes/func_02065BD0.c.txt
 * recorded at 144/168; the loop shape (guarded do-while, cursor p) is
 * that note's.
 *
 * What closed it:
 *   - Compiler pin ../2.0/sp2.  The note's whole 24-byte residue was the
 *     tail zero: 1.1p1 keeps it in r4 across the fill call, the image
 *     rematerialises it (`mov r0, #0` before, `mov r1, #0` after) -- the
 *     "kept constants" tell.  The note probed the pin before the head was
 *     right and read it as worse; with the head below the pin is EXACT.
 *   - Head order: the 0xFFFE store is volatile AND the loop guard's count
 *     read is volatile, which keeps the count load below the sentinel store
 *     (the image's ldr / ldr / str / strh / ldrh order).  Either alone is
 *     21 bytes out.
 *
 * symbols:
 *   g_02147B88     0x02147B88  data  a4
 *   g_02148318     0x02148318  data  a4
 *   g_02147C18     0x02147C18  data  a4
 *   g_020A81F8     0x020A81F8  data  a2
 *   func_02082AC0  0x02082AC0  arm
 *   func_02064E3C  0x02064E3C  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Bank {
    u16   count;    /* 0x00 */
    u16   unk_02;   /* 0x02 */
    u32   unk_04;
    void *obj;      /* 0x08 */
    u32   unk_0c;   /* 0x0c */
};

struct Ent { u8 pad_00[0x10]; u8 unk_10[0x10]; };

extern struct Bank g_02147B88;
extern struct Ent  g_02148318[];
extern u8          g_02147C18[];
extern u16 g_020A81F8;
extern void func_02082AC0(u32 value, void *dst, u32 size);
extern void func_02064E3C(void);

void func_02065BD0(void *obj)
{
    struct Ent *p;
    s32 i;

    g_02147B88.obj = obj;
    g_02147B88.unk_0c = 0;
    *(volatile u16 *)&g_020A81F8 = 0xfffe;

    i = 0;
    if (i < ((volatile struct Bank *)&g_02147B88)->count) {
        p = g_02148318;
        do {
            func_02082AC0((u32)-1, p->unk_10, 0x10);
            i++;
            p++;
        } while (i < g_02147B88.count);
    }

    g_02147B88.count = 0;
    g_02147B88.unk_02 = 0;
    func_02082AC0(0, g_02147C18, 0x100);

    *(volatile u32 *)0x04000444 = 0;
    *(volatile u32 *)0x04000454 = 0;
    func_02064E3C();
}
