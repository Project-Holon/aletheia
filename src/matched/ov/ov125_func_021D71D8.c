/*
 * unit: yes
 * function: GDS_RAP_ReadReply, GDS_RAP_GetResult, GDS_RAP_ClearResult
 * address: 0x021D71D8
 * packet: pkt_ov125_021D71D8
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sGdsEmptyString 0x021D8D28 data a4
 *   GDS_SOCKET_GetReply 0x021D85E8 arm ov125
 *   GDS_SOCKET_GetReplySize 0x021D85F4 arm ov125
 *   func_02034714 0x02034714 arm
 *   GDS_RAP_CheckUploadEntryReply 0x021D732C thumb ov125
 *   GDS_RAP_CheckDownloadEntriesReply 0x021D7354 thumb ov125
 *   GDS_RAP_CheckUploadVideoReply 0x021D73B8 thumb ov125
 *   GDS_RAP_CheckSearchVideosReply 0x021D73F0 thumb ov125
 *   GDS_RAP_CheckGetVideoReply 0x021D74B4 thumb ov125
 *   GDS_RAP_CheckMarkVideoReply 0x021D7520 thumb ov125
 *   GDS_RAP_PollSaveUploadedVideo 0x021D7064 thumb ov125
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj00327.h"
#include "../include/Obj23000.h"
typedef unsigned short u16;
extern char sGdsEmptyString[];
extern char *GDS_SOCKET_GetReply(void);
extern int GDS_SOCKET_GetReplySize(void);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern int GDS_RAP_CheckUploadEntryReply(char *, const u16 *);
extern int GDS_RAP_CheckDownloadEntriesReply(char *, const u16 *);
extern int GDS_RAP_CheckUploadVideoReply(char *, const u16 *);
extern int GDS_RAP_CheckSearchVideosReply(char *, const u16 *);
extern int GDS_RAP_CheckGetVideoReply(char *, const u16 *);
extern int GDS_RAP_CheckMarkVideoReply(char *, const u16 *);
extern int GDS_RAP_PollSaveUploadedVideo(char *, const u16 *);
extern void MI_CpuFill8(void *, int, unsigned int);
int GDS_RAP_ReadReply(char *p)
{
    const u16 *state;
    int result = 1;
    state = (const u16 *)GDS_SOCKET_GetReply();
    GDS_SOCKET_GetReplySize();
    if (((struct Obj00327 *)p)->f3DC != state[0]) func_02034714(sGdsEmptyString, 0, sGdsEmptyString);
    ((struct Obj00327 *)p)->f3F0 = 0;
    switch (state[0]) {
    case 0: break;
    case 21000:
        result = GDS_RAP_CheckUploadEntryReply(p, state);
        ((struct Obj00327 *)p)->f3F0 = ((struct Obj00327 *)p)->f14C;
        break;
    case 21001:
        result = GDS_RAP_CheckDownloadEntriesReply(p, state);
        ((struct Obj00327 *)p)->f3F0 = ((struct Obj00327 *)p)->f150;
        break;
    case 22000:
        result = GDS_RAP_CheckUploadVideoReply(p, state);
        ((struct Obj00327 *)p)->f3F0 = ((struct Obj00327 *)p)->f154;
        if (result == 1) ((struct Obj00327 *)p)->f3FC = (void *)GDS_RAP_PollSaveUploadedVideo;
        break;
    case 22001:
        result = GDS_RAP_CheckSearchVideosReply(p, state);
        ((struct Obj00327 *)p)->f3F0 = ((struct Obj00327 *)p)->f158;
        break;
    case 22002:
        result = GDS_RAP_CheckGetVideoReply(p, state);
        ((struct Obj00327 *)p)->f3F0 = ((struct Obj00327 *)p)->f15C;
        break;
    case 22003:
        result = GDS_RAP_CheckMarkVideoReply(p, state);
        ((struct Obj00327 *)p)->f3F0 = ((struct Obj00327 *)p)->f160;
        break;
    }
    if (result == 0) {
        ((struct Obj00327 *)p)->f168 = 2;
        ((struct Obj00327 *)p)->f16C = state[0];
        ((struct Obj00327 *)p)->f170 = state[1];
        ((struct Obj00327 *)p)->f164 = 1;
    } else ((struct Obj00327 *)p)->f164 = 0;
    return result;
}
int GDS_RAP_GetResult(char *p, int **out)
{
    *out = (int *)(p + 0x164);
    return ((struct Obj23000 *)p)->f164;
}
void GDS_RAP_ClearResult(char *p)
{
    MI_CpuFill8(p + 0x164, 0, 16);
}
