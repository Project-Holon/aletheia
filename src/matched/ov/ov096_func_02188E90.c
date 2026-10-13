/*
 * unit:     yes
 * function: TR_AI_CmdLoadAbleBackupCount, TR_AI_CmdLoadCurrentMove
 * address:  0x02188E90
 * packet:   pkt_ov096_02188E90
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * TR_AI_CmdLoadCurrentMove is the unlabelled store-and-return stub at 0x02188F08
 * (function_starts seed).
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   TR_AI_GetPosition  0x0218A160  thumb  ov096
 *   TR_AI_GetSlotPoke  0x0218A308  thumb  ov096
 *   BTL_MAIN_GetSlotClientIdThunk  0x021B8DE4  thumb  ov093
 *   BTL_SIDE_GetSlotOfClientThunk  0x021B9AF8  thumb  ov093
 *   BTL_MAIN_GetPositionsPerClientThunk  0x021B99B8  thumb  ov093
 *   BTL_SLOT_GetCount  0x021B9B94  thumb  ov093
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
extern u8 TR_AI_GetPosition(u8 *p, int k);
extern u8 *TR_AI_GetSlotPoke(void *p, u32 i);
extern u8 BTL_MAIN_GetSlotClientIdThunk(char *p, int i);
extern char *BTL_SIDE_GetSlotOfClientThunk(char *p, int i);
extern int BTL_MAIN_GetPositionsPerClientThunk(void *pp, unsigned int b);
struct Q1;
extern u8 BTL_SLOT_GetCount(struct Q1 *p);
extern int BTL_POKEPARAM_IsAbleToBattle(void *);

int TR_AI_CmdLoadAbleBackupCount(struct Cursor *a, Conn *b)
{
    int x;
    char *p;
    int n;

    x = BTL_MAIN_GetSlotClientIdThunk((char *)b->fb0, TR_AI_GetPosition((u8 *)b, VM_GetU32(a)));
    p = BTL_SIDE_GetSlotOfClientThunk(b->fb8, x);
    n = BTL_MAIN_GetPositionsPerClientThunk((void *)b->fb0, x);
    b->f38 = 0;
    for (; n < BTL_SLOT_GetCount((struct Q1 *)p); n++) {
        if (BTL_POKEPARAM_IsAbleToBattle(TR_AI_GetSlotPoke(p, (u8)n)) != 0)
            b->f38++;
    }
    return b->fc4;
}

int TR_AI_CmdLoadCurrentMove(int a, Conn *b)
{
    b->f38 = b->f2;
    return b->fc4;
}
