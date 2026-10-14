/*
 * unit: yes
 * function: GURU2_MAIN_UpdateScreenFlash, GURU2_MAIN_ScreenFlashTask
 * address: 0x021E1320
 * packet: pkt_ov137_021E1320
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021E13A8 tail-forwards r1 and r1+0xC88 to this callback.
 * symbols:
 *   GURU2_MAIN_LoadScreen26 0x021DFEA0 thumb ov137
 *   GURU2_MAIN_LoadScreen24 0x021DFEAC thumb ov137
 *   GURU2_MAIN_LoadScreen25 0x021DFEB8 thumb ov137
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
typedef unsigned short u16;
typedef struct { u16 state, flag; int count; } State;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void GURU2_MAIN_LoadScreen26(u8 *p);
extern void GURU2_MAIN_LoadScreen24(u8 *p);
extern void GURU2_MAIN_LoadScreen25(u8 *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void GURU2_MAIN_UpdateScreenFlash(void *task, State *p)
{
    switch (p->state) {
    case 0: break;
    case 1:
        GURU2_MAIN_LoadScreen26(task);
        GFL_USE_PlaySeDefaultVolume(1832);
        p->count = 0;
        p->state++;
    case 2:
        p->count++;
        if (p->count >= 2) {
            p->count = 0;
            p->state++;
            GURU2_MAIN_LoadScreen25(task);
        }
        break;
    case 3:
        p->count++;
        if (p->count >= 4) {
            GURU2_MAIN_LoadScreen26(task);
            p->count = 0;
            p->state++;
        }
        break;
    case 4:
        p->count++;
        if (p->count >= 2) {
            GURU2_MAIN_LoadScreen24(task);
            p->flag = 0;
            p->state = 0;
        }
        break;
    }
}
void GURU2_MAIN_ScreenFlashTask(void *unused, char *p)
{
    GURU2_MAIN_UpdateScreenFlash(p, (State *)(p + 0xc88));
}
