/*
 * function: EVENT_FIELD_PROCLINK_ClearReturnSlot
 * address: 0x0216230C
 * packet: pkt_ov010_0216230C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * domain: Primary calls at 0216213C/0216216E receive loop index 0..2
 *   from 02162120 (zero at 0216212A; increment/test at 02162188..18C).
 *   ov011 02172D70 passes Work+0x35C through 02161F74 to 02162120.
 *   02172BC0 allocates 0x94C bytes and initializes that 0x48-byte record
 *   with 02161F54. The clear spans offsets 8..31; the mask reads offset 2.
 *   Thus primary shift counts 0..2 are defined; no arbitrary-u32 domain claim.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj07292.h"
typedef unsigned short u16;
extern void MI_CpuFill8(void *, int, int);
void EVENT_FIELD_PROCLINK_ClearReturnSlot(char *p, unsigned i) { MI_CpuFill8(p+8+i*8,0,8); ((struct Obj07292 *)p)->f2 = ((struct Obj07292 *)p)->f2 & ~(1<<i); }
