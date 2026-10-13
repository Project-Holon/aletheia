/*
 * function: FLDMMDL_SysPushAll
 * address:  0x0216D2AC
 * packet:   pkt_ov010_0216D2AC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_SysCheckDrawInit  0x0216D948  thumb  ov010
 *   FLDMMDL_DeleteMoveTcb  0x0216DFAC  thumb  ov010
 *   FLDMMDL_CallDrawPushProc  0x0216D780  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
struct Rec;
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);
extern int FLDMMDL_SysCheckDrawInit(int a0);
extern int FLDMMDL_DeleteMoveTcb(int a0);
extern void FLDMMDL_CallDrawPushProc(void *a0);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);

void FLDMMDL_SysPushAll(u32 x)
{
    int n;
    u8 *o;
    u32 k = 5;

    n = 0;
    if (FLDMMDL_SysCheckDrawInit(x)) {
        while (FLDMMDL_SysSearchUseMmdl((struct Ctx *)x, (struct Rec **)(&o), (u32 *)(&n)) == 1) {
            FLDMMDL_DeleteMoveTcb((int)o);
            FLDMMDL_CallDrawPushProc(o);
            FLDMMDL_SetMoveBit(o, k);
        }
    }
}
