/*
 * function: func_021B9F94
 * address:  0x021B9F94
 * packet:   pkt_ov088_021B9F94
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020070A4  0x020070A4  thumb
 *   func_02008730  0x02008730  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_02009210  0x02009210  thumb
 *   func_02012FE4  0x02012FE4  thumb
 */

extern void func_0203064C(unsigned int, unsigned int, unsigned int);
typedef unsigned int   u32;
struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *, int, int);
struct Sub02007084Ctrl;
struct Sub0200852CObj;
struct Sub02009210Obj;
extern struct Sub02007084Ctrl *func_020070A4(void);
extern struct Sub0200852CObj *func_02008730(void *sys);
extern void *func_0200C0F0(void *sys);
extern struct Sub02009210Obj *func_02009210(void *sys);
struct Sub020071CCCtrl;
extern void *func_02012FE4(struct Sub020071CCCtrl *a0);

int func_021B9F94(struct Obj0203159C *a)
{
    int *p;
    func_0203064C(1, 0xb, 0x80000);
    p = func_0203159C(a, 0x150, 0xb);
    func_02082BCC(p, 0, 0x150);
    p[0] = (int)func_020070A4();
    p[1] = (int)func_02008730((void *)p[0]);
    p[2] = (int)func_0200C0F0((void *)p[0]);
    p[3] = (int)func_02009210((void *)p[0]);
    p[4] = (int)func_02012FE4((struct Sub020071CCCtrl *)p[0]);
    return 1;
}
