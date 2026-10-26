/*
 * pokemontrade_demo_types.h: types of the pokemontrade demo files of ov117 and
 * ov118. The demo work object is the ov119 TradeWork; the animation block is
 * the ov119 ParticleManager.
 */
#ifndef POKEMONTRADE_DEMO_TYPES_H
#define POKEMONTRADE_DEMO_TYPES_H

#include "../ov119/pokemontrade_types.h"

/* Button-emitter user data reached through PARTICLE_EMITTER_GetUserData. The object
 * holds a pointer at 0xC to the emitter's ICA animation record, whose anime
 * handle sits at 0x98 and whose second handle sits at 0x9C. */
typedef struct {
    unsigned char pad_0[0x98];
    void         *anime;                 /* 0x98 */
    void         *animeB;                /* 0x9C */
} PokeTradeButtonAnim;

typedef struct {
    unsigned char        pad_0[0xC];
    PokeTradeButtonAnim *anim;           /* 0x0C */
} PokeTradeButtonData;

#endif
