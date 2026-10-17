/*
 * file:     mus_poke_draw.c
 * unit:     yes
 * function: MUSICAL_MCSS_CreateRenderObj, MUSICAL_MCSS_DeleteRenderObj, MUSICAL_MCSS_TickAnim, MUSICAL_MCSS_DrawRenderObj, MUSICAL_MCSS_SetupRenderObj, MUSICAL_MCSS_FreeRenderObj, MUSICAL_MCSS_GetRenderPos, MUSICAL_MCSS_GetRenderRot, MUSICAL_MCSS_SetRenderFrame, MUSICAL_MCSS_SetRenderMode, MUSICAL_MCSS_GetRenderHandle, MUSICAL_MCSS_GetRenderFieldA, MUSICAL_MCSS_GetRenderFieldB, MUSICAL_MCSS_SetRenderAnim, MUSICAL_MCSS_ResetRender, MUSICAL_MCSS_ResetRender2, MUSICAL_MCSS_GetRenderSize, MUSICAL_MCSS_SetRenderFieldA, MUSICAL_MCSS_SetRenderFieldB, MUSICAL_MCSS_GetRenderElem, MUSICAL_MCSS_GetRenderFlags, MUSICAL_MCSS_GetRenderMatrix, MUSICAL_MCSS_SetMatrix, MUSICAL_MCSS_GetPokemonArcs
 * address:  0x021F5164
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from musical_shot_sys.c, musical_mcss.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free 0x020307B0 arm
 *   MUSICAL_MCSS_DeleteRenderObj 0x021F51B0 thumb ov112
 *   MUSICAL_MCSS_TickAnim 0x021F51E8 thumb ov112
 *   MUSICAL_MCSS_DrawRenderObj 0x021F51F4 thumb ov112
 *   MUSICAL_MCSS_CreateRenderObj 0x021F5164 thumb ov112
 *   MUSICAL_MCSS_SetRenderFieldA 0x021F5438 thumb ov112
 *   BILLBOARD_AddElem 0x0204F428 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   d_021F83C4 0x021F83C4 data a1
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   POKE_TOOL_NormalizeForm 0x02019D30 thumb
 *   POKE_TOOL_FilterSpecies 0x02019D58 thumb
 *   POKEGRA_GetCbrArcIndex 0x0202D09C thumb
 *   POKEGRA_GetPalArcIndex 0x0202D0D4 thumb
 *   POKEGRA_GetCelArcIndex 0x0202D110 thumb
 *   POKEGRA_GetAnmArcIndex 0x0202D144 thumb
 *   POKEGRA_GetMCelArcIndex 0x0202D178 thumb
 *   POKEGRA_GetMAnmArcIndex 0x0202D1AC thumb
 *   POKEGRA_GetNcecArcIndex 0x0202D1E0 thumb
 *   MUSICAL_MCSS_AllocRenderPool 0x021F55F8 thumb ov112
 *   MUSICAL_MCSS_FreeRenderPool 0x021F5644 thumb ov112
 *   MUSICAL_MCSS_TickMCAnim 0x021F5678 thumb ov112
 *   MUSICAL_MCSS_DrawMC 0x021F56BC thumb ov112
 *   MUSICAL_MCSS_LoadMC 0x021F611C thumb ov112
 *   MUSICAL_MCSS_FreeMC 0x021F61D8 thumb ov112
 *   MUSICAL_MCSS_NoOp7 0x021F621C thumb ov112
 *   MUSICAL_MCSS_SetFieldA 0x021F622C thumb ov112
 *   MUSICAL_MCSS_SetFieldB 0x021F6230 thumb ov112
 *   MUSICAL_MCSS_GetFieldA 0x021F6234 thumb ov112
 *   MUSICAL_MCSS_GetFieldB 0x021F624C thumb ov112
 *   MUSICAL_MCSS_SetFieldC 0x021F6264 thumb ov112
 *   MUSICAL_MCSS_GetFieldC 0x021F626C thumb ov112
 *   MUSICAL_MCSS_GetFieldD 0x021F6280 thumb ov112
 *   MUSICAL_MCSS_GetFieldE 0x021F6290 thumb ov112
 *   MUSICAL_MCSS_GetFieldF 0x021F62A0 thumb ov112
 *   MUSICAL_MCSS_SetMCAnim 0x021F62B0 thumb ov112
 *   MUSICAL_MCSS_GetFieldG 0x021F62D0 thumb ov112
 *   MUSICAL_MCSS_NoOp8 0x021F62DC thumb ov112
 *   MUSICAL_MCSS_NoOp9 0x021F62EC thumb ov112
 *   MUSICAL_MCSS_CopyField 0x021F62FC thumb ov112
 */
