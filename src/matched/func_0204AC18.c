/*
 * function: func_0204AC18
 * address:  0x0204AC18
 * packet:   pkt_0204AC18
 * status:   EXACT
 * symbols:
 *   lbl_02146A74  0x02146A74 data
 *   func_02049250 0x02049250 arm
 *   func_0204DD08 0x0204DD08 arm
 *   func_020307B0 0x020307B0 arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct Record_0204AC18 {
    char pad_00[0x14];
    u32 flags;
};

struct Struct_0204AC18 {
    char pad_00[0x10C];
    struct Record_0204AC18 *records;
    u16 unk110;
    u16 count;
};

extern struct Struct_0204AC18 *lbl_02146A74;

extern void *func_02049250(u32 a6);
extern void  func_0204DD08(void *p, int r4, void *res, int a2, int a3, u16 a4, u16 a5);
extern void  func_020307B0(void *res);

int func_0204AC18(int a0, int a1, int a2, int a3, u16 a4, u16 a5, u16 a6)
{
    struct Struct_0204AC18 *p = lbl_02146A74;
    u16 count = p->count;
    int i = 0;
    void *res;
    u32 flags;

    if (count <= 0) {
        return -1;
    }

    while (i < count) {
        flags = p->records[i].flags;
        if ((flags & 0x80000000) == 0) {
            break;
        }
        i++;
        count = p->count;
    }

    if (i >= count) {
        return -1;
    }

    flags = (u32)(a6 | 0x8000) & 0xFFFF;
    res = func_02049250(flags);

    func_0204DD08((u8 *)lbl_02146A74 + 0x104, i, res, a2, a3, a4, a5);
    func_020307B0(res);

    return i;
}
