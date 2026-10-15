/*
 * function: B_PLIST_MAIN_UpdateSwapFrames
 * address: 0x02211420
 * packet: pkt_ov198_02211420
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_PLIST_MAIN_CopyFrame 0x022113B8 thumb ov198
 *   B_PLIST_MAIN_GetFramePos 0x0221139C thumb ov198
 *   B_PLIST_MAIN_MoveActorByFlag 0x022113FC thumb ov198
 *   B_PLIST_MAIN_SwapOrder 0x022110A4 thumb ov198
 *   B_PLIST_MAIN_SwapActorPos 0x0220F2DC thumb ov198
 *   data_02212550 0x02212550 data ov198
 *   BGWINFRM_Create  0x0202C9B4  thumb  arm9
 *   BGWINFRM_Delete  0x0202CA0C  thumb  arm9
 *   BGWINFRM_AddFrame  0x0202CA3C  thumb  arm9
 *   BGWINFRM_SetFrameData  0x0202CAC4  thumb  arm9
 *   BGWINFRM_PutFrame  0x0202CB4C  thumb  arm9
 *   BGWINFRM_StartMove  0x0202CD64  thumb  arm9
 *   BGWINFRM_UpdateMoves  0x0202CD94  thumb  arm9
 *   BGWINFRM_IsMoving  0x0202CE40  thumb  arm9
 *   BGWINFRM_GetPos  0x0202CF98  thumb  arm9
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WinMgr;
extern u8 data_02212550[];
extern struct WinMgr *BGWINFRM_Create(u32 a0, u32 a1, u32 heap);
extern void BGWINFRM_AddFrame(struct WinMgr *mgr, u32 idx, u32 a, u32 b, u32 c);
extern void BGWINFRM_SetFrameData(struct WinMgr *mgr, u32 idx, const void *src);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void BGWINFRM_UpdateMoves(struct WinMgr *mgr);
extern void BGWINFRM_StartMove(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern void BGWINFRM_GetPos(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern u32 BGWINFRM_IsMoving(struct WinMgr *mgr, u32 idx);
extern void BGWINFRM_Delete(struct WinMgr *mgr);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void B_PLIST_MAIN_CopyFrame(u8 *dst, unsigned bg, unsigned which);
extern void B_PLIST_MAIN_GetFramePos(u8 *, u8 *, unsigned);
extern void B_PLIST_MAIN_MoveActorByFlag(u8 *p, int a, int b);
extern void B_PLIST_MAIN_SwapOrder(u8 *p, int a, int b);
extern void B_PLIST_MAIN_SwapActorPos(char *p, int a1, int a2);

#define MGR (*(struct WinMgr **)(p + 0x2194))

int B_PLIST_MAIN_UpdateSwapFrames(u8 *p)
{
    s8 xy[4];
    s8 pos[4];
    s8 pos2[4];
    switch (p[0x1e98]) {
    case 0: {
        u8 *buf;
        MGR = BGWINFRM_Create(2, 4, *(u16 *)(*(u8 **)p + 0x10));
        BGWINFRM_AddFrame(MGR, 0, 5, 0x10, 6);
        BGWINFRM_AddFrame(MGR, 1, 6, 0x10, 6);
        BGWINFRM_AddFrame(MGR, 2, 5, 0x10, 6);
        BGWINFRM_AddFrame(MGR, 3, 6, 0x10, 6);
        buf = func_02030734((u16)(0x8000 | (*(u16 *)(*(u8 **)p + 0x10) & 0x7fff)), 0xc0, 0, (const char *)data_02212550, 0xb89);
        B_PLIST_MAIN_CopyFrame(buf, 5, p[0x2499]);
        BGWINFRM_SetFrameData(MGR, 0, buf);
        B_PLIST_MAIN_CopyFrame(buf, 6, p[0x2499]);
        BGWINFRM_SetFrameData(MGR, 1, buf);
        B_PLIST_MAIN_CopyFrame(buf, 5, p[0x249a]);
        BGWINFRM_SetFrameData(MGR, 2, buf);
        B_PLIST_MAIN_CopyFrame(buf, 6, p[0x249a]);
        BGWINFRM_SetFrameData(MGR, 3, buf);
        func_020307B0(buf);
        B_PLIST_MAIN_GetFramePos((u8 *)&xy[1], (u8 *)&xy[0], p[0x2499]);
        BGWINFRM_PutFrame(MGR, 0, xy[1], xy[0]);
        BGWINFRM_PutFrame(MGR, 1, xy[1], xy[0]);
        B_PLIST_MAIN_GetFramePos((u8 *)&xy[1], (u8 *)&xy[0], p[0x249a]);
        BGWINFRM_PutFrame(MGR, 2, xy[1], xy[0]);
        BGWINFRM_PutFrame(MGR, 3, xy[1], xy[0]);
        BGWINFRM_UpdateMoves(MGR);
        p[0x1e98]++;
        break;
    }
    case 1:
        if (p[0x2499] & 1) {
            BGWINFRM_StartMove(MGR, 0, 1, 0, 0x10);
            BGWINFRM_StartMove(MGR, 1, 1, 0, 0x10);
        } else {
            BGWINFRM_StartMove(MGR, 0, -1, 0, 0x10);
            BGWINFRM_StartMove(MGR, 1, -1, 0, 0x10);
        }
        if (p[0x249a] & 1) {
            BGWINFRM_StartMove(MGR, 2, 1, 0, 0x10);
            BGWINFRM_StartMove(MGR, 3, 1, 0, 0x10);
        } else {
            BGWINFRM_StartMove(MGR, 2, -1, 0, 0x10);
            BGWINFRM_StartMove(MGR, 3, -1, 0, 0x10);
        }
        p[0x1e98]++;
        break;
    case 2: {
        BGWINFRM_UpdateMoves(MGR);
        B_PLIST_MAIN_MoveActorByFlag(p, p[0x2499], 0);
        B_PLIST_MAIN_MoveActorByFlag(p, p[0x249a], 0);
        BGWINFRM_GetPos(MGR, 0, &pos[3], &pos[2]);
        BGWINFRM_GetPos(MGR, 2, &pos[1], &pos[0]);
        if (BGWINFRM_IsMoving(MGR, 0) != 0) break;
        B_PLIST_MAIN_SwapOrder(p, p[0x2499], p[0x249a]);
        BGWINFRM_PutFrame(MGR, 0, pos[1], pos[0]);
        BGWINFRM_PutFrame(MGR, 1, pos[1], pos[0]);
        BGWINFRM_PutFrame(MGR, 2, pos[3], pos[2]);
        BGWINFRM_PutFrame(MGR, 3, pos[3], pos[2]);
        B_PLIST_MAIN_SwapActorPos((char *)p, p[0x2499], p[0x249a]);
        p[0x1e98]++;
        break;
    }
    case 3:
        BGWINFRM_UpdateMoves(MGR);
        if (p[0x249a] & 1) {
            BGWINFRM_StartMove(MGR, 0, -1, 0, 0x10);
            BGWINFRM_StartMove(MGR, 1, -1, 0, 0x10);
        } else {
            BGWINFRM_StartMove(MGR, 0, 1, 0, 0x10);
            BGWINFRM_StartMove(MGR, 1, 1, 0, 0x10);
        }
        if (p[0x2499] & 1) {
            BGWINFRM_StartMove(MGR, 2, -1, 0, 0x10);
            BGWINFRM_StartMove(MGR, 3, -1, 0, 0x10);
        } else {
            BGWINFRM_StartMove(MGR, 2, 1, 0, 0x10);
            BGWINFRM_StartMove(MGR, 3, 1, 0, 0x10);
        }
        p[0x1e98]++;
        break;
    case 4: {
        BGWINFRM_UpdateMoves(MGR);
        B_PLIST_MAIN_MoveActorByFlag(p, p[0x2499], 1);
        B_PLIST_MAIN_MoveActorByFlag(p, p[0x249a], 1);
        BGWINFRM_GetPos(MGR, 0, &pos2[3], &pos2[2]);
        BGWINFRM_GetPos(MGR, 2, &pos2[1], &pos2[0]);
        if (BGWINFRM_IsMoving(MGR, 0) == 0) p[0x1e98]++;
        break;
    }
    case 5:
        BGWINFRM_Delete(MGR);
        MGR = 0;
        p[0x1e98] = 0;
        return 0;
    }
    return 1;
}
