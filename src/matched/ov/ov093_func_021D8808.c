/*
 * unit: yes
 * function: HAND_TOKUSEI_TangledFeetHalveAccuracy, HAND_TOKUSEI_GetTangledFeetHandlers
 * address: 0x021D8808
 * packet: pkt_ov093_021D8808
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: 021D881C loads r1=c and 021D8822 forwards the returned r0.
 * BTL_SERVER_FLOW_GetPokeParam's legacy void signature is read as a pointer result;
 * its ldr r0,[r0,#8] tail forwards the full-word payload unchanged.
 * symbols:
 *   gTangledFeetHandlers 0x021F0668 data ov093 a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 gTangledFeetHandlers[];
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_MultiplyVar(int,int);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
void HAND_TOKUSEI_TangledFeetHalveAccuracy(int a,int b,int c) { if (c==BTL_EVENT_GetVar(4)) { if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam((int *)b,c),6)) BTL_EVENT_MultiplyVar(53,2048); } }
u8 *HAND_TOKUSEI_GetTangledFeetHandlers(u32 *p) { *p=1; return gTangledFeetHandlers; }
