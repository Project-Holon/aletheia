/*
 * function: func_021C493C
 * address: 0x021C493C
 * packet: pkt_ov093_021C493C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the first out-value is a one-word struct passed by value.
 * symbols:
 *  func_021C4A24 0x021C4A24 thumb ov093
 *  func_021C4A34 0x021C4A34 thumb ov093
 *  func_021C4A44 0x021C4A44 thumb ov093
 *  func_021C4A54 0x021C4A54 thumb ov093
 *  func_021D5440 0x021D5440 thumb ov093
 *  func_021B9934 0x021B9934 thumb ov093
 *  func_021D5B68 0x021D5B68 thumb ov093
 *  func_021D6064 0x021D6064 thumb ov093
 *  func_021CC8D8 0x021CC8D8 thumb ov093
 *  func_021CC95C 0x021CC95C thumb ov093
 *  func_021BC2B0 0x021BC2B0 thumb ov093
 *  func_021D806C 0x021D806C thumb ov093
 *  func_021CD4B0 0x021CD4B0 thumb ov093
 *  func_021C5200 0x021C5200 thumb ov093
 */
#include "../../../matched/include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 value; } Word;
extern u32 func_021C4A24(u8 *);
extern u8 *func_021C4A34(u8 *, u32);
extern u8 *func_021C4A44(u32);
extern void func_021C4A54(u8 *, u8 *, Word, u32, u8 *);
extern u8 func_021D5440(u8 *p);
extern u8 *func_021B9934(char *, int);
extern int func_021D5B68(void *p);
union Slot;
extern int func_021D6064(u8 *p, u32 k, union Slot *out, int *changed);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern int func_021BC2B0(u8 *);
extern u32 func_021D806C(const u8 *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021C5200(u8 *p);
int func_021C493C(u8 *p, u8 *a)
{
    u8 list[6];
    Word y;
    u32 x;
    u32 i, n, k, s;
    u8 *q, *m;
    list[0] = 0;
    list[1] = 0;
    list[2] = 0;
    list[3] = 0;
    list[4] = 3;
    list[5] = 0;
    i = 0;
    n = func_021C4A24(a);
    for (; i < n; i++) list[i] = func_021D5440(func_021C4A34(a, i));
    k = 0;
    for (;;) {
        q = func_021C4A44(k++);
        if (q == 0) break;
        for (i = 0; i < n; i++) {
            m = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, list[i]);
            if (func_021D5B68(m) == 0) {
                if (func_021D6064(m, (u32)q, (union Slot *)(&y), (int *)(&x))) {
                    s = func_021CC8D8(p + 0x1d74, 9719);
                    func_021C4A54(m, q, y, x, p);
                    func_021CC95C((u32 *)(p + 0x1d74), s, 9721);
                }
            }
        }
        if (func_021BC2B0(p)) break;
    }
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x15, (u8)n, (u8)k, func_021D806C(list));
    return func_021C5200(p);
}