#include "musical_shot_sys_shared_types.h"
#include "mus_item_draw_shared_types.h"
#include "mus_poke_draw_shared_types.h"

extern u32 GFL_HEAP_Free(void *p);

typedef struct { int f0, f4, active; } Fields;

typedef struct { u32 value; u8 pad[52]; } Track;

typedef struct {
    u32 active, enabled;
    u8 *object;
    char *primary, *secondary;
    Track tracks[9];
    u32 f524, f528, f532, f536, f540, f544, f548, f552;
} Slot;

/* The render object (allocated 4456 bytes by CreateRenderObj): a halfword heap
   id, then the render pool pointer and 8 slots. heap is stored as a u16. */
typedef struct { u16 heap; u16 pad_2; char *main; Slot slots[8]; } Scene;

typedef struct { u32 stats[9]; int scale[3]; } Buffers;

extern void *GFL_HEAP_Alloc(u32, u32, int, const char *, u16);

extern void *POKE_TOOL_GetBoxParam(void *p);

extern u32 POKE_TOOL_NormalizeForm(u32, u32);

extern int POKE_TOOL_FilterSpecies(u16 a, int b);

extern int POKEGRA_GetCbrArcIndex(u32,u32,u32,u32,u32,u32,u32);

extern int POKEGRA_GetPalArcIndex(u32,u32,u32,u32,u32,u32,u32);

extern int POKEGRA_GetCelArcIndex(u32,u32,u32,u32,u32,u32,u32);

extern int POKEGRA_GetAnmArcIndex(u32,u32,u32,u32,u32,u32,u32);

extern int POKEGRA_GetMCelArcIndex(u32,u32,u32,u32,u32,u32,u32);

extern int POKEGRA_GetMAnmArcIndex(u32,u32,u32,u32,u32,u32,u32);

extern int POKEGRA_GetNcecArcIndex(u32,u32,u32,u32,u32,u32,u32);

void *MUSICAL_MCSS_CreateRenderObj(u32 heap);

void MUSICAL_MCSS_DeleteRenderObj(int a);

void MUSICAL_MCSS_TickAnim(u8 *p);

void MUSICAL_MCSS_DrawRenderObj(void **p);

u8 *MUSICAL_MCSS_SetupRenderObj(Scene *p,const u8 *b,int c);

void MUSICAL_MCSS_FreeRenderObj(int a, int b);

void MUSICAL_MCSS_GetRenderPos(int *p, int *q);

void MUSICAL_MCSS_GetRenderRot(int *p, int *q);

void MUSICAL_MCSS_SetRenderFrame(int *p, unsigned short v);

void MUSICAL_MCSS_SetRenderMode(int *p,int b);

int MUSICAL_MCSS_GetRenderHandle(u8 **p);

void MUSICAL_MCSS_GetRenderFieldA(void **p);

void MUSICAL_MCSS_GetRenderFieldB(int a);

void MUSICAL_MCSS_SetRenderAnim(int a, u32 n);

void MUSICAL_MCSS_ResetRender(int a);

void MUSICAL_MCSS_ResetRender2(int a,int b);

void MUSICAL_MCSS_GetRenderSize(int a0, int a1);

void MUSICAL_MCSS_SetRenderFieldA(void **p,int b);

void MUSICAL_MCSS_SetRenderFieldB(u8 *p, int a);

u8 *MUSICAL_MCSS_GetRenderElem(u8 *p, int i);

u8 *MUSICAL_MCSS_GetRenderFlags(u8 *p);

char *MUSICAL_MCSS_GetRenderMatrix(char *p);

void MUSICAL_MCSS_SetMatrix(unsigned mode, McssMatrixInput *in, Big *p);

void MUSICAL_MCSS_GetPokemonArcs(u8 *p, u32 *out, u32 k);

void *MUSICAL_MCSS_AllocRenderPool(int count, u32 heap);

void MUSICAL_MCSS_FreeRenderPool(char *p);

void MUSICAL_MCSS_TickMCAnim(char *p);

void MUSICAL_MCSS_DrawMC(int *p, void (*arg)(unsigned, McssMatrixInput *, Big *));

char *MUSICAL_MCSS_LoadMC(char *a,u32 b,u32 c,u32 d,u32 e,u32 f,u32 g);

