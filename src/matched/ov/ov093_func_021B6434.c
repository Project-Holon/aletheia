/*
 * function: BTL_MAIN_ProcMain
 * address:  0x021B6434
 * packet:   pkt_ov093_021B6434
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetOwnsSlots  0x021B9114  thumb  ov093
 *   BTL_MAIN_JudgeResult  0x021BA54C  thumb  ov093
 *   BTL_MAIN_StoreRecorderEntry  0x021BA6C0  thumb  ov093
 *   BTL_MAIN_StoreResultStats  0x021BA878  thumb  ov093
 *   BTL_MAIN_WriteBackResults  0x021BA2E4  thumb  ov093
 *   BTL_MAIN_IsRecordPlaybackDone  0x021B64CC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct P {
    u8 pad00[0x88];
    int f88;
    u8 pad8c[0x35];
    u8 fc1_0 : 1;
    u8 fc1_1 : 1;
};

struct S {
    struct P *f00;
    u8 pad04[0x42c];
    int f430;
    int f434;
    int f438;
    u8 pad43c[0x28];
    int (*f464)(struct S *);
};

extern u8 BTL_MAIN_GetOwnsSlots(u8 **p);
extern int BTL_MAIN_JudgeResult(char *p);
extern void BTL_MAIN_StoreRecorderEntry(char *p);
extern void BTL_MAIN_StoreResultStats(u8 *p);
extern void BTL_MAIN_WriteBackResults(char *p);
extern int BTL_MAIN_IsRecordPlaybackDone(u8 *p);

int BTL_MAIN_ProcMain(int a0, int a1, int a2, struct S *s)
{
    u32 t;
    u32 r;

    if (s->f464 == 0) {
        return 1;
    }
    if (s->f464(s) != 0) {
        if (BTL_MAIN_GetOwnsSlots((u8 **)s) == 0) {
            t = BTL_MAIN_JudgeResult((char *)s);
            BTL_MAIN_StoreRecorderEntry((char *)s);
            BTL_MAIN_StoreResultStats((u8 *)s);
            BTL_MAIN_WriteBackResults((char *)s);
            switch (t) {
            case 1:
                s->f00->f88 = s->f430 + s->f434;
                break;
            case 0:
            case 2:
                s->f00->f88 = -s->f438;
                break;
            }
        } else {
            r = BTL_MAIN_IsRecordPlaybackDone((u8 *)s);
            s->f00->fc1_1 = r;
        }
        return 1;
    }
    return 0;
}
