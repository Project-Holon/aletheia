/*
 * function: func_021F6CE0
 * address: 0x021F6CE0
 * packet: pkt_ov112_021F6CE0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F9E04 0x021F9E04 thumb ov132
 *   func_021F9E18 0x021F9E18 thumb ov132
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   _fflt 0x0209BDBC arm
 *   _ffltu 0x0209BE04 arm
 *   _fdiv 0x0209CE10 arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
#include "../include/Obj00771.h"
#include "../include/Obj05317.h"
typedef unsigned short u16;
typedef struct { short x, y; } Point;
typedef unsigned char  u8;
extern u16 func_021F9E04(u8 *p);
extern int func_021F9E18(char *p);
extern void func_0204B404(int, Point *, int);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
void func_021F6CE0(char *p, char *q) {
    u16 n;
    int tmp;
    Point point;
    if (*(int *)&((struct Obj00771 *)p)->f4 == 0) tmp = 0x80;
    else tmp = func_021F9E04((u8 *)(*(int *)&((struct Obj00771 *)p)->f4));
    n = tmp;
    if (((struct Obj05317 *)q)->f0 == 1) {
        point.x = (short)((float)((struct Obj05317 *)q)->f8 / 4096.0f - (float)(unsigned)n);
        point.y = (short)((float)((struct Obj05317 *)q)->fC / 4096.0f);
        func_0204B404(((struct Obj05317 *)q)->f1C, &point, 0);
        if (*(int *)&((struct Obj00771 *)p)->f4 != 0 && func_021F9E18((char *)(*(int *)&((struct Obj00771 *)p)->f4)) != 4) {
            func_0204B3DC((struct Obj *)((struct Obj05317 *)q)->f1C, 0);
            return;
        }
        func_0204B3DC((struct Obj *)((struct Obj05317 *)q)->f1C, 1);
    }
}
