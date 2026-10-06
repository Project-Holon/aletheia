/*
 * function: OS_KillThread
 * address:  0x0200AD9C
 * packet:   pkt_0200AD9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020173EC 0x020173EC thumb
 *   func_02082D44 0x02082D44 arm
 */

typedef unsigned int   u32;
extern u32 func_020173EC(void);
extern void func_02082D44(void *thread, void *arg1, void *res);

void OS_KillThread(void *thread, void *arg1)
{
    void *res = (void *)func_020173EC();
    func_02082D44(thread, arg1, res);
}
