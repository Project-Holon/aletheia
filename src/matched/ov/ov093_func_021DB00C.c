/*
 * unit: yes
 * function: func_021DB00C, func_021DB0D0
 * address: 0x021DB00C
 * packet: pkt_ov093_021DB00C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7D00 0x021C7D00 thumb ov093
 *   func_021C7F68 0x021C7F68 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021C88B4 0x021C88B4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021D7B74 0x021D7B74 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F07E8 0x021F07E8 data a4
 * The unit includes the store-return follower; labelled 021DB0DC is excluded.
 * An 8-bit candidate count keeps its immediate spill/reload; m precedes n
 * in the declaration list to place those spills at +8 and +4 respectively.
 */
#include "../include/Obj13471.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D775C(int key);
extern int func_021C7D00(u8 *p, int b);
extern u8 func_021C7F68(int *p, int b, u8 *out);
struct Unk021D62A8;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021C88B4(void *a, int k, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern int func_021D7B74(u8 *p, u32 k);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);
void func_021DB00C(int a, void *b, int c)
{
    u8 list[4];
    void *m;
    u8 n;
    int flag;
    u8 *r;
    u8 i;
    if (c == func_021D775C(2)) {
        flag = 0;
        n = func_021C7F68(b, (u16)(func_021C7D00(b, c) | 0x100), list);
        for (i = 0; i < n; i++) {
            m = func_021C7CF4(b, list[i]);
            if (func_021D62C4(m, 2)) {
                if (!flag) {
                    flag = 1;
                    func_021C88B4(b, 2, c);
                }
                r = (u8 *)func_021C88A4(b, 7, c);
                r[6] = list[i];
                ((struct Obj13471 *)r)->f4 = func_021D7B74(m, 8);
                func_021C8838(r + 12, 2, 0x1e4);
                func_021C8860((struct S *)(r + 12), list[i]);
                func_021C88C8(b, r);
            }
        }
        if (flag) func_021C88B4(b, 3, c);
    }
}
extern u8 d_021F07E8[];
void *func_021DB0D0(int *p) { *p = 1; return d_021F07E8; }
