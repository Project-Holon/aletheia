/*
 * function: BTL_CLIENT_StartMainStep
 * address: 0x021CD9B0
 * packet: pkt_ov093_021CD9B0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Prototype: 021CDA0C stores its r1 payload unchanged at +0x28; caller
 * passes a callback address. Pointer replaces legacy u32 for that payload.
 * symbols:
 *   func_021D3F88 0x021D3F88 thumb ov093
 *   BTL_CLIENT_SetStepFn 0x021CDA0C thumb ov093
 *   BTL_CLIENT_StepMain 0x021CDA18 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S;
extern void func_021D3F88(struct S *p);
struct QE;
extern void BTL_CLIENT_SetStepFn(struct QE *p, u32 v);
extern int BTL_CLIENT_StepMain(u8 *);
void BTL_CLIENT_StartMainStep(u8 *p) { func_021D3F88((struct S *)(p+0x18)); BTL_CLIENT_SetStepFn((struct QE *)p,(u32)BTL_CLIENT_StepMain); }
