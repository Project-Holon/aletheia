/*
 * function: DWC_RAP_CreateWork
 * address:  0x0215539C
 * packet:   pkt_ov009_0215539C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates the 0x7AC-byte ov009 work block into _pRapWork (asserting it
 * was empty) and initialises it.  GFL_NET_AllocAligned's last two arguments look
 * like a file/line pair (d_021A1C60, 302).
 *
 * symbols:
 *   _pRapWork     0x021A8264  data  ov009  a4
 *   d_021A1C5C     0x021A1C5C  data  ov009  a1
 *   d_021A1C60     0x021A1C60  data  ov009  a1
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GFL_NET_AllocAligned  0x0203D7C8  arm
 *   func_02034714  0x02034714  arm
 *   func_020597C8  0x020597C8  arm
 *   func_02059760  0x02059760  arm
 *   DWC_RAP_SetState  0x02155374  thumb  ov009
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

extern G *_pRapWork;
extern char d_021A1C5C[];
extern char d_021A1C60[];
typedef unsigned int   u32;
void *GFL_NET_GetInitParam(void);
void *GFL_NET_AllocAligned(u32 heap, u32 size, const char *file, u16 line);
void func_02034714(const char *expr, u32 line, const char *file);
struct DWCstAccUserData;
int func_020597C8(struct DWCstAccUserData *userdata);
int func_02059760(struct DWCstAccUserData *userdata);
void DWC_RAP_SetState(int v);

int DWC_RAP_CreateWork(int a0, int a1)
{
    Ctx *ctx;
    int i;

    ctx = GFL_NET_GetInitParam();
    if (_pRapWork != 0)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    _pRapWork = GFL_NET_AllocAligned(ctx->heap, sizeof(G), d_021A1C60, 302);
    for (i = 0; i < 32; i++)
        _pRapWork->arr[i] = -1;
    DWC_RAP_SetState(0);
    _pRapWork->w77C = 0;
    _pRapWork->w770 = -1;
    _pRapWork->w764 = ctx->b60;
    _pRapWork->w774 = -1;
    _pRapWork->h782 = 0;
    _pRapWork->b79E = 0;
    _pRapWork->h794 = 1;
    _pRapWork->w790 = 1;
    _pRapWork->h796 = 1;
    _pRapWork->w108 = a0;
    _pRapWork->w100 = a1;
    _pRapWork->b7A1 = 1;
    for (i = 0; i < 32; i++)
        _pRapWork->bytes[i] = 0;
    if (func_020597C8((struct DWCstAccUserData *)_pRapWork->w108) == 0)
        return 1;
    if (func_02059760((struct DWCstAccUserData *)_pRapWork->w108) == 0)
        return 2;
    return 0;
}
