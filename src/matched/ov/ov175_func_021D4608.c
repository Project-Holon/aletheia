/*
 * function: WIFIBATTLEMATCH_NET_TaskStepB
 * address: 0x021D4608
 * packet: pkt_ov175_021D4608
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E7E0C 0x021E7E0C thumb ov177
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   WIFIBATTLEMATCH_NET_SetupSprite 0x021D6550 thumb ov175
 *   WIFIBATTLEMATCH_NET_IsSpriteAnimDone 0x021D65DC thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteSprite 0x021D65C8 thumb ov175
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_NET_TaskStepK 0x021D57BC thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepC 0x021D4730 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskCleanupB 0x021D61CC thumb ov175
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 */
typedef unsigned int u32;
extern void func_021E7E0C(void **, int);
extern void func_021E8738(int *, int, int, int);
extern void func_021E8AB4(u32, u32);
extern void WIFIBATTLEMATCH_NET_SetupSprite(u32 *, int);
extern int WIFIBATTLEMATCH_NET_IsSpriteAnimDone(char *);
extern void WIFIBATTLEMATCH_NET_DeleteSprite(char *);
extern void func_021E8AA0(int *, int);
extern void WIFIBATTLEMATCH_NET_TaskStepK(unsigned sys, int *state, int *p);
extern void WIFIBATTLEMATCH_NET_TaskStepC(u32 sys, int *state, u32 *p);
extern void WIFIBATTLEMATCH_NET_TaskCleanupB(void *a, u32 **pp, char *p);
extern int func_021E8844(const int *);
extern void func_021E8AB8(u32);
void WIFIBATTLEMATCH_NET_TaskStepB(u32 sys, int *state, u32 *p)
{
    u32 *ctx = (u32 *)p[16];
    int result;
    switch (*state) {
    case 0: func_021E7E0C((void **)p[8], 0); *state = 1; break;
    case 1:
        func_021E8738((int *)p[9], p[4], 25, 1);
        *state = 7; func_021E8AB4(sys, 2); break;
    case 2: WIFIBATTLEMATCH_NET_SetupSprite(p, 1); *state = 3; break;
    case 3:
        result = WIFIBATTLEMATCH_NET_IsSpriteAnimDone((char *)p);
        if (result != -1) {
            WIFIBATTLEMATCH_NET_DeleteSprite((char *)p);
            switch (result) {
            case 0: ctx[0] = 1; func_021E8AA0((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepK); break;
            case 1: ctx[0] = 0; func_021E8AA0((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepC); break;
            case 2: ctx[0] = 3; *state = 4; break;
            }
        }
        break;
    case 4:
        func_021E8738((int *)p[9], p[4], 30, 1);
        *state = 7; func_021E8AB4(sys, 5); break;
    case 5: WIFIBATTLEMATCH_NET_SetupSprite(p, 0); *state = 6; break;
    case 6:
        result = WIFIBATTLEMATCH_NET_IsSpriteAnimDone((char *)p);
        if (result != -1) {
            WIFIBATTLEMATCH_NET_DeleteSprite((char *)p);
            switch (result) {
            case 0: ctx[1] = 0; func_021E8AA0((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupB); break;
            case 1: *state = 1; break;
            }
        }
        break;
    case 7: if (func_021E8844((int *)p[9])) func_021E8AB8(sys); break;
    }
}
