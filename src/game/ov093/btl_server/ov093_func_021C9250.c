/*
 * function: func_021C9250
 * address: 0x021C9250
 * packet: pkt_ov093_021C9250
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: message pointer setup before the second for-loop avoids a duplicate guard (+4 bytes).
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021C9374 0x021C9374 thumb ov093
 *   func_021C9384 0x021C9384 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D5D14 0x021D5D14 thumb ov093
 *   func_021C5A1C 0x021C5A1C thumb ov093
 *   func_021C5A34 0x021C5A34 thumb ov093
 *   func_021C3008 0x021C3008 thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 */
#include "../../../matched/include/Obj00003.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
enum Kind { K0, K1, K10=10 };
typedef struct { u32 low:8,index:5,pad:10,flag:1,high:8; enum Kind kind; u32 value; s8 a; u8 b,c,count; u8 ids[8]; u8 msg[36]; } Ent;
struct Msg;
extern u8 *func_021B9934(char *p, int i);
extern int func_021C9374(void *, u8);
extern int func_021C9384(void *, u8);
extern int func_021D5B68(void *);
extern int func_021D5D14(s8 *p, int i, int sign);
extern void func_021C5A1C(u8 *p, u8 *a);
extern void func_021C5A34(u8 *p, u8 *a);
extern int func_021C3008(u8 *, u8, u8 *, enum Kind, int, u8, u16, u32, int, u32);
extern int func_021C99A0(void *w, const struct Msg *m);
int func_021C9250(u8 *p, const Ent *e, u16 arg)
{
    u8 *a;
    int f;
    int result;
    u32 i;
    u8 *b;
    const u8 *m;
    a = func_021B9934(((struct Obj00003 *)p)->f8, (u8)e->index);
    f = 0;
    result = 0;
    for (i = 0; i < e->count; i++) {
        if (func_021C9374(p + 0x1ab8, e->ids[i])) {
            b = func_021B9934(((struct Obj00003 *)p)->f8, (u8)e->ids[i]);
            if (!func_021D5B68(b)) {
                if (func_021D5D14((s8 *)b, (u32)e->kind, e->a)) {
                    f = 1;
                    break;
                }
            }
        }
    }
    if (f && e->flag) func_021C5A1C(p, a);
    m = (const u8 *)e;
    m += 24;
    for (i = 0; i < e->count; i++) {
        if (func_021C9384(p + 0x1ab8, e->ids[i])) {
            b = func_021B9934(((struct Obj00003 *)p)->f8, (u8)e->ids[i]);
            if (!func_021D5B68(b)) {
                if (func_021C3008(p, e->index, b, e->kind, e->a, 31, arg, e->value, e->c, e->b == 0)) {
                    func_021C99A0(p, (const struct Msg *)m);
                    result = 1;
                }
            }
        }
    }
    if (f && e->flag) func_021C5A34(p, a);
    return result;
}