void MUSICAL_MCSS_FreeMC(char *a, char *p);

void MUSICAL_MCSS_NoOp7(void *p);

void MUSICAL_MCSS_SetFieldA(char *p,int b);

void MUSICAL_MCSS_SetFieldB(u8 *p, int a);

void MUSICAL_MCSS_GetFieldA(char *p, int *q);

void MUSICAL_MCSS_GetFieldB(char *p, int *q);

void MUSICAL_MCSS_SetFieldC(char *p, unsigned short v);

void MUSICAL_MCSS_GetFieldC(u8 *p);

void MUSICAL_MCSS_GetFieldD(u8 *p);

void MUSICAL_MCSS_GetFieldE(u8 *p);

void MUSICAL_MCSS_GetFieldF(char *p);

void MUSICAL_MCSS_SetMCAnim(char *p,u32 n);

u32 MUSICAL_MCSS_GetFieldG(u8 *p);

void MUSICAL_MCSS_NoOp8(char *p);

void MUSICAL_MCSS_NoOp9(char *p);

void MUSICAL_MCSS_CopyField(Object *a,Object *b);

extern const char d_021F83C4[];

void *MUSICAL_MCSS_CreateRenderObj(u32 heap)
{
    int i;
    char *p;
    p = GFL_HEAP_Alloc(heap, 4456, 0, d_021F83C4, 76);
    ((Scene *)p)->heap = heap;
    ((Scene *)p)->main = MUSICAL_MCSS_AllocRenderPool(8, heap);
    for (i = 0; i < 8; i++) *(u32 *)(p + i * 556 + 8) = 0;
    MUSICAL_MCSS_NoOp7(((Scene *)p)->main);
    return p;
}

void MUSICAL_MCSS_DeleteRenderObj(int a) { int i; for(i=0;i<8;i++) { if(((Fields *)(a+i*556))->active==1)MUSICAL_MCSS_FreeRenderObj(a,a+8+i*556); } MUSICAL_MCSS_FreeRenderPool(((Scene *)a)->main); GFL_HEAP_Free((void *)a); }

void MUSICAL_MCSS_TickAnim(u8 *p) { MUSICAL_MCSS_TickMCAnim((char *)(((Scene *)p)->main)); }

/*
 * 2026-10-05 (wave D5 lane 02): ov112 0x021F546C is a different function from the ov194 one (a 172-byte slot
 * writer: mode >= 7 copies an input record into slot mode-7, modes 4 and 5 write four words). Parked as
 * src/pending/ov/MUSICAL_MCSS_SetMatrix.c, DIFF. Still blocks this MATCH.
 * 2026-10-05 (wD4 lane16): re-checked, bytes identical; MATCH only because MUSICAL_MCSS_SetMatrix (ov112) has no EXACT witness (ov194 has a pending file at the same address, 9 overlays overlap). Needs the callback matched in ov112.
 * 2026-10-05 (wave D6 lane 01): bytes still identical; still blocked by ov112 021F546C (DIFF 170/172).
 * 2026-10-05 (wave D7 lane 01): still MATCH, blocked by ov112 021F546C, now DIFF 172/172 with 27 bytes
 *   (two register-order residues, see that file).
 * 2026-10-05 (wave D8 lane 01): bytes still identical, still blocked by ov112 021F546C. Finding for
 *   that draft (not in this lane, so not edited): dropping const from the input pointer
 *   (the matrix input `*in`) fixes its residue (b), the modes 4/5 y-before-x load order; with the y local kept
 *   it is 172/172 with 5 bytes left, only the slot multiply colours (original idx r4 and product
 *   r1, ours idx r1 and product r4). No change to that from: no idx local, mode -= 7, unsigned idx,
 *   idx declared at function scope, an else-if chain, a void * parameter cast to Big *, an inline
 *   SetSlot(p, idx, in), enabled stored last; a byte-offset form loses the copy shape.
 * 2026-10-05 (D9 lane 02): still blocked by ov112 021F546C. Tried one more reading there: `Slot *s = &p->slots[mode - 7]` instead of the idx local (worse, 128 bytes differ).
 * 2026-10-05 (D9r lane 45): bytes still identical; still blocked by ov112 021F546C, now DIFF 172/172 with
 *   5 bytes (only the slot multiply colours), see that file.
 * 2026-10-05 (D9r lane 74): bytes still identical; still blocked by ov112 021F546C (DIFF, 5 bytes, slot
 *   multiply colours; new tries listed in that file).
 * 2026-10-05 (D9r lane 94): bytes still identical; still blocked by ov112 021F546C (DIFF, 5 bytes, slot multiply
 *   colours; three more tries listed in that file).
 * 2026-10-05 (D9r lane 121): bytes still identical (re-checked); still blocked by ov112 021F546C (DIFF, 5 bytes,
 *   same slot multiply colours; new tries listed in that file).
 * 2026-10-05 (D9r lane 144): bytes still identical (re-checked); still blocked by ov112 021F546C (DIFF, 5 bytes;
 *   new tries listed in that file).
 * 2026-10-05 (D9r lane 155): bytes still identical (re-checked); still blocked by ov112 021F546C (DIFF, 5 bytes;
 *   new finding and tries listed in that file).
 * 2026-10-05 (D9r lane 171): bytes still identical (re-checked, MATCH, the MUSICAL_MCSS_SetMatrix ABS32 word has no
 *   witness); still blocked by ov112 021F546C (DIFF, 5 bytes; tries listed in that file).
 * 2026-10-05 (D9r lane 195): ov112 021F546C is now EXACT (src/matched/ov/MUSICAL_MCSS_SetMatrix.c, compound product form).
 *   This MATCH should resolve once the integrator regenerates the witness index (the tool still reads the old
 *   manifest: "no witness outside"). Re-run match.py one after the regenerate and file as EXACT.
 */
