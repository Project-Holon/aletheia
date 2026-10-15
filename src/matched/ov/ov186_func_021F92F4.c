/*
 * function: BR_PROC_SYS_Main
 * address: 0x021F92F4
 * packet: pkt_ov186_021F92F4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   BR_FADE_Update 0x021FE768 thumb ov186
 *   BR_SIDEBAR_Update 0x021FEE00 thumb ov186
 *   BR_PROC_SYS_RunSlot 0x021F9A80 thumb ov186
 *   BR_GRAPHIC_Draw 0x021FC4C8 thumb ov186
 *   BR_NET_Main 0x021FF52C thumb ov186
 *   BR_PROC_SYS_IsDone 0x021F9B98 thumb ov186
 */
typedef signed int     s32;
typedef unsigned int   u32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
typedef struct {int x[3];} S;
extern void BR_FADE_Update(S *);
extern void BR_SIDEBAR_Update(char *p);
extern void BR_PROC_SYS_RunSlot(char *p);
extern void BR_GRAPHIC_Draw(char *);
extern void BR_NET_Main(char *p);
extern int BR_PROC_SYS_IsDone(int *p);
int BR_PROC_SYS_Main(int sys,int *state,int unused,int *p)
{
    switch(*state) {
    case 0: *state=1; break;
    case 1: FADE_Start(3,16,0,0); *state=2; break;
    case 2: if(!FADE_IsActive()) *state=3; break;
    case 3:
        BR_FADE_Update((S *)p[3]);
        BR_SIDEBAR_Update((char *)p[4]);
        BR_PROC_SYS_RunSlot((char *)p[2]);
        BR_GRAPHIC_Draw((char *)p[0]);
        if(p[5]) BR_NET_Main((char *)p[5]);
        if(BR_PROC_SYS_IsDone((int *)p[2])) *state=4;
        break;
    case 4: FADE_Start(3,0,16,0); *state=5; break;
    case 5: if(!FADE_IsActive()) *state=6; break;
    case 6: return 1;
    }
    return 0;
}
