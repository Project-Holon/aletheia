/*
 * function: func_021B82E8
 * address: 0x021B82E8
 * packet: pkt_ov133_021B82E8
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Named halfword call-result local fixes comparison load order.
 * symbols:
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021BA20C 0x021BA20C thumb ov133
 *   func_021BA148 0x021BA148 thumb ov133
 *   func_021BA124 0x021BA124 thumb ov133
 *   func_021BA22C 0x021BA22C thumb ov133
 *   func_021F4E8C 0x021F4E8C thumb ov112
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 *   func_021BA244 0x021BA244 thumb ov133
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 *   func_021BA228 0x021BA228 thumb ov133
 *   func_021BA21C 0x021BA21C thumb ov133
 *   func_021BA248 0x021BA248 thumb ov133
 *   func_021BA23C 0x021BA23C thumb ov133
 *   func_021BA24C 0x021BA24C thumb ov133
 *   func_021B7A18 0x021B7A18 thumb ov133
 *   func_020061E4 0x020061E4 thumb
 *   d_021BA588 0x021BA588 data a4
 *   d_021BA568 0x021BA568 data a4
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
#include "../include/Obj00004.h"
#include "../include/Obj14149.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x, y, z; } Vec;
typedef struct { int x, y; } Pair;
extern const Vec d_021BA588;
extern const Pair d_021BA568;
extern u8 *func_021BA218(u8 *);
extern u8 *func_021BA20C(u8 *);
typedef signed short   s16;
typedef unsigned int   u32;
extern void func_021BA148(u8 *p, u8 *q);
extern void func_021BA124(u8 *p, u8 *q);
extern void func_021BA22C(u8 *p, const u8 *src);
extern void func_021F4E8C(int, int, Vec *);
extern void func_021F4EB4(u32 unused, u32 p, s16 a, s16 b);
extern void func_021BA244(u8 *p, u32 value);
extern void *func_021BA184(char *p);
extern u8 *func_021BA208(u8 *);
extern u8 *func_021BA228(u8 *p);
extern void func_021BA21C(u8 *p, const u8 *src);
extern int func_021BA248(char *p);
extern void func_021BA23C(u8 *p, u32 value);
extern void func_021BA24C(char *p, u32 v);
extern void func_021B7A18(u8 *);
extern void func_020061E4(u32 a);
void func_021B82E8(u8 *p, int unused)
{
    Vec v;
    Pair pos;
    Pair fallback;
    u8 *sprite, *data, *entry, *found;
    u16 key;
    func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);
    sprite = func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);
    data = func_021BA20C(*(u8 * *)&((struct Obj00004 *)p)->f38);
    func_021BA148(((struct Obj00004 *)p)->f1820, *(u8 * *)&((struct Obj00004 *)p)->f38);
    func_021BA124(((struct Obj00004 *)p)->f1828, *(u8 * *)&((struct Obj00004 *)p)->f38);
    v = d_021BA588;
    pos.x = ((struct Obj00004 *)p)->f1C;
    pos.y = *(int *)&((struct Obj00004 *)p)->f20;
    if (((struct Obj00004 *)p)->f44 > 0) v.x = (int)(0.5f + (float)(((struct Obj00004 *)p)->f44 << 12));
    else v.x = (int)((float)(((struct Obj00004 *)p)->f44 << 12) - 0.5f);
    if (((struct Obj00004 *)p)->f48 > 0) v.y = (int)(0.5f + (float)(((struct Obj00004 *)p)->f48 << 12));
    else v.y = (int)((float)(((struct Obj00004 *)p)->f48 << 12) - 0.5f);
    func_021BA22C(*(u8 * *)&((struct Obj00004 *)p)->f38, (const u8 *)(&pos));
    func_021F4E8C(*(int *)&((struct Obj00004 *)p)->f1884, (int)sprite, &v);
    func_021F4EB4(*(int *)&((struct Obj00004 *)p)->f1884, (int)sprite, 4096, 4096);
    func_021BA244(*(u8 * *)&((struct Obj00004 *)p)->f38, 4096);
    found = 0;
    entry = func_021BA184(((struct Obj00004 *)p)->f181C);
    while (entry && !found) {
        key = *(u16 *)func_021BA20C(entry);
        if (key == ((struct Obj14149 *)data)->f0) found = entry;
        entry = func_021BA208(entry);
    }
    if (found) {
        func_021BA21C(*(u8 * *)&((struct Obj00004 *)p)->f38, (const u8 *)func_021BA228(found));
        func_021BA23C(*(u8 * *)&((struct Obj00004 *)p)->f38, func_021BA248((char *)found));
    } else {
        fallback = d_021BA568;
        func_021BA21C(*(u8 * *)&((struct Obj00004 *)p)->f38, (const u8 *)(&fallback));
        func_021BA23C(*(u8 * *)&((struct Obj00004 *)p)->f38, 0);
    }
    func_021BA24C((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38), 10);
    ((struct Obj14149 *)data)->fC = 0;
    func_021B7A18(p);
    func_020061E4(1574);
}
