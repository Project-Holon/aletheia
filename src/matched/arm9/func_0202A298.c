/*
 * unit:     no
 * function: func_0202A298
 * address:  0x0202A298
 * packet:   pkt_0202A298
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490A8  0x020490A8  arm
 *   func_02048F74  0x02048F74  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204944C  0x0204944C  arm
 *   func_02049238  0x02049238  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32   func_020490A8(u32 a, u32 b);
extern void func_02048F74(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);
extern void *func_020490F4(unsigned int id, unsigned int heap);
struct ArcFile;
extern void func_0204944C(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
extern void  func_02049238(void *h);

u32 func_0202A298(u16 key, u16 want, u32 heap)
{
    u16   rec[4];
    void *h;
    u32   end;
    u32   found = 0;

    end = func_020490A8(0x5a, 0);
    func_02048F74(rec, 0x5b, 0, key * 2, (u32 *)2);
    h = func_020490F4(0x5a, heap);

    while (rec[0] != end) {
        func_0204944C(h, 0, rec[0], 4, &rec[1]);
        if (rec[1] == key && rec[2] == want) {
            found = 1;
            break;
        }
        if (rec[1] != key) {
            break;
        }
        rec[0] = (u16)(rec[0] + 4);
    }

    func_02049238(h);
    return found;
}
