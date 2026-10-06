/*
 * function: func_021B2F18
 * address:  0x021B2F18
 * packet:   pkt_ov021_021B2F18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B2F18 0x021B2F18 thumb
 *   func_02043658 0x02043658 arm
 *   func_02188DA0 0x02188DA0 thumb ov021
 *   func_02043534 0x02043534 arm
 *   func_02188DB0 0x02188DB0 thumb ov021
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_02189A1C 0x02189A1C thumb ov021
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 */

extern unsigned int func_02043658(void);
extern void func_02188DA0(void);
extern void func_02043534(unsigned int planes);
typedef unsigned char  u8;
struct Node;
extern void func_02188DB0(u8 *a);
typedef signed int     s32;
typedef unsigned int   u32;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void func_02189A1C(u8 *p, u32 v);
extern void func_02030EAC(struct Node *n);
extern u32 func_020307B0(void *p);

void func_021B2F18(int p, int *q)
{
    int x;
    int y;
    int z;
    int w;
    int c;
    void *t;

    switch (q[5]) {
    case 0:
        if ((unsigned int)q[4] <= 1) {
            x = -1;
        } else {
            x = 4;
        }
        if (q[4] == 0 || q[4] == 2) {
            y = 16;
            z = 0;
            t = (void *)func_02043658();
            func_02188DA0();
            func_02043534((unsigned int)t);
            func_02188DB0((u8 *)q[1]);
        } else {
            y = 0;
            z = 16;
        }
        if (q[2] == 0) {
            w = 3;
        } else {
            w = 12;
        }
        func_0204E720(w, y, z, x);
        q[5] = q[5] + 1;
        break;
    case 1:
        c = 0;
        if (q[3] == 1) {
            c = 1;
        }
        if (func_0204E804() == 0) {
            c = 1;
        }
        if (c) {
            func_02189A1C((u8 *)q[1], 0);
            func_02030EAC((struct Node *)p);
            func_020307B0(q);
        }
        break;
    }
}
