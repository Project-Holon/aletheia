/*
 * function: func_021C8E58
 * address:  0x021C8E58
 * packet:   pkt_ov093_021C8E58
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021C8F14  0x021C8F14  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5C30  0x021D5C30  thumb  ov093
 *   func_021C20BC  0x021C20BC  thumb  ov093
 *   func_021C20D0  0x021C20D0  thumb  ov093
 *   func_021C5A1C  0x021C5A1C  thumb  ov093
 *   func_021C5A34  0x021C5A34  thumb  ov093
 *   func_021C70E4  0x021C70E4  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u8 *func_021B9934(char *p, int i);
extern int func_021C8F14(int a, u8 b);
extern int func_021D5B68(void *p);
struct UtilWork;
extern int func_021D5C30(struct UtilWork *p);
extern int func_021C20BC(u8 *p, u8 *a, int r);
extern int func_021C20D0(u8 *p, u8 *a, int c, u8 *l);
extern void func_021C5A1C(u8 *p, u8 *a);
extern void func_021C5A34(u8 *p, u8 *a);
extern void func_021C70E4(u8 *p, int a, int b, int c, int e, u32 f);

typedef struct {
    u32 pad : 8; u32 idx : 5; u32 mid : 10; u32 fl : 1; u32 top : 8;
    u16 h4; u8 b6; u8 f7a : 1; u8 f7b : 1; u8 f7c : 6; u16 h8; u8 ba; u8 bb;
} Ent;

int func_021C8E58(int p, const Ent *e)
{
    int a;
    u8 *b;
    u32 i;

    if (func_021C8F14(p + 0x1ab8, e->b6)) {
        a = (int)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, e->b6);
        b = 0;
        i = e->idx;
        if (i != 0x1f)
            b = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (u8)i);
        if (func_021D5B68((void *)a) == 0) {
            if (!e->f7a || func_021D5C30((struct UtilWork *)a) == 0) {
                if (func_021C20BC((u8 *)p, (u8 *)a, e->h4)) {
                    if (e->fl)
                        func_021C5A1C((u8 *)p, b);
                    if (e->f7b)
                        func_021C70E4((u8 *)p, e->h8, e->ba, e->bb, 0, 0);
                    func_021C20D0((u8 *)p, (u8 *)a, e->h4, (void *)((u8 *)e + 0xc));
                    if (e->fl)
                        func_021C5A34((u8 *)p, b);
                    return 1;
                }
            }
        }
    }
    return 0;
}
