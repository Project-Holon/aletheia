/*
 * function: func_021C8C04
 * address: 0x021C8C04
 * packet: pkt_ov128_021C8C04
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034A5C 0x02034A5C arm
 *   func_02034AC4 0x02034AC4 arm
 *   PROCSYS_Create 0x02031324 arm
 *   PROCSYS_Main 0x02031330 arm
 *   func_0203133C 0x0203133C arm
 *   PROCSYS_Push 0x02031348 arm
 *   func_020355C4 0x020355C4 arm
 *   func_021C8DA0 0x021C8DA0 thumb ov128
 *   func_021C6390 0x021C6390 thumb ov128
 *   func_021C6360 0x021C6360 thumb ov128
 *   func_021C6438 0x021C6438 thumb ov128
 *   func_021C6440 0x021C6440 thumb ov128
 *   NAMEIN_SETUP_FreeArgs 0x0216C0C0 thumb ov010
 *   id67 0x00000043 data
 *   id194 0x000000C2 data
 *   id129 0x00000081 data
 *   d_021F5580 0x021F5580 data ov194 a4
 *   d_021DA62C 0x021DA62C data ov129 a4
 *   CODEIN_PARAM_Create  0x0202E4EC  thumb  arm9
 * interface: 02031324 forwards heap to 02031354 and returns its node;
 * 02031348 forwards all four inputs to 020314F4 despite legacy void(void).
 * data: Process setup loads ov194/ov129 and receives their callback tables.
 */
#include "../include/Obj23097.h"
#include "../include/Obj23098.h"
#include "../include/Obj23099.h"
#include "../include/Obj23100.h"
#include "../include/Obj23101.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int     s32;
struct Obj0202E54C;
struct Param;
struct S020314B8;
extern void func_02034A5C(s32 handle);
extern int func_02034AC4(s32 handle);
extern void *PROCSYS_Create(int);
extern u32 PROCSYS_Main(void *);
extern void func_0203133C(struct S020314B8 *p);
extern void PROCSYS_Push(void *, u32, void *, void *);
extern u8 func_020355C4(void);
extern char *func_021C8DA0(void *unused, char *q, int mode, int heap);
extern struct Param *CODEIN_PARAM_Create(u32 heap, u32 a1, u32 a2, u32 a3, u32 *src);
extern void func_0202E54C(struct Obj0202E54C *p);
extern void func_021C6390(u8 *);
extern void func_021C6360(char *p, int heap);
extern void func_021C6438(u8 *p, u8 a, u8 b);
extern void func_021C6440(u8 *p, void *a, void *b);
extern int NAMEIN_SETUP_FreeArgs(int a0);
extern char id67[], id194[], id129[];
extern char d_021F5580[], d_021DA62C[];
int func_021C8C04(void **p, u8 *a, u8 *b, void *unused, int heap)
{
    u32 sizes[3];
    switch (b[8]) {
    case 0:
        func_02034A5C((u32)id67);
        p[1] = func_021C8DA0(p, (char *)b, 1, heap);
        sizes[0] = 4; sizes[1] = 4; sizes[2] = 4;
        p[2] = CODEIN_PARAM_Create(heap, 0, 0, 12, sizes);
        func_021C6390(a);
        p[0] = PROCSYS_Create(heap);
        PROCSYS_Push(p[0], (u32)id194, d_021F5580, p[1]);
        b[8] = 1;
        break;
    case 1:
        if (PROCSYS_Main(p[0]) == 0) {
            if (((struct Obj23097 *)((u8 *)p[1]))->f1C == 0) {
                PROCSYS_Push(p[0], (u32)id129, d_021DA62C, p[2]);
                b[8] = 2;
            } else {
                func_0203133C(p[0]);
                func_021C6438(b, 0, 0);
                b[8] = 3;
            }
        }
        break;
    case 2:
        if (PROCSYS_Main(p[0]) == 0) {
            func_0203133C(p[0]);
            func_021C6440(b, ((struct Obj23098 *)((u8 *)p[1]))->f20, ((struct Obj23099 *)((u8 *)p[2]))->f20);
            func_021C6438(b, 0, 7);
            b[8] = 3;
        }
        break;
    case 3:
        NAMEIN_SETUP_FreeArgs((int)p[1]);
        func_0202E54C(p[2]);
        func_02034AC4((u32)id67);
        func_021C6360((char *)a, heap);
        return 1;
    case 4:
        func_02034A5C((u32)id67);
        p[1] = func_021C8DA0(p, (char *)b, 0, heap);
        func_021C6390(a);
        p[0] = PROCSYS_Create(heap);
        PROCSYS_Push(p[0], (u32)id194, d_021F5580, p[1]);
        b[8] = 5;
        break;
    case 5:
        if (PROCSYS_Main(p[0]) == 0) {
            func_0203133C(p[0]);
            *(int *)b = func_020355C4();
            if (((struct Obj23100 *)((u8 *)p[1]))->f1C == 0) {
                func_021C6438(b, 1, 14);
                func_021C6440(b, ((struct Obj23101 *)((u8 *)p[1]))->f20, 0);
                b[8] = 6;
            } else {
                func_021C6438(b, 1, 15);
                b[8] = 6;
            }
        }
        break;
    case 6:
        NAMEIN_SETUP_FreeArgs((int)p[1]);
        func_02034AC4((u32)id67);
        func_021C6360((char *)a, heap);
        return 1;
    }
    return 0;
}
