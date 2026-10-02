/*
 * function: func_021D785C
 * address: 0x021D785C
 * packet: pkt_ov131_021D785C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * checks: 1 complete callee arity/body/live-register audit; 2 filtered ov131/119/093 twins absent; 3 compiled const source no change, FD4 int/u32 no change; 4 fitting const/named-result/stack-struct/store-argument idioms read; 5 fresh full idiom directory and 7A44/79A8/neighbours reread, no rescue.
 * budget: iteration 4 runs including one CCERR, three consecutive nonshrinking changes; check3 one compile; scheduling variants one; one permuter300/types completed with no improvement; carry these caps.
 * residual: original size 288, four concrete bytes differ at +AA/+AC;
 *   original stores constructor result before mov r1,#2, compiled reverses.
 *   22/24 relocations resolved; ARM9 02015D80 lacks independent witness
 *   outside this caller. Ilias owns it; no blocker C was written/matched.
 * interface: 02017270 leaves r0 live and this caller stores and passes it;
 *   extern returns that payload despite legacy void declaration. 020173B4
 *   sets all r1-r3 before forwarding to 02015F2C, so consumes only r0.
 *   02015D80's complete body writes only r1 low halfword at +0x178;
 *   caller supplies pooled full-width 0xD555 without truncation.
 * semantic: four three-word templates initialize all local vector words;
 *   021D7A44 only modifies those initialized words. No integer arithmetic
 *   on admitted inputs is performed here.
 * note 2026-10-02 (lane B2-09): 4 concrete bytes differ (+0xAA/+0xAC): original
 *   stores the second constructor result (str r0,[r4,#4]) before movs r1,#2;
 *   compiled swaps them. The first group already matches. Isolated copies of
 *   the second group and the whole function without the final func_021D7A1C
 *   (&d) call compile in the original order: the swap appears only when d's
 *   address is live (three spilled vector pointers). Inert: pointer locals
 *   for a/b/c/d (any order), const Vec, int Vec, nested/assigned/cast store
 *   forms, ((void**)q)[1], struct q, static inline per-object helper,
 *   Vec assigned instead of initialised. func_02015D80 witness is now filed
 *   (src/matched/arm9/func_02015D80.c), so only the 4 bytes remain.
 * note 2026-10-02 (lane R5): still 4 bytes (+0xAA/+0xAC). Prototypes now
 *   copied from the matched definitions (Vec of u32, 02015D80(u8 *,u16),
 *   02015D30/CDC(void *,u32 *)) and the third parameter that caller
 *   021D6A38 passes in r2 is named; all inert for the swap. Measured: the
 *   swap is a scheduling effect (order correct at -O1, swapped from -O2) and
 *   appears only while &d is live across group 2 (passing &a/&b/&c to
 *   func_021D7A1C instead gives the original order in both groups). Inert:
 *   block-scoped result local (initialised, chained, pointer-to-slot), store
 *   then FD4 on the void * slot, int/char * result type, q+4 pointer local,
 *   Vec *v[3] pointer array for b/c/d (same bytes, same swap), a two-pass
 *   loop (not unrolled, 240 bytes).
 * symbols:
 *   d_021DC1F8 0x021DC1F8 data ov131 a4
 *   d_021DC240 0x021DC240 data ov131 a4
 *   d_021DC180 0x021DC180 data a4
 *   d_021DC1C8 0x021DC1C8 data ov131 a4
 *   func_021D60A4 0x021D60A4 thumb ov131
 *   func_021D7A44 0x021D7A44 thumb ov131
 *   func_021D79A8 0x021D79A8 thumb ov131
 *   func_021D7A1C 0x021D7A1C thumb ov131
 *   func_02015D80 0x02015D80 thumb
 *   func_02015D30 0x02015D30 thumb
 *   func_02015CDC 0x02015CDC thumb
 *   func_02015EB0 0x02015EB0 thumb
 *   func_02015EA0 0x02015EA0 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct { u32 x,y,z; } Vec;
extern const Vec d_021DC1F8,d_021DC240,d_021DC180,d_021DC1C8;
extern void *func_021D60A4(void *);
extern void func_021D7A44(void *,int,int *,int *);
extern void func_021D79A8(void *,void *,int);
extern void func_021D7A1C(void *,void *,Vec *);
extern void *func_02017270(void *,void *,u32,u32,u32,u32);
extern void func_02015FD4(char *,int);
extern void func_02015D80(u8 *,u16);
extern void func_02015D30(void *,u32 *);
extern int func_020173B4(void *);
extern void func_02015CDC(void *,u32 *);
extern void func_02015EB0(void *);
extern void func_02015EA0(void *);
void func_021D785C(u8 *p,u8 *q,void *mon)
{
    Vec a=d_021DC1F8;
    Vec b=d_021DC240;
    Vec c=d_021DC180;
    Vec d=d_021DC1C8;
    void *m=func_021D60A4((void *)p);
    func_021D7A44((void *)p,(int)q,(int *)&a,(int *)&b);
    *(void **)q=func_02017270(*(void **)(p+0x78),m,0,0xd8000,0x48000,0);
    func_02015FD4(*(char **)q,2);
    func_02015D80(*(u8 **)q,0xd555);
    func_02015D30(*(void **)q,&b.x);
    func_020173B4(*(void **)q);
    func_02015CDC(*(void **)q,&a.x);
    *(void **)(q+4)=func_02017270(*(void **)(p+0x78),m,1,0xd8000,0x48000,0);
    func_02015FD4(*(char **)(q+4),2);
    func_02015D80(*(u8 **)(q+4),0xd555);
    func_02015D30(*(void **)(q+4),&c.x);
    func_020173B4(*(void **)(q+4));
    func_02015CDC(*(void **)(q+4),&a.x);
    func_021D79A8((void *)p,q,0);
    func_021D7A1C((void *)p,q,&d);
    if(*(int *)(q+0xc)==1) {
        func_02015EB0(*(void **)q);
        func_02015EA0(*(void **)(q+4));
        return;
    }
    func_02015EB0(*(void **)(q+4));
    func_02015EA0(*(void **)q);
}
