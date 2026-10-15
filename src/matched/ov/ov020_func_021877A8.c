/*
 * function: EL_SCOREBOARD_StartOnFieldWithCallback
 * address:  0x021877A8
 * packet:   pkt_ov020_021877A8
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * c must be u8 (as in the twin EL_SCOREBOARD_StartStandalone): with an int c the scheduler
 * hoists its spilled reload above the strb of d.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020124EC  0x020124EC  thumb
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   COMM_PLAYER_SUPPORT_PrevSeason  0x0202E8B8  thumb
 *   EL_SCOREBOARD_EnterState  0x02187C20  thumb  ov020
 *   EL_SCOREBOARD_EventMain  0x021876E0  thumb  ov020
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct { int a; int b; u16 c; int d; int e; u8 f; u8 g; u8 pad[10];
                 int h; int i; } T;

extern int EL_SCOREBOARD_EventMain(void *, int *, char *);
typedef unsigned int   u32;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u32 *func_020124EC(struct Obj *p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern u8 COMM_PLAYER_SUPPORT_PrevSeason(int);
extern void EL_SCOREBOARD_EnterState(char *o, int *p, int st);

void *EL_SCOREBOARD_StartOnFieldWithCallback(int a, int b, u8 c, u8 d, int e, int f)
{
    void *r7 = func_020122C0((void *)a, 0, EL_SCOREBOARD_EventMain, 0x28);
    T *t = func_020124E8(r7);
    int x = (int)func_020124EC(r7);
    t->a = a; t->b = b; t->c = FIELDMAP_GetHeapId((u8 *)b); t->d = 0; t->e = 0;
    t->f = d; t->g = COMM_PLAYER_SUPPORT_PrevSeason(c); t->h = e; t->i = f;
    EL_SCOREBOARD_EnterState((char *)t, (int *)x, 0);
    return r7;
}
