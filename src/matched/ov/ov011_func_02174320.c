/*
 * function: INTRUDE_CMD_RecvProfile
 * address:  0x02174320
 * packet:   pkt_ov011_02174320
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   GAME_DATA_GetBattleRecSlot  0x020127AC  thumb
 *   func_02082D44  0x02082D44  arm
 */

typedef struct H {
    unsigned short f : 3;
} H;

typedef unsigned int   u32;
struct Link;
struct SaveBlock;
u32 GAME_COMM_GetGameData(void *obj);
struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
u32 GFL_NET_GetHandleNetID(struct Link *p);
void *GAME_DATA_GetBattleRecSlot(struct SaveBlock *p, u32 idx);
void func_02082D44(void *d, int s, int n);

void INTRUDE_CMD_RecvProfile(int a, int b, void *c, char *d)
{
    int p;

    p = GAME_COMM_GetGameData((void *)(((int *)d)[1]));
    if (a != GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle())) && ((unsigned char)d[0x8fb] & (1 << a))) {
        func_02082D44(c, (int)GAME_DATA_GetBattleRecSlot((struct SaveBlock *)p, a), 0x10);
        if (a == ((H *)(d + 0x86))->f) {
            d[0x8fb + 0xb] = 1;
        }
    }
}
