/*
 * function: func_021B98F8
 * address: 0x021B98F8
 * packet: pkt_ov114_021B98F8
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_021B95A0 0x021B95A0 thumb ov114
 * func_021B95B0 0x021B95B0 thumb ov114
 * func_021B95C0 0x021B95C0 thumb ov114
 * d_021CE2D4 0x021CE2D4 data a4
 * d_021CE284 0x021CE284 data a4
 * d_021CE280 0x021CE280 data a4
 * func_021BE648 0x021BE648 arm ov114
 * func_021BF04C 0x021BF04C arm ov114
 * func_021BE6AC 0x021BE6AC arm ov114
 * func_021BE9C8 0x021BE9C8 arm ov114
 * func_021BE79C 0x021BE79C arm ov114
 * func_02034714 0x02034714 arm
 * MI_CpuFill8 0x02082BCC arm
 * func_0208CADC 0x0208CADC arm
 */
#include "../include/Obj10329.h"
#include "../include/G_Pair.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern char d_021CE2D4[], d_021CE280[];
extern unsigned int func_021B95A0(unsigned int, unsigned int);
extern void func_021B95B0(int);
extern int func_021B95C0(int, int, unsigned int *);
extern struct Pair d_021CE284;
extern int func_021BE648(int a, int b, int c);
extern void *func_021BF04C(char *url_p, int method, char *buf_p, u32 len, int (*callback)(void *, int, void *), void *userParam_p);
extern u32 func_021BE6AC(void);
extern int func_021BE9C8(int a, int b, int c);
extern int func_021BE79C(void *handle, void *value_p, unsigned long length);
extern void func_02034714(const char *, u32, const char *);
extern void MI_CpuFill8(int, int, int);
extern char *func_0208CADC(char *, const char *);
int func_021B98F8(u8 *p)
{
    int h;
    if (p == 0) return 0;
    if (func_021BE648((int)func_021B95A0, (int)func_021B95B0, 12) != 0) {
        func_02034714(d_021CE2D4, 0, d_021CE2D4);
        return 0;
    }
    MI_CpuFill8((int)(p+0x410), 0, 4);
    func_0208CADC((char *)(p+0x410), (char *)((u32 *)&d_021CE284)[14]);
    h = (int)func_021BF04C((char *)((u32 *)&d_021CE284)[14], ((u32 *)&d_021CE284)[15], (char *)(p+0x10), 0x400, (int (*)(void *, int,  void *))func_021B95C0, 0);
    if (h == 0) {
        func_021BE6AC();
        if (h == 0) func_02034714(d_021CE2D4, 0, d_021CE2D4);
        return 0;
    }
    ((struct Obj10329 *)p)->fC = h;
    if (func_021BE9C8(h, (int)d_021CE280, 1) < 0) {
        func_02034714(d_021CE2D4, 0, d_021CE2D4);
        return 0;
    }
    func_021BE79C((void *)h, (void *)(((struct Obj10329 *)p)->f0), ((struct Obj10329 *)p)->f4);
    return 1;
}
