/*
 * function: POKETRADE_SAVE_RestoreSaveControl
 * address: 0x021E017C
 * packet: pkt_ov119_021E017C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_02009470 0x02009470 thumb
 *   GAME_SYNC_GetBlockSize 0x02009454 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 */
struct Big;
struct Sub02009470Obj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern unsigned GAME_SYNC_GetBlockSize(void);
extern void MI_CpuCopy8(void *, void *, int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void POKETRADE_SAVE_RestoreSaveControl(void *sys, void *buf)
{
    void *src = func_02009470(GAME_DATA_GetSaveControl(sys));
    MI_CpuCopy8(buf, src, GAME_SYNC_GetBlockSize());
    func_020307B0(buf);
}
