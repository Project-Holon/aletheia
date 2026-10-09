/*
 * file:     weather_task_p04.c
 * unit:     yes
 * function: func_021A244C, func_021A2564, func_021A25BC, func_021A25CC, func_021A25DC, func_021A2604, func_021A2630, func_021A2638, func_021A2640, func_021A2654, func_021A26C4, func_021A26D8, func_021A2724, func_021A273C, func_021A274C, func_021A277C, func_021A27B8, func_021A27F8, func_021A282C, func_021A284C, func_021A2860, func_021A28A0
 * address:  0x021A244C
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
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_02048B30  0x02048B30  arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_0207CF3C  0x0207CF3C  arm
 *   func_021A2D30  0x021A2D30  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   g_02148B54  0x02148B54  data
 *   func_021A2C28  0x021A2C28  thumb  ov021
 *   func_0204B53C  0x0204B53C  arm
 *   func_0204B528  0x0204B528  arm
 *   func_021A2C30 0x021A2C30 thumb ov021
 *   func_021A2C6C  0x021A2C6C  thumb  ov021
 *   func_02005C64  0x02005C64  thumb
 *   func_02028A7C  0x02028A7C  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02028ACC  0x02028ACC  thumb
 *   func_020061F0  0x020061F0  thumb
 *   func_021A2C24 0x021A2C24 thumb ov021
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   func_02082BCC  0x02082BCC  arm
 *   data_021D88E8  0x021D88E8  data  a1
 *   func_021A2BC4  0x021A2BC4  thumb  ov021
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021A2978  0x021A2978  thumb  ov021
 *   func_021A29A8  0x021A29A8  thumb  ov021
 *   func_021A29F4  0x021A29F4  thumb  ov021
 *   func_021A2994  0x021A2994  thumb  ov021
 *   func_021A2A18  0x021A2A18  thumb  ov021
 *   func_021A2A68  0x021A2A68  thumb  ov021
 */
#include "../../matched/include/Obj00954.h"
#include "../../matched/include/Obj19740.h"
#include "../../matched/include/Obj18003.h"
#include "../../matched/include/Obj12714.h"
#include "../../matched/include/Obj12084.h"

struct Actor;
struct Pt_021A244C;
struct SoundSys2;
struct Obj_021A2564;
struct Vec2;
struct Obj_021A277C;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef signed int s32;

typedef s32 fx32;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32_021A244C;

typedef struct { short x, y; } Pt_021A244C;

typedef struct { char pad[0x774]; int *list; } Obj_021A2564;

typedef signed char s8;

struct PtS {
    s16 x;
    s16 y;
};

typedef short Pt_021A2654;

typedef struct {
    u8 pad[0x24];
    u8 lo : 4;
    u8 hi : 4;
} Obj021A2724;

typedef struct {
    u8 data[0x38];
} Slot021A274C;

typedef struct {
    u8 pad[0x74];
    Slot021A274C slots[0x20];
} Obj021A274C;

typedef struct Node021A277C {
    u32 pad0;
    u32 handle;
    u8 pad8[0x28];
    struct Node021A277C *prev;
    struct Node021A277C *next;
} Node021A277C;

typedef struct {
    u8 pad[0x774];
    Node021A277C *head;
    int count;
} Obj021A277C;

typedef struct Node021A27B8 {
    u32 pad0;
    u32 handle;
    u8 pad8[0x28];
    struct Node021A27B8 *prev;
    struct Node021A27B8 *next;
} Node021A27B8;

typedef struct {
    u8 pad[0x774];
    Node021A27B8 *head;
    int count;
} Obj021A27B8;

typedef struct Node021A27F8 {
    u32 pad0;
    u32 handle;
    u8 pad8[0x28];
    struct Node021A27F8 *prev;
    struct Node021A27F8 *next;
} Node021A27F8;

typedef struct {
    u8 pad[0x48];
    void (*cb)(Node021A27F8 *n);
} Ops021A27F8;

typedef struct {
    u8 pad[0x20];
    Ops021A27F8 *ops;
    u8 pad24[0x750];
    Node021A27F8 *head;
} Obj021A27F8;

