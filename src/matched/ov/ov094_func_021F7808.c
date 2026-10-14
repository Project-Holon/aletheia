/*
 * function: BTLV_EFFECT_Exit
 * address:  0x021F7808
 * packet:   pkt_ov094_021F7808
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   gBtlvEff 0x0220AF20 data ov094 a4
 *   PM_VOICE_FreeBuffers 0x020066E8 thumb
 *   BTLV_EFFECT_DeleteAllTasks 0x021F8B6C thumb ov094
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   BTLV_MCSS_Delete 0x021FEB78 thumb ov094
 *   BTLV_STAGE_Delete 0x021F6898 thumb ov094
 *   BTLV_FIELD_Delete 0x021F6CF0 thumb ov094
 *   BTLV_CAMERA_Delete 0x021F6EC0 thumb ov094
 *   BTLV_CLACT_Delete 0x02201AC4 thumb ov094
 *   BTLV_GAUGE_Delete 0x02206E28 thumb ov094
 *   BTLV_TIMER_Delete 0x022092E8 thumb ov094
 *   BTLV_BG_Delete 0x0220977C thumb ov094
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   BTLV_EFFVM_Destroy 0x021F94D8 thumb ov094
 *   func_02030EAC 0x02030EAC arm
 *   func_02030DA4 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 */
extern char *gBtlvEff;
extern void PM_VOICE_FreeBuffers(void);
extern void BTLV_EFFECT_DeleteAllTasks(void);
typedef unsigned int   u32;
struct Node;
struct PalAnmSlot;
struct Res;
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);
extern void BTLV_MCSS_Delete(void *);
extern void BTLV_STAGE_Delete(void *);
extern void BTLV_FIELD_Delete(void *);
extern void BTLV_CAMERA_Delete(void **p);
extern void BTLV_CLACT_Delete(struct Res *r);
extern void BTLV_GAUGE_Delete(char *p);
extern void BTLV_TIMER_Delete(void *);
extern void BTLV_BG_Delete(void *);
extern void PARTICLE_ExitManager(void);
extern void BTLV_EFFVM_Destroy(void *);
extern void func_02030EAC(struct Node *n);
extern void func_02030DA4(void *);
extern u32 func_020307B0(void *p);
#define FIELD(k) (*(void **)(gBtlvEff + (k)))

void BTLV_EFFECT_Exit(void)
{
    if (gBtlvEff != 0) {
        PM_VOICE_FreeBuffers();
        BTLV_EFFECT_DeleteAllTasks();
        PALANM_FreeSlotBuffers(FIELD(0x18c), 0);
        PALANM_FreeSlotBuffers(FIELD(0x18c), 1);
        PALANM_FreeSlotBuffers(FIELD(0x18c), 2);
        PALANM_FreeSlotBuffers(FIELD(0x18c), 3);
        PALANM_Delete(FIELD(0x18c));
        BTLV_MCSS_Delete(FIELD(0x190));
        BTLV_STAGE_Delete(FIELD(0x194));
        BTLV_FIELD_Delete(FIELD(0x198));
        BTLV_CAMERA_Delete(FIELD(0x19c));
        BTLV_CLACT_Delete(FIELD(0x1a0));
        BTLV_GAUGE_Delete(FIELD(0x1a4));
        BTLV_TIMER_Delete(FIELD(0x1b0));
        BTLV_BG_Delete(FIELD(0x1b4));
        PARTICLE_ExitManager();
        BTLV_EFFVM_Destroy(FIELD(0x188));
        func_02030EAC(FIELD(0x1b8));
        func_02030DA4(FIELD(0));
        func_020307B0(FIELD(4));
        func_020307B0(gBtlvEff);
        gBtlvEff = 0;
    }
}
