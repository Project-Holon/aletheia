/*
 * file:     sta_act_audience.c
 * unit:     yes
 * function: STA_ACT_AUDIENCE_Create, STA_ACT_AUDIENCE_Delete, STA_ACT_AUDIENCE_Update, STA_ACT_AUDIENCE_Noop, STA_ACT_AUDIENCE_Noop2, STA_ACT_AUDIENCE_SetupRecords, STA_ACT_AUDIENCE_Noop3, STA_ACT_AUDIENCE_UpdateRecords, STA_ACT_AUDIENCE_UpdateRecord, STA_ACT_AUDIENCE_DrawRecord, STA_ACT_AUDIENCE_ApplyChoices, STA_ACT_AUDIENCE_RandomizeRecords, STA_ACT_AUDIENCE_SetSlotValue, STA_ACT_AUDIENCE_SetHighlight, STA_ACT_AUDIENCE_SetBgScroll
 * address:  0x021F9FEC
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from sta_acting.c, script_command.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   STA_ACT_AUDIENCE_Create 0x021F9FEC thumb ov132
 *   STA_ACT_AUDIENCE_Delete 0x021FA04C thumb ov132
 *   GFL_HEAP_Free 0x020307B0 arm
 *   STA_ACT_AUDIENCE_Update 0x021FA064 thumb ov132
 *   STA_ACT_LIGHT_CopyActorPos 0x021F8044 thumb ov112
 *   STA_ACT_LIGHT_GetElemPos 0x021F6F04 thumb ov112
 *   STA_ACT_AUDIENCE_SetBgScroll 0x021FA57C thumb ov132
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   STA_ACT_AUDIENCE_SetSlotValue 0x021FA558 thumb ov132
 *   STA_ACT_AUDIENCE_SetHighlight 0x021FA56C thumb ov132
 *   GFL_USE_GetRandomBelow 0x02005728 thumb
 *   d_021FDCC4 0x021FDCC4 data a4
 *   STA_ACTING_GetCameraPos 0x021F9DFC thumb ov132
 *   MUSICAL_PROGRAM_GetCategoryBonus 0x0215725C thumb ov010
 *   STA_ACTING_GetCameraScrollX 0x021F9E04 thumb ov132
 *   STA_ACTING_GetActorSystem 0x021F9DA0 thumb ov132
 *   STA_ACTING_GetActor 0x021F9DA4 thumb ov132
 *   STA_ACTING_GetCharSystem 0x021F9DD4 thumb ov132
 *   STA_ACTING_GetCharSlot 0x021F9DDC thumb ov132
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   d_021FDC16 0x021FDC16 data a2
 *   _fdiv                        0x0209CE10  arm
 *   _ffix                        0x0209C494  arm
 *   _fflt                        0x0209BDBC  arm
 *   _ffltu                       0x0209BE04  arm
 *   _fsub                        0x0209CB8C  arm
 */
#include "ov132_types.h"
#include "sta_acting_shared_types.h"

#include "../ov112/sta_act_poke.h"


#include "../arm9/gfl_heap_wrap.h"


#include "sta_acting.h"

#include "../arm9/gfl_use.h"
struct MusicalShowProgram;

#include "../ov010/musical_program.h"






#include "../ov112/sta_act_light.h"

#include "../arm9/bg_sys.h"



char *STA_ACT_AUDIENCE_Create(unsigned heap, void *a, void *b);

void STA_ACT_AUDIENCE_Delete(u8 *p);

void STA_ACT_AUDIENCE_Update(char *p);

void STA_ACT_AUDIENCE_Noop(char *audience);

void STA_ACT_AUDIENCE_Noop2(void *p);

void STA_ACT_AUDIENCE_SetupRecords(char *p, char *q);

void STA_ACT_AUDIENCE_Noop3(void *audience);

void STA_ACT_AUDIENCE_UpdateRecords(char *p);

void STA_ACT_AUDIENCE_UpdateRecord(char *p,u8 *rec);

