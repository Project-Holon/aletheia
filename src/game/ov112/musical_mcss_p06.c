/*
 * file:     musical_mcss_p06.c
 * unit:     yes
 * function: func_021F5158, func_021F5164, func_021F51B0, func_021F51E8, func_021F51F4, func_021F5204, func_021F5330, func_021F5350, func_021F535C, func_021F5368, func_021F5374, func_021F5388, func_021F539C, func_021F53B4
 * address:  0x021F5158
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F4F54  0x021F4F54  thumb  ov112
 *   sub_02030734 0x02030734 arm
 *   d_021F83C4 0x021F83C4 data a1
 *   func_021F55F8 0x021F55F8 thumb ov112
 *   func_021F621C 0x021F621C thumb ov112
 *   func_021F5644 0x021F5644 thumb ov112
 *   func_020307B0 0x020307B0 arm
 *   func_021F5678  0x021F5678  thumb  ov112
 *   func_021F546C 0x021F546C thumb ov112
 *   func_021F56BC 0x021F56BC thumb ov112
 *   func_021F5518 0x021F5518 thumb ov112
 *   func_021F611C 0x021F611C thumb ov112
 *   func_021F62DC 0x021F62DC thumb ov112
 *   func_021F6290 0x021F6290 thumb ov112
 *   func_021F61D8  0x021F61D8  thumb  ov112
 *   func_021F6234  0x021F6234  thumb  ov112
 *   func_021F624C  0x021F624C  thumb  ov112
 *   func_021F6264  0x021F6264  thumb  ov112
 *   func_021F62EC 0x021F62EC thumb ov112
 *   func_021F62D0 0x021F62D0 thumb ov112
 *   func_021F62A0 0x021F62A0 thumb ov112
 */
#include "../../matched/include/Obj10301.h"
#include "../../matched/include/Obj10302.h"
#include "../../matched/include/Obj22534.h"
#include "../../matched/include/Obj22535.h"
#include "../../matched/include/Obj08022.h"
#include "../../matched/include/Obj22536.h"
#include "../../matched/include/Obj22537.h"
#include "../../matched/include/Obj22538.h"
#include "../../matched/include/Obj10304.h"

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct { int f0, f4, active; } Fields;

typedef short s16;

typedef signed char s8;

typedef int s32;

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

unsigned char *func_021F4F54(unsigned char *p, int i);
extern void *sub_02030734(u32, u32, int, const char *, u16);
extern void *func_021F55F8(int, u32);
extern void func_021F621C(void *);
extern void func_021F5644(char *p);
extern u32 func_020307B0(void *p);
extern void func_021F5678(char *p);
extern void func_021F546C(u32,void *,void *);
extern void func_021F56BC(void *,void (*)(u32,void *,void *));
extern void func_021F5518(u8 *,u32 *,u32);
extern char *func_021F611C(char *,u32,u32,u32,u32,u32,u32);
extern void func_021F62DC(char *);
extern void func_021F6290(u8 *);
extern void func_021F61D8(char *a, char *p);
void func_021F6234(char *p, int *q);
void func_021F624C(char *p, int *q);
void func_021F6264(char *p, unsigned short v);
extern void func_021F62EC(char *p);
extern u32 func_021F62D0(u8 *);
extern void func_021F62A0(char *p);
unsigned char func_021F5158(void *p, int i);
void *func_021F5164(u32 heap);
void func_021F51B0(int a);
void func_021F51E8(u8 *p);
void func_021F51F4(void **p);
u8 *func_021F5204(Scene *p,const u8 *b,int c);
void func_021F5330(int a, int b);
void func_021F5350(int *p, int *q);
void func_021F535C(int *p, int *q);
void func_021F5368(int *p, unsigned short v);
void func_021F5374(int *p,int b);
int func_021F5388(u8 **p);
void func_021F539C(void **p);
void func_021F53B4(int a);
extern const char d_021F83C4[];


unsigned char func_021F5158(void *p, int i)
{
    return *(func_021F4F54(p, i) + 8);
}

void *func_021F5164(u32 heap)
{
    int i;
    char *p;
    p = sub_02030734(heap, 4456, 0, d_021F83C4, 76);
    ((struct Obj10301 *)p)->f0 = heap;
    ((struct Obj10301 *)p)->f4 = func_021F55F8(8, heap);
    for (i = 0; i < 8; i++) *(u32 *)(p + i * 556 + 8) = 0;
    func_021F621C(((struct Obj10301 *)p)->f4);
    return p;
}

void func_021F51B0(int a) { int i; for(i=0;i<8;i++) { if(((Fields *)(a+i*556))->active==1)func_021F5330(a,a+8+i*556); } func_021F5644(((struct Obj10302 *)a)->f4); func_020307B0((void *)a); }

