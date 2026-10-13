/*
 * file:     unit_021DDBA4.c
 * unit:     yes
 * function: func_021DDBA4, func_021DDBB8, func_021DDBC4, func_021DDBD8
 * address:  0x021DDBA4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DDCD8   0x021DDCD8  thumb
 *   d_021F17DC     0x021F17DC  data   ov093  a4
 *   d_021F172C     0x021F172C  data   ov093  a4
 */
#include "unit_021DD588_types.h"

extern int func_021DDCD8(struct BtlEventFactor *factor, void *server, int pokeId, int *work, int moveType, int ignoreAffinity);

extern int d_021F17DC[];
extern int d_021F172C[];

void func_021DDBA4(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021DDBC4(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *func_021DDBB8(int *handlerCount);
int *func_021DDBD8(int *handlerCount);

void func_021DDBA4(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    func_021DDCD8(factor, server, pokeId, work, POKETYPE_GROUND, 0);
}

int *func_021DDBB8(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F17DC;
}

void func_021DDBC4(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    func_021DDCD8(factor, server, pokeId, work, POKETYPE_FLYING, 0);
}

int *func_021DDBD8(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F172C;
}
