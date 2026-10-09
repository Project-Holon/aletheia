/*
 * file:     pokemontrade_demo_up_p04.c
 * unit:     yes
 * function: func_021D5B74, func_021D5B98, func_021D5BB8, func_021D64F4, func_021D6544, func_021D6600, func_021D667C, func_021D66E8, func_021D6734, func_021D6738, func_021D6744, func_021D6750, func_021D67D4, func_021D67F8
 * address:  0x021D5B74
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021DFA60  0x021DFA60  thumb  ov119
 *   func_021E3004  0x021E3004  thumb  ov119
 *   func_021D56E0  0x021D56E0  thumb  ov118
 *   func_021D55AC  0x021D55AC  thumb  ov118
 *   func_021D5628  0x021D5628  thumb  ov118
 *   func_021D56FC  0x021D56FC  thumb  ov118
 *   func_021D5888  0x021D5888  thumb  ov118
 *   func_021D572C  0x021D572C  thumb  ov118
 *   func_021D5748  0x021D5748  thumb  ov118
 *   func_02015F50  0x02015F50  thumb
 *   func_02015EA0  0x02015EA0  thumb
 *   func_02015EB0  0x02015EB0  thumb
 *   func_02015E4C  0x02015E4C  thumb
 *   func_02015C30  0x02015C30  thumb
 *   func_02015C48  0x02015C48  thumb
 *   func_02015C94  0x02015C94  thumb
 *   func_02015CAC  0x02015CAC  thumb
 *   func_020515CC  0x020515CC  arm
 *   func_0202208C  0x0202208C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_021E71F0  0x021E71F0  thumb  ov119
 *   func_021E7208  0x021E7208  thumb  ov119
 *   func_021DFD24  0x021DFD24  thumb  ov119
 *   func_021DFB84  0x021DFB84  thumb  ov119
 *   func_021DFB4C  0x021DFB4C  thumb  ov119
 *   func_021D5930  0x021D5930  thumb  ov118
 *   func_021D5990  0x021D5990  thumb  ov118
 *   _dflt          0x0209B750  arm
 *   _dmul          0x0209B2E8  arm
 *   _dfix          0x0209C508  arm
 *   func_02015E04  0x02015E04  thumb
 *   func_021DFC68  0x021DFC68  thumb  ov119
 *   func_021E3230  0x021E3230  thumb  ov119
 *   func_0207D658  0x0207D658  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021D8FA4  0x021D8FA4  thumb  ov119
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_021E3BB0  0x021E3BB0  thumb  ov119
 *   func_021D8A24  0x021D8A24  thumb  ov119
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02030734  0x02030734  arm
 *   func_02015F2C  0x02015F2C  thumb
 *   func_021DFD0C  0x021DFD0C  thumb  ov119
 *   func_021E106C  0x021E106C  thumb  ov119
 *   func_02040EBC  0x02040EBC  arm
 *   func_021D6918  0x021D6918  thumb  ov118
 *   d_021D8650     0x021D8650  data
 *   d_021D7CC4     0x021D7CC4  data
 *   d_021D7CD0     0x021D7CD0  data
 */
#include "../../matched/include/Obj13879.h"
#include "../../matched/include/Obj22679.h"
#include "../../matched/include/Obj00672.h"
#include "../../matched/include/Obj22681.h"
#include "../../matched/include/Obj03255.h"
#include "../../matched/include/Obj22682.h"
#include "../../matched/include/Obj22683.h"
#include "../../matched/include/Obj22684.h"
#include "../../matched/include/Obj22685.h"
#include "../../matched/include/Obj03771.h"
#include "../../matched/include/Obj22686.h"
#include "../../matched/include/Obj01725.h"
#include "../../matched/include/Obj22687.h"
#include "../../matched/include/Obj22688.h"
#include "../../matched/include/Obj22689.h"
#include "../../matched/include/Obj22690.h"
#include "../../matched/include/Obj22691.h"
#include "../../matched/include/Obj00001.h"

#define FRAME (*(s32 *)(p + 0xF2C))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define HEAP (*(u16 *)(p + 0x5F4))
#define WORK (*(u32 **)(p + 0xc))
#define SLOT0 (*(u32 *)(p + 0x85C))
#define SLOT1 (*(u32 *)(p + 0x860))
#define FADE (*(s8 **)(p + 0x818))
struct Personal;
struct Sub0200852CObj;
struct Obj;
struct Actor;
struct Entry;
struct Link;
struct McssFade;
typedef unsigned int u32;

