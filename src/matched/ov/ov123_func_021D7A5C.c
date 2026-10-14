/*
 * function: GSYNC_STATE_StateSetFileAttribute
 * address: 0x021D7A5C
 * packet: pkt_ov123_021D7A5C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_DOWNLOAD_ClearResult 0x021D5C0C thumb ov123
 *   GSYNC_DOWNLOAD_Reset 0x021D5C2C thumb ov123
 *   GSYNC_DOWNLOAD_SetAttr 0x021D5C64 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateErrorMessage 0x021D6FF0 thumb ov123
 *   GSYNC_STATE_StateRequestFileList 0x021D7A18 thumb ov123
 *   d_021DAB88 0x021DAB88 data a1
 *   d_021DAB90 0x021DAB90 data a1
 *   d_021DAB9C 0x021DAB9C data a1
 */
#include "../include/Obj01934.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern int GSYNC_DOWNLOAD_ClearResult(char *p);
extern int GSYNC_DOWNLOAD_Reset(char *p);
extern int GSYNC_DOWNLOAD_SetAttr(char *p, void *arg, int value);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateErrorMessage(char *p);
extern void GSYNC_STATE_StateRequestFileList(int a);
extern const char d_021DAB88[], d_021DAB90[], d_021DAB9C[];
void GSYNC_STATE_StateSetFileAttribute(u8 *p)
{
    if (GSYNC_DOWNLOAD_ClearResult(((struct Obj01934 *)p)->f8)) {
        if (GSYNC_DOWNLOAD_Reset(((struct Obj01934 *)p)->f8)) {
            ((struct Obj01934 *)p)->f80 = 0xfff0;
            GSYNC_STATE_ChangeState(p, (int)GSYNC_STATE_StateErrorMessage, 0x424);
            return;
        }
        switch (p[0xa7]) {
        case 0:
            if (GSYNC_DOWNLOAD_SetAttr(((struct Obj01934 *)p)->f8, (void *)d_021DAB88, p[0xa5])) {
                GSYNC_STATE_ChangeState(p, (int)GSYNC_STATE_StateRequestFileList, 0x42b);
                return;
            }
            ((struct Obj01934 *)p)->f80 = 0xfff0;
            GSYNC_STATE_ChangeState(p, (int)GSYNC_STATE_StateErrorMessage, 0x42f);
            return;
        case 1:
            if (GSYNC_DOWNLOAD_SetAttr(((struct Obj01934 *)p)->f8, (void *)d_021DAB90, p[0xa4])) {
                GSYNC_STATE_ChangeState(p, (int)GSYNC_STATE_StateRequestFileList, 0x434);
                return;
            }
            ((struct Obj01934 *)p)->f80 = 0xfff0;
            GSYNC_STATE_ChangeState(p, (int)GSYNC_STATE_StateErrorMessage, 0x438);
            return;
        case 2:
            if (GSYNC_DOWNLOAD_SetAttr(((struct Obj01934 *)p)->f8, (void *)d_021DAB9C, p[0xa6])) {
                GSYNC_STATE_ChangeState(p, (int)GSYNC_STATE_StateRequestFileList, 0x43d);
                return;
            }
            ((struct Obj01934 *)p)->f80 = 0xfff0;
            GSYNC_STATE_ChangeState(p, (int)GSYNC_STATE_StateErrorMessage, 0x441);
            return;
        }
    }
}
