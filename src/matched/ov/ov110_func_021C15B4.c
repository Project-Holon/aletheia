/*
 * function: func_021C15B4
 * address: 0x021C15B4
 * packet: pkt_ov110_021C15B4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Blocked on ARM9 leaves 0x02024120 and 0x02024134; zero padding follows.
 * blocker: 0x02024120 Thumb, EXACT (block24120.log)
 *   typedef unsigned char u8;
 *   u8 PMSI_PARAM_CheckModified(u8 *p) { return p[2]; }
 * blocker: 0x02024134 Thumb, EXACT (block24134.log)
 *   symbols: PMSI_PARAM_Copy 0x02024570 thumb
 *   typedef unsigned char u8;
 *   extern void PMSI_PARAM_Copy(void *,const void *);
 *   void PMSI_PARAM_GetSentence(u8 *p,void *out) { PMSI_PARAM_Copy(out,p+16); }
 * symbols:
 *   PMSI_PARAM_CheckModified 0x02024120 thumb
 *   PMSI_PARAM_GetSentence 0x02024134 thumb
 *   PMS_WORD_SetSaveEntry 0x02024918 thumb
 *   PMSI_PARAM_Delete 0x020240FC thumb
 */
typedef unsigned char u8;
extern int PMSI_PARAM_CheckModified(u8 *p);
typedef signed int     s32;
struct Obj02024838;
extern void PMSI_PARAM_GetSentence(char *a, void *b);
extern void PMS_WORD_SetSaveEntry(const struct Obj02024838 *p, s32 idx, void *dest);
extern void PMSI_PARAM_Delete(void *);
int func_021C15B4(int *state, u8 *p) {
    unsigned pair[2];
    switch (*state) {
    case 0:
        if (PMSI_PARAM_CheckModified(*(void **)(p+0x90))) {
            PMSI_PARAM_GetSentence(*(void **)(p+0x90),pair);
            PMS_WORD_SetSaveEntry(*(void **)(p+0x20),p[0x95],pair);
        }
        PMSI_PARAM_Delete(*(void **)(p+0x90));
        ++*state;
        break;
    case 1: return 1;
    }
    return 0;
}
