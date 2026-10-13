/*
 * function: func_021F3DFC
 * address:  0x021F3DFC
 * packet:   pkt_ov038_021F3DFC
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     same enum-k spelling as ov038_func_021F3F40 (k = (u8)(k + 1)
 *           on an enum local, int fourth parameter on the 0x021BE6xx calls).
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   func_02197DA0  0x02197DA0  thumb  ov021
 *   func_02197DAC  0x02197DAC  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 */
#include "../include/Obj00881.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { K_0 } KType;

typedef struct {
    int x;
    int y;
    int z;
} V3;

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *p, int idx);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021BE4B4(char *p, int i, int j, int v);
extern void func_021BE700(void *p, int i, int j, int k, int flag);
extern void func_021BE6CC(int p, int i, int j, int k, int flag);
extern void func_020061E4(u32 se);
extern void GFL_USE_StopAllSe(void);
extern int func_02197DA0(u32 a);
extern void func_02197DAC(void *a);
struct VecFx32;
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_021A3044(u8 *p, void *v);

int func_021F3DFC(int a0, int *a1)
{
    void *sys;
    int h;
    u8 *s;
    void *q;
    u8 c;
    KType k;
    int done;
    int d;
    V3 v;

    sys = func_0201210C(func_020124E4((void *)a0));
    h = func_02188D2C(sys);
    s = (u8 *)func_021897BC(sys, 1);
    q = func_02188CB4(sys);
    k = 0;
    c = s[3] + 0x19;
    if (s[6] == 1)
        k = (u8)(k + 1);
    switch (*a1) {
    case 0:
        GFL_USE_StopAllSe();
        *a1 = *a1 + 1;
    case 1:
        if (((struct Obj00881 *)s)->f14 != 0) {
            if (func_02197DA0(((struct Obj00881 *)s)->f14) == 1) {
                func_02197DAC((void *)(((struct Obj00881 *)s)->f14));
                ((struct Obj00881 *)s)->f14 = 0;
                s[5] = 0;
                *a1 = *a1 + 1;
            }
        } else {
            s[5] = 0;
            *a1 = *a1 + 1;
        }
        if (*a1 == 2)
            ((struct Obj00881 *)s)->f20 = 0;
        break;
    case 2:
        func_021A3038(q, (struct VecFx32 *)&v);
        done = 0;
        s[5]++;
        if (s[6] == 0) {
            v.z += s[5] << 12;
            if (v.z >= ((struct Obj00881 *)s)->f10) {
                v.z = ((struct Obj00881 *)s)->f10;
                done = 1;
            }
            d = (((struct Obj00881 *)s)->f10 - v.z) / 2;
        } else {
            v.z += -s[5] << 12;
            if (v.z <= ((struct Obj00881 *)s)->f10) {
                v.z = ((struct Obj00881 *)s)->f10;
                done = 1;
            }
            d = (v.z - ((struct Obj00881 *)s)->f10) / 2;
        }
        if (((struct Obj00881 *)s)->f20 == 0 && d != 0) {
            func_020061E4(0x6C4);
            ((struct Obj00881 *)s)->f20 = 1;
        }
        func_021BE6CC(h, 0, 0x22, k, d);
        func_021A3044(q, &v);
        if (done) {
            func_021BE700((void *)h, 0, 0x22, k, 0);
            func_021BE4B4((char *)h, 0, 0x22, 1);
            func_021BE4B4((char *)h, 0, c, 0);
            return 1;
        }
        break;
    }
    return 0;
}
