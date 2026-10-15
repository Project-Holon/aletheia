/*
 * function: WIFIBATTLEMATCH_SYS_ApplySetup
 * address: 0x02212E74
 * packet: pkt_ov199_02212E74
 * region: ov199
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_SYS_CountBoxSpecies 0x022135CC thumb ov199
 *   WIFIBATTLEMATCH_SYS_GetPartyCounts 0x02213684 thumb ov199
 *   BATTLE_REC_LoadToolOverlay 0x0200BA58 thumb
 *   BATTLE_REC_TOOL_PackSetup 0x021EEE78 thumb ov188
 *   BATTLE_REC_UnloadToolOverlay 0x0200BA68 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   REGULATION_GetCard 0x0200B1D4 thumb
 *   REGULATION_NoOp 0x0200AE14 thumb
 *   REGULATION_Card_GetValue 0x0200B078 thumb
 *   WIFIBATTLEMATCH_SYS_FillSetupRecord 0x022133E4 thumb ov199
 *   POKE_REGULATION_Load 0x0201A354 thumb
 *   func_020307B0 0x020307B0 arm
 *   BTL_SETUP_FreeSlots 0x020130DC thumb
 *   WIFIBATTLEMATCH_SYS_SetStep 0x02213808 thumb ov199
 */
#include "../include/Obj01007.h"
#include "../include/Obj03909.h"
#include "../include/Obj10857.h"
typedef unsigned char u8;
typedef struct Flag { u8 bit:1; u8 rest:7; } Flag;
typedef struct Bytes { u8 a,b,c; } Bytes;
extern void WIFIBATTLEMATCH_SYS_CountBoxSpecies(u8 *,u8 *,u8 *);
extern void WIFIBATTLEMATCH_SYS_GetPartyCounts(const u8 *,u8 *,u8 *);
extern void BATTLE_REC_LoadToolOverlay(void);
extern void BATTLE_REC_TOOL_PackSetup(void *);
extern void BATTLE_REC_UnloadToolOverlay(void);
typedef signed int     s32;
typedef unsigned int   u32;
struct Big;
struct Rec160;
struct Reg2;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *BATTLE_COMPETITION_GetFromSave(void *);
extern struct Rec160 *REGULATION_GetCard(struct Rec160 *arr, u32 index);
extern void *REGULATION_NoOp(void *);
extern s32 REGULATION_Card_GetValue(struct Reg2 *p, u32 id);
extern void WIFIBATTLEMATCH_SYS_FillSetupRecord(u8 *p, void *party1, void *party2, u8 *save, void *reg, int setting, u8 *record, void *other, int mode);
extern void *POKE_REGULATION_Load(int,int);
extern u32 func_020307B0(void *p);
extern void BTL_SETUP_FreeSlots(void *);
extern void WIFIBATTLEMATCH_SYS_SetStep(char *p, int value);
int WIFIBATTLEMATCH_SYS_ApplySetup(void *manager, u8 *arg, u8 *p)
{
    u8 *record = *(u8 * *)&((struct Obj03909 *)arg)->f4;
    int state = ((struct Obj03909 *)arg)->fC;
    Bytes bytes;
    void *rules,*reg,*created;
    int setting;
    ((struct Obj01007 *)p)->f1B8 = ((struct Obj10857 *)record)->f4;
    ((struct Obj01007 *)p)->f1B4 = ((struct Obj10857 *)record)->f8C;
    ((struct Obj01007 *)p)->f1C4 = ((Flag *)(record + 0xc1))->bit;
    ((struct Obj01007 *)p)->f1B4 = ((struct Obj10857 *)record)->f8C;
    WIFIBATTLEMATCH_SYS_CountBoxSpecies(*(u8 * *)&((struct Obj03909 *)arg)->f4, &bytes.b, &bytes.c);
    p[0x1bc] = bytes.c;
    WIFIBATTLEMATCH_SYS_GetPartyCounts(*(u8 * *)&((struct Obj03909 *)arg)->f4, &bytes.a, p + 0x1bd);
    BATTLE_REC_LoadToolOverlay();
    BATTLE_REC_TOOL_PackSetup(((struct Obj03909 *)arg)->f4);
    BATTLE_REC_UnloadToolOverlay();
    if (((struct Obj01007 *)p)->f1C == 0) {
        rules = REGULATION_GetCard(BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl(((struct Obj01007 *)p)->f4)),0);
        reg = REGULATION_NoOp(rules);
        setting = REGULATION_Card_GetValue(rules,2);
        if (state == 0) WIFIBATTLEMATCH_SYS_FillSetupRecord(p + 0x1d0,((struct Obj01007 *)p)->f30,((struct Obj01007 *)p)->f34,((struct Obj01007 *)p)->f2C,reg,setting,record,p + 0x1b4,0);
    } else if (((struct Obj01007 *)p)->f1C == 2) {
        created = POKE_REGULATION_Load(((struct Obj01007 *)p)->f8 + 0xf,0x56);
        if (state == 0) WIFIBATTLEMATCH_SYS_FillSetupRecord(p + 0x1d0,((struct Obj01007 *)p)->f30,((struct Obj01007 *)p)->f34,((struct Obj01007 *)p)->f2C,created,0,record,p + 0x1b4,2);
        func_020307B0(created);
    }
    BTL_SETUP_FreeSlots(((struct Obj03909 *)arg)->f4);
    func_020307B0(((struct Obj03909 *)arg)->f4);
    func_020307B0(((struct Obj03909 *)arg)->f8);
    func_020307B0(arg);
    if (((struct Obj01007 *)p)->f1C == 1) {
        switch(state) {
        case 0: WIFIBATTLEMATCH_SYS_SetStep(manager,0);break;
        case 1: ((struct Obj01007 *)p)->f1C0=1;WIFIBATTLEMATCH_SYS_SetStep(manager,0);break;
        }
    } else {
        switch(state) {
        case 0: ((struct Obj01007 *)p)->f20=1;WIFIBATTLEMATCH_SYS_SetStep(manager,1);break;
        case 2: ((struct Obj01007 *)p)->f220=1;WIFIBATTLEMATCH_SYS_SetStep(manager,4);break;
        case 3: ((struct Obj01007 *)p)->f20=2;WIFIBATTLEMATCH_SYS_SetStep(manager,1);break;
        }
    }
    return 1;
}
