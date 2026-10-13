/*
 * function: func_021C154C
 * address: 0x021C154C
 * packet: pkt_ov110_021C154C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Blocked on ARM9 leaves 0x02024910 and 0x02024108, no outside witnesses.
 * blocker: 0x02024910 Thumb, EXACT (block24910.log)
 *   typedef unsigned char u8;
 *   void *PMS_WORD_GetSaveEntry(u8 *p,int i) { return p+8+i*8; }
 * blocker: 0x02024108 Thumb, EXACT (block24108.log)
 *   typedef unsigned char u8; typedef unsigned short u16;
 *   void PMSI_PARAM_SetSentence(u8 *p,const u16 *s) {
 *     *(u16 *)(p+16)=s[0]; *(u16 *)(p+18)=s[1];
 *     *(u16 *)(p+20)=s[2]; *(u16 *)(p+22)=s[3];
 *   }
 * symbols:
 *   PMSI_PARAM_Create 0x02024044 thumb
 *   PMS_WORD_GetSaveEntry 0x02024910 thumb
 *   PMSI_PARAM_SetSentence 0x02024108 thumb
 *   PROCSYS_Push 0x02031348 arm
 *   d_021C39B8 0x021C39B8 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
extern struct Obj *PMSI_PARAM_Create(u32 kind, u32 a1, void *src, u32 flag, void *sys, u32 hh);
extern void *PMS_WORD_GetSaveEntry(char *p, int idx);
extern void PMSI_PARAM_SetSentence(u16 *dst, const u16 *src);
extern void PROCSYS_Push(void *, int, void *, void *);
extern const unsigned d_021C39B8[];
int func_021C154C(int *state, u8 *p) {
    void *q;
    switch (*state) {
    case 0: ++*state; break;
    case 1:
        q=PMSI_PARAM_Create(2,0,0,1,*(void **)(p+0x1c),*(u16 *)(p+4));
        PMSI_PARAM_SetSentence(q,PMS_WORD_GetSaveEntry(*(void **)(p+0x20),p[0x95]));
        PROCSYS_Push(*(void **)(p+0xac),-1,(void *)d_021C39B8,q);
        *(void **)(p+0x90)=q;
        return 1;
    }
    return 0;
}
