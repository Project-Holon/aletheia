/*
 * function: INTRUDE_COMM_BuildSymbolPage
 * address:  0x02174D5C
 * packet:   pkt_ov011_02174D5C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SYMBOL_SAVE_GetBlock  0x0200E0B0  thumb
 *   func_0216749C  0x0216749C  thumb ov010
 *   func_021673C4  0x021673C4  thumb ov010
 *   func_021673A8  0x021673A8  thumb ov010
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Blk {
    u8 pad[0x50];
    u32 a : 6;
    u32 b : 4;
    u32 c : 4;
    u32 d : 4;
    u32 e : 6;
} Blk;

struct Big;
u32 GAME_COMM_GetGameData(void *obj);
void *GAME_DATA_GetSaveControl(struct Big *p);
void *SYMBOL_SAVE_GetBlock(void *p);
struct Entry32;
unsigned short func_0216749C(struct Entry32 *list, struct Entry32 *out, u32 cap, int page, u8 *n);
typedef unsigned short u16;
u8 func_021673C4(u8 *p);
u8 func_021673A8(u8 *p);
u16 GFL_NET_SYSTEM_GetCurrentAid(void);

void INTRUDE_COMM_BuildSymbolPage(int *p, const u8 *q)
{
    Blk *b;
    void *x;
    int t;
    u8 buf[4];

    b = (Blk *)((u8 *)p + 0x880);
    x = SYMBOL_SAVE_GetBlock(GAME_DATA_GetSaveControl((struct Big *)GAME_COMM_GetGameData((void *)p[1])));
    func_0216749C(x, (struct Entry32 *)b, 0x14, q[0], buf);
    b->a = buf[0];
    b->b = func_021673C4(x);
    b->c = func_021673A8(x);
    t = GFL_NET_SYSTEM_GetCurrentAid();
    b->d = t;
    b->e = q[0];
}
