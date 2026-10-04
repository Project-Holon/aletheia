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
typedef unsigned short u16;
typedef struct { short x, y; } Point;
extern int func_021F9E04(int);
extern int func_021F9E18(int);
extern void func_0204B404(int, Point *, int);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
void func_021F6CE0(char *p, char *q) {
    u16 n;
    int tmp;
    Point point;
    if (*(int *)(p + 4) == 0) tmp = 0x80;
    else tmp = func_021F9E04(*(int *)(p + 4));
    n = tmp;
    if (*(int *)q == 1) {
        point.x = (short)((float)*(int *)(q + 8) / 4096.0f - (float)(unsigned)n);
        point.y = (short)((float)*(int *)(q + 0xc) / 4096.0f);
        func_0204B404(*(int *)(q + 0x1c), &point, 0);
        if (*(int *)(p + 4) != 0 && func_021F9E18(*(int *)(p + 4)) != 4) {
            func_0204B3DC((struct Obj *)*(int *)(q + 0x1c), 0);
            return;
        }
        func_0204B3DC((struct Obj *)*(int *)(q + 0x1c), 1);
    }
}
