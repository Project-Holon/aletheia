/*
 * function: func_021BC24C
 * address: 0x021BC24C
 * packet: pkt_ov091_021BC24C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
 * blocker: ARM9 0x02019CF8 is an unlabelled Thumb tail-call leaf.
 * The caller's +0x26 THM_CALL has no witness; tu --suggest-split leaves
 * this single caller OUT. Verified leaf C (one, Thumb, no region): EXACT.
 *   extern unsigned int func_02019BBC(unsigned int);
 *   unsigned int func_02019CF8(unsigned int item) {
 *       return func_02019BBC(item);
 *   }
 * The leaf is 8 bytes: ldr r3,[pc,#0]; bx r3; .word 0x02019BBD.
 * ARM9 ownership remains with Ilias.
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_02019CF8 0x02019CF8 thumb
 *   func_02017988 0x02017988 thumb
 */
typedef unsigned int u32;
extern u32 func_02017E1C(void *,u32,u32);
extern int func_02019CF8(int);
extern u32 func_02017988(void *,u32);
void func_021BC24C(void *unused,void *a,int b) { u32 t=0; int r; if(func_02017E1C(a,5,0)==0x1ED) { t=func_02017E1C(a,0x6F,t); r=func_02019CF8(b); if(t!=r)func_02017988(a,r); } }
