/*
 * file:     field_g3d_map.c
 * unit:     yes
 * function: func_0216BF38, func_0216BF74, func_0216BF9C
 * address:  0x0216BF38
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldmmdl.c at 0x0216BFD4 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0200D468  0x0200D468  thumb
 *   func_02008530 0x02008530 thumb
 *   func_0200C38C 0x0200C38C thumb
 *   g_BeaconTrainerKeys 0x02172508 data a4
 *   func_0200C39C 0x0200C39C thumb
 */
struct ScriptWorkRef;
struct ScriptSaveBlock;
struct BeaconSave;
struct TrainerRec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

extern void *func_0215A5E4(void *scriptCtx);
extern void *func_02012EBC(struct ScriptWorkRef *p);
extern void *func_0200D418(void *saveSys);
extern unsigned int func_02159B10(void *, void *);
extern unsigned short *func_02159AE8(void *a0, void *a1);
extern u8 func_0200D468(struct ScriptSaveBlock *p, u32 i);
extern u32 func_02008530(const struct TrainerRec *obj);
extern void func_0200C38C(struct BeaconSave *p, s32 i, u32 v);
extern u32 func_0200C39C(struct BeaconSave *p, s32 i);
int func_0216BF38(int cmdState, int scriptCtx);
void func_0216BF74(void *beaconSave, int slot, void *trainerRec);
int func_0216BF9C(void *beaconSave, int slot, void *trainerRec);
extern const u32 g_BeaconTrainerKeys[];

/* Script command: copy byte [index] of the 0x38-byte save block into a script variable. */
int func_0216BF38(int cmdState, int scriptCtx)
{
    /* The register copies below are kept: they decide the original's register allocation. */
    int index;
    int cmdStateCopy;
    int scriptCtxCopy;
    void *saveBlock;
    void *chain;

    scriptCtxCopy = scriptCtx;
    cmdStateCopy = cmdState;
    cmdState = scriptCtxCopy;
    chain = func_0215A5E4((void *)cmdState);
    chain = func_02012EBC((struct ScriptWorkRef *)chain);
    saveBlock = func_0200D418(chain);
    cmdState = cmdStateCopy;
    scriptCtx = scriptCtxCopy;
    cmdState = func_02159B10((void *)cmdState, (void *)scriptCtx);
    cmdState = cmdState << 0x18;
    index = (unsigned)cmdState >> 0x18;
    cmdState = cmdStateCopy;
    scriptCtx = scriptCtxCopy;
    cmdState = (int)func_02159AE8((void *)cmdState, (void *)scriptCtx); /* int-typed on purpose: pointer local changes codegen */
    cmdStateCopy = cmdState;
    scriptCtx = index;
    cmdState = func_0200D468(saveBlock, scriptCtx);
    *(u16 *)cmdStateCopy = cmdState;
    cmdState = 0;
    return cmdState;
}

/* Store the trainer ID of trainerRec, xored with the slot key, in the beacon save. */
void func_0216BF74(void *beaconSave, int slot, void *trainerRec) {
    if(slot<8) func_0200C38C(beaconSave,slot,func_02008530(trainerRec)^*(const u32 *)((u32)g_BeaconTrainerKeys+(u32)slot*4));
}

/*
 * lever: named second call-result local preserves the original comparison registers.
 */
int func_0216BF9C(void *beaconSave, int slot, void *trainerRec) {
    u32 trainerId; u32 storedId;
    if(slot>=8) return 0;
    trainerId=func_02008530(trainerRec);
    storedId=func_0200C39C(beaconSave,slot);
    if((storedId^trainerId)==*(const u32 *)((u32)g_BeaconTrainerKeys+(u32)slot*4)) return 1;
    return 0;
}
