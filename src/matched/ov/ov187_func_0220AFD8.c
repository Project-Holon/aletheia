/*
 * function: BR_MAIN_Main
 * address: 0x0220AFD8
 * packet: pkt_ov187_0220AFD8
 * region: ov187
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_MAIN_RunSceneStep 0x0220B02C thumb ov187
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct State;
extern int BR_MAIN_RunSceneStep(struct State *p);
int BR_MAIN_Main(void *a,int *state,int b,void *p) { switch(*state) { case 0: *state=1; break; case 1: if(BR_MAIN_RunSceneStep(p)) *state=2; break; case 2: return 1; } return 0; }
