/*
 * function: func_021D4A20
 * address: 0x021D4A20
 * packet: pkt_ov120_021D4A20
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: score declared before id gives score r4 and id r5; reverse gives 23-byte DIFF.
 * symbols:
 *   func_0216CB30 0x0216CB30 arm ov009
 *   func_02009EC8 0x02009EC8 thumb
 *   func_02009E74 0x02009E74 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   func_02008530 0x02008530 thumb
 */
#include "../include/Obj10386.h"
#include "../include/Obj22828.h"
typedef unsigned char u8;
extern int func_0216CB30(int, int, int);
extern void *func_02009EC8(void *);
typedef unsigned int   u32;
struct Sub02009D9CObj;
extern u32 func_02009E74(struct Sub02009D9CObj *obj, u32 id);
struct Sub0200852CObj;
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
#define I(k) (*(int *)(p + (k)))
int func_021D4A20(int a, u8 *p)
{
    int mode;
    int x;
    int y;
    int score = -1;
    int id;
    int group;
    int i;
    u8 *q = *(u8 * *)&((struct Obj10386 *)p)->f48;
    mode = func_0216CB30(a, (int)(p + 0x76), -1);
    x = func_0216CB30(a, (int)(p + 0x8e), -1);
    y = func_0216CB30(a, (int)(p + 0x82), -1);
    id = func_0216CB30(a, (int)(p + 0x5e), 0);
    group = func_0216CB30(a, (int)(p + 0xb2), 0);
    if (I(0x138) == 1) {
        if (mode == 4) {
            if (I(0x148) == -1) {
                if (func_02009E74(func_02009EC8(((struct Obj10386 *)p)->f30), id) != 0)
                    score = 100;
            } else {
                if (I(0x18) == id) score = 100;
            }
        } else {
            if (group == func_02008530((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus((void *)(((struct Obj22828 *)q)->f0)))) {
                if (I(0x148) == -1) {
                    if (func_02009E74(func_02009EC8(((struct Obj10386 *)p)->f30), id) != 0)
                        score = 100;
                } else {
                    if (I(0x18) == id) score = 100;
                }
            }
        }
    } else {
        if (I(0x144) == mode) {
            if (I(0x13c) == x) score += 20;
            else if (I(0x13c) == 0 || x == 0) score += 10;
            else score -= 40;
            if (I(0x140) == y) score += 20;
            else if (y == 0 || I(0x140) == 0) score += 10;
            else score -= 40;
            for (i = 0; i < 100; i++) {
                if (id == *(int *)(q + i * 4 + 0x1c) && id != 0) {
                    score = 0;
                    break;
                }
            }
        }
    }
    return score;
}