typedef unsigned char u8;

typedef int s32;

typedef unsigned short u16;

typedef struct {
    s32 x, y, z;
} Vec;

typedef signed char s8;

typedef int s32_021D64F4;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

typedef signed int     s32_021D667C;

typedef short s16;

extern void func_021D8E84(void *p, int next);
extern void func_021DFA60(u32 key);
extern void func_021E3004(char *p);
extern int func_021D56E0(int);
extern void func_021D55AC(void *);
extern void func_021D5628(void *);
extern void func_021D56FC(void *);
extern void func_021D5888(u8 *, int);
extern void func_021D572C(u8 *, int);
extern void func_021D5748(u8 *, int);
extern void func_02015F50(u32, u32, u32, s32, u32);
extern void func_02015EA0(u32);
extern void func_02015EB0(u32);
extern void func_02015E4C(u32);
extern void func_02015C30(u32, Vec *);
extern void func_02015C48(u32, Vec *);
extern void func_02015C94(u32, Vec *);
extern void func_02015CAC(u32, void *);
extern int func_020515CC(u32, int, void *, void *);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020307B0(u32);
extern void func_021E71F0(void *, int);
extern void func_021E7208(void *, int);
extern void func_021DFD24(u32);
extern u32 func_021DFB84(u32, int, Vec *, u32);
extern void func_021DFB4C(u32, int, void *);
extern void func_021D5930(void *p);
extern void func_021D5990(void *p);
extern void func_021DFC68(u32, void *);
extern void func_021E3230(void *);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern int func_021D8AA8(void *p);
extern void *func_021D8FA4(void *p, int which);
extern u32 func_02017E1C(void *mon, u32 id, u32 arg);
extern void *func_0201ADE4(unsigned int a, int b, unsigned int heap);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B9A0(struct Actor *a);
extern void *func_020490F4(u32 id, u32 heap);
extern s32_021D667C func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32_021D667C func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32_021D667C func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_021E3BB0(char *p);
extern int func_021D8A24(void *p);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *h, u32 a, u32 b);
extern u32 func_02039CB4(struct Link *h, u32 a, u32 b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02015F2C(u32 obj, void *arg, void (*cb)(void), int a);
extern void func_021DFD0C(char *p);
extern void func_021E106C(char *p);
extern void func_02040EBC(u32 a0, u32 a1);
extern void func_021D6918(u8 *p);
void func_021D5B74(u8 *p);
void func_021D5B98(u8 *p);
void func_021D5BB8(u8 *p);
void func_021D64F4(s8 *fade);
void func_021D6544(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy);
void func_021D6600(void *p);
void func_021D667C(void *p);
void func_021D66E8(void *p);
int func_021D6734(int a);
void func_021D6738(u8 *p, u32 v);
void func_021D6744(u8 *p);
void func_021D6750(u8 *p);
void func_021D67D4(u8 *p);
void func_021D67F8(u8 *p);
extern const char d_021D8650[];
extern const Vec d_021D7CC4;
extern const Vec d_021D7CD0;





/*
 * Addresses are Black-image addresses.
 */
void func_021D5B74(u8 *p)
{
    func_021DFA60(((struct Obj13879 *)p)->fF2C);
    func_021E3004(((struct Obj13879 *)p)->fC);
    func_021D8E84(p, (int)func_021D5B98);
}





void func_021D5B98(u8 *p)
{
    func_021DFA60(((struct Obj22679 *)p)->fF2C);
    func_021D8E84(p, (int)func_021D5BB8);
}





void func_021D5BB8(u8 *p)
{
    Vec v1, v2, v3, v4, v5, v6, v7, v8;

    func_021DFA60(FRAME);
    if (FRAME == func_021D56E0(1)) {
        func_02015F50(OBJ(0), 8, 8, 0, 0xFFFF);
    }
    if (FRAME == func_021D56E0(2)) {
        func_02015F50(OBJ(0), 0x10, 0x10, 0, 0xFFFF);
    }
    if (FRAME == func_021D56E0(3)) {
        func_021D5628(p);
        func_021D55AC(p);
    }
    if (FRAME == func_021D56E0(4)) {
        func_021E71F0(p, 0x11);
        func_021E7208(p, 0x18);
    }
    if (FRAME == func_021D56E0(4)) {
        func_02015EA0(OBJ(0));
    }
    if (FRAME == func_021D56E0(0x356)) {
        func_020515CC(WORK[0], 10, 0, p);
    }
    if (FRAME == func_021D56E0(0x65)) {
        func_020515CC(WORK[1], 1, 0, p);
    }
    if (FRAME == func_021D56E0(0x9A)) {
        func_020515CC(WORK[2], 2, 0, p);
    }
    if (FRAME == func_021D56E0(0x356)) {
        func_020515CC(WORK[8], 2, 0, p);
    }
    if (FRAME == func_021D56E0(0xE)) {
        func_020515CC(WORK[3], 3, 0, p);
    }
    if (FRAME == func_021D56E0(0x483)) {
        func_020515CC(WORK[7], 3, 0, p);
    }
    if (FRAME == func_021D56E0(0x9A)) {
        func_020515CC(WORK[4], 4, func_021D5930, p);
    }
    if (FRAME == func_021D56E0(0x152)) {
        func_020515CC(WORK[5], 5, 0, p);
    }
    if (FRAME == func_021D56E0(0x2BC)) {
        func_020515CC(WORK[6], 6, func_021D5990, p);
    }
    if (FRAME == func_021D56E0(0x47F)) {
        func_021D5628(p);
        func_021D55AC(p);
    }
    if (FRAME == func_021D56E0(0x10A)) {
        func_0202208C(0, 0, 0, 0x7FFF, func_021D56E0(0x14), 1, HEAP);
    }
    if (FRAME == func_021D56E0(0x12D)) {
        func_0202208C(0, 1, 1, 0x7FFF, func_021D56E0(0x19), 1, HEAP);
    }
    if (FRAME == func_021D56E0(0x14A)) {
        func_02015EB0(OBJ(2));
        v1.x = -0x32000;
        v1.y = -0x96000;
        v1.z = 0xA000;
        func_02015C48(OBJ(2), &v1);
        v1.x = -0x32000;
        v1.y = -0x37000;
        v1.z = 0xA000;
        func_021DFD24(SLOT0);
        SLOT0 = func_021DFB84(OBJ(2), func_021D56E0(0xF), &v1, HEAP);
        func_02015E04(OBJ(2));
        func_02015C94(OBJ(2), &v1);
        v1.x *= 1.2;
        v1.y *= 1.2;
        func_02015CAC(OBJ(2), &v1);
    }
    if (FRAME == func_021D56E0(0x14B)) {
        func_02015EB0(OBJ(3));
        v2.x = 0x3C000;
        v2.y = 0x50000;
        v2.z = -0xA000;
        func_02015C48(OBJ(3), &v2);
        v2.x = 0x3C000;
        v2.y = 0x5000;
        v2.z = -0xA000;
        func_021DFD24(SLOT1);
        SLOT1 = func_021DFB84(OBJ(3), func_021D56E0(0xF), &v2, HEAP);
        func_02015E04(OBJ(3));
        func_02015C94(OBJ(3), &v2);
        v2.x *= 1.2;
        v2.y *= 1.2;
        func_02015CAC(OBJ(3), &v2);
    }
    if (FRAME == func_021D56E0(0x154)) {
        v3.x = -0x32000;
        v3.y = -0x37000;
        v3.z = 0xA000;
        func_021DFB4C(SLOT0, func_021D56E0(0x1C), &v3);
        v3.x = 0x3C000;
        v3.y = 0x5000;
        v3.z = -0xA000;
        func_021DFB4C(SLOT1, func_021D56E0(0x1C), &v3);
    }
    if (FRAME == func_021D56E0(0x170)) {
        func_021D572C(p, 0);
        func_021D572C(p, 1);
        v4.x = -0x96000;
        v4.y = -0x37000;
        v4.z = 0;
        func_021DFD24(SLOT0);
        SLOT0 = func_021DFB84(OBJ(2), func_021D56E0(0x2E), &v4, HEAP);
        v4.x = 0x96000;
        v4.y = 0x5000;
        v4.z = 0;
        func_021DFD24(SLOT1);
        SLOT1 = func_021DFB84(OBJ(3), func_021D56E0(0x2E), &v4, HEAP);
        *(u16 *)(SLOT0 + 0x16) = 1;
        *(u16 *)(SLOT1 + 0x16) = 1;
    }
    if (FRAME == func_021D56E0(0x1B2)) {
        func_020307B0(SLOT0);
        SLOT0 = 0;
        func_02015EB0(OBJ(0));
        func_02015F50(OBJ(0), 0, 0, 0, 0x7FFF);
        v5.x = -0x96000;
        v5.y = 0x5000;
        v5.z = -0xA000;
        func_02015C48(OBJ(0), &v5);
        v5.x = 0x3C000;
        v5.y = 0x5000;
        v5.z = -0xA000;
        func_021DFD24(SLOT0);
        SLOT0 = func_021DFB84(OBJ(0), func_021D56E0(0x67), &v5, HEAP);
        func_02015C94(OBJ(0), &v5);
        v5.x *= 1.2;
        v5.y *= 1.2;
        func_02015CAC(OBJ(0), &v5);
        func_020307B0(SLOT1);
        SLOT1 = 0;
        func_02015EB0(OBJ(1));
        v6.x = 0x96000;
        v6.y = -0x37000;
        v6.z = 0xA000;
        func_02015C48(OBJ(1), &v6);
        v6.x = -0x2D000;
        v6.y = -0x37000;
        v6.z = 0xA000;
        func_021DFD24(SLOT1);
        SLOT1 = func_021DFB84(OBJ(1), func_021D56E0(0x67), &v6, HEAP);
        func_02015C94(OBJ(1), &v6);
        v6.x *= 1.2;
        v6.y *= 1.2;
        func_02015CAC(OBJ(1), &v6);
        *(u16 *)(SLOT0 + 0x16) = 1;
        *(u16 *)(SLOT1 + 0x16) = 1;
    }
    if (FRAME == func_021D56E0(0x1F8)) {
        func_021DFB4C(SLOT0, func_021D56E0(0x80), (void *)(SLOT0 + 0x28));
        func_021DFB4C(SLOT1, func_021D56E0(0x80), (void *)(SLOT1 + 0x28));
    }
    if (FRAME == func_021D56E0(0x27D)) {
        func_021D572C(p, 0);
        func_021D572C(p, 1);
        v7.x = 0x3C000;
        v7.y = 0x64000;
        v7.z = -0xA000;
        func_021DFD24(SLOT0);
        SLOT0 = func_021DFB84(OBJ(0), func_021D56E0(7), &v7, HEAP);
        v7.x = -0x2D000;
        v7.y = -0xA0000;
        v7.z = 0xA000;
        func_021DFD24(SLOT1);
        SLOT1 = func_021DFB84(OBJ(1), func_021D56E0(7), &v7, HEAP);
    }
    func_021D56E0(0x48B);
    if (FRAME == func_021D56E0(0x48B + 3)) {
        if (((struct Obj00672 *)p)->f11EE == 0) {
            func_021D5888(p, 3);
            func_021D5748(p, 3);
            func_02015F50(OBJ(3), 0x10, 0x10, 0, 0x7FFF);
        } else {
            func_021D5888(p, 3);
            func_02015EA0(OBJ(3));
            func_021D5888(p, 1);
            func_021D5748(p, 3);
            func_02015F50(OBJ(1), 0x10, 0x10, 0, 0x7FFF);
        }
    }
    if (FRAME == func_021D56E0(0x48F)) {
        func_02015F50(OBJ(3), 8, 8, 0, 0x7FFF);
    }
    if (FRAME == func_021D56E0(0x490)) {
        func_02015F50(OBJ(3), 0, 0, 0, 0x7FFF);
    }
    if (func_021D56E0(0x48E) < FRAME && ((struct Obj00672 *)p)->f11EE != 0 && *(u32 *)&((struct Obj00672 *)p)->f868 != 0
        && *(u32 *)(*(u32 *)&((struct Obj00672 *)p)->f868 + 8) == 9) {
        func_02015C30(OBJ(1), &v8);
        func_02015C48(OBJ(3), &v8);
        func_02015EB0(OBJ(3));
        func_02015EA0(OBJ(1));
        **(u32 * *)&((struct Obj00672 *)p)->f868 = OBJ(3);
    }
    if (FRAME == func_021D56E0(0x4A0)) {
        func_02015E4C(OBJ(3));
    }
    if (FRAME == func_021D56E0(0x28B)) {
        func_0202208C(0, 0, 0, 0x7FFF, func_021D56E0(0xA), 1, HEAP);
    }
    if (FRAME == func_021D56E0(0x2B5)) {
        func_0202208C(0, 1, 1, 0x7FFF, func_021D56E0(0x19), 1, HEAP);
    }
    if (FRAME == func_021D56E0(0x380)) {
        func_0202208C(0, 0, 0, 0x7FFF, func_021D56E0(0x1E), 1, HEAP);
    }
    if (FRAME == func_021D56E0(0x3CA)) {
        func_0202208C(0, 1, 1, 0x7FFF, func_021D56E0(0x1E), 1, HEAP);
    }
    if (FRAME == func_021D56E0(0x4C1)) {
        func_021D572C(p, 0);
        func_021D572C(p, 1);
        func_021E3230(p);
        func_021D8E84(p, (int)func_021D56FC);
    }
    func_021DFC68(SLOT0, p);
    func_021DFC68(SLOT1, p);
    func_021DFC68(((struct Obj00672 *)p)->f864, p);
    func_021DFC68(*(u32 *)&((struct Obj00672 *)p)->f868, p);
}





void func_021D64F4(s8 *fade)
{
    s32_021D64F4 value;

    if (fade == 0) {
        return;
    }
    if (fade[0] >= fade[1]) {
        fade[1]++;
        value = ((fade[3] - fade[2]) << 12) / fade[0];
        value = value * fade[1] / 4096;
        func_0207D658(0x04000050, 0x1E, value);
        func_0207D658(0x04001050, 0x1F, value);
    }
}





void func_021D6544(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy)
{
    int which;
    void *mon;
    u32 id;
    u32 a;
    u32 b;
    u32 egg;
    u32 h;
    u32 flag;

    if (enemy != 0) {
        if (func_021D8AA8(p) != 0) {
            which = 1;
        } else {
            which = 0;
        }
    } else {
        if (func_021D8AA8(p) != 0) {
            which = 0;
        } else {
            which = 1;
        }
    }
    mon = func_021D8FA4(p, which);
    id = func_02017E1C(mon, 7, 0);
    a = func_02017E1C(mon, 0xAB, 0);
    b = func_02017E1C(mon, 0x6F, 0);
    egg = func_02017E1C(mon, 0x4C, 0);
    if (egg == 0) {
        h = (u32)func_0201ADE4((u16)a, (u16)b, ((struct Obj22681 *)p)->f5F4);
        flag = func_0201AE1C((const struct Personal *)h, 0x10);
        func_0201AE14((void *)h);
    }
    if (egg != 0) {
        *outFlag = 1;
    } else if (flag != 0) {
        *outFlag = 1;
    } else {
        *outFlag = 0;
    }
    if (id != func_02008530((const struct Sub0200852CObj *)key)) {
        *outSame = 0;
    } else {
        *outSame = 1;
    }
}





void func_021D6600(void *p)
{
    u32 v = ((struct Obj22682 *)((char *)((struct Obj03255 *)p)->fC))->fB0;
    if (v == 0) {
        Local s;
        s.a = 0x80;
        s.b = 0x63;
        s.c = 0;
        s.d = 0;
        s.e = 0;
        ((struct Obj22683 *)((char *)((struct Obj03255 *)p)->fC))->fB0 =
            (u32)func_0204B294((void *)((struct Obj03255 *)p)->f9C4,
                          ((struct Obj03255 *)p)->f8A8,
                          ((struct Obj03255 *)p)->f88C,
                          ((struct Obj03255 *)p)->f8BC,
                          &s, 0, ((struct Obj03255 *)p)->f5F4);
        func_0204B92C((struct Obj *)((struct Obj22684 *)((char *)((struct Obj03255 *)p)->fC))->fB0, 1);
        func_0204B3DC((struct Obj *)((struct Obj22685 *)((char *)((struct Obj03255 *)p)->fC))->fB0, 1);
    } else {
        func_0204B9A0((struct Actor *)v);
    }
}





void func_021D667C(void *p)
{
    void *h = func_020490F4(0x67, ((struct Obj03771 *)p)->f5F4);
    ((struct Obj03771 *)p)->f8A8 = func_0204A6C8(h, 2, 0, 0, ((struct Obj03771 *)p)->f5F4);
    ((struct Obj03771 *)p)->f88C = func_0204AC18(h, 3, 0, 0xE0, 0, 1, ((struct Obj03771 *)p)->f5F4);
    ((struct Obj03771 *)p)->f8BC = func_0204AF28(h, 1, 0, ((struct Obj03771 *)p)->f5F4);
    func_02049238(h);
    ((struct Obj22686 *)((char *)((struct Obj03771 *)p)->fC))->fB0 = 0;
}





/*
 * Teardown of the three sub-buffers at +0x8a8/+0x88c/+0x8bc (their base
 * 0x8a8 is the single pool word) plus the +0xb0 pointer hung off the +0xc
 * record; every slot clears to zero. Non-SDK deps are the matched ov118
 * func_021D66E8 callers' targets; this is the first callee of func_021D6C78.
 *
 * Addresses are Black-image addresses.
 */
void func_021D66E8(void *p)
{
    u8 *b = p;

    if (((struct Obj22687 *)((u8 *)((struct Obj01725 *)b)->fC))->fB0 != 0)
        func_0204B3B4(((struct Obj22688 *)((u8 *)((struct Obj01725 *)b)->fC))->fB0);
    if (((struct Obj01725 *)b)->f8A8 != 0) {
        func_0204A8D4((u32)(((struct Obj01725 *)b)->f8A8));
        func_0204ADA4((u32)(((struct Obj01725 *)b)->f88C));
        func_0204AFD8((u32)(((struct Obj01725 *)b)->f8BC));
    }
    ((struct Obj01725 *)b)->f8A8 = 0;
    ((struct Obj01725 *)b)->f88C = 0;
    ((struct Obj01725 *)b)->f8BC = 0;
    ((struct Obj22689 *)((u8 *)((struct Obj01725 *)b)->fC))->fB0 = 0;
}




int func_021D6734(int a) { return a; }




void func_021D6738(u8 *p, u32 v) { ((struct Obj22690 *)p)->fF2C = v; }




void func_021D6744(u8 *p) { ((struct Obj22691 *)p)->f1094 = 1; }



void func_021D6750(u8 *p)
{
    func_021E3BB0((char *)p);
    if (((struct Obj00001 *)p)->f854 == 1) {
        func_021D6544(p, p + 0x11ED, p + 0x11EF, ((struct Obj00001 *)p)->f834, 1);
        func_021D6544(p, p + 0x11EE, p + 0x11F0, ((struct Obj00001 *)p)->f830, 0);
        func_021E3230(p);
        if (func_021D8A24(p) != 0) {
            func_02039C68((struct Link *)func_020399A8(), 0x11, 8);
            func_021D8E84(p, (int)func_021D67D4);
        } else {
            func_021D8E84(p, (int)func_021D67F8);
        }
    }
}



void func_021D67D4(u8 *p)
{
    if (func_02039CB4((struct Link *)func_020399A8(), 0x11, 8) != 0) {
        func_021D8E84(p, (int)func_021D67F8);
    }
}



void func_021D67F8(u8 *p)
{
    Vec a;
    Vec b;

    func_021D6738(p, 0);
    FADE = func_02030734(HEAP, 4, 1, d_021D8650, 0xF5);
    FADE[0] = func_021D6734(0xE);
    FADE[1] = 0;
    FADE[2] = 0;
    FADE[3] = -0x10;
    a = d_021D7CC4;
    func_021DFD24((u32)((u32 *)SLOT0));
    SLOT0 = (u32)(void *)func_021DFB84((u32)((void *)OBJ(0)), (int)((void *)func_021D6734(0x2A)), (Vec *)&a, HEAP);
    b = d_021D7CD0;
    func_021DFD24((u32)((u32 *)SLOT1));
    SLOT1 = (u32)(void *)func_021DFB84((u32)((void *)OBJ(1)), (int)((void *)func_021D6734(0x54)), (Vec *)&b, HEAP);
    func_02015F2C(OBJ(0), p, (void (*)(void))func_021DFD0C, 1);
    func_02015F50((u32)((struct McssFade *)OBJ(1)), 0, 0x10, (s8)(func_021D6734(0xE) / 16), 0);
    func_021E106C((char *)p);
    func_02040EBC(1, 0);
    func_02040EBC(5, 0);
    func_021D6738(p, 0);
    func_021D8E84(p, (int)func_021D6918);
}