void MUSICAL_MCSS_DrawRenderObj(void **p) { MUSICAL_MCSS_DrawMC(p[1],MUSICAL_MCSS_SetMatrix); }

u8 *MUSICAL_MCSS_SetupRenderObj(Scene *p,const u8 *b,int c)
{
    int i;
    int j;
    u8 *slot;
    Buffers buffers;
    char *second;
    for(i=0;i<8;i++) if(p->slots[i].active==0) break;
    slot=(u8 *)&p->slots[i];
    ((Slot *)slot)->active=1;
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

void MUSICAL_MCSS_FreeRenderObj(int a, int b) {
    if (((Slot *)b)->secondary != 0) {
        MUSICAL_MCSS_FreeMC((char *)(*(int *)&((Scene *)a)->main), (char *)(((Slot *)b)->secondary));
    }
    MUSICAL_MCSS_FreeMC((char *)(*(int *)&((Scene *)a)->main), (char *)(((Slot *)b)->primary));
    ((Slot *)b)->active = 0;
}

void MUSICAL_MCSS_GetRenderPos(int *p, int *q)
{
    MUSICAL_MCSS_GetFieldA(*(char * *)&((Slot *)p)->object, q);
}

void MUSICAL_MCSS_GetRenderRot(int *p, int *q)
{
    MUSICAL_MCSS_GetFieldB(*(char * *)&((Slot *)p)->object, q);
}

void MUSICAL_MCSS_SetRenderFrame(int *p, unsigned short v)
{
    MUSICAL_MCSS_SetFieldC(*(char * *)&((Slot *)p)->object, v);
}

void MUSICAL_MCSS_SetRenderMode(int *p,int b) { if(b==1)MUSICAL_MCSS_NoOp9((char *)p[2]); else MUSICAL_MCSS_NoOp8((char *)p[2]); }

int MUSICAL_MCSS_GetRenderHandle(u8 **p) { return MUSICAL_MCSS_GetFieldG(p[2]) != 1; }

void MUSICAL_MCSS_GetRenderFieldA(void **p) {MUSICAL_MCSS_GetFieldF(p[3]); if(p[4])MUSICAL_MCSS_GetFieldF(p[4]); }

void MUSICAL_MCSS_GetRenderFieldB(int a) {
    MUSICAL_MCSS_GetFieldE((u8 *)(((Slot *)a)->primary));
    if (((Slot *)a)->secondary != 0) {
        MUSICAL_MCSS_GetFieldE((u8 *)(((Slot *)a)->secondary));
    }
}

void MUSICAL_MCSS_SetRenderAnim(int a, u32 n)
{
    MUSICAL_MCSS_SetMCAnim(*(char * *)&((Slot *)a)->object, n);
}

void MUSICAL_MCSS_ResetRender(int a) {
    if (((Slot *)a)->enabled == 1) {
        MUSICAL_MCSS_CopyField((Object *)((Slot *)a)->primary, (Object *)((Slot *)a)->secondary);
        ((Slot *)a)->object = (u8 *)((Slot *)a)->secondary;
        ((Slot *)a)->enabled = 0;
        MUSICAL_MCSS_NoOp8((char *)(((Slot *)a)->primary));
    } else {
        MUSICAL_MCSS_CopyField((Object *)((Slot *)a)->secondary, (Object *)((Slot *)a)->primary);
        ((Slot *)a)->object = (u8 *)((Slot *)a)->primary;
        ((Slot *)a)->enabled = 1;
        MUSICAL_MCSS_NoOp8((char *)(((Slot *)a)->secondary));
    }
}

void MUSICAL_MCSS_ResetRender2(int a,int b) { if(b!=((Slot *)a)->enabled)MUSICAL_MCSS_ResetRender(a); }

/*
 * Recursive MATCH unblocker: unresolved callee named by the parked
 * ov112_func_021F80B0.  The +8 word is loaded once and shared by both arms
 * (the two identical loads CSE, which schedules the load before the branch).
 *
 * Addresses are Black-image addresses.
 */
void MUSICAL_MCSS_GetRenderSize(int a0, int a1)
{
    if (a1 == 1)
        MUSICAL_MCSS_GetFieldC((u8 *)(((Slot *)a0)->object));
    else
        MUSICAL_MCSS_GetFieldD((u8 *)(((Slot *)a0)->object));
}

void MUSICAL_MCSS_SetRenderFieldA(void **p,int b) {MUSICAL_MCSS_SetFieldA(p[1],b); }

void MUSICAL_MCSS_SetRenderFieldB(u8 *p, int a)
{
    MUSICAL_MCSS_SetFieldB(*(u8 * *)&((Scene *)p)->main, a);
}

u8 *MUSICAL_MCSS_GetRenderElem(u8 *p, int i) { return p + 0x14 + i * 0x38; }

u8 *MUSICAL_MCSS_GetRenderFlags(u8 *p) { return p + 0x20c; }

/*
 * follower: aggregate-copy function 021F546C parked as DIFF note.
 */
char *MUSICAL_MCSS_GetRenderMatrix(char *p) { return p+536; }

void MUSICAL_MCSS_SetMatrix(unsigned mode, McssMatrixInput *in, Big *p)
{
    if (mode >= 7) {
        u32 off = mode - 7;
        u32 base = (u32)p;
        off *= 0x38;
        *(int *)(base + off + 0x14) = 1;
        base += off;
        *(struct Vec3 *)(base + 0x18) = in->a;
        *(struct Vec3 *)(base + 0x24) = in->b;
        *(u16 *)(base + 0x48) = in->e;
        *(u16 *)(base + 0x4a) = in->f;
        *(struct Vec3 *)(base + 0x30) = in->c;
        *(struct Vec3 *)(base + 0x3c) = in->d;
        return;
    }
    if (mode == 4) {
        int y = in->b.y;
        p->t[0].x = in->b.x;
        p->t[0].y = y;
        p->t[0].z = 0;
        p->flag[0] = 1;
        return;
    }
    if (mode == 5) {
        int y = in->b.y;
        p->t[1].x = in->b.x;
        p->t[1].y = y;
        p->t[1].z = 0;
        p->flag[1] = 1;
    }
}

void MUSICAL_MCSS_GetPokemonArcs(u8 *p, u32 *out, u32 k)
{
    u32 a, c, d, flag;
    int b;
    u32 n;
    POKE_TOOL_GetBoxParam(((McssMon *)p)->source);
    a = ((McssMon *)p)->species;
    n = POKE_TOOL_NormalizeForm(a, p[11]);
    c = p[10];
    d = p[12];
    flag = 0;
    b = POKE_TOOL_FilterSpecies(((McssMon *)p)->species, (u8)n);
    if (k == 1) flag = 1;
    out[0] = 52;
    out[1] = POKEGRA_GetCbrArcIndex(out[0],a,b,c,d,flag,0);
    out[2] = POKEGRA_GetPalArcIndex(out[0],a,b,c,d,flag,0);
    out[3] = POKEGRA_GetCelArcIndex(out[0],a,b,c,d,flag,0);
    out[4] = POKEGRA_GetAnmArcIndex(out[0],a,b,c,d,flag,0);
    out[5] = POKEGRA_GetMCelArcIndex(out[0],a,b,c,d,flag,0);
    out[6] = POKEGRA_GetMAnmArcIndex(out[0],a,b,c,d,flag,0);
    out[7] = POKEGRA_GetNcecArcIndex(out[0],a,b,c,d,flag,0);
    out[8] = ((McssMon *)p)->field10;
}
