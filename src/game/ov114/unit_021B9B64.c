/*
 * file:     unit_021B9B64.c
 * unit:     yes
 * function: func_021B9B64, func_021B9BD4, func_021B9BF4, func_021B9C08, func_021B9C1C, func_021B9C60
 * address:  0x021B9B64
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BBEB8 0x021BBEB8 arm ov114
 *   func_02085D94 0x02085D94 arm
 *   func_021BBEA0 0x021BBEA0 arm ov114
 *   func_020853C0 0x020853C0 arm
 *   func_02085868 0x02085868 arm
 *   func_021B9C60 0x021B9C60 arm ov114
 *   func_02088234 0x02088234 arm
 *   g_02150FEC 0x02150FEC data
 *   func_021BE4D4  0x021BE4D4  arm  ov114
 */
struct OSMessageQueue;
typedef struct {
    char pad[0x20];
    void *msgArray[3];
    char commThread[0x2c];
    char mq[0x1c];
} ThreadInfo_021B9B64;

typedef unsigned char  u8;

typedef signed int     s32;

typedef unsigned int u32;

typedef struct {
    char pad[0x2c];
    int commThread;
} ThreadInfo_021B9C1C;

typedef struct {
    int pad;
    int *current;
} OSInfo;

extern int func_021BBEB8(u8 *p);
extern void func_02085D94(struct OSMessageQueue *mq, void **msgArray, s32 msgCount);
extern void func_021BBEA0(u8 *p);
extern void func_020853C0(void *thread, void (*func)(void *), void *arg, void *stack, unsigned long stackSize, unsigned long prio);
extern void func_02085868(void *thread);
extern void func_021B9C60(void *);
extern void func_02085710(void *);
extern void func_02085E50(int, int *, int);
extern void func_02085DBC(int, int, int);
extern void func_02088234(void);
int func_021B9B64(ThreadInfo_021B9B64 *threadInfo_p, unsigned long priority, unsigned long *stack_p);
void func_021B9BD4(int a, u8 *p);
void func_021B9BF4(int a);
void func_021B9C08(int a);
void func_021B9C1C(ThreadInfo_021B9C1C *threadInfo_p, int is);
void func_021B9C60(void *p);
extern void func_021BE4D4(void);
extern OSInfo g_02150FEC;


int func_021B9B64(ThreadInfo_021B9B64 *threadInfo_p, unsigned long priority, unsigned long *stack_p)
{
    if (func_021BBEB8((u8 *)threadInfo_p) == 0) {
        func_02085D94((struct OSMessageQueue *)threadInfo_p, threadInfo_p->msgArray, 3);
        func_021BBEA0((u8 *)threadInfo_p);
    }
    func_020853C0((char *)threadInfo_p + 0x2c, func_021B9C60, 0, (char *)stack_p + 0x2000, 0x2000, priority);
    func_02085868((char *)threadInfo_p + 0x2c);
    return 1;
}


void func_021B9BD4(int a, u8 *p)
{
    *(u32 *)(p + 0x18) = 1;
    func_021B9C08(a);
    func_02085710((char *)a + 0x2c);
}


void func_021B9BF4(int a)
{
    int tmp;

    func_02085E50(a, &tmp, 1);
}


void func_021B9C08(int a)
{
    func_02085DBC(a, 0, 0);
}


void func_021B9C1C(ThreadInfo_021B9C1C *threadInfo_p, int is)
{
    int *commThread_p = &threadInfo_p->commThread;
    int *cur = g_02150FEC.current;

    if (cur) {
        if ((is == 0 && cur != commThread_p) || (is != 0 && cur == commThread_p)) {
            func_02088234();
        }
    }
}

void func_021B9C60(void *p)
{
    func_021BE4D4();
}
