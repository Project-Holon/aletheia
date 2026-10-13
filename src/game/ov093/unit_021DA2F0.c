/*
 * file:     unit_021DA2F0.c
 * unit: yes
 * function: func_021DA2F0, func_021DA320
 * address: 0x021DA2F0
 * packet: pkt_ov093_021DA2F0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F07F0 0x021F07F0 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 * extent: includes store-and-return followers 021DA320.
 */
#include "unit_021D9ADC_types.h"

extern unsigned char d_021F07F0[];
extern int func_021D775C(int);
extern void *func_021C88A4(char *flowWork, int kind, int pokeId);
extern void func_021C88C8(void *flowWork, void *record);

/* Natural Cure: when the Pokemon leaves the field, cure its status condition. */
void func_021DA2F0(int myHandle, void *flowWork, int pokeId)
{
    struct HandExCureSick *record;
    if (pokeId == func_021D775C(HANDVAR_POKE_ID)) {
        record = func_021C88A4(flowWork, HANDEX_KIND_CURE_SICK, pokeId);
        record->sickKind = 0x24;
        record->pokeCount = 1;
        record->pokeIds[0] = pokeId;
        record->suppressMessage = 1;
        func_021C88C8(flowWork, record);
    }
}

void *func_021DA320(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F07F0;
}
