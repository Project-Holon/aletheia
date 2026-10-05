/*
 * function: func_0202AD44
 * address:  0x0202AD44
 * packet:   pkt_0202AD10
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned int u32;

extern int  func_0202AE08(void *obj);
extern int  func_0202AE34(void *obj);
extern int  func_0202AE68(void *obj);
extern int  func_0202AE04(void *obj);
extern int  func_0202AEBC(void *obj);
extern void func_0202ABFC(void *obj, u32 value);

void func_0202AD44(void *obj)
{
    int a = func_0202AE34(obj);
    int b = func_0202AE68(obj);

    if (a != 0 || b != 0) {
        func_0202AEBC(obj);
    }
    if (func_0202AE04(obj) <= 0) {
        func_0202ABFC(obj, 0);
    }
}
