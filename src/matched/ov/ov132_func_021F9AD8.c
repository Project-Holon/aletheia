/*
 * function: func_021F9AD8
 * address: 0x021F9AD8
 * packet: pkt_ov132_021F9AD8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: The final random choice is a ternary; an if/else shares the earlier action-seven assignment and leaves 36 bytes different.
 * ABI: The matched 0203D378 body returns u32(void); the preceding guard loads r0 without an argument to that call.
 * symbols:
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   func_0203F0A8 0x0203F0A8 arm
 *   func_021F9774 0x021F9774 thumb ov132
 *   _ll_mul 0x0209C054 arm
 *   _ull_mul 0x0209C054 arm
 */
#include "../include/Obj03287.h"
#include "../include/Obj08155.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef enum { ACTION7 = 7, ACTION8 = 8 } Action;
extern u32 GFL_NET_IsParentAid(void);
extern u32 func_0203F0A8(void);
extern int func_021F9774(char *, unsigned);
static inline u32 random_below(u32 n)
{
    u32 draw;
    draw = func_0203F0A8();
    return ((u64)draw * n) >> 32;
}
void func_021F9AD8(char *p, int mode, u8 slot)
{
    u8 i;
    if (**(void ** *)&((struct Obj08155 *)p)->f30 && GFL_NET_IsParentAid() != 1) return;
    for (i = 0; i < 4; i++) {
        int eligible[2] = {0, 0};
        char *record = *(char **)(*(char * *)&((struct Obj08155 *)p)->f30 + i * 4 + 4);
        Action action;
        int value;
        if (((struct Obj03287 *)record)->f0 != 2 || func_021F9774(p, i) == 1 || *(u16 *)(p + i * 2 + 0x124) != 0) continue;
        if (((struct Obj03287 *)record)->f3E != 255 && !*(int *)(p + i * 8 + 0x13C)) eligible[0] = 1;
        if (((struct Obj03287 *)record)->f44 != 255 && !*(int *)(p + i * 8 + 0x140)) eligible[1] = 1;
        if (!eligible[0] && !eligible[1]) continue;
        if (eligible[0] == 1 && eligible[1] == 0) action = ACTION7;
        else if (eligible[1] == 1 && eligible[0] == 0) action = ACTION8;
        else {
            action = (u8)random_below(2) == 0 ? ACTION7 : ACTION8;
        }
        switch (mode) {
        case 1:
            if (((struct Obj03287 *)record)->f78 == 65533 && i == slot) {
                *(u16 *)(p + i * 2 + 0x124) = random_below(30) + 30;
                *(int *)(p + i * 4 + 0x12C) = action;
            }
            break;
        case 2:
            if (((struct Obj03287 *)record)->f78 == 65535 && random_below(100) < 50) {
                *(u16 *)(p + i * 2 + 0x124) = random_below(60) + 60;
                *(int *)(p + i * 4 + 0x12C) = action;
            }
            if (((struct Obj03287 *)record)->f78 == 65534 && random_below(100) < 25) {
                *(u16 *)(p + i * 2 + 0x124) = random_below(60) + 60;
                *(int *)(p + i * 4 + 0x12C) = action;
            }
            break;
        case 0:
            if (((struct Obj03287 *)record)->f78 != 0 && ((struct Obj03287 *)record)->f78 < 65533) {
                value = ((struct Obj03287 *)record)->f78 + (s8)(random_below(121) - 60);
                if (value < 0) *(u16 *)(p + i * 2 + 0x124) = 0;
                else *(u16 *)(p + i * 2 + 0x124) = value;
                *(int *)(p + i * 4 + 0x12C) = action;
            }
            break;
        }
    }
}
