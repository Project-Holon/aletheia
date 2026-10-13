/*
 * function: func_021D49C8
 * address: 0x021D49C8
 * packet: pkt_ov124_021D49C8
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the two-halfword delta is a struct assignment; field stores differ by 13 bytes.
 * symbols:
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02061CA4 0x02061CA4 arm
 *   func_02030734 0x02030734 arm
 *   func_02041090 0x02041090 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B92C 0x0204B92C arm
 *   CLACT_SetActorAnimIndex 0x0204B908 arm
 *   d_021D4CF4 0x021D4CF4 data a4
 *   d_021D4CA4 0x021D4CA4 data a4
 *   d_021D4D4C 0x021D4D4C data a1
 *   d_021D4C04 0x021D4C04 data a4
 *   d_021D4BE0 0x021D4BE0 data a2
 */
#include "../include/Obj00122.h"
#include "../include/Obj22993.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef struct { s16 x, y; } Vec;
extern const u32 d_021D4CF4[], d_021D4CA4[], d_021D4C04[];
extern const char d_021D4D4C[];
extern const Vec d_021D4BE0;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern int func_02061CA4(void *, u32, u32, int);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02041090(u32, u32, u32, u32, u8, u8);
extern u32 func_020307B0(void *p);
extern void func_020409B4(u32);
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimIndex(int a0, int a1);
void func_021D49C8(char *p, u32 n)
{
    u16 *q;
    u8 i, j;
    Vec delta;
    CLACT_SetActorAnimSeq(((struct Obj00122 *)p)->f5C, d_021D4CF4[n]);
    func_0204B3DC(((struct Obj00122 *)p)->f5C, 1);
    if (n <= 7) {
        func_02061CA4((void *)31, 320, (u32)(*(char * *)&((struct Obj22993 *)(*(char * *)&((struct Obj00122 *)p)->f48))->fC + d_021D4CA4[n] * 32), 32);
        q = func_02030734(((struct Obj00122 *)p)->f0, 32, 1, d_021D4D4C, 0x2ac);
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                q[i * 4 + j] = j + d_021D4C04[n] + i * 32 + 0xa000;
            }
        }
        func_02041090(4, (u32)q, 2, 4, 4, 4);
        func_020307B0(q);
    } else {
        q = func_02030734(((struct Obj00122 *)p)->f0, 32, 1, d_021D4D4C, 0x2bb);
        func_02041090(4, (u32)q, 2, 4, 4, 4);
        func_020307B0(q);
    }
    func_020409B4(4);
    delta = d_021D4BE0;
    func_0204B404(((struct Obj00122 *)p)->f5C, (const struct Vec2 *)(&delta), 1);
    if (n == 10) {
        func_0204B92C(((struct Obj00122 *)p)->f5C, 0);
        CLACT_SetActorAnimIndex((int)(((struct Obj00122 *)p)->f5C), 1);
    } else if (n == 11) {
        func_0204B92C(((struct Obj00122 *)p)->f5C, 0);
        CLACT_SetActorAnimIndex((int)(((struct Obj00122 *)p)->f5C), 0);
    } else {
        func_0204B92C(((struct Obj00122 *)p)->f5C, 1);
    }
}
