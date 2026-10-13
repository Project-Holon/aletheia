/*
 * file:     unit_021DDB24.c
 * unit:     yes
 * function: func_021DDB24, func_021DDB38, func_021DDB44, func_021DDB58
 * address:  0x021DDB24
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
 *   d_021F17AC     0x021F17AC  data   ov093  a4
 *   d_021F171C     0x021F171C  data   ov093  a4
 */
#include "unit_021DD588_types.h"

extern int func_021DDCD8(struct BtlEventFactor *factor, void *server, int pokeId, int *work, int moveType, int ignoreAffinity);

extern int d_021F17AC[];
extern int d_021F171C[];

void func_021DDB24(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021DDB44(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *func_021DDB38(int *handlerCount);
int *func_021DDB58(int *handlerCount);

void func_021DDB24(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    func_021DDCD8(factor, server, pokeId, work, POKETYPE_GRASS, 0);
}

int *func_021DDB38(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F17AC;
}

void func_021DDB44(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    func_021DDCD8(factor, server, pokeId, work, POKETYPE_ICE, 0);
}

int *func_021DDB58(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F171C;
}