void STA_ACT_AUDIENCE_DrawRecord(char *p,u8 *rec,unsigned type);

void STA_ACT_AUDIENCE_ApplyChoices(char *p);

void STA_ACT_AUDIENCE_RandomizeRecords(char *p);

void STA_ACT_AUDIENCE_SetSlotValue(char *p, int i, int v);

void STA_ACT_AUDIENCE_SetHighlight(char *p, u8 v);

void STA_ACT_AUDIENCE_SetBgScroll(void *unused, int x);

extern const char d_021FDCC4[];

extern u16 d_021FDC16[];

char *STA_ACT_AUDIENCE_Create(unsigned heap, void *scene, void *input)
{
    u8 i = 0;
    char *p = GFL_HEAP_Alloc(heap, sizeof(struct ActAudience), 0, d_021FDCC4, 115);
    ((struct ActAudience *)p)->heapId = heap;
    STA_ACT_AUDIENCE_Noop(p);
    STA_ACT_AUDIENCE_SetupRecords(p, (char *)input);
    ((struct ActAudience *)p)->scene = scene;
    ((struct ActAudience *)p)->dirty = 0;
    for (; i < 4; i++) ((struct ActAudience *)p)->choices[i] = 0;
    ((struct ActAudience *)p)->highlight = 255;
    return p;
}

void STA_ACT_AUDIENCE_Delete(u8 *p)
{
    STA_ACT_AUDIENCE_Noop3(p);
    STA_ACT_AUDIENCE_Noop2(p);
    GFL_HEAP_Free(p);
}

/*
 * extent: compiled ends 021FA0CE; two zero padding bytes before labelled 021FA0D0.
 */
void STA_ACT_AUDIENCE_Update(char *p)
{
    u8 i;
    if (STA_ACTING_GetCameraPos(((struct ActAudience *)p)->scene) == 0) {
        if (GFL_USE_GetRandomBelow(10) == 0) {
            for (i = 0; i < 3; i++) {
                u8 a = GFL_USE_GetRandomBelow(4);
                u8 b = GFL_USE_GetRandomBelow(60);
                STA_ACT_AUDIENCE_DrawRecord(p, (u8 *)((u8 *)&((struct ActAudience *)p)->records + b * 8), a);
            }
        }
    } else {
        if (((struct ActAudience *)p)->dirty == 1) {
            STA_ACT_AUDIENCE_ApplyChoices(p);
            ((struct ActAudience *)p)->dirty = 0;
        }
        STA_ACT_AUDIENCE_UpdateRecords(p);
    }
}

void STA_ACT_AUDIENCE_Noop(char *audience) { }

void STA_ACT_AUDIENCE_Noop2(void *p) { }

#pragma opt_common_subs off

/*
 * note 2026-10-05: needs per-function opt_common_subs off (the original does not share
 * idx*8 between the record stores and the call argument; without the pragma only
 * the rec/off register pair is swapped). Callee STA_ACT_AUDIENCE_DrawRecord takes (p, rec, type).
 * Caller passes q as a pointer: field 0x14 is a byte table read by MUSICAL_PROGRAM_GetCategoryBonus.
 */
