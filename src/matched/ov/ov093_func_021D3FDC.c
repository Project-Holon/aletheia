/*
 * function: func_021D3FDC
 * address: 0x021D3FDC
 * packet: pkt_ov093_021D3FDC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * note 2026-10-05: now verifies EXACT (func_021F8B10 resolves).
 * match-note: A goto to the bottom epilogue reproduces the entry guards;
 * input is called before adjusted=0, preserving the original scheduling.
 * symbols:
 *   func_021EAE74 0x021EAE74 thumb ov093
 *   func_021EAE64 0x021EAE64 thumb ov093
 *   func_021EAE04 0x021EAE04 thumb ov093
 *   func_021EAECC 0x021EAECC thumb ov093
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_SetPlayersAudible 0x02005CA4 thumb
 *   PM_VOICE_SetMasterVolume 0x02006734 thumb
 *   func_021F8B10 0x021F8B10 thumb ov094
 *   func_021B92A0 0x021B92A0 thumb ov093
 *   func_021EAE14 0x021EAE14 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Q {
    u8 state, mode;
    u8 flag0:1, flag1:1, flag2:1, flag3:1, flag4:1, flag5:1, rest:2;
    u8 unk3;
    u16 delay, current, target, maximum, tick;
};
extern void func_021EAE74(char *p, u32 a, u32 b);
extern int func_021EAE64(void *);
extern void func_021EAE04(u32 *p);
extern void func_021EAECC(u8 *p, int v, int w);
extern void GFL_USE_FadeOutBgm(u32);
extern void GFL_USE_SetPlayersAudible(int,u32);
extern void PM_VOICE_SetMasterVolume(u8);
extern int func_021F8B10(void);
extern void func_021B92A0(u8 *p);
extern int func_021EAE14(u32 *p);
void func_021D3FDC(u8 *p, struct Q *q)
{
    int changed, adjusted, input;
    if (p[0x1a7] != 2 || q->flag4 || q->flag5 || !q->maximum) goto done;
    changed = 0;
    if (q->flag3) {
        q->flag3 = 0;
        if (!q->flag0) {
            if (q->current < q->maximum && q->state == 0) {
                ++q->current;
                if (!q->delay) q->target = q->current;
                changed = 1;
            }
        } else {
            if (q->tick < q->target) {
                ++q->tick;
                if (q->tick == q->target) {
                    q->current = q->target;
                    if (*(void **)(p+0x54)) func_021EAE74(*(void **)(p+0x54),q->current,q->target);
                }
            }
            return;
        }
    }
    if (!q->current || !*(void **)(p+0x54)) return;
    switch (q->state) {
    case 0:
        input = func_021EAE64(*(void **)(p+0x54));
        adjusted = 0;
        switch (input) {
        case 2:
            q->mode = 1;
            func_021EAE04(*(void **)(p+0x54));
            q->flag1 = 1;
            q->state = 1;
            func_021EAECC(*(void **)(p+0x54),q->current,1);
            GFL_USE_FadeOutBgm(30);
            GFL_USE_SetPlayersAudible(0,62);
            PM_VOICE_SetMasterVolume(0);
            func_021F8B10();
            func_021B92A0((u8 *)(*(u32 *)p));
            break;
        case 0:
            if (q->target > 1) { --q->target; adjusted = 1; }
            q->delay = 45;
            break;
        case 1:
            if (q->target < q->maximum) { ++q->target; adjusted = 1; }
            q->delay = 45;
            break;
        }
        if (adjusted || changed) func_021EAE74(*(void **)(p+0x54),q->current,q->target);
        if (q->delay) {
            --q->delay;
            if (!q->delay) {
                q->mode = 2;
                func_021EAE04(*(void **)(p+0x54));
                q->flag1 = 1;
                q->state = 1;
                GFL_USE_FadeOutBgm(30);
                GFL_USE_SetPlayersAudible(0,62);
                PM_VOICE_SetMasterVolume(0);
                func_021F8B10();
            }
        }
        break;
    case 1:
        if (func_021EAE14(*(void **)(p+0x54))) { q->flag2 = 1; q->state = 2; }
        break;
    case 2:
        break;
    }
done:
    return;
}
