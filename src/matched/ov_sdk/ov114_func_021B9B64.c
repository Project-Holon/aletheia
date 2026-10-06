/*
 * function: func_021B9B64
 * address:  0x021B9B64
 * packet:   pkt_ov114_021B9B64
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_createCommThread (libnhttp.TWL.HYB.a(nhttp_os_ntr.o))
 *
 * symbols:
 *   func_021BBEB8 0x021BBEB8 arm ov114
 *   func_02085D94 0x02085D94 arm
 *   func_021BBEA0 0x021BBEA0 arm ov114
 *   func_020853C0 0x020853C0 arm
 *   func_02085868 0x02085868 arm
 *   func_021B9C60 0x021B9C60 arm ov114
 */

typedef struct {
    char pad[0x20];
    void *msgArray[3];
    char commThread[0x2c];
    char mq[0x1c];
} ThreadInfo;

typedef unsigned char  u8;
extern int func_021BBEB8(u8 *p);
typedef signed int     s32;
struct OSMessageQueue;
extern void func_02085D94(struct OSMessageQueue *mq, void **msgArray, s32 msgCount);
extern void func_021BBEA0(u8 *p);
extern void func_020853C0(void *thread, void (*func)(void *), void *arg, void *stack, unsigned long stackSize, unsigned long prio);
extern void func_02085868(void *thread);
extern void func_021B9C60(void *);

int func_021B9B64(ThreadInfo *threadInfo_p, unsigned long priority, unsigned long *stack_p)
{
    if (func_021BBEB8((u8 *)threadInfo_p) == 0) {
        func_02085D94((struct OSMessageQueue *)threadInfo_p, threadInfo_p->msgArray, 3);
        func_021BBEA0((u8 *)threadInfo_p);
    }
    func_020853C0((char *)threadInfo_p + 0x2c, func_021B9C60, 0, (char *)stack_p + 0x2000, 0x2000, priority);
    func_02085868((char *)threadInfo_p + 0x2c);
    return 1;
}