typedef struct {
    char pad0[4];
    unsigned short count;
} Hdr;

typedef struct {
    char pad0[0x18];
    int *arr;
    int pad1c;
    Hdr *hdr;
    char pad24[4];
    char sub[4];
} Obj_021A277C;

typedef struct {
    u8 pad[4];
    u16 count;
} Info021A28A0;

typedef struct {
    u8 pad[0x18];
    u32 *items;
    u8 pad1C[4];
    Info021A28A0 *info;
    u8 pad24[4];
    u8 slots[1];
} Obj021A28A0;

extern void *func_0218EC2C(void);
extern void func_02048B30(void *cam, VecFx32_021A244C *out);
extern void func_02048AE8(void *cam, VecFx32_021A244C *out);
extern fx32 func_0207CF3C(const VecFx32_021A244C *a, const VecFx32_021A244C *b);
extern void func_021A2D30(void *p, fx32 dist, fx32 *w, fx32 *h);
extern u32 func_0207C768(u32 a, u32 b);
u32 func_021A2C28(u8 *p);
void func_0204B53C(const struct Actor *actor, struct Pt_021A244C *out);
void func_0204B528(struct Actor *actor, const struct Pt_021A244C *src);
extern void func_021A2C30(unsigned char *o, int a, int b);
extern void func_021A2C6C(u8 *p, u32 v);
int func_02005C64(void);
void func_02028A7C(struct SoundSys2 *s, u32 id);
void func_020061E4(u32 a);
void func_02028ACC(struct SoundSys2 *s, u32 id, u32 who);
void func_020061F0(u32 a, u32 b);
extern unsigned char *func_021A2C24(unsigned char *o);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
u32 func_0204B404(struct Obj_021A2564 *p, const struct Vec2 *delta, u32 which);
void func_02082BCC(void *p, int v, int n);
void func_0204B3DC(struct Obj_021A277C *h, unsigned int v);
extern void func_021A2978(u8 *p, u16 *q, u32 c, u32 a3);
extern u32 func_021A29A8(u32, u32, u32);
extern u32 func_021A2994(u32);
extern void func_021A29F4(u16 *p, u32 a1, u32 a2, u32 a3);
void func_021A2A18(void *a, int i, int v, void *p, int x);
void func_021A2A68(u8 *p, int i, int x);
void func_021A244C(u8 *o, s32 *outX, s32 *outY);
void func_021A2564(Obj_021A2564 *obj, int px, int py);
void func_021A25BC(unsigned char *o, int arg);
void func_021A25CC(u8 *p);
void func_021A25DC(u8 *p, int a);
void func_021A2604(u8 *p, int a, int b);
unsigned char *func_021A2630(unsigned char *o);
unsigned int func_021A2638(unsigned char *o);
void func_021A2640(u8 *a, struct PtS *b);
void func_021A2654(int obj, unsigned short *src);
int func_021A26C4(u32 a, u32 b);
void func_021A26D8(int *p);
int func_021A2724(Obj021A2724 *p, int (*cb)(Obj021A2724 *, int, int), int x);
u8 func_021A273C(u8 *p);
Slot021A274C *func_021A274C(Obj021A274C *p);
void func_021A277C(Obj021A277C *p, Node021A277C *n);
void func_021A27B8(Obj021A27B8 *p, Node021A27B8 *n);
void func_021A27F8(Obj021A27F8 *p);
int func_021A282C(u32 a, u32 b, u32 c, u32 d);
int func_021A284C(u32 a, u32 b, u32 c, u32 d);
void func_021A2860(Obj_021A277C *o, int x);
void func_021A28A0(Obj021A28A0 *p);
extern u8 g_02148B54[];
extern const u8 data_021D88E8[];







/*
 * func_0207C768 is FX_Div, func_0207CF3C VEC_Distance.
 *
 * Addresses are Black-image addresses.
 */
