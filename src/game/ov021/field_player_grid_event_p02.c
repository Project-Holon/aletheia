/*
 * file:     field_player_grid_event_p02.c
 * unit:     yes
 * function: func_021C0810, func_021C0820, func_021C0844, func_021C0904, func_021C0988, func_021C09A8, func_021C09B0, func_021C0A10, func_021C0A48, func_021C0A70, func_021C0AA0, func_021C0AC0, func_021C0B3C, func_021C0BD8, func_021C0BE8, func_021C0C48, func_021C0C80, func_021C0C94, func_021C0CA4, func_021C0CE4, func_021C0D08, func_021C0DDC, func_021C0E4C, func_021C0E98, func_021C1024, func_021C1094, func_021C10A0, func_021C10B4, func_021C1228, func_021C12C4, func_021C12D0, func_021C12E4, func_021C1318, func_021C146C, func_021C14F8, func_021C157C, func_021C161C, func_021C1670, func_021C16AC
 * address:  0x021C0810
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012124  0x02012124  thumb
 *   _s32_div_f  0x0209C0A4  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02029830  0x02029830  thumb
 *   func_02029620  0x02029620  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0218C584  0x0218C584  thumb  ov021
 *   func_0218C6D0  0x0218C6D0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_0218C860  0x0218C860  thumb  ov021
 *   func_020520FC  0x020520FC  arm
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0218C7F0  0x0218C7F0  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   d_021DA098  0x021DA098  data  ov021  a4
 *   func_0218C88C  0x0218C88C  thumb  ov021
 *   func_0218C69C  0x0218C69C  thumb  ov021
 *   func_0218C8FC  0x0218C8FC  thumb  ov021
 *   func_0218C724  0x0218C724  thumb  ov021
 *   d_021DA0E0     0x021DA0E0  data  a4
 *   func_0218C8D8  0x0218C8D8  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA1C  0x0201AA1C  thumb
 *   func_021A5728  0x021A5728  thumb  ov021
 *   func_021A572C  0x021A572C  thumb  ov021
 *   func_021A3AB8  0x021A3AB8  thumb  ov021
 *   func_021A44BC  0x021A44BC  thumb  ov021
 *   func_021A448C  0x021A448C  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02164208  0x02164208  thumb  ov010
 *   func_0216D91C  0x0216D91C  thumb  ov010
 *   func_0216D924  0x0216D924  thumb  ov010
 *   func_021AB0D4  0x021AB0D4  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   func_021AB2DC  0x021AB2DC  thumb  ov021
 *   func_021C19B4  0x021C19B4  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216E5FC  0x0216E5FC  thumb  ov010
 *   func_021A395C  0x021A395C  thumb  ov021
 *   func_021639C0  0x021639C0  thumb  ov010
 *   func_021A3990  0x021A3990  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A5408  0x021A5408  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216DAE0  0x0216DAE0  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D8E0  0x0216D8E0  thumb  ov010
 *   func_0216E014  0x0216E014  thumb  ov010
 *   func_0216E57C  0x0216E57C  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   d_021DE3AC     0x021DE3AC  data  ov021  a4
 *   func_021A3068  0x021A3068  thumb  ov021
 *   func_021A36E0  0x021A36E0  thumb  ov021
 *   func_021AB2E8  0x021AB2E8  thumb  ov021
 *   func_02188D30  0x02188D30  thumb  ov021
 *   func_02030DA8  0x02030DA8  arm
 *   func_02030EE8  0x02030EE8  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_02164280  0x02164280  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021ACB38  0x021ACB38  thumb  ov021
 *   func_021A2F8C  0x021A2F8C  thumb  ov021
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AA900  0x021AA900  thumb  ov021
 *   func_021AAB1C  0x021AAB1C  thumb  ov021
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_021A2F98  0x021A2F98  thumb  ov021
 *   func_021ACBB8  0x021ACBB8  thumb  ov021
 *   func_021A2F48  0x021A2F48  thumb  ov021
 *   func_021A2F54  0x021A2F54  thumb  ov021
 *   func_021A35A0  0x021A35A0  thumb  ov021
 *   func_021C1988  0x021C1988  thumb  ov021
 *   func_021ABE30  0x021ABE30  thumb  ov021
 *   func_021AD564  0x021AD564  thumb  ov021
 *   func_021C6B18  0x021C6B18  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_021AD5CC  0x021AD5CC  thumb  ov021
 *   func_021ABE64  0x021ABE64  thumb  ov021
 */
#include "../../matched/include/Obj00707.h"
#include "../../matched/include/Obj02394.h"
#include "../../matched/include/Obj20159.h"
#include "../../matched/include/Obj00959.h"
#include "../../matched/include/Obj01505.h"
#include "../../matched/include/Obj06070.h"
#include "../../matched/include/Obj00235.h"
#include "../../matched/include/Obj05075.h"
#include "../../matched/include/Obj18274.h"
#include "../../matched/include/Obj03610.h"
#include "../../matched/include/Obj18276.h"
#include "../../matched/include/Obj01665.h"
#include "../../matched/include/Obj01359.h"
#include "../../matched/include/Obj01506.h"
#include "../../matched/include/Obj00657.h"
#include "../../matched/include/Obj04270.h"
#include "../../matched/include/Obj04271.h"
#include "../../matched/include/Obj00129.h"

struct Ctx;
struct Desc;
struct Obj;
struct Evt;
struct Obj00020;
struct VecFx32;
struct Mtx33;
struct Blk;
struct BigObj;
struct Actor;
struct S02030EE8;
struct Self;
struct Node;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { int x, y, z; } Vec;

typedef struct { int x, y, z; } Vec3;

typedef struct {
    u16 state;
    s16 count;
    u16 f4;
    u16 f6;
    u16 f8;
    u16 padA;
    u32 fC;
    u8 *f10;
    u32 f14;
} Work;

typedef struct { int x, y, z; } V3;

