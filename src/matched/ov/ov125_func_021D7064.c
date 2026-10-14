/*
 * unit: yes
 * function: GDS_RAP_PollSaveUploadedVideo, GDS_RAP_PollNothingAfterError
 * address: 0x021D7064
 * packet: pkt_ov125_021D7064
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GDS_RAP_GetVideoWork 0x021D7700 thumb ov125
 *   GDS_RAP_FindMember 0x021D7154 thumb ov125
 *   GDS_RAP_CopyNickname 0x021D71CC thumb ov125
 *   GDS_RAP_SaveVideoWithDataNumber 0x021D75E8 thumb ov125
 *   GDS_SOCKET_GetReply 0x021D85E8 arm ov125
 *   BATTLE_REC_DecodeWork 0x0200B490 thumb
 *   BATTLE_REC_GetBody 0x0200B91C thumb
 *   BATTLE_REC_EncodeWork 0x0200B4B8 thumb
 *   BATTLE_REC_GetModeLayout  0x0200B784  thumb  arm9
 *   BATTLE_REC_SetBodyCrc  0x0200BA44  thumb  arm9
 */
#include "../include/Obj10460.h"
#include "../include/Obj22998.h"
typedef unsigned short u16;
extern char *GDS_RAP_GetVideoWork(void);
extern void BATTLE_REC_GetModeLayout(u16, int *, int *);
extern int GDS_RAP_FindMember(int, int, int *, int *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void GDS_RAP_CopyNickname(const void *src, void *dst, u32 n);
struct RecC4;
extern void BATTLE_REC_DecodeWork(void);
extern u8 *BATTLE_REC_GetBody(void);
extern void BATTLE_REC_SetBodyCrc(struct RecC4 *p);
extern void BATTLE_REC_EncodeWork(void);
extern char *GDS_SOCKET_GetReply(void);
extern int GDS_RAP_SaveVideoWithDataNumber(int, int, int, u16 *, int, u16);
int GDS_RAP_PollSaveUploadedVideo(char *p, const u16 *s)
{
    char *base;
    char *out;
    char *r;
    int outer, inner;
    int n, m;
    int i;
    int *obj;
    int result;
    if (s[2] == 0 && ((struct Obj10460 *)p)->f5A0 != 0) {
        r = GDS_RAP_GetVideoWork();
        BATTLE_REC_DecodeWork();
        BATTLE_REC_GetModeLayout(((struct Obj22998 *)r)->fA6, &n, &m);
        i = 0;
        out = p + 0x498;
        base = r + 0xd00;
        for (; i < 12; i++) {
            if (!GDS_RAP_FindMember((int)p, i, &outer, &inner)) break;
            GDS_RAP_CopyNickname(out + i * 22, base + outer * 676 + inner * 112 + 50, 11);
        }
        BATTLE_REC_SetBodyCrc((struct RecC4 *)BATTLE_REC_GetBody());
        BATTLE_REC_EncodeWork();
    }
    obj = (int *)GDS_SOCKET_GetReply();
    result = GDS_RAP_SaveVideoWithDataNumber(((struct Obj10460 *)p)->f0, obj[1], obj[2], (u16 *)(s + 2), (int)(s + 3), (u16)((struct Obj10460 *)p)->f13C);
    if (result == 2 || result == 3) return 1;
    return 0;
}
int GDS_RAP_PollNothingAfterError(void) { return 1; }
