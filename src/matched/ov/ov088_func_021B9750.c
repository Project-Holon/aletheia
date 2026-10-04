/*
 * function: func_021B9750
 * address:  0x021B9750
 * packet:   pkt_ov088_021B9750
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B98BC  0x021B98BC  thumb  ov088
 *   func_021B9910  0x021B9910  thumb  ov088
 *   func_021B997C  0x021B997C  thumb  ov088
 *   func_021B9A1C  0x021B9A1C  thumb  ov088
 *   func_021B9C2C  0x021B9C2C  thumb  ov088
 *   func_021B9EC4  0x021B9EC4  thumb  ov088
 *   func_021B9928  0x021B9928  thumb  ov088
 *   func_021B965C  0x021B965C  thumb  ov088
 *   func_021B95CC  0x021B95CC  thumb  ov088
 *   func_021B9F70  0x021B9F70  thumb  ov088
 *   func_021B9E54  0x021B9E54  thumb  ov088
 *   func_021B9C08  0x021B9C08  thumb  ov088
 *   func_021B99EC  0x021B99EC  thumb  ov088
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_02005DAC  0x02005DAC  thumb
 *   func_02006BD0  0x02006BD0  thumb
 *   func_02005E30  0x02005E30  thumb
 *   func_02005E50  0x02005E50  thumb
 *   func_02005D28  0x02005D28  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021B98BC(void);
extern void func_021B9910(void);
extern void func_021B997C(void *p, int heap);
extern void func_021B9A1C(void *p, int heap);
extern void func_021B9C2C(void *p, int heap);
extern void func_021B9EC4(void *p, int heap);
extern void func_021B9928(void *p);
typedef signed int     s32;
extern void func_021B965C(char *p);
extern void func_021B95CC(char *p);
extern void func_021B9F70(void *p);
extern void func_021B9E54(void *p);
extern void func_021B9C08(void *p);
extern void func_021B99EC(void *p);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int  func_0204E804(void);
extern void func_02005DAC(void *arg);
extern u32  func_02006BD0(u32 a);
extern void func_02005E30(u32 a);
extern int  func_02005E50(void);
extern void func_02005D28(void);

int func_021B9750(int a0, int a1, int a2, char *p)
{
    switch (*(u16 *)p) {
    case 0:
        func_021B98BC();
        func_021B9910();
        *(u16 *)p = 1;
        break;
    case 1:
        func_021B997C(p + 8, *(u16 *)(p + 2));
        func_021B9A1C(p + 0x14, *(u16 *)(p + 2));
        func_021B9C2C(p + 0x40, *(u16 *)(p + 2));
        func_021B9EC4(p + 0x54, *(u16 *)(p + 2));
        func_0204E720(3, 0x10, 0, 2);
        *(u32 *)(p + 0x8C) = 0;
        *(u16 *)p = 2;
        func_02005DAC((void *)0x3EF);
        break;
    case 2:
        if (func_0204E804() == 0) {
            *(u16 *)p = 3;
        }
        func_021B9928(p);
        break;
    case 3:
        func_021B9928(p);
        func_021B965C(p);
        func_021B95CC(p);
        break;
    case 4:
        if (func_02006BD0(*(u32 *)(p + 0x90)) == 0) {
            *(u16 *)p = 5;
        }
        func_021B9928(p);
        break;
    case 5:
        func_0204E720(3, 0, 0x10, 2);
        *(u16 *)p = 6;
        func_021B9928(p);
        func_02005E30(0x10);
        break;
    case 6:
        if (func_0204E804() == 0 && func_02005E50() == 0) {
            func_02005D28();
            *(u16 *)p = 7;
        }
        func_021B9928(p);
        break;
    case 7:
        func_021B9F70(p + 0x54);
        func_021B9E54(p + 0x40);
        func_021B9C08(p + 0x14);
        func_021B99EC(p + 8);
        return 1;
    case 8:
        return 1;
    }
    return 0;
}
