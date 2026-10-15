/*
 * function: MUSICAL_MCSS_SetupRenderObj
 * address: 0x021F5204
 * packet: pkt_ov112_021F5204
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: typed 556-byte slots preserve base spills; u32 secondary index keeps its multiply apart; one 48-byte stack Buffers object fixes the array locations.
 * bounds: 021F5164 allocates 4456 = 8 + 8*556; 5204 loops over 9 tracks and stores the final eight words; 5518 writes all nine stats, 535C forwards the three-word scale.
 * symbols:
 *   MUSICAL_MCSS_GetPokemonArcs 0x021F5518 thumb ov112
 *   MUSICAL_MCSS_LoadMC 0x021F611C thumb ov112
 *   MUSICAL_MCSS_NoOp8 0x021F62DC thumb ov112
 *   MUSICAL_MCSS_GetRenderRot 0x021F535C thumb ov112
 *   MUSICAL_MCSS_GetFieldE 0x021F6290 thumb ov112
 */
#include "../include/Obj22535.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void MUSICAL_MCSS_GetPokemonArcs(u8 *,u32 *,u32);
extern char *MUSICAL_MCSS_LoadMC(char *,u32,u32,u32,u32,u32,u32);
extern void MUSICAL_MCSS_NoOp8(char *);
extern void MUSICAL_MCSS_GetRenderRot(int *,int *);
extern void MUSICAL_MCSS_GetFieldE(u8 *);
typedef struct { u32 value; u8 pad[52]; } Track;
typedef struct {
    u32 active, enabled;
    u8 *object;
    char *primary, *secondary;
    Track tracks[9];
    u32 f524, f528, f532, f536, f540, f544, f548, f552;
} Slot;
typedef struct { u32 heap; char *main; Slot slots[8]; } Scene;
typedef struct { u32 stats[9]; int scale[3]; } Buffers;
u8 *MUSICAL_MCSS_SetupRenderObj(Scene *p,const u8 *b,int c)
{
    int i;
    int j;
    u8 *slot;
    Buffers buffers;
    char *second;
    for(i=0;i<8;i++) if(p->slots[i].active==0) break;
    slot=(u8 *)&p->slots[i];
    ((struct Obj22535 *)slot)->f0=1;
    MUSICAL_MCSS_GetPokemonArcs((u8 *)b,buffers.stats,0);
    p->slots[i].primary=MUSICAL_MCSS_LoadMC(p->main,0,0,0,(u32)buffers.stats,(u32)slot,0);
    if(c==1) {
        MUSICAL_MCSS_GetPokemonArcs((u8 *)b,buffers.stats,1);
        p->slots[(u32)i].secondary=MUSICAL_MCSS_LoadMC(p->main,0,0,0,(u32)buffers.stats,(u32)slot,0);
        MUSICAL_MCSS_NoOp8(p->slots[(u32)i].secondary);
    } else p->slots[i].secondary=0;
    p->slots[i].enabled=1;
    p->slots[i].object=(u8 *)p->slots[i].primary;
    buffers.scale[0]=65536;
    buffers.scale[1]=65536;
    buffers.scale[2]=4096;
    for(j=0;j<9;j++) p->slots[i].tracks[j].value=0;
    p->slots[i].f548=0;
    p->slots[i].f552=0;
    p->slots[i].f524=0;
    p->slots[i].f528=0;
    p->slots[i].f532=0;
    p->slots[i].f536=0;
    p->slots[i].f540=0;
    p->slots[i].f544=0;
    MUSICAL_MCSS_GetRenderRot((int *)&p->slots[i],buffers.scale);
    MUSICAL_MCSS_GetFieldE(p->slots[i].object);
    return (u8 *)&p->slots[i];
}