void STA_ACT_AUDIENCE_SetupRecords(char *p, char *input)
{
    u16 sum = 0;
    u8 b[4];
    u8 a[4] = {0, 0, 0, 0};
    u8 c[60];
    u8 n = 0;
    u8 i, j, k, g, x, idx;
    int base;
    u8 r;
    int off;
    u8 *rec;
    for (i = 0; i < 4; i++) {
        b[i] = MUSICAL_PROGRAM_GetCategoryBonus((struct MusicalShowProgram *)(((struct ActingInput *)input)->program), i);
        sum = sum + b[i];
    }
    for (i = 0; i < 4; i++) {
        a[i] = (b[i] * 60) / sum;
        n = n + a[i];
    }
    for (; n < 60; n++)
        a[GFL_USE_GetRandomBelow(4)]++;
    k = 0;
    for (i = 0; i < 4; i++)
        for (j = 0; j < a[i]; j++) {
            c[k] = i;
            k++;
        }
    for (r = 0; r < 3; r++) {
        for (i = 0; i < 60; i++) {
            u8 t;
            x = GFL_USE_GetRandomBelow(60);
            t = c[i];
            c[i] = c[x];
            c[x] = t;
        }
    }
    for (g = 0; g < 5; g++) {
        i = 0;
        base = g * 12;
        for (; i < 12; i++) {
            idx = i + base;
            off = idx * 8;
            rec = (u8 *)(p + off);
            ((struct ActAudience *)rec)->records[0].state = i + 2;
            ((struct ActAudience *)rec)->records[0].rowOffset = g;
            ((struct ActAudience *)rec)->records[0].tileIndex = c[idx];
            ((struct ActAudience *)rec)->records[0].timer = GFL_USE_GetRandomBelow(60) + 1;
            ((struct ActAudience *)rec)->records[0].actorIndex = 0xff;
            if (i < 2)
                STA_ACT_AUDIENCE_DrawRecord(p, (u8 *)((u8 *)&((struct ActAudience *)p)->records + off), 3);
            else if (i < 4)
                STA_ACT_AUDIENCE_DrawRecord(p, (u8 *)((u8 *)&((struct ActAudience *)p)->records + off), 2);
            else if (i < 6)
                STA_ACT_AUDIENCE_DrawRecord(p, (u8 *)((u8 *)&((struct ActAudience *)p)->records + off), 1);
            else
                STA_ACT_AUDIENCE_DrawRecord(p, (u8 *)((u8 *)&((struct ActAudience *)p)->records + off), 0);
        }
    }
}

#pragma opt_common_subs reset

void STA_ACT_AUDIENCE_Noop3(void *audience)
{
}

/*
 * Lever: keep the declared base but expand p+0x204 at the call; named base left a four-byte r5/r6 swap.
 * trailing: Two zero alignment bytes.
 */
void STA_ACT_AUDIENCE_UpdateRecords(char *p)
{
  u8 i = 0;
  u8 *base = (u8 *) ((u8 *)&((struct ActAudience *)p)->records);
  for (; i < 60; i++)
    STA_ACT_AUDIENCE_UpdateRecord(p, ((u8 *) ((u8 *)&((struct ActAudience *)p)->records)) + (i * 8));

}

void STA_ACT_AUDIENCE_UpdateRecord(char *p,u8 *rec)
{
    StaActingVec v;
    void *a,*b;
    u16 x;
    short delta;
    if(rec[1]!=0) rec[1]--;
    if(rec[1]==0) {
        if(rec[0]==255 && ((struct ActAudience *)p)->highlight==255) {
            ((struct AudienceRecord *)rec)->value=65535;
            if(rec[6]<2) STA_ACT_AUDIENCE_DrawRecord(p,rec,3);
            else if(rec[6]<4) STA_ACT_AUDIENCE_DrawRecord(p,rec,2);
            else if(rec[6]<6) STA_ACT_AUDIENCE_DrawRecord(p,rec,1);
            else STA_ACT_AUDIENCE_DrawRecord(p,rec,0);
        } else {
            STA_ACTING_GetCameraScrollX(((struct ActAudience *)p)->scene);
            x=((rec[6]*32-64)*4)/3;
            if(rec[0]!=255) {
                a=STA_ACTING_GetActorSystem(((struct ActAudience *)p)->scene);
                STA_ACT_LIGHT_CopyActorPos(a,STA_ACTING_GetActor(((struct ActAudience *)p)->scene,rec[0]),(u32 *)(&v));
            } else {
                b=STA_ACTING_GetCharSystem((void *)(((struct ActAudience *)p)->scene));
                STA_ACT_LIGHT_GetElemPos((void *)b,(char *)STA_ACTING_GetCharSlot((void *)(((struct ActAudience *)p)->scene),((struct ActAudience *)p)->highlight),(StaActLightVec3 *)&v);
            }
            delta=(float)v.x/4096.f-(float)(u32)x;
            if(delta < -64) STA_ACT_AUDIENCE_DrawRecord(p,rec,0);
            else if(delta >64) STA_ACT_AUDIENCE_DrawRecord(p,rec,3);
            else if(delta<0) STA_ACT_AUDIENCE_DrawRecord(p,rec,1);
            else STA_ACT_AUDIENCE_DrawRecord(p,rec,2);
        }
        rec[1]=GFL_USE_GetRandomBelow(60)+1;
    }
}

