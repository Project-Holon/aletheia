/*
 * function: GSYNC_STATE_StateInitDownload
 * address: 0x021D7B68
 * packet: pkt_ov123_021D7B68
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_DIST_SAVE_GetBlockSize 0x0200C6E4 thumb
 *   GSYNC_DOWNLOAD_AllocWork 0x021D5B10 thumb ov123
 *   GSYNC_DOWNLOAD_InitAsync 0x021D5BD4 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateSetFileAttribute 0x021D7A5C thumb ov123
 *   GSYNC_STATE_StateErrorMessage 0x021D6FF0 thumb ov123
 */
#include "../include/Obj03271.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 MUSICAL_DIST_SAVE_GetBlockSize(void);
extern u32 func_0200E8B0(void);
extern char *GSYNC_DOWNLOAD_AllocWork(int heap, int size);
extern int GSYNC_DOWNLOAD_InitAsync(char *p);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateSetFileAttribute(u8 *p);
extern void GSYNC_STATE_StateErrorMessage(char *p);
void GSYNC_STATE_StateInitDownload(char *p)
{
    switch (((struct Obj03271 *)p)->fA7) {
    case 0: ((struct Obj03271 *)p)->f8 = GSYNC_DOWNLOAD_AllocWork(((struct Obj03271 *)p)->f0, MUSICAL_DIST_SAVE_GetBlockSize() + 4); break;
    case 1: ((struct Obj03271 *)p)->f8 = GSYNC_DOWNLOAD_AllocWork(((struct Obj03271 *)p)->f0, 0x20000); break;
    case 2: ((struct Obj03271 *)p)->f8 = GSYNC_DOWNLOAD_AllocWork(((struct Obj03271 *)p)->f0, func_0200E8B0() + 4); break;
    }
    if (GSYNC_DOWNLOAD_InitAsync(((struct Obj03271 *)p)->f8)) {
        GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateSetFileAttribute, 0x458);
        return;
    }
    ((struct Obj03271 *)p)->f80 = 0xfff0;
    GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateErrorMessage, 0x45c);
}
