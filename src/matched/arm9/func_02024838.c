/*
 * function: func_02024838
 * address:  0x02024838
 * packet:   pkt_02024838
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads one archived message/graphics entry into the caller's buffer.
 * The flat id is split by func_020248D8 into a bank index and an
 * entry index; the bank index selects an archive id out of the
 * halfword table at 0x0209F7AC, that archive is opened, the entry is
 * read into dest and the archive closed again.  The sentinel id
 * 0xffff means "nothing to load" and only clears dest.
 *
 * symbols:
 *   Table_0209F7AC   0x0209F7AC  data
 *   func_020248D8    0x020248D8  thumb
 *   func_0204581C    0x0204581C  arm
 *   func_02045B38    0x02045B38  arm
 *   func_02045C04    0x02045C04  arm
 *   func_02045CAC    0x02045CAC  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 Table_0209F7AC[];

extern int   func_020248D8(u32 id, u32 *bank, u32 *entry);
extern void  func_0204581C(void *dest);
extern void *func_02045B38(int a, int b, u32 id, u32 heap);
extern void  func_02045C04(void *arc);
extern void  func_02045CAC(void *arc, u32 entry, void *dest);

void func_02024838(u32 id, void *dest, u32 heap)
{
    u32 bank;
    u32 entry;

    if (id != 0xffff) {
        void *arc;

        func_020248D8(id, &bank, &entry);
        bank = Table_0209F7AC[bank];
        arc = func_02045B38(0, 2, bank, heap);
        func_02045CAC(arc, entry, dest);
        func_02045C04(arc);
    } else {
        func_0204581C(dest);
    }
}
