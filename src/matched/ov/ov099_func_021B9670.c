/*
 * function: func_021B9670
 * address:  0x021B9670
 * packet:   pkt_ov099_021B9670
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5F30  0x021C5F30  thumb  ov127
 *   func_021B9DB0  0x021B9DB0  thumb  ov099
 *   func_021BA648  0x021BA648  thumb  ov099
 *   func_021B9B80  0x021B9B80  thumb  ov099
 *   func_021B9D5C  0x021B9D5C  thumb  ov099
 *   func_021C48C0  0x021C48C0  thumb  ov127
 *   func_021C47E4  0x021C47E4  thumb  ov127
 *   func_021B9DD4  0x021B9DD4  thumb  ov099
 *   func_021B9E08  0x021B9E08  thumb  ov099
 *   MI_CpuFill8  0x02082BCC  arm
 */
#include "../include/Obj07938.h"

typedef unsigned char  u8;
extern void func_021C5F30(u8 *p);
extern void func_021B9DB0(char *p);
extern void func_021BA648(int unused, void *p);
extern void func_021B9B80(char *p);
extern void func_021B9D5C(char *p);
extern void func_021C48C0(u8 *p);
extern void func_021C47E4(u8 *p);
extern void func_021B9DD4(void *a);
extern void func_021B9E08(int);
extern void MI_CpuFill8(void *p, int v, int n);

void func_021B9670(char *p)
{
    func_021C5F30((u8 *)(((struct Obj07938 *)p)->f59C));
    func_021B9DB0(p);
    func_021BA648((int)p, p + 0x574);
    func_021B9B80(p);
    func_021B9D5C(p);
    func_021C48C0((u8 *)(((struct Obj07938 *)p)->f58C));
    func_021C47E4((u8 *)(((struct Obj07938 *)p)->f588));
    func_021B9DD4(p + 0x14);
    func_021B9E08(((struct Obj07938 *)p)->f10);
    MI_CpuFill8(p, 0, 0x5a0);
}
