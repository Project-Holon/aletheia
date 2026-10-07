/*
 * function: func_021C9010
 * address:  0x021C9010
 * packet:   pkt_ov093_021C9010
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021C0898  0x021C0898  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021C7194  0x021C7194  thumb  ov093
 *   func_021C2128  0x021C2128  thumb  ov093
 */
#include "../../../matched/include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u8 *func_021B9934(char *p, int i);
extern int func_021D5B68(void *p);
struct Msg;
extern int func_021C0898(u8 *p, u8 *a, u32 b, u32 c);
extern int func_021C99A0(void *w, const struct Msg *m);
extern int func_021C7194(u8 *p, u8 *a, u32 v);
extern int func_021C2128(u8 *p, u8 *a);

typedef struct {
    u32 w; u8 b4; u8 b5; u8 b6; u8 f7a : 1; u8 f7b : 1; u8 f7c : 6;
} Ent;

int func_021C9010(int p, const Ent *e)
{
    int a;

    a = (int)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, e->b5);
    if (func_021D5B68((void *)a) == 0 || e->f7b) {
        if (func_021C0898((u8 *)p, (u8 *)a, e->b6, e->b4)) {
            func_021C99A0((void *)p, (void *)((u8 *)e + 8));
            if (func_021C7194((u8 *)p, (u8 *)a, e->b6))
                func_021C2128((u8 *)p, (u8 *)a);
        }
        return 1;
    }
    return 0;
}
