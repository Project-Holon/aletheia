#ifndef GAME_OV119_POKEMONTRADE_3D_H
#define GAME_OV119_POKEMONTRADE_3D_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokemontrade_3d.c, prototypes copied from their definitions. */

struct ParticleManager;
typedef struct ParticleManager ParticleManager;

#include "../ov119/pokemontrade_types.h"
#include "../types.h"

void POKETRADE_3D_CreateIcaStreamsForMode(ParticleManager *p,unsigned mode);
void POKETRADE_3D_DeleteIcaStreams(ParticleManager *p);
void POKETRADE_3D_CreateIcaStreamsEnding(ParticleManager *p);
void POKETRADE_3D_FreeParticleResources(ParticleManager *particles);
void POKETRADE_3D_InitParticleSystems(ParticleManager *p);
void POKETRADE_3D_SetupParticleSystemsLow(ParticleManager *p);
void POKETRADE_3D_SetupParticleSystemsHigh(ParticleManager *p);
void POKETRADE_3D_ExitParticleManager(ParticleManager *p, int unused);
void POKETRADE_3D_InitTradeParticleSet(ParticleManager *p);
void POKETRADE_3D_Init3DScene(char *p);
void POKETRADE_3D_Update3DScene(void *p);
void POKETRADE_3D_Delete3DScene(char *p);
void POKETRADE_3D_UploadCubeTextures(void *p);
void POKETRADE_3D_AddUnitAndInit(void *p, int a);
void POKETRADE_3D_RemoveCurrentUnit(void *p);
void POKETRADE_3D_AddUnit(char *p,int n);
void POKETRADE_3D_RemoveUnit(char *p);
void POKETRADE_3D_Draw3DScene(char *p);
void POKETRADE_3D_SetMcssOffsetForSpecies(void *mcss, int *dir, int side, void *mon);
void POKETRADE_3D_AddPokemonMcss(TradeWork *p, int idx, int side, void *mon, int flag);
void POKETRADE_3D_AddPokemonMcssFlipped(void *a, int b, int c, void *d, int e, int f);
void POKETRADE_3D_AddPokemonMcssPlain(void *a, int b, int c, void *d, int e);
void POKETRADE_3D_DeleteMcssSlot(void *p, int idx);
void POKETRADE_3D_EmitCubeVertex(int n);
void POKETRADE_3D_SetCubeNormal(int n);
void POKETRADE_3D_SetCubeTexCoord(int n);
void POKETRADE_3D_FillTextureCell(unsigned short *p, int x, int y, int colour);
void POKETRADE_3D_FillTexturePage(u16 *p, u8 *src, int k, int unused);
void POKETRADE_3D_FillTextureHeader(u16 *p, u8 *src, int unused);
void POKETRADE_3D_UploadTexturePages(char *p, int count);
void POKETRADE_3D_SetToonEdgeColors(int a, int b);
void POKETRADE_3D_DrawCubeFace(int z,int index,u16 a,int b);
void POKETRADE_3D_DrawRotatingCube(const u8 *p);
void POKETRADE_3D_LoadTexturePalette(char *p);
void POKETRADE_3D_FadeTexturePalette(char *p);
void POKETRADE_3D_CreateTouchbar(char *p);
/* END mkheaders: generated region */

#endif
