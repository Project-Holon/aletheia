/*
 * function: func_0215539C
 * address:  0x0215539C
 * packet:   pkt_ov009_0215539C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates the 0x7AC-byte ov009 work block into d_021A8264 (asserting it
 * was empty) and initialises it.  func_0203D7C8's last two arguments look
 * like a file/line pair (d_021A1C60, 302).
 *
 * symbols:
 *   d_021A8264     0x021A8264  data  ov009  a4
 *   d_021A1C5C     0x021A1C5C  data  ov009  a1
 *   d_021A1C60     0x021A1C60  data  ov009  a1
 *   func_0203D798  0x0203D798  arm
 *   func_0203D7C8  0x0203D7C8  arm
 *   func_02034714  0x02034714  arm
 *   func_020597C8  0x020597C8  arm
 *   func_02059760  0x02059760  arm
 *   func_02155374  0x02155374  thumb  ov009
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    char pad0[0x56];
    u16 heap;
    char pad58[0x60 - 0x58];
    u8 b60;
} Ctx;

typedef struct {
    char pad0[0x100];
    int w100;
    char pad104[0x108 - 0x104];
    int w108;
    char pad10C[0x17C - 0x10C];
    int arr[32];
    char pad1FC[0x32C - 0x1FC];
    u8 bytes[32];
    char pad34C[0x764 - 0x34C];
    int w764;
    char pad768[0x770 - 0x768];
    int w770;
    int w774;
    char pad778[0x77C - 0x778];
    int w77C;
    char pad780[0x782 - 0x780];
    u16 h782;
    char pad784[0x790 - 0x784];
    int w790;
    u16 h794;
    u16 h796;
    char pad798[0x79E - 0x798];
    u8 b79E;
    char pad79F[0x7A1 - 0x79F];
    u8 b7A1;
    char pad7A2[0x7AC - 0x7A2];
} G;

extern G *d_021A8264;
extern char d_021A1C5C[];
extern char d_021A1C60[];
Ctx *func_0203D798(void);
G *func_0203D7C8(u16 heap, int size, char *file, int line);
void func_02034714(char *a, int b, char *c);
int func_020597C8(int x);
int func_02059760(int x);
void func_02155374(int v);

int func_0215539C(int a0, int a1)
{
    Ctx *ctx;
    int i;

    ctx = func_0203D798();
    if (d_021A8264 != 0)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    d_021A8264 = func_0203D7C8(ctx->heap, sizeof(G), d_021A1C60, 302);
    for (i = 0; i < 32; i++)
        d_021A8264->arr[i] = -1;
    func_02155374(0);
    d_021A8264->w77C = 0;
    d_021A8264->w770 = -1;
    d_021A8264->w764 = ctx->b60;
    d_021A8264->w774 = -1;
    d_021A8264->h782 = 0;
    d_021A8264->b79E = 0;
    d_021A8264->h794 = 1;
    d_021A8264->w790 = 1;
    d_021A8264->h796 = 1;
    d_021A8264->w108 = a0;
    d_021A8264->w100 = a1;
    d_021A8264->b7A1 = 1;
    for (i = 0; i < 32; i++)
        d_021A8264->bytes[i] = 0;
    if (func_020597C8(d_021A8264->w108) == 0)
        return 1;
    if (func_02059760(d_021A8264->w108) == 0)
        return 2;
    return 0;
}
