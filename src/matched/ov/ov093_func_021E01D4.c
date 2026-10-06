/*
 * function: func_021E01D4
 * address:  0x021E01D4
 * packet:   pkt_ov093_021E01D4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_0201C314  0x0201C314  thumb
 *   func_021E0274  0x021E0274  thumb  ov093
 *   func_021D7098  0x021D7098  thumb  ov093
 *   func_021C7EC4  0x021C7EC4  thumb  ov093
 *   func_021D7090  0x021D7090  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021D775C(int key);
extern int func_0201C314(u16 id);
extern int func_021E0274(u16 id);
typedef unsigned int   u32;
struct QQ;
extern int func_021D7098(u8 *p);
extern u32 func_021C7EC4(u8 *p);
extern void func_021D7090(u8 *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern u16 func_021D70A8(struct QQ *p);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021E01D4(void *a, void *b, int c, int *d, u8 e)
{
    u16 t;
    char *p;

    if (c == func_021D775C(3) && e == func_021D775C(0x16)) {
        t = func_021D775C(0x12);
        if (func_0201C314(t) != 0 && func_021E0274(t) == 0 && func_021D7098(a) == 0
            && func_021C7EC4(b) == 0) {
            func_021D7090(a);
            p = func_021C88A4(b, 0x23, c);
            func_021C8838(p + 8, 1, 0xb6);
            func_021C8860((struct S *)(p + 8), func_021D70A8(a));
            func_021C8860((struct S *)(p + 8), func_021D775C(0x12));
            func_021C88C8(b, p);
            *d = 1;
        }
    }
}
