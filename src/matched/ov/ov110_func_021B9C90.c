/*
 * function: PMS_INPUT_VIEW_IsTaskNotRunning
 * address: 0x021B9C90
 * packet: pkt_ov110_021B9C90
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Two-byte zero alignment padding follows the compiled function.
 * symbols:
 *   TCBL_IsDeletePending 0x02030EE8 arm
 */
typedef unsigned int   u32;
struct S02030EE8;
extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);
int PMS_INPUT_VIEW_IsTaskNotRunning(unsigned int a,int b) { int i; int value; for(i=0;i<4;i++) if(*(void **)(a+(unsigned)i*4+8)) { value=*(int *)(TCBL_IsDeletePending(*(void **)(a+(unsigned)i*4+8))+12); if(value==b) return 0; } return 1; }