/*
 * ABI: 41300 caller truncates tile to u16 and coordinates to u8 before each call.
 */
void STA_ACT_AUDIENCE_DrawRecord(char *p,u8 *rec,unsigned type)
{
    u16 tile;
    int reverse=0;
    u8 row,col,x;
    u32 t;
    switch(type) {
    case 3: reverse=1; tile=*(u16 *)((uptr)d_021FDC16+rec[2]*2)+0x400; break;
    case 2: reverse=1; tile=*(u16 *)((uptr)d_021FDC16+rec[2]*2)+0x404; break;
    case 1: tile=*(u16 *)((uptr)d_021FDC16+rec[2]*2)+4; break;
    case 0: tile=*(u16 *)((uptr)d_021FDC16+rec[2]*2); break;
    }
    for(row=0;row<4;row++) {
        for(col=0;col<4;col++) {
            if(reverse==1) x=3-col+rec[6]*4;
            else x=col+rec[6]*4;
            t=tile+col+row*32;
            BG_SYS_SetTileEntry(4,tile+col+row*32,x,row+rec[7]*4+2,1,1,0);
            BG_SYS_SetTileEntry(6,t,x,row+rec[7]*4+5,1,1,0);
        }
    }
    BG_SYS_MarkTileDirty(4);
    BG_SYS_MarkTileDirty(6);
}

void STA_ACT_AUDIENCE_ApplyChoices(char *p)
{
    u8 i;
    u8 n = 0;
    u8 choices[4] = {0, 0, 0, 0};
    for (i = 0; i < 4; i++) {
        if (((struct ActAudience *)p)->choices[i] == 1) { choices[n] = i; n++; }
    }
    if (n == 0) STA_ACT_AUDIENCE_RandomizeRecords(p);
    else {
        for (i = 0; i < 60; i++) {
            ((struct ActAudience *)p)->records[i].timer = GFL_USE_GetRandomBelow(60) + 1;
            ((struct ActAudience *)p)->records[i].actorIndex = choices[GFL_USE_GetRandomBelow(n)];
        }
    }
}

void STA_ACT_AUDIENCE_RandomizeRecords(char *p)
{
    u8 i;
    for (i = 0; i < 60; i++) {
        char *q = p + i * 8;
        ((struct ActAudience *)q)->records[0].timer = GFL_USE_GetRandomBelow(60) + 1;
        ((struct ActAudience *)q)->records[0].actorIndex = 255;
    }
}

void STA_ACT_AUDIENCE_SetSlotValue(char *p, int player, int value)
{
    char *q = p + player * 4;

    ((struct ActAudience *)q)->choices[0] = value;
    ((struct ActAudience *)p)->dirty = 1;
}

void STA_ACT_AUDIENCE_SetHighlight(char *p, u8 actor)
{
    ((struct ActAudience *)p)->highlight = actor;
    ((struct ActAudience *)p)->dirty = 1;
}

void STA_ACT_AUDIENCE_SetBgScroll(void *unused, int scroll)
{
    u16 v = ((scroll << 7) / 256) + 64;
    BG_SYS_ChangeScrollImmediate(4, 0, v);
    BG_SYS_ChangeScrollImmediate(6, 0, v);
    BG_SYS_ChangeScrollImmediate(5, 0, v);
}
