/*
 * function: func_022132C4
 * address: 0x022132C4
 * packet: pkt_ov199_022132C4
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 Thumb tails 0200BA58 and 0200BA68 lack matched/label witnesses.
 * Scratch-only tails each EXACT 16B; blocker-0200BA58.log and blocker-0200BA68.log.
 * TU/suggest-split MATCH: no viable partition; the integrator owns ARM9 filing.
 * Verified blocker C (symbols: ov188_id 0x000000BC data a1;
 * func_02034AC4 0x02034AC4 arm; func_02034A5C 0x02034A5C arm):
 * extern const char ov188_id[];
 * extern void func_02034AC4(const void *);
 * extern void func_02034A5C(const void *);
 * void BATTLE_REC_LoadToolOverlay(void) { func_02034AC4(ov188_id); }
 * void BATTLE_REC_UnloadToolOverlay(void) { func_02034A5C(ov188_id); }
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021EEEA8 0x021EEEA8 thumb ov188
 *   BATTLE_REC_LoadToolOverlay 0x0200BA58 thumb
 *   BATTLE_REC_UnloadToolOverlay 0x0200BA68 thumb
 *   ov093_id 0x0000005D data a1
 *   d_02213D04 0x02213D04 data ov199 a1
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb  arm9
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 *   BTL_SETUP_InitWithSlots  0x020138C4  thumb  arm9
 *   BTL_SETUP_Clear  0x020130C4  thumb  arm9
 */
typedef signed int     s32;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, unsigned int);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern void BTL_SETUP_Clear(u8 *p);
extern void BTL_SETUP_InitWithSlots(char *, void *, int);
extern void BATTLE_REC_LoadToolOverlay(void);
extern void BATTLE_REC_UnloadToolOverlay(void);
extern void func_021EEEA8(void *p, u32 c);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(unsigned short, int);
extern const char d_02213D04[];
extern const char ov093_id[];
void *func_022132C4(void *unused, int heap, char *p)
{
    char *work = func_02030734(heap, 0xf0, 0, d_02213D04, 0x6f4);
    func_02082BCC(work, 0, 0xf0);
    func_02034AC4((s32)ov093_id);
    BTL_SETUP_Clear((u8 *)work);
    BTL_SETUP_InitWithSlots(work, *(void **)(p + 4), heap);
    func_02034A5C((s32)ov093_id);
    BATTLE_REC_LoadToolOverlay();
    func_021EEEA8(work, heap);
    BATTLE_REC_UnloadToolOverlay();
    func_02034AC4((s32)ov093_id);
    GFL_USE_CancelChangeAndStopBgm();
    GFL_USE_CancelChangeAndPlayBgm(*(unsigned short *)(work + 0x18), 0xffff);
    return work;
}
