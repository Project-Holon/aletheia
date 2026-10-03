/*
 * function: func_021B77B0
 * address: 0x021B77B0
 * packet: pkt_ov103_021B77B0
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 7FF0 tail-forwards to u32-returning 0201C4E4; caller tests live r0.
 * symbols:
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021B7FF0 0x021B7FF0 thumb ov103
 *   func_021B8100 0x021B8100 thumb ov103
 *   func_021B7918 0x021B7918 thumb ov103
 *   func_021B63D0 0x021B63D0 thumb ov101
 *   func_021B71E4 0x021B71E4 thumb ov101
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern void func_0204E720(u32, int, int, int);
extern int func_0204E804(void);
extern u32 func_021B7FF0(u8 *);
extern int func_021B8100(void *, void *);
extern void func_021B7918(u8 *);
struct Obj;
extern int func_021B63D0(struct Obj *p);
extern void func_021B71E4(int);
int func_021B77B0(void *unused, u32 *state, int unused2, char *p)
{
    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        func_0204E720(3, 16, 0, 0);
        *state = 2;
        break;
    case 2:
        if (func_0204E804() == 0) *state = 3;
        break;
    case 3:
        (*(void (**)(char *, char *))(p + 0x728))(p, p + 0x72c);
        if (*(u32 *)(p + 0x730) != 0) *state = 4;
        break;
    case 4:
        func_0204E720(3, 0, 16, 0);
        *state = 5;
        break;
    case 5:
        if (func_0204E804() == 0) *state = 6;
        break;
    case 6:
        return 1;
    }
    if (func_021B7FF0((u8 *)(p + 0x174)) != 0) {
        func_021B8100(p + 0x184, p + 0x174);
        func_021B8100(p + 0x748, p + 0x174);
    }
    func_021B7918((u8 *)p);
    func_021B63D0(*(void **)(*(u8 **)(p + 0xb0c) + 4));
    func_021B71E4(*(int *)(p + 0xa38));
    return 0;
}
