/*
 * function: func_021E0468
 * address:  0x021E0468
 * packet:   pkt_ov093_021E0468
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5448  0x021D5448  thumb  ov093
 *   func_021D54C0  0x021D54C0  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_0201C1C8  0x0201C1C8  thumb
 *   func_021D5814  0x021D5814  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021E8CF0  0x021E8CF0  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../../../matched/include/Obj13503.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D775C(int key);
struct QG;
struct QQ;
extern void *func_021C7CF4(int *p, int i);
extern u8 func_021D5448(struct QG *p);
extern u16 func_021D54C0(u8 *p, int i);
extern u16 func_021D70A8(struct QQ *p);
extern u8 func_0201C1C8(void *p);
extern int func_021D5814(void *q, int k);
extern void *func_021C88A4(char *p, int a, int b);
extern u32 func_021D78AC(u32 range);
extern int func_021E8CF0(int a);
extern void func_021C88C8(void *a, void *b);

void func_021E0468(void *a, void *b, int c)
{
    u8 buf[4];
    void *q;
    u32 n;
    u16 i;
    u16 cnt;
    u32 v;
    char *p;

    if (c == func_021D775C(3)) {
        q = func_021C7CF4(b, c);
        n = func_021D5448(q);
        i = 0;
        cnt = 0;
        for (; i < n; i++) {
            v = func_021D54C0(q, (u8)i);
            if (v != func_021D70A8(a)) {
                v = func_0201C1C8((void *)v);
                if (func_021D5814(q, v) == 0) {
                    buf[cnt++] = v;
                }
            }
        }
        if (cnt != 0) {
            p = func_021C88A4(b, 0x14, c);
            ((struct Obj13503 *)p)->f4 = func_021E8CF0(buf[(u16)func_021D78AC(cnt)]);
            ((struct Obj13503 *)p)->f6 = c;
            func_021C88C8(b, p);
        }
    }
}
