/*
 * unit:     yes
 * function: func_02188E90, func_02188F08
 * address:  0x02188E90
 * packet:   pkt_ov096_02188E90
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_02188F08 is the unlabelled store-and-return stub at 0x02188F08
 * (function_starts seed).
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A308  0x0218A308  thumb  ov096
 *   func_021B8DE4  0x021B8DE4  thumb  ov093
 *   func_021B9AF8  0x021B9AF8  thumb  ov093
 *   func_021B99B8  0x021B99B8  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   BTL_POKEPARAM_IsAbleToBattle  0x021D5B7C  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[2];
    u16 f2;
    u8 pad04[0x38 - 4];
    int f38;
    u8 pad3C[0xb0 - 0x3c];
    int fb0;
    u8 padB4[4];
    char *fb8;
    u8 padBC[8];
    int fc4;
} Conn;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A308(void *p, u32 i);
extern u8 func_021B8DE4(char *p, int i);
extern char *func_021B9AF8(char *p, int i);
extern int func_021B99B8(void *pp, unsigned int b);
struct Q1;
extern u8 func_021B9B94(struct Q1 *p);
extern int BTL_POKEPARAM_IsAbleToBattle(void *);

int func_02188E90(struct Cursor *a, Conn *b)
{
    int x;
    char *p;
    int n;

    x = func_021B8DE4((char *)b->fb0, func_0218A160((u8 *)b, VM_GetU32(a)));
    p = func_021B9AF8(b->fb8, x);
    n = func_021B99B8((void *)b->fb0, x);
    b->f38 = 0;
    for (; n < func_021B9B94((struct Q1 *)p); n++) {
        if (BTL_POKEPARAM_IsAbleToBattle(func_0218A308(p, (u8)n)) != 0)
            b->f38++;
    }
    return b->fc4;
}

int func_02188F08(int a, Conn *b)
{
    b->f38 = b->f2;
    return b->fc4;
}