void func_021A244C(u8 *o, s32 *outX, s32 *outY)
{
    VecFx32_021A244C pos;
    VecFx32_021A244C tgt;
    fx32 w;
    fx32 h;
    fx32 dx;
    fx32 dz;
    fx32 sx;
    fx32 sy;
    void *cam;

    if (((struct Obj00954 *)o)->f14 == 0) {
        *outX = 0;
        *outY = 0;
        return;
    }
    cam = func_0218EC2C();
    func_02048B30(cam, &pos);
    func_02048AE8(cam, &tgt);
    dx = pos.x - ((VecFx32_021A244C *)(o + 0x68))->x;
    dz = pos.z - ((VecFx32_021A244C *)(o + 0x68))->z;
    if ((dx < 0 ? -dx : dx) > 0x3E8000 || (dz < 0 ? -dz : dz) > 0x64000) {
        *(VecFx32_021A244C *)(o + 0x68) = pos;
        *outX = 0;
        *outY = 0;
        return;
    }
    func_021A2D30(g_02148B54, func_0207CF3C(&pos, &tgt), &w, &h);
    w = func_0207C768(w, 0x100000);
    h = func_0207C768(h, 0xC0000);
    sx = 0x1000;
    if (dx < 0) {
        sx = -0x1000;
        dx = -dx;
    }
    dx = func_0207C768(dx, w);
    if (sx < 0) {
        dx = 0 - dx;
        dx += 0x1000;
    }
    sy = 0x1000;
    if (dz < 0) {
        sy = -0x1000;
        dz = -dz;
    }
    dz = func_0207C768(dz, h);
    if (sy < 0) {
        dz = 0 - dz;
        dz += 0x1000;
    }
    if (dx + dz != 0) {
        *(VecFx32_021A244C *)(o + 0x68) = pos;
    }
    *outX = dx >> 12;
    *outY = dz >> 12;
}








void func_021A2564(Obj_021A2564 *obj, int px, int py)
{
    int *p = obj->list;
    int h;
    int y;
    int x;
    Pt_021A244C pt;

    if (p != 0) {
        x = (short)px;
        y = (short)py;
        do {
            h = func_021A2C28((u8 *)((int)p));
            func_0204B53C((const struct Actor *)h, (struct Pt_021A244C *)(&pt));
            pt.x = pt.x - x;
            pt.y = pt.y - y;
            func_0204B528((struct Actor *)h, (const struct Pt_021A244C *)(&pt));
            p = (int *)p[0x34 / 4];
        } while (p != obj->list);
    }
}








/*
 * Unlabelled tail-call stub, filed for the ov026 lane.
 */
void func_021A25BC(unsigned char *o, int arg)
{
    func_021A2C30(o + 0x40, ((struct Obj19740 *)o)->fC, arg);
}








