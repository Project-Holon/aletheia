/*
 * function: INTRUDE_LINK_EventMain
 * address:  0x021766F0
 * packet:   pkt_ov011_021766F0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Lever: case 1 forwards func_0201210C's live r0 result into
 * func_02189A08(unsigned char *); the matched body reads p + 0x13C.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask  0x02029BCC  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF498  0x021CF498  thumb  ov021
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   func_02012444  0x02012444  thumb
 *   FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask  0x02029C00  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   sIntrudeLinkProcTable     0x02176FCC  data  ov011  a4
 */

typedef unsigned int u32;

extern char sIntrudeLinkProcTable[];
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
typedef unsigned char  u8;
struct Evt;
struct Obj;
extern void *FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(void *a, u32 b);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int  func_02189A08(unsigned char *p);
extern void func_021CF498(struct Ctx *c, u32 x, int idx);
extern int  FIELD_STATUS_CreateFieldCloseEvent(int a, int b);
extern void func_02012444(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern void *FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(void *a);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *a0);
extern void *FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(void *a);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);

int INTRUDE_LINK_EventMain(void *a, u32 *p, int *q)
{
    int sv;

    sv = (int)func_0201210C((const struct Ctx *)q[0]);
    switch (*p) {
    case 0:
        func_02012374(a, FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask((void *)q[0], 0x490));
        (*p)++;
        break;
    case 1:
        func_021CF498((struct Ctx *)func_02189A08((unsigned char *)sv), (u32)a, 5);
        (*p)++;
        break;
    case 2:
        func_02012374(a, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent(q[0], sv));
        (*p)++;
        break;
    case 3:
        func_02012444(a, -1, (u32)sIntrudeLinkProcTable, q[1]);
        (*p)++;
        break;
    case 4:
        func_02012374(a, FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask((void *)q[0]));
        (*p)++;
        break;
    case 5:
        func_02012374(a, FIELD_STATUS_CreateFieldOpenEvent((void *)q[0]));
        (*p)++;
        break;
    case 6:
        func_02012374(a, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask((void *)q[0]));
        (*p)++;
        break;
    case 7:
        func_02012374(a, (struct Evt **)func_021BE92C((void *)q[0], sv, 0, 0, 1, 0, 0));
        (*p)++;
        break;
    default:
        return 1;
    }
    return 0;
}