void func_021F51E8(u8 *p) { func_021F5678((char *)(((struct Obj22534 *)p)->f4)); }

/*
 * 2026-10-05 (wave D5 lane 02): ov112 0x021F546C is a different function from the ov194 one (a 172-byte slot
 * writer: mode >= 7 copies an input record into slot mode-7, modes 4 and 5 write four words). Parked as
 * src/pending/ov/ov112_func_021F546C.c, DIFF. Still blocks this MATCH.
 * 2026-10-05 (wD4 lane16): re-checked, bytes identical; MATCH only because func_021F546C (ov112) has no EXACT witness (ov194 has a pending file at the same address, 9 overlays overlap). Needs the callback matched in ov112.
 * 2026-10-05 (wave D6 lane 01): bytes still identical; still blocked by ov112 021F546C (DIFF 170/172).
 * 2026-10-05 (wave D7 lane 01): still MATCH, blocked by ov112 021F546C, now DIFF 172/172 with 27 bytes
 *   (two register-order residues, see that file).
 * 2026-10-05 (wave D8 lane 01): bytes still identical, still blocked by ov112 021F546C. Finding for
 *   that draft (not in this lane, so not edited): dropping const from the input pointer
 *   (`Input *in`) fixes its residue (b), the modes 4/5 y-before-x load order; with the y local kept
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
 * 2026-10-05 (D9r lane 171): bytes still identical (re-checked, MATCH, the func_021F546C ABS32 word has no
 *   witness); still blocked by ov112 021F546C (DIFF, 5 bytes; tries listed in that file).
 * 2026-10-05 (D9r lane 195): ov112 021F546C is now EXACT (src/matched/ov/ov112_func_021F546C.c, compound product form).
 *   This MATCH should resolve once the integrator regenerates the witness index (the tool still reads the old
 *   manifest: "no witness outside"). Re-run match.py one after the regenerate and file as EXACT.
 */
void func_021F51F4(void **p) { func_021F56BC(p[1],func_021F546C); }

u8 *func_021F5204(Scene *p,const u8 *b,int c)
{
    int i;
    int j;
    u8 *slot;
    Buffers buffers;
    char *second;
    for(i=0;i<8;i++) if(p->slots[i].active==0) break;
    slot=(u8 *)&p->slots[i];
    ((struct Obj22535 *)slot)->f0=1;
    func_021F5518((u8 *)b,buffers.stats,0);
    p->slots[i].primary=func_021F611C(p->main,0,0,0,(u32)buffers.stats,(u32)slot,0);
    if(c==1) {
        func_021F5518((u8 *)b,buffers.stats,1);
        p->slots[(u32)i].secondary=func_021F611C(p->main,0,0,0,(u32)buffers.stats,(u32)slot,0);
        func_021F62DC(p->slots[(u32)i].secondary);
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
    func_021F535C((int *)&p->slots[i],buffers.scale);
    func_021F6290(p->slots[i].object);
    return (u8 *)&p->slots[i];
}


void func_021F5330(int a, int b) {
    if (((struct Obj08022 *)b)->f10 != 0) {
        func_021F61D8((char *)(*(int *)&((struct Obj10302 *)a)->f4), (char *)(((struct Obj08022 *)b)->f10));
    }
    func_021F61D8((char *)(*(int *)&((struct Obj10302 *)a)->f4), (char *)(((struct Obj08022 *)b)->fC));
    ((struct Obj08022 *)b)->f0 = 0;
}


void func_021F5350(int *p, int *q)
{
    func_021F6234(*(char * *)&((struct Obj22536 *)p)->f8, q);
}


void func_021F535C(int *p, int *q)
{
    func_021F624C(*(char * *)&((struct Obj22537 *)p)->f8, q);
}


void func_021F5368(int *p, unsigned short v)
{
    func_021F6264(*(char * *)&((struct Obj22538 *)p)->f8, v);
}

void func_021F5374(int *p,int b) { if(b==1)func_021F62EC((char *)p[2]); else func_021F62DC((char *)p[2]); }

int func_021F5388(u8 **p) { return func_021F62D0(p[2]) != 1; }

void func_021F539C(void **p) {func_021F62A0(p[3]); if(p[4])func_021F62A0(p[4]); }


void func_021F53B4(int a) {
    func_021F6290((u8 *)(((struct Obj10304 *)a)->fC));
    if (((struct Obj10304 *)a)->f10 != 0) {
        func_021F6290((u8 *)(((struct Obj10304 *)a)->f10));
    }
}
