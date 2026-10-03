/*
 * function: func_021643E8
 * address:  0x021643E8
 * packet:   pkt_ov010_021643E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Per-object setup: registers the object with the frame list, applies
 * the flag word and seeds the 177-entry table pass.
 *
 * symbols:
 *   func_02012B38  0x02012B38  thumb
 *   func_02013F6C  0x02013F6C  thumb
 *   func_02014464  0x02014464  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   func_0215E428  0x0215E428  thumb ov010
 *   func_0215E364  0x0215E364  thumb ov010
 *   func_0201296C  0x0201296C  thumb
 *   func_0201433C  0x0201433C  thumb
 *   func_02164728  0x02164728  thumb ov010
 *   func_02013FFC  0x02013FFC  thumb
 *   func_02008854  0x02008854  thumb
 *   func_02008988  0x02008988  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Big;
struct BigObj;
struct Sub02008828Obj;
struct Sub02014444Obj;
extern void *func_02012B38(const struct BigObj *p);
extern u32   func_02013F6C(void *a);
extern void func_02014464(struct Sub02014444Obj *o, u8 v);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200D418(void *a);
extern void  func_0215E428(void *a, void *b);
extern void  func_0215E364(void *a);
extern void *func_0201296C(void *a);
extern void func_0201433C(char *a0, int a1);
extern void  func_02164728(void *a);
extern int   func_02013FFC(void *a);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern void func_02008988(struct Sub02008828Obj *obj, u16 value);

void func_021643E8(void *a, void *b)
{
    void *w = func_02012B38(a);
    void *c;
    if ((func_02013F6C(b) & 3) == 0) {
        func_02014464(w, 0);
    }
    func_0215E428(func_0200D418(func_02012EBC(a)), b);
    func_0215E364(a);
    c = func_0201296C(a);
    func_0201433C(c, 0x964);
    func_02164728(c);
    if (func_02013FFC(b) == 0) {
        func_02008988(func_02008854(func_02012EBC(a)), 0);
    }
}
