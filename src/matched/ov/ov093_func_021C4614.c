/*
 * function: func_021C4614
 * address: 0x021C4614
 * packet: pkt_ov093_021C4614
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: first index declared before other indices; byte results of 021B8DEC.
 * symbols:
 *  func_021B8588 0x021B8588 thumb ov093
 *  func_021B8FF4 0x021B8FF4 thumb ov093
 *  func_021B9064 0x021B9064 thumb ov093
 *  func_021B9AEC 0x021B9AEC thumb ov093
 *  func_021B9B98 0x021B9B98 thumb ov093
 *  func_021B9CE8 0x021B9CE8 thumb ov093
 *  func_021D5440 0x021D5440 thumb ov093
 *  func_021C4724 0x021C4724 thumb ov093
 *  func_021C4734 0x021C4734 thumb ov093
 *  func_021B8DEC 0x021B8DEC thumb ov093
 *  func_021B99F0 0x021B99F0 thumb ov093
 *  func_021CD4B0 0x021CD4B0 thumb ov093
 *  func_021BD43C 0x021BD43C thumb ov093
 *  func_021BD4E4 0x021BD4E4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_021B8588(void *);
extern u8 func_021B8FF4(u8 *);
extern int func_021B9064(void *, int, int);
extern char *func_021B9AEC(char *, int);
extern u8 func_021B9B98(char *);
extern u8 *func_021B9CE8(char *);
extern u8 func_021D5440(u8 *);
extern u32 func_021C4724(u8 *, u32);
extern u32 func_021C4734(u8 *, u32);
extern u8 func_021B8DEC(void *, int);
extern u32 func_021B99F0(u32);
extern void func_021CD4B0(void *, u32, ...);
extern void func_021BD43C(u8 *, int, u8, u8, int);
extern void func_021BD4E4(u8 *, int, u8, u8);
void func_021C4614(u8 *p)
{
    u32 first, a, b;
    char *x, *y;
    u8 *m, *n;
    u32 mi, ni, s, t;
    u8 v, w;
    if (func_021B8588(*(void **)(p + 4)) != 2) return;
    a = func_021B8FF4(*(u8 **)(p + 4));
    first = a;
    b = (u8)func_021B9064(*(void **)(p + 4), a, 0);
    if (a > b) { first = b; b = a; }
    x = func_021B9AEC(*(char **)(p + 8), first);
    y = func_021B9AEC(*(char **)(p + 8), b);
    if (func_021B9B98(x) != 1) return;
    if (func_021B9B98(y) != 1) return;
    m = func_021B9CE8(x);
    n = func_021B9CE8(y);
    mi = func_021D5440(m);
    ni = func_021D5440(n);
    s = func_021C4724(p + 0x1ab8, mi);
    t = func_021C4734(p + 0x1ab8, ni);
    if (s == 6 || t == 6) return;
    v = func_021B8DEC(*(void **)(p + 4), s);
    w = func_021B8DEC(*(void **)(p + 4), t);
    if (v != w) return;
    if (func_021B99F0(s) != 0) return;
    func_021CD4B0(*(void **)(p + 12), 0x50, first, v, b, w);
    func_021BD43C(p, first, v, 1, 1);
    func_021BD43C(p, b, w, 1, 1);
    func_021BD4E4(p, first, v, 1);
    func_021BD4E4(p, b, w, 1);
}
