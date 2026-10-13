/*
 * function: func_021F7808
 * address:  0x021F7808
 * packet:   pkt_ov094_021F7808
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   d_0220AF20 0x0220AF20 data ov094 a4
 *   PM_VOICE_FreeBuffers 0x020066E8 thumb
 *   func_021F8B6C 0x021F8B6C thumb ov094
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   func_021FEB78 0x021FEB78 thumb ov094
 *   func_021F6898 0x021F6898 thumb ov094
 *   func_021F6CF0 0x021F6CF0 thumb ov094
 *   func_021F6EC0 0x021F6EC0 thumb ov094
 *   func_02201AC4 0x02201AC4 thumb ov094
 *   func_02206E28 0x02206E28 thumb ov094
 *   BTLV_TIMER_Delete 0x022092E8 thumb ov094
 *   BTLV_BG_Delete 0x0220977C thumb ov094
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   func_021F94D8 0x021F94D8 thumb ov094
 *   func_02030EAC 0x02030EAC arm
 *   func_02030DA4 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 */
extern char *d_0220AF20;
extern void PM_VOICE_FreeBuffers(void);
extern void func_021F8B6C(void);
typedef unsigned int   u32;
struct Node;
struct PalAnmSlot;
struct Res;
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);
extern void func_021FEB78(void *);
extern void func_021F6898(void *);
extern void func_021F6CF0(void *);
extern void func_021F6EC0(void **p);
extern void func_02201AC4(struct Res *r);
extern void func_02206E28(char *p);
extern void BTLV_TIMER_Delete(void *);
extern void BTLV_BG_Delete(void *);
extern void PARTICLE_ExitManager(void);
extern void func_021F94D8(void *);
extern void func_02030EAC(struct Node *n);
extern void func_02030DA4(void *);
extern u32 func_020307B0(void *p);
#define FIELD(k) (*(void **)(d_0220AF20 + (k)))

void func_021F7808(void)
{
    if (d_0220AF20 != 0) {
        PM_VOICE_FreeBuffers();
        func_021F8B6C();
        PALANM_FreeSlotBuffers(FIELD(0x18c), 0);
        PALANM_FreeSlotBuffers(FIELD(0x18c), 1);
        PALANM_FreeSlotBuffers(FIELD(0x18c), 2);
        PALANM_FreeSlotBuffers(FIELD(0x18c), 3);
        PALANM_Delete(FIELD(0x18c));
        func_021FEB78(FIELD(0x190));
        func_021F6898(FIELD(0x194));
        func_021F6CF0(FIELD(0x198));
        func_021F6EC0(FIELD(0x19c));
        func_02201AC4(FIELD(0x1a0));
        func_02206E28(FIELD(0x1a4));
        BTLV_TIMER_Delete(FIELD(0x1b0));
        BTLV_BG_Delete(FIELD(0x1b4));
        PARTICLE_ExitManager();
        func_021F94D8(FIELD(0x188));
        func_02030EAC(FIELD(0x1b8));
        func_02030DA4(FIELD(0));
        func_020307B0(FIELD(4));
        func_020307B0(d_0220AF20);
        d_0220AF20 = 0;
    }
}
