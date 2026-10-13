/*
 * unit:     no
 * function: func_0202A310
 * address:  0x0202A310
 * packet:   pkt_0202A298
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   func_020490A8  0x020490A8  arm
 *   func_02048F74  0x02048F74  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204944C  0x0204944C  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02049238  0x02049238  arm
 *   func_02045C04  0x02045C04  arm
 *   STRBUF_Clear  0x0204581C  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct ArcFile;
struct MsgBank;
struct Rec;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32   func_020490A8(u32 a, u32 b);
extern void func_02048F74(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_0204944C(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void  func_02049238(void *h);
extern u32 func_02045C04(struct Rec *rec);
extern void STRBUF_Clear(struct U16Vec *vec);

void func_0202A310(int key, int want, void *dest, u32 heap)
{
    u16   rec[4];
    void *h;
    void *bank;
    u32   end;

    bank = func_02045B38(0, 2, 0xbd, heap);
    end = func_020490A8(0x5a, 0);
    func_02048F74(rec, 0x5b, 0, key * 2, (u32 *)2);
    h = func_020490F4(0x5a, heap);

    while (rec[0] != end) {
        func_0204944C(h, 0, rec[0], 4, &rec[1]);
        if (rec[1] == key && rec[2] == want) {
            func_02045CAC(bank, (u32)rec[0] >> 2, dest);
            break;
        }
        rec[0] = (u16)(rec[0] + 4);
    }

    func_02049238(h);
    func_02045C04(bank);

    if (rec[0] == end) {
        STRBUF_Clear(dest);
    }
}
