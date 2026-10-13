/*
 * function: SCRCMD_WORK_Create
 * address: 0x0215A55C
 * packet: pkt_ov010_0215A55C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: const source pointer hoists its copy before the destination id store.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   SCRIPT_WORK_GetCmdWork 0x02158F6C thumb ov010
 *   sScrcmdWorkFileName 0x021728E0 data ov010 a4
 */
#include "../include/Obj05883.h"
typedef struct { int w[4]; } S16;
typedef struct { unsigned short id; S16 r; } T;
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern unsigned int SCRIPT_WORK_GetCmdWork(void *);
extern int sScrcmdWorkFileName;
void *SCRCMD_WORK_Create(const S16 *src, int v)
{
    T *p;
    const S16 *s;
    p = (T *)func_02030734((unsigned short)((v & 0x7fff) | 0x8000), 0x24, 1, (const char *)&sScrcmdWorkFileName, 0x94);
    s = src;
    p->id = v;
    p->r = *s;
    ((struct Obj05883 *)p)->f20 = SCRIPT_WORK_GetCmdWork((void *)src->w[3]);
    return p;
}