/*
 * Tail call with the object displaced by 0x40 and the word at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021A25CC(u8 *p)
{
    func_021A2C6C(p + 0x40, ((struct Obj18003 *)p)->fC);
}








void func_021A25DC(u8 *p, int a)
{
    if (func_02005C64() == 0) {
        if (((struct Obj00954 *)p)->f48 != 0)
            func_02028A7C((struct SoundSys2 *)(((struct Obj00954 *)p)->fC), a);
        else
            func_020061E4(a);
    }
}








void func_021A2604(u8 *p, int a, int b)
{
    if (func_02005C64() == 0) {
        if (((struct Obj12714 *)p)->f48 != 0)
            func_02028ACC((struct SoundSys2 *)(((struct Obj12714 *)p)->fC), a, b);
        else
            func_020061F0(a, b);
    }
}








unsigned char *func_021A2630(unsigned char *o)
{
    return func_021A2C24(o);
}








unsigned int func_021A2638(unsigned char *o)
{
    return func_021A2C28(o);
}






/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_021A2640(u8 *a, struct PtS *b)
{
    func_0204B454((struct Actor *)func_021A2C28(a), b, 0);
}





void func_021A2654(int obj, unsigned short *src)
{
    Pt_021A2654 pt[2];

    pt[0] = src[0];
    pt[1] = src[1];
    if (pt[0] > 320) {
        pt[0] = pt[0] % 320;
    } else if (pt[0] < -64) {
        pt[0] = pt[0] + 320;
    }
    if (pt[1] > 256) {
        Pt_021A2654 *py;
        py = &pt[1];
        *py = *py % 256;
    } else if (pt[1] < -64) {
        pt[1] = pt[1] + 256;
    }
    func_0204B404((struct Obj_021A2564 *)func_021A2C28((u8 *)obj), (const struct Vec2 *)pt, 0);
}




int func_021A26C4(u32 a, u32 b)
{
return func_0204B404((struct Obj_021A2564 *)(func_021A2C28((u8 *)a)), (const struct Vec2 *)b, 0);
}




void func_021A26D8(int *p)
{
    int f0;
    int f4;
    int f10;
    int f8;
    int f18;
    int f14;
    int fc;
    unsigned short h;

    f0 = p[0];
    f4 = p[1];
    f14 = p[5];
    f10 = p[4];
    fc = p[3];
    f8 = p[2];
    h = *(unsigned short *)&p[7];
    f18 = p[6];
    func_02082BCC(p, 0, 0x784);
    p[5] = f14;
    p[0] = f0;
    p[3] = fc;
    p[1] = f4;
    *(unsigned short *)&p[7] = h;
    p[2] = f8;
    p[6] = f18;
    p[4] = f10;
}




int func_021A2724(Obj021A2724 *p, int (*cb)(Obj021A2724 *, int, int), int x)
{
    if (cb != 0)
        return cb(p, p->lo, x);
    return 1;
}




u8 func_021A273C(u8 *p)
{
    return data_021D88E8[p[0x26]];
}




Slot021A274C *func_021A274C(Obj021A274C *p)
{
    int i;
    for (i = 0; i < 0x20; i++) {
        if (func_021A2BC4((Slot021A274C *)((u8 *)p + 0x74) + i) == 0) {
            p = (Obj021A274C *)((u8 *)p + 0x74);
            return (Slot021A274C *)p + i;
        }
    }
    return 0;
}



void func_021A277C(Obj021A277C *p, Node021A277C *n)
{
    Node021A277C *tail;

    p->count++;
    if (p->head == 0) {
        p->head = n;
        n->next = n;
        p->head->prev = n;
        return;
    }
    tail = p->head->prev;
    n->prev = tail;
    n->next = tail->next;
    tail->next->prev = n;
    tail->next = n;
    func_0204B3DC((struct Obj_021A277C *)n->handle, 1);
}



void func_021A27B8(Obj021A27B8 *p, Node021A27B8 *n)
{
    p->count--;
    if (p->head == n) {
        if (n->next == n)
            p->head = 0;
        else
            p->head = n->next;
    }
    n->next->prev = n->prev;
    n->prev->next = n->next;
    n->next = 0;
    n->prev = 0;
    func_0204B3DC((struct Obj_021A277C *)n->handle, 0);
}



void func_021A27F8(Obj021A27F8 *p)
{
    Node021A27F8 *cur = p->head;
    Node021A27F8 *nx;

    if (cur != 0 && p->ops->cb != 0) {
        nx = cur->next;
        do {
            p->ops->cb(cur);
            cur = nx;
            nx = nx->next;
        } while (cur != p->head && p->head != 0);
    }
}



/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A282C(u32 a, u32 b, u32 c, u32 d)
{
func_021A2978((u8 *)(a + 40), (u16 *)(((struct Obj12084 *)((u8 *)(a)))->f20), b, d);
return func_021A29A8((a + 40), ((struct Obj12084 *)((u8 *)(a)))->f20, b);
}



int func_021A284C(u32 a, u32 b, u32 c, u32 d)
{
func_021A29F4((u16 *)(a + 40), b, c, d);
return func_021A2994((a + 40));
}



void func_021A2860(Obj_021A277C *o, int x)
{
    int i;

    for (i = 0; i < o->hdr->count; i++) {
        func_021A2A18(o->sub, i, o->arr[i], (char *)o->hdr + 0xe + i * 12, x);
    }
}



void func_021A28A0(Obj021A28A0 *p)
{
    int i;

    for (i = 0; i < p->info->count; i++)
        func_021A2A68(p->slots, i, p->items[i]);
}
