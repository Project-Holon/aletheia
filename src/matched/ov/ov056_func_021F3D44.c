/*
 * function: func_021F3D44
 * address: 0x021F3D44
 * packet: pkt_ov056_021F3D44
 * region: ov056
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov056/unit_021F36C0.c and filed here.
 *
 * symbols:
 *   func_02047A60 0x02047A60 arm
 */

extern void func_02047A60(void *, void *);
void func_021F3D44(char *a);

/*
 * note:     heap is u16: the original passes r2 straight to the stack slot
 *           of func_021F4040's u16 parameter (an int heap adds lsls/lsrs).
 */
void func_021F3D44(char *a)
{
    func_02047A60(*(void **)(a + 0x1c), a + 0x20);
}
