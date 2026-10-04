/*
 * function: func_021C8DE4
 * address:  0x021C8DE4
 * packet:   pkt_ov093_021C8DE4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021C8E48  0x021C8E48  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021C1E14  0x021C1E14  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u8 *func_021B9934(char *p, int i);
extern int func_021C8E48(int a, u8 b);
extern int func_021D5B68(void *p);
struct Msg;
extern int func_021C1E14(u8 *p, u8 *q, u32 a, u32 b);
extern int func_021C99A0(void *w, const struct Msg *m);

typedef struct {
    u32 w; u16 h4; u8 b6; u8 b7; u16 h8; u16 ha;
} Ent;

int func_021C8DE4(int p, const Ent *e)
{
    int s = 0;
    int t;

    if (e->b7 != 0x1f)
        s = (int)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, e->b7);
    if (func_021C8E48(p + 0x1ab8, e->b6)) {
        t = (int)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, e->b6);
        if (func_021D5B68((void *)t) == 0 && func_021C1E14((u8 *)p, (u8 *)t, s, e->h4)) {
            if ((u8)e->ha)
                func_021C99A0((void *)p, (void *)&e->h8);
            return 1;
        }
    }
    return 0;
}
