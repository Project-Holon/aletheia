/*
 * function: func_021B3A64
 * address:  0x021B3A64
 * packet:   pkt_ov021_021B3A64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B3A64 0x021B3A64 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02186670 0x02186670 thumb ov020
 *   func_0201F81C 0x0201F81C thumb
 *   func_021B385C 0x021B385C thumb ov021
 *   func_0201F878 0x0201F878 thumb
 *   func_02045C04 0x02045C04 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
struct MsgBank;
struct Rec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02186670(void *, void *, void *, int, int);
extern void *func_0201F81C(int, int);
extern void func_021B385C(void *, int, int, int, void *);
extern void func_0201F878(void *, void *, int, int, int);
extern void func_02045C04(struct Rec *rec);

void func_021B3A64(char *p, int i)
{
    int k = 0;
    void *q = func_02045B38(0, 2, 54, *(u16 *)(p + 4));

    func_02186670(*(void **)(p + 28), p + 32, p + 352, i - 247, *(u16 *)(p + 4));
    *(void **)(p + 384) = func_0201F81C(*(u16 *)(p + 352) + 1, *(u16 *)(p + 4));
    for (; k < *(u16 *)(p + 352); k++) {
        func_021B385C(p, k, *(u8 *)(p + 354), *(u16 *)(p + 32 + k * 8), q);
    }
    func_0201F878(*(char **)(p + 384) + k * 8, *(void **)(p + 392), 11, -2, *(u16 *)(p + 4));
    func_02045C04(q);
}
