/*
 * function: func_021F9A7C
 * address:  0x021F9A7C
 * packet:   pkt_ov094_021F9A7C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stops every live sound slot of the owner's work (six words at 0x26c, -1 = free).
 *
 * symbols:
 *   func_02011324 0x02011324 thumb
 *   func_02006BB4 0x02006BB4 thumb
 */
typedef unsigned int   u32;
struct ScriptVm;
extern void *func_02011324(struct ScriptVm *vm);
extern void func_02006BB4(u32 i);

void func_021F9A7C(void *a)
{
    char *s = func_02011324(a);
    int i;

    for (i = 0; i < 6; i++) {
        if (((int *)(s + 0x26c))[i] != -1)
            func_02006BB4(((int *)(s + 0x26c))[i]);
    }
}
