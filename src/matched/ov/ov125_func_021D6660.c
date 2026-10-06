/*
 * function: func_021D6660
 * address: 0x021D6660
 * packet: pkt_ov125_021D6660
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021D8600 0x021D8600 arm ov125
 *   func_02030734 0x02030734 arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_021D8598 0x021D8598 arm ov125
 *   func_02034714 0x02034714 arm
 *   ov114_id 0x00000072 data
 *   d_021D8D00 0x021D8D00 data a4
 *   d_021D8D0C 0x021D8D0C data a4
 *   d_021D8D28 0x021D8D28 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 w[7]; } Blk;
typedef signed int     s32;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern int func_02034AC4(s32 handle);
extern void func_02082BCC(void *, int, u32);
extern int func_021D8600(int);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern int func_021D8598(void *, const char *, int);
extern void func_02034714(const char *, u32, const char *);
extern char ov114_id[];
extern const char d_021D8D00[];
extern const char d_021D8D0C[];
extern char d_021D8D28[];

int func_021D6660(char *p, char *a)
{
    func_02034AC4((int)ov114_id);
    func_02082BCC(p, 0, 0x5A4);
    *(u32 *)(p + 0x13C) = *(u16 *)(a + 4);
    *(u32 *)p = *(u32 *)(a + 8);
    *(u32 *)(p + 0x494) = *(u32 *)(a + 0xC);
    *(Blk *)(p + 0x148) = *(Blk *)(a + 0x10);
    *(int *)(p + 0x144) = -1;
    *(u32 *)(p + 0x3D8) = 0x55F4;
    *(u32 *)(p + 0x3DC) = 0x55F4;
    *(void **)(p + 0x3AC) = func_02030734(*(u16 *)(a + 4), func_021D8600(-1), 0, d_021D8D00, 0x84);
    func_02082BCC(*(void **)(p + 0x3AC), 0, func_021D8600(-1));
    *(int *)(p + 0x3E4) = (int)func_02045B38(0, 2, 0xE8, *(u16 *)(a + 4));
    *(int *)(p + 0x3E8) = (int)func_0201EC64(*(u16 *)(a + 4));
    *(int *)(p + 0x3EC) = (int)func_020457B0(0x100, *(u16 *)(a + 4));
    *(u32 *)(p + 4) = *(u32 *)a;
    p[8] = 0x15;
    p[9] = 2;
    if (func_021D8598(p + 4, d_021D8D0C, 0x3071) != 1)
        func_02034714(d_021D8D28, 0, d_021D8D28);
    *(u32 *)(p + 0x3B4) = 1;
    *(u32 *)(p + 0x3B0) = 1;
    return 1;
}
