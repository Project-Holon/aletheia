/*
 * function: func_021E432C
 * address: 0x021E432C
 * packet: pkt_ov170_021E432C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_021EF3A0 0x021EF3A0 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021EF3EC 0x021EF3EC thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E01B0 0x021E01B0 thumb ov170
 *   func_020260E0 0x020260E0 thumb
 *   func_021DEFEC 0x021DEFEC thumb ov170
 *   func_021ED544 0x021ED544 thumb ov170
 *   func_021ED508 0x021ED508 thumb ov170
 *   func_021EE364 0x021EE364 thumb ov170
 *   func_021EF68C 0x021EF68C thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23899.h"
#include "../include/Obj23900.h"
typedef unsigned char u8;
typedef unsigned int u32;
#define W(p) (*(u8 **)((p) + 44))
struct WinMgr;
extern void func_021EC000(char *p, int i, int v);
extern void func_021EE038(char *p, int a, int b, int c);
extern void func_021EF3A0(struct WinMgr *mgr);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021ED888(char *p, int a);
extern void func_021EF3EC(struct WinMgr *mgr);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E01B0(u8 *);
struct Sound;
extern u8 func_020260E0(struct Sound *obj);
extern void func_021DEFEC(char *p, int b);
extern void func_021ED544(char *p, int b);
extern void func_021ED508(u8 *, int, int);
extern void func_021EE364(char **p, int idx, int v);
extern void func_021EF68C(char *p);
extern void func_021EF670(char *p);
int func_021E432C(u8 *p)
{
    u8 index;
    u8 selection;
    switch (*(u32 *)(W(p) + 0xa194)) {
    case 0:
        func_021EC000((char *)W(p), 4, 0);
        func_021EE038((char *)p, 0, 0, 1);
        if (p[27] == 0) {
            func_021EF3A0(*(struct WinMgr **)(W(p) + 116));
            *(u32 *)(W(p) + 0xa194) = 2;
        } else {
            func_021ECB20((char *)p, 1, 1);
            func_021ED888((char *)W(p), 0);
            func_021EF3EC(*(struct WinMgr **)(W(p) + 116));
            *(u32 *)(W(p) + 0xa194) = 1;
        }
        GFL_USE_PlaySeDefaultVolume(0x669);
        return func_021E8FC0((char *)p, (int)func_021E01B0, 33);
    case 1:
        *(u32 *)(W(p) + 0xa194) = 0;
        index = func_020260E0(*(void **)(W(p) + 112));
        if (index < 30 || index >= 36)
            selection = 0;
        else
            selection = index - 30;
        func_021DEFEC((char *)p, selection + 30);
        func_021ED544((char *)p, 6);
        func_021ED508(p, 14, 1);
        if (((struct Obj23899 *)(*(u8 * *)&((struct Obj00000 *)p)->f0))->f24 == 2) {
            func_021EE364((char **)p, 5, selection);
            return 27;
        }
        func_021EF68C((char *)W(p));
        func_021EE364((char **)p, 14, selection);
        return 39;
    case 2:
        *(u32 *)(W(p) + 0xa194) = 0;
        index = func_020260E0(*(void **)(W(p) + 112));
        if (index >= 30)
            index = 0;
        func_021DEFEC((char *)p, index);
        func_021EF670((char *)W(p));
        func_021ED544((char *)p, 6);
        func_021ED508(p, 14, 1);
        if (((struct Obj23900 *)(*(u8 * *)&((struct Obj00000 *)p)->f0))->f24 == 4) {
            func_021EE364((char **)p, 13, index);
            return 35;
        }
        func_021EE364((char **)p, 3, index);
        return 17;
    }
    return 33;
}
