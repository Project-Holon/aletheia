/*
 * function: func_021B68E0
 * address: 0x021B68E0
 * packet: pkt_ov101_021B68E0
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetPlayerStatus 0x02012950 thumb
 *   MYSTATUS_GetSize 0x02008468 thumb
 *   func_02082D44 0x02082D44 arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct Rec44;
struct Sub24;
extern struct Rec44 *GAME_DATA_GetPlayerStatus(struct Sub24 *p, u32 i);
extern int MYSTATUS_GetSize(void);
extern void func_02082D44(void *, const void *, u32);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
void func_021B68E0(u32 a, int b, int c, int *d, u32 e)
{
    void *p;
    if (*(int *)d[0] != 0) {
        p = GAME_DATA_GetPlayerStatus((void *)*(int *)d[0], a);
        func_02082D44((void *)(c + 12), p, MYSTATUS_GetSize());
    }
    if (e == (u32)GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_SYSTEM_GetCurrentAid())
            d[9] = 1;
    }
}
