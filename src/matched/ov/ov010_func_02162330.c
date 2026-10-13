/*
 * function: EVENT_FIELD_PROCLINK_ClearReturnResultSlotSub
 * address: 0x02162330
 * packet: pkt_ov010_02162330
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * domain: Primary ov011 call 02174C8C reaches this through thunk 02162038.
 *   Its byte counter is zeroed at 02174C64..68, loaded at 02174C88, and
 *   increments/tests against 3 at 02174C90..9A: index 0..2, shifts 5..7.
 *   The record is Work+0x35C (02174C62/6A/8A); 02172BC0 allocates
 *   0x94C bytes and 02161F54 initializes this 0x48-byte record.
 *   Clears cover offsets 0x30..0x47; mask halfword offset 2 is initialized.
 *   No arbitrary-u32 domain claim: all primary arithmetic stays in range.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj12334.h"
typedef unsigned short u16;
extern void func_02082BCC(void *, int, int);
void EVENT_FIELD_PROCLINK_ClearReturnResultSlotSub(char *p, unsigned i) { func_02082BCC(p+0x30+i*8,0,8); ((struct Obj12334 *)p)->f2 = ((struct Obj12334 *)p)->f2 & ~(1<<(i+5)); }
