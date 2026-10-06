/*
 * function: func_021EDCA8
 * address: 0x021EDCA8
 * packet: pkt_ov093_021EDCA8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021EDDC6 rereads flags after setting bit 0.
 * symbols:
 *   func_02040B1C 0x02040B1C arm
 *   func_02040618 0x02040618 arm
 *   func_020437D4 0x020437D4 arm
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   func_02021ED8 0x02021ED8 thumb
 */
#include "../include/Obj00341.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Flags { u8 shown : 1; u8 close : 1; };
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void func_02040618(u32, u32, u32);
struct Bmp;
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_020061E4(u32 a);
extern int func_02006254(u32 a);
extern int func_021F86E0(void);
extern void *func_021F86D4(void);
extern int func_0202173C(void *, u16, u16, s16, u8, u8, u16, void *);
extern u32 func_02021ED8(const char *ptr);
int func_021EDCA8(u8 *p)
{
    u32 i;
    u8 *src;
    u32 dst;
    void *pal;
    void *ctx;
    u16 mask;
    switch (p[0xd]) {
    case 0:
        func_02040B1C(p[0xb], ((struct Obj00341 *)p)->f10, 0x900, ((struct Obj00341 *)p)->f1C);
        p[0xd]++;
        break;
    case 1:
        p[0x20] = 8;
        if (p[0xa] == 0) {
            ((struct Obj00341 *)p)->f14 = 0x90000;
            ((struct Obj00341 *)p)->f18 = -0x12000;
        } else {
            ((struct Obj00341 *)p)->f14 = -0x90000;
            ((struct Obj00341 *)p)->f18 = 0x12000;
        }
        func_02040618(p[0xb], 0, ((struct Obj00341 *)p)->f14 >> 12);
        func_02040618(p[0xb], 3, 0);
        func_020061E4(0x573);
        p[0xd]++;
        break;
    case 2:
        if (p[0x20] != 0) {
            ((struct Obj00341 *)p)->f14 += ((struct Obj00341 *)p)->f18;
            func_02040618(p[0xb], 0, ((struct Obj00341 *)p)->f14 >> 12);
            p[0x20]--;
        } else {
            func_02040618(p[0xb], 0, 0);
            p[0x21] = 0;
            p[0xd]++;
        }
        break;
    case 3:
        if (p[0x21] < 17) {
            src = (u8 *)func_020437D4(((struct Obj00341 *)p)->f4);
            dst = ((struct Obj00341 *)p)->f1C + p[0x21];
            src += p[0x21] * 32;
            for (i = 0; i < 4; i++) {
                func_02040B1C(p[0xb], src + i * 0x240, 32, dst + i * 18);
            }
            p[0x21]++;
        } else {
            ((struct Flags *)(p + 0x22))->shown = 1;
            if (((volatile struct Flags *)(p + 0x22))->close == 0) return 1;
            p[0xd]++;
        }
        break;
    case 4:
        pal = (void *)func_021F86E0();
        ctx = func_021F86D4();
        mask = 1 << (p[0xa] + 1);
        func_020061E4(0x54d);
        func_0202173C(pal, 1, mask, 0, 16, 0, 0x7fff, ctx);
        p[0xd]++;
        break;
    case 5:
        if (func_02021ED8((const char *)func_021F86E0()) == 0) p[0xd]++;
        break;
    case 6:
        if (func_02006254(0x54d) == 0 && func_02006254(0x573) == 0) return 1;
        break;
    }
    return 0;
}
