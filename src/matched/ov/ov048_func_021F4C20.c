/*
 * function: func_021F4C20
 * address:  0x021F4C20
 * packet:   pkt_ov048_021F4C20
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_0218ED2C  0x0218ED2C  thumb  ov021
 *   func_0218ED40  0x0218ED40  thumb  ov021
 *   func_0218ED54  0x0218ED54  thumb  ov021
 *   func_0218ECC4  0x0218ECC4  thumb  ov021
 *   func_021F3790  0x021F3790  thumb  ov048
 *   func_021C6F00  0x021C6F00  thumb  ov021
 *   func_021C7058  0x021C7058  thumb  ov021
 *   func_021C701C  0x021C701C  thumb  ov021
 *   func_021C7AE4  0x021C7AE4  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x; int y; int z; } Vec;

typedef struct W {
    int f0;
    u32 f4;
    u16 h8;
    u16 hA;
    u16 hC;
    u16 hE;
    u32 f10;
    Vec v14;
} W;

extern void *func_02188C58(void *p);
extern u32 func_02188D38(u8 *p);
extern u16 func_0218ED2C(u8 *p);
extern u16 func_0218ED40(u8 *p);
extern u32 func_0218ED54(u8 *p);
extern void func_0218ECC4(u32 a, void *b);
extern u8 func_021F3790(char *p);
extern u32 func_021C6F00(u32 a, u16 b, u32 c);
extern u32 func_021C7058(u32 a, u16 b, u16 c);
extern u32 func_021C701C(u32 a, u16 b, u16 c);
extern u32 func_021C7AE4(u32 a, u16 b, void *c);
extern void func_021C6DE0(u8 *p, u32 a, u32 b);
extern int func_021C6E48(u32 a);
extern u32 func_020362DC(void);

int func_021F4C20(int a0, int *state, W *w)
{
    u32 cam;
    u32 obj;
    u32 h;
    u32 v;

    cam = w->f4;
    obj = (u32)func_02188C58((void *)cam);
    h = func_02188D38((u8 *)cam);
    switch (*state) {
    case 0:
        w->hA = func_0218ED2C((u8 *)obj);
        w->hC = func_0218ED40((u8 *)obj);
        w->f10 = func_0218ED54((u8 *)obj);
        func_0218ECC4(obj, &w->v14);
        (*state)++;
        break;
    case 1: {
        Vec vec;
        int ang1;
        int ang2;
        u32 dist;
        u32 r0;
        u32 r1;
        u32 r2;
        u32 r3;

        switch (func_021F3790((char *)cam)) {
        case 1:
        default:
            ang1 = 0xEE5;
            dist = 0x86000;
            ang2 = 0;
            vec.x = 0;
            vec.y = 0x1B000;
            vec.z = -0x6C000;
            break;
        case 3:
            ang1 = 0xEE5;
            dist = 0x86000;
            ang2 = 0x3FFF;
            vec.x = -0x6C000;
            vec.y = 0x1B000;
            vec.z = 0;
            break;
        }
        r0 = func_021C6F00(cam, w->h8, dist);
        r1 = func_021C7058(cam, w->h8, ang1);
        r2 = func_021C701C(cam, w->h8, ang2);
        r3 = func_021C7AE4(cam, w->h8, &vec);
        func_021C6DE0((u8 *)h, r0, 0);
        func_021C6DE0((u8 *)h, r1, 0);
        func_021C6DE0((u8 *)h, r2, 0);
        func_021C6DE0((u8 *)h, r3, 0);
        (*state)++;
        break;
    }
    case 2:
        if (func_021C6E48(h))
            (*state)++;
        break;
    case 3:
        v = func_020362DC();
        if ((v & 0x20) || (v & 0x10) || (v & 0x80) || (v & 2))
            (*state)++;
        break;
    case 4: {
        u32 r0;
        u32 r1;
        u32 r2;
        u32 r3;

        r0 = func_021C6F00(cam, w->h8, w->f10);
        r1 = func_021C7058(cam, w->h8, w->hA);
        r2 = func_021C701C(cam, w->h8, w->hC);
        r3 = func_021C7AE4(cam, w->h8, &w->v14);
        func_021C6DE0((u8 *)h, r0, 0);
        func_021C6DE0((u8 *)h, r1, 0);
        func_021C6DE0((u8 *)h, r2, 0);
        func_021C6DE0((u8 *)h, r3, 0);
        (*state)++;
        break;
    }
    case 5:
        if (func_021C6E48(h))
            (*state)++;
        break;
    case 6:
        return 1;
    }
    return 0;
}
