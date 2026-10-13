/*
 * function: BTL_CLIENT_StartRemoteStep
 * address: 0x021CD984
 * packet: pkt_ov093_021CD984
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Prototype: 021CDA0C stores its r1 payload unchanged at +0x28; caller
 * passes a callback address. Pointer replaces legacy u32 for that payload.
 * symbols:
 *   BTL_REC_ResetReader 0x021EE674 thumb ov093
 *   BTL_ADAPTER_ClearRecvHeader 0x021EEBDC thumb ov093
 *   BTL_CLIENT_StartCounterReplay 0x021D3F64 thumb ov093
 *   BTL_CLIENT_SetStepFn 0x021CDA0C thumb ov093
 *   BTL_CLIENT_StepRemote 0x021CDC0C thumb ov093
 */
#include "../include/Obj07767.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BTL_REC_ResetReader(void *);
extern void BTL_ADAPTER_ClearRecvHeader(void *);
extern void BTL_CLIENT_StartCounterReplay(u8 *,u16);
struct QE;
extern void BTL_CLIENT_SetStepFn(struct QE *p, u32 v);
extern int BTL_CLIENT_StepRemote(u8 *);
void BTL_CLIENT_StartRemoteStep(u8 *p,u16 n) { BTL_REC_ResetReader(((struct Obj07767 *)p)->f14); BTL_ADAPTER_ClearRecvHeader(((struct Obj07767 *)p)->f50); BTL_CLIENT_StartCounterReplay(p+0x18,n); BTL_CLIENT_SetStepFn((struct QE *)p,(u32)BTL_CLIENT_StepRemote); }
