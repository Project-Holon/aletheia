/*
 * function: func_021C94C8
 * address: 0x021C94C8
 * packet: pkt_ov093_021C94C8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C95C0 0x021C95C0 thumb ov093
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5970 0x021D5970 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 w; u16 values[5]; u8 id; u8 f0:1,f1:1,f2:1,f3:1,f4:1,pad:3; u8 msg[36]; } Ent;
extern int func_021C95C0(void *, u8);
extern u8 *func_021B9934(char *p, int i);
extern void func_021D5970(u8 *, int, u16);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021C99A0(void *, const void *);
int func_021C94C8(u8 *p, const Ent *e)
{
    u8 *a;
    if (func_021C95C0(p + 0x1ab8, e->id)) {
        a = func_021B9934(((struct Obj00003 *)p)->f8, e->id);
        if (e->f0) { func_021D5970(a, 8, e->values[0]); func_021CD4B0(((struct Obj00003 *)p)->fC, 19, e->id, 8, (u8)e->values[0]); }
        if (e->f1) { func_021D5970(a, 9, e->values[1]); func_021CD4B0(((struct Obj00003 *)p)->fC, 19, e->id, 9, (u8)e->values[1]); }
        if (e->f2) { func_021D5970(a, 10, e->values[2]); func_021CD4B0(((struct Obj00003 *)p)->fC, 19, e->id, 10, (u8)e->values[2]); }
        if (e->f3) { func_021D5970(a, 11, e->values[3]); func_021CD4B0(((struct Obj00003 *)p)->fC, 19, e->id, 11, (u8)e->values[3]); }
        if (e->f4) { func_021D5970(a, 12, e->values[4]); func_021CD4B0(((struct Obj00003 *)p)->fC, 19, e->id, 12, (u8)e->values[4]); }
        func_021C99A0(p, e->msg);
        return 1;
    }
    return 0;
}
