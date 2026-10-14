/*
 * function: ZUKAN_DETAIL_VOICE_SwitchPokemonSlot
 * address: 0x021C34A4
 * packet: pkt_ov208_021C34A4
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   ZUKAN_DETAIL_VOICE_ClearTimerWindow 0x021C32FC thumb ov208
 *   ZUKAN_DETAIL_VOICE_UnloadPokemonGraphics 0x021C2FEC thumb ov208
 *   ZUKAN_DETAIL_VOICE_LoadPokemonGraphics 0x021C2E6C thumb ov208
 *   ZUKAN_DETAIL_VOICE_DrawSpeciesName 0x021C3280 thumb ov208
 *   ZUKAN_DETAIL_VOICE_StopVoice 0x021C3480 thumb ov208
 *   ZUKAN_DETAIL_VOICE_InitWaveformState 0x021C3678 thumb ov208
 */
#include "../include/Obj00146.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p,u32 v);
extern void ZUKAN_DETAIL_VOICE_ClearTimerWindow(u16 *heap,u8 *p,int key);
struct S;
extern void ZUKAN_DETAIL_VOICE_UnloadPokemonGraphics(void *unused, struct S *p, u32 unused2, u32 i);
extern void ZUKAN_DETAIL_VOICE_LoadPokemonGraphics(u16 *heap, u8 *p, int key, u32 slot);
struct Key;
extern void ZUKAN_DETAIL_VOICE_DrawSpeciesName(u16 *heap, u8 *p, struct Key *key);
extern void ZUKAN_DETAIL_VOICE_StopVoice(int unused, char *p, int key);
extern void ZUKAN_DETAIL_VOICE_InitWaveformState(u16 *heap,u8 *p,int key);
void ZUKAN_DETAIL_VOICE_SwitchPokemonSlot(u16 *heap,u8 *p,int key)
{
    if(*(struct Obj **)(p+((struct Obj00146 *)p)->f5C*4+0x54))
        CLACT_SetActorDrawEnable(*(struct Obj **)(p+((struct Obj00146 *)p)->f5C*4+0x54),0);
    ((struct Obj00146 *)p)->f5C=(((struct Obj00146 *)p)->f5C+1)%2;
    ZUKAN_DETAIL_VOICE_ClearTimerWindow(heap,p,key);
    ZUKAN_DETAIL_VOICE_UnloadPokemonGraphics(heap,(struct S *)p,key,((struct Obj00146 *)p)->f5C);
    ZUKAN_DETAIL_VOICE_LoadPokemonGraphics(heap,p,key,((struct Obj00146 *)p)->f5C);
    ZUKAN_DETAIL_VOICE_DrawSpeciesName(heap,p,(struct Key *)key);
    ZUKAN_DETAIL_VOICE_StopVoice((int)heap,(char *)p,key);
    ZUKAN_DETAIL_VOICE_InitWaveformState(heap,p,key);
}
