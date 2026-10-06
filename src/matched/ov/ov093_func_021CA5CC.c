/*
 * function: func_021CA5CC
 * address: 0x021CA5CC
 * packet: pkt_ov093_021CA5CC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: C7F68 returns its normalized u8 j, and u8 n restores the count reload.
 * symbols:
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021C7F68 0x021C7F68 thumb ov093
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5BDC 0x021D5BDC thumb ov093
 *   func_021C5418 0x021C5418 thumb ov093
 *   func_021D69AC 0x021D69AC thumb ov093
 *   func_0203EFC8 0x0203EFC8 arm
 *   func_021C6F34 0x021C6F34 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021C5620 0x021C5620 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cmd { u32 a:8; u32 id:5; u32 b:19; };
struct Unk021D62A8;
struct UtilWork;
extern int func_021B8D8C(void *p, void *a, u32 b);
extern u8 func_021C7F68(void *, u16, u8 *);
typedef signed int     s32;
struct Slot;
extern u8 *func_021B9934(char *p, int i);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern int func_021C5418(u8 *, u8 *, int);
extern u8 func_021D69AC(u8 *, int);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern int func_021C6F34(u8 *, u8 *, int);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021C5620(u8 *p, u8 *a, int k, struct Slot *out);
extern void func_021CD64C(void *, u8, ...);
int func_021CA5CC(const u8 *p, const struct Cmd *q)
{
    u8 buf[8];
    u8 n;
    u8 i;
    u8 *a;
    int changed;
    u8 t;
    n = func_021C7F68((u8 *)p, func_021B8D8C(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, (u8)q->id) | 0x800, buf);
    i = 0;
    if (i >= n) goto done;
loop:
    {
        a = (u8 *)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, buf[i]);
        changed = 0;
        if (func_021D5BDC((struct UtilWork *)a, 3)) {
            func_021C5418((u8 *)p, a, 3);
            t = func_021D69AC(a, 4);
            if (!(t && (t = (u8)(t - 1)) < 24)) t = 31;
            if (t != 31) func_0203EFC8(p, a, 1);
            changed = 1;
        }
        if (func_021C6F34((u8 *)p, a, 1)) changed = 1;
        if (func_021D62C4((struct Unk021D62A8 *)a, 30)) {
            func_021C5620((u8 *)p, a, 30, 0);
            changed = 1;
        }
        if (func_021D62C4((struct Unk021D62A8 *)a, 32)) {
            func_021C5620((u8 *)p, a, 32, 0);
            changed = 1;
        }
        if (changed) func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x43b, buf[i], 0xffff0000);
    }
    i++;
    if (i < n) goto loop;
done:
    return 1;
}
