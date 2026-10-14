/*
 * function: GDS_RAP_RequestUploadVideo
 * address: 0x021D683C
 * packet: pkt_ov125_021D683C
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GDS_RAP_GetVideoWork 0x021D7700 thumb ov125
 *   GDS_RAP_IsIdle 0x021D730C thumb ov125
 *   GDS_RAP_FindMember 0x021D7154 thumb ov125
 *   GDS_RAP_CopyNickname 0x021D71CC thumb ov125
 *   BATTLE_REC_GetWork 0x0200B910 thumb
 *   BATTLE_REC_GetModeLayout  0x0200B784  thumb  arm9
 *   MI_CpuCopy8  0x02082D44  arm  arm9
 */
#include "../include/Obj06472.h"
#include "../include/Obj22996.h"
typedef unsigned short u16;
extern char *GDS_RAP_GetVideoWork(void);
typedef unsigned int   u32;
struct ObjC4;
extern int GDS_RAP_IsIdle(char *p);
extern void BATTLE_REC_GetModeLayout(u16, int *, int *);
extern int GDS_RAP_FindMember(int, int, int *, int *);
extern void GDS_RAP_CopyNickname(const void *src, void *dst, u32 n);
extern struct ObjC4 *BATTLE_REC_GetWork(void);
extern void MI_CpuCopy8(void *, const void *, unsigned int);
int GDS_RAP_RequestUploadVideo(char *p, void *dst)
{
    char *r;
    char *out;
    char *base;
    int outer, inner;
    int n, m;
    int i;
    r = GDS_RAP_GetVideoWork();
    if (!GDS_RAP_IsIdle(p)) return 0;
    BATTLE_REC_GetModeLayout(((struct Obj22996 *)r)->fA6, &n, &m);
    base = r + 0xd00;
    out = p + 0x498;
    for (i = 0; i < 12; i++) {
        if (!GDS_RAP_FindMember((int)p, i, &outer, &inner)) break;
        GDS_RAP_CopyNickname(base + outer * 676 + inner * 112 + 50, out + i * 22, 11);
    }
    ((struct Obj06472 *)p)->f5A0 = 0;
    p[0x403] = 0;
    *(char * *)&((struct Obj06472 *)p)->f174 = r;
    MI_CpuCopy8(dst, BATTLE_REC_GetWork(), 128);
    p[0x401] = 60;
    ((struct Obj06472 *)p)->f3D8 = 0x55f0;
    return 1;
}
