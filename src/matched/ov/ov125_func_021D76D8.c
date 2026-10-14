/*
 * function: GDS_RAP_StepVideoSave
 * address: 0x021D76D8
 * packet: pkt_ov125_021D76D8
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   GAME_DATA_PartSaveMain 0x02012E7C thumb
 *   func_020072A4 0x020072A4 thumb
 */
struct Sub020072A4Ctrl;
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p); extern int GAME_DATA_PartSaveMain(char *,int); extern void func_020072A4(struct Sub020072A4Ctrl *,unsigned int);
int GDS_RAP_StepVideoSave(char *p,int id) {void *s=GAME_DATA_GetSaveControl((struct Big *)p); int r=GAME_DATA_PartSaveMain(p,id); if(r==2 || r==3) func_020072A4(s,id); return r;}