extern void func_02012124(struct Ctx *p, u32 v);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
extern void *func_02188C80(void *p);
extern void *func_02029830(void *a, u32 b);
extern void *func_02029620(void *a, u32 b, u32 c);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_0201210C(const struct Ctx *p);
extern u16 func_02188C84(u8 *p);
extern u32 func_02188C98(u8 *p);
extern u32 func_0218DC6C(u8 *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3038(unsigned char *a, struct VecFx32 *pos);
extern int *func_0218C584(int, int *, int, int *);
extern void func_0218C6D0(int *p, int b);
extern u32 func_020307B0(void *p);
extern void func_0218C860(int);
extern void func_020520FC(int ax, int ay, int az, struct Mtx33 *dst);
extern void func_0207C9D0(u8 *dst, u8 *src, int *v);
extern u8 *func_0218C7F0(u8 *owner, u32 x, struct Blk *src);
extern void func_020061E4(u32 a);
extern void func_0218C88C(unsigned char *p, int v, int c);
extern void func_0218C69C(unsigned char *p, int b, int i, int c);
extern int func_0218C8FC(unsigned char *p, int i);
extern u8 *func_0218C724(u8 *owner, u32 *obj);
extern int func_0218C8D8(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA1C(void *);
extern u32 func_021A5728(u8 *p);
extern void *func_021A572C(u8 *p);
extern u16 func_021A3AB8(u32 a, u32 v);
extern int func_021A44BC(int a, int b);
extern int func_021A448C(u32 *p, int a);
extern void func_0216D88C(const struct Actor *obj, struct VecFx32 *out);
extern void func_02164208(int dir, int *p, int amt);
extern u8 func_0216D91C(int a0);
extern u8 func_0216D924(int a0);
extern int func_021AB0D4(void *a, void *b);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB11C(u32 attr);
extern int func_021AB2DC(u16 id);
extern u32 func_021C19B4(u8 *a, u32 b);
extern u16 func_0216D598(void *p);
extern int func_0216E5FC(u16 id);
extern u32 func_021A395C(u8 *p);
extern u32 func_021639C0(u32 a, u32 b);
extern u32 func_021A3990(u8 *p);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_021A3960(unsigned char *p);
extern int func_0216D3CC(int a0);
extern int func_021A5408(u8 *a);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(u32 o, u32 a);
extern int func_0216D454(u32 o);
extern int func_02163E58(u32 o, Vec3 *v, int *out);
extern int func_0216DB4C(void *a0, int a1);
extern void func_0216DAE0(unsigned int *p, unsigned int v);
extern void func_0216D89C(u32 o, Vec3 *v);
extern void func_0216D8E0(u32 o, void *p);
extern void func_0216E014(void *a, int *p, int b);
extern void func_0216E57C(void *a);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern u32 func_021A3068(u8 *p);
extern u32 func_021A36E0(u8 *p);
extern int func_021AB2E8(int id);
extern u32 func_02188D30(u8 *p);
extern void func_02030DA8(u32, void (*)(), u32 *, u32);
extern u32 func_02030EE8(struct S02030EE8 *p);
extern u32 func_02030EAC(u32);
extern void *func_021A3074(unsigned char *p);
extern u16 func_0216D5F8(void *obj);
extern int func_0216D83C(void *obj);
extern int func_0216D86C(void *obj);
extern void func_02164280(int x, int y, int *p);
extern u32 func_02188CD0(u8 *p);
extern u32 func_021ACB38(u32, u32, Vec *, void *, int);
extern void func_021A2F8C(u8 *a, u32 b);
extern u32 func_02188CE8(u8 *p);
extern int func_021AA900(struct Self *self, short *pos);
extern void func_021AAB1C(void *p, int b);
extern int func_0216D480(char *p);
extern u32 func_021A2F98(u8 *a);
extern void func_021ACBB8(u32 a, u8 v);
extern void func_021A2F48(u8 *p, u32 a1);
extern int func_021A2F54(u8 *a);
extern void func_021A35A0(u32 *p, int a);
extern void func_021C1988(void *a, u16 *s);
extern void func_021ABE30(int a, int *b, int c);
extern u32 func_021AD564(u32 a, u32 b, u32 c);
extern void func_021C6B18(u32 a, u16 b, u32 c);
extern void func_021AC154(u32 a);
extern int func_0209C0A4(int a, int b);
extern int func_021AD5CC(u32 a);
extern void func_021ABE64(u32 a, int b);
int func_021C0810(u32 a, u32 b, u32 c, u32 d);
void *func_021C0820(void *p, int a1, u32 n);
int func_021C0844(u32 a, int *st, u8 *p);
void func_021C0904(u8 *p, u32 a, u32 n);
void func_021C0988(u8 *p);
void func_021C09A8(u8 *p, int *st, int v);
void func_021C09B0(u8 *p);
void func_021C0A10(u8 *p);
void func_021C0A48(u8 *p);
int func_021C0A70(u8 *p);
void *func_021C0AA0(void *p, int a1);
int func_021C0AC0(u32 a, int *st, u8 *p);
void func_021C0B3C(u8 *p, u32 a);
void func_021C0BD8(int *p);
void func_021C0BE8(u8 *p);
void func_021C0C48(u8 *p);
int func_021C0C80(u32 a);
u32 func_021C0C94(u32 a);
int func_021C0CA4(u8 *a, int b, int c, int d);
int func_021C0CE4(u8 *a, u32 b, u32 flags);
int func_021C0D08(void *obj, u32 dir, void *map);
int func_021C0DDC(u8 *a, u32 b, int c);
void *func_021C0E4C(u32 a, u32 b, u32 c, u32 d);
int func_021C0E98(u32 unused, int *st, u8 *p);
void func_021C1024(u32 a, u16 b, u32 c, u32 d);
int func_021C1094(void *a);
int func_021C10A0(u32 a);
void func_021C10B4(u32 task, Work *w);
void func_021C1228(u32 a, u16 b, u32 c, u32 d);
int func_021C12C4(void *a);
void func_021C12D0(void *h);
void func_021C12E4(u32 a, const V3 *v);
int func_021C1318(u8 *p);
int func_021C146C(u8 *p);
int func_021C14F8(u8 *p);
int func_021C157C(u8 *p);
int func_021C161C(u8 *p);
int func_021C1670(u8 *p);
void func_021C16AC(u8 *p);
extern u8 d_021DA098[];
extern u8 d_021DA0E0;
extern u8 d_021DE3AC;








/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C0810(u32 a, u32 b, u32 c, u32 d)
{
func_02012124((struct Ctx *)c, 0);
return 1;
}








void *func_021C0820(void *p, int a1, u32 n)
{
    void *t = func_020122C0(p, (void *)a1, func_021C0844, 0x38);
    u8 *w = func_020124E8(t);

    func_021C0904(w, (u32)p, n);
    return t;
}








int func_021C0844(u32 a, int *st, u8 *p)
{
    switch (*st) {
    case 0:
        if ((int)((struct Obj00707 *)p)->f16 % 15 == 0) {
            func_021C09B0(p);
            if (p[0x14] <= p[0x15]) {
                func_021C09A8(p, st, 1);
            }
        }
        break;
    case 1:
        if (((struct Obj00707 *)p)->f16 > 10) {
            func_021C0A10(p);
            func_02012374((struct Evt *)a, func_02029830(func_02188C80((void *)(((struct Obj00707 *)p)->f4)), 0x514));
            func_021C09A8(p, st, 2);
        }
        break;
    case 2:
        if (func_021C0A70(p) != 0) {
            func_021C0A48(p);
            func_021C09A8(p, st, 3);
        }
        break;
    case 3:
        func_02012374((struct Evt *)a, func_02029620(func_02188C80((void *)(((struct Obj00707 *)p)->f4)), 0, 6));
        func_021C09A8(p, st, 4);
        break;
    case 4:
        func_021C0988(p);
        return 1;
    }
    ((struct Obj00707 *)p)->f16 = ((struct Obj00707 *)p)->f16 + 1;
    return 0;
}








void func_021C0904(u8 *p, u32 a, u32 n)
{
    void *s;
    u32 w;
    u32 t;
    int *r;
    int pos[3];
    int rect[4];
    int cnt;

    s = func_0201210C((void *)a);
    w = func_02188C84(s);
    t = func_02188C98(s);
    ((struct Obj02394 *)p)->f0 = w;
    p[0x14] = n;
    ((struct Obj02394 *)p)->f4 = s;
    p[0x15] = 0;
    ((struct Obj02394 *)p)->f18 = func_0218DC6C((u8 *)t);
    ((struct Obj02394 *)p)->f34 = 0;
    if (p[0x14] > 6) {
        p[0x14] = 6;
    }
    func_021A3038(func_02188CB4(((struct Obj02394 *)p)->f4), (struct VecFx32 *)pos);
    rect[0] = pos[2] - 0x50000;
    rect[1] = pos[2] + 0x50000;
    rect[2] = pos[0] - 0x50000;
    rect[3] = pos[0] + 0x50000;
    r = func_0218C584(((struct Obj02394 *)p)->f18, rect, 3, &cnt);
    if (r) {
        ((struct Obj02394 *)p)->f34 = *r;
        func_0218C6D0((int *)(*r), (int)(p + 8));
    }
    func_020307B0(r);
}








/*
 * Releases each of the p[0x14] handles (EXACT*: unlabelled follower at 0x021C09A8).
 */
void func_021C0988(u8 *p)
{
    int i;

    for (i = 0; i < p[0x14]; i++)
        func_0218C860(((int *)(p + 0x1C))[i]);
}








/*
 * Unlabelled leaf: stores the next state and clears the halfword counter at +0x16.
 */
void func_021C09A8(u8 *p, int *st, int v)
{
    *st = v;
    ((struct Obj20159 *)p)->f16 = 0;
}








void func_021C09B0(u8 *p)
{
    struct { int out[3]; int scale[3]; int mat[9]; } s;
    u32 i;

    i = p[0x15];
    if (p[0x14] > i) {
        s.scale[0] = 0x1000;
        s.scale[1] = 0x1000;
        s.scale[2] = 0x1000;
        func_020520FC(0, 0, 0, (struct Mtx33 *)s.mat);
        func_0207C9D0(p + 8, d_021DA098 + i * 12, s.out);
        *(u32 *)(p + 0x1c + i * 4) = (u32)func_0218C7F0((u8 *)(((struct Obj00707 *)p)->f18), 0x62, (struct Blk *)s.out);
        p[0x15] = p[0x15] + 1;
        func_020061E4(0x568);
    }
}








/*
 * Resets each of the p[0x15] handles, then the optional one at +0x34.
 */
void func_021C0A10(u8 *p)
{
    int i;

    for (i = 0; i < p[0x15]; i++)
        func_0218C88C((unsigned char *)(((int *)(p + 0x1C))[i]), 0, 0);
    if (((struct Obj00707 *)p)->f34 != 0)
        func_0218C69C((unsigned char *)(*(int *)&((struct Obj00707 *)p)->f18), ((struct Obj00707 *)p)->f34, 0, 0);
}








/*
 * Sets mode 3 on each of the p[0x15] handles.
 */
void func_021C0A48(u8 *p)
{
    int i;

    for (i = 0; i < p[0x15]; i++)
        func_0218C88C((unsigned char *)(((int *)(p + 0x1C))[i]), 0, 3);
}








/*
 * Returns 1 when every one of the p[0x15] handles reports done.
 */
int func_021C0A70(u8 *p)
{
    int i;

    for (i = 0; i < p[0x15]; i++) {
        if (func_0218C8FC((unsigned char *)(((int *)(p + 0x1C))[i]), 0) != 1)
            return 0;
    }
    return 1;
}








/*
 * Spawns a 0x3C-byte task (callback func_021C0AC0) and initialises it.
 */
void *func_021C0AA0(void *p, int a1)
{
    void *t = func_020122C0(p, (void *)a1, func_021C0AC0, 0x3C);
    u8 *w = func_020124E8(t);

    func_021C0B3C(w, (u32)p);
    return t;
}







int func_021C0AC0(u32 a, int *st, u8 *p)
{
    switch (*st) {
    case 0:
        if ((int)((struct Obj00959 *)p)->f16 % 20 == 0) {
            func_021C0BE8(p);
            if (p[0x14] <= p[0x15]) {
                *st = *st + 1;
                ((struct Obj00959 *)p)->f16 = 0;
            }
        }
        break;
    case 1:
        if (((struct Obj00959 *)p)->f16 > 10) {
            func_021C0C48(p);
            *st = *st + 1;
            ((struct Obj00959 *)p)->f16 = 0;
        }
        break;
    case 2:
        if (func_021C0C80((u32)p) != 0) {
            *st = *st + 1;
        }
        break;
    case 3:
        func_021C0BD8((int *)p);
        return 1;
    }
    ((struct Obj00959 *)p)->f16 = ((struct Obj00959 *)p)->f16 + 1;
    return 0;
}







void func_021C0B3C(u8 *p, u32 a)
{
    void *s;
    u32 t;
    int *r;
    int pos[3];
    int rect[4];
    int cnt;

    s = func_0201210C((void *)a);
    t = func_02188C98(s);
    ((struct Obj01505 *)p)->f0 = func_02188C84(s);
    ((struct Obj01505 *)p)->f4 = s;
    p[0x14] = func_021C0C94(a);
    p[0x15] = 0;
    ((struct Obj01505 *)p)->f18 = func_0218DC6C((u8 *)t);
    ((struct Obj01505 *)p)->f34 = 0;
    if (p[0x14] > 6) {
        p[0x14] = 6;
    }
    func_021A3038(func_02188CB4(((struct Obj01505 *)p)->f4), (struct VecFx32 *)pos);
    rect[0] = pos[2] - 0x50000;
    rect[1] = pos[2] + 0x50000;
    rect[2] = pos[0] - 0x50000;
    rect[3] = pos[0] + 0x50000;
    r = func_0218C584(((struct Obj01505 *)p)->f18, rect, 8, &cnt);
    if (r) {
        ((struct Obj01505 *)p)->f34 = *r;
        func_0218C6D0((int *)(*r), (int)(p + 8));
    }
    func_020307B0(r);
    if (((struct Obj01505 *)p)->f34 != 0) {
        ((struct Obj01505 *)p)->f38 = (u32)func_0218C724((u8 *)(((struct Obj01505 *)p)->f18), (u32 *)(((struct Obj01505 *)p)->f34));
    }
}







/*
 * Releases the optional handle at +0x38.
 */
void func_021C0BD8(int *p)
{
    if (p[13] != 0)
        func_0218C860(p[14]);
}







/*
 * Addresses are Black-image addresses.
 */
void func_021C0BE8(u8 *p)
{
    struct {
        int pos[3];
        int scale[3];
        int mtx[9];
    } s;
    u32 i;

    i = p[0x15];
    if (p[0x14] > i) {
        s.scale[0] = 0x1000;
        s.scale[1] = 0x1000;
        s.scale[2] = 0x1000;
        func_020520FC(0, 0, 0, (struct Mtx33 *)s.mtx);
        func_0207C9D0(p + 8, &d_021DA0E0 + i * 12, s.pos);
        *(u32 *)(p + 0x1c + i * 4) = (u32)func_0218C7F0((u8 *)(((struct Obj00959 *)p)->f18), 0x62, (struct Blk *)(&s));
        p[0x15]++;
        func_020061E4(0x568);
    }
}







/*
 * Sets mode 2 on each of the p[0x15] handles, then resets the one at +0x38.
 */
void func_021C0C48(u8 *p)
{
    int i;

    for (i = 0; i < p[0x15]; i++)
        func_0218C88C((unsigned char *)(((int *)(p + 0x1C))[i]), 0, 2);
    if (((struct Obj00959 *)p)->f34 != 0)
        func_0218C88C((unsigned char *)(((struct Obj00959 *)p)->f38), 0, 0);
}







int func_021C0C80(u32 a)
{
if (*(u32 *)&((struct Obj00959 *)((u8 *)(a)))->f34 != 0) {
    return func_0218C8D8((void *)(*(u32 *)&((struct Obj00959 *)((u8 *)(a)))->f38));
}
return 1;
}







u32 func_021C0C94(u32 a)
{
return func_0201AA1C(func_02012934(func_020120F4((const struct Ctx *)a)));
}







int func_021C0CA4(u8 *a, int b, int c, int d)
{
    int r7, r4;
    r7 = func_021A5728((u8 *)a);
    func_021A572C((u8 *)a);
    r4 = func_021A3AB8(r7, c);
    if (func_021A44BC((int)a, r4) == 0)
        return 0;
    r7 = func_021C0CE4(a, r4, d);
    if (r7 == 0)
        return 0;
    return r7;
}







/*
 * Runs func_021C0DDC when bit 0 of the flags is set.
 */
int func_021C0CE4(u8 *a, u32 b, u32 flags)
{
    int r = 0;
    int h = func_021A448C((u32 *)a, b);

    if (flags & 1)
        r = func_021C0DDC(a, b, h);
    return r;
}







int func_021C0D08(void *obj, u32 dir, void *map)
{
    Vec pos;
    Vec cur;
    int flagB;
    int flagA;
    u8 i;
    u8 m;
    u8 n;
    u8 j;
    u32 attr;
    u16 id;

    func_0216D88C(obj, (struct VecFx32 *)&pos);
    func_02164208(dir, (int *)(&pos), 0x10000);
    n = func_0216D91C((int)obj);
    m = func_0216D924((int)obj);
    flagB = 0;
    flagA = 0;
    for (i = 0; i < m; i++, pos.z -= 0x10000) {
        cur = pos;
        for (j = 0; j < n; j++, cur.x += 0x10000) {
            attr = func_021AB0D4(map, &cur);
            id = func_021AB0F0(attr);
            if (func_021AB11C(attr)) {
                if (func_021AB2DC(id) == 0)
                    return 1;
                flagA = 1;
            } else {
                flagB = 1;
            }
        }
    }
    if (flagA == 1) {
        if (flagB == 0)
            return 3;
        return 2;
    }
    return 0;
}







int func_021C0DDC(u8 *a, u32 b, int c)
{
    u32 r6;
    u32 r4;
    u32 f;

    if (c == 1) {
        r6 = func_021C19B4(a, b);
        if (r6 != 0) {
            if (func_0216E5FC(func_0216D598((void *)r6)) == 1) {
                r4 = func_021C0D08((void *)r6, b, (void *)func_02188C98((u8 *)func_021A395C((u8 *)func_021A5728((u8 *)a))));
                f = func_021639C0(r6, b);
                f &= ~1;
                if ((f & 2) && r4 - 2 <= 1)
                    f &= ~2;
                if (f == 0) {
                    int k = 0;
                    if (r4 == 3)
                        k = 1;
                    return (int)func_021C0E4C((u32)a, b, r6, k);
                }
            }
        }
    }
    return 0;
}







void *func_021C0E4C(u32 a, u32 b, u32 c, u32 d)
{
    u32 t;
    void *task;
    u32 *w;

    t = func_021A5728((u8 *)a);
    task = func_020122C0((void *)func_021A3990((u8 *)t), 0, func_021C0E98, 0x24);
    w = func_020124E8(task);
    func_02082BCC(w, 0, 0x24);
    w[0] = a;
    ((struct Obj06070 *)w)->f4 = b;
    ((struct Obj06070 *)w)->f6 = d;
    w[7] = c;
    w[8] = (u32)func_021A3960((void *)t);
    return task;
}







int func_021C0E98(u32 unused, int *st, u8 *p)
{
    Vec3 a;
    Vec3 b;
    Vec3 c;

    switch (*st) {
    case 0:
        if (func_0216D3CC(((struct Obj00235 *)p)->f1C) == 0)
            break;
        if (func_0216D3CC(((struct Obj00235 *)p)->f20) == 0 && func_021A5408((u8 *)(((struct Obj00235 *)p)->f0)) == 0)
            break;
        func_0216D410(((struct Obj00235 *)p)->f1C, func_02197E7C(((struct Obj00235 *)p)->f4, 8));
        func_0216D410(((struct Obj00235 *)p)->f20, func_02197E7C(((struct Obj00235 *)p)->f4, 0x20));
        func_020061E4(0x674);
        (*st)++;
        break;
    case 1:
        if (func_0216D454(((struct Obj00235 *)p)->f1C) == 0)
            break;
        if (func_0216D454(((struct Obj00235 *)p)->f20) == 0)
            break;
        if (((struct Obj00235 *)p)->f6 == 0) {
            *st = 4;
            break;
        }
        func_0216D88C((const struct Actor *)((struct Obj00235 *)p)->f1C, (struct VecFx32 *)&a);
        func_02163E58(((struct Obj00235 *)p)->f1C, &a, (int *)(p + 0xc));
        if (func_0216D598((void *)(((struct Obj00235 *)p)->f1C)) == 0x6d)
            ((struct Obj00235 *)p)->fC -= 14 << 12;
        else
            ((struct Obj00235 *)p)->fC -= 26 << 12;
        func_0216DB4C((void *)(((struct Obj00235 *)p)->f1C), 1);
        func_0216DAE0((unsigned int *)(((struct Obj00235 *)p)->f1C), 0);
        func_020061E4(0x675);
        (*st)++;
        break;
    case 2:
        func_0216D88C((const struct Actor *)((struct Obj00235 *)p)->f1C, (struct VecFx32 *)&b);
        if (((struct Obj00235 *)p)->fC < b.y) {
            b.y -= 0x4000;
            if (((struct Obj00235 *)p)->fC > b.y)
                b.y = ((struct Obj00235 *)p)->fC;
        } else if (((struct Obj00235 *)p)->fC > b.y) {
            b.y += 0x4000;
            if (((struct Obj00235 *)p)->fC < b.y)
                b.y = ((struct Obj00235 *)p)->fC;
        }
        func_0216D89C(((struct Obj00235 *)p)->f1C, &b);
        if (((struct Obj00235 *)p)->fC == b.y) {
            ((struct Obj00235 *)p)->f14 = 0x2000;
            (*st)++;
        }
        break;
    case 3:
        func_0216D8E0(((struct Obj00235 *)p)->f1C, p + 0x10);
        ((struct Obj00235 *)p)->f14 = -((struct Obj00235 *)p)->f14;
        ((struct Obj00235 *)p)->f8 = ((struct Obj00235 *)p)->f8 + 1;
        if (((struct Obj00235 *)p)->f8 & 4) {
            if (((struct Obj00235 *)p)->f14 < 0)
                ((struct Obj00235 *)p)->f14 += 0x1000;
            else if (((struct Obj00235 *)p)->f14 > 0)
                ((struct Obj00235 *)p)->f14 -= 0x1000;
        }
        if (((struct Obj00235 *)p)->f14 == 0) {
            func_0216D88C((const struct Actor *)((struct Obj00235 *)p)->f1C, (struct VecFx32 *)&c);
            func_0216E014((void *)(((struct Obj00235 *)p)->f1C), (int *)(&c), ((struct Obj00235 *)p)->f4);
            func_0216D8E0(((struct Obj00235 *)p)->f1C, p + 0x10);
            func_0216E57C((void *)(((struct Obj00235 *)p)->f1C));
            (*st)++;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}







void func_021C1024(u32 a, u16 b, u32 c, u32 d)
{
    u32 *r;

    r = func_02030734((u16)(0x8000 | (d & 0x7fff)), 0x18, 1, (const char *)&d_021DE3AC, 0x1e6);
    r[3] = func_021A3068((u8 *)a);
    ((struct Obj05075 *)r)->f6 = b;
    r[4] = a;
    r[5] = func_021A36E0((u8 *)a);
    if (func_021AB2E8(func_021AB0F0(c)) == 1)
        ((struct Obj05075 *)r)->f8 = 1;
    func_02030DA8(func_02188D30((u8 *)r[3]), func_021C10B4, r, 0);
}






int func_021C1094(void *a)
{
return ((struct Obj18274 *)((u8 *)(func_02030EE8((struct S02030EE8 *)a))))->f4;
}






int func_021C10A0(u32 a)
{
func_020307B0((void *)func_02030EE8((struct S02030EE8 *)a));
return func_02030EAC(a);
}






void func_021C10B4(u32 task, Work *w)
{
    void *obj;
    u16 dir;
    u32 r;
    int x;
    int y;
    Vec v;
    int h;
    s16 pos[3];
    void *q;
    int step;

    obj = func_021A3074(w->f10);
    switch (w->state) {
    case 0:
        dir = func_0216D5F8(obj);
        x = func_0216D83C(obj);
        y = func_0216D86C(obj);
        func_0216D88C(obj, (struct VecFx32 *)&v);
        func_02164280(x, y, (int *)(&v));
        step = 0x10000;
        if (w->f8 == 1)
            step = 0x20000;
        func_02164208(dir, (int *)(&v), step);
        h = 0;
        func_02163E58((u32)obj, (Vec3 *)&v, &h);
        v.y = h;
        func_021A2F8C(w->f10, func_021ACB38(func_02188CD0((u8 *)w->fC), dir, &v, obj, 0));
        q = (void *)func_02188CE8((u8 *)w->fC);
        pos[0] = (v.x >> 4) / 0x1000;
        pos[1] = (v.y >> 4) / 0x1000;
        pos[2] = (v.z >> 4) / 0x1000;
        if (func_021AA900(q, pos))
            func_021AAB1C(q, 1);
        w->state++;
        break;
    case 1:
        w->count++;
        if (w->count > 15)
            w->state++;
        break;
    case 2:
        dir = func_0216D5F8(obj);
        r = func_02197E7C(dir, 0x34);
        if (w->f8 == 1)
            r = func_02197E7C(dir, 0x38);
        func_0216D410((u32)obj, r);
        w->state++;
        break;
    case 3:
        if (func_0216D454((u32)obj) == 0)
            break;
        func_0216D480(obj);
        func_021ACBB8(func_021A2F98(w->f10), 1);
        func_021A2F48(w->f10, 4);
        w->state++;
    case 4:
        if (func_021A2F54(w->f10) == 1) {
            func_021A35A0((u32 *)w->f10, 1);
            w->f4 = 1;
            w->state++;
        }
        break;
    case 5:
        break;
    }
}





void func_021C1228(u32 a, u16 b, u32 c, u32 d)
{
    u8 *r;
    void *r7;
    Vec3 va;
    Vec3 vb;
    int out;

    r = func_02030734((u16)(0x8000 | (d & 0x7fff)), 0x4c, 1, (const char *)&d_021DE3AC, 0x2b3);
    ((struct Obj03610 *)r)->f4 = b;
    ((struct Obj03610 *)r)->f3C = a;
    ((struct Obj03610 *)r)->f40 = func_021A3068((u8 *)a);
    r7 = func_021A3074((void *)a);
    func_0216D88C(r7, (struct VecFx32 *)&va);
    vb = va;
    func_02164208(((struct Obj03610 *)r)->f4, (int *)(&vb), 0x20000);
    func_02163E58((u32)r7, &vb, &out);
    if (out > va.y)
        ((struct Obj03610 *)r)->f0 = 1;
    ((struct Obj03610 *)r)->f44 = func_021A36E0((u8 *)(((struct Obj03610 *)r)->f3C));
    func_02030DA8(func_02188D30((u8 *)(((struct Obj03610 *)r)->f40)), func_021C1988, (u32 *)r, 0);
}





int func_021C12C4(void *a)
{
return ((struct Obj18276 *)((u8 *)(func_02030EE8((struct S02030EE8 *)a))))->f6;
}





void func_021C12D0(void *h)
{
    func_020307B0((void *)func_02030EE8(h));
    func_02030EAC((u32)h);
}





/*
 * Offsets a position by (0, 1.0, 5.0) fx32 and applies it.
 */
void func_021C12E4(u32 a, const V3 *v)
{
    V3 t = *v;

    t.y += 0x1000;
    t.z += 0x5000;
    func_0216D8E0(a, &t);
}




int func_021C1318(u8 *p)
{
    u32 k;
    void *o;
    u32 r6;
    u32 r7;
    Vec3 v;
    Vec3 b;
    Vec3 c;
    Vec3 a;
    int n;

    o = func_021A3074(((struct Obj01665 *)p)->f3C);
    k = 1;
    func_0216DB4C(o, 1);
    func_0216D88C(o, (struct VecFx32 *)&v);
    a = v;
    b = a;
    c = a;
    func_02164208(((struct Obj01665 *)p)->f4, (int *)(&b), 0x10000);
    func_02164208(((struct Obj01665 *)p)->f4, (int *)(&c), 0x20000);
    func_02164280((s16)((b.x >> 4) / 0x1000), (s16)((b.z >> 4) / 0x1000), (int *)(&b));
    func_02164280((s16)((c.x >> 4) / 0x1000), (s16)((c.z >> 4) / 0x1000), (int *)(p + 0x24));
    *(Vec3 *)(p + 0x24) = c;
    func_02163E58((u32)o, &c, (int *)(p + 0x28));
    ((struct Obj01665 *)p)->f30 = (b.x - v.x) / 2 / 16;
    ((struct Obj01665 *)p)->f38 = (b.z - v.z) / 2 / 16;
    ((struct Obj01665 *)p)->f34 = 0x6000;
    ((struct Obj01665 *)p)->f1C = 0x1000;
    r6 = func_021A2F98((u8 *)(*(u32 *)&((struct Obj01665 *)p)->f3C));
    func_021ACBB8(r6, 2);
    if ((u16)(((struct Obj01665 *)p)->f4 + 0xfffe) <= 1)
        k = 3;
    r7 = func_02188CD0((u8 *)(((struct Obj01665 *)p)->f40));
    n = 9;
    func_021ABE30(r7, &n, 1);
    ((struct Obj01665 *)p)->f48 = func_021AD564(r7, k, r6);
    func_021C6B18(((struct Obj01665 *)p)->f40, 0x10, 0x20000);
    func_020061E4(0x6e0);
    ((struct Obj01665 *)p)->f2 = ((struct Obj01665 *)p)->f2 + 1;
    return 1;
}




int func_021C146C(u8 *p)
{
    Vec3 v;
    void *r4;
    u32 r6;

    r4 = func_021A3074(((struct Obj01359 *)p)->f3C);
    func_0216D88C(r4, (struct VecFx32 *)&v);
    v.x += ((struct Obj01359 *)p)->f30;
    v.z += ((struct Obj01359 *)p)->f38;
    func_0216D89C((u32)r4, &v);
    ((struct Obj01359 *)p)->f1C = -((struct Obj01359 *)p)->f1C;
    ((struct Obj01359 *)p)->f8 += 1;
    if (((struct Obj01359 *)p)->f8 >= 0x10) {
        ((struct Obj01359 *)p)->f8 = 0;
        ((struct Obj01359 *)p)->f1C = 0;
        ((struct Obj01359 *)p)->f2 = ((struct Obj01359 *)p)->f2 + 1;
        func_021AC154(((struct Obj01359 *)p)->f48);
        r6 = func_021A2F98((u8 *)(*(u32 *)&((struct Obj01359 *)p)->f3C));
        {
            u32 k = 2;
            if ((u16)(((struct Obj01359 *)p)->f4 + 0xfffe) <= 1)
                k = 2;
            ((struct Obj01359 *)p)->f48 = func_021AD564(func_02188CD0((u8 *)(((struct Obj01359 *)p)->f40)), k, r6);
        }
    }
    func_021C12E4((u32)r4, (const V3 *)(p + 0x18));
    return 0;
}




int func_021C14F8(u8 *p)
{
    Vec3 v;
    void *r4;

    r4 = func_021A3074(((struct Obj01506 *)p)->f3C);
    func_0216D88C(r4, (struct VecFx32 *)&v);
    v.y += ((struct Obj01506 *)p)->f34;
    if (v.y >= ((struct Obj01506 *)p)->f28) {
        v.y = ((struct Obj01506 *)p)->f28;
        ((struct Obj01506 *)p)->f2 = ((struct Obj01506 *)p)->f2 + 1;
        ((struct Obj01506 *)p)->f30 = (((struct Obj01506 *)p)->f24 - v.x) / 16;
        ((struct Obj01506 *)p)->f38 = (((struct Obj01506 *)p)->f2C - v.z) / 16;
        ((struct Obj01506 *)p)->f10 = -0x8000;
        ((struct Obj01506 *)p)->f34 = 0x6000;
        ((struct Obj01506 *)p)->f10 = func_0209C0A4(-0x8000, 0xb);
        func_021C6B18(((struct Obj01506 *)p)->f40, 0x10, (u32)-0x8000 << 2);
        func_021AC154(((struct Obj01506 *)p)->f48);
    }
    func_0216D89C((u32)r4, &v);
    return 0;
}



int func_021C157C(u8 *p)
{
    Vec3 v;
    void *r4;

    r4 = func_021A3074(((struct Obj00657 *)p)->f3C);
    func_0216D88C(r4, (struct VecFx32 *)&v);
    if (v.x < ((struct Obj00657 *)p)->f24) {
        v.x += ((struct Obj00657 *)p)->f30;
        if (v.x > ((struct Obj00657 *)p)->f24)
            v.x = ((struct Obj00657 *)p)->f24;
    } else {
        v.x += ((struct Obj00657 *)p)->f30;
        if (v.x < ((struct Obj00657 *)p)->f24)
            v.x = ((struct Obj00657 *)p)->f24;
    }
    if (v.z < ((struct Obj00657 *)p)->f2C) {
        v.z += ((struct Obj00657 *)p)->f38;
        if (v.z > ((struct Obj00657 *)p)->f2C)
            v.z = ((struct Obj00657 *)p)->f2C;
    } else {
        v.z += ((struct Obj00657 *)p)->f38;
        if (v.z < ((struct Obj00657 *)p)->f2C)
            v.z = ((struct Obj00657 *)p)->f2C;
    }
    v.y += ((struct Obj00657 *)p)->f34;
    ((struct Obj00657 *)p)->f34 += ((struct Obj00657 *)p)->f10;
    ((struct Obj00657 *)p)->f8 += 1;
    if (((struct Obj00657 *)p)->f8 >= 0x10) {
        v = *(Vec3 *)(p + 0x24);
        ((struct Obj00657 *)p)->f18 = 0;
        ((struct Obj00657 *)p)->f1C = 0;
        ((struct Obj00657 *)p)->f20 = 0;
        ((struct Obj00657 *)p)->f2 = ((struct Obj00657 *)p)->f2 + 1;
    }
    func_0216D89C((u32)r4, &v);
    func_021C12E4((u32)r4, (const V3 *)(p + 0x18));
    return 0;
}



int func_021C161C(u8 *p)
{
    void *r5;

    r5 = func_021A3074(((struct Obj04270 *)p)->f3C);
    func_0216DB4C(r5, 0);
    func_0216E014(r5, (int *)(p + 0x24), ((struct Obj04270 *)p)->f4);
    r5 = (void *)func_021A2F98((u8 *)(*(u32 *)&((struct Obj04270 *)p)->f3C));
    func_021ACBB8((u32)r5, 1);
    ((struct Obj04270 *)p)->f48 = func_021AD564(func_02188CD0((u8 *)(((struct Obj04270 *)p)->f40)), 0, (u32)r5);
    func_020061E4(0x6e2);
    ((struct Obj04270 *)p)->f2 = ((struct Obj04270 *)p)->f2 + 1;
    return 0;
}



int func_021C1670(u8 *p)
{
    u32 o;

    if (((struct Obj04271 *)p)->f48 != 0 && func_021AD5CC(((struct Obj04271 *)p)->f48) == 1) {
        o = func_02188CD0((u8 *)(((struct Obj04271 *)p)->f40));
        func_021AC154(((struct Obj04271 *)p)->f48);
        func_021ABE64(o, 9);
        func_021A35A0((u32 *)(((struct Obj04271 *)p)->f3C), 1);
        ((struct Obj04271 *)p)->f48 = 0;
        ((struct Obj04271 *)p)->f6 = 1;
    }
    return 0;
}



void func_021C16AC(u8 *p)
{
    void *o;
    u32 k;
    void *r7;
    u32 t;
    Vec3 w;
    Vec3 v;
    Vec3 b;
    Vec3 c;
    Vec3 a;
    int n;

    o = func_021A3074(((struct Obj00129 *)p)->f3C);
    switch (((struct Obj00129 *)p)->f2) {
    case 0:
        k = 1;
        func_0216DB4C(o, 1);
        func_0216D88C(o, (struct VecFx32 *)&v);
        a = v;
        b = a;
        c = a;
        func_02164208(((struct Obj00129 *)p)->f4, (int *)(&b), 0x10000);
        func_02164208(((struct Obj00129 *)p)->f4, (int *)(&c), 0x20000);
        func_02164280((s16)((b.x >> 4) / 0x1000), (s16)((b.z >> 4) / 0x1000), (int *)(&b));
        func_02164208(((struct Obj00129 *)p)->f4, (int *)(&b), 0x4000);
        func_02164280((s16)((c.x >> 4) / 0x1000), (s16)((c.z >> 4) / 0x1000), (int *)(&c));
        *(Vec3 *)(p + 0x24) = c;
        func_02163E58((u32)o, &c, (int *)(p + 0x28));
        ((struct Obj00129 *)p)->f30 = (b.x - v.x) / 16;
        ((struct Obj00129 *)p)->f38 = (b.z - v.z) / 16;
        ((struct Obj00129 *)p)->f34 = -0x6000;
        ((struct Obj00129 *)p)->f1C = 0x1000;
        r7 = (void *)func_021A2F98((u8 *)(*(u32 *)&((struct Obj00129 *)p)->f3C));
        func_021ACBB8((u32)r7, 2);
        if ((u16)(((struct Obj00129 *)p)->f4 + 0xfffe) <= 1)
            k = 3;
        t = func_02188CD0((u8 *)(((struct Obj00129 *)p)->f40));
        n = 9;
        func_021ABE30(t, &n, 1);
        ((struct Obj00129 *)p)->f48 = func_021AD564(t, k, (u32)r7);
        func_021C6B18(((struct Obj00129 *)p)->f40, 0x10, 0x20000);
        func_020061E4(0x6e1);
        ((struct Obj00129 *)p)->f2 = ((struct Obj00129 *)p)->f2 + 1;
    case 1:
        func_0216D88C(o, (struct VecFx32 *)&w);
        w.x += ((struct Obj00129 *)p)->f30;
        w.z += ((struct Obj00129 *)p)->f38;
        func_0216D89C((u32)o, &w);
        ((struct Obj00129 *)p)->f1C = -((struct Obj00129 *)p)->f1C;
        ((struct Obj00129 *)p)->f8 += 1;
        if (((struct Obj00129 *)p)->f8 >= 0x10) {
            ((struct Obj00129 *)p)->f8 = 0;
            ((struct Obj00129 *)p)->f1C = 0;
            ((struct Obj00129 *)p)->f2 = ((struct Obj00129 *)p)->f2 + 1;
            func_021AC154(((struct Obj00129 *)p)->f48);
            r7 = (void *)func_021A2F98((u8 *)(*(u32 *)&((struct Obj00129 *)p)->f3C));
            {
                u32 k2 = 2;
                if ((u16)(((struct Obj00129 *)p)->f4 + 0xfffe) <= 1)
                    k2 = 2;
                ((struct Obj00129 *)p)->f48 = func_021AD564(func_02188CD0((u8 *)(((struct Obj00129 *)p)->f40)), k2, (u32)r7);
            }
        }
        func_021C12E4((u32)o, (const V3 *)(p + 0x18));
        break;
    case 2:
        func_0216D88C(o, (struct VecFx32 *)&w);
        w.y += ((struct Obj00129 *)p)->f34;
        if (w.y <= ((struct Obj00129 *)p)->f28) {
            w.y = ((struct Obj00129 *)p)->f28;
            ((struct Obj00129 *)p)->f2 = ((struct Obj00129 *)p)->f2 + 1;
            ((struct Obj00129 *)p)->f30 = (((struct Obj00129 *)p)->f24 - w.x) / 16;
            ((struct Obj00129 *)p)->f38 = (((struct Obj00129 *)p)->f2C - w.z) / 16;
            func_021C6B18(((struct Obj00129 *)p)->f40, 0x10, -0x20000);
            func_021AC154(((struct Obj00129 *)p)->f48);
            r7 = (void *)func_021A2F98((u8 *)(*(u32 *)&((struct Obj00129 *)p)->f3C));
            func_021ACBB8((u32)r7, 1);
            ((struct Obj00129 *)p)->f48 = func_021AD564(func_02188CD0((u8 *)(((struct Obj00129 *)p)->f40)), 0, (u32)r7);
        }
        func_0216D89C((u32)o, &w);
        break;
    case 3:
        func_0216D88C(o, (struct VecFx32 *)&w);
        w.x += ((struct Obj00129 *)p)->f30;
        w.z += ((struct Obj00129 *)p)->f38;
        func_0216D89C((u32)o, &w);
        ((struct Obj00129 *)p)->f8 += 1;
        if (((struct Obj00129 *)p)->f8 >= 0x10) {
            t = func_02188CD0((u8 *)(((struct Obj00129 *)p)->f40));
            func_0216DB4C(o, 0);
            func_0216E014(o, (int *)(p + 0x24), ((struct Obj00129 *)p)->f4);
            func_021AC154(((struct Obj00129 *)p)->f48);
            func_021ABE64(t, 9);
            func_021A35A0((u32 *)(*(u32 *)&((struct Obj00129 *)p)->f3C), 1);
            ((struct Obj00129 *)p)->f48 = 0;
            ((struct Obj00129 *)p)->f6 = 1;
            func_020061E4(0x6e2);
            ((struct Obj00129 *)p)->f2 = ((struct Obj00129 *)p)->f2 + 1;
        }
        break;
    }
}
