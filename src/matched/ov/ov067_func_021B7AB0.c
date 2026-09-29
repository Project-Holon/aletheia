/*
 * function: func_021B7AB0
 * address:  0x021B7AB0
 * packet:   pkt_ov067_021B7AB0
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02035CB8  0x02035CB8  arm
 *   func_021B806C  0x021B806C  thumb  ov067
 *   func_021B8460  0x021B8460  thumb  ov067
 *   func_021B8B74  0x021B8B74  thumb  ov067
 *   func_021B8C4C  0x021B8C4C  thumb  ov067
 *   func_020355C4  0x020355C4  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0202EA40  0x0202EA40  thumb
 *   func_021B9344  0x021B9344  thumb  ov067
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct S {
    u8 pad00[0x30];
    void *f30;
    u8 pad34[0x4e - 0x34];
    u16 f4e;
    u8 pad50[0x54 - 0x50];
    int f54;
    int f58;
    s16 f5c;
    u8 pad5e[0x86 - 0x5e];
    u8 f86_lo : 5;
    u8 f86_b5 : 1;
    u8 f86_hi : 2;
    u8 pad87[0x96 - 0x87];
    u8 f96;
} S;

extern int func_02035CB8(int *a, int *b);
extern int func_021B806C(S *p);
extern int func_021B8460(S *p);
extern int func_021B8B74(S *p);
extern int func_021B8C4C(S *p);
extern int func_020355C4(void);
extern u32 func_020362DC(void);
extern void func_0202EA40(void *p);
extern void func_021B9344(S *p);

int func_021B7AB0(S *p)
{
    int buf;
    int ret = -1;

    if (func_02035CB8(&buf, &p->f54) == 0) {
        p->f54 = -1;
        p->f86_b5 = 0;
    }
    switch (p->f4e) {
    case 0:
        ret = func_021B806C(p);
        break;
    case 1:
        if (func_021B8460(p) == 1)
            ret = -10;
        break;
    case 2:
        if (func_021B8B74(p) == 1)
            ret = -9;
        break;
    case 3:
        if (func_021B8C4C(p) == 1)
            ret = -8;
        break;
    case 4:
        if (func_020355C4() == 0 && (func_020362DC() & 1))
            ret = p->f5c;
        if (p->f96 == 0)
            p->f4e = 0;
        else
            p->f96--;
        break;
    }
    p->f58 = p->f54;
    func_0202EA40(p->f30);
    func_021B9344(p);
    return ret;
}
