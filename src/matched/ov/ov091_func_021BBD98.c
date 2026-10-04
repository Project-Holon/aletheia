/*
 * function: func_021BBD98
 * address:  0x021BBD98
 * packet:   pkt_ov091_021BBD98
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045C04  0x02045C04  arm
 *   d_021BEC8C     0x021BEC8C  data  ov091  a4
 */

typedef unsigned short u16;

extern unsigned int func_02017E1C(void *, unsigned int, unsigned int);
typedef unsigned int   u32;
struct MsgBank;
struct Rec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045C04(struct Rec *rec);
extern int d_021BEC8C[];

int func_021BBD98(int a, int unused, int idx)
{
    int r;
    int h;
    if (idx >= 0x10 && idx <= 0x13) {
        r = func_02017E1C((void *)*(int *)(a + 0x38), idx + 0x26, 0);
        h = (int)func_02045B38(0, 2, 0xcb, *(u16 *)a);
        r = (int)func_02045EC0((struct MsgBank *)h, r);
        func_02045C04((struct Rec *)h);
    } else {
        r = (int)func_02045EC0((struct MsgBank *)(*(int *)(a + 0x134)), d_021BEC8C[idx]);
    }
    return r;
}
