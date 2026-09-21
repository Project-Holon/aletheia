/*
 * function: func_02039658
 * address:  0x02039658
 * packet:   pkt_02039658
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203A28C  0x0203A28C  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02037BE8  0x02037BE8  arm
 *
 * Reset one slot entry while KEEPING its eight resource pointers.  The eight
 * pointers at +8 are stashed on the stack, each live one's 0x10-byte record
 * is zeroed in place, the entry's own object at +0 is released, the whole
 * 0x50-byte entry is wiped, and the eight pointers are written straight back
 * -- so the resource objects survive the reset and only the entry's state
 * does not.  A real slot index (anything but the 0xFF own-slot spelling)
 * first has its bit cleared out of the +0x40 mask through func_0203A28C and
 * its +0x3E companion zeroed.  func_02039834 and func_020398B4 both drive
 * this in a loop over the nine slots.
 *
 * THE STACK BUFFER HOLDS NINE POINTERS, NOT EIGHT, AND ONLY EIGHT ARE USED.
 * Declared `void *saved[8]` the function is byte-identical but for its frame:
 * `sub sp, sp, #0x20` with r3 in the push, against the image's
 * `sub sp, sp, #0x24` with a seven-register push.  The ninth word is what
 * takes the frame to 0x24 and lets the prologue drop the r3 home slot; the
 * unused slot is not padding the compiler inserted but a declared one.  Nine
 * is also the family's own table size (sub_0203996C resolves nine 0x50-byte
 * entries, eight peers plus the own slot), so the buffer was almost
 * certainly spelled with the same manifest constant as the table and the
 * loop simply stops at the eight peers.  tools/permuter.py exhausted hill
 * mode (206 single mutations, none better) on the eight-element version:
 * the array's own size is outside its mutation set.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039658.c \
 *       --func func_02039658 --addr 0x02039658 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 func_0203A28C(u16 mask, u32 idx, u32 set);
extern void func_020307B0(void *p);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void func_02037BE8(u32 idx);

struct Entry {
    void *obj;
    u8    pad_04[4];
    void *slot[8];
    u8    pad_28[0x16];
    u16   key3e;
    u16   key40;
};

void func_02039658(struct Entry *e, u32 idx)
{
    void *saved[9];
    int i;

    if (idx != 0xff) {
        u16 h = e->key40;
        e->key3e = 0;
        e->key40 = func_0203A28C(h, idx, 0);
    }

    for (i = 0; i < 8; i++) {
        if (e->slot[i] != 0)
            func_02082BCC(e->slot[i], 0, 0x10);
        saved[i] = e->slot[i];
    }

    if (e->obj != 0) {
        func_020307B0(e->obj);
        e->obj = 0;
    }

    func_02082BCC(e, 0, 0x50);

    for (i = 0; i < 8; i++)
        e->slot[i] = saved[i];

    func_02037BE8(idx);
}
